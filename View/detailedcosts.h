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
#include <QtCharts/QLineSeries>
#include <QtCharts/QtCharts>
#include <QChart>


class detailedcosts : public view
{
    Q_OBJECT
private:
    void connectViewSignals() const override;
    CostiViaggio* c;
protected:
    void closeEvent(QCloseEvent* event) override;

public:
    explicit detailedcosts(CostiViaggio* cost,const QSize& s = QSize(), view* parent = nullptr);
    virtual ~detailedcosts() = default;
    QVBoxLayout* addIstogramma();
};


#endif // DETAILEDCOSTS_H
