#include "vehiclelistcontroller.h"
#include "QDebug"
#include "View/editorvehicle.h"
#include "Controller/editorvehiclecontroller.h"
void vehiclelistcontroller::connectViewController() const
{
    connect(v, SIGNAL(loadVehicleSignal()), this, SLOT(loadVehicleSlot()));
    connect(v, SIGNAL(newVehicleSignal()), this, SLOT(newVehicleSlot()));
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
//    *g  = JSONAgent::getVehicleList(veicoli);
//    g->printGarage();
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
