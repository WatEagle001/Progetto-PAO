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

class veicoloListItem : public QListWidgetItem
{
private:
    QString marcamodello, targa, km;
    QPushButton aggiungiViaggio, modifica, elimina;
    QHBoxLayout id;
    QVBoxLayout pulsanti;

public:
    veicoloListItem(veicolo& v);
};
#endif // VEICOLOLISTITEM_H
