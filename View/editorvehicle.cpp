#include "editorvehicle.h"
#include <QItemEditorFactory>
#include <QString>
#include <iostream>
#include <QLineEdit>
#include <QComboBox>
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
     tipoVeicolo = new QComboBox;
     tipoAlimentazione = new QComboBox;
        layout = new QFormLayout;
       layout->addWidget(tipoVeicolo);
       layout->insertRow(1,new QLabel(tr("Tipologia Veicolo")), tipoVeicolo);
       layout->insertRow(2,new QLabel(tr("Marca")), new QLineEdit);
       layout->insertRow(3,new QLabel(tr("Modello")), new QLineEdit);
       layout->insertRow(4,new QLabel(tr("Targa")), new QLineEdit);
       layout->insertRow(5,new QLabel(tr("Km Odometro")), new QLineEdit);
       layout->insertRow(6,new QLabel(tr("Cilindrata")), new QLineEdit);
       layout->insertRow(7,new QLabel(tr("Litri Carburante")), new QLineEdit);
       layout->insertRow(8,new QLabel(tr("Carburante")), tipoAlimentazione);
       layout->insertRow(9,new QLabel(tr("Manutenzione")), new QLineEdit);
       layout->insertRow(10,new QLabel(tr("Costo Manutenzione")), new QLineEdit);
       layout->insertRow(11,new QLabel(tr("KW Batteria")), new QLineEdit);
       layout->insertRow(12,new QLabel(tr("Ricaricare")), new QLineEdit);
       layout->insertRow(13,new QLabel(tr("Costo Ricarica")), new QLineEdit);


       connect(tipoVeicolo, QOverload<int>::of(&QComboBox::currentIndexChanged),
           [=](int index){addMoreOptions(); });

    tipoVeicolo->addItem(QString("Automobile"));
    tipoVeicolo->addItem(QString("Automobile elettrica"));
    tipoVeicolo->addItem(QString("Automobile ibrida"));
    tipoVeicolo->addItem(QString("Moto"));
    tipoVeicolo->addItem(QString("Moto elettrica"));
    tipoVeicolo->addItem(QString("Monopattino elettrico"));

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

void editorvehicle::addMoreOptions()
{

        deleteOptions();

}

void editorvehicle::deleteOptions()
{
    if(tipoVeicolo->currentIndex() == 1
            || tipoVeicolo->currentIndex() == 4 || tipoVeicolo->currentIndex() == 5){
    layout->removeRow(6);
    layout->removeRow(7);
    layout->removeRow(8);
    layout->removeRow(9);
    layout->removeRow(10);

    }
    if(tipoVeicolo->currentIndex() == 0 || tipoVeicolo->currentIndex() == 2 ||tipoVeicolo->currentIndex() == 3){
        layout->removeRow(11);
        layout->removeRow(12);
        layout->removeRow(13);
    }
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

editorvehicle::editorvehicle(const QSize &s, view *parent) : view(s, parent)
{
    QVBoxLayout* main = new QVBoxLayout;
    main->addLayout(configureFinalLayout());

    setLayout(main);
    setFixedSize(s);
    connectViewSignals();
    setTitle("Editor Veicoli");
}
