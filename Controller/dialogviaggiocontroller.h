#ifndef DIALOGVIAGGIOCONTROLLER_H
#define DIALOGVIAGGIOCONTROLLER_H

#include "Controller/controller.h"
#include "View/dialogviaggio.h"
#include "Model/garage.h"
#include "Model/CostiViaggio.h"
#include "View/vehiclelist.h"
#include "Controller/vehiclelistcontroller.h"

// Estensione di Controller utilizzata per la gesione dell'inserimento di un nuovo viaggio
class dialogviaggiocontroller : public controller
{
private:
    void connectViewController() const;
    garage* m;
    CostiViaggio* c;
    veicolo* veic;
    string part;

public:
    view* getView() const override;
    model* getModel() const override;
    dialogviaggiocontroller(DialogViaggio* v, veicolo* vehicle, garage* g, CostiViaggio* costi, controller* parent = nullptr);

public slots:
    void saveViaggio(veicolo* veic, std::string partenza, std::string arrivo, int km_percorsi, double efficienza, double costo_carburante = 0, double costo_elettricita = 0);
    void onClosedView() const override;
};

#endif // DIALOGVIAGGIOCONTROLLER_H

