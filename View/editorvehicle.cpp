#include "editorvehicle.h"
#include <QItemEditorFactory>
#include <QString>
#include <iostream>
#include <QLineEdit>

QLayout* editorvehicle::configureFinalLayout(){
    // Creazione Layout
    QVBoxLayout* mainLayout = new QVBoxLayout();

    // Aggiunta dei Vari Componenti al Layout
    mainLayout->addLayout(configureEditor());
    mainLayout->addLayout(configureButtons());

    return mainLayout;
}

QVBoxLayout *editorvehicle::configureEditor()
{
    QVBoxLayout* edit = new QVBoxLayout;
    //QItemEditorFactory *factory = new QItemEditorFactory;

        /*QItemEditorCreatorBase *colorListCreator =
            new QStandardItemEditorCreator<ColorListEditor>();

        factory->registerEditor(QMetaType::QColor, colorListCreator);

        QItemEditorFactory::setDefaultFactory(factory);
        */
    //edit->addWidget(factory);
    QString test("Seleziona tipologia veicolo con cui convertire il mezzo selezionato");
    QLineEdit* test1 = new QLineEdit;
    edit->addWidget(test1);

    return edit;
}

QHBoxLayout *editorvehicle::configureButtons()
{
    QHBoxLayout* buttons = new QHBoxLayout();

    // Creazione Pulsanti
    save = new QPushButton("Salva", this);
    save->setFixedSize(150, 70);
    clear = new QPushButton("Elimina tutti i campi dati", this);
    clear->setFixedSize(150, 70);

    // Aggiunta dei Bottoni al Layout Secondario
    buttons->addWidget(save);
    buttons->addWidget(clear);

    return buttons;
}

void editorvehicle::connectViewSignals() const
{
    connect(save, SIGNAL(clicked()), this, SIGNAL(saveSignal()));
    connect(clear, SIGNAL(clicked()), this, SIGNAL(clearSignal()));
}

void editorvehicle::close(QCloseEvent *event)
{
    //Elaboro chiusura solo se intenzionata da evento esterno
        if(!event->spontaneous()) return;
        else {
            //Accetto l'evento di chiusura della finestra
            event->accept();
            //Emetto segnale di chiusura della View
            emit viewClosed();
        }
}

editorvehicle::editorvehicle(const QSize &s, view *parent) : view(s, parent)
{
    QVBoxLayout* main = new QVBoxLayout;
    main->addLayout(configureFinalLayout());

    setLayout(main);
    setFixedSize(s);
    connectViewSignals();
    setTitle("Editor Veicoli");
}
