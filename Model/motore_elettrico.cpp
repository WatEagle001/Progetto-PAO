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
    unsigned int _kw_batteria
        ):
    veicolo(_marca, _modello, _paese, _descrizione, _rapp_peso_pot, _cavalli, _peso, _nm), kw_batteria(_kw_batteria){}

void motore_elettrico::setCavalli(unsigned int newCavalli)
{
    cavalli = newCavalli/8.5; //corrispondono ai cavalli fiscali dichiarati nella carta di circolazione
}

motore_elettrico::~motore_elettrico() = default;

unsigned int motore_elettrico::getKw_batteria() const
{
    return kw_batteria;
}

void motore_elettrico::setKw_batteria(unsigned int newKw_batteria)
{
    kw_batteria = newKw_batteria;
}

