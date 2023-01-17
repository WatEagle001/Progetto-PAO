#include "motore_elettrico.h"

bool motore_elettrico::getRicaricare() const
{
    return ricaricare;
}

void motore_elettrico::setRicaricare(bool newRicaricare)
{
    ricaricare = newRicaricare;
}

double motore_elettrico::getCosto_ricarica() const
{
    return costo_ricarica;
}

void motore_elettrico::setCosto_ricarica(double newCosto_ricarica)
{
    costo_ricarica = newCosto_ricarica;
}

motore_elettrico::motore_elettrico(
    string _marca,
    string _modello,
    int _km_odometro,
    unsigned int _kw_batteria,
    bool _ricaricare,
        double _costo_ricarica,
    string _targa
        ):
    veicolo(_marca, _modello,_targa,_km_odometro),kw_batteria(_kw_batteria), costo_ricarica(_costo_ricarica), ricaricare(_ricaricare){}

motore_elettrico::~motore_elettrico() = default;

unsigned int motore_elettrico::getKw_batteria() const
{
    return kw_batteria;
}

void motore_elettrico::setKw_batteria(unsigned int newKw_batteria)
{
    kw_batteria = newKw_batteria;
}

