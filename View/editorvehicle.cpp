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

editorvehicle::editorvehicle(garage* gar,veicolo* veic,const QSize &s, view *parent) : view(s, parent)
{   v = veic;
    g = gar;
    qDebug() << "tipo veicolo passato all'editor";
     qDebug() << typeid(*veic).name();
    QVBoxLayout* main = new QVBoxLayout;
    main->addLayout(configureEditor());
    main->addLayout(configureButtons());

    setLayout(main);
    setFixedSize(s);
    connectViewSignals();
    setTitle("Editor Veicoli");
}

QFormLayout *editorvehicle::configureEditor(){

       layout = new QFormLayout;
       layout->insertRow(1,new QLabel(tr("Marca")),  marca = new QLineEdit(QString::fromStdString(v->getMarca())));
       layout->insertRow(2,new QLabel(tr("Modello")), modello = new QLineEdit(QString::fromStdString(v->getModello())));
       layout->insertRow(3,new QLabel(tr("Targa")), targa = new QLineEdit(QString::fromStdString(v->getTarga())));
       layout->insertRow(4,new QLabel(tr("Km Odometro")), km = new QLineEdit(QString::number(v->getKm_odometro())));
       targa->setReadOnly(true);

       marca->setValidator(new QRegularExpressionValidator(QRegularExpression("[A-Z]*[a-z]*[A-Z]*"), this));
              modello->setValidator(new QRegularExpressionValidator(QRegularExpression("[A-Z]*[a-z]*[0-9]*"), this));
              km->setValidator(new QIntValidator(v->getKm_odometro(), INT_MAX, this));

       addMoreOptions();
    return layout;
}



QFormLayout* editorvehicle::addMoreOptions(){
    motore_combustione* ptr = dynamic_cast<motore_combustione*>(v);
    if(dynamic_cast<automobile*>(ptr) || dynamic_cast<moto*>(ptr) || dynamic_cast<auto_ibrida*>(ptr)){
        tipoAlimentazione = new QComboBox;
        tipoAlimentazione->addItem(QString("Benzina"));
        tipoAlimentazione->addItem(QString("Diesel"));
        tipoAlimentazione->addItem(QString("Metano"));
        tipoAlimentazione->addItem(QString("GPL"));
        tipoAlimentazione->addItem(QString("BioDiesel"));
        tipoAlimentazione->addItem(QString("Idrogeno"));
        tipoAlimentazione->setDisabled(true);

    layout->insertRow(5,new QLabel(tr("Cilindrata")), cilindrata = new QLineEdit(QString::number(ptr->getCilindrata())));
    layout->insertRow(6,new QLabel(tr("Litri Carburante")), litri_carburante = new QLineEdit(QString::number(ptr->getLitri_serbatoio())));
    layout->insertRow(7,new QLabel(tr("Carburante")), tipoAlimentazione);
    layout->insertRow(8,new QLabel(tr("Manutenzione")), manutenzione_bool = new QLineEdit(QString::number(ptr->getManutenzione())));
    layout->insertRow(9,new QLabel(tr("Costo Manutenzione")), costo_manutenzione= new QLineEdit(QString::number(ptr->getCosto_manutenzione())));

    cilindrata->setValidator(new QIntValidator(ptr->getCilindrata(), INT_MAX, this));
        litri_carburante->setValidator(new QIntValidator(0, INT_MAX, this));
        manutenzione_bool->setValidator(new QIntValidator(0, 1, this));
        costo_manutenzione->setValidator(new QDoubleValidator(0.0, INT_MAX, 2,this));
    }
    motore_elettrico* e = dynamic_cast<motore_elettrico*>(v);
    if(dynamic_cast<auto_elettrica*>(e) || dynamic_cast<moto_elettrica*>(e) || dynamic_cast<monopattino_elettrico*>(e) || dynamic_cast<auto_ibrida*>(e)){
    layout->insertRow(10,new QLabel(tr("KW Batteria")), kw =new QLineEdit(QString::number(e->getKw_batteria())));
    layout->insertRow(11,new QLabel(tr("Ricaricare")), ricaricare_bool = new QLineEdit(QString::number(e->getRicaricare())));
    layout->insertRow(12,new QLabel(tr("Costo Ricarica")), costo_ricarica = new QLineEdit(QString::number(e->getCosto_ricarica())));

    kw->setValidator(new QIntValidator(0, INT_MAX, this));
        ricaricare_bool->setValidator(new QIntValidator(0, 1, this));
        costo_ricarica->setValidator(new QDoubleValidator(0, INT_MAX, 2,this));
    }

    return layout;
}
void editorvehicle::checkIfDataIsModified() {

    qDebug() << "No modifiche";
    if(marca->isModified() == true || modello->isModified() == true || km->isModified() == true
            /*
            || cilindrata->isModified() == true
            || litri_carburante->isModified() == true || manutenzione_bool->isModified() == true || costo_manutenzione->isModified() == true
            || kw->isModified() == true || ricaricare_bool->isModified() == true || costo_ricarica->isModified() == true
            */
            ){
        qDebug() << "Modifiche";

        qDebug() << "tipo veicolo dopo salvataggio";
                    qDebug() <<typeid(v).name();
        v->setMarca(marca->text().toStdString());
        v->setModello(modello->text().toStdString());
        v->setTarga(v->getTarga());
        v->setKm_odometro(km->text().toInt());
        motore_combustione* ptr = dynamic_cast<motore_combustione*>(v);
        if(ptr){
            qDebug() << "ok combustione";
            ptr->setCilindrata(cilindrata->text().toInt());
             ptr->setLitri_serbatoio(litri_carburante->text().toInt());
              ptr->setManutenzione(manutenzione_bool->text().toInt());
               ptr->setCosto_manutenzione(costo_manutenzione->text().toInt());
        }

        motore_elettrico* e = dynamic_cast<motore_elettrico*>(v);
        if(e){
            qDebug() << "ok elettrico";
            e->setKw_batteria(kw->text().toUInt());
            e->setRicaricare(ricaricare_bool->text().toInt());
            e->setCosto_ricarica(costo_ricarica->text().toDouble());
    }
    }

    connect(save, &QPushButton::clicked,(bind(&editorvehicle::saveSignal, this, v,v)));
}

void editorvehicle::checkSignal(){
    qDebug() << "premuto check";
    checkIfDataIsModified();
}

void editorvehicle::clearSlot()
{
marca->setText(QString::fromStdString(v->getMarca()));
modello->setText(QString::fromStdString(v->getModello()));
km->setText(QString::number(v->getKm_odometro()));
targa->setText(QString::fromStdString(v->getTarga()));

motore_combustione* ptr = dynamic_cast<motore_combustione*>(v);
if(ptr){
    cilindrata->setText(QString::number(ptr->getCilindrata()));
    litri_carburante->setText(QString::number(ptr->getLitri_serbatoio()));
    manutenzione_bool->setText(QString::number(ptr->getManutenzione()));
    costo_manutenzione->setText(QString::number(ptr->getCosto_manutenzione()));
}

motore_elettrico* e = dynamic_cast<motore_elettrico*>(v);
if(e){
    kw->setText(QString::number(e->getKw_batteria()));
    ricaricare_bool->setText(QString::number(e->getRicaricare()));
    costo_ricarica->setText(QString::number(e->getCosto_ricarica()));
}

}

void editorvehicle::connectViewSignals() const
{
    connect(clear, SIGNAL(clicked()), this, SLOT(clearSlot()));
    connect(confermaDati, SIGNAL(clicked()), this, SLOT(checkSignal()));
}

QHBoxLayout *editorvehicle::configureButtons()
{
    QHBoxLayout* buttons = new QHBoxLayout();

    // Creazione Pulsanti
    save = new QPushButton("Salva", this);
    save->setFixedSize(150, 70);
    clear = new QPushButton("Elimina le modifiche", this);
    clear->setFixedSize(150, 70);
    confermaDati = new QPushButton("Conferma Dati",this);
    confermaDati->setFixedSize(150, 70);
    buttons->addWidget(confermaDati);
    buttons->addWidget(save);
    buttons->addWidget(clear);

    return buttons;
}

void editorvehicle::closeEvent(QCloseEvent *event)
{
    //Elaboro chiusura solo se intenzionata da evento esterno
        if(!event->spontaneous()) return;

        if(!dialogPopUp_Question(2, "Annullamento", "Sei sicuro di voler annullare l'operazione?\n")){
            event->ignore();
        }
        else {
            //Accetto l'evento di chiusura della finestra
            event->accept();
            //Emetto segnale di chiusura della View
            emit viewClosed();
        }
}

