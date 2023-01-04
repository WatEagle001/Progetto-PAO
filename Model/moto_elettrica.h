#ifndef MOTO_ELETTRICA_H
#define MOTO_ELETTRICA_H
#include "motore_elettrico.h"

class moto_elettrica:public motore_elettrico{
public:
    moto_elettrica(
        string _marca,
        string _modello,
        int _km_odometro = 0,
        unsigned int _kw_batteria = 0,
        bool _ricaricare = 0,
        double _costo_ricarica = 0,
        string _targa = "AA000BB"

    );
    virtual ~moto_elettrica();
};

#endif // MOTO_ELETTRICA_H
