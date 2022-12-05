#ifndef MOTORE_ELETTRICO_H
#define MOTORE_ELETTRICO_H
#include "veicolo.h"

class motore_elettrico: virtual public veicolo{
protected:

    unsigned int cv_fiscali;
    unsigned int kw_batteria;
public:
    unsigned int getCv_fiscali() const;
    void setCv_fiscali(unsigned int newCv_fiscali);
    unsigned int getKw_batteria() const;
    void setKw_batteria(unsigned int newKw_batteria);

    motore_elettrico(std::string _marca, std::string _modello, std::string _paese, std::string _descrizione, double _rapp_peso_pot, unsigned int _cavalli, unsigned int _peso, unsigned int _nm, unsigned int _cv_fiscali, unsigned int _kw_batteria);
    virtual ~motore_elettrico();
};

#endif // MOTORE_ELETTRICO_H
