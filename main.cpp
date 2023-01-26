#include <QApplication>
#include <iostream>
#include "View/welcome.h"
#include "Controller/welcomecontroller.h"
#include "Controller/vehiclelistcontroller.h"
#include "Model/CostiViaggio.h"
#include "View/dialogviaggio.h"

int main(int argc, char* argv[]){
    QApplication app(argc, argv);

    welcome* w = new welcome(QSize(500,500));
    garage* g = new garage;
    CostiViaggio* costi = new CostiViaggio;

    welcomeController* c = new welcomeController(w,g, costi);

    c->showView();
    return app.exec();
}
