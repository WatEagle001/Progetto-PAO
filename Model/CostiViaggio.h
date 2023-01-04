#ifndef COSTIVIAGGIO_H
#define COSTIVIAGGIO_H

#include "Model/motore_combustione.h"
#include "Model/motore_elettrico.h"
#include "Model/veicolo.h"
#include "Model/array.h"

class CostiViaggio{
private:
   Array<veicolo*> v;
   Array<double> costi;
   Array<string> partenza;
   Array<string> arrivo;
   Array<int> km_percorsi;
   Array<double> efficienza_riportata; // indicatore della macchina
   Array<double> costo_carburante;
   Array<double> costo_elettricita;
public:
   CostiViaggio() : v(nullptr), costi(NULL), partenza(""), arrivo(""), km_percorsi(NULL), efficienza_riportata(NULL), costo_carburante(NULL), costo_elettricita(NULL){};
   void addViaggio(veicolo* veicolo,string part, string arr,int km,double efficienza, double carbur, double elett);
   double getCostiVeicolo(veicolo* c);
   ~CostiViaggio();

};

#endif // COSTIVIAGGIO_H
