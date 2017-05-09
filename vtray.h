#ifndef VTRAY_H
#define VTRAY_H

#include <QSystemTrayIcon>

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
    void checkStatus();

private:
    QAction *quitAction;
    QMenu *trayIconMenu;
    QTimer *timer;
};

#endif // VTRAY_H
