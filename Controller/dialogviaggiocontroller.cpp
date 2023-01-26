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

}

void dialogviaggiocontroller::onClosedView() const
{
    delete this;
}

