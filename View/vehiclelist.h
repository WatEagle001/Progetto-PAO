// Classe derivata da View che mostra i veicoli presenti nel garage, permettendo di crearne o caricare di nuovi e di visionare/modificare i veicoli esistenti
#ifndef VEHICLELIST_H
#define VEHICLELIST_H
#include <QAction>
#include <QDialog>
#include <QFileDialog>
#include <QFrame>
#include <QHBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QGridLayout>
#include <QListWidget>
#include "Model/garage.h"
#include "view.h"
#include <Model/veicolowidget.h>


class vehiclelistcontroller;

class vehiclelist : public view
{
    Q_OBJECT

private:
    garage* g;
    QBoxLayout* layout;
    QMenu *file, *gar;
    QPushButton* add;
    QPushButton* load;
    void connectViewSignals() const override;
    QLabel* marcamodello;
    QLabel* targa;
    QLabel* km;
    QPushButton* aggiungiViaggio;
    QPushButton* modifica;
    QPushButton* elimina;
    QPushButton* detailedView;
    QHBoxLayout id;
    QHBoxLayout* pulsanti;
protected:
    void closeEvent(QCloseEvent* event) override;
public:
    explicit vehiclelist(garage* garage = nullptr,const QSize& s = QSize(), view* parent = nullptr);
    QHBoxLayout *configureButtons(veicolo* veic);
    QWidget *configureVheicleItem(veicolo* veic);
signals:
    void loadVehicleSignal();
    void newVehicleSignal();
    void addNewViaggioSignal(veicolo * v);
    void editVehicleDetailsSignal(veicolo * v);
    //void editAutoDetailsSignal(automobile * v);
    void deleteVehicleSignal(veicolo* v);
    void showVehicleDetails(veicolo* v);
};
#endif // VEHICLELIST_H
