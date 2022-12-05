#include "auto_ibrida.h"


auto_ibrida::auto_ibrida(
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
    alimentazione _carburante,
    unsigned int _cv_fiscali,
    unsigned int _kw_batteria
):
    veicolo(_marca, _modello, _paese, _descrizione, _rapp_peso_pot, _cavalli, _peso, _nm),
    motore_combustione(_marca, _modello, _paese, _descrizione, _rapp_peso_pot, _cavalli, _peso, _nm, _cilindrata, _cilindri, _litri_serbatoio, _carburante),
    motore_elettrico(_marca, _modello, _paese, _descrizione, _rapp_peso_pot, _cavalli, _peso, _nm ,_cv_fiscali, _kw_batteria){};


