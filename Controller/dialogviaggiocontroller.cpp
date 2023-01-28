#include "dialogviaggiocontroller.h"

void dialogviaggiocontroller::connectViewController() const
{
    connect(static_cast<DialogViaggio*>(v), &DialogViaggio::tryAddViaggio, this, &dialogviaggiocontroller::saveViaggio);
}

view *dialogviaggiocontroller::getView() const
{
    return static_cast<DialogViaggio*>(v);
}

model *dialogviaggiocontroller::getModel() const
{
    return static_cast<garage*>(m);
}

dialogviaggiocontroller::dialogviaggiocontroller(DialogViaggio *v, veicolo *vehicle, garage* g, CostiViaggio* costi, controller *parent) : controller(v, g, parent)
{
    m = g;
    c = costi;
    veic = vehicle;
    connectViewController();
}

void dialogviaggiocontroller::saveViaggio(veicolo* veic, string partenza, string arrivo, int km_percorsi, double efficienza, double costo_carburante, double costo_elettricita)
{

    c->addViaggio(veic,partenza,arrivo,km_percorsi,efficienza,costo_carburante,costo_elettricita);
    veic->setKm_odometro(veic->getKm_odometro() + km_percorsi);

    vehiclelist* vehicle = new vehiclelist(m,v->size(), nullptr);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, m, c, const_cast<controller*>(static_cast<const controller*>(this)));

    vehiclecontroller->showView();
    v->hide();

}

void dialogviaggiocontroller::onClosedView() const
{
    vehiclelist* vehicle = new vehiclelist(m,v->size(), nullptr);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, m, c, const_cast<controller*>(static_cast<const controller*>(this)));

    vehiclecontroller->showView();
    v->hide();
}

