#ifndef VEHICLELIST_H
#define VEHICLELIST_H

#include <QAction>
#include <QDialog>
#include <QFileDialog>
#include <QFrame>
#include <QHBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "view.h"
#include "Controller/vehiclelistcontroller.h"

class vehiclelist : public view
{

    Q_OBJECT

private:
    QHBoxLayout* layout;
    QMenu *file, *garage;

    void connectViewSignals() const override;

protected:
    void closeEvent(QCloseEvent* event) override;

public:
    explicit vehiclelist(const QSize& s = QSize(), view* parent = nullptr);
    void setTitle(const QString &title) override;

// DA INSERIRE SIGNAL E SLOT DELLA CLASSE
};

#endif // VEHICLELIST_H
