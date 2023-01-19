#include "veicolowidget.h"
veicoloWidget::veicoloWidget(veicolo* rif)
{
    QVBoxLayout* a = new QVBoxLayout;
    a->addLayout(configureVehicleView(rif));
    a->addLayout(configureButtons());
    qDebug() << "tipo veicolo del widget";
    qDebug() << typeid(*rif).name();
    qDebug() << "-------------------";
}

QHBoxLayout *veicoloWidget::configureButtons()
{
    pulsanti = new QHBoxLayout;
    aggiungiViaggio = new QPushButton(QString("Add"));
    aggiungiViaggio->setFixedSize(40, 40);
    modifica = new QPushButton(QString("Edit"));
    modifica->setFixedSize(40,40);
    elimina = new QPushButton(QString("Delete"));
    elimina->setFixedSize(40,40);

    pulsanti->addWidget(aggiungiViaggio);
    pulsanti->addWidget(modifica);
    pulsanti->addWidget(elimina);
    return pulsanti;
}

QHBoxLayout *veicoloWidget::configureVehicleView(veicolo *v)
{
    QHBoxLayout* info = new QHBoxLayout;
    marcamodello = new QLabel(QString::fromUtf8(v->getMarca()) + QString(" ") + QString::fromUtf8(v->getModello()));
    targa = new QLabel(QString::fromUtf8(v->getTarga()));
    km = new QLabel(QString::number(v->getKm_odometro()));
    info->addWidget(marcamodello);
    info->addWidget(targa);
    info->addWidget(km);
    return info;
}
