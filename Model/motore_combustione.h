#ifndef MOTORE_COMBUSTIONE_H
#define MOTORE_COMBUSTIONE_H
#include "veicolo.h"
using std::string;

enum alimentazione{
    benzina = 0, diesel = 1, metano = 2, gpl = 3, biodisel = 4, idrogeno = 5
};

class motore_combustione:virtual public veicolo{
protected:
    unsigned int cilindrata;
    unsigned int litri_serbatoio;
    alimentazione carburante;
    bool manutenzione;
    unsigned int costo_manutenzione;

public:
    // Costruttore e Distruttore
    motore_combustione(
        string _marca = "",
        string _modello = "",
        string _targa = "AA000BB",
        int _km_odometro = 0,
        unsigned int _cilindrata = 0,
        unsigned int _litri_serbatoio = 0,
        alimentazione _carburante = benzina,
        bool _manutenzione = 0,
        unsigned int _costo_manutenzione = 0
    );

    virtual ~motore_combustione();

    // Getter e Setter
    unsigned int getCilindrata() const;
    void setCilindrata(unsigned int newCilindrata);
    unsigned int getLitri_serbatoio() const;
    void setLitri_serbatoio(unsigned int newLitri_serbatoio);
    char getAlimentazione() const;
    void setAlimentazione(alimentazione newAlimentazione);
    bool getManutenzione() const;
    void setManutenzione(bool newManutenzione);
    unsigned int getCosto_manutenzione() const;
    void setCosto_manutenzione(unsigned int newCosto_manutenzione);

};

#endif // MOTORE_COMBUSTIONE_H
