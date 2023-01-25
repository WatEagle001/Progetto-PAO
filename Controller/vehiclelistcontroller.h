#ifndef VEHICLELISTCONTROLLER_H
#define VEHICLELISTCONTROLLER_H
#pragma once
#include "controller.h"
#include "View/vehiclelist.h"
#include "Model/garage.h"
#include "Controller/jsonagent.h"
#include <iostream>
#include <Model/CostiViaggio.h>

class vehiclelistcontroller : public controller
{
    Q_OBJECT
private:
    void connectViewController() const;
    garage* g;
    veicolo* veic;
    CostiViaggio* c;
public:
    explicit vehiclelistcontroller(vehiclelist* v, garage* m, controller* parent = nullptr);
    view* getView() const override;
    garage* getModel() const override;
    void loadGarage(garage& g) const;
    virtual ~vehiclelistcontroller() = default;
signals:

public slots:
    virtual void onClosedView() const override;
    void loadVehicleSlot();
    void newVehicleSlot();
    void editVehicleSlot(veicolo* veic);
    void deleteVehicleSlot(veicolo* veic);
    void detailedVehicleViewSlot(veicolo* veic);
    void addViaggioSlot(veicolo *veic);
    void detailedCostsSlot(CostiViaggio* costi);
};

#endif // VEHICLELISTCONTROLLER_H
