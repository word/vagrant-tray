#include "vtray.h"

#include <QAction>
#include <QCoreApplication>
#include <QMenu>
#include <QFile>
#include <QTimer>

VTray::VTray()
{



    // set up actions
    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);

    // create context menu
    trayIconMenu = new QMenu();
    trayIconMenu -> addAction(quitAction);

    setContextMenu(trayIconMenu);

    // set initial icon
    setIcon(QIcon(":/images/heart.png"));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkStatus()));
    timer->start(1000);

}

void VTray::checkStatus() {

    QFile testfile("/tmp/testfile");
    if ( testfile.exists() ) {
        setIcon(QIcon(":/images/heart.png"));
    } else {
        setIcon(QIcon(":/images/bad.png"));
    }

}
