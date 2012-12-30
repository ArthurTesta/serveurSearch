#include <QtGui/QApplication>
#include "mainwindowservfinal.h"
#include <QDebug>
#include <vlc/vlc.h>
#include "media.h"
#include "medialist.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowServFinal w;
    w.show();
    
    return a.exec();
}
