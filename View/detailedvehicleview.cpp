#include "detailedvehicleview.h"
#include <QString>
#include <iostream>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <Model/veicolo.h>
#include <Model/automobile.h>
#include <Model/moto.h>
#include <Model/auto_ibrida.h>
#include <Model/moto_elettrica.h>
#include <Model/monopattino_elettrico.h>
#include <Model/auto_elettrica.h>

QLayout *detailedvehicleview::configureFinalLayout(){
    // Creazione Layout
    QBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addLayout(configureEditor());
    // Aggiunta dei Vari Componenti al Layout

    return mainLayout;
}

QFormLayout *detailedvehicleview::configureEditor(){
       tipoAlimentazione = new QComboBox;
       layout = new QFormLayout;
       layout->insertRow(1,new QLabel(tr("Marca")), new QLabel(QString::fromStdString(v->getMarca())));
       layout->insertRow(2,new QLabel(tr("Modello")), new QLabel(QString::fromStdString(v->getModello())));
       layout->insertRow(3,new QLabel(tr("Targa")), new QLabel(QString::fromStdString(v->getTarga())));;
       layout->insertRow(4,new QLabel(tr("Km Odometro")), new QLabel(QString::number(v->getKm_odometro())));
    addMoreOptions();

    tipoAlimentazione->addItem(QString("Benzina"));
    tipoAlimentazione->addItem(QString("Diesel"));
    tipoAlimentazione->addItem(QString("Metano"));
    tipoAlimentazione->addItem(QString("GPL"));
    tipoAlimentazione->addItem(QString("BioDiesel"));
    tipoAlimentazione->addItem(QString("Idrogeno"));


    return layout;
}
QFormLayout* detailedvehicleview::addMoreOptions(){
    motore_combustione* ptr = dynamic_cast<motore_combustione*>(v);
    if(dynamic_cast<automobile*>(ptr) || dynamic_cast<moto*>(ptr) || dynamic_cast<auto_ibrida*>(ptr)){

        string carb;
        if(ptr->getAlimentazione() == 0){
            carb = "benzina";
        }
        if(ptr->getAlimentazione() == 1){
            carb = "diesel";
        }
        if(ptr->getAlimentazione() == 2){
            carb = "metano";
        }
        if(ptr->getAlimentazione() == 3){
            carb = "GPL";
        }
        if(ptr->getAlimentazione() == 4){
            carb = "BioDiesel";
        }
        if(ptr->getAlimentazione() == 5){
            carb = "Idrogeno";
        }
        if(ptr->getAlimentazione() == 9){
            carb = "Undefined";
        }

    layout->insertRow(5,new QLabel(tr("Cilindrata")), new QLabel(QString::number(ptr->getCilindrata())));
    layout->insertRow(6,new QLabel(tr("Litri Carburante")), new QLabel(QString::number(ptr->getLitri_serbatoio())));
    layout->insertRow(7,new QLabel(tr("Carburante")), new QLabel(QString::fromStdString(carb)));
    layout->insertRow(8,new QLabel(tr("Manutenzione")), new QLabel(QString::number(ptr->getManutenzione())));
    layout->insertRow(9,new QLabel(tr("Costo Manutenzione")), new QLabel(QString::number(ptr->getCosto_manutenzione())));
    }
    motore_elettrico* e = dynamic_cast<motore_elettrico*>(v);
    if(dynamic_cast<auto_elettrica*>(e) || dynamic_cast<moto_elettrica*>(e) || dynamic_cast<monopattino_elettrico*>(e)){
    layout->insertRow(10,new QLabel(tr("KW Batteria")), new QLabel(QString::number(e->getKw_batteria())));
    layout->insertRow(11,new QLabel(tr("Ricaricare")), new QLabel(QString::number(e->getRicaricare())));
    layout->insertRow(12,new QLabel(tr("Costo Ricarica")), new QLabel(QString::number(e->getCosto_ricarica())));
    }
    return layout;
}

void detailedvehicleview::connectViewSignals() const
{

}

void detailedvehicleview::close(QCloseEvent *event)
{
    //Elaboro chiusura solo se intenzionata da evento esterno
        if(!event->spontaneous()) return;
        else {
            //Accetto l'evento di chiusura della finestra
            event->accept();
            //Emetto segnale di chiusura della View
            emit viewClosed();
        }
}

detailedvehicleview::detailedvehicleview(veicolo* veic,const QSize &s, view *parent) : view(s, parent)
{
    v = veic;
    QBoxLayout* main = new QVBoxLayout;
    main->addLayout(configureFinalLayout());
    setLayout(main);
    setFixedSize(s);
    setTitle("Dettaglio Veicolo");
}
