#include "detailedvehicleview.h"
#include <QString>
#include <iostream>
#include <QFormLayout>
#include <QLineEdit>

QLayout *detailedvehicleview::configureFinalLayout(){
    // Creazione Layout
    QBoxLayout* mainLayout = new QVBoxLayout();

    // Aggiunta dei Vari Componenti al Layout

    return mainLayout;
}
QVBoxLayout *detailedvehicleview::configureDescription()
{

}
QHBoxLayout *detailedvehicleview::configureButtons()
{
    /*QHBoxLayout* buttons = new QHBoxLayout();
    // Creazione Pulsanti
    createGarage = new QPushButton("Crea Nuovo Garage", this);
    createGarage->setFixedSize(150, 70);
    //openGarage = new QPushButton("Apri Garage Esistente", this);
    //openGarage->setFixedSize(150, 70);
    // Aggiunta dei Bottoni al Layout Secondario
    buttons->addWidget(createGarage);
    //buttons->addWidget(openGarage);
    return buttons;
    */
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
    qDebug() << QString::fromStdString("stampa targa de detailed view");
                qDebug() <<QString::fromStdString(veic->getTarga());
    QBoxLayout* main = new QVBoxLayout;
    //main->addLayout(configureFinalLayout());
    QFormLayout* info = new QFormLayout;
    info->insertRow(1,new QLabel(tr("Marca")), new QLabel(QString::fromStdString(veic->getMarca())));
    info->insertRow(2,new QLabel(tr("Modello")), new QLabel(QString::fromStdString(veic->getModello())));
    info->insertRow(3,new QLabel(tr("Targa")), new QLabel(QString::fromStdString(veic->getTarga())));
    //info->insertRow(4,new QLabel(tr("KM Odometro")), new QLabel(QString::fromStdString(veic->getKm_odometro())));
    main->addLayout(info);
    setLayout(main);
    setFixedSize(s);
    setTitle("Dettaglio Veicolo");
}
