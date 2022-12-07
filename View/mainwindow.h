#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();
};
#endif // MAINWINDOW_H
