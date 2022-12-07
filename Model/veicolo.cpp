#include "veicolo.h"

veicolo::veicolo(
        std::string _marca,
        std::string _modello,
        std::string _paese,
        std::string _descrizione,
        double _rapp_peso_pot,
        unsigned int _cavalli,
        unsigned int _peso,
        unsigned int _nm
        ):
 marca(_marca),
 modello(_modello),
 paese(_paese),
 descrizione(_descrizione),
 rapp_peso_pot(_rapp_peso_pot),
 cavalli(_cavalli),
 peso(_peso),
 nm(_nm){};

veicolo::~veicolo() = default;

string veicolo::getModello() const{
    return modello;
}

void veicolo::setModello(const string &newModello){
    modello = newModello;
}

string veicolo::getPaese() const{
    return paese;
}

void veicolo::setPaese(const string &newPaese){
    paese = newPaese;
}

string veicolo::getDescrizione() const{
    return descrizione;
}

void veicolo::setDescrizione(const string &newDescrizione){
    descrizione = newDescrizione;
}

double veicolo::getRapp_peso_pot() const{
    return rapp_peso_pot;
}

void veicolo::setRapp_peso_pot(double newRapp_peso_pot){
    rapp_peso_pot = newRapp_peso_pot;
}

unsigned int veicolo::getCavalli() const{
    return cavalli;
}

/*void veicolo::setCavalli(unsigned int newCavalli){
    cavalli = newCavalli;
}
*/
unsigned int veicolo::getPeso() const{
    return peso;
}

void veicolo::setPeso(unsigned int newPeso){
    peso = newPeso;
}

unsigned int veicolo::getNm() const{
    return nm;
}

void veicolo::setNm(unsigned int newNm){
    nm = newNm;
}

string veicolo::getMarca() const{
    return marca;
}

void veicolo::setMarca(const string &newMarca){
    marca = newMarca;
}