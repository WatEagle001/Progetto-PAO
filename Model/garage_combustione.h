#ifndef GARAGE_COMBUSTIONEH_H
#define GARAGE_COMBUSTIONEH_H
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


class garage_combustione
{
private:
    Array<motore_combustione*> _macchine;
public:

    garage_combustione(): _macchine(nullptr){};
    void addVeicolo(motore_combustione* const veicolo);
    double getCostoGarage();
    void deleteVeicolo(motore_combustione* veicolo);
    void printGarage() const;
};

#endif // GARAGE_COMBUSTIONEH_H
