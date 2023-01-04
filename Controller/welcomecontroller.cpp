#include "welcomecontroller.h"
#include "Model/garage.h"
#include "Model/veicolo.h"
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
    garage g;
    veicolo v("audi", "a4", "ao111oa",10000);
    g.addVeicolo(&v);
    g.printGarage();

    // Apri nuova vista del garage e mostrala
    vehiclelist* vehicle = new vehiclelist();
    vehicle->setTitle("Nuovo Garage");

    /*
     * vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, new model qualcosa, const_cast<controller*>(static_cast<const controller*>(this)));
     * vehiclecontroller->show();
     * v->hide();
    */
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
