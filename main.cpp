#include <QApplication>
#include <iostream>
#include "View/welcome.h"
#include "Controller/welcomecontroller.h"
#include "Controller/vehiclelistcontroller.h"

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    welcome* w = new welcome(QSize(500,500));
    garage* g = new garage;
    //vehiclelist* l = new vehiclelist();
    automobile* a = new automobile("Fiat", "punto","AO111OA", 125000,1200,45,benzina,0,0);
    g->addVeicolo(a);
    welcomeController* c = new welcomeController(w,g);
    //vehiclelistcontroller* v = new vehiclelistcontroller(l,g);
    c->showView();
    return app.exec();
}
