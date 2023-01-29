#include "garage_combustione.h"


void garage_combustione::addVeicolo(motore_combustione * const veicolo)
{
    _macchine.push_back(veicolo);
}

double garage_combustione::getCostoGarage()
{
    double costo = 0;
    for(Array<motore_combustione*>::iterator it = _macchine.begin(); it != _macchine.end(); it++){
        if(_macchine[it]->getManutenzione() == 1){
            motore_elettrico* ptr = dynamic_cast<motore_elettrico*>(_macchine[it]);
            if(ptr != nullptr && ptr->getRicaricare() == 1){ // caso macchina ibrida
                costo+= ptr->getCosto_ricarica();
            }
        costo +=_macchine[it]->getCosto_manutenzione();
        }
    }
    return costo;

}

void garage_combustione::deleteVeicolo(motore_combustione *veicolo){
    for(Array<motore_combustione*>::iterator it = _macchine.begin(); it != _macchine.end(); it++){
        if(_macchine[it]->getTarga() == veicolo->getTarga()){
            _macchine.erase(it);
        }

}
}

void garage_combustione::printGarage() const
{
    for(int i = 0; i < _macchine.size(); i++){
        cout<<_macchine[i]->getTarga()<<endl;
        //const std::type_info& ti1 = typeid(first->info);
       // cout << ti1.name();
    }
}
