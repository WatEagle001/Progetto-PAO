#include "jsonagent.h"

QString JSONAgent::selectFile()
{
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
    QString data;
    QFile file;

    file.setFileName(filePath);
    file.open(QIODevice::Text | QIODevice::ReadOnly);
    data = file.readAll();
    file.close();

    // Lettura documento
    QJsonDocument* doc = new QJsonDocument(QJsonDocument::fromJson(data.toLocal8Bit()));
    QJsonObject obj = doc->object();

    //Controllo che i dati del documento siano corretti

    // Ritorno del documento corretto

    return new QJsonDocument();
}

QStringList *JSONAgent::getVehicleList(QJsonDocument *file)
{

}
