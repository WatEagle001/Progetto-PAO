#include "newvehiclecontroller.h"
#include "View/editorvehicle.h"
#include "vehiclelistcontroller.h"
#include "Model/garage.h"
#include <iostream>
#include "QDebug"

void newvehiclecontroller::connectViewController() const
{
   connect(static_cast<editorvehicle*>(v), &editorvehicle::saveSignal, this, &newvehiclecontroller::saveSlot);
   connect(v, SIGNAL(clearSignal()), this, SLOT(clearSlot()));
}

newvehiclecontroller::newvehiclecontroller(newvehicle *v,garage *m,controller *parent, veicolo* veicol) : controller(v, m, parent)
{
    veic = veicol;
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


    vehiclelist* vehicle = new vehiclelist(g,v->size(), v);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, nullptr, const_cast<controller*>(static_cast<const controller*>(this)));

    vehiclecontroller->showView();
    v->hide();

}

void newvehiclecontroller::onClosedView() const
{
    delete this;
}

void newvehiclecontroller::clearSlot(){

}
