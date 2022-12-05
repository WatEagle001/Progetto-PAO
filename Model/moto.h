#ifndef MOTO_H
#define MOTO_H
#include "motore_combustione.h"

class moto: public motore_combustione{
public:
    moto(
        std::string _marca,
        std::string _modello,
        std::string _paese,
        std::string _descrizione,
        double _rapp_peso_pot,
        unsigned int _cavalli,
        unsigned int _peso,
        unsigned int _nm,
        unsigned int _cilindrata = 0,
        unsigned int _cilindri = 0,
        unsigned int _litri_serbatoio = 0,
        alimentazione _carburante = benzina
    );

};

#endif // MOTO_H
