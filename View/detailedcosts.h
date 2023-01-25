#ifndef DETAILEDCOSTS_H
#define DETAILEDCOSTS_H
#include "view.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QCloseEvent>
#include <QBoxLayout>
#include <Model/CostiViaggio.h>
class detailedcosts : public view
{
    Q_OBJECT
private:
    QLayout* configureFinalLayout();
    QVBoxLayout* configureDescription();
    QHBoxLayout* configureButtons();
    void connectViewSignals() const override;
protected:
    void close(QCloseEvent* event);
public:
    explicit detailedcosts(CostiViaggio* c,const QSize& s = QSize(), view* parent = nullptr);
    virtual ~detailedcosts() = default;
    void addDiagrammaCartesiano();
};


#endif // DETAILEDCOSTS_H
