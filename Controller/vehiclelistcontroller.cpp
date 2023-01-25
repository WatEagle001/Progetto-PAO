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

    connect(v, SIGNAL(newVehicleSignal()), this, SLOT(newVehicleSlot()));
    connect(v, SIGNAL(addNewViaggioSignal()), this, SLOT(loadVehicleSlot()));
    connect(v, SIGNAL(editVehicleDetailsSignal()), this, SLOT(newVehicleSlot()));
    connect(v, SIGNAL(deleteVehicleSignal()), this, SLOT(newVehicleSlot()));

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

    QString path = JSONAgent::selectFile();
    QJsonDocument* veicoli = JSONAgent::getData(path);
    JSONAgent::getVehicleList(veicoli, *g);
    qDebug() << "stampa da dopo caricamento";
    g->printGarage();
    vehiclelist* vehicle = new vehiclelist(g,v->size(), v);
    vehicle->setTitle("Garage");
    vehiclelistcontroller* vehiclecontroller = new vehiclelistcontroller(vehicle, g, const_cast<controller*>(static_cast<const controller*>(this)));
       qDebug() << "stampa dopo aver caricato i veicoli";
       g->printGarage();
       vehiclecontroller->showView();
       v->hide();
    //manca da implementare la creazione dei veicolo in base a quanto letto dal JSON

}

void vehiclelistcontroller::newVehicleSlot()
{
   // g->printGarage();
    newvehicle* vehicle = new newvehicle(g,v->size(), v);
    vehicle->setTitle("Aggiunta Veicolo");
    newvehiclecontroller* vehiclecontroller = new newvehiclecontroller(vehicle, g, const_cast<controller*>(static_cast<const controller*>(this)));

    vehiclecontroller->showView();
       v->hide();

}

void vehiclelistcontroller::addViaggioSlot(veicolo * veic)
{
    string s = "Chilometri in Partenza: " + std::to_string(veic->getKm_odometro()) + "\nChilometri all'Arrivo: ";
    int newkm = QInputDialog::getInt(v, tr("Aggiungi Viaggio"), QString::fromStdString(s), veic->getKm_odometro(), veic->getKm_odometro(), INT_MAX, 1);

    if(newkm >= veic->getKm_odometro()){
        int diff = newkm - veic->getKm_odometro();
        veic->setKm_odometro(newkm);
        // Bisogna ricaricare il garage

        v->dialogPopUp_Information("Conferma Inserimento", "Il viggio dalla lunghezza di " + QString::fromStdString(std::to_string(diff)) +" km è stato inserito con successo nel sistema");
    }
    else {
        // Teoricamente questo errore non è raggiungibile, ma non si sa mai cosa si inventa l'utente
        v->dialogPopUp_Warning("Errore", "I chilometri finali non possono essere inferiori a quelli iniziali");
    }

    vehiclelist* veh = new vehiclelist(g,v->size(), v);
    veh->setTitle("Garage");
    vehiclelistcontroller* vc = new vehiclelistcontroller(veh, g, const_cast<controller*>(static_cast<const controller*>(this)));

    vc->showView();
    v->hide();
}

void vehiclelistcontroller::detailedCostsSlot(CostiViaggio *costi)
{
    c = costi;
    detailedcosts* cos = new detailedcosts(c,v->size(), v);
    detailedcostscontroller* costiV = new detailedcostscontroller(cos, c, const_cast<controller*>(static_cast<const controller*>(this)));
    costiV->showView();
}

void vehiclelistcontroller::editVehicleSlot(veicolo* veic)
{
    editorvehicle* vehicle = new editorvehicle(g,veic,v->size(), v);
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

void vehiclelistcontroller::addViaggioSlot()
{

}

void vehiclelistcontroller::editVehicleSlot()
{
    editorvehicle* vehicle = new editorvehicle(v->size(), v);
    editorvehiclecontroller* editor = new editorvehiclecontroller(vehicle, g, const_cast<controller*>(static_cast<const controller*>(this)));
    editor->showView();
}

void vehiclelistcontroller::deleteVehicleSlot()
{

}
