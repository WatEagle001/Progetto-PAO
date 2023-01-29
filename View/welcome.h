// Classe derivata da View che rappresenta la schermata di benvenuto, dalla quale si può o aprire un nuovo garage oppure caricarne uno
#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QCloseEvent>
#include <QBoxLayout>
#include <QString>

#include "View/view.h"

class welcome : public view
{
    Q_OBJECT
private:
    QPushButton* openGarage;
    QPushButton* createGarage;
    QLayout* configureFinalLayout();
    QVBoxLayout* configureDescription();
    QHBoxLayout* configureButtons();
    void connectViewSignals() const override;

protected:
    void closeEvent(QCloseEvent* event) override;

public:
    explicit welcome(const QSize& s = QSize(), view* parent = nullptr);
    virtual ~welcome() = default;
signals:
    void readGarage();
    void newGarage();
};
#endif // WELCOME_H
