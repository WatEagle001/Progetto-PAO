#include "editorvehicle.h"
#include <QItemEditorFactory>
#include <QString>
#include <iostream>
#include <QLineEdit>
#include <QComboBox>
#include <Model/automobile.h>
#include <QFormLayout>

QLayout* editorvehicle::configureFinalLayout(){
    // Creazione Layout
    QVBoxLayout* mainLayout = new QVBoxLayout();

    // Aggiunta dei Vari Componenti al Layout
    mainLayout->addLayout(configureEditor());
    mainLayout->addLayout(configureButtons());

    return mainLayout;
}

QFormLayout *editorvehicle::configureEditor(){
       tipoAlimentazione = new QComboBox;
       layout = new QFormLayout;
       layout->insertRow(1,new QLabel(tr("Marca")),  marca = new QLineEdit(QString::fromStdString(v->getMarca())));
       layout->insertRow(2,new QLabel(tr("Modello")), new QLineEdit(QString::fromStdString(v->getModello())));
       layout->insertRow(3,new QLabel(tr("Targa")), new QLineEdit(QString::fromStdString(v->getTarga())));;
       layout->insertRow(4,new QLabel(tr("Km Odometro")), new QLineEdit(QString::fromStdString(v->getTarga())));
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
    buttons->addWidget(save);
    buttons->addWidget(clear);

    return buttons;
}

void editorvehicle::addMoreOptions(){
    //automobile* a = new automobile("Fiat", "punto","AO111OA", 125000,1200,45,benzina,0,0);
    //g = new garage();
    //g->addVeicolo(a);
    //g->printGarage();
    if(dynamic_cast<automobile*>(v) || dynamic_cast<moto*>(v) || dynamic_cast<auto_ibrida*>(v)){
    layout->insertRow(5,new QLabel(tr("Cilindrata")), new QLineEdit);
    layout->insertRow(6,new QLabel(tr("Litri Carburante")), new QLineEdit);
    layout->insertRow(7,new QLabel(tr("Carburante")), tipoAlimentazione);
    layout->insertRow(8,new QLabel(tr("Manutenzione")), new QLineEdit);
    layout->insertRow(9,new QLabel(tr("Costo Manutenzione")), new QLineEdit);
    }
     if(dynamic_cast<auto_elettrica*>(v) || dynamic_cast<moto_elettrica*>(v) || dynamic_cast<monopattino_elettrico*>(v))
    layout->insertRow(10,new QLabel(tr("KW Batteria")), new QLineEdit);
    layout->insertRow(11,new QLabel(tr("Ricaricare")), new QLineEdit);
    layout->insertRow(12,new QLabel(tr("Costo Ricarica")), new QLineEdit);
}

void editorvehicle::connectViewSignals() const
{
    connect(save, SIGNAL(clicked()), this, SIGNAL(saveSignal()));
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
