#ifndef WELCOMECONTROLLER_H
#define WELCOMECONTROLLER_H

#include "controller.h"
#include "View/welcome.h"
#include "Model/model.h"
#include "jsonagent.h"
#include "View/vehiclelist.h"

#include <QFileDialog>
#include <QStringList>
#include <QJsonDocument>


class welcomeController : public controller
{
    Q_OBJECT

private:
    void connectViewController() const;
    garage* g;
    vehiclelistcontroller* c;
    vehiclelist* vehicle;
    CostiViaggio* co;

public:
    explicit welcomeController(welcome* v,garage* dati, CostiViaggio* costi, controller* parent = nullptr);
    welcome* getView() const override;
    model* getModel() const override;
    virtual ~welcomeController() = default;

signals:

public slots:
    void NewGarage();
    void OpenGarage() const;
    void onClosedView() const override;
};

#endif // WELCOMECONTROLLER_H
