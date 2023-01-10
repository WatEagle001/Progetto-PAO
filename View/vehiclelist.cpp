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
    // Aggiunta dei pulsanti
    QHBoxLayout* buttons = new QHBoxLayout();
    add = new QPushButton("Aggiungi Veicolo", this);
    load = new QPushButton("Carica Veicolo", this);

    buttons->addWidget(add);
    buttons->addWidget(load);

    layout->addLayout(buttons);

    // Mostra del garage
    QHBoxLayout* list = new QHBoxLayout();
    QListWidget* items = new QListWidget();
    items->setIconSize(QSize(52, 52));

    /// DEBUG

    automobile* a1 = new automobile("Ferrari", "California");
    veicoloListItem* a1l = new veicoloListItem(dynamic_cast<veicolo&>(*a1));
    items->addItem(a1l);

    /// FINE DEBUG

    list->addWidget(items);
    layout->addLayout(list);

    // Sistemazione Finale del layout
    setLayout(layout);
    connectViewSignals();

}
