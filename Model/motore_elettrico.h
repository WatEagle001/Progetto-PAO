#ifndef MOTORE_ELETTRICO_H
#define MOTORE_ELETTRICO_H
#include "veicolo.h"

class motore_elettrico:virtual public veicolo{
protected:
    unsigned int kw_batteria;
    double costo_ricarica;
    bool ricaricare;
public:
    // Costruttore e Distruttore
    motore_elettrico(
        string _marca,
        string _modello,
        int _km_odometro,
        unsigned int _kw_batteria,
        bool _ricaricare,
        double _costo_ricarica,
        string _targa
    );
    virtual ~motore_elettrico();
    void setCavalli(unsigned int newCavalli);

    // Getter e Setter
    unsigned int getKw_batteria() const;
    void setKw_batteria(unsigned int newKw_batteria);
    bool getRicaricare() const;
    void setRicaricare(bool newRicaricare);
    double getCosto_ricarica() const;
    void setCosto_ricarica(double newCosto_ricarica);
};

#endif // MOTORE_ELETTRICO_H
