
#ifndef DIALOGVIAGGIOCONTROLLER_H
#define DIALOGVIAGGIOCONTROLLER_H

#include "Controller/controller.h"
#include "View/dialogviaggio.h"
#include "Model/garage.h"
#include "Model/CostiViaggio.h"

class dialogviaggiocontroller : public controller
{


private:
    void connectViewController() const;
    garage* m;
    CostiViaggio* c;
    veicolo* veic;


public:
    view* getView() const override;
    model* getModel() const override;
    dialogviaggiocontroller(DialogViaggio* v, veicolo* vehicle, garage* g, CostiViaggio* costi, controller* parent = nullptr);

public slots:
    void saveViaggio(veicolo* veic, string partenza, string arrivo, int km_percorsi, double efficienza, double costo_carburante = 0, double costo_elettricita = 0);
    void onClosedView() const override;
};

#endif // DIALOGVIAGGIOCONTROLLER_H

