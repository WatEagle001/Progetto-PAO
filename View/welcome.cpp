#include "welcome.h"

QLayout *welcome::configureFinalLayout(){
    // Creazione Layout
    QBoxLayout* mainLayout = new QVBoxLayout();

    // Aggiunta dei Vari Componenti al Layout
    mainLayout->addLayout(configureDescription());
    mainLayout->addLayout(configureButtons());
    return mainLayout;
}

QVBoxLayout *welcome::configureDescription()
{
    QVBoxLayout* desc = new QVBoxLayout();
    // Creazione Descrizione
    QLabel* description = new QLabel("Applicazione per la gestione di una flotta aziendale, ideata per il progetto di Programmazione ad Oggetti dell'Università di Padova, A.A. 2022-2023", this);
    description->setWordWrap(true);
    description->setAlignment(Qt::AlignCenter);
    // Descrizione Autori
    QLabel* authors = new QLabel(tr("Soldà Matteo - 1226319\nVeronese Andrea - 1225411"));
    authors->setAlignment(Qt::AlignCenter);
    // Creazione Immagine di Benvenuto con Logo (Senza Perdita di Qualità)
    QImage Qimg(":Assets/image/logos/QFleetLogo.png");
    QPixmap image;
    QLabel* logo = new QLabel;
    image = image.fromImage(Qimg.scaled(397, 221, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));    //Conversione da Image a Pixmap senza perdita di qualità
    logo->setPixmap(image);
    logo->setAlignment(Qt::AlignCenter);
    // Aggiunta dei Componenti al Layout
    desc->addWidget(logo);
    desc->addWidget(description);
    desc->addWidget(authors);
    return desc;
}
QHBoxLayout *welcome::configureButtons()
{
    QHBoxLayout* buttons = new QHBoxLayout();
    // Creazione Pulsanti
    createGarage = new QPushButton("Crea Nuovo Garage", this);
    createGarage->setFixedSize(150, 70);
    openGarage = new QPushButton("Apri Garage Esistente", this);
    openGarage->setFixedSize(150, 70);
    // Aggiunta dei Bottoni al Layout Secondario
    buttons->addWidget(createGarage);
    buttons->addWidget(openGarage);
    return buttons;
}
void welcome::connectViewSignals() const
{
    connect(createGarage, SIGNAL(clicked()), this, SIGNAL(newGarage()));
    connect(openGarage, SIGNAL(clicked()), this, SIGNAL(readGarage()));
}
void welcome::closeEvent(QCloseEvent *event)
{
    //Elaboro chiusura solo se intenzionata da evento esterno
    if(!event->spontaneous()) return;

    if(!dialogPopUp_Question(2, "Uscita", "Sei sicuro di voler chiudere l'applicazione?\n")){
        event->ignore();
    }
    else {
        //Accetto l'evento di chiusura della finestra
        event->accept();
        //Emetto segnale di chiusura della View
        emit viewClosed();
    }
}

welcome::welcome(const QSize &s, view *parent) : view(s, parent)
{
    QBoxLayout* main = new QVBoxLayout;
    main->addLayout(configureFinalLayout());

    setLayout(main);
    setFixedSize(s);
    welcome::connectViewSignals();
    setTitle("QFleet Home");
}
