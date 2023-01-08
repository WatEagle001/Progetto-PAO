#ifndef VEHICLELISTCONTROLLER_H
#define VEHICLELISTCONTROLLER_H

#include "controller.h"
#include "View/vehiclelist.h"
#include "Model/garage.h"

class vehiclelistcontroller : public controller
{

    Q_OBJECT

private:
    void connectViewController() const;

public:
    vehiclelistcontroller(vehiclelist* v, garage* g, controller* parent = nullptr);
    view* getView() const;
    model* getModel() const;

signals:

public slots:
    virtual void onClosedView() const;
};

#endif // VEHICLELISTCONTROLLER_H
