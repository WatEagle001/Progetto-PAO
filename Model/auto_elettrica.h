#ifndef AUTO_ELETTRICA_H
#define AUTO_ELETTRICA_H
#include "motore_elettrico.h"

class auto_elettrica: public motore_elettrico{
public:
    auto_elettrica(
        string _marca = "",
        string _modello = "",
        string _targa = "AA000BB",
        int _km_odometro = 0,
        unsigned int _kw_batteria = 0,
        bool _ricaricare = 0,
        double _costo_ricarica = 0

    );


    virtual ~auto_elettrica();
};

#endif // AUTO_ELETTRICA_H
