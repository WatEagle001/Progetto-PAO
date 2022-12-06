#include "motore_elettrico.h"

motore_elettrico::motore_elettrico(
    std::string _marca,
    std::string _modello,
    std::string _paese,
    std::string _descrizione,
    double _rapp_peso_pot,
    unsigned int _cavalli,
    unsigned int _peso,
    unsigned int _nm,
    unsigned int _cv_fiscali,
    unsigned int _kw_batteria
):
    veicolo(_marca, _modello, _paese, _descrizione, _rapp_peso_pot, _cavalli, _peso, _nm), cv_fiscali(_cv_fiscali), kw_batteria(_kw_batteria){}

motore_elettrico::~motore_elettrico() = default;

unsigned int motore_elettrico::getCv_fiscali() const
{
    return cv_fiscali;
}

void motore_elettrico::setCv_fiscali(unsigned int newCv_fiscali)
{
    cv_fiscali = newCv_fiscali;
}

unsigned int motore_elettrico::getKw_batteria() const
{
    return kw_batteria;
}

void motore_elettrico::setKw_batteria(unsigned int newKw_batteria)
{
    kw_batteria = newKw_batteria;
}


