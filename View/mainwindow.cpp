#include "mainwindow.h"
#include <QMenuBar>
mainwindow::mainwindow(QWidget *parent): QMainWindow(parent){
    QVBoxLayout* main = new QVBoxLayout;
    QMenuBar* menu = new QMenuBar(this);
    QMenu* file = new QMenu("File", menu);
    QAction* save = file->addAction("Salva");
    menu->addMenu(file);
    setLayout(main);
}

mainwindow::~mainwindow()
{
}

