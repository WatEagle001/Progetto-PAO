#ifndef DIALOGVIAGGIO_H
#define DIALOGVIAGGIO_H

#include <QInputDialog>
#include <QFormLayout>
#include <QLabel>
#include <QDialogButtonBox>

#include "Model/veicolo.h"

class DialogViaggio : public QDialog
{

    Q_OBJECT

private:
    QFormLayout* layout;
    QList<QLineEdit*>* campidati;

public:
    DialogViaggio(veicolo* veic);

signals:
    void tryAddViaggio();
};

#endif // DIALOGVIAGGIO_H
