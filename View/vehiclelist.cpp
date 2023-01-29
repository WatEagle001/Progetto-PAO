#include "vehiclelist.h"
#include <Controller/vehiclelistcontroller.h>
#include <Controller/welcomecontroller.h>


void vehiclelist::connectViewSignals() const{
    connect(add, SIGNAL(clicked()), this, SIGNAL(newVehicleSignal()));
    connect(load, SIGNAL(clicked()), this, SIGNAL(loadVehicleSignal()));
    connect(toExp, SIGNAL(clicked()), this, SIGNAL(exportGarage()));
    connect(detailedCosts,SIGNAL(clicked()),this,SIGNAL(detailedCostsSignal()));

}

void vehiclelist::closeEvent(QCloseEvent *event)
{
    //Elaboro chiusura solo se intenzionata da evento esterno
    if(!event->spontaneous()) return;

    if(!dialogPopUp_Question(2, "Uscita", "Sei sicuro di voler chiudere l'applicazione?\n")){
        event->ignore();
    }
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
    aggiungiViaggio = new QPushButton;
    aggiungiViaggio->setIcon(QIcon(":/Assets/image/icons/add.png"));
    aggiungiViaggio->setFixedSize(40, 40);
    modifica = new QPushButton;
    modifica->setIcon(QIcon(":/Assets/image/icons/editing.png"));
    modifica->setFixedSize(40,40);
    elimina = new QPushButton;
    elimina->setIcon(QIcon(":/Assets/image/icons/delete.png"));
    elimina->setFixedSize(40,40);
    detailedView = new QPushButton;
    detailedView->setIcon(QIcon(":/Assets/image/icons/info.png"));
    detailedView->setFixedSize(40,40);


    connect(elimina, &QPushButton::clicked, (bind(&vehiclelist::deleteVehicleSignal, this, veic)));
    connect(aggiungiViaggio, &QPushButton::clicked, (bind(&vehiclelist::addNewViaggioSignal, this, veic)));
    connect(modifica, &QPushButton::clicked,(bind(&vehiclelist::editVehicleDetailsSignal, this, veic)));
    connect(detailedView, &QPushButton::clicked,(bind(&vehiclelist::showVehicleDetails, this, veic)));

    pulsanti->addWidget(aggiungiViaggio);
    pulsanti->addWidget(modifica);
    pulsanti->addWidget(elimina);
    pulsanti->addWidget(detailedView);
    return pulsanti;
}

QWidget* vehiclelist::configureVheicleItem(veicolo* veic){
    QWidget* test = new QWidget;
    QHBoxLayout* list = new QHBoxLayout;
    veicoloWidget* wid = new veicoloWidget(veic);

    list->addLayout(wid->configureVehicleView(veic));
    list->addLayout(configureButtons(veic));

    test->setLayout(list);
    return test;
}

vehiclelist::vehiclelist(garage* garage,const QSize &s, view *parent) : view(s,parent), layout(new QVBoxLayout(this))
{
    g = garage;

    QHBoxLayout* buttons = new QHBoxLayout(this);
    add = new QPushButton("Aggiungi Veicolo", this);
    load = new QPushButton("Carica Veicolo", this);
    detailedCosts = new QPushButton("Dettaglio Viaggi", this);
    toExp = new QPushButton("Esporta Garage", this);
    QLabel* costi = new QLabel("Costo gestione garage: " + QString::number(g->getCostoGarage()) + " €");

    buttons->addWidget(add);
    buttons->addWidget(load);
    buttons->addWidget(toExp);
    buttons->addWidget(detailedCosts);
    buttons->addWidget(costi);

    layout->addLayout(buttons);

    QWidget *window = new QWidget(this);
    QVBoxLayout *l = new QVBoxLayout(window);

    for(int i = 0; i < g->size(); i++){
        if(dynamic_cast<automobile*>(g->getVeicolo(i))){
            automobile* tmp = dynamic_cast<automobile*>(g->getVeicolo(i));
            QWidget* wtmp =configureVheicleItem(tmp);
            l->addWidget(wtmp);
        }

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
    }

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidget(window);
    scrollArea->setWidgetResizable(true);
    layout->addWidget(scrollArea);

    vehiclelist::connectViewSignals();
}
