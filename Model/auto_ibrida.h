#ifndef AUTO_IBRIDA_H
#define AUTO_IBRIDA_H
#include "motore_combustione.h"
#include "motore_elettrico.h"
#include <string>
using std::string;


class auto_ibrida: public motore_combustione, public motore_elettrico{
public:
    auto_ibrida(
        string _marca,
        string _modello,
        string _targa = "AA000BB",
        int _km_odometro = 0,
        unsigned int _cilindrata = 0,
        unsigned int _litri_serbatoio =  0,
        alimentazione _carburante = benzina,
        unsigned int _kw_batteria = 0,
        bool _manutenzione = 0,
        unsigned int _costo_manutenzione = 0,
        bool _ricaricare = 0,
        double _costo_ricarica = 0
       );

};

#endif // AUTO_IBRIDA_H
