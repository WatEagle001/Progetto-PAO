
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

welcomeController::welcomeController(welcome *v, garage* dati,controller *parent) : controller(v, dati, parent)
{

    g = dati;
    connectViewController();
    //qDebug() << "stampa da welcomecontroller";
    //g->printGarage();

}

welcome *welcomeController::getView() const
{
    return static_cast<welcome*>(v);
}

model *welcomeController::getModel() const
{
    // La schermata di benvenuto non conteiene modelli
    return nullptr;
}

void welcomeController::NewGarage()
{
    // Apri nuova vista del garage e mostrala
    vehiclelist* vehicle = new vehiclelist(g,v->size(), v);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, const_cast<controller*>(static_cast<const controller*>(this)));
      // qDebug() << "stampa dopo creazione vehiclelistcontroller in welcomecontroller";
      // g->printGarage();

       vehiclecontroller->showView();
       v->hide();

}


// DA CONTROLLARE VALIDITA' DI QUESTO CODICE
void welcomeController::OpenGarage() const
{
    QString path = JSONAgent::selectFile();
    QJsonDocument* veicoli = JSONAgent::getData(path);


    JSONAgent* js = new JSONAgent(g);
    js->getVehicleList(veicoli, g);


    vehiclelist* vehicle = new vehiclelist(g,v->size(), v);
    vehicle->setTitle("Garage");
    g->printGarage();
    vehiclelistcontroller* vcontroller = new vehiclelistcontroller(vehicle, g, const_cast<controller*>(static_cast<const controller*>(this)));

       vcontroller->showView();
       v->hide();

}

void welcomeController::onClosedView() const
{
    delete this;
}
