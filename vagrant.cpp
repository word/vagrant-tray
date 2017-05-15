#include "vagrant.h"

#include <QFile>
#include <QDir>

void Vagrant::readMachineIndex() {

    QString homePath = QDir::homePath();
    QFile indexFile(homePath + "/.vagrant.d/data/machine-index/index");

    if (!indexFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open machine index file.");
    }

    QByteArray indexData = indexFile.readAll();

    QJsonDocument indexDoc(QJsonDocument::fromJson(indexData));
    QJsonObject indexObj = indexDoc.object();
    *boxes = indexObj["machines"].toObject();

}
