QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    auto_elettrica.cpp \
    auto_ibrida.cpp \
    automobile.cpp \
    main.cpp \
    mainwindow.cpp \
    moto.cpp \
    moto_elettrica.cpp \
    motore_combustione.cpp \
    motore_elettrico.cpp \
    veicolo.cpp

HEADERS += \
    auto_elettrica.h \
    auto_ibrida.h \
    automobile.h \
    mainwindow.h \
    moto.h \
    moto_elettrica.h \
    motore_combustione.h \
    motore_elettrico.h \
    veicolo.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    car-brands
