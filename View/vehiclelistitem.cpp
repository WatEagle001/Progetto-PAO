#include "veicololistitem.h"
#include <iostream>

veicoloListItem::veicoloListItem(veicolo &v)
{

    marcamodello = QString::fromUtf8(v.getMarca()) + QString(" ") + QString::fromUtf8(v.getModello());
    targa = QString::fromUtf8(v.getTarga());
    km = QString::number(v.getKm_odometro());

    if(dynamic_cast<automobile*>(&v)){
        std::cout << "automobile" << std::endl;
        setIcon(QIcon(":/Assets/image/icons/automobile.png"));
    }
    else
    if(dynamic_cast<auto_elettrica*>(&v)){
        std::cout << "automobile elettrica" << std::endl;
        setIcon(QIcon("Assets/image/icons/auto_elettrica.png"));
    }
    else
    if(dynamic_cast<auto_ibrida*>(&v)){
        std::cout << "automobile ibrida" << std::endl;
        setIcon(QIcon("Assets/image/icons/auto_ibrida.png"));
    }
    else
    if(dynamic_cast<moto*>(&v)){
        std::cout << "moto" << std::endl;
        setIcon(QIcon("Assets/image/icons/moto.png"));
    }
    else
    if(dynamic_cast<moto_elettrica*>(&v)){
        std::cout << "moto elettrica" << std::endl;
        setIcon(QIcon("Assets/image/icons/moto_elettrica.png"));
    }
    else
    if(dynamic_cast<monopattino_elettrico*>(&v)){
        std::cout << "monopattino" << std::endl;
        setIcon(QIcon("Assets/image/icons/monopattino_elettrico.png"));
    }

    setText(QString(marcamodello + "\n" + targa + "\n" + km));

}
