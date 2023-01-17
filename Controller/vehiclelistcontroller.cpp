#include "vehiclelistcontroller.h"
#include "QDebug"
#include "View/editorvehicle.h"
#include "Controller/editorvehiclecontroller.h"
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
    //qDebug()<<"stampo garage schermata principale";
    //veicolo a("audi", "a8", "cc111ee", 100);
    //getModel()->addVeicolo(&a);
    //getModel()->printGarage();
    editorvehicle* vehicle = new editorvehicle(v->size(), v);
    editorvehiclecontroller* editor = new editorvehiclecontroller(vehicle, g, const_cast<controller*>(static_cast<const controller*>(this)));
    editor->showView();
    v->hide();

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
