#ifndef DETAILEDCOSTSCONTROLLER_H
#define DETAILEDCOSTSCONTROLLER_H

#include <QFileDialog>
#include <QStringList>
#include <QJsonDocument>

#include <Controller/jsonagent.h>
#include "Controller/controller.h"
#include "View/vehiclelist.h"
#include "View/detailedcosts.h"
#include "Model/garage.h"
#include "Model/CostiViaggio.h"
#include "Model/model.h"

class detailedcostscontroller : public controller
{
    Q_OBJECT

private:
    void connectViewController() const;
    CostiViaggio* cost;
    vehiclelistcontroller* c;
    vehiclelist* vehicle;
    garage * gar;

public:
    explicit detailedcostscontroller(detailedcosts* v,CostiViaggio* dati, garage* g, controller* parent = nullptr);
    detailedcosts* getView() const override;
    model* getModel() const override;
    virtual ~detailedcostscontroller() = default;
    void onClosedView() const override;
};


#endif // DETAILEDCOSTSCONTROLLER_H
