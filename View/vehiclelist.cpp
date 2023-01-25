#include "vehiclelist.h"
#include <QTableView>
#include <QLabel>
#include <QScrollArea>
#include <Controller/vehiclelistcontroller.h>
#include <Controller/welcomecontroller.h>
#include <iostream>

#include "View/detailedvehicleview.h"

using std::bind;

void vehiclelist::connectViewSignals() const{
    connect(add, SIGNAL(clicked()), this, SIGNAL(newVehicleSignal()));
    connect(load, SIGNAL(clicked()), this, SIGNAL(loadVehicleSignal()));
    //connect(detailedCosts, SIGNAL(clicked()), this, SIGNAL(detailedCostsSignal()));
    connect(toExp, SIGNAL(clicked()), this, SIGNAL(exportGarage()));

}

void vehiclelist::closeEvent(QCloseEvent *event)
{
            if(!event->spontaneous()) return;
            else {
                //Accetto l'evento di chiusura della finestra
                event->accept();
                //Emetto segnale di chiusura della View
                emit viewClosed();
            }
}

QHBoxLayout *vehiclelist::configureButtons(veicolo* veic)
{
    pulsanti = new QHBoxLayout;
    aggiungiViaggio = new QPushButton(QString("Add"));
    aggiungiViaggio->setFixedSize(40, 40);
    modifica = new QPushButton(QString("Edit"));
    modifica->setFixedSize(40,40);
    elimina = new QPushButton(QString("Delete"));
    elimina->setFixedSize(40,40);
    detailedView = new QPushButton(QString("Dettagli"));
    detailedView->setFixedSize(60,40);


    connect(elimina, &QPushButton::clicked, (bind(&vehiclelist::deleteVehicleSignal, this, veic)));
    connect(aggiungiViaggio, &QPushButton::clicked, (bind(&vehiclelist::addNewViaggioSignal, this, veic, c)));
    connect(modifica, &QPushButton::clicked,(bind(&vehiclelist::editVehicleDetailsSignal, this, veic)));
    // connect(modifica, &QPushButton::clicked,(bind(&vehiclelist::editAutoDetailsSignal, this, veic)));
    connect(detailedView, &QPushButton::clicked,(bind(&vehiclelist::showVehicleDetails, this, veic)));
    connect(detailedCosts, &QPushButton::clicked,(bind(&vehiclelist::detailedCostsSignal, this, c)));


    pulsanti->addWidget(aggiungiViaggio);
    pulsanti->addWidget(modifica);
    pulsanti->addWidget(elimina);
    pulsanti->addWidget(detailedView);
    return pulsanti;
}

QWidget* vehiclelist::configureVheicleItem(veicolo* veic){
    //qDebug() << "tipo veicolo passato al widget";
    //qDebug() << typeid(*veic).name();
   // qDebug() << typeid(veic).name();
    QWidget* test = new QWidget;
    QHBoxLayout* list = new QHBoxLayout;
    veicoloWidget* wid = new veicoloWidget(veic);

    list->addLayout(wid->configureVehicleView(veic));
    list->addLayout(configureButtons(veic));

    test->setLayout(list);
    return test;
}

vehiclelist::vehiclelist(garage* garage,const QSize &s, view *parent) : view(s), layout(new QVBoxLayout(this))
{
    g = garage;

    QHBoxLayout* buttons = new QHBoxLayout();
    add = new QPushButton("Aggiungi Veicolo", this);
    load = new QPushButton("Carica Veicolo", this);
    detailedCosts = new QPushButton("Dettaglio Viaggi", this);
    toExp = new QPushButton("Esporta Garage", this);
    QLabel* costi = new QLabel("Costo gestione garage: " + QString::number(g->getCostoGarage()) + " €");

    buttons->addWidget(add);
    buttons->addWidget(load);
    buttons->addWidget(toExp);
    buttons->addWidget(costi);
    buttons->addWidget(detailedCosts);
    
    QVBoxLayout* l = new QVBoxLayout;

    layout->addLayout(buttons);
    QScrollArea* scrollArea = new QScrollArea();
    layout->addWidget(scrollArea);


    for(int i = 0; i < g->size(); i++){
       // qDebug() << typeid(*(g)->getVeicolo(i)).name();
       // qDebug() << "-----------------------------------------------";
        if(dynamic_cast<automobile*>(g->getVeicolo(i))){
            automobile* tmp = dynamic_cast<automobile*>(g->getVeicolo(i));
            QWidget* wtmp =configureVheicleItem(tmp);
            l->addWidget(wtmp);
        }
        /*else if(dynamic_cast<veicolo*>(g->getVeicolo(i))){
            veicolo* tmp1 = new veicolo(g->getVeicolo(i)->getMarca(), g->getVeicolo(i)->getModello(),g->getVeicolo(i)->getTarga(),g->getVeicolo(i)->getKm_odometro());
            QWidget* wtmp =configureVheicleItem(tmp1);
            l->addWidget(wtmp);
        }
        */
        else if(dynamic_cast<auto_elettrica*>(g->getVeicolo(i))){
            auto_elettrica* tmp2 = dynamic_cast<auto_elettrica*>(g->getVeicolo(i));
            QWidget* wtmp  =configureVheicleItem(tmp2);
            l->addWidget(wtmp);
        }
       if(dynamic_cast<moto_elettrica*>(g->getVeicolo(i))){
            moto_elettrica* tmp = dynamic_cast<moto_elettrica*>(g->getVeicolo(i));
            QWidget* wtmp  =configureVheicleItem(tmp);
            l->addWidget(wtmp);
        }

        else if(dynamic_cast<auto_ibrida*>(g->getVeicolo(i))){
            auto_ibrida* tmp3 = dynamic_cast<auto_ibrida*>(g->getVeicolo(i));
            QWidget* wtmp  =configureVheicleItem(tmp3);
            l->addWidget(wtmp);
        }
        else if(dynamic_cast<monopattino_elettrico*>(g->getVeicolo(i))){
            monopattino_elettrico* tmp4 = dynamic_cast<monopattino_elettrico*>(g->getVeicolo(i));
            QWidget* wtmp  =configureVheicleItem(tmp4);
            l->addWidget(wtmp);
        }
        else if(dynamic_cast<moto*>(g->getVeicolo(i))){
            moto* tmp = dynamic_cast<moto*>(g->getVeicolo(i));
            QWidget* wtmp  =configureVheicleItem(tmp);
            l->addWidget(wtmp);
        }
        /*else{
            qDebug() <<"Fallito tutto";
        }
        */
    }

    scrollArea->setLayout(l);

    setLayout(layout);
    connectViewSignals();
}
