#include "motore_combustione.h"

motore_combustione::motore_combustione(
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
    veicolo(_marca, _modello, _targa, _km_odometro),
    cilindrata(_cilindrata), litri_serbatoio(_litri_serbatoio), carburante(_carburante), manutenzione(_manutenzione), costo_manutenzione(_costo_manutenzione){}


motore_combustione::~motore_combustione() = default;

bool motore_combustione::getManutenzione() const
{
    return manutenzione;
}

void motore_combustione::setManutenzione(bool newManutenzione)
{
    manutenzione = newManutenzione;
}

unsigned int motore_combustione::getCosto_manutenzione() const
{
    return costo_manutenzione;
}
void motore_combustione::setCosto_manutenzione(unsigned int newCosto_manutenzione)
{
    costo_manutenzione = newCosto_manutenzione;
}

unsigned int motore_combustione::getCilindrata() const
{
    return cilindrata;
}

void motore_combustione::setCilindrata(unsigned int newCilindrata)
{
    cilindrata = newCilindrata;
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
