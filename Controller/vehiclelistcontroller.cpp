#include "vehiclelistcontroller.h"
#include "QDebug"
#include "View/editorvehicle.h"
#include "Controller/editorvehiclecontroller.h"
#include "View/detailedvehicleview.h"
#include "Controller/detailedvehicleviewcontroller.h"
void vehiclelistcontroller::connectViewController() const
{
    connect(v, SIGNAL(loadVehicleSignal()), this, SLOT(loadVehicleSlot()));
    connect(v, SIGNAL(newVehicleSignal()), this, SLOT(newVehicleSlot()));
    connect(v, SIGNAL(addNewViaggioSignal()), this, SLOT(loadVehicleSlot()));
    connect(static_cast<vehiclelist*>(v), &vehiclelist::editVehicleDetailsSignal, this, &vehiclelistcontroller::editVehicleSlot);
    connect(static_cast<vehiclelist*>(v), &vehiclelist::deleteVehicleSignal, this, &vehiclelistcontroller::deleteVehicleSlot);
    connect(static_cast<vehiclelist*>(v), &vehiclelist::showVehicleDetails, this, &vehiclelistcontroller::detailedVehicleViewSlot);
}

vehiclelistcontroller::vehiclelistcontroller(vehiclelist *v, garage* m, controller *parent) : controller(v,m, parent)
{
    g = m;
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
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, const_cast<controller*>(static_cast<const controller*>(this)));

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

void vehiclelistcontroller::addViaggioSlot()
{

}

void vehiclelistcontroller::editVehicleSlot(veicolo* veic)
{
    editorvehicle* vehicle = new editorvehicle(veic,v->size(), v);
    editorvehiclecontroller* editor = new editorvehiclecontroller(vehicle, g, const_cast<controller*>(static_cast<const controller*>(this)));
    editor->showView();
}

void vehiclelistcontroller::deleteVehicleSlot(veicolo* veic)
{
   g->deleteVeicolo(veic);
   g->printGarage();

    vehiclelist* vehicle = new vehiclelist(g,v->size(), v);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, const_cast<controller*>(static_cast<const controller*>(this)));

       vehiclecontroller->showView();
       v->hide();
}

void vehiclelistcontroller::detailedVehicleViewSlot(veicolo *veic)
{
    qDebug() << QString::fromStdString(veic->getTarga());
    detailedvehicleview* vehicledetails = new detailedvehicleview(veic,v->size(), v);
    detailedvehicleviewcontroller* detailedController = new detailedvehicleviewcontroller(vehicledetails, g, const_cast<controller*>(static_cast<const controller*>(this)));
    detailedController->showView();

}
