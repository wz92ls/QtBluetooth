/***************************************************************************
**
** Copyright (C) 2013 BlackBerry Limited. All rights reserved.
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtBluetooth module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "device.h"

#include <qbluetoothaddress.h>
#include <qbluetoothdevicediscoveryagent.h>
#include <qbluetoothlocaldevice.h>
#include <qbluetoothdeviceinfo.h>
#include <qbluetoothservicediscoveryagent.h>
#include <QDebug>
#include <QList>
#include <QMetaEnum>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QUrlQuery>
#include <QLowEnergyAdvertisingParameters>
#include <QLowEnergyServiceData>
#include <QBluetoothUuid>
#include <QLowEnergyCharacteristicData>
Device::Device()
{


    QUrl url("https://openbfapi.gongyitech.com/other/deviceSend");


    QByteArray data="ticket=unHj2qeiMcH0JLyefFFJx2T6EyRKejukQJ2eCD3DXRHTWZz8Uj/KQ97LX3ApKJWX";
    data=data+"&status=UT";
    qDebug()<<url.toString();



    //! [les-devicediscovery-1]
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent();
    discoveryAgent->setLowEnergyDiscoveryTimeout(5000);
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &Device::addDevice);
    connect(discoveryAgent, QOverload<QBluetoothDeviceDiscoveryAgent::Error>::of(&QBluetoothDeviceDiscoveryAgent::error),
            this, &Device::deviceScanError);
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished, this, &Device::deviceScanFinished);
    //! [les-devicediscovery-1]

    setUpdate(tr("搜索设备"));
}
Device::~Device()
{
    delete discoveryAgent;
    delete controller;
    qDeleteAll(devices);
    qDeleteAll(m_services);
    qDeleteAll(m_characteristics);
    devices.clear();
    m_services.clear();
    m_characteristics.clear();
}

void Device::startDeviceDiscovery()
{
    qDeleteAll(devices);
    devices.clear();
    emit devicesUpdated();

    //    setUpdate("Scanning for devices ...");
    setUpdate("搜索设备中 ...");
    //    tr("搜索设备")
    //! [les-devicediscovery-2]
    discoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
    //! [les-devicediscovery-2]

    if (discoveryAgent->isActive()) {
        m_deviceScanState = true;
        Q_EMIT stateChanged();
    }
}

//! [les-devicediscovery-3]
void Device::addDevice(const QBluetoothDeviceInfo &info)
{
    if (info.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration)
        setUpdate("最近发现设备: " + info.name());
}
//! [les-devicediscovery-3]

void Device::deviceScanFinished()
{
    const QList<QBluetoothDeviceInfo> foundDevices = discoveryAgent->discoveredDevices();
    for (auto nextDevice : foundDevices)
        if (nextDevice.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration)
            devices.append(new DeviceInfo(nextDevice));

    emit devicesUpdated();
    m_deviceScanState = false;
    emit stateChanged();
    if (devices.isEmpty())
        //        setUpdate("No Low Energy devices found...");
        setUpdate(tr("没有发现设备..."));
    else
        //        setUpdate("Done! Scan Again!");
        setUpdate(tr("再次搜索"));
}

QVariant Device::getDevices()
{
    return QVariant::fromValue(devices);
}

QVariant Device::getServices()
{
    return QVariant::fromValue(m_services);
}

QVariant Device::getCharacteristics()
{
    return QVariant::fromValue(m_characteristics);
}

QString Device::getUpdate()
{
    return m_message;
}

void Device::scanServices(const QString &address)
{
    // We need the current device for service discovery.

    for (auto d: qAsConst(devices)) {
        if (auto device = qobject_cast<DeviceInfo *>(d)) {
            if (device->getAddress() == address ) {
                currentDevice.setDevice(device->getDevice());
                break;
            }
        }
    }

    if (!currentDevice.getDevice().isValid()) {
        qWarning() << "Not a valid device";
        return;
    }

    qDeleteAll(m_characteristics);
    m_characteristics.clear();
    emit characteristicsUpdated();
    qDeleteAll(m_services);
    m_services.clear();
    emit servicesUpdated();

    setUpdate("Back\n(Connecting to device...)");

    if (controller && m_previousAddress != currentDevice.getAddress()) {
        controller->disconnectFromDevice();
        delete controller;
        controller = nullptr;
    }

    //! [les-controller-1]
    if (!controller) {
        // Connecting signals and slots for connecting to LE services.
        controller = QLowEnergyController::createCentral(currentDevice.getDevice());

        connect(controller, &QLowEnergyController::connected,
                this, &Device::deviceConnected);
        connect(controller, QOverload<QLowEnergyController::Error>::of(&QLowEnergyController::error),
                this, &Device::errorReceived);
        connect(controller, &QLowEnergyController::disconnected,
                this, &Device::deviceDisconnected);
        connect(controller, &QLowEnergyController::serviceDiscovered,
                this, &Device::addLowEnergyService);
        connect(controller, &QLowEnergyController::discoveryFinished,
                this, &Device::serviceScanDone);
    }

    if (isRandomAddress())
        controller->setRemoteAddressType(QLowEnergyController::RandomAddress);
    else
        controller->setRemoteAddressType(QLowEnergyController::PublicAddress);


    controller->connectToDevice();




    //! [les-controller-1]

    m_previousAddress = currentDevice.getAddress();
}

void Device::addLowEnergyService(const QBluetoothUuid &serviceUuid)
{
    //! [les-service-1]

    if(serviceUuid!=QBluetoothUuid(quint16(0xFFE0)))
    {
        return;
    }
    QLowEnergyService *service = controller->createServiceObject(serviceUuid);
    qDebug()<<serviceUuid;

    if (!service) {
        qWarning() << "Cannot create service for uuid";
        return;
    }
    //! [les-service-1]
    auto serv = new ServiceInfo(service);
    m_services.append(serv);

    emit servicesUpdated();
}
//! [les-service-1]

void Device::serviceScanDone()
{
    setUpdate("Back\n(Service scan done!)");
    // force UI in case we didn't find anything
    if (m_services.isEmpty())
        emit servicesUpdated();
}

void Device::connectToService(const QString &uuid)
{
    QLowEnergyService *service = nullptr;
    for (auto s: qAsConst(m_services)) {
        auto serviceInfo = qobject_cast<ServiceInfo *>(s);
        if (!serviceInfo)
            continue;

        if (serviceInfo->getUuid() == uuid) {
            service = serviceInfo->service();
            break;
        }
    }

    if (!service)
        return;
    m_service=service;

    //    QLowEnergyAdvertisingData advertisingData;
    //    advertisingData.setDiscoverability(QLowEnergyAdvertisingData::DiscoverabilityGeneral);
    //    advertisingData.setIncludePowerLevel(true);
    //    advertisingData.setLocalName("Server");
    //    advertisingData.setServices(QList<QBluetoothUuid>() << QBluetoothUuid(quint16(0xffe0)));
    //    controller->startAdvertising(QLowEnergyAdvertisingParameters(), advertisingData,
    //                                   advertisingData);
    //    m_service = controller->createServiceObject(QBluetoothUuid(quint16(0xffe0)),this);

    //    sendInfoLoad = m_service->characteristic(QBluetoothUuid(quint16(0xFFE1)));




    if (m_service) {
        connect(m_service, &QLowEnergyService::stateChanged, this, &Device::serviceDetailsDiscovered);
        connect(m_service, &QLowEnergyService::characteristicChanged, this, &Device::characteristicChanged);
        connect(m_service, &QLowEnergyService::descriptorWritten, this, &Device::SL_descriptorWritten);
        m_service->discoverDetails();
    } else {

    }


    //    service->discoverDetails();
    qDeleteAll(m_characteristics);
    m_characteristics.clear();
    emit characteristicsUpdated();

    if (service->state() == QLowEnergyService::DiscoveryRequired) {
        //! [les-service-3]
        connect(service, &QLowEnergyService::stateChanged,
                this, &Device::serviceDetailsDiscovered);
        service->discoverDetails();
        setUpdate("Back\n(Discovering details...)");
        //! [les-service-3]
        return;
    }

    //discovery already done
    const QList<QLowEnergyCharacteristic> chars = service->characteristics();
    for (const QLowEnergyCharacteristic &ch : chars) {
        auto cInfo = new CharacteristicInfo(ch);
        m_characteristics.append(cInfo);
    }
    QTimer::singleShot(0, this, &Device::characteristicsUpdated);
}

void Device::deviceConnected()
{
    setUpdate("Back\n(Discovering services...)");
    connected = true;
    //! [les-service-2]
    controller->discoverServices();
    //! [les-service-2]
}

void Device::errorReceived(QLowEnergyController::Error /*error*/)
{
    qWarning() << "Error: " << controller->errorString();
    setUpdate(QString("Back\n(%1)").arg(controller->errorString()));
}

void Device::setUpdate(const QString &message)
{
    m_message = message;
    emit updateChanged();
}



void Device::disconnectFromDevice()
{
    // UI always expects disconnect() signal when calling this signal
    // TODO what is really needed is to extend state() to a multi value
    // and thus allowing UI to keep track of controller progress in addition to
    // device scan progress

    if (controller->state() != QLowEnergyController::UnconnectedState)
        controller->disconnectFromDevice();
    else
        deviceDisconnected();
}

void Device::sendCmd(const QString &uuid)
{
    qDebug()<<"uuid="<<uuid;
    sendInfoLoad = m_service->characteristic(QBluetoothUuid(quint16(0xFFE1)));

    qDebug()<<sendInfoLoad.name();
    m_service->writeCharacteristic(sendInfoLoad,"123456");
    //    connect(m_service,&QLowEnergyService::characteristicRead, this,
    //            [this](QLowEnergyCharacteristic c,QByteArray value) {
    //        sendInfoLoad = c;
    //        qDebug() << "Peripheral characteristicRead::" <<c.uuid();
    //        qDebug() << value;
    //    });


}
void Device::characteristicChanged(const QLowEnergyCharacteristic &c, const QByteArray &value)
{
    qDebug() << "Peripheral characteristicRead::" <<c.uuid();
    qDebug() << value;
}

void Device::SL_descriptorWritten(const QLowEnergyDescriptor &descriptor, const QByteArray &newValue)
{
    qDebug()<<descriptor.uuid();
    qDebug()<<newValue;

}
void Device::deviceDisconnected()
{
    //    qWarning() << "Disconnect from device";
    //    emit disconnected();
}

void Device::serviceDetailsDiscovered(QLowEnergyService::ServiceState newState)
{
    if (newState != QLowEnergyService::ServiceDiscovered) {
        // do not hang in "Scanning for characteristics" mode forever
        // in case the service discovery failed
        // We have to queue the signal up to give UI time to even enter
        // the above mode
        if (newState != QLowEnergyService::DiscoveringServices) {
            QMetaObject::invokeMethod(this, "characteristicsUpdated",
                                      Qt::QueuedConnection);
        }
        return;
    }

    auto service = qobject_cast<QLowEnergyService *>(sender());
    if (!service)
        return;



    //! [les-chars]
    const QList<QLowEnergyCharacteristic> chars = service->characteristics();
    for (const QLowEnergyCharacteristic &ch : chars) {
        auto cInfo = new CharacteristicInfo(ch);
        m_characteristics.append(cInfo);
        sendInfoLoad =ch;
        qDebug()<<"sendInfoLoad="<<sendInfoLoad.uuid();
        QLowEnergyDescriptor notification = sendInfoLoad.descriptor(QBluetoothUuid::ClientCharacteristicConfiguration);
        if (!notification.isValid())
        {
            qDebug()<<"notification描述符无效，返回";
        }
        m_service->writeDescriptor(notification, QByteArray::fromHex("0100"));
    }
    //! [les-chars]

    emit characteristicsUpdated();
}



void Device::deviceScanError(QBluetoothDeviceDiscoveryAgent::Error error)
{
    if (error == QBluetoothDeviceDiscoveryAgent::PoweredOffError)
        setUpdate("The Bluetooth adaptor is powered off, power it on before doing discovery.");
    else if (error == QBluetoothDeviceDiscoveryAgent::InputOutputError)
        setUpdate("Writing or reading from the device resulted in an error.");
    else {
        static QMetaEnum qme = discoveryAgent->metaObject()->enumerator(
                    discoveryAgent->metaObject()->indexOfEnumerator("Error"));
        setUpdate("Error: " + QLatin1String(qme.valueToKey(error)));
    }

    m_deviceScanState = false;
    emit devicesUpdated();
    emit stateChanged();
}

bool Device::state()
{
    return m_deviceScanState;
}

bool Device::hasControllerError() const
{
    return (controller && controller->error() != QLowEnergyController::NoError);
}

bool Device::isRandomAddress() const
{
    return randomAddress;
}

void Device::setRandomAddress(bool newValue)
{
    randomAddress = newValue;
    emit randomAddressChanged();
}
