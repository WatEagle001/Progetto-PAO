#include "veicolowidget.h"
#include "Model/automobile.h"
#include "Model/auto_elettrica.h"
#include "Model/auto_ibrida.h"
#include "Model/moto.h"
#include "Model/moto_elettrica.h"
#include "Model/monopattino_elettrico.h"

veicoloWidget::veicoloWidget(veicolo* rif)
{
    QVBoxLayout* a = new QVBoxLayout;
    a->addLayout(configureVehicleView(rif));
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
    if(dynamic_cast<automobile*>(v)){
        Qimg = QImage(":Assets/image/icons/automobile.png");
    }
    else
        if(dynamic_cast<auto_elettrica*>(v)){
            Qimg = QImage(":Assets/image/icons/auto_elettrica.png");
        }
        else
            if(dynamic_cast<auto_ibrida*>(v)){
                Qimg = QImage(":Assets/image/icons/auto_ibrida.png");
            }
            else
                if(dynamic_cast<moto*>(v)){
                    Qimg = QImage(":Assets/image/icons/moto.png");
                }
                else
                    if(dynamic_cast<moto_elettrica*>(v)){
                        Qimg = QImage(":Assets/image/icons/moto_elettrica.png");
                    }
                    else
                        if(dynamic_cast<monopattino_elettrico*>(v)){
                            Qimg = QImage(":Assets/image/icons/monopattino.png");
                        }
                        else Qimg = QImage();
    QPixmap image;
    QLabel* logo = new QLabel;
    image = image.fromImage(Qimg.scaled(40, 40, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));    //Conversione da Image a Pixmap senza perdita di qualità
    logo->setPixmap(image);
    logo->setAlignment(Qt::AlignCenter);
    marcamodello = new QLabel(QString::fromUtf8(v->getMarca()) + QString(" ") + QString::fromUtf8(v->getModello()));
    targa = new QLabel(QString::fromUtf8(v->getTarga()));
    km = new QLabel(QString::number(v->getKm_odometro()));
    info->addWidget(logo);
    info->addWidget(marcamodello);
    info->addWidget(targa);
    info->addWidget(km);
    return info;
}
