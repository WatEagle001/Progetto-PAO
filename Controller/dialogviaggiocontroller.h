#ifndef DIALOGVIAGGIOCONTROLLER_H
#define DIALOGVIAGGIOCONTROLLER_H

#include "Controller/controller.h"
#include "View/dialogviaggio.h"
#include "Model/garage.h"

class dialogviaggiocontroller : public controller
{


private:
    void connectViewController() const;
    garage* m;
    veicolo* veic;

public:
    view* getView() const override;
    model* getModel() const override;
    dialogviaggiocontroller(DialogViaggio* v, veicolo* veic, garage* g, controller* parent = nullptr);

public slots:
    void saveViaggio();
    void onClosedView() const override;
};

#endif // DIALOGVIAGGIOCONTROLLER_H
