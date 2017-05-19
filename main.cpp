#include "vtray.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    VTray w;
    w.show();

    return a.exec();
}
