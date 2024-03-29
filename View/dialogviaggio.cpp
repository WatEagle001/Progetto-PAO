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

void DialogViaggio::connectViewSignals() const
{
    // Connessioni Effettuate Manualmente per Insorgenza Errori
}


DialogViaggio::DialogViaggio(veicolo *veic, CostiViaggio* costi, const QSize &s, view *parent) : view(s, parent)
{
    vec = veic;
    c = costi;


    layout = new QFormLayout(this);
    layout->addRow(new QLabel("Inserimento Viaggio"));
    veicol = new QLineEdit(QString::fromStdString(veic->getTarga()), this);
    veicol->setReadOnly(true);
    partenza = new QLineEdit(this);
    partenza->setValidator(new QRegularExpressionValidator(QRegularExpression("[A-Z]*[a-z]*[A-Z]*"), this));
    km_partenza = new QLineEdit(QString::number(veic->getKm_odometro()),this);
    km_partenza->setReadOnly(true);
    arrivo = new QLineEdit(this);
    arrivo->setValidator(new QRegularExpressionValidator(QRegularExpression("[A-Z]*[a-z]*[A-Z]*"), this));
    km_arrivo = new QLineEdit(this);
    km_arrivo->setValidator(new QIntValidator(km_partenza->text().toInt(), INT_MAX, this));
    efficienza = new QLineEdit(this);


    layout->addRow("Veicolo Utilizzato: ", veicol);
    layout->addRow("Città di Partenza: ", partenza);
    layout->addRow("Km alla Partenza: ", km_partenza);
    layout->addRow("Città di Arrivo: ", arrivo);
    layout->addRow("Chilometri all'Arrivo:", km_arrivo);
    layout->addRow("Efficienza del Veicolo: ", efficienza);

    configureEditor(veic);


    conferma = new QPushButton("Conferma Dati", this);
    aggiungi = new QPushButton("Inserisci",this);

    QHBoxLayout* buttons = new QHBoxLayout;
    buttons->addWidget(aggiungi);
    buttons->addWidget(conferma);

    layout->addItem(buttons);
    connect(conferma,SIGNAL(clicked()), this, SLOT(checkifdataismodified()));
}

void DialogViaggio::checkifdataismodified()
{
    if(partenza->isModified() == true || km_partenza->isModified() == true || arrivo -> isModified() == true ||
            km_arrivo->isModified() == true|| costoCarburante->isModified() == true || costoElettricita->isModified() == true ){
        int km = (km_arrivo->text().toInt()) - (km_partenza->text().toInt());
        if(km  < 0){
            km = 0;
        }
        connect(aggiungi, &QPushButton::clicked, (bind(
                                                      &DialogViaggio::tryAddViaggio,
                                                      this,
                                                      vec,
                                                      partenza->text().toStdString(),
                                                      arrivo->text().toStdString(),
                                                      km,
                                                      efficienza->text().toDouble(),
                                                      costoCarburante->text().toDouble(),
                                                      costoElettricita->text().toDouble()
                                                      )
                                                  )
                );
    }
}

void DialogViaggio::closeEvent(QCloseEvent *event)
{
    //Elaboro chiusura solo se intenzionata da evento esterno
    if(!event->spontaneous()) return;

    if(!dialogPopUp_Question(2, "Annullamento", "Sei sicuro di voler annullare l'operazione?\n")){
        event->ignore();
    }
    else {
        //Accetto l'evento di chiusura della finestra
        event->accept();
        //Emetto segnale di chiusura della View
        emit viewClosed();
    }
}

