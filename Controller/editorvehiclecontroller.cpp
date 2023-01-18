#include "editorvehiclecontroller.h"
#include "View/editorvehicle.h"
#include "vehiclelistcontroller.h"
#include "Model/garage.h"
#include <iostream>
#include "QDebug"

void editorvehiclecontroller::connectViewController() const
{
   connect(static_cast<editorvehicle*>(v), &editorvehicle::saveSignal, this, &editorvehiclecontroller::saveSlot);
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


void editorvehiclecontroller::saveSlot(veicolo* veic)
{

    vehiclelist* vehicle = new vehiclelist(g,v->size(), v);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, const_cast<controller*>(static_cast<const controller*>(this)));

       vehiclecontroller->showView();
       v->hide();

}

void editorvehiclecontroller::clearSlot()
{

    qDebug() << "premuto clear";
}

void editorvehiclecontroller::onClosedView() const
{
    delete this;
}

void editorvehiclecontroller::editVehicleSlot(){
    qDebug() << "Premuto editor veicoli";
}
