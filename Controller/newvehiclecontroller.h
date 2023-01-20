#ifndef NEWVEHICLECONTROLLER_H
#define NEWVEHICLECONTROLLER_H
#include "controller.h"
#include "View/vehiclelist.h"
#include "Model/garage.h"
#include "Controller/jsonagent.h"
#include <iostream>
#include "View/editorvehicle.h"
#include "View/newvehicle.h"

class newvehiclecontroller : public controller
{

    Q_OBJECT

private:
    void connectViewController() const;
    garage* g;
    veicolo* veic;
    automobile* nuovoa;

public:
    newvehiclecontroller(newvehicle* v, garage* m,controller* parent = nullptr, veicolo* veicol= nullptr);
    view* getView() const override;
    garage* getModel() const override;

signals:

public slots:
    virtual void onClosedView() const override;
    void saveSlot(veicolo* veic,veicolo* nuovo);
    void saveSlotAuto(veicolo* veic,automobile* nuovoa);
    //void saveSlot();
    void clearSlot();
    void newVehicleSlot();
};


#endif // NEWVEHICLECONTROLLER_H
