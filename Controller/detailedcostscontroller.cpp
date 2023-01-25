#include "detailedcostscontroller.h"
#include "vehiclelistcontroller.h"
#include "Model/garage.h"
#include <iostream>
#include "QDebug"
#include <View/detailedcosts.h>

detailedcostscontroller::detailedcostscontroller(detailedcosts *v, CostiViaggio* dati,controller *parent) : controller(v, dati, parent)
{

    cost = dati;
    //connectViewController();
    //qDebug() << "stampa da welcomecontroller";
    //g->printGarage();

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
    delete this;
}
