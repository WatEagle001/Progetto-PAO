QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RC_ICONS = Assets/image/logos/appLogo.ico

SOURCES += \
    Controller/jsonagent.cpp \
    Controller/vehiclelistcontroller.cpp \
    Controller/welcomecontroller.cpp \
    Controller/controller.cpp \
    Model/model.cpp \
    Model/CostiViaggio.cpp \
    View/vehiclelist.cpp \
    View/view.cpp \
    View/welcome.cpp \
    main.cpp \
       Model/auto_elettrica.cpp \
       Model/auto_ibrida.cpp \
       Model/automobile.cpp \
       Model/emptyexception.cpp \
       Model/garage.cpp \
       Model/monopattino_elettrico.cpp \
       Model/outofboundsexception.cpp \
       Model/moto.cpp \
       Model/moto_elettrica.cpp \
       Model/motore_combustione.cpp \
       Model/motore_elettrico.cpp \
       Model/veicolo.cpp

HEADERS += \
   Model/CostiViaggio.h \
   Model/array.h \
   Model/auto_elettrica.h \
   Model/auto_ibrida.h \
   Model/automobile.h \
   Model/emptyexception.h \
   Model/garage.h \
   Model/monopattino_elettrico.h \
   Model/outofboundsexception.h \
   Model/moto.h \
   Model/moto_elettrica.h \
   Model/motore_combustione.h \
   Model/motore_elettrico.h \
   Model/veicolo.h \
    Controller/jsonagent.h \
    Controller/vehiclelistcontroller.h \
    Controller/welcomecontroller.h \
    Controller/controller.h \
    Model/model.h \
    View/vehiclelist.h \
    View/view.h \
    View/welcome.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    car-brands

RESOURCES += \
   resources.qrc

