
#ifndef DIALOGVIAGGIO_H
#define DIALOGVIAGGIO_H

#include <QInputDialog>
#include <QFormLayout>
#include <QLabel>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QValidator>
#include <QRegularExpressionValidator>

#include "Model/veicolo.h"
#include "Model/CostiViaggio.h"

using std::bind;

class DialogViaggio : public view
{

    Q_OBJECT

private:
    QFormLayout* layout;
    QList<QLineEdit*>* campidati;
    QPushButton * aggiungi;
    QPushButton * reset;
    QPushButton * annulla;
    QPushButton * conferma;
    QDialogButtonBox * buttonbox;

    QLineEdit* veicol;
    QLineEdit* partenza;
    QLineEdit* km_partenza;
    QLineEdit* arrivo;
    QLineEdit* km_arrivo;
    QLineEdit* efficienza;
    QLineEdit* costoCarburante;
    QLineEdit* costoElettricita;

    veicolo* vec;
    CostiViaggio* c;

    void configureEditor(veicolo* veic);

    void connectViewSignals() const;

public:
    DialogViaggio(veicolo* veic, CostiViaggio* costi, const QSize& s = QSize(), view* parent = nullptr);

signals:
    void tryAddViaggio(veicolo* veic, string partenza, string arrivo, int km_percorsi, double efficienza, double costo_carburante, double costo_elettricita);

public slots:
    void checkifdataismodified();
};

#endif // DIALOGVIAGGIO_H

