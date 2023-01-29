#include "moto_elettrica.h"

moto_elettrica::moto_elettrica(
    string _marca,
    string _modello,
    int _km_odometro,
    unsigned int _kw_batteria,
    bool _ricaricare,
    double _costo_ricarica,
    string _targa
):
    veicolo(_marca, _modello,_targa,_km_odometro),
    motore_elettrico(_marca, _modello,_km_odometro,_kw_batteria, _ricaricare, _costo_ricarica,_targa){}

moto_elettrica::~moto_elettrica() = default;

