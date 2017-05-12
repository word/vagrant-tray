#ifndef VTRAY_H
#define VTRAY_H

#include <QSystemTrayIcon>
#include "vagrant.h"

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
QT_END_NAMESPACE

class VTray : public QSystemTrayIcon
{
    Q_OBJECT

public:
    VTray();

public slots:
    void setStatus();

private:
    QAction *quitAction;
    QMenu *trayIconMenu;
    QTimer *timer;
    Vagrant *vagrant = new Vagrant;
};

#endif // VTRAY_H
