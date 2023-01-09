#ifndef VEHICLELISTCONTROLLER_H
#define VEHICLELISTCONTROLLER_H

#include "controller.h"
#include "View/vehiclelist.h"
#include "Model/garage.h"
#include "Controller/jsonagent.h"
#include <iostream>

class vehiclelistcontroller : public controller
{

    Q_OBJECT

private:
    void connectViewController() const;

public:
    vehiclelistcontroller(vehiclelist* v, garage* g, controller* parent = nullptr);
    view* getView() const override;
    model* getModel() const override;

signals:

public slots:
    virtual void onClosedView() const override;
    void loadVehicleSlot() const;
    void newVehicleSlot() const;
};

#endif // VEHICLELISTCONTROLLER_H
