#ifndef VEICOLOWIDGET_H
#define VEICOLOWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <Model/veicolo.h>
class veicoloWidget: public QVBoxLayout
{
    Q_OBJECT
private:
    QLabel* marcamodello;
    QLabel* targa;
    QLabel* km;
    QPushButton* aggiungiViaggio;
    QPushButton* modifica;
    QPushButton* elimina;
    QHBoxLayout id;
    QHBoxLayout* pulsanti;
    veicolo* v;
public:
    veicoloWidget(veicolo* rif);
    QHBoxLayout *configureButtons();
    QHBoxLayout *configureVehicleView(veicolo* v);
};

#endif // VEICOLOWIDGET_H
