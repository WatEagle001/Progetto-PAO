#include "Model/garage.h"

//garage::~garage()= default;

Array<veicolo *> garage::getVeicoli(string targa) const
{
    for(int i = 0; i < _veicoli.size(); i++){
        if(_veicoli[i]->getTarga() == targa){
            return _veicoli[i];
        }
    }

}

int garage::size() const
{
return _veicoli.size();
}


garage::garage(): _veicoli(nullptr){}

void garage::addVeicolo(veicolo* const veicolo) {
    _veicoli.push_back(veicolo);
}


void garage::deleteVeicolo(veicolo* veicolo){
    if(_veicoli.size() == 0){
        qDebug()<< QString("Garage ora vuoto");
    }
    else{
    for(int i = 0; i < _veicoli.size(); i++){
        if(_veicoli[i]->getTarga() == veicolo->getTarga()){
            for(int j = i; j < _veicoli.size()-1; j++){
                _veicoli[j] = _veicoli[i+1];
                i++;
            }
        }
    }
    _veicoli.pop_back();
    }
}
void garage::editVeicolo(veicolo* veicolo, string marca, string modello, string targa,int km_odometro, alimentazione alim, unsigned int cilindrata, unsigned int litri_serbatoio,
                        bool manutenzione, unsigned int costo_manutenzione, unsigned int kw_batteria, double costo_ricarica, bool ricaricare){
    for(int i = 0; i < _veicoli.size(); i++){
        if(_veicoli[i]->getTarga() == veicolo->getTarga()){
            _veicoli[i]->setMarca(marca);
            _veicoli[i]->setModello(modello);
            _veicoli[i]->setTarga(targa);
             _veicoli[i]->setKm_odometro(km_odometro);
            motore_combustione* ptr = dynamic_cast<motore_combustione*>(_veicoli[i]);
            if(dynamic_cast<automobile*>(ptr) || dynamic_cast<moto*>(ptr) || dynamic_cast<auto_ibrida*>(ptr)){
                ptr->setAlimentazione(alim);
                ptr->setCilindrata(cilindrata);
                ptr->setLitri_serbatoio(litri_serbatoio);
                ptr->setManutenzione(manutenzione);
                ptr->setCosto_manutenzione(costo_manutenzione);
            }
             motore_elettrico* e = dynamic_cast<motore_elettrico*>(_veicoli[i]);
             if(dynamic_cast<auto_elettrica*>(e) || dynamic_cast<moto_elettrica*>(e) || dynamic_cast<monopattino_elettrico*>(e) || dynamic_cast<auto_ibrida*>(e)){
                 e->setKw_batteria(kw_batteria);
                 e->setCosto_ricarica(costo_ricarica);
                 e->setRicaricare(ricaricare);
             }

        }
}
}


void garage::printGarage() const{
    for(int i = 0; i < _veicoli.size(); i++){
        cout<<_veicoli[i]->getTarga()<< " "<<_veicoli[i]->getMarca()<< " " << _veicoli[i]->getModello() << " " << _veicoli[i]->getKm_odometro() << endl;
    }
}

void garage::eraseGarage(){
    _veicoli.clear();
}

double garage::getCostoGarage() const{
    double costi = 0;
    for(int i = 0; i < _veicoli.size(); i++){
      motore_combustione* ptr = dynamic_cast<motore_combustione*>(_veicoli[i]);
      if(dynamic_cast<automobile*>(ptr) || dynamic_cast<moto*>(ptr) || dynamic_cast<auto_ibrida*>(ptr)){
         if(ptr->getManutenzione() == 1){
        costi+=(ptr->getCosto_manutenzione());
         }
      }
      motore_elettrico* e = dynamic_cast<motore_elettrico*>(_veicoli[i]);
      if(dynamic_cast<auto_elettrica*>(e) || dynamic_cast<moto_elettrica*>(e) || dynamic_cast<monopattino_elettrico*>(e) || dynamic_cast<auto_ibrida*>(e)){
          if(e->getRicaricare() == 1){
        costi+=(e->getCosto_ricarica());
      }
    }
    }

    return costi;
}

veicolo *garage::getVeicolo(int n)
{
 return _veicoli[n];
}



