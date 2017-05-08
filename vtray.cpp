#include "vtray.h"

#include <QAction>
#include <QCoreApplication>
#include <QMenu>

VTray::VTray()
{
    setIcon(QIcon(":/images/heart.png"));

    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);

    trayIconMenu = new QMenu();
    trayIconMenu -> addAction(quitAction);

    setContextMenu(trayIconMenu);

}
