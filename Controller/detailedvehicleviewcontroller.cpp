#include "detailedvehicleviewcontroller.h"
#include "vehiclelistcontroller.h"
#include "QDebug"
#include "View/detailedvehicleview.h"

void detailedvehicleviewcontroller::connectViewController() const
{
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

    vehiclelist* vehicle = new vehiclelist(g,v->size(), v);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, c, const_cast<controller*>(static_cast<const controller*>(this)));

    vehiclecontroller->showView();

    v->hide();
}

