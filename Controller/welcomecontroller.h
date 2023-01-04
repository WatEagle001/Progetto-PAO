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

public:
    explicit welcomeController(welcome* v, controller* parent = nullptr);
    welcome* getView() const override;
    model* getModel() const override;

signals:

public slots:
    void NewGarage() const;
    void OpenGarage() const;
    void onClosedView() const override;
    void OpenMainWindow() const;


};

#endif // WELCOMECONTROLLER_H
