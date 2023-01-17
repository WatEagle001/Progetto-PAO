#ifndef GARAGE_H
#define GARAGE_H
#include <Model/veicolo.h>
#include <Model/array.h>
#include <iostream>
#include <Model/automobile.h>
#include <Model/auto_elettrica.h>
#include <Model/auto_ibrida.h>
#include <Model/moto_elettrica.h>
#include <Model/moto.h>
#include <Model/monopattino_elettrico.h>
#include <Model/veicolo.h>
using std::cout;
using std::endl;
#include <vector>
#include <algorithm>
#include <Model/model.h>

class garage:public model{
private:
    Array<veicolo*> _veicoli;
public:
     garage();
     virtual ~garage() = default;
     void addVeicolo(veicolo* const veicolo);
     void deleteVeicolo(veicolo* veicolo);
     void printGarage() const;
     void eraseGarage();
     double getCostoGarage() const;
     veicolo* getVeicolo(int n);
     void editVeicolo(veicolo *veicolo, string marca = "", string modello = "", string targa = "", alimentazione alim = benzina, unsigned int cilindrata = 0, unsigned int litri_serbatoio = 0, bool manutenzione = 0, unsigned int costo_manutenzione = 0, unsigned int kw_batteria = 0, double costo_ricarica = 0, bool ricaricare = 0);
     Array<veicolo*> getVeicoli(string targa) const;
     void setVeicoli(const Array<veicolo *> &newVeicoli);
     int size() const;
};

#endif // GARAGE_H
