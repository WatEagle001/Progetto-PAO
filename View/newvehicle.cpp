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

newvehicle::newvehicle(garage* gar,const QSize &s, view *parent) : view(s, parent)
{
    g = gar;
    qDebug() << "tipo veicolo passato all'editor";
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
       layout->addWidget(tipoVeicolo);

       layout->insertRow(1,new QLabel(tr("Marca")),  marca = new QLineEdit());
       layout->insertRow(2,new QLabel(tr("Modello")), modello = new QLineEdit());
       layout->insertRow(3,new QLabel(tr("Targa")), targa = new QLineEdit());
       layout->insertRow(4,new QLabel(tr("Km Odometro")), km = new QLineEdit());

    tipoVeicolo->addItem(QString("Automobile"));
    tipoVeicolo->addItem(QString("Moto"));
    tipoVeicolo->addItem(QString("Auto Elettrica"));
    tipoVeicolo->addItem(QString("Auto Ibrida"));
    tipoVeicolo->addItem(QString("Moto Elettrica"));
    tipoVeicolo->addItem(QString("Monopattino Elettrico"));

    connect(tipoVeicolo, SIGNAL(currentIndexChanged(int)),SLOT(createOptions(int)));

    return layout;
}



void newvehicle::chechIfDataIsModified() {

    qDebug() << "No modifiche";
    if(marca->isModified() == true || modello->isModified() == true || km->isModified() == true || cilindrata->isModified() == true
            || litri_carburante->isModified() == true || manutenzione_bool->isModified() == true || costo_manutenzione->isModified() == true
            || kw->isModified() == true || ricaricare_bool->isModified() == true || costo_ricarica->isModified() == true ){
        qDebug() << "Modifiche";

        if(tipoVeicolo->currentIndex() == 0){
            v = new automobile(marca->text().toStdString(), modello->text().toStdString(), targa->text().toStdString(),km->text().toInt());
                               //cilindrata->text().toUInt(),litri_carburante->text().toUInt(),benzina,manutenzione_bool->text().toInt(),costo_manutenzione->text().toInt());
       }
        if(tipoVeicolo->currentIndex() == 1){
            v = new moto(marca->text().toStdString(), modello->text().toStdString(), targa->text().toStdString(),km->text().toInt());
                         //,
                        // cilindrata->text().toUInt(),litri_carburante->text().toUInt(),benzina,manutenzione_bool->text().toInt(),costo_manutenzione->text().toInt());
       }
        if(tipoVeicolo->currentIndex() == 2){
            v = new auto_elettrica(marca->text().toStdString(), modello->text().toStdString(), targa->text().toStdString(),km->text().toInt());
            //,kw->text().toInt(),ricaricare_bool->text().toInt(),costo_ricarica->text().toDouble());
       }
        if(tipoVeicolo->currentIndex() == 3){
            v = new auto_ibrida(marca->text().toStdString(), modello->text().toStdString(), targa->text().toStdString(),km->text().toInt());
            //,cilindrata->text().toUInt(),litri_carburante->text().toUInt(),benzina,manutenzione_bool->text().toInt(),costo_manutenzione->text().toInt(),
                              //  kw->text().toInt(),ricaricare_bool->text().toInt(),costo_ricarica->text().toDouble());
       }
        if(tipoVeicolo->currentIndex() == 4){
            //v = new moto_elettrica(marca->text().toStdString(), modello->text().toStdString(), targa->text().toStdString(),km->text().toInt());
       }

        if(tipoVeicolo->currentIndex() == 5){
            v = new monopattino_elettrico(marca->text().toStdString(), modello->text().toStdString(), targa->text().toStdString(),km->text().toInt());
            //,
                                          //kw->text().toInt(),ricaricare_bool->text().toInt(),costo_ricarica->text().toDouble());
       }

    }
    connect(save, &QPushButton::clicked,(bind(&newvehicle::saveSignal, this, v)));
}

void newvehicle::checkSignal(){
    qDebug() << "premuto check";
    chechIfDataIsModified();
}

void newvehicle::createOptions(int x)
{
    for(int i = 4; i <= layout->rowCount();i++){
        layout->removeRow(i);
    }
    if(x == 0 || x == 1 || x == 3 ){
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
    if(x == 2 || x == 4 ||x == 5){
    layout->insertRow(5,new QLabel(tr("KW Batteria")), kw =new QLineEdit());
    layout->insertRow(6,new QLabel(tr("Ricaricare")), ricaricare_bool = new QLineEdit());
    layout->insertRow(7,new QLabel(tr("Costo Ricarica")), costo_ricarica = new QLineEdit());
    }



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

