#include "dialogviaggio.h"

/*void DialogViaggio::connectViewSignals() const
{
    connect(buttonbox, &QDialogButtonBox::clicked, (bind(&DialogViaggio::tryAddViaggio, this, vec, c)));
}

DialogViaggio::DialogViaggio(veicolo *veic, CostiViaggio* costi, const QSize &s, view *parent) : view(s, parent)
{
    vec = veic;
    c = costi;

    layout = new QFormLayout(this);
    layout->addRow(new QLabel("Inserimento Viaggio"));

    QLineEdit* veicolo = new QLineEdit(this);
    QLineEdit* partenza = new QLineEdit(this);
    QLineEdit* arrivo = new QLineEdit(this);
    QLineEdit* percorsi = new QLineEdit(this);
    QLineEdit* efficienza = new QLineEdit(this);
    QLineEdit* costoCarburante = new QLineEdit(this);
    QLineEdit* costoElettricita = new QLineEdit(this);

    layout->addRow("Veicolo Utilizzato: ", veicolo);
    layout->addRow("Città di Partenza: ", partenza);
    layout->addRow("Città di Arrivo: ", arrivo);
    layout->addRow("Chilometri Percorsi: ", percorsi);
    layout->addRow("Efficienza del Veicolo: ", efficienza);
    layout->addRow("Costo Carburante", costoCarburante);
    layout->addRow("Costo Elettricità", costoElettricita);

    buttonbox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, this);
    buttonbox->centerButtons();
    layout->addRow(buttonbox);

     connectViewSignals();
    //da inserire il segnale di pulizia
}
*/
