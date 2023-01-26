#include "editorvehiclecontroller.h"
#include "View/editorvehicle.h"
#include "vehiclelistcontroller.h"
#include "Model/garage.h"
#include <iostream>
#include "QDebug"

void editorvehiclecontroller::connectViewController() const
{
   connect(static_cast<editorvehicle*>(v), &editorvehicle::saveSignal, this, &editorvehiclecontroller::saveSlot);
   //connect(static_cast<editorvehicle*>(v), &editorvehicle::saveSignalAuto, this, &editorvehiclecontroller::saveSlotAuto);
    connect(v, SIGNAL(clearSignal()), this, SLOT(clearSlot()));
}

editorvehiclecontroller::editorvehiclecontroller(editorvehicle *v, garage *m, CostiViaggio *costi, controller *parent, veicolo* n) : controller(v, m, parent)
{
    g = m;
    c = costi;
    nuovo = n;
    connectViewController();

}

view *editorvehiclecontroller::getView() const
{
    return static_cast<editorvehicle*>(v);
}

garage *editorvehiclecontroller::getModel() const
{
    return static_cast<garage*>(m);
}


void editorvehiclecontroller::saveSlot(veicolo* veic,veicolo* nuovo)
{
   qDebug() << "test nuovo veicolo" ;
               qDebug() << QString::fromStdString(nuovo->getMarca());
    // g->addVeicolo(veic);
    g->deleteVeicolo(veic);
    g->addVeicolo(nuovo);
    //g->editVeicolo(veic,marca.toStdString(), modello.toStdString(), veic->getTarga(),km);
    qDebug() << "Stampa garage aggiornato";
    g->printGarage();
    //qDebug()<< QString::fromStdString(g->getVeicolo(0)->getMarca()) + QString::fromStdString(g->getVeicolo(0)->getModello());

    vehiclelist* vehicle = new vehiclelist(g,v->size(), v);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, c, const_cast<controller*>(static_cast<const controller*>(this)));

       vehiclecontroller->showView();
       v->hide();

}


void editorvehiclecontroller::clearSlot()
{

    qDebug() << "premuto clear";
}

void editorvehiclecontroller::onClosedView() const
{
    delete this;
}

void editorvehiclecontroller::editVehicleSlot(){
    qDebug() << "Premuto editor veicoli";
}
