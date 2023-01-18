#ifndef VEHICLELISTCONTROLLER_H
#define VEHICLELISTCONTROLLER_H
#pragma once
#include "controller.h"
#include "View/vehiclelist.h"
#include "Model/garage.h"
#include "Controller/jsonagent.h"
#include <iostream>
#include <QInputDialog>

class vehiclelistcontroller : public controller
{
    Q_OBJECT
private:
    void connectViewController() const;
    garage* g;
    veicolo* veic;
public:
    explicit vehiclelistcontroller(vehiclelist* v, garage* m, controller* parent = nullptr);
    view* getView() const override;
    garage* getModel() const override;
    void loadGarage(garage& g) const;

signals:

public slots:
    virtual void onClosedView() const override;
    void loadVehicleSlot();
    void newVehicleSlot();
    void addViaggioSlot(veicolo * veic);
    void editVehicleSlot(veicolo* veic);
    void deleteVehicleSlot();
};

#endif // VEHICLELISTCONTROLLER_H
