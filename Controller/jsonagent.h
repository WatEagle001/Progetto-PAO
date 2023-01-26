#ifndef JSONAGENT_H
#define JSONAGENT_H

#include <QFile>
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <string>
#include <QDebug>

#include "Model/garage.h"
#include "Model/veicolo.h"

class JSONAgent{
private:
        garage* g;

public:

    explicit JSONAgent(garage * gar);

    // Eliminazione del costruttore e del distruttore (classe statica)
    explicit JSONAgent(const JSONAgent&) = delete;
    ~JSONAgent() = delete;

    // Permette di selezionare un file JSON idoneo per il programma
    static QString selectFile();

    // Permette di leggere un file JSON idoneo per il programma
    static QJsonDocument* getData(const QString& filePath);

    // Estrae i dati di interesse da un file JSON idoneo
    void getVehicleList(QJsonDocument* file, garage* gar);

    // Permette di esportare un garage un di un file JSON idoneo
    static bool saveGarage(const QString& filePath, garage* g);


};

#endif // JSONAGENT_H
