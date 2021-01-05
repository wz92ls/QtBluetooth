TARGET = lowenergyscanner
INCLUDEPATH += .

QT += quick bluetooth

# Input
SOURCES += main.cpp \
    device.cpp \
    deviceinfo.cpp \
    httpsclient.cpp \
    serviceinfo.cpp \
    characteristicinfo.cpp

OTHER_FILES += assets/*.qml

HEADERS += \
    device.h \
    deviceinfo.h \
    httpsclient.h \
    serviceinfo.h \
    characteristicinfo.h

RESOURCES += \
    resources.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/bluetooth/lowenergyscanner
INSTALLS += target

android:include($$PWD/android_openssl-master/openssl.pri)

DISTFILES += \
    assets/DeviceControl.qml

