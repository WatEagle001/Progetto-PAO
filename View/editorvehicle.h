#ifndef EDITORVEHICLE_H
#define EDITORVEHICLE_H
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

class editorvehicle:public view{
    Q_OBJECT
private:
        veicolo* v;
        veicolo* nuovo;
        QPushButton* save;
        QPushButton* clear;
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
        QLayout* configureFinalLayout();
        QFormLayout* configureEditor();
        QHBoxLayout* configureButtons();
        QFormLayout* addMoreOptions();
        void deleteOptions();
        void connectViewSignals() const override;
protected:
    void close(QCloseEvent* event);
public:
    explicit editorvehicle(veicolo* veic,const QSize& s = QSize(), view* parent = nullptr);
    virtual ~editorvehicle() = default;

signals:
    void saveSignal(veicolo* v);
    void clearSignal();
    void selectedTypeVehicle();

};

#endif // EDITORVEHICLE_H
