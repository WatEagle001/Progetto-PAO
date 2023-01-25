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
    explicit JSONAgent(const JSONAgent&) = delete;

    static QString selectFile();
    static QJsonDocument* getData(const QString& filePath);
    void getVehicleList(QJsonDocument* file, garage* gar);
    // static std::vector<Record*> getRecords(QJsonDocument* file) ???
    virtual ~JSONAgent() = default;

    static bool saveGarage(const QString& filePath, garage* g);


};

#endif // JSONAGENT_H
