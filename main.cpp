#include <QApplication>
#include <iostream>
#include "Model/auto_elettrica.h"
#include "Model/automobile.h"
#include "Model/motore_combustione.h"
#include "Model/motore_elettrico.h"
using std::cout;
using std::endl;
#include <QMainWindow>

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    QMainWindow w;
    w.show();
     return app.exec();


    motore_combustione carbone("BMW", "serie 3", "germania","ciao", 100,2000, 1000,280);
    motore_elettrico carbone2("Tesla", "model 3", "USA","ciao2", 150,2500, 300,800, 350);

    cout<<carbone.getMarca()<< " "<< carbone.getModello() << " " <<carbone.getPaese() << " "<<carbone.getDescrizione()<< " "<< carbone.getRapp_peso_pot() << " "<<
          carbone.getPeso() << " "<< carbone.getCavalli() <<  " "<< carbone.getNm() << endl;

    cout<<carbone2.getMarca()<< " "<< carbone2.getModello() << " " <<carbone2.getPaese() << " "<<carbone2.getDescrizione()<< " "<< carbone2.getRapp_peso_pot() << " "<<
          carbone2.getPeso() << " "<< carbone2.getCavalli() <<  " "<< carbone2.getNm()<<endl;

    carbone2.setCavalli(10000);
    cout<<carbone2.getMarca()<< " "<< carbone2.getModello() << " " <<carbone2.getPaese() << " "<<carbone2.getDescrizione()<< " "<< carbone2.getRapp_peso_pot() << " "<<
          carbone2.getPeso() << " "<< carbone2.getCavalli() <<  " "<< carbone2.getNm() <<endl;

    automobile a("a","b","c", "d", 100,190, 1200, 230);
    cout<<a.getMarca()<< " "<< a.getModello() << " " <<a.getPaese() << " "<<a.getDescrizione()<< " "<< a.getRapp_peso_pot() << " "<<
              a.getPeso() << " "<< a.getCavalli() <<  " "<< a.getNm()<<endl;

    a.setCavalli(200);

    cout<<a.getMarca()<< " "<< a.getModello() << " " <<a.getPaese() << " "<<a.getDescrizione()<< " "<< a.getRapp_peso_pot() << " "<<
              a.getPeso() << " "<< a.getCavalli() <<  " "<< a.getNm()<<endl;
    auto_elettrica e("w","x","y", "z", 100,190, 1200, 230);
    cout<<e.getMarca()<< " "<< e.getModello() << " " <<e.getPaese() << " "<<e.getDescrizione()<< " "<< e.getRapp_peso_pot() << " "<<
              e.getPeso() << " "<< e.getCavalli() <<  " "<< e.getNm()<<endl;

    e.setCavalli(20000);
    cout<<e.getMarca()<< " "<< e.getModello() << " " <<e.getPaese() << " "<<e.getDescrizione()<< " "<< e.getRapp_peso_pot() << " "<<
              e.getPeso() << " "<< e.getCavalli() <<  " "<< e.getNm()<<endl;
}