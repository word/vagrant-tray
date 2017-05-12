#ifndef VAGRANT_H
#define VAGRANT_H

#include <QObject>
#include <QJsonObject>

class Vagrant : public QObject
{
    Q_OBJECT


public:
    Vagrant();
    bool boxesRunning();

public slots:
    bool readMachineIndex();

private:
    bool running = false;
};


#endif // VAGRANT_H
