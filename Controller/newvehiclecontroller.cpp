#include "newvehiclecontroller.h"
#include "View/editorvehicle.h"
#include "vehiclelistcontroller.h"
#include "Model/garage.h"
#include <iostream>
#include "QDebug"

void newvehiclecontroller::connectViewController() const
{
   connect(static_cast<editorvehicle*>(v), &editorvehicle::saveSignal, this, &newvehiclecontroller::saveSlot);
}

newvehiclecontroller::newvehiclecontroller(newvehicle *v,garage *m,CostiViaggio* cost,controller *parent, veicolo* veicol) : controller(v, m, parent)
{
    veic = veicol;
    c = cost;
    g = m;
    connectViewController();
}

view *newvehiclecontroller::getView() const
{
    return static_cast<newvehicle*>(v);
}

garage *newvehiclecontroller::getModel() const
{
    return static_cast<garage*>(m);
}


void newvehiclecontroller::saveSlot(veicolo* veic)
{
    g->addVeicolo(veic);

    vehiclelist* vehicle = new vehiclelist(g,v->size(), nullptr);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, c, const_cast<controller*>(static_cast<const controller*>(this)));

    vehiclecontroller->showView();
    v->close();

}

void newvehiclecontroller::onClosedView() const
{
    vehiclelist* vehicle = new vehiclelist(g,v->size(), nullptr);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, c, const_cast<controller*>(static_cast<const controller*>(this)));

    vehiclecontroller->showView();
    v->close();

}

void newvehiclecontroller::clearSlot(){

}

