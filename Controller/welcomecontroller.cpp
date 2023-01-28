
#include "welcomecontroller.h"
#include "vehiclelistcontroller.h"
#include "Model/garage.h"
#include <iostream>
#include "QDebug"

void welcomeController::connectViewController() const
{
    connect(v, SIGNAL(newGarage()), this, SLOT(NewGarage()));
    connect(v, SIGNAL(readGarage()), this, SLOT(OpenGarage()));
}

welcomeController::welcomeController(welcome *v, garage* dati, CostiViaggio* costi,controller *parent) : controller(v, dati, parent)
{
    co = costi;
    g = dati;
    connectViewController();
}

welcome *welcomeController::getView() const
{
    return static_cast<welcome*>(v);
}

model *welcomeController::getModel() const
{
    // La schermata di benvenuto non contiene modelli
    return nullptr;
}

void welcomeController::NewGarage()
{
    vehiclelist* vehicle = new vehiclelist(g,v->size(), nullptr);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, co,const_cast<controller*>(static_cast<const controller*>(this)));

    vehiclecontroller->showView();
    v->hide();
}

void welcomeController::OpenGarage() const
{
    QString path = JSONAgent::selectFile();
    QJsonDocument* veicoli = JSONAgent::getData(path);

    JSONAgent::getVehicleList(veicoli, g);

    vehiclelist* vehicle = new vehiclelist(g,v->size(), nullptr);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vcontroller = new vehiclelistcontroller(vehicle, g, co, const_cast<controller*>(static_cast<const controller*>(this)));

    vcontroller->showView();
    v->hide();
}

void welcomeController::onClosedView() const
{
    delete this;
    QCoreApplication::quit();
}
