#include "auto_ibrida.h"


auto_ibrida::auto_ibrida(
    string _marca,
    string _modello,
    string _targa,
    int _km_odometro,
    unsigned int _cilindrata,
    unsigned int _litri_serbatoio,
    alimentazione _carburante,
    unsigned int _kw_batteria,
    bool _manutenzione,
    unsigned int _costo_manutenzione,
    bool _ricaricare,
    double _costo_ricarica
):
    veicolo(_marca, _modello, _targa,_km_odometro),
    motore_combustione(_marca, _modello,_targa,_km_odometro, _cilindrata, _litri_serbatoio, _carburante, _manutenzione, _costo_manutenzione),
    motore_elettrico(_marca, _modello,_km_odometro,_kw_batteria, _ricaricare, _costo_ricarica, _targa){}

auto_ibrida::~auto_ibrida() = default;



