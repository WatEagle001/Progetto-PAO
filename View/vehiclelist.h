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

#include "View/veicololistitem.h"
#include "Model/garage.h"
#include "view.h"


class vehiclelist : public view
{

    Q_OBJECT

private:
    QBoxLayout* layout;
    QMenu *file, *garage;
    QPushButton* add;
    QPushButton* load;

    void connectViewSignals() const override;

protected:
    void closeEvent(QCloseEvent* event) override;

public:
    explicit vehiclelist(const QSize& s = QSize(), view* parent = nullptr);

signals:
    void loadVehicleSignal();
    void newVehicleSignal();

// DA INSERIRE SIGNAL E SLOT DELLA CLASSE
};

#endif // VEHICLELIST_H
