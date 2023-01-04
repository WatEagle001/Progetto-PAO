#ifndef MONOPATTINO_ELETTRICO_H
#define MONOPATTINO_ELETTRICO_H
#include <string>
using std::string;
#include "Model/motore_elettrico.h"

class monopattino_elettrico: public motore_elettrico{

public:
    monopattino_elettrico(
            string _marca = "",
            string _modello = "",
            string _targa = "AA000BB",
            int _km_odometro =0,
            unsigned int _kw_batteria = 0,
            bool _ricaricare = 0,
            double _costo_ricarica = 0
            );
    virtual ~monopattino_elettrico();
};

#endif // MONOPATTINO_ELETTRICO_H
