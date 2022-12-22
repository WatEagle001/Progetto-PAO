#ifndef GARAGE_ELETTRICOH_H
#define GARAGE_ELETTRICOH_H
#include <Model/automobile.h>
#include <Model/auto_elettrica.h>
#include <Model/auto_ibrida.h>
#include <Model/moto_elettrica.h>
#include <Model/monopattino_elettrico.h>
#include <Model/veicolo.h>
#include <Model/CostiViaggio.h>
#include "Model/array.h"
#include <iostream>
using std::cout;
using std::endl;



class garage_elettrico
{
private:
    Array<motore_elettrico*> _macchine_elettriche;
public:

    garage_elettrico(): _macchine_elettriche(nullptr){};
    void addVeicolo(motore_elettrico* const veicolo);
    double getCostoGarage();
    void deleteVeicolo(motore_elettrico* veicolo);
    void printGarage() const;
};

#endif // GARAGE_ELETTRICOH_H
