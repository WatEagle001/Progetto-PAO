#include "vehiclelist.h"


void vehiclelist::connectViewSignals() const{
    connect(add, SIGNAL(clicked()), this, SIGNAL(newVehicleSignal()));
    connect(load, SIGNAL(clicked()), this, SIGNAL(loadVehicleSignal()));
}

void vehiclelist::closeEvent(QCloseEvent *event)
{

}

vehiclelist::vehiclelist(const QSize &s, view *parent) : view(s, parent), layout(new QHBoxLayout(this))
{
    //Aggiunta dei pulsanti
    QHBoxLayout* buttons = new QHBoxLayout();
     add = new QPushButton("Aggiungi Veicolo", this);
     load = new QPushButton("Carica Veicolo", this);

    buttons->addWidget(add);
    buttons->addWidget(load);

    layout->addLayout(buttons);

    // Sistemazione Finale del layout
    setLayout(layout);
    connectViewSignals();

}
