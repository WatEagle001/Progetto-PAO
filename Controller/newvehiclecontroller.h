#ifndef NEWVEHICLECONTROLLER_H
#define NEWVEHICLECONTROLLER_H

#include "Controller/controller.h"
#include <View/editorvehicle.h>
#include "View/newvehicle.h"
#include "Model/garage.h"
#include "Model/CostiViaggio.h"

class newvehiclecontroller : public controller
{

    Q_OBJECT

private:
    void connectViewController() const;
    garage* g;
    veicolo* veic;
    CostiViaggio* c;

public:
    newvehiclecontroller(newvehicle* v, garage* m,CostiViaggio* cost,controller* parent = nullptr, veicolo* veicol= nullptr);
    view* getView() const override;
    garage* getModel() const override;
    virtual ~newvehiclecontroller() = default;

signals:

public slots:
    virtual void onClosedView() const override;
    void saveSlot(veicolo* veic);
    //void newVehicleSlot();
    //void saveSlot();
    void clearSlot();
};


#endif // NEWVEHICLECONTROLLER_H
