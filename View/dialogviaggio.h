#ifndef DIALOGVIAGGIO_H
#define DIALOGVIAGGIO_H

#include <QInputDialog>

#include "Model/veicolo.h"

class DialogViaggio : public QInputDialog
{
public:
    DialogViaggio(veicolo* veic);
};

#endif // DIALOGVIAGGIO_H
