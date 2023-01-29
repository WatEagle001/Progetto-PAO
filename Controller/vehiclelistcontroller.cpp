#include "vehiclelistcontroller.h"

#include <Controller/detailedcostscontroller.h>
#include <Controller/detailedvehicleviewcontroller.h>
#include <Controller/dialogviaggiocontroller.h>
#include <Controller/editorvehiclecontroller.h>
#include <Controller/newvehiclecontroller.h>

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
    QCoreApplication::quit();
}

void vehiclelistcontroller::loadVehicleSlot()
{

    QString path = JSONAgent::selectFile();
    QJsonDocument* veicoli = JSONAgent::getData(path);


    JSONAgent::getVehicleList(veicoli, g);

    vehiclelist* vehicle = new vehiclelist(g,v->size(), nullptr);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, c,const_cast<controller*>(static_cast<const controller*>(this)));

    vehiclecontroller->showView();
    v->hide();

}

void vehiclelistcontroller::newVehicleSlot()
{
    newvehicle* vehicle = new newvehicle(g,v->size(), nullptr);
    vehicle->setTitle("Aggiunta Veicolo");
    newvehiclecontroller* vehiclecontroller = new newvehiclecontroller(vehicle, g, c,const_cast<controller*>(static_cast<const controller*>(this)));

    vehiclecontroller->showView();
    v->hide();


}

void vehiclelistcontroller::addViaggioSlot(veicolo* vec)
{

    DialogViaggio* dv = new DialogViaggio(vec, c, v->size(), nullptr);
    dialogviaggiocontroller* dvc = new dialogviaggiocontroller(dv, veic, g, c, const_cast<controller*>(static_cast<const controller*>(this)));
    dvc->showView();
    v->close();
}

void vehiclelistcontroller::detailedCostsSlot()
{
    detailedcosts* dc = new detailedcosts(c, v->size(), nullptr);
    detailedcostscontroller* dcc = new detailedcostscontroller(dc, c, g, const_cast<controller*>(static_cast<const controller*>(this)));
    dcc->showView();
    v->close();
}

void vehiclelistcontroller::editVehicleSlot(veicolo* veic)
{
    editorvehicle* vehicle = new editorvehicle(g,veic,v->size(), nullptr);
    editorvehiclecontroller* editor = new editorvehiclecontroller(vehicle, g, c,  const_cast<controller*>(static_cast<const controller*>(this)));

    editor->showView();
    v->hide();

}

void vehiclelistcontroller::deleteVehicleSlot(veicolo* veic)
{
    g->deleteVeicolo(veic);

    v->close();
    vehiclelist* vehicle = new vehiclelist(g,v->size(), nullptr);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, c,const_cast<controller*>(static_cast<const controller*>(this)));

    vehiclecontroller->showView();
    v->hide();

}

void vehiclelistcontroller::detailedVehicleViewSlot(veicolo *veic)
{
    detailedvehicleview* vehicledetails = new detailedvehicleview(veic,v->size(), nullptr);
    detailedvehicleviewcontroller* detailedController = new detailedvehicleviewcontroller(vehicledetails, g, c,const_cast<controller*>(static_cast<const controller*>(this)));
    detailedController->showView();
    v->close();
}

void vehiclelistcontroller::exportGarageSlot()
{
    bool tmp = JSONAgent::saveGarage(QFileDialog::getSaveFileName(nullptr, "Salva come", "../Progetto_PAO/Assets/doc", "JSON (*.json)"), g);

    if(!tmp){
        v->dialogPopUp_Warning("Errore", "Qualcosa è andato storto durante l'esportazione del file");
    }

    v->hide();

    vehiclelist* vehicle = new vehiclelist(g,v->size(), nullptr);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, c, const_cast<controller*>(static_cast<const controller*>(this)));

    vehiclecontroller->showView();
}
