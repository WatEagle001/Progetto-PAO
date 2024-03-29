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
#include <QTableView>
#include <QLabel>
#include <QScrollArea>

#include "Model/garage.h"
#include "View/view.h"
#include "Model/CostiViaggio.h"
#include <View/veicolowidget.h>

using std::bind;

class vehiclelistcontroller;

class vehiclelist : public view
{
    Q_OBJECT

private:
    CostiViaggio* c;
    garage* g;
    QBoxLayout* layout;
    QMenu *file, *gar;
    QPushButton* add;
    QPushButton* load;
    QPushButton* detailedCosts;
    QPushButton* toExp;
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
    void addNewViaggioSignal(veicolo* vec);
    void editVehicleDetailsSignal(veicolo * v);
    void deleteVehicleSignal(veicolo* v);
    void showVehicleDetails(veicolo* v);
    void detailedCostsSignal();
    void exportGarage();

};
#endif // VEHICLELIST_H
