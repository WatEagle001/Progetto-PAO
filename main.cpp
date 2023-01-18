#include <QApplication>
#include <iostream>
#include "View/welcome.h"
#include "Controller/welcomecontroller.h"
#include "Controller/vehiclelistcontroller.h"
#include "View/dialogviaggio.h"

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    welcome* w = new welcome(QSize(500,500));
    garage* g = new garage;
    //vehiclelist* l = new vehiclelist();
    automobile* a = new automobile("Fiat", "punto","AO111OA", 125000,1200,45,benzina,0,0);
    automobile* a1 = new automobile("Ferrari", "California", "AA111BB", 1000);
   automobile* a2 = new automobile("Opel", "Astra", "BB333ZZ", 12500);
    automobile* a3 = new automobile("Fiat", "126", "WW555PP", 30000);
    automobile* a4 = new automobile("Gino", "Pino", "1111111", 30000);
    automobile* a5 = new automobile("Pino", "a", "ZZ444PP", 30000);
    g->addVeicolo(a);
     g->addVeicolo(a1);
      g->addVeicolo(a2);
       g->addVeicolo(a3);
        g->addVeicolo(a4);
         g->addVeicolo(a5);
    welcomeController* c = new welcomeController(w,g);

    DialogViaggio* d = new DialogViaggio(a1);
    d->show();

    //vehiclelistcontroller* v = new vehiclelistcontroller(l,g);
    c->showView();
    return app.exec();
}
