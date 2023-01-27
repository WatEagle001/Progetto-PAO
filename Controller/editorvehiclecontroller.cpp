#include "editorvehiclecontroller.h"
#include "View/editorvehicle.h"
#include "vehiclelistcontroller.h"
#include "Model/garage.h"
#include <iostream>
#include "QDebug"

void editorvehiclecontroller::connectViewController() const
{
   connect(static_cast<editorvehicle*>(v), &editorvehicle::saveSignal, this, &editorvehiclecontroller::saveSlot);
   //connect(static_cast<editorvehicle*>(v), &editorvehicle::saveSignalAuto, this, &editorvehiclecontroller::saveSlotAuto);
    connect(v, SIGNAL(clearSignal()), this, SLOT(clearSlot()));
}

editorvehiclecontroller::editorvehiclecontroller(editorvehicle *v, garage *m, CostiViaggio *costi, controller *parent, veicolo* n) : controller(v, m, parent)
{
    g = m;
    c = costi;
    nuovo = n;
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


void editorvehiclecontroller::saveSlot(veicolo* veic,veicolo* nuovo)
{
    g->deleteVeicolo(veic);
    g->addVeicolo(nuovo);

    vehiclelist* vehicle = new vehiclelist(g,v->size(), v);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, c, const_cast<controller*>(static_cast<const controller*>(this)));

    vehiclecontroller->showView();
    v->hide();


}

void editorvehiclecontroller::onClosedView() const
{
    v->close();
    delete this;
}

void editorvehiclecontroller::editVehicleSlot(){

}

void editorvehiclecontroller::clearSlot(){

}
