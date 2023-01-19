#include "vehiclelistcontroller.h"
#include "QDebug"
#include "View/editorvehicle.h"
#include "Controller/editorvehiclecontroller.h"
#include "View/detailedvehicleview.h"
#include "Controller/detailedvehicleviewcontroller.h"
#include <QInputDialog>
#include "View/newvehicle.h"
#include "Controller/newvehiclecontroller.h"
void vehiclelistcontroller::connectViewController() const
{
    connect(v, SIGNAL(loadVehicleSignal()), this, SLOT(loadVehicleSlot()));
    connect(v, SIGNAL(newVehicleSignal()), this, SLOT(newVehicleSlot()));
    connect(static_cast<vehiclelist*>(v), &vehiclelist::addNewViaggioSignal, this, &vehiclelistcontroller::addViaggioSlot);
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
    newvehicle* vehicle = new newvehicle(g,nullptr,v->size(), v);
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
