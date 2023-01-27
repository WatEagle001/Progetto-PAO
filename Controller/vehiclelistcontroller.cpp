#include "vehiclelistcontroller.h"
#include "QDebug"
#include "View/editorvehicle.h"
#include "Controller/editorvehiclecontroller.h"
#include "View/detailedvehicleview.h"
#include "Controller/detailedvehicleviewcontroller.h"
#include <QInputDialog>
#include "View/newvehicle.h"
#include "Controller/newvehiclecontroller.h"
#include <View/detailedcosts.h>
#include <Controller/detailedcostscontroller.h>

void vehiclelistcontroller::connectViewController() const
{
    connect(v, SIGNAL(loadVehicleSignal()), this, SLOT(loadVehicleSlot()));

    connect(static_cast<vehiclelist*>(v), &vehiclelist::newVehicleSignal, this, &vehiclelistcontroller::newVehicleSlot);
    connect(static_cast<vehiclelist*>(v), &vehiclelist::addNewViaggioSignal, this, &vehiclelistcontroller::addViaggioSlot);
    connect(static_cast<vehiclelist*>(v), &vehiclelist::editVehicleDetailsSignal, this, &vehiclelistcontroller::editVehicleSlot);
    connect(static_cast<vehiclelist*>(v), &vehiclelist::deleteVehicleSignal, this, &vehiclelistcontroller::deleteVehicleSlot);
    connect(static_cast<vehiclelist*>(v), &vehiclelist::showVehicleDetails, this, &vehiclelistcontroller::detailedVehicleViewSlot);
    connect(static_cast<vehiclelist*>(v), &vehiclelist::detailedCostsSignal, this, &vehiclelistcontroller::detailedCostsSlot);
    connect(v, SIGNAL(exportGarage()), this, SLOT(exportGarageSlot()));
}

vehiclelistcontroller::vehiclelistcontroller(vehiclelist *v, garage* m, CostiViaggio* costi,controller *parent) : controller(v,m, parent)
{
    g = m;
    c = costi;
    connectViewController();

    qDebug()  << "costo maxxx" << c->getCostoMax();
}

view *vehiclelistcontroller::getView() const
{
    return static_cast<vehiclelist*>(v);
}

garage *vehiclelistcontroller::getModel() const
{
    return static_cast<garage*>(g);
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

    v->close();
    vehiclelist* vehicle = new vehiclelist(g,v->size(), v);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, c,const_cast<controller*>(static_cast<const controller*>(this)));

    vehiclecontroller->showView();
    v->hide();

}

void vehiclelistcontroller::newVehicleSlot()
{
    newvehicle* vehicle = new newvehicle(g,v->size(), v);
    vehicle->setTitle("Aggiunta Veicolo");
    newvehiclecontroller* vehiclecontroller = new newvehiclecontroller(vehicle, g, c,const_cast<controller*>(static_cast<const controller*>(this)));

    vehiclecontroller->showView();


}

void vehiclelistcontroller::addViaggioSlot(veicolo* vec)
{
    qDebug() << c->getCostoMax();
    qDebug() << "Creazione View Dialog Viaggio\n";
    DialogViaggio* dv = new DialogViaggio(vec, c, v->size(), v);
    dialogviaggiocontroller* dvc = new dialogviaggiocontroller(dv, veic, g, c, const_cast<controller*>(static_cast<const controller*>(this)));
    dvc->showView();
}

void vehiclelistcontroller::detailedCostsSlot()
{
    detailedcosts* dc = new detailedcosts(c, v->size(), v);
    detailedcostscontroller* dcc = new detailedcostscontroller(dc, c, const_cast<controller*>(static_cast<const controller*>(this)));
    dcc->showView();
}

void vehiclelistcontroller::editVehicleSlot(veicolo* veic)
{
    editorvehicle* vehicle = new editorvehicle(g,veic,v->size(), v);
    editorvehiclecontroller* editor = new editorvehiclecontroller(vehicle, g, c,  const_cast<controller*>(static_cast<const controller*>(this)));
    editor->showView();
}

void vehiclelistcontroller::deleteVehicleSlot(veicolo* veic)
{
   g->deleteVeicolo(veic);
   g->printGarage();

   v->close();
    vehiclelist* vehicle = new vehiclelist(g,v->size(), v);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, c,const_cast<controller*>(static_cast<const controller*>(this)));

    vehiclecontroller->showView();

}

void vehiclelistcontroller::detailedVehicleViewSlot(veicolo *veic)
{
    qDebug() << QString::fromStdString(veic->getTarga());
    detailedvehicleview* vehicledetails = new detailedvehicleview(veic,v->size(), v);
    detailedvehicleviewcontroller* detailedController = new detailedvehicleviewcontroller(vehicledetails, g, const_cast<controller*>(static_cast<const controller*>(this)));
    detailedController->showView();

}

void vehiclelistcontroller::exportGarageSlot()
{
    JSONAgent::saveGarage(QFileDialog::getSaveFileName(nullptr, "Salva come", "../Progetto_PAO/Assets/doc", "JSON (*.json)"), g);
}
