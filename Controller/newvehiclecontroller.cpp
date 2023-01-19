#include "newvehiclecontroller.h"
#include "View/editorvehicle.h"
#include "vehiclelistcontroller.h"
#include "Model/garage.h"
#include <iostream>
#include "QDebug"

void newvehiclecontroller::connectViewController() const
{
   //connect(static_cast<editorvehicle*>(v), &editorvehicle::saveSignal, this, &newvehiclecontroller::saveSlot);
   //connect(static_cast<editorvehicle*>(v), &editorvehicle::saveSignalAuto, this, &newvehiclecontroller::saveSlotAuto);
   // connect(v, SIGNAL(clearSignal()), this, SLOT(clearSlot()));
}

newvehiclecontroller::newvehiclecontroller(newvehicle *v,garage *m,controller *parent) : controller(v, m, parent)
{
    g = m;
    connectViewController();
}

view *newvehiclecontroller::getView() const
{
    return static_cast<editorvehicle*>(v);
}

garage *newvehiclecontroller::getModel() const
{
    return static_cast<garage*>(m);
}


void newvehiclecontroller::saveSlot(veicolo* veic,veicolo* nuovo)
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
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, const_cast<controller*>(static_cast<const controller*>(this)));

       vehiclecontroller->showView();
       v->hide();

}
void newvehiclecontroller::saveSlotAuto(veicolo* veic,automobile* nuovoa)
{
   qDebug() << "test nuovo veicolo auto" ;
               qDebug() << QString::fromStdString(nuovoa->getMarca());
    // g->addVeicolo(veic);
    g->deleteVeicolo(veic);
    g->addVeicolo(nuovoa);
    //g->editVeicolo(veic,marca.toStdString(), modello.toStdString(), veic->getTarga(),km);
    qDebug() << "Stampa garage aggiornato";
    g->printGarage();
    //qDebug()<< QString::fromStdString(g->getVeicolo(0)->getMarca()) + QString::fromStdString(g->getVeicolo(0)->getModello());

    vehiclelist* vehicle = new vehiclelist(g,v->size(), v);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, const_cast<controller*>(static_cast<const controller*>(this)));

       vehiclecontroller->showView();
       v->hide();

}

void newvehiclecontroller::clearSlot()
{

    qDebug() << "premuto clear";
}

void newvehiclecontroller::onClosedView() const
{
    delete this;
}

void newvehiclecontroller::newVehicleSlot(){
    qDebug() << "Premuto aggiunta veicoli";
}
