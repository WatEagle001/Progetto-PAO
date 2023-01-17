#ifndef VEHICLELISTITEMCONTROLLER_H
#define VEHICLELISTITEMCONTROLLER_H

#include "controller.h"
#include "View/vehiclelist.h"
#include "Model/veicolo.h"
#include "View/vehiclelistitem.h"
#include "View/vehiclelist.h"
#include <iostream>

/*class vehiclelistitemcontroller : public controller
{
    Q_OBJECT
private:
    void connectViewController() const;
    veicolo* veic;
public:
    explicit vehiclelistitemcontroller(vehicleListItem* v, veicolo* m, controller* parent = nullptr);
    view* getView() const override;
    //veicolo* getModel() const override;
signals:

public slots:
    virtual void onClosedView() const override;
    void editVehicleSlot(veicolo* v);
    void deleteVehicleSlot(veicolo* v);
};
*/
#endif // VEHICLELISTITEMCONTROLLER_H
