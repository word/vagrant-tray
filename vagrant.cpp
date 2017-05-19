#include "vagrant.h"

#include <QFile>
#include <QDir>

void Vagrant::readMachineIndex() {

    QFile indexFile(getIndexPath());

    if (!indexFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open machine index file.");
    }

    QByteArray indexData = indexFile.readAll();

    QJsonDocument indexDoc(QJsonDocument::fromJson(indexData));
    QJsonObject indexObj = indexDoc.object();
    *boxes = indexObj["machines"].toObject();

}

QString Vagrant::getIndexPath() {

    return QDir::homePath() + "/.vagrant.d/data/machine-index/index";
}
