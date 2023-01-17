
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
    qDebug() << "stampa da welcomecontroller";
    g->printGarage();

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
      // c = vehiclecontroller;
       //c = new vehiclelistcontroller(vehicle, g, nullptr);
                                   //  const_cast<controller*>(static_cast<const controller*>(this)));
       qDebug() << "stampa dopo creazione vehiclelistcontroller in welcomecontroller";
       //vehiclecontroller->getModel()->printGarage();
       g->printGarage();

        //qDebug() << "stampa c dopo creazione vehiclelistcontroller in welcomecontroller";
        //c->getModel()->printGarage();

       vehiclecontroller->showView();
       v->hide();

}


// DA CONTROLLARE VALIDITA' DI QUESTO CODICE
void welcomeController::OpenGarage() const
{
    /*
    // Fai il pick del file con la libreria apposita
    QString path = JSONAgent::selectFile();
    if(path.isNull()){
        v->dialogPopUp_Warning("File Error", "Seleziona un file per procedere");
    }

    // Prendi i dati dal file (se corretto)
    QJsonDocument* data = JSONAgent::getData(path);
    if(data->isNull()){
        v->dialogPopUp_Warning("Reading Error", "Seleziona un file valido (.json)");
        return;
    }

    // Apri nuova vista del garage
    vehiclelist* vehicle = new vehiclelist(v->size(), v);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, const_cast<controller*>(static_cast<const controller*>(this)));
    vehiclecontroller->showView();

    // Inserire i dati letti

    // Nascondi la vista della pagina di benvenuto
    v->hide();
    */

    QString path = JSONAgent::selectFile();
    QJsonDocument* veicoli = JSONAgent::getData(path);
    JSONAgent::getVehicleList(veicoli, *g);
    g->printGarage();
}

void welcomeController::onClosedView() const
{
    delete this;
}
