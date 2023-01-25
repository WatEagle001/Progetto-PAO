#include "dialogviaggio.h"

void DialogViaggio::configureEditor(veicolo *veic)
{
    motore_elettrico* e = dynamic_cast<motore_elettrico*>(veic);
    motore_combustione* c = dynamic_cast<motore_combustione*>(veic);


    if(e){
        QLineEdit* costoElettricita = new QLineEdit(this);
        costoElettricita->setValidator(new QDoubleValidator(0,10, 3, this));
        layout->addRow("Costo Elettricità", costoElettricita);
    }

    if(c){
        QLineEdit* costoCarburante = new QLineEdit(this);
        costoCarburante->setValidator(new QDoubleValidator(0,10, 3, this));
        layout->addRow("Costo Carburante", costoCarburante);

    }

    if(!e && !c){
        dialogPopUp_Warning("Errore", "Impossibile definire il tipo del veicolo selezionato");
    }


}

void DialogViaggio::connectViewSignals() const
{
    connect(buttonbox, SIGNAL(accepted()), this, SIGNAL(tryAddViaggio()));
    connect(buttonbox, SIGNAL(rejected()), this, SIGNAL(viewClosed()));
}

DialogViaggio::DialogViaggio(veicolo *veic, CostiViaggio* costi, const QSize &s, view *parent) : view(s, parent)
{
    vec = veic;
    c = costi;

    layout = new QFormLayout(this);
    layout->addRow(new QLabel("Inserimento Viaggio"));

    QLineEdit* veicolo = new QLineEdit(QString::fromStdString(veic->getTarga()), this);
    veicolo->setReadOnly(true);
    QLineEdit* partenza = new QLineEdit(this);
    partenza->setValidator(new QRegularExpressionValidator(QRegularExpression("*[A-Z]*[a-z]*[A-Z]*"), this));
    QLineEdit* km_partenza = new QLineEdit(QString::number(veic->getKm_odometro()),this);
    km_partenza->setReadOnly(true);
    QLineEdit* arrivo = new QLineEdit(this);
    arrivo->setValidator(new QRegularExpressionValidator(QRegularExpression("*[A-Z]*[a-z]*[A-Z]*"), this));
    QLineEdit* km_arrivo = new QLineEdit(this);
    km_arrivo->setValidator(new QIntValidator(0, INT_MAX, this));
    QLineEdit* efficienza = new QLineEdit(this);


    layout->addRow("Veicolo Utilizzato: ", veicolo);
    layout->addRow("Città di Partenza: ", partenza);
    layout->addRow("Km alla Partenza: ", km_partenza);
    layout->addRow("Città di Arrivo: ", arrivo);
    layout->addRow("Chilometri all'Arrivo:", km_arrivo);
    layout->addRow("Efficienza del Veicolo: ", efficienza);

    configureEditor(vec);

    buttonbox = new QDialogButtonBox( QDialogButtonBox::Ok | QDialogButtonBox::Abort, Qt::Horizontal, this);

    layout->addRow(buttonbox);

    connectViewSignals();
}
