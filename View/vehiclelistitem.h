
#ifndef VEICOLOLISTITEM_H
#define VEICOLOLISTITEM_H
#include <QWidget>
#include <QListWidgetItem>
#include <Model/veicolo.h>
#include <Model/automobile.h>
#include <Model/auto_elettrica.h>
#include <Model/auto_ibrida.h>
#include <Model/moto_elettrica.h>
#include <Model/monopattino_elettrico.h>
#include <Model/moto.h>
#include <QIcon>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QBoxLayout>
#include <QDebug>
#include "view.h"
class vehicleListItem: public QListWidgetItem
{
private:
    QString marcamodello;
    QString targa;
    QString km;
    QPushButton* aggiungiViaggio;
    QPushButton* modifica;
    QPushButton* elimina;
    QHBoxLayout id;
    QHBoxLayout* pulsanti;

public:
    vehicleListItem(veicolo& v);
    ~vehicleListItem() = default;
    QHBoxLayout* confugureButtons();
signals:
    void editVehicleSignal(veicolo& v);
    void newVehicleSignal(veicolo& v);
};
#endif // VEICOLOLISTITEM_H

