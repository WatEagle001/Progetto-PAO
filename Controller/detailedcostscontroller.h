#ifndef DETAILEDCOSTSCONTROLLER_H
#define DETAILEDCOSTSCONTROLLER_H

#include "controller.h"
#include "Model/model.h"
#include "jsonagent.h"
#include "View/vehiclelist.h"

#include <QFileDialog>
#include <QStringList>
#include <QJsonDocument>
#include <View/detailedcosts.h>
#include <Model/CostiViaggio.h>
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
