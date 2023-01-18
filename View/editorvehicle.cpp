#include "editorvehicle.h"
#include <QItemEditorFactory>
#include <QString>
#include <iostream>
#include <QLineEdit>
#include <QComboBox>
#include <Model/automobile.h>
#include <QFormLayout>
using std::bind;
#include <Model/veicolo.h>

QLayout* editorvehicle::configureFinalLayout(){
    // Creazione Layout
    QVBoxLayout* mainLayout = new QVBoxLayout();

    // Aggiunta dei Vari Componenti al Layout
    mainLayout->addLayout(configureEditor());
    mainLayout->addLayout(configureButtons());

    return mainLayout;
}

editorvehicle::editorvehicle(veicolo* veic,const QSize &s, view *parent) : view(s, parent)
{   v = veic;
   // g->addVeicolo(v);
    QVBoxLayout* main = new QVBoxLayout;
    main->addLayout(configureFinalLayout());

    setLayout(main);
    setFixedSize(s);
    connectViewSignals();
    setTitle("Editor Veicoli");
}

QFormLayout *editorvehicle::configureEditor(){
       tipoAlimentazione = new QComboBox;
       layout = new QFormLayout;
       layout->insertRow(1,new QLabel(tr("Marca")),  marca = new QLineEdit(QString::fromStdString(v->getMarca())));
       layout->insertRow(2,new QLabel(tr("Modello")), modello = new QLineEdit(QString::fromStdString(v->getModello())));
       layout->insertRow(3,new QLabel(tr("Targa")), targa = new QLineEdit(QString::fromStdString(v->getTarga())));;
       layout->insertRow(4,new QLabel(tr("Km Odometro")), km = new QLineEdit(QString::number(v->getKm_odometro())));
    addMoreOptions();

    tipoAlimentazione->addItem(QString("Benzina"));
    tipoAlimentazione->addItem(QString("Diesel"));
    tipoAlimentazione->addItem(QString("Metano"));
    tipoAlimentazione->addItem(QString("GPL"));
    tipoAlimentazione->addItem(QString("BioDiesel"));
    tipoAlimentazione->addItem(QString("Idrogeno"));


    return layout;
}

QHBoxLayout *editorvehicle::configureButtons()
{
    QHBoxLayout* buttons = new QHBoxLayout();

    // Creazione Pulsanti
    save = new QPushButton("Salva", this);
    save->setFixedSize(150, 70);
    clear = new QPushButton("Elimina tutti i campi dati", this);
    clear->setFixedSize(150, 70);

    // Aggiunta dei Bottoni al Layout Secondario
    connect(save, &QPushButton::clicked,(bind(&editorvehicle::saveSignal, this, v)));
    buttons->addWidget(save);
    buttons->addWidget(clear);

    return buttons;
}

QFormLayout* editorvehicle::addMoreOptions(){
    motore_combustione* ptr = dynamic_cast<motore_combustione*>(v);
    if(dynamic_cast<automobile*>(ptr) || dynamic_cast<moto*>(ptr) || dynamic_cast<auto_ibrida*>(ptr)){
    layout->insertRow(5,new QLabel(tr("Cilindrata")), cilindrata = new QLineEdit(QString::number(ptr->getCilindrata())));
    layout->insertRow(6,new QLabel(tr("Litri Carburante")), litri_carburante = new QLineEdit(QString::number(ptr->getLitri_serbatoio())));
    layout->insertRow(7,new QLabel(tr("Carburante")), tipoAlimentazione);
    layout->insertRow(8,new QLabel(tr("Manutenzione")), manutenzione_bool = new QLineEdit(QString::number(ptr->getManutenzione())));
    layout->insertRow(9,new QLabel(tr("Costo Manutenzione")), costo_manutenzione= new QLineEdit(QString::number(ptr->getCosto_manutenzione())));
    /*v->setMarca(marca->text().toStdString());
    v->setModello(modello->text().toStdString());
    qDebug() << "test" << QString::fromStdString(modello->text().toStdString());
    v->setTarga(targa->text().toStdString());
    v->setKm_odometro(km->text().toInt());
    */

    }
    motore_elettrico* e = dynamic_cast<motore_elettrico*>(v);
    if(dynamic_cast<auto_elettrica*>(e) || dynamic_cast<moto_elettrica*>(e) || dynamic_cast<monopattino_elettrico*>(e)){
    layout->insertRow(10,new QLabel(tr("KW Batteria")), new QLineEdit(QString::number(e->getKw_batteria())));
    layout->insertRow(11,new QLabel(tr("Ricaricare")), new QLineEdit(QString::number(e->getRicaricare())));
    layout->insertRow(12,new QLabel(tr("Costo Ricarica")), new QLineEdit(QString::number(e->getCosto_ricarica())));
    }

    return layout;
}

void editorvehicle::connectViewSignals() const
{
    connect(clear, SIGNAL(clicked()), this, SIGNAL(clearSignal()));
}

void editorvehicle::close(QCloseEvent *event)
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

