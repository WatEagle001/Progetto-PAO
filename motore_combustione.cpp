#include "motore_combustione.h"

unsigned int motore_combustione::getCilindrata() const
{
    return cilindrata;
}

void motore_combustione::setCilindrata(unsigned int newCilindrata)
{
    cilindrata = newCilindrata;
}

unsigned int motore_combustione::getCilindri() const
{
    return cilindri;
}

void motore_combustione::setCilindri(unsigned int newCilindri)
{
    cilindri = newCilindri;
}

unsigned int motore_combustione::getLitri_serbatoio() const
{
    return litri_serbatoio;
}

void motore_combustione::setLitri_serbatoio(unsigned int newLitri_serbatoio)
{
    litri_serbatoio = newLitri_serbatoio;
}

char motore_combustione::getAlimentazione() const
{
    return carburante;
}

void motore_combustione::setAlimentazione(alimentazione newAlimentazione)
{
    carburante  = newAlimentazione;
}

motore_combustione::motore_combustione(std::string _marca, std::string _modello, std::string _paese, std::string _descrizione, double _rapp_peso_pot, unsigned int _cavalli, unsigned int _peso, unsigned int _nm, unsigned int _cilindrata, unsigned int _cilindri, unsigned int _litri_serbatoio, alimentazione _carburante):
    veicolo(_marca, _modello, _paese, _descrizione, _rapp_peso_pot, _cavalli, _peso, _nm),
    cilindrata(_cilindrata), cilindri(_cilindri), litri_serbatoio(_litri_serbatoio), carburante(_carburante){}

motore_combustione::~motore_combustione() = default;


