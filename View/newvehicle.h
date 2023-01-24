#ifndef NEWVEHICLE_H
#define NEWVEHICLE_H
#include <QPushButton>
#include "view.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QCloseEvent>
#include <QFormLayout>
#include <QComboBox>
#include <Model/garage.h>
#include <Model/veicolo.h>

class newvehicle:public view{
    Q_OBJECT
private:
        veicolo* v;
        veicolo* nuovo;
        automobile* nuovoa;
        moto* nuovom;
        auto_elettrica* nuovoe;
        monopattino_elettrico* nuovomon;
        auto_ibrida* nuovoai;
        moto_elettrica* nuovome;
        garage* g;
       // motore_combustione* ptr;
        QPushButton* save;
        QPushButton* clear;
        QPushButton* confermaDati;
        QLineEdit* marca;
        QLineEdit* modello;
        QLineEdit* targa;
        QLineEdit* km;
        QLineEdit* cilindrata;
        QLineEdit* manutenzione_bool;
        QLineEdit* costo_manutenzione;
        QLineEdit* kw;
        QLineEdit* ricaricare_bool;
        QLineEdit* costo_ricarica;
        QLineEdit* litri_carburante;
        QLineEdit* carburante;
        QFormLayout* layout;
        QComboBox* tipoAlimentazione;
        QComboBox* tipoVeicolo;
        QLayout* configureFinalLayout();
        QFormLayout* configureEditor();
        QHBoxLayout* configureButtons();
        QFormLayout* addMoreOptions();
        void deleteOptions();
        void connectViewSignals() const override;
protected:
    void close(QCloseEvent* event);
public:
    explicit newvehicle(garage* gar,const QSize& s = QSize(), view* parent = nullptr);
    virtual ~newvehicle() = default;

    void chechIfDataIsModified();

signals:
    void saveSignal(veicolo* veic);

    //void saveSignal();
    void clearSignal();
    void selectedTypeVehicle();
public slots:
    void checkSignal();
    void createOptions(int);



};

#endif // NEWVEHICLE_H
