#include "garage_elettrico.h"


void garage_elettrico::addVeicolo(motore_elettrico * const veicolo)
{
    _macchine_elettriche.push_back(veicolo);
}

double garage_elettrico::getCostoGarage()
{
    double costo = 0;
    for(Array<motore_elettrico*>::iterator it = _macchine_elettriche.begin(); it != _macchine_elettriche.end(); it++){
            if(_macchine_elettriche[it] ->getRicaricare() == 1){ // caso macchina ibrida
                costo+=_macchine_elettriche[it]->getCosto_ricarica();
            }
        }
    return costo;
}

void garage_elettrico::deleteVeicolo(motore_elettrico *veicolo){
    for(Array<motore_elettrico*>::iterator it = _macchine_elettriche.begin(); it != _macchine_elettriche.end(); it++){
        if(_macchine_elettriche[it]->getTarga() == veicolo->getTarga()){
            _macchine_elettriche.erase(it);
        }

}
}

void garage_elettrico::printGarage() const
{
    for(int i = 0; i < _macchine_elettriche.size(); i++){
        cout<<_macchine_elettriche[i]->getTarga()<<endl;
        //const std::type_info& ti1 = typeid(first->info);
       // cout << ti1.name();
    }
}
