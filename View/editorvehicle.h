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
#include <QFormLayout>
#include <QComboBox>
#include <Model/garage.h>
#include <Model/veicolo.h>

class editorvehicle:public view{
    Q_OBJECT
private:
        veicolo * v;
        QPushButton* save;
        QPushButton* clear;
        QLineEdit* marca;
        QFormLayout* layout;
        QComboBox* tipoAlimentazione;
        QLayout* configureFinalLayout();
        QFormLayout* configureEditor();
        QHBoxLayout* configureButtons();
        void addMoreOptions();
        void deleteOptions();
        void connectViewSignals() const override;
protected:
    void close(QCloseEvent* event);
public:
    explicit editorvehicle(veicolo* veic,const QSize& s = QSize(), view* parent = nullptr);
    virtual ~editorvehicle() = default;

signals:
    void saveSignal();
    void clearSignal();
    void selectedTypeVehicle();

};

#endif // EDITORVEHICLE_H
