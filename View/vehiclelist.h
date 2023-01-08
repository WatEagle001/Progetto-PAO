// Classe derivata da View che mostra i veicoli presenti nel garage, permettendo di crearne o caricare di nuovi e di visionare/modificare i veicoli esistenti
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
