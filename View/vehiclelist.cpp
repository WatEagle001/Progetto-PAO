#include "vehiclelist.h"


void vehiclelist::connectViewSignals() const
{

}

void vehiclelist::closeEvent(QCloseEvent *event)
{

}

vehiclelist::vehiclelist(const QSize &s, view *parent) : view(s, parent), layout(new QHBoxLayout(this))
{
    //Aggiunta dei pulsanti
    QHBoxLayout* buttons = new QHBoxLayout();
    QPushButton* add = new QPushButton("Aggiungi Veicolo", this);
    QPushButton* load = new QPushButton("Carica Veicolo", this);

    buttons->addWidget(add);
    buttons->addWidget(load);

    layout->addLayout(buttons);

    // Sistemazione Finale del layout
    setLayout(layout);
    connectViewSignals();

}
