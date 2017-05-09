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
    setStatus();

    // periodically check setStatus
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(setStatus()));
    timer->start(2000);

}

void VTray::setStatus() {

    if (vagrant -> boxesRunning()) {
        setIcon(QIcon(":/images/vagrant-up.png"));
    } else {
        setIcon(QIcon(":/images/vagrant-down.png"));
    }

}
