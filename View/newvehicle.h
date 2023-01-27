#ifndef NEWVEHICLE_H
#define NEWVEHICLE_H
#include <QPushButton>
#include "view.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QCloseEvent>
#include <QFormLayout>
#include <QComboBox>
#include <Model/garage.h>
#include <Model/veicolo.h>

class newvehicle:public view{
    Q_OBJECT
private:
        veicolo* v;
        garage* g;
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
    void closeEvent(QCloseEvent* event) override;
public:
    explicit newvehicle(garage* gar,const QSize& s = QSize(), view* parent = nullptr);
    virtual ~newvehicle() = default;
    void checkIfDataIsModified();
    void addFieldsCombustione();
    void addFieldsElettrico();
    void firstSelection(int);
signals:
    void saveSignal(veicolo* veic);
    void clearSignal();
public slots:
    void checkSignal();
    void createOptions(int);
};

#endif // NEWVEHICLE_H
