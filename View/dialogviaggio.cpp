#include "dialogviaggio.h"

DialogViaggio::DialogViaggio(veicolo *veic)
{
    minimumSize();
    setVisible(true);
    QString s = "Chilometri in Partenza: " + QString::fromStdString(std::to_string(veic->getKm_odometro())) + "\nChilometri all'Arrivo: ";
    setLabelText(s);



}
