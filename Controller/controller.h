#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "View/view.h"
#include "Model/model.h"

class controller : public QObject{
    Q_OBJECT

private:
    void connectViewController() const;

protected:
    view* v;
    model* m;

public:
    explicit controller(view* _v, model* _m, controller* parent = nullptr);
    virtual ~controller();
    virtual view* getView() const = 0;
    virtual model* getModel() const = 0;
    virtual void showView() const;
    virtual void hideView() const;

signals:

public slots:
    virtual void onClosedView() const = 0;
};

#endif
