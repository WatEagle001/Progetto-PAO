#ifndef DIALOGVIAGGIO_H
#define DIALOGVIAGGIO_H

#include <QInputDialog>
#include <QFormLayout>
#include <QLabel>
#include <QDialogButtonBox>

#include "Model/veicolo.h"
#include "Model/CostiViaggio.h"

using std::bind;

class DialogViaggio : public view
{

   /* Q_OBJECT

private:
    QFormLayout* layout;
    QList<QLineEdit*>* campidati;
    QDialogButtonBox* buttonbox;

    veicolo* vec;
    CostiViaggio* c;

    void connectViewSignals() const;

public:
    DialogViaggio(veicolo* veic, CostiViaggio* costi, const QSize& s = QSize(), view* parent = nullptr);

signals:
    void tryAddViaggio(veicolo* veic, CostiViaggio* c);
    */
};

#endif // DIALOGVIAGGIO_H
