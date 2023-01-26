#include "dialogviaggio.h"

void DialogViaggio::configureEditor(veicolo *veic)
{
    motore_elettrico* e = dynamic_cast<motore_elettrico*>(veic);
    motore_combustione* c = dynamic_cast<motore_combustione*>(veic);


    if(e){

        costoCarburante = new QLineEdit(0,this);
        costoCarburante->setValidator(new QDoubleValidator(0,10, 3, this));
        costoCarburante->setHidden(true);

        costoElettricita = new QLineEdit(this);
        costoElettricita->setValidator(new QDoubleValidator(0,10, 3, this));
        layout->addRow("Costo Elettricità", costoElettricita);
    }

    if(c){

        costoElettricita = new QLineEdit(0,this);
        costoElettricita->setValidator(new QDoubleValidator(0,10, 3, this));
        costoElettricita->setHidden(true);

        costoCarburante = new QLineEdit(this);
        costoCarburante->setValidator(new QDoubleValidator(0,10, 3, this));
        layout->addRow("Costo Carburante", costoCarburante);

    }

    if(c && e) {
        costoCarburante = new QLineEdit(this);
        costoCarburante->setValidator(new QDoubleValidator(0,10, 3, this));
        layout->addRow("Costo Carburante", costoCarburante);

        costoElettricita = new QLineEdit(this);
        costoElettricita->setValidator(new QDoubleValidator(0,10, 3, this));
        layout->addRow("Costo Elettricità", costoElettricita);
    }
    if(!e && !c){
        dialogPopUp_Warning("Errore", "Impossibile definire il tipo del veicolo selezionato");
    }


}


DialogViaggio::DialogViaggio(veicolo *veic, CostiViaggio* costi, const QSize &s, view *parent) : view(s, parent)
{
    qDebug() << "Assegnazione per Iniezione\n";
    vec = veic;
    c = costi;

    qDebug() << "Aggiunta delle Componenti\n";
    layout = new QFormLayout(this);
    qDebug() << "Creato nuovo layout\n";
    layout->addRow(new QLabel("Inserimento Viaggio"));
    qDebug() << "Aggiunta della Prima riga\n";

    qDebug() << "Inizio Lettura Veicolo e Creazione Input\n";
    veicol = new QLineEdit(QString::fromStdString(veic->getTarga()), this);
    qDebug() << "Letta la Targa\n";
    veicol->setReadOnly(true);
    partenza = new QLineEdit(this);
    partenza->setValidator(new QRegularExpressionValidator(QRegularExpression("[A-Z]*[a-z]*[A-Z]*"), this));
    km_partenza = new QLineEdit(QString::number(veic->getKm_odometro()),this);
    km_partenza->setReadOnly(true);
    arrivo = new QLineEdit(this);
    arrivo->setValidator(new QRegularExpressionValidator(QRegularExpression("[A-Z]*[a-z]*[A-Z]*"), this));
    km_arrivo = new QLineEdit(this);
    km_arrivo->setValidator(new QIntValidator(0, INT_MAX, this));
    efficienza = new QLineEdit(this);


    layout->addRow("Veicolo Utilizzato: ", veicol);
    layout->addRow("Città di Partenza: ", partenza);
    layout->addRow("Km alla Partenza: ", km_partenza);
    layout->addRow("Città di Arrivo: ", arrivo);
    layout->addRow("Chilometri all'Arrivo:", km_arrivo);
    layout->addRow("Efficienza del Veicolo: ", efficienza);

    configureEditor(veic);


    aggiungi = new QPushButton("Inserisci",this);
   reset = new QPushButton("Pulisci",this);
    annulla = new QPushButton("Esci Senza Salvare",this);

    QHBoxLayout* buttons = new QHBoxLayout;
    buttons->addWidget(aggiungi);
    buttons->addWidget(reset);
    buttons->addWidget(annulla);
    layout->addItem(buttons);

   // buttonbox->addButton(aggiungi, QDialogButtonBox::AcceptRole);
   // buttonbox->addButton(reset, QDialogButtonBox::ResetRole);
   // buttonbox->addButton(annulla, QDialogButtonBox::DestructiveRole);
    //qDebug() << "Aggiunti bottoni alla buttonbox";
   // layout->addWidget(buttonbox);
    //qDebug() << "Aggiunto buttonbox al layout";

    //connectViewSignals();
    connect(aggiungi, &QPushButton::clicked, (bind(
                                                      &DialogViaggio::tryAddViaggio,
                                                      this,
                                                      veic,
                                                      partenza->text().toStdString(),
                                                      arrivo->text().toStdString(),
                                                      ((km_arrivo->text().toInt()) - (km_partenza->text().toInt())),
                                                      efficienza->text().toDouble(),
                                                      costoCarburante->text().toDouble(),
                                                      costoElettricita->text().toDouble()
                                                      )
                                                  )
            );



}

void DialogViaggio::connectViewSignals() const
{


}

