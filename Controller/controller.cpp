#include "controller.h"

#include <iostream>

void controller::connectViewController() const
{

    connect(v, SIGNAL(viewClosed()), this, SLOT(onClosedView()));
}

controller::controller(view *_v, model *_m, controller *parent) : QObject(parent), v(_v), m(_m)
{
    connectViewController();
}

controller::~controller()
{
    setParent(nullptr);
    for(auto c : children())
        delete c;

    delete v;
    delete m;
}

void controller::showView() const
{
    v->show();
}

void controller::hideView() const
{
    v->hide();
}
