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

class JSONAgent
{

public:
    explicit JSONAgent() = delete;
    explicit JSONAgent(const JSONAgent&) = delete;

    static QString selectFile();
    static QJsonDocument* getData(const QString& filePath);
    static void getVehicleList(QJsonDocument* file, garage &g);
    // static std::vector<Record*> getRecords(QJsonDocument* file) ???

    static bool saveGarage(const QJsonDocument& file, const QString& filePath);

};

#endif // JSONAGENT_H
