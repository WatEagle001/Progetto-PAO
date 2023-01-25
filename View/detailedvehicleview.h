#ifndef DETAILEDVEHICLEVIEW_H
#define DETAILEDVEHICLEVIEW_H
#include "View/view.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QCloseEvent>
#include <QBoxLayout>
#include <Model/veicolo.h>
#include <QFormLayout>
#include <QComboBox>
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
    void close(QCloseEvent* event);
public:
    explicit detailedvehicleview(veicolo* veic,const QSize& s = QSize(), view* parent = nullptr);
    virtual ~detailedvehicleview() = default;
    QFormLayout *configureEditor();
    QFormLayout *addMoreOptions();
signals:
    void showVehicleDetails(veicolo* veic);
};

#endif // DETAILEDVEHICLEVIEW_H
