#include "veicololistitem.h"

veicoloListItem::veicoloListItem(veicolo &v)
{

    marcamodello = QString::fromUtf8(v.getMarca()) + QString::fromUtf8(v.getModello());
    targa = QString::fromUtf8(v.getTarga());
    km = QString::number(v.getKm_odometro());

    if(dynamic_cast<automobile*>(&v)){
        setIcon(QIcon("Assets/image/icons/automobile.png"));
    }

    if(dynamic_cast<auto_elettrica*>(&v)){
        setIcon(QIcon("Assets/image/icons/auto_elettrica.png"));
    }

    if(dynamic_cast<auto_ibrida*>(&v)){
        setIcon(QIcon("Assets/image/icons/auto_ibrida.png"));
    }

    if(dynamic_cast<moto*>(&v)){
        setIcon(QIcon("Assets/image/icons/moto.png"));
    }

    if(dynamic_cast<moto_elettrica*>(&v)){
        setIcon(QIcon("Assets/image/icons/moto_elettrica.png"));
    }

    if(dynamic_cast<monopattino_elettrico*>(&v)){
        setIcon(QIcon("Assets/image/icons/monopattino_elettrico.png"));
    }

    setText(QString());
}
