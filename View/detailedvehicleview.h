// Classe derivata da View che mostra i dettagli di un determinato veicolo
#ifndef DETAILEDVEHICLEVIEW_H
#define DETAILEDVEHICLEVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QCloseEvent>
#include <QBoxLayout>
#include <QFormLayout>
#include <QComboBox>
#include <QString>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>

#include "View/view.h"
#include "Model/veicolo.h"
#include <Model/automobile.h>
#include <Model/moto.h>
#include <Model/auto_ibrida.h>
#include <Model/moto_elettrica.h>
#include <Model/monopattino_elettrico.h>
#include <Model/auto_elettrica.h>

class detailedvehicleview : public view
{
    Q_OBJECT
private:
    QPushButton* createGarage;
    QLayout* configureFinalLayout();
    QVBoxLayout* configureDescription();
    QHBoxLayout* configureButtons();
    veicolo* v;
    QFormLayout* layout;
    QComboBox* tipoAlimentazione;
    void connectViewSignals() const override;
protected:
    void closeEvent(QCloseEvent* event) override;
public:
    explicit detailedvehicleview(veicolo* veic,const QSize& s = QSize(), view* parent = nullptr);
    virtual ~detailedvehicleview() = default;
    QFormLayout *configureEditor();
    QFormLayout *addMoreOptions();
signals:
    void showVehicleDetails(veicolo* veic);
};

#endif // DETAILEDVEHICLEVIEW_H
