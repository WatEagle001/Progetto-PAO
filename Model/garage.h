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

class garage{
private:
    Array<veicolo*> _veicoli;
public:
    garage(): _veicoli(nullptr){};
    // ~garage() = 0;
     void addVeicolo(veicolo* const veicolo);
     void deleteVeicolo(veicolo* veicolo);
     void printGarage() const;
     void eraseGarage();
     double getCostoGarage() const;
     void orderGarage();
     void editVeicolo(veicolo *veicolo, string marca = "", string modello = "", string targa = "", alimentazione alim = benzina, unsigned int cilindrata = 0, unsigned int litri_serbatoio = 0, bool manutenzione = 0, unsigned int costo_manutenzione = 0, unsigned int kw_batteria = 0, double costo_ricarica = 0, bool ricaricare = 0);
     void deleteVeicolo(Array<veicolo *>::iterator it);
};

#endif // GARAGE_H
