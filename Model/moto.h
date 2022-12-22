#ifndef MOTO_H
#define MOTO_H
#include "motore_combustione.h"
#include <string>
using std::string;

class moto: public motore_combustione{
public:
    moto(
        string _marca,
        string _modello,
        string _targa = "AA000BB",
        int _km_odometro = 0,
        unsigned int _cilindrata = 0,
        unsigned int _litri_serbatoio = 0,
        alimentazione _carburante = benzina,
        bool _manutenzione = 0,
        unsigned int _costo_manutenzione = 0
    );

};

#endif // MOTO_H
