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

    qDebug() << "premuto clear";
}

void editorvehiclecontroller::onClosedView() const
{
    delete this;
}

void editorvehiclecontroller::editVehicleSlot() const{
    qDebug() << "Premuto editor veicoli";
}
