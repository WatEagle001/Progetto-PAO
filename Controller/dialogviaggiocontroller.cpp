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
    qDebug() << QString::fromStdString(veic->getTarga());
    qDebug() << QString::fromStdString(partenza);
    qDebug() << QString::fromStdString(arrivo);
    qDebug() << QString::number(km_percorsi);
    c->addViaggio(veic,partenza,arrivo,km_percorsi,efficienza,costo_carburante,costo_elettricita);

    v->close();

}

void dialogviaggiocontroller::onClosedView() const
{
     delete this;
}

