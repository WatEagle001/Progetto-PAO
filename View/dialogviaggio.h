#ifndef DIALOGVIAGGIO_H
#define DIALOGVIAGGIO_H

#include <QInputDialog>
#include <QFormLayout>
#include <QLabel>
#include <QDialogButtonBox>

#include "Model/veicolo.h"

class DialogViaggio : public view
{

    Q_OBJECT

private:
    QFormLayout* layout;
    QList<QLineEdit*>* campidati;
    QDialogButtonBox* buttonbox;

    void connectViewSignals() const;

public:
    DialogViaggio(veicolo* veic, const QSize& s = QSize(), view* parent = nullptr);

signals:
    void tryAddViaggio();
};

#endif // DIALOGVIAGGIO_H
