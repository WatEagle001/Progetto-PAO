#ifndef MOTORE_COMBUSTIONE_H
#define MOTORE_COMBUSTIONE_H
#include "veicolo.h"

enum alimentazione{
    benzina, diesel, metano, gpl, biodisel, idrogeno
};

class motore_combustione: virtual public veicolo{
private:
    unsigned int cilindrata;
    unsigned int cilindri;
    unsigned int litri_serbatoio;
    alimentazione carburante;

public:
    // Costruttore e Distruttore
    motore_combustione(
        std::string _marca,
        std::string _modello,
        std::string _paese,
        std::string _descrizione,
        double _rapp_peso_pot,
        unsigned int _cavalli,
        unsigned int _peso,
        unsigned int _nm,
        unsigned int _cilindrata = 0,
        unsigned int _cilindri = 0,
        unsigned int _litri_serbatoio = 0,
        alimentazione _carburante = benzina
    );

    virtual ~motore_combustione();
    void setCavalli(unsigned int newCavalli);

    // Getter e Setter
    unsigned int getCilindrata() const;
    void setCilindrata(unsigned int newCilindrata);
    unsigned int getCilindri() const;
    void setCilindri(unsigned int newCilindri);
    unsigned int getLitri_serbatoio() const;
    void setLitri_serbatoio(unsigned int newLitri_serbatoio);
    char getAlimentazione() const;
    void setAlimentazione(alimentazione newAlimentazione);
};

#endif // MOTORE_COMBUSTIONE_H