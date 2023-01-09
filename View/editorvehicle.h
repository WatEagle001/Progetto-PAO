#ifndef EDITORVEHICLE_H
#define EDITORVEHICLE_H
#include <QPushButton>
#include "view.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QCloseEvent>

class editorvehicle:public view{
    Q_OBJECT
private:
        QPushButton* save;
        QPushButton* clear;

        QLayout* configureFinalLayout();
        QVBoxLayout* configureEditor();
        QHBoxLayout* configureButtons();
        void connectViewSignals() const override;
protected:
    void close(QCloseEvent* event);
public:
    explicit editorvehicle(const QSize& s = QSize(), view* parent = nullptr);
    virtual ~editorvehicle() = default;

signals:
    void saveSignal();
    void clearSignal();
};

#endif // EDITORVEHICLE_H
