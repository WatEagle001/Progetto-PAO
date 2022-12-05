#ifndef AUTO_IBRIDA_H
#define AUTO_IBRIDA_H
#include "motore_combustione.h"
#include "motore_elettrico.h"
class auto_ibrida: public motore_combustione, public motore_elettrico{
public:
    auto_ibrida(std::string _marca, std::string _modello, std::string _paese, std::string _descrizione, double _rapp_peso_pot, unsigned int _cavalli, unsigned int _peso, unsigned int _nm, unsigned int _cilindrata = 0, unsigned int _cilindri = 0, unsigned int _litri_serbatoio =  0, alimentazione _carburante = benzina, unsigned int _cv_fiscali = 0, unsigned int _kw_batteria = 0);
};

#endif // AUTO_IBRIDA_H
