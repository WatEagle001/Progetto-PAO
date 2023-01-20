#include "vehiclelistcontroller.h"
#include "QDebug"
#include "View/editorvehicle.h"
#include "Controller/editorvehiclecontroller.h"
void vehiclelistcontroller::connectViewController() const
{
    connect(v, SIGNAL(loadVehicleSignal()), this, SLOT(loadVehicleSlot()));
    connect(v, SIGNAL(newVehicleSignal()), this, SLOT(newVehicleSlot()));
    connect(static_cast<vehiclelist*>(v), &vehiclelist::addNewViaggioSignal, this, &vehiclelistcontroller::addViaggioSlot);
    connect(static_cast<vehiclelist*>(v), &vehiclelist::editVehicleDetailsSignal, this, &vehiclelistcontroller::editVehicleSlot);
    connect(v, SIGNAL(deleteVehicleSignal()), this, SLOT(newVehicleSlot()));
}

vehiclelistcontroller::vehiclelistcontroller(vehiclelist *v, garage* m, CostiViaggio* costi,controller *parent) : controller(v,m, parent)
{
    g = m;
    c = costi;
    connectViewController();
}

view *vehiclelistcontroller::getView() const
{
    return static_cast<vehiclelist*>(v);
}

garage *vehiclelistcontroller::getModel() const
{
    return static_cast<garage*>(g);
}

void vehiclelistcontroller::loadGarage(garage &g) const
{

}

void vehiclelistcontroller::onClosedView() const
{
    delete this;
}

void vehiclelistcontroller::loadVehicleSlot()
{
     JSONAgent* js = new JSONAgent(g);
    QString path = js->selectFile();
    QJsonDocument* veicoli = js->getData(path);



    js->getVehicleList(veicoli, g);


    vehiclelist* vehicle = new vehiclelist(g,v->size(), v);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, c,const_cast<controller*>(static_cast<const controller*>(this)));

    vehiclecontroller->showView();
    v->hide();

}

void vehiclelistcontroller::newVehicleSlot()
{
    /*editorvehicle* vehicle = new editorvehicle(veic,v->size(), v);
    editorvehiclecontroller* editor = new editorvehiclecontroller(vehicle, g, const_cast<controller*>(static_cast<const controller*>(this)));
    editor->showView();
    v->hide();
    */

}

void vehiclelistcontroller::addViaggioSlot(veicolo * vec, CostiViaggio* costi)
{
    DialogViaggio* dv = new DialogViaggio(vec, costi, v->size(), v);
    dialogviaggiocontroller* dvc = new dialogviaggiocontroller(dv, vec, g, c, const_cast<controller*>(static_cast<const controller*>(this)));
    dvc->showView();
}

void vehiclelistcontroller::editVehicleSlot(veicolo* veic)
{
    editorvehicle* vehicle = new editorvehicle(veic,v->size(), v);
    editorvehiclecontroller* editor = new editorvehiclecontroller(vehicle, g, const_cast<controller*>(static_cast<const controller*>(this)));
    editor->showView();
}

void vehiclelistcontroller::deleteVehicleSlot()
{

}
