#ifndef DETAILEDVEHICLEVIEWCONTROLLER_H
#define DETAILEDVEHICLEVIEWCONTROLLER_H

#include "Controller/controller.h"
#include "View/detailedvehicleview.h"
#include "View/detailedvehicleview.h"
#include "Model/CostiViaggio.h"
#include "Model/garage.h"

class detailedvehicleviewcontroller : public controller
{
    Q_OBJECT
private:
    void connectViewController() const;
    veicolo* veic;
    garage* g;
    CostiViaggio *c;

public:
    explicit detailedvehicleviewcontroller(detailedvehicleview* v, garage* m, CostiViaggio* cost, controller* parent = nullptr);
    view* getView() const override;
    garage* getModel() const override;
    virtual ~detailedvehicleviewcontroller() = default;
signals:

public slots:
    virtual void onClosedView() const override;
};


#endif // DETAILEDVEHICLEVIEWCONTROLLER_H
