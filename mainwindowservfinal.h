#ifndef MAINWINDOWSERVFINAL_H
#define MAINWINDOWSERVFINAL_H

#include <QMainWindow>
#include "serveurtcp.h"
#include <QModelIndex>
#include "medialist.h"

namespace Ui {
class MainWindowServFinal;
}

class MainWindowServFinal : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindowServFinal(QWidget *parent = 0);
    ~MainWindowServFinal();
    
private:
    Ui::MainWindowServFinal *ui;
    ServeurTcp * serv;
    int port;
    int interface;
    MediaList * m;
    QString path;
    QString getPath();
private slots:
    void launch();
    void interfaceChoisie(const QModelIndex &);
    void portChoisi(int);
};

#endif // MAINWINDOWSERVFINAL_H
