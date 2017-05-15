#include "vtray.h"

#include <QAction>
#include <QCoreApplication>
#include <QMenu>
#include <QFile>
#include <QDir>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

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
    setStatus();

    // periodically set status
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(setStatus()));
    timer->start(2000);

}

void VTray::setStatus() {

    vagrant -> readMachineIndex();

    bool boxesRunning = false;

    QJsonObject::iterator boxIt;

    for (boxIt = vagrant->boxes->begin(); boxIt != vagrant->boxes->end(); boxIt++) {
        QString boxId = boxIt.key();
        QJsonObject boxObj = boxIt.value().toObject();
        QString boxName = boxObj["name"].toString();
        QString boxState = boxObj["state"].toString();

        if (boxState == "running") {
           boxesRunning = true;
        }
    }

    if ( boxesRunning ) {
        setIcon(QIcon(":/images/vagrant-up.png"));
    } else {
        setIcon(QIcon(":/images/vagrant-down.png"));
    }
}
