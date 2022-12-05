#ifndef VEICOLO_H
#define VEICOLO_H
#include <string>
using std::string;

class veicolo{
private:
   string marca;
   string modello;
   string paese;
   string descrizione;
   double rapp_peso_pot;
   unsigned int cavalli;
   unsigned int peso;
   unsigned int nm;
public:
   string getMarca() const;
   void setMarca(const string &newMarca);
   string getModello() const;
   void setModello(const string &newModello);
   string getPaese() const;
   void setPaese(const string &newPaese);
   string getDescrizione() const;
   void setDescrizione(const string &newDescrizione);
   double getRapp_peso_pot() const;
   void setRapp_peso_pot(double newRapp_peso_pot);
   unsigned int getCavalli() const;
   void setCavalli(unsigned int newCavalli);
   unsigned int getPeso() const;
   void setPeso(unsigned int newPeso);
   unsigned int getNm() const;
   void setNm(unsigned int newNm);


   virtual ~veicolo();
   veicolo(string _marca = "", string _modello = "", string _paese = "", string _descrizione = "", double _rapp_peso_pot = 0, unsigned int _cavalli = 0, unsigned int _peso = 0, unsigned int _nm = 0);


};





#endif // VEICOLO_H
