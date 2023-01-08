
#include "welcomecontroller.h"
#include "vehiclelistcontroller.h"
#include "Model/garage.h"
#include <iostream>

void welcomeController::connectViewController() const
{
    connect(v, SIGNAL(newGarage()), this, SLOT(NewGarage()));
    connect(v, SIGNAL(readGarage()), this, SLOT(OpenGarage()));
}

welcomeController::welcomeController(welcome *v, controller *parent) : controller(v, nullptr, parent)
{
    connectViewController();
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

void welcomeController::NewGarage() const
{
    // Apri nuova vista del garage e mostrala
    vehiclelist* vehicle = new vehiclelist(v->size(), v);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, new garage(), const_cast<controller*>(static_cast<const controller*>(this)));
    vehiclecontroller->showView();
    v->hide();
}

void welcomeController::OpenGarage() const
{

    // Fai il pick del file con la libreria apposita
    QString path = JSONAgent::selectFile();
    if(path.isNull()){
        v->dialogPopUp_Warning("File Error", "Seleziona un file per procedere");
        return;
    }

    // Prendi i dati dal file (se corretto)
    QJsonDocument* data = JSONAgent::getData(path);
    if(data->isNull()){
        v->dialogPopUp_Warning("Reading Error", "Seleziona un file valido (.json)");
        return;
    }

    // Apri nuova vista del garage con i dati inseriti
    // Nascondi la vista della pagina di benvenuto
}

void welcomeController::onClosedView() const
{
    delete this;
}
