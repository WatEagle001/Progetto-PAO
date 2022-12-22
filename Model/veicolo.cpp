#include "veicolo.h"
#include <string>
using std::string;


string veicolo::getTarga() const{
    return targa;
}

void veicolo::setTarga(const string &newTarga){
    targa = newTarga;
}

int veicolo::getKm_odometro() const{
    return km_odometro;
}

void veicolo::setKm_odometro(int newKm_odometro){
    km_odometro = newKm_odometro;
}

veicolo::veicolo(
        string _marca,
        string _modello,
        string _targa,
        int _km_odometro
        ):
 marca(_marca),modello(_modello),targa(_targa), km_odometro(_km_odometro){};

veicolo::~veicolo() = default;

string veicolo::getModello() const{
    return modello;
}

void veicolo::setModello(const string& newModello){
    modello = newModello;
}

string veicolo::getMarca() const{
    return marca;
}

void veicolo::setMarca(const string& newMarca){
    marca = newMarca;
}
