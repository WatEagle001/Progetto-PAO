#include "vehiclelistitemcontroller.h"
#include "QDebug"
#include "View/editorvehicle.h"
#include "Controller/editorvehiclecontroller.h"
/*void vehiclelistitemcontroller::connectViewController() const
{
   // connect(v, SIGNAL(editVehicleSignal(veic)), this, SLOT(editVehicleSlot(veci)));
   // connect(v, SIGNAL(newVehicleSignal()), this, SLOT(newVehicleSlot()));
}

vehiclelistitemcontroller::vehiclelistitemcontroller(vehicleListItem *v, veicolo* m, controller *parent) : controller(nullptr,nullptr, parent)
{
    veic = m;
    connectViewController();
}

view *vehiclelistitemcontroller::getView() const
{
    return static_cast<vehiclelist*>(v);
}

/*veicolo *vehiclelistitemcontroller::getModel() const
{
    return static_cast<veicolo*>(v);
}


void vehiclelistitemcontroller::onClosedView() const
{
    delete this;
}

*/
