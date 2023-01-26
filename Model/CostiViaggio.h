#ifndef COSTIVIAGGIO_H
#define COSTIVIAGGIO_H

#include "Model/motore_combustione.h"
#include "Model/motore_elettrico.h"
#include "Model/veicolo.h"
#include "Model/array.h"
#include "Model/model.h"

class CostiViaggio: public model{
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
   CostiViaggio() : v(0), costi(0), partenza(" "), arrivo(" "), km_percorsi(0), efficienza_riportata(0), costo_carburante(0), costo_elettricita(0){};
   void addViaggio(veicolo* veicolo,string part, string arr,int km,double efficienza, double carbur, double elett);
   double getCostiVeicolo(veicolo* c);
   double getCostiCombustione();
   double getCostiElettrico();
   Array<int> getKm_percorsi() const;
   double getCostoMedio();
   double getCostoMax();
   double getCostoMin();
   int getMaxDistanza();
   int getMinDistanza();
   int getMediaDistanza();
   Array<veicolo *> getV() const;
   Array<double> getCosti() const;
};

#endif // COSTIVIAGGIO_H
