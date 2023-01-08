#include "vehiclelistcontroller.h"

void vehiclelistcontroller::connectViewController() const
{

}

vehiclelistcontroller::vehiclelistcontroller(vehiclelist *v, garage *g, controller *parent) : controller(v, m, parent)
{

}

view *vehiclelistcontroller::getView() const
{
    return static_cast<vehiclelist*>(v);
}

model *vehiclelistcontroller::getModel() const
{
    return static_cast<model*>(m);
}

void vehiclelistcontroller::onClosedView() const
{
    delete this;
}
