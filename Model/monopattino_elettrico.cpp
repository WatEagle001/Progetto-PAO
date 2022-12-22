#include "monopattino_elettrico.h"

monopattino_elettrico::monopattino_elettrico(
        std::string _marca,
        std::string _modello,
        string _targa,
        int _km_odometro,
        unsigned int _kw_batteria,
        bool _ricaricare,
        double _costo_ricarica):
    veicolo(_marca,_modello,_targa,_km_odometro), motore_elettrico(_marca,_modello,_km_odometro,_kw_batteria,_ricaricare, _costo_ricarica,_targa){}

monopattino_elettrico::~monopattino_elettrico()
{

}
