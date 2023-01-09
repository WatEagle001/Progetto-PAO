#ifndef VEICOLOLISTITEM_H
#define VEICOLOLISTITEM_H

#include <QWidget>
#include <QListWidgetItem>
#include <Model/veicolo.h>

class veicoloListItem : public QListWidgetItem
{
    Q_OBJECT
private:


public:
    veicoloListItem(veicolo& v);
};

#endif // VEICOLOLISTITEM_H
