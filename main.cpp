#include <QApplication>
#include <iostream>
#include "Model/auto_elettrica.h"
#include "Model/automobile.h"
#include "Model/motore_combustione.h"
#include "Model/motore_elettrico.h"
#include "Model/CostiViaggio.h"
#include "Model/garage_combustione.h"
#include "Model/garage_elettrico.h"
using std::cout;
using std::endl;
#include <QMainWindow>
#include <QDebug>
#include "Model/garage.h"
int main(int argc, char* argv[]){
    /*QApplication app(argc, argv);
    QMainWindow w;
    w.show();
     return app.exec();
     */
    //cout<< "Garage con veicoli a combustione"<<endl;
    automobile a1("Mercedes","A45", "AA222BB",1000, 2000, 55, diesel, 1,100);
    automobile a2("Audi","Golf 7", "CC111BB",20000, 3200, 90, benzina, 0,1000);
    automobile a3("VW","Golf 7", "CC222BS",300000, 3200, 90,  benzina, 1,200);
    auto_ibrida ai("BMW","e-UP", "XX111ZZ",25000, 2000, 90, benzina, 1,50,1000,1,50);
    auto_ibrida ai2("FIAT","e-UP", "SZ999AP",25000, 2000, 90, benzina, 1,50,1000,1,50);
    auto_elettrica ae("Tesla","Model Y", "CC222BZ",12000,300,1,100);
    moto_elettrica me("Ducati","e-Panigale", 1800,32, 1, 150, "AS957AZ");

    garage g;
       g.addVeicolo(&ai2);
       g.addVeicolo(&a1);
       g.addVeicolo(&a2);
       g.addVeicolo(&a3);
       g.addVeicolo(&ai);
       g.addVeicolo(&ae);
       g.addVeicolo(&me);

       g.printGarage();

       cout << g.getCostoGarage()<<endl;
       cout<<"------------------"<<endl;
       cout<<"eliminazione"<<endl;
       g.deleteVeicolo(&me);
       g.deleteVeicolo(&ae);
       g.printGarage();
       cout<<g.getCostoGarage()<<endl;
       cout<<"----------"<<endl;
        //g.orderGarage();

        g.editVeicolo(&a1, "Ausi", "a4","CCCCCCC");
        g.printGarage();
        cout<<g.getCostoGarage()<<endl;
        cout<<"----------"<<endl;

        g.deleteVeicolo(&a3);
        g.printGarage();
        cout<<g.getCostoGarage()<<endl;
        cout<<"----------------------------------------------------"<<endl;
        cout<<"costi viaggio"<<endl;
        CostiViaggio c;
        c.addViaggio(&a1,"padova", "bologna", 400,6,1.60,0.0);
        c.addViaggio(&a1,"padova", "bologna", 120,10,1.60,0.0);
        c.addViaggio(&a2,"milano", "genova",1200,32,0,0.25);
        c.addViaggio(&a2,"milano", "genova",10000,10,2,0.0);
        c.addViaggio(&a3,"milano", "genova",1,32,0,0.0);
        c.addViaggio(&a3,"milano", "genova",212,32,0,0.25);

        c.addViaggio(&ae,"milano", "genova",200,32,0,0.25);
        c.addViaggio(&ae,"milano", "genova",200,32,0,0.25);
        c.addViaggio(&me,"milano", "genova",200,32,0,0.25);
        c.addViaggio(&me,"milano", "genova",80,32,0,0.25);

        double costo = c.getCostiVeicolo(&a1);

        int a = c.getMaxDistanza();
        cout<<a<<endl;
        int aa1 = c.getMinDistanza();
        cout<<aa1<<endl;
        int aa2 = c.getMediaDistanza();
        cout<<aa2<<endl;

        double aa = c.getCostoMax();
        cout<<aa<<endl;
        double aaa1 = c.getCostoMin();
        cout<<aaa1<<endl;
        double aaa2 = c.getCostoMedio();
        cout<<aaa2<<endl;

        double comb = c.getCostiCombustione();
        cout<< comb<<endl;

        double elett = c.getCostiElettrico();
        cout <<elett <<endl;



    return 0;




}
