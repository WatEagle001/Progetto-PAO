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
    connect(v, SIGNAL(editVehicleSignal()), this, SLOT(editVehicleSlot()));
}

editorvehiclecontroller::editorvehiclecontroller(editorvehicle *v,garage *m,controller *parent) : controller(v, m, parent)
{
    g = m;
    connectViewController();
}

view *editorvehiclecontroller::getView() const
{
    return static_cast<editorvehicle*>(v);
}

garage *editorvehiclecontroller::getModel() const
{
    return static_cast<garage*>(m);
}


void editorvehiclecontroller::saveSlot() const
{
    /*getModel()->printGarage();
    qDebug()<< "premuto Salva";
    */
    g->printGarage();
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

void editorvehiclecontroller::editVehicleSlot() const{
    qDebug() << "Premuto editor veicoli";
}
