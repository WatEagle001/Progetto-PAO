#include "motore_elettrico.h"

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

motore_elettrico::motore_elettrico(unsigned int _cv_fiscali, unsigned int _kw_batteria):
    veicolo(marca, modello, paese, descrizione, rapp_peso_pot, cavalli, peso, nm),
    cv_fiscali(_cv_fiscali), kw_batteria(_kw_batteria){}

motore_elettrico::~motore_elettrico() = default;

