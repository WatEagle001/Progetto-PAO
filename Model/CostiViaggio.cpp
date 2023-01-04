#include <Model/CostiViaggio.h>

void CostiViaggio::addViaggio(veicolo* veicolo, string part, string arr, int km, double efficienza, double carbur, double elett){
    v.push_back(veicolo);
    if(dynamic_cast<motore_combustione*>(veicolo)){
    costi.push_back((km/100) * efficienza * carbur);
    }
    if(dynamic_cast<motore_elettrico*>(veicolo)){
        costi.push_back((km/100) * efficienza * elett);
    }
    partenza.push_back(part);
    arrivo.push_back(arr);
    km_percorsi.push_back(km);
    efficienza_riportata.push_back(efficienza);
    costo_carburante.push_back(carbur);
    costo_elettricita.push_back(elett);

}

double CostiViaggio::getCostiVeicolo(veicolo* c){
    double costo = 0;
   for(int i = 0; i < v.size(); i++){
       if(v[i]->getTarga() == c->getTarga()){
           costo += costi[i];
       }
   }
   return costo;
}

CostiViaggio::~CostiViaggio(){
    /*delete &v;
    delete &costi;
    delete &partenza;
    delete &arrivo;
    delete &km_percorsi;
    delete &efficienza_riportata;
    delete &costo_carburante;
    delete &costo_elettricita;
    */
}


