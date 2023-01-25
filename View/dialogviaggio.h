
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
    QDialogButtonBox* buttonbox;
    QPushButton * aggiungi;
    QPushButton * reset;
    QPushButton * annulla;

    veicolo* vec;
    CostiViaggio* c;

    void configureEditor(veicolo* veic);

    void connectViewSignals() const;

public:
    DialogViaggio(veicolo* veic, CostiViaggio* costi, const QSize& s = QSize(), view* parent = nullptr);

signals:
    void tryAddViaggio();

public slots:
};

#endif // DIALOGVIAGGIO_H

