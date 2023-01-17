#include "vehiclelistitem.h"
#include <iostream>
#include <QLabel>

QHBoxLayout* vehicleListItem::confugureButtons()
{
    pulsanti = new QHBoxLayout;
    aggiungiViaggio = new QPushButton(QString("Add"));
    aggiungiViaggio->setFixedSize(70, 70);
    modifica = new QPushButton(QString("Edit"));
    modifica->setFixedSize(70,70);
    elimina = new QPushButton(QString("Delete"));
    elimina->setFixedSize(70,70);

    pulsanti->addWidget(aggiungiViaggio);
    pulsanti->addWidget(modifica);
    pulsanti->addWidget(elimina);
    return pulsanti;
}

vehicleListItem::vehicleListItem(veicolo &v)
{
    QVBoxLayout* test = new QVBoxLayout();
    /*marcamodello = QString::fromUtf8(v.getMarca()) + QString(" ") + QString::fromUtf8(v.getModello());
        targa = QString::fromUtf8(v.getTarga());
        km = QString::number(v.getKm_odometro());
 setText(QString(marcamodello + "\n" + targa + "\n" + km));
*/
    QPushButton* dio = new QPushButton("dio canotto");
    test->addWidget(dio);

    /*if(dynamic_cast<automobile*>(&v)){
        qDebug()<< "DEBUG: item automobile" ;
        setIcon(QIcon(":/Assets/image/icons/automobile.png"));
    }
    else
    if(dynamic_cast<auto_elettrica*>(&v)){
        qDebug()<< "DEBUG: item automobile elettrica" ;
        setIcon(QIcon(":/Assets/image/icons/auto_elettrica.png"));
    }
    else
    if(dynamic_cast<auto_ibrida*>(&v)){
        qDebug()<< "DEBUG: item automobile ibrida" ;
        setIcon(QIcon(":/Assets/image/icons/auto_ibrida.png"));
    }
    else
    if(dynamic_cast<moto*>(&v)){
        qDebug()<< "DEBUG: item moto" ;
        setIcon(QIcon(":/Assets/image/icons/moto.png"));
    }
    else
    if(dynamic_cast<moto_elettrica*>(&v)){
        qDebug()<< "DEBUG: item moto elettrica" ;
        setIcon(QIcon(":/Assets/image/icons/moto_elettrica.png"));
    }
    else
    if(dynamic_cast<monopattino_elettrico*>(&v)){
        qDebug()<< "DEBUG: item monopattino" ;
        setIcon(QIcon(":/Assets/image/icons/monopattino_elettrico.png"));
    }

    */
}

