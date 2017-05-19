#ifndef VTRAY_H
#define VTRAY_H

#include <QSystemTrayIcon>
#include <QFileSystemWatcher>
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

private slots:
    void indexChanged();

private:
    void setStatus();
    QAction *quitAction;
    QMenu *trayIconMenu;
    //QTimer *timer;
    QFileSystemWatcher *watcher;
    Vagrant *vagrant;
};

#endif // VTRAY_H
