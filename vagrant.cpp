#include "vagrant.h"

#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

Vagrant::Vagrant() {
}

bool Vagrant::readMachineIndex() {

    QString homePath = QDir::homePath();
    QFile indexFile(homePath + "/.vagrant.d/data/machine-index/index");

    if (!indexFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open machine index file.");
        return false;
    }

    QByteArray indexData = indexFile.readAll();

    QJsonDocument indexDoc(QJsonDocument::fromJson(indexData));
    QJsonObject indexObj = indexDoc.object();
    QJsonObject machinesObj = indexObj["machines"].toObject();

    foreach (const QJsonValue &value, machinesObj) {
        QJsonObject machine = value.toObject();
        //qDebug() << machine["name"] << machine["state"];

        if ( machine["state"].toString() == "running" ) {
            running = true;
        }
    }

    return true;
}

bool Vagrant::boxesRunning() {

    readMachineIndex();
    return running;

}
