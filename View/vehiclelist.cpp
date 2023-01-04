#include "vehiclelist.h"


void vehiclelist::connectViewSignals() const
{

}

void vehiclelist::closeEvent(QCloseEvent *event)
{

}

vehiclelist::vehiclelist(const QSize &s, view *parent) : view(s, parent), layout(new QHBoxLayout(this))
{
    // Creazione Barra dei Menu
    QMenuBar* menu = new QMenuBar;

    file = new QMenu("File", menu);
    garage = new QMenu("Garage", menu);

    menu->addMenu(file);
    menu->addMenu(garage);

    file->addAction(new QAction("Chiudi", file));

    garage->addAction(new QAction("Importa Garage", garage));
    garage->addAction(new QAction("Esporta Garage", garage));

    // Definizione del resto del layout
    setLayout(layout);
    connectViewSignals();

}

void vehiclelist::setTitle(const QString &title)
{

}
