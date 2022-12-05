#include "auto_elettrica.h"


auto_elettrica::auto_elettrica(
    string _marca,
    string _modello,
    string _paese,
    string _descrizione,
    double _rapp_peso_pot,
    unsigned int _cavalli,
    unsigned int _peso,
    unsigned int _nm,
    unsigned int _cv_fiscali,
    unsigned int _kw_batteria
):
    veicolo(_marca, _modello, _paese, _descrizione, _rapp_peso_pot, _cavalli, _peso, _nm),
    motore_elettrico(_marca, _modello, _paese, _descrizione, _rapp_peso_pot, _cavalli, _peso, _nm ,_cv_fiscali, _kw_batteria){}

auto_elettrica::~auto_elettrica()
{

}
