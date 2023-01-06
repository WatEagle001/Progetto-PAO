#include <Model/CostiViaggio.h>

Array<int> CostiViaggio::getKm_percorsi() const{
    return km_percorsi;
}

double CostiViaggio::getCostoMedio(){
    double sum = 0;
    for(Array<double>::iterator it = costi.begin(); it != costi.end(); it++){
        sum += costi[it];
    }
    return sum/costi.size();
}

double CostiViaggio::getCostoMax(){
    double max = 0;
    for(Array<double>::iterator it = costi.begin(); it != costi.end(); it++){
        if(costi[it]>= max)
            max = costi[it];
    }
    return max;
}

double CostiViaggio::getCostoMin(){
    double min = 0;
    for(Array<double>::iterator it = costi.begin(); it != costi.end(); it++){
        if(costi[it] < min)
            min = costi[it];
    }
    return min;
}

int CostiViaggio::getMaxDistanza(){
    int max = 0;
    for(Array<int>::iterator it = km_percorsi.begin(); it != km_percorsi.end(); it++){
        if(km_percorsi[it]>= max)
            max = km_percorsi[it];
    }
    return max;
}

int CostiViaggio::getMinDistanza(){
    int min = this->getMaxDistanza();
    for(Array<int>::iterator it = km_percorsi.begin(); it != km_percorsi.end(); it++){
        if(km_percorsi[it]<= min && km_percorsi[it] >= 0)
            min = km_percorsi[it];
    }
    return min;
}

int CostiViaggio::getMediaDistanza(){
    double sum = 0;
    for(Array<int>::iterator it = km_percorsi.begin(); it != km_percorsi.end(); it++){
        sum += km_percorsi[it];
    }
    return sum/km_percorsi.size();
}


void CostiViaggio::addViaggio(veicolo* veicolo, string part, string arr, int km, double efficienza, double carbur, double elett){
    v.push_back(veicolo);
    if(dynamic_cast<motore_combustione*>(veicolo)){
    costi.push_back((km/100) * efficienza * carbur);
    }
    else{
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

double CostiViaggio::getCostiCombustione(){
    double costo = 0;
   for(int i = 0; i < v.size(); i++){
       if(dynamic_cast<motore_combustione*>(v[i])){
           costo += costi[i];
       }
   }
   return costo;
}



double CostiViaggio::getCostiElettrico(){
    double costo = 0;
   for(int i = 0; i < v.size(); i++){
       if(dynamic_cast<motore_elettrico*>(v[i])){
           costo += costi[i];
       }
   }
   return costo;
}

void insertionSort(int* array, int size) {
   int key, j;
   for(int i = 1; i<size; i++) {
      key = array[i];//take value
      j = i;
      while(j > 0 && array[j-1]>key) {
         array[j] = array[j-1];
         j--;
      }
      array[j] = key;   //insert in right place
   }
}
