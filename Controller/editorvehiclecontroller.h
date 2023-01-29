#ifndef EDITORVEHICLECONTROLLER_H
#define EDITORVEHICLECONTROLLER_H

#include "Controller/controller.h"
#include "View/editorvehicle.h"
#include "Model/CostiViaggio.h"
#include "Model/garage.h"

class editorvehiclecontroller : public controller
{

    Q_OBJECT

private:
    void connectViewController() const;
    garage* g;
    veicolo* veic;
    veicolo* nuovo;
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

};


#endif // EDITORVEHICLECONTROLLER_H
