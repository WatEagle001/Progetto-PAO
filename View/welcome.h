// Classe derivata da View che rappresenta la schermata di benvenuto, dalla quale si può o aprire un nuovo garage oppure caricarne uno
#ifndef WELCOME_H
#define WELCOME_H
#include "view.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QCloseEvent>
#include <QBoxLayout>

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
    void close(QCloseEvent* event);
public:
    explicit welcome(const QSize& s = QSize(), view* parent = nullptr);
    virtual ~welcome() = default;
signals:
    void readGarage();
    void newGarage();
};
#endif // WELCOME_H
