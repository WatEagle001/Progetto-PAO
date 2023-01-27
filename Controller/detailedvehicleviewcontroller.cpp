#include "detailedvehicleviewcontroller.h"
#include "vehiclelistcontroller.h"
#include "QDebug"
#include "View/detailedvehicleview.h"

void detailedvehicleviewcontroller::connectViewController() const
{
}

detailedvehicleviewcontroller::detailedvehicleviewcontroller(detailedvehicleview *v, garage* m, controller *parent) : controller(v,m, parent){}


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
    v->close();
    delete this;
}

