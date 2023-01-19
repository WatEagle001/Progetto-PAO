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

    connect(aggiungiViaggio,&QPushButton::clicked, (bind(&vehiclelist::addNewViaggioSignal, this, veic)));
    connect(elimina, &QPushButton::clicked, (bind(&vehiclelist::deleteVehicleSignal, this, veic)));
    connect(modifica, &QPushButton::clicked,(bind(&vehiclelist::editVehicleDetailsSignal, this, veic)));
    // connect(modifica, &QPushButton::clicked,(bind(&vehiclelist::editAutoDetailsSignal, this, veic)));
    connect(detailedView, &QPushButton::clicked,(bind(&vehiclelist::showVehicleDetails, this, veic)));


    pulsanti->addWidget(aggiungiViaggio);
    pulsanti->addWidget(modifica);
    pulsanti->addWidget(elimina);
    pulsanti->addWidget(detailedView);
    return pulsanti;
}

QWidget* vehiclelist::configureVheicleItem(veicolo* veic){
    qDebug() << "tipo veicolo passato al widget";
    qDebug() << typeid(*veic).name();
    QWidget* test = new QWidget;
    QHBoxLayout* list = new QHBoxLayout;
    veicoloWidget* wid = new veicoloWidget(veic);

    list->addLayout(wid->configureVehicleView(veic));
    list->addLayout(configureButtons(veic));

    test->setLayout(list);
    return test;
}

vehiclelist::vehiclelist(garage* garage,const QSize &s, view *parent) : view(s, parent), layout(new QVBoxLayout(this))
{
    g = garage;

    QHBoxLayout* buttons = new QHBoxLayout();
    add = new QPushButton("Aggiungi Veicolo", this);
    load = new QPushButton("Carica Veicolo", this);
    QLabel* costi = new QLabel("Costo gestione garage: " + QString::number(g->getCostoGarage()) + " €");

    buttons->addWidget(add);
    buttons->addWidget(load);
    buttons->addWidget(costi);

    QVBoxLayout* l = new QVBoxLayout;

    layout->addLayout(buttons);
    QScrollArea* scrollArea = new QScrollArea();
    layout->addWidget(scrollArea);


    for(int i = 0; i < g->size(); i++){
        qDebug() << typeid(*(g)->getVeicolo(i)).name();
        qDebug() << "-----------------------------------------------";
        if(dynamic_cast<automobile*>(g->getVeicolo(i))){
            automobile* tmp = new automobile(g->getVeicolo(i)->getMarca(), g->getVeicolo(i)->getModello(),g->getVeicolo(i)->getTarga(),g->getVeicolo(i)->getKm_odometro());
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
            auto_elettrica* tmp2 = new auto_elettrica(g->getVeicolo(i)->getMarca(), g->getVeicolo(i)->getModello(),g->getVeicolo(i)->getTarga(),g->getVeicolo(i)->getKm_odometro());
            QWidget* wtmp  =configureVheicleItem(tmp2);
            l->addWidget(wtmp);
        }
       /*if(dynamic_cast<moto_elettrica*>(g->getVeicolo(i))){
            moto_elettrica* tmp = new moto_elettrica(g->getVeicolo(i)->getMarca(), g->getVeicolo(i)->getModello(),g->getVeicolo(i)->getKm_odometro(),g->getVeicolo(i)->getTarga());
            QWidget* wtmp  =configureVheicleItem(tmp);
            l->addWidget(wtmp);
        }
        */
        else if(dynamic_cast<auto_ibrida*>(g->getVeicolo(i))){
            auto_ibrida* tmp = new auto_ibrida(g->getVeicolo(i)->getMarca(), g->getVeicolo(i)->getModello(),g->getVeicolo(i)->getTarga(),g->getVeicolo(i)->getKm_odometro());
            QWidget* wtmp  =configureVheicleItem(tmp);
            l->addWidget(wtmp);
        }
        else if(dynamic_cast<monopattino_elettrico*>(g->getVeicolo(i))){
            monopattino_elettrico* tmp = new monopattino_elettrico(g->getVeicolo(i)->getMarca(), g->getVeicolo(i)->getModello(),g->getVeicolo(i)->getTarga(),g->getVeicolo(i)->getKm_odometro());
            QWidget* wtmp  =configureVheicleItem(tmp);
            l->addWidget(wtmp);
        }
        else if(dynamic_cast<moto*>(g->getVeicolo(i))){
            moto* tmp = new moto(g->getVeicolo(i)->getMarca(), g->getVeicolo(i)->getModello(),g->getVeicolo(i)->getTarga(),g->getVeicolo(i)->getKm_odometro());
            QWidget* wtmp  =configureVheicleItem(tmp);
            l->addWidget(wtmp);
        }
        else{
            qDebug() <<"Fallito tutto";
            qDebug() << QString::fromStdString(g->getVeicolo(i)->getMarca()) << " " <<QString::fromStdString(g->getVeicolo(i)->getModello())<< " "<< QString::fromStdString(g->getVeicolo(i)->getTarga());
        }
    }

    scrollArea->setLayout(l);

    setLayout(layout);
    connectViewSignals();
}
