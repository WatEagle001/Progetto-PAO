#ifndef VEHICLELISTCONTROLLER_H
#define VEHICLELISTCONTROLLER_H
#pragma once

#include "controller.h"
#include "View/vehiclelist.h"
#include "Model/garage.h"
#include "Controller/jsonagent.h"
#include "Controller/dialogviaggiocontroller.h"
#include <iostream>
#include <Model/CostiViaggio.h>
#include <QInputDialog>

class vehiclelistcontroller : public controller
{
    Q_OBJECT

private:
    void connectViewController() const;
    garage* g;
    veicolo* veic;
    CostiViaggio* c;

public:
    explicit vehiclelistcontroller(vehiclelist* v, garage* m,CostiViaggio* costi, controller* parent = nullptr);
    virtual ~vehiclelistcontroller() = default;

    view* getView() const override;
    garage* getModel() const override;
    void loadGarage(garage& g) const;

signals:

public slots:
    void onClosedView() const override;
    void loadVehicleSlot();
    void newVehicleSlot();
    void editVehicleSlot(veicolo* veic);
    void deleteVehicleSlot(veicolo* veic);
    void detailedVehicleViewSlot(veicolo* veic);
    //void addViaggioSlot(veicolo *vec);
    void detailedCostsSlot();
    void addViaggioSlot(veicolo *vec);
    void exportGarageSlot();

};

#endif // VEHICLELISTCONTROLLER_H
