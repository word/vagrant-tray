#include "vtray.h"

#include <QAction>
#include <QCoreApplication>
#include <QMenu>
#include <QFile>
#include <QDir>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>
//#include <QDebug>

VTray::VTray()
{

    // set up actions
    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);

    // create context menu
    trayIconMenu = new QMenu();
    trayIconMenu -> addAction(quitAction);

    setContextMenu(trayIconMenu);

    // set initial status
    checkStatus();

    // periodically check status
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkStatus()));
    timer->start(2000);

}

void VTray::checkStatus() {

    QString homePath = QDir::homePath();
    QFile indexFile(homePath + "/.vagrant.d/data/machine-index/index");

    if (!indexFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open machine index file.");
        //return false;
    }

    QByteArray indexData = indexFile.readAll();

    QJsonDocument indexDoc(QJsonDocument::fromJson(indexData));
    QJsonObject indexObj = indexDoc.object();
    QJsonObject machinesObj(indexObj["machines"].toObject());

    bool boxesRunning = false;

    foreach (const QJsonValue &value, machinesObj) {
        QJsonObject machine = value.toObject();
        //qDebug() << machine["name"] << machine["state"];

        if ( machine["state"].toString() == "running" ) {
            boxesRunning = true;
        }
    }

    if (boxesRunning) {
        setIcon(QIcon(":/images/vagrant-up.png"));
    } else {
        setIcon(QIcon(":/images/vagrant-down.png"));
    }

}
