#include "detailedvehicleviewcontroller.h"
#include <Controller/vehiclelistcontroller.h>

void detailedvehicleviewcontroller::connectViewController() const
{
    // Questo Controller Non Possiede Slot Propri
}

detailedvehicleviewcontroller::detailedvehicleviewcontroller(detailedvehicleview *v, garage* m, CostiViaggio* cost, controller *parent) : controller(v,m, parent){
    g = m;
    c = cost;
}


view *detailedvehicleviewcontroller::getView() const
{
    return static_cast<detailedvehicleview*>(v);
}

garage *detailedvehicleviewcontroller::getModel() const
{
    return static_cast<garage*>(m);
}

void detailedvehicleviewcontroller::onClosedView() const
{

    vehiclelist* vehicle = new vehiclelist(g,v->size(), nullptr);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, c, const_cast<controller*>(static_cast<const controller*>(this)));

    vehiclecontroller->showView();

    v->hide();
}

