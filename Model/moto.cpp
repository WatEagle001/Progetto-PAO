#include "moto.h"

moto::moto(
    std::string _marca,
    std::string _modello,
    std::string _paese,
    std::string _descrizione,
    double _rapp_peso_pot,
    unsigned int _cavalli,
    unsigned int _peso,
    unsigned int _nm,
    unsigned int _cilindrata,
    unsigned int _cilindri,
    unsigned int _litri_serbatoio,
    alimentazione _carburante
):
    veicolo(_marca, _modello, _paese, _descrizione, _rapp_peso_pot, _cavalli, _peso, _nm),
    motore_combustione(_marca, _modello, _paese, _descrizione, _rapp_peso_pot, _cavalli, _peso, _nm, _cilindrata, _cilindri, _litri_serbatoio, _carburante){};
