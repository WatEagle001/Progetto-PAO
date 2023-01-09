#include "vehiclelist.h"


void vehiclelist::connectViewSignals() const{
    connect(add, SIGNAL(clicked()), this, SIGNAL(newVehicleSignal()));
    connect(load, SIGNAL(clicked()), this, SIGNAL(loadVehicleSignal()));
}

void vehiclelist::closeEvent(QCloseEvent *event)
{

}

vehiclelist::vehiclelist(const QSize &s, view *parent) : view(s, parent), layout(new QVBoxLayout(this))
{
    //Aggiunta dei pulsanti
    QHBoxLayout* buttons = new QHBoxLayout();
    add = new QPushButton("Aggiungi Veicolo", this);
    load = new QPushButton("Carica Veicolo", this);

    buttons->addWidget(add);
    buttons->addWidget(load);

    layout->addLayout(buttons);

    // Aggiunda dei Veicoli
    QVBoxLayout* list = new QVBoxLayout();
    listview = new QListWidget();


    for(int i = 0; i < 10; i++){
        listview->addItem(QString("Melassa"));
    }

    list->addWidget(listview);

    layout->addLayout(list);

    /*
    // Aggiunta della Barra di Scroll
    scroll = new QScrollBar(this);
    list->addWidget(scroll);
    layout->addWidget(scroll);
    */

    // Sistemazione Finale del layout
    setLayout(layout);
    connectViewSignals();

}
