#include "newvehicle.h"
#include <QItemEditorFactory>
#include <QString>
#include <iostream>
#include <QLineEdit>
#include <QComboBox>
#include <Model/automobile.h>
#include <QFormLayout>
using std::bind;
#include <Model/veicolo.h>

QLayout* newvehicle::configureFinalLayout(){
    // Creazione Layout
    QVBoxLayout* mainLayout = new QVBoxLayout();

    // Aggiunta dei Vari Componenti al Layout
    mainLayout->addLayout(configureEditor());
    mainLayout->addLayout(configureButtons());

    return mainLayout;
}

newvehicle::newvehicle(garage* gar,veicolo* veic,const QSize &s, view *parent) : view(s, parent)
{   v = veic;
    g = gar;
    qDebug() << "tipo veicolo passato all'editor";
     qDebug() << typeid(*veic).name();
    /*if(cilindrata->isModified() == true || litri_carburante->isModified() == true
            || manutenzione_bool->isModified() == true || costo_manutenzione->isModified() == true){
    ptr->setCilindrata(cilindrata->text().toInt());
    ptr->setLitri_serbatoio(litri_carburante->text().toInt());
    ptr->setManutenzione(manutenzione_bool->text().toInt());
    ptr->setCosto_manutenzione(costo_manutenzione->text().toInt());

    }
    */

   // g->addVeicolo(v);
    QVBoxLayout* main = new QVBoxLayout;
   // main->addLayout(configureFinalLayout());
    main->addLayout(configureEditor());
    main->addLayout(configureButtons());

    setLayout(main);
    setFixedSize(s);
    connectViewSignals();
    setTitle("Editor Veicoli");
}

QFormLayout *newvehicle::configureEditor(){

       layout = new QFormLayout;
       tipoVeicolo = new QComboBox;
       layout->insertRow(1,new QLabel(tr("Marca")),  marca = new QLineEdit());
       layout->insertRow(2,new QLabel(tr("Modello")), modello = new QLineEdit());
       layout->insertRow(3,new QLabel(tr("Targa")), targa = new QLineEdit());
       layout->insertRow(4,new QLabel(tr("Km Odometro")), km = new QLineEdit());
       targa->setReadOnly(true);

    addMoreOptions();

    tipoVeicolo->addItem(QString("Automobile"));
    tipoVeicolo->addItem(QString("Moto"));
    tipoVeicolo->addItem(QString("Auto Elettrica"));
    tipoVeicolo->addItem(QString("Auto Ibrida"));
    tipoVeicolo->addItem(QString("Moto Elettrica"));
    tipoVeicolo->addItem(QString("Monopattino Elettrico"));


    return layout;
}



QFormLayout* newvehicle::addMoreOptions(){
    motore_combustione* ptr = dynamic_cast<motore_combustione*>(v);
    if(dynamic_cast<automobile*>(ptr) || dynamic_cast<moto*>(ptr) || dynamic_cast<auto_ibrida*>(ptr)){
        tipoAlimentazione = new QComboBox;
        tipoAlimentazione->addItem(QString("Benzina"));
        tipoAlimentazione->addItem(QString("Diesel"));
        tipoAlimentazione->addItem(QString("Metano"));
        tipoAlimentazione->addItem(QString("GPL"));
        tipoAlimentazione->addItem(QString("BioDiesel"));
        tipoAlimentazione->addItem(QString("Idrogeno"));
    layout->insertRow(5,new QLabel(tr("Cilindrata")), cilindrata = new QLineEdit());
    layout->insertRow(6,new QLabel(tr("Litri Carburante")), litri_carburante = new QLineEdit());
    layout->insertRow(7,new QLabel(tr("Carburante")), tipoAlimentazione);
    layout->insertRow(8,new QLabel(tr("Manutenzione")), manutenzione_bool = new QLineEdit());
    layout->insertRow(9,new QLabel(tr("Costo Manutenzione")), costo_manutenzione= new QLineEdit());

    }
    motore_elettrico* e = dynamic_cast<motore_elettrico*>(v);
    if(dynamic_cast<auto_elettrica*>(e) || dynamic_cast<moto_elettrica*>(e) || dynamic_cast<monopattino_elettrico*>(e) || dynamic_cast<auto_ibrida*>(e)){
    layout->insertRow(10,new QLabel(tr("KW Batteria")), kw =new QLineEdit());
    layout->insertRow(11,new QLabel(tr("Ricaricare")), ricaricare_bool = new QLineEdit());
    layout->insertRow(12,new QLabel(tr("Costo Ricarica")), costo_ricarica = new QLineEdit());
    }

    return layout;
}
void newvehicle::chechIfDataIsModified() {

    qDebug() << "No modifiche";
    if(marca->isModified() == true || modello->isModified() == true || km->isModified() == true || cilindrata->isModified() == true
            || litri_carburante->isModified() == true || manutenzione_bool->isModified() == true || costo_manutenzione->isModified() == true
            || kw->isModified() == true || ricaricare_bool->isModified() == true || costo_ricarica->isModified() == true ){
        qDebug() << "Modifiche";
        if(dynamic_cast<veicolo*>(v)){
            qDebug() << "ok creo nuovo veicolo normale";
            nuovo = new veicolo(marca->text().toStdString(),modello->text().toStdString(),v->getTarga(),km->text().toInt());
            qDebug() << typeid(nuovo).name();
         }
           if(dynamic_cast<automobile*>(v)){
               qDebug() << "ok creo nuovo auto";
               nuovoa = new automobile(marca->text().toStdString(),modello->text().toStdString(),v->getTarga(),km->text().toInt(),cilindrata->text().toInt());
               qDebug() << typeid(nuovoa).name();
            }
           if(dynamic_cast<moto*>(v)){
               qDebug() << "ok creo nuovo moto";
               nuovo = new moto(marca->text().toStdString(),modello->text().toStdString(),v->getTarga(),km->text().toInt());
            }
           if(dynamic_cast<auto_elettrica*>(v)){
               qDebug() << "ok creo nuovo auto_e";
               nuovo = new auto_elettrica(marca->text().toStdString(),modello->text().toStdString(),v->getTarga(),km->text().toInt());
            }
           if(dynamic_cast<auto_ibrida*>(v)){
               qDebug() << "ok creo nuovo auto_i";
               nuovo = new auto_ibrida(marca->text().toStdString(),modello->text().toStdString(),v->getTarga(),km->text().toInt());
            }
           /*if(dynamic_cast<moto_elettrica*>(v)){
               qDebug() << "ok creo nuovo veicolo";
               nuovo = new moto_elettrica(marca->text().toStdString(),modello->text().toStdString(),v->getTarga(),km->text().toInt());
            }
            */
           if(dynamic_cast<monopattino_elettrico*>(v)){
               qDebug() << "ok creo nuovo monopattino";
               nuovo = new monopattino_elettrico(marca->text().toStdString(),modello->text().toStdString(),v->getTarga(),km->text().toInt());
            }
    }
    //qDebug() << QString::fromStdString(v->getMarca()) + " "<< QString::fromStdString(v->getModello()) + " " << QString::number(v->getKm_odometro());
    connect(save, &QPushButton::clicked,(bind(&newvehicle::saveSignal, this, v,nuovo)));
    //connect(save, &QPushButton::clicked,(bind(&newvehicle::saveSignalAuto, this, v,nuovoa)));
}

void newvehicle::checkSignal(){
    qDebug() << "premuto check";
    chechIfDataIsModified();
}

void newvehicle::connectViewSignals() const
{
    connect(clear, SIGNAL(clicked()), this, SIGNAL(clearSignal()));
    connect(confermaDati, SIGNAL(clicked()), this, SLOT(checkSignal()));
    //connect(save, SIGNAL(clicked()), this, SIGNAL(saveSignal()));
}

QHBoxLayout *newvehicle::configureButtons()
{
    QHBoxLayout* buttons = new QHBoxLayout();

    // Creazione Pulsanti
    save = new QPushButton("Salva", this);
    save->setFixedSize(150, 70);
    clear = new QPushButton("Elimina tutti i campi dati", this);
    clear->setFixedSize(150, 70);
    confermaDati = new QPushButton("Conferma Dati",this);
    confermaDati->setFixedSize(150, 70);
    buttons->addWidget(confermaDati);
    buttons->addWidget(save);
    buttons->addWidget(clear);

    return buttons;
}

void newvehicle::close(QCloseEvent *event)
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

