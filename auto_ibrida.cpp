#include "auto_ibrida.h"


auto_ibrida::auto_ibrida():
    veicolo(marca, modello, paese, descrizione, rapp_peso_pot, cavalli, peso, nm),
    motore_combustione(cilindrata, cilindri, litri_serbatoio, carburante),
    motore_elettrico(cv_fiscali, kw_batteria){};
