#ifndef EDITORVEHICLECONTROLLER_H
#define EDITORVEHICLECONTROLLER_H
#include "controller.h"
#include "View/vehiclelist.h"
#include "Model/garage.h"
#include "Controller/jsonagent.h"
#include <iostream>
#include "View/editorvehicle.h"
#include "Model/CostiViaggio.h"

class editorvehiclecontroller : public controller
{

    Q_OBJECT

private:
    void connectViewController() const;
    garage* g;
    veicolo* veic;
    veicolo* nuovo;
    automobile* nuovoa;
    CostiViaggio* c;

public:
    editorvehiclecontroller(editorvehicle* v, garage* m, CostiViaggio* costi,controller* parent = nullptr,veicolo* n = nullptr);
    virtual ~editorvehiclecontroller() = default;

    view* getView() const override;
    garage* getModel() const override;

signals:

public slots:
    virtual void onClosedView() const override;
    void saveSlot(veicolo* veic,veicolo* nuovo);
    void clearSlot();
    void editVehicleSlot();
};


#endif // EDITORVEHICLECONTROLLER_H
