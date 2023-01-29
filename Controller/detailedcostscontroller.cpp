#include "detailedcostscontroller.h"
#include <Controller/vehiclelistcontroller.h>

detailedcostscontroller::detailedcostscontroller(detailedcosts *v, CostiViaggio* dati, garage* g, controller *parent) : controller(v, dati, parent)
{
    cost = dati;
    gar = g;
}

detailedcosts *detailedcostscontroller::getView() const
{
    return static_cast<detailedcosts*>(v);
}

model *detailedcostscontroller::getModel() const
{
    // La schermata di benvenuto non conteiene modelli
    return nullptr;
}

void detailedcostscontroller::onClosedView() const
{
    vehiclelist* vehicle = new vehiclelist(gar,v->size(), nullptr);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, gar, cost,  const_cast<controller*>(static_cast<const controller*>(this)));

    vehiclecontroller->showView();
    v->hide();

}
