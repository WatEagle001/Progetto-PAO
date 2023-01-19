#ifndef EDITORVEHICLECONTROLLER_H
#define EDITORVEHICLECONTROLLER_H
#include "controller.h"
#include "View/vehiclelist.h"
#include "Model/garage.h"
#include "Controller/jsonagent.h"
#include <iostream>
#include "View/editorvehicle.h"

class editorvehiclecontroller : public controller
{

    Q_OBJECT

private:
    void connectViewController() const;
    garage* g;
    veicolo* veic;
    veicolo* nuovo;

public:
    editorvehiclecontroller(editorvehicle* v, garage* m,controller* parent = nullptr,veicolo* n = nullptr);
    view* getView() const override;
    garage* getModel() const override;

signals:

public slots:
    virtual void onClosedView() const override;
    void saveSlot(veicolo* veic,veicolo* nuovo);
    //void saveSlot();
    void clearSlot();
    void editVehicleSlot();
};


#endif // EDITORVEHICLECONTROLLER_H
