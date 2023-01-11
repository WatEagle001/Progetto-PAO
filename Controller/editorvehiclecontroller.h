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

public:
    editorvehiclecontroller(editorvehicle* v, garage* g,controller* parent = nullptr);
    view* getView() const override;
    garage* getModel() const override;

signals:

public slots:
    virtual void onClosedView() const override;
    void saveSlot() const;
    void clearSlot() const;
};


#endif // EDITORVEHICLECONTROLLER_H
