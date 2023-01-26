#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "View/view.h"
#include "Model/model.h"

class controller : public QObject{
    Q_OBJECT

private:

    // Connessione tra Segnali della Vista e Slot del Controller
    void connectViewController() const;

protected:
    view* v;
    model* m;

public:
    // Costruttore Esplicito e Distruttore Virtuale
    explicit controller(view* _v, model* _m, controller* parent = nullptr);
    virtual ~controller();

    // Funzioni Getter Virtuali Pure
    virtual view* getView() const = 0;
    virtual model* getModel() const = 0;

    // Funzioni per Mostrare e Nascondere v
    virtual void showView() const;
    virtual void hideView() const;

signals:

public slots:
    // Slot per la definizione del comportamento del programma in caso di chiusure volute o accidentali
    virtual void onClosedView() const = 0;
};

#endif
