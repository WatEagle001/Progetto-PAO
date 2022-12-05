#include "auto_elettrica.h"


auto_elettrica::auto_elettrica():
    veicolo(marca, modello, paese, descrizione, rapp_peso_pot, cavalli, peso, nm),
    motore_elettrico(cv_fiscali, kw_batteria){}

auto_elettrica::~auto_elettrica()
{

};
