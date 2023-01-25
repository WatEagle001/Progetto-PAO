#include "jsonagent.h"

JSONAgent::JSONAgent(garage *gar)
{
g = gar;
}

QString JSONAgent::selectFile()
{
    qDebug() << "DEBUG: Creazione del popup per la scelta del file\n";
    QFileDialog popup;
    popup.setFileMode(QFileDialog::ExistingFile);
    popup.setNameFilter("JSON (*.json)");
    QString file;

    if(popup.exec())
        file = popup.selectedFiles().at(0);

    return file;
}

QJsonDocument *JSONAgent::getData(const QString &filePath)
{
    if(filePath.isNull()) return new QJsonDocument();

    qDebug() << "DEBUG: Caricamento del file .json\n";
    QString data;
    QFile file;

    file.setFileName(filePath);
    file.open(QIODevice::Text | QIODevice::ReadOnly);
    data = file.readAll();
    file.close();

    // Lettura documento
    qDebug() << "DEBUG: Lettura del file .json\n";
    QJsonDocument* doc = new QJsonDocument(QJsonDocument::fromJson(data.toLocal8Bit()));
    QJsonObject obj = doc->object();

    if(!obj.contains("veicoli")){
        delete doc;
        return new QJsonDocument();
    }

    qDebug() << "DEBUG: Fine lettura del file .json\n";
    return doc;

}

// Da implementare mettendo un riferimento a garage come parametro così da caricare tutto direttamente dentro
void JSONAgent::getVehicleList(QJsonDocument *file, garage* gar){
    g = gar;
    QJsonObject data = file->object();
    QJsonArray list = data["veicoli"].toArray();

    for(const QJsonValue& vehicle : list){

        alimentazione carburante = undefined;

        if(vehicle.toObject().value("carburante").toString().toStdString() == "benzina")
            carburante = benzina;
        else
            if(vehicle.toObject().value("carburante").toString().toStdString() == "diesel")
                carburante = diesel;
            else
                if(vehicle.toObject().value("carburante").toString().toStdString() == "metano")
                    carburante = metano;
                else
                    if(vehicle.toObject().value("carburante").toString().toStdString() == "gpl")
                        carburante = gpl;
                    else
                        if(vehicle.toObject().value("carburante").toString().toStdString() == "biodiesel")
                            carburante = biodisel;
                        else
                            if(vehicle.toObject().value("carburante").toString().toStdString() == "idrogeno")
                                carburante = idrogeno;

        if(vehicle.toObject().value("tipo").toString() == QString("auto ibrida")){
            auto_ibrida* a = new auto_ibrida(
                        vehicle.toObject().value("marca").toString().toStdString(),
                        vehicle.toObject().value("modello").toString().toStdString(),
                        vehicle.toObject().value("targa").toString().toStdString(),
                        vehicle.toObject().value("km").toInt(),
                        static_cast<unsigned int>(vehicle.toObject().value("cilindrata").toInt()),
                        static_cast<unsigned int>(vehicle.toObject().value("litri_serbatoio").toInt()),
                        carburante,
                        vehicle.toObject().value("kw").toInt(),
                        vehicle.toObject().value("manutenzione").toBool(),
                        static_cast<unsigned int>(vehicle.toObject().value("ricaricare").toInt()),
                        static_cast<unsigned int>(vehicle.toObject().value("costo").toDouble()),
                        static_cast<unsigned int>(vehicle.toObject().value("costo_ricarica").toDouble()));
            g->addVeicolo(a);

        }
        if(vehicle.toObject().value("tipo").toString() == QString("automobile")){
            automobile* a = new automobile(
                        vehicle.toObject().value("marca").toString().toStdString(),
                        vehicle.toObject().value("modello").toString().toStdString(),
                        vehicle.toObject().value("targa").toString().toStdString(),
                        vehicle.toObject().value("km").toInt(),
                        static_cast<unsigned int>(vehicle.toObject().value("cilindrata").toInt()),
                        static_cast<unsigned int>(vehicle.toObject().value("litri_serbatoio").toInt()),
                        carburante,
                        vehicle.toObject().value("manutenzione").toBool(),
                        static_cast<unsigned int>(vehicle.toObject().value("costo").toInt()));
            g->addVeicolo(a);

        }
        if(vehicle.toObject().value("tipo").toString() == QString("monopattino elettrico")){
            monopattino_elettrico* a = new monopattino_elettrico(
                        vehicle.toObject().value("marca").toString().toStdString(),
                        vehicle.toObject().value("modello").toString().toStdString(),
                        vehicle.toObject().value("targa").toString().toStdString(),
                        vehicle.toObject().value("km").toInt(),
                        vehicle.toObject().value("kw").toInt(),
                        static_cast<unsigned int>(vehicle.toObject().value("ricaricare").toInt()),
                        static_cast<unsigned int>(vehicle.toObject().value("costo_ricarica").toDouble()));

            g->addVeicolo(a);

        }
        if(vehicle.toObject().value("tipo").toString() == QString("moto")){
            moto* a = new moto(
                        vehicle.toObject().value("marca").toString().toStdString(),
                        vehicle.toObject().value("modello").toString().toStdString(),
                        vehicle.toObject().value("targa").toString().toStdString(),
                        vehicle.toObject().value("km").toInt(),
                        static_cast<unsigned int>(vehicle.toObject().value("cilindrata").toInt()),
                        static_cast<unsigned int>(vehicle.toObject().value("litri_serbatoio").toInt()),
                        carburante,
                        vehicle.toObject().value("manutenzione").toBool(),
                        static_cast<unsigned int>(vehicle.toObject().value("costo").toInt()));
            g->addVeicolo(a);

        }
        if(vehicle.toObject().value("tipo").toString() == QString("moto elettrica")){
            moto_elettrica* a = new moto_elettrica(
                        vehicle.toObject().value("marca").toString().toStdString(),
                        vehicle.toObject().value("modello").toString().toStdString(),
                        vehicle.toObject().value("km").toInt(),
                        vehicle.toObject().value("kw").toInt(),
                        static_cast<unsigned int>(vehicle.toObject().value("ricaricare").toInt()),
                        static_cast<unsigned int>(vehicle.toObject().value("costo_ricarica").toDouble()));
                        vehicle.toObject().value("targa").toString().toStdString();
            g->addVeicolo(a);

        }
        if(vehicle.toObject().value("tipo").toString() == QString("auto elettrica")){
            auto_elettrica* a = new auto_elettrica(
                        vehicle.toObject().value("marca").toString().toStdString(),
                        vehicle.toObject().value("modello").toString().toStdString(),
                        vehicle.toObject().value("targa").toString().toStdString(),
                        vehicle.toObject().value("km").toInt(),
                        vehicle.toObject().value("kw").toInt(),
                        static_cast<unsigned int>(vehicle.toObject().value("ricaricare").toInt()),
                        static_cast<unsigned int>(vehicle.toObject().value("costo_ricarica").toDouble()));

            g->addVeicolo(a);

        }
    }
}

bool JSONAgent::saveGarage(const QString &filePath, garage* g)
{
    if(filePath.isNull() || filePath.isEmpty()){
        qDebug() << "Primo False";
        return false;
    }

    QJsonDocument file;
    QJsonObject gobj = QJsonObject();
    QJsonArray toExport;

    for(int i = 0; i < g->size(); ++i){

        QJsonObject gobj = QJsonObject();
        QString alim = QString("undefined");
        motore_combustione* tmp = dynamic_cast<motore_combustione*>(g->getVeicolo(i));

        if(tmp){
            if(tmp->getAlimentazione() == benzina){
                alim = QString("benzina");
            }

            if(tmp->getAlimentazione() == diesel){
                alim = QString("diesel");
            }

            if(tmp->getAlimentazione() == idrogeno){
                alim = QString("idrogeno");
            }

            if(tmp->getAlimentazione() == metano){
                alim = QString("metano");
            }

            if(tmp->getAlimentazione() == gpl){
                alim = QString("gpl");
            }

            if(tmp->getAlimentazione() == biodisel){
                alim = QString("biodisel");
            }
        }


        if(dynamic_cast<automobile*>(g->getVeicolo(i))){
            gobj.insert("tipo", "automobile");
            gobj.insert("marca", QJsonValue::fromVariant(QString::fromStdString(g->getVeicolo(i)->getMarca())));
            gobj.insert("modello", QJsonValue::fromVariant(QString::fromStdString(g->getVeicolo(i)->getModello())));
            gobj.insert("targa", QJsonValue::fromVariant(QString::fromStdString(g->getVeicolo(i)->getTarga())));
            gobj.insert("km", QJsonValue::fromVariant(QString::number(g->getVeicolo(i)->getKm_odometro())));
            gobj.insert("cilindrata", QJsonValue::fromVariant(QString::number(dynamic_cast<automobile*>(g->getVeicolo(i))->getCilindrata())));
            gobj.insert("litri_serbatoio", QJsonValue::fromVariant(QString::number(dynamic_cast<automobile*>(g->getVeicolo(i))->getLitri_serbatoio())));
            gobj.insert("carburante", QJsonValue::fromVariant(alim));
            gobj.insert("manutenzione", QJsonValue::fromVariant(QString::number(dynamic_cast<automobile*>(g->getVeicolo(i))->getManutenzione())));
            gobj.insert("costo", QJsonValue::fromVariant(QString::number(dynamic_cast<automobile*>(g->getVeicolo(i))->getCosto_manutenzione())));

            toExport.push_back(gobj);
        }
        else
        if(dynamic_cast<auto_elettrica*>(g->getVeicolo(i))){
            gobj.insert("tipo", "auto elettrica");
            gobj.insert("marca", QJsonValue::fromVariant(QString::fromStdString(g->getVeicolo(i)->getMarca())));
            gobj.insert("modello", QJsonValue::fromVariant(QString::fromStdString(g->getVeicolo(i)->getModello())));
            gobj.insert("targa", QJsonValue::fromVariant(QString::fromStdString(g->getVeicolo(i)->getTarga())));
            gobj.insert("km", QJsonValue::fromVariant(QString::number(g->getVeicolo(i)->getKm_odometro())));
            gobj.insert("kw", QJsonValue::fromVariant(QString::number(dynamic_cast<auto_elettrica*>(g->getVeicolo(i))->getKw_batteria())));
            gobj.insert("ricaricare", QJsonValue::fromVariant(QString::number(dynamic_cast<auto_elettrica*>(g->getVeicolo(i))->getRicaricare())));
            gobj.insert("costo_ricarica", QJsonValue::fromVariant(QString::number(dynamic_cast<auto_elettrica*>(g->getVeicolo(i))->getCosto_ricarica())));

            toExport.push_back(gobj);
        }
        else
        if(dynamic_cast<auto_ibrida*>(g->getVeicolo(i))){
            gobj.insert("tipo", "auto ibrida");
            gobj.insert("marca", QJsonValue::fromVariant(QString::fromStdString(g->getVeicolo(i)->getMarca())));
            gobj.insert("modello", QJsonValue::fromVariant(QString::fromStdString(g->getVeicolo(i)->getModello())));
            gobj.insert("targa", QJsonValue::fromVariant(QString::fromStdString(g->getVeicolo(i)->getTarga())));
            gobj.insert("km", QJsonValue::fromVariant(QString::number(g->getVeicolo(i)->getKm_odometro())));
            gobj.insert("cilindrata", QJsonValue::fromVariant(QString::number(dynamic_cast<auto_ibrida*>(g->getVeicolo(i))->getCilindrata())));
            gobj.insert("litri_serbatoio", QJsonValue::fromVariant(QString::number(dynamic_cast<auto_ibrida*>(g->getVeicolo(i))->getLitri_serbatoio())));
            gobj.insert("carburante", QJsonValue::fromVariant(alim));
            gobj.insert("kw", QJsonValue::fromVariant(QString::number(dynamic_cast<auto_ibrida*>(g->getVeicolo(i))->getKw_batteria())));
            gobj.insert("manutenzione", QJsonValue::fromVariant(QString::number(dynamic_cast<auto_ibrida*>(g->getVeicolo(i))->getManutenzione())));
            gobj.insert("ricaricare", QJsonValue::fromVariant(QString::number(dynamic_cast<auto_ibrida*>(g->getVeicolo(i))->getRicaricare())));
            gobj.insert("costo", QJsonValue::fromVariant(QString::number(dynamic_cast<auto_ibrida*>(g->getVeicolo(i))->getCosto_manutenzione())));
            gobj.insert("costo_ricarica", QJsonValue::fromVariant(QString::number(dynamic_cast<auto_ibrida*>(g->getVeicolo(i))->getCosto_ricarica())));

            toExport.push_back(gobj);
        }
        else
        if(dynamic_cast<moto*>(g->getVeicolo(i))){
            gobj.insert("tipo", "moto");
            gobj.insert("marca", QJsonValue::fromVariant(QString::fromStdString(g->getVeicolo(i)->getMarca())));
            gobj.insert("modello", QJsonValue::fromVariant(QString::fromStdString(g->getVeicolo(i)->getModello())));
            gobj.insert("targa", QJsonValue::fromVariant(QString::fromStdString(g->getVeicolo(i)->getTarga())));
            gobj.insert("km", QJsonValue::fromVariant(QString::number(g->getVeicolo(i)->getKm_odometro())));
            gobj.insert("cilindrata", QJsonValue::fromVariant(QString::number(dynamic_cast<moto*>(g->getVeicolo(i))->getCilindrata())));
            gobj.insert("litri_serbatoio", QJsonValue::fromVariant(QString::number(dynamic_cast<moto*>(g->getVeicolo(i))->getLitri_serbatoio())));
            gobj.insert("carburante", QJsonValue::fromVariant(alim));
            gobj.insert("manutenzione", QJsonValue::fromVariant(QString::number(dynamic_cast<moto*>(g->getVeicolo(i))->getManutenzione())));
            gobj.insert("costo", QJsonValue::fromVariant(QString::number(dynamic_cast<moto*>(g->getVeicolo(i))->getCosto_manutenzione())));

            toExport.push_back(gobj);
        }
        else
        if(dynamic_cast<moto_elettrica*>(g->getVeicolo(i))){
            gobj.insert("tipo", "moto elettrica");
            gobj.insert("marca", QJsonValue::fromVariant(QString::fromStdString(g->getVeicolo(i)->getMarca())));
            gobj.insert("modello", QJsonValue::fromVariant(QString::fromStdString(g->getVeicolo(i)->getModello())));
            gobj.insert("targa", QJsonValue::fromVariant(QString::fromStdString(g->getVeicolo(i)->getTarga())));
            gobj.insert("km", QJsonValue::fromVariant(QString::number(g->getVeicolo(i)->getKm_odometro())));
            gobj.insert("kw", QJsonValue::fromVariant(QString::number(dynamic_cast<moto_elettrica*>(g->getVeicolo(i))->getKw_batteria())));
            gobj.insert("ricaricare", QJsonValue::fromVariant(QString::number(dynamic_cast<moto_elettrica*>(g->getVeicolo(i))->getRicaricare())));
            gobj.insert("costo_ricarica", QJsonValue::fromVariant(QString::number(dynamic_cast<moto_elettrica*>(g->getVeicolo(i))->getCosto_ricarica())));

            toExport.push_back(gobj);
        }
        else
        if(dynamic_cast<monopattino_elettrico*>(g->getVeicolo(i))){
            gobj.insert("tipo", "moto elettrica");
            gobj.insert("marca", QJsonValue::fromVariant(QString::fromStdString(g->getVeicolo(i)->getMarca())));
            gobj.insert("modello", QJsonValue::fromVariant(QString::fromStdString(g->getVeicolo(i)->getModello())));
            gobj.insert("targa", QJsonValue::fromVariant(QString::fromStdString(g->getVeicolo(i)->getTarga())));
            gobj.insert("km", QJsonValue::fromVariant(QString::number(g->getVeicolo(i)->getKm_odometro())));
            gobj.insert("kw", QJsonValue::fromVariant(QString::number(dynamic_cast<monopattino_elettrico*>(g->getVeicolo(i))->getKw_batteria())));
            gobj.insert("ricaricare", QJsonValue::fromVariant(QString::number(dynamic_cast<monopattino_elettrico*>(g->getVeicolo(i))->getRicaricare())));
            gobj.insert("costo_ricarica", QJsonValue::fromVariant(QString::number(dynamic_cast<monopattino_elettrico*>(g->getVeicolo(i))->getCosto_ricarica())));

            toExport.push_back(gobj);
        }
    }

    file.setArray(toExport);

    QFile fileTemplate(filePath);
    if(fileTemplate.open(QFile::WriteOnly | QFile::Text | QFile::Truncate)){
        fileTemplate.write(file.toJson());
        fileTemplate.close();
        return true;
    }

    qDebug() << "Secondo False";
    return false;
}
