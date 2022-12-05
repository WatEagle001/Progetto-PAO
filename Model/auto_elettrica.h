#ifndef AUTO_ELETTRICA_H
#define AUTO_ELETTRICA_H
#include "motore_elettrico.h"

class auto_elettrica: public motore_elettrico{
public:
    auto_elettrica(
        string _marca = "",
        string _modello = "",
        string _paese = "",
        string _descrizione = "",
        double _rapp_peso_pot = 0,
        unsigned int _cavalli = 0,
        unsigned int _peso = 0,
        unsigned int _nm = 0,
        unsigned int _cv_fiscali = 0,
        unsigned int _kw_batteria = 0
    );


    ~auto_elettrica();
};

#endif // AUTO_ELETTRICA_H
