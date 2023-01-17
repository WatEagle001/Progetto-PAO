#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H
#include "motore_combustione.h"
#include <string>
using std::string;


class automobile: public motore_combustione{
public:
automobile(
    string _marca,
    string _modello,
    string _targa = "AA000BB",
    int _km_odometro = 0,
    unsigned int _cilindrata = 0,
    unsigned int _litri_serbatoio =  0,
    alimentazione _carburante = benzina,
    bool _manutenzione = 0,
    unsigned int _costo_manutenzione = 0
    );

    virtual ~automobile();

};

#endif // AUTOMOBILE_H
