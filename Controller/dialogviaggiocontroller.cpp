#include "dialogviaggiocontroller.h"

void dialogviaggiocontroller::connectViewController() const
{
    connect(v, SIGNAL(tryAddViaggio()), this, SLOT(saveViaggio()));
}

view *dialogviaggiocontroller::getView() const
{
    return static_cast<DialogViaggio*>(v);
}

model *dialogviaggiocontroller::getModel() const
{
    return static_cast<garage*>(m);
}

dialogviaggiocontroller::dialogviaggiocontroller(DialogViaggio *v, veicolo *veic, garage* g, controller *parent) : controller(v, g, parent)
{
    m = g;
    connectViewController();
}

void dialogviaggiocontroller::saveViaggio()
{

}

void dialogviaggiocontroller::onClosedView() const
{
    delete this;
}
