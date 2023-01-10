#include "vehiclelistcontroller.h"
#include "QDebug"
#include "View/editorvehicle.h"
#include "Controller/editorvehiclecontroller.h"

void vehiclelistcontroller::connectViewController() const
{
    connect(v, SIGNAL(loadVehicleSignal()), this, SLOT(loadVehicleSlot()));
    connect(v, SIGNAL(newVehicleSignal()), this, SLOT(newVehicleSlot()));
}

vehiclelistcontroller::vehiclelistcontroller(vehiclelist *v, garage *g, controller *parent) : controller(v, m, parent)
{
    connectViewController();
}

view *vehiclelistcontroller::getView() const
{
    return static_cast<vehiclelist*>(v);
}

model *vehiclelistcontroller::getModel() const
{
    return static_cast<model*>(m);
}

void vehiclelistcontroller::loadGarage(garage& g) const
{

}

void vehiclelistcontroller::onClosedView() const
{
    delete this;
}

void vehiclelistcontroller::loadVehicleSlot() const
{
    QString path = JSONAgent::selectFile();
    QJsonDocument* veicoli = JSONAgent::getData(path);
    garage test = JSONAgent::getVehicleList(veicoli);
    test.printGarage();

}

void vehiclelistcontroller::newVehicleSlot() const
{
    editorvehicle* vehicle = new editorvehicle(v->size(), v);
    editorvehiclecontroller* editor = new editorvehiclecontroller(vehicle, new garage(), const_cast<controller*>(static_cast<const controller*>(this)));
    editor->showView();
    v->hide();

}


