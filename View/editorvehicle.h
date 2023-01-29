#ifndef EDITORVEHICLE_H
#define EDITORVEHICLE_H

#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QCloseEvent>
#include <QFormLayout>
#include <QComboBox>
#include <QItemEditorFactory>
#include <QString>
#include <QLineEdit>
#include <QComboBox>
#include <QFormLayout>

#include "View/view.h"
#include "Model/garage.h"
#include "Model/veicolo.h"
#include <Model/automobile.h>


using std::bind;

class editorvehicle:public view{
    Q_OBJECT
private:
    veicolo* v;
    veicolo* nuovo;
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
    QLayout* configureFinalLayout();
    QFormLayout* configureEditor();
    QHBoxLayout* configureButtons();
    QFormLayout* addMoreOptions();
    void deleteOptions();
    void connectViewSignals() const override;
protected:
    void closeEvent(QCloseEvent* event) override;
public:
    explicit editorvehicle(garage* gar,veicolo* veic,const QSize& s = QSize(), view* parent = nullptr);
    virtual ~editorvehicle() = default;

    void checkIfDataIsModified();
signals:
    void saveSignal(veicolo* veic,veicolo* nuovo);
    void selectedTypeVehicle();
public slots:
    void checkSignal();
    void clearSlot();

};

#endif // EDITORVEHICLE_H
