/****************************************************************************
** Meta object code from reading C++ file 'device.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../device.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'device.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Device_t {
    QByteArrayData data[38];
    char stringdata0[604];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Device_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Device_t qt_meta_stringdata_Device = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Device"
QT_MOC_LITERAL(1, 7, 14), // "devicesUpdated"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 15), // "servicesUpdated"
QT_MOC_LITERAL(4, 39, 22), // "characteristicsUpdated"
QT_MOC_LITERAL(5, 62, 13), // "updateChanged"
QT_MOC_LITERAL(6, 76, 12), // "stateChanged"
QT_MOC_LITERAL(7, 89, 12), // "disconnected"
QT_MOC_LITERAL(8, 102, 20), // "randomAddressChanged"
QT_MOC_LITERAL(9, 123, 20), // "startDeviceDiscovery"
QT_MOC_LITERAL(10, 144, 12), // "scanServices"
QT_MOC_LITERAL(11, 157, 7), // "address"
QT_MOC_LITERAL(12, 165, 16), // "connectToService"
QT_MOC_LITERAL(13, 182, 4), // "uuid"
QT_MOC_LITERAL(14, 187, 20), // "disconnectFromDevice"
QT_MOC_LITERAL(15, 208, 7), // "sendCmd"
QT_MOC_LITERAL(16, 216, 9), // "addDevice"
QT_MOC_LITERAL(17, 226, 20), // "QBluetoothDeviceInfo"
QT_MOC_LITERAL(18, 247, 18), // "deviceScanFinished"
QT_MOC_LITERAL(19, 266, 15), // "deviceScanError"
QT_MOC_LITERAL(20, 282, 37), // "QBluetoothDeviceDiscoveryAgen..."
QT_MOC_LITERAL(21, 320, 19), // "addLowEnergyService"
QT_MOC_LITERAL(22, 340, 14), // "QBluetoothUuid"
QT_MOC_LITERAL(23, 355, 15), // "deviceConnected"
QT_MOC_LITERAL(24, 371, 13), // "errorReceived"
QT_MOC_LITERAL(25, 385, 27), // "QLowEnergyController::Error"
QT_MOC_LITERAL(26, 413, 15), // "serviceScanDone"
QT_MOC_LITERAL(27, 429, 18), // "deviceDisconnected"
QT_MOC_LITERAL(28, 448, 24), // "serviceDetailsDiscovered"
QT_MOC_LITERAL(29, 473, 31), // "QLowEnergyService::ServiceState"
QT_MOC_LITERAL(30, 505, 8), // "newState"
QT_MOC_LITERAL(31, 514, 11), // "devicesList"
QT_MOC_LITERAL(32, 526, 12), // "servicesList"
QT_MOC_LITERAL(33, 539, 18), // "characteristicList"
QT_MOC_LITERAL(34, 558, 6), // "update"
QT_MOC_LITERAL(35, 565, 16), // "useRandomAddress"
QT_MOC_LITERAL(36, 582, 5), // "state"
QT_MOC_LITERAL(37, 588, 15) // "controllerError"

    },
    "Device\0devicesUpdated\0\0servicesUpdated\0"
    "characteristicsUpdated\0updateChanged\0"
    "stateChanged\0disconnected\0"
    "randomAddressChanged\0startDeviceDiscovery\0"
    "scanServices\0address\0connectToService\0"
    "uuid\0disconnectFromDevice\0sendCmd\0"
    "addDevice\0QBluetoothDeviceInfo\0"
    "deviceScanFinished\0deviceScanError\0"
    "QBluetoothDeviceDiscoveryAgent::Error\0"
    "addLowEnergyService\0QBluetoothUuid\0"
    "deviceConnected\0errorReceived\0"
    "QLowEnergyController::Error\0serviceScanDone\0"
    "deviceDisconnected\0serviceDetailsDiscovered\0"
    "QLowEnergyService::ServiceState\0"
    "newState\0devicesList\0servicesList\0"
    "characteristicList\0update\0useRandomAddress\0"
    "state\0controllerError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Device[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       7,  156, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x06 /* Public */,
       3,    0,  120,    2, 0x06 /* Public */,
       4,    0,  121,    2, 0x06 /* Public */,
       5,    0,  122,    2, 0x06 /* Public */,
       6,    0,  123,    2, 0x06 /* Public */,
       7,    0,  124,    2, 0x06 /* Public */,
       8,    0,  125,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  126,    2, 0x0a /* Public */,
      10,    1,  127,    2, 0x0a /* Public */,
      12,    1,  130,    2, 0x0a /* Public */,
      14,    0,  133,    2, 0x0a /* Public */,
      15,    1,  134,    2, 0x0a /* Public */,
      16,    1,  137,    2, 0x08 /* Private */,
      18,    0,  140,    2, 0x08 /* Private */,
      19,    1,  141,    2, 0x08 /* Private */,
      21,    1,  144,    2, 0x08 /* Private */,
      23,    0,  147,    2, 0x08 /* Private */,
      24,    1,  148,    2, 0x08 /* Private */,
      26,    0,  151,    2, 0x08 /* Private */,
      27,    0,  152,    2, 0x08 /* Private */,
      28,    1,  153,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,    2,
    QMetaType::Void, 0x80000000 | 22,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 29,   30,

 // properties: name, type, flags
      31, QMetaType::QVariant, 0x00495001,
      32, QMetaType::QVariant, 0x00495001,
      33, QMetaType::QVariant, 0x00495001,
      34, QMetaType::QString, 0x00495103,
      35, QMetaType::Bool, 0x00495003,
      36, QMetaType::Bool, 0x00495001,
      37, QMetaType::Bool, 0x00095001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       6,
       4,
       0,

       0        // eod
};

void Device::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Device *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->devicesUpdated(); break;
        case 1: _t->servicesUpdated(); break;
        case 2: _t->characteristicsUpdated(); break;
        case 3: _t->updateChanged(); break;
        case 4: _t->stateChanged(); break;
        case 5: _t->disconnected(); break;
        case 6: _t->randomAddressChanged(); break;
        case 7: _t->startDeviceDiscovery(); break;
        case 8: _t->scanServices((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->connectToService((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->disconnectFromDevice(); break;
        case 11: _t->sendCmd((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->addDevice((*reinterpret_cast< const QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 13: _t->deviceScanFinished(); break;
        case 14: _t->deviceScanError((*reinterpret_cast< QBluetoothDeviceDiscoveryAgent::Error(*)>(_a[1]))); break;
        case 15: _t->addLowEnergyService((*reinterpret_cast< const QBluetoothUuid(*)>(_a[1]))); break;
        case 16: _t->deviceConnected(); break;
        case 17: _t->errorReceived((*reinterpret_cast< QLowEnergyController::Error(*)>(_a[1]))); break;
        case 18: _t->serviceScanDone(); break;
        case 19: _t->deviceDisconnected(); break;
        case 20: _t->serviceDetailsDiscovered((*reinterpret_cast< QLowEnergyService::ServiceState(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothDeviceInfo >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothUuid >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyController::Error >(); break;
            }
            break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyService::ServiceState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::devicesUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::servicesUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::characteristicsUpdated)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::updateChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::stateChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::disconnected)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::randomAddressChanged)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Device *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariant*>(_v) = _t->getDevices(); break;
        case 1: *reinterpret_cast< QVariant*>(_v) = _t->getServices(); break;
        case 2: *reinterpret_cast< QVariant*>(_v) = _t->getCharacteristics(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getUpdate(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->isRandomAddress(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->state(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->hasControllerError(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Device *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 3: _t->setUpdate(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setRandomAddress(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Device::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Device.data,
    qt_meta_data_Device,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Device::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Device::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Device.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Device::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Device::devicesUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Device::servicesUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Device::characteristicsUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Device::updateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Device::stateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Device::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Device::randomAddressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
