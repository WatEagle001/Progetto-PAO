#ifndef MOTO_ELETTRICA_H
#define MOTO_ELETTRICA_H
#include "motore_elettrico.h"

class moto_elettrica:public motore_elettrico{
public:
    moto_elettrica(
        string _marca,
        string _modello,
        string _paese,
        string _descrizione,
        double _rapp_peso_pot,
        unsigned int _cavalli,
        unsigned int _peso,
        unsigned int _nm,
        unsigned int _kw_batteria
    );
};

#endif // MOTO_ELETTRICA_H
