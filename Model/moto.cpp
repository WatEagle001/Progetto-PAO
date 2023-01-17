#include "moto.h"
#include <string>
using std::string;


moto::moto(
    string _marca,
    string _modello,
    string _targa,
    int _km_odometro,
    unsigned int _cilindrata,
    unsigned int _litri_serbatoio,
    alimentazione _carburante,
    bool _manutenzione,
    unsigned int _costo_manutenzione
):
    veicolo(_marca, _modello,_targa,_km_odometro),
    motore_combustione(_marca, _modello,_targa,_km_odometro, _cilindrata, _litri_serbatoio, _carburante, _manutenzione, _costo_manutenzione){}

moto::~moto() = default;
