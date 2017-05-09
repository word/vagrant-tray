#ifndef VAGRANT_H
#define VAGRANT_H

#include <QObject>

class Vagrant : public QObject
{
    Q_OBJECT

public:
    Vagrant();
    bool boxesRunning();
};


#endif // VAGRANT_H
