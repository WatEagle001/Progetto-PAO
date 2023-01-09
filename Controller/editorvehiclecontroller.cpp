#include "editorvehiclecontroller.h"
#include "View/editorvehicle.h"
#include "vehiclelistcontroller.h"
#include "Model/garage.h"
#include <iostream>
#include "QDebug"

void editorvehiclecontroller::connectViewController() const
{
    connect(v, SIGNAL(saveSignal()), this, SLOT(saveSlot()));
    connect(v, SIGNAL(clearSignal()), this, SLOT(clearSlot()));
}

editorvehiclecontroller::editorvehiclecontroller(editorvehicle *v,garage *g, controller *parent) : controller(v, m, parent)
{
    connectViewController();
}

view *editorvehiclecontroller::getView() const
{
    return static_cast<editorvehicle*>(v);
}

model *editorvehiclecontroller::getModel() const
{
    return static_cast<model*>(m);
}


void editorvehiclecontroller::saveSlot() const
{
    /*garage * g = new garage;
    g->printGarage();
    // Apri nuova vista del garage e mostrala
    vehiclelist* vehicle = new vehiclelist(v->size(), v);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, new garage(), const_cast<controller*>(static_cast<const controller*>(this)));
    vehiclecontroller->showView();
    v->hide();
    */
    qDebug()<< "premuto Salva";
}

void editorvehiclecontroller::clearSlot() const
{

    // Fai il pick del file con la libreria apposita
    /*QString path = JSONAgent::selectFile();
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
    */
    qDebug() << "premuto clear";
}

void editorvehiclecontroller::onClosedView() const
{
    delete this;
}
