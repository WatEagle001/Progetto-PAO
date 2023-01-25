#include "detailedvehicleviewcontroller.h"
#include "vehiclelistcontroller.h"
#include "QDebug"
#include "View/detailedvehicleview.h"

void detailedvehicleviewcontroller::connectViewController() const
{
    //connect(static_cast<vehiclelist*>(v), &vehiclelist::showVehicleDetails, this, &detailedvehicleviewcontroller::detailedVehicleViewSlot);
}

detailedvehicleviewcontroller::detailedvehicleviewcontroller(detailedvehicleview *v, garage* m, controller *parent) : controller(v,m, parent)
{
    //veic = v;
    connectViewController();
}

void detailedvehicleviewcontroller::detailedVehicleViewSlot()
{
    qDebug() << QString::fromStdString(veic->getTarga());
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
    delete this;
}

