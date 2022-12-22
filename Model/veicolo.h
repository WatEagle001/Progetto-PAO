#ifndef VEICOLO_H
#define VEICOLO_H
#include <string>
using std::string;

class veicolo{
private:
   string marca;
   string modello;
   string targa;
   int km_odometro;
public:
   // Costruttore e Distruttore
   veicolo(
       string _marca = "",
       string _modello = "",
       string _targa = "AA000BB",
       int _km_odometro = 0
    );
    virtual ~veicolo();
   // Setter e Getter
   string getMarca() const;
   void setMarca(const string &newMarca);
   string getModello() const;
   void setModello(const string &newModello);
   string getTarga() const;
   void setTarga(const string &newTarga);
   int getKm_odometro() const;
   void setKm_odometro(int newKm_odometro);
};

#endif // VEICOLO_H
