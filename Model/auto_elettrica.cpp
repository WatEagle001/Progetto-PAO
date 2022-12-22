#include "auto_elettrica.h"


auto_elettrica::auto_elettrica(
    string _marca,
    string _modello,
    string _targa,
    int _km_odometro,
    unsigned int _kw_batteria,
    bool _ricaricare,
   double _costo_ricarica
):
    veicolo(_marca, _modello, _targa, _km_odometro),
    motore_elettrico(_marca, _modello,_km_odometro,_kw_batteria, _ricaricare, _costo_ricarica, _targa){}

auto_elettrica::~auto_elettrica()
{

}
