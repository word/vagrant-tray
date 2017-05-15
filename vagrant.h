#ifndef VAGRANT_H
#define VAGRANT_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QVector>
#include "box.h"

class Vagrant : public QObject
{
    Q_OBJECT

public:
    void readMachineIndex();
    QJsonObject *boxes = new QJsonObject;


};


#endif // VAGRANT_H
