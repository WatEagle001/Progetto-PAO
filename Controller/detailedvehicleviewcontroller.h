#ifndef DETAILEDVEHICLEVIEWCONTROLLER_H
#define DETAILEDVEHICLEVIEWCONTROLLER_H
#pragma once
#include "controller.h"
#include "View/vehiclelist.h"
#include "Model/garage.h"
#include "Controller/jsonagent.h"
#include <iostream>
#include <View/detailedvehicleview.h>

class detailedvehicleviewcontroller : public controller
{
    Q_OBJECT
private:
    void connectViewController() const;
    veicolo* veic;
public:
    explicit detailedvehicleviewcontroller(detailedvehicleview* v, garage* m, controller* parent = nullptr);
    view* getView() const override;
    garage* getModel() const override;
    virtual ~detailedvehicleviewcontroller() = default;
signals:

public slots:
    virtual void onClosedView() const override;
    void detailedVehicleViewSlot();
};


#endif // DETAILEDVEHICLEVIEWCONTROLLER_H
