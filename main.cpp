#include <QApplication>
#include <iostream>
#include "View/welcome.h"
#include "Controller/welcomecontroller.h"

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    welcome* w = new welcome(QSize(500,500));
    welcomeController* c = new welcomeController(w);
    c->show();

    return app.exec();
}
