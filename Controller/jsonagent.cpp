#include "jsonagent.h"

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
void JSONAgent::getVehicleList(QJsonDocument *file, garage& g){
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
            g.addVeicolo(a);
            delete a;
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
            g.addVeicolo(a);
            delete a;
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

            g.addVeicolo(a);
            delete a;
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
            g.addVeicolo(a);
            delete a;
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
            g.addVeicolo(a);
            delete a;
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

            g.addVeicolo(a);
            delete a;
        }
    }
}
