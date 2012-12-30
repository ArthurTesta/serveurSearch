#include "mainwindowservfinal.h"
#include "ui_mainwindowservfinal.h"
#include <QMessageBox>

MainWindowServFinal::MainWindowServFinal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowServFinal)
{
    ui->setupUi(this);
    //    serv = new ServeurTcp();

    interface = -1;
    port = 4002;

    qDebug() << "[MAIN] - INIT";
    connect(ui->ServLaunch,SIGNAL(clicked()),this,SLOT(launch()));
    connect(ui->listInterface,SIGNAL(clicked(const QModelIndex &)),this, SLOT(interfaceChoisie(const QModelIndex &)));


    qDebug() << "[MAIN] - REMPLISSAGE LISTE INTERFACES";

    serv = new ServeurTcp();

    for(int i = 0; i < serv->getAddressList().size(); i++)
    {
        ui->listInterface->addItem(serv->getAddressList().at(i).toString());
    }
    ui->listInterface->addItem("All");

}

void MainWindowServFinal::interfaceChoisie(const QModelIndex & index){

    qDebug() << "[MAIN] - INTERFACE CHOISIE " << index.row();
    if(index.isValid()){
        interface = index.row();
    }
}

QString MainWindowServFinal::getPath(){
    return ui->lineEditPath->text();
}

void MainWindowServFinal::portChoisi(int index){
    qDebug() << "[MAIN] - PORT CHOISI " << index;
    port = index;
}

void MainWindowServFinal::launch(){
    qDebug() << "[MAIN] - CLICK LAUNCH " << interface;
    // si option par defaut ou all
    /*
      ARTHUR 27/11 : Modifié pour les threads
      J'ai enlevé les listenPerso que j'ai remplacer par un setPath + listen traditionnel
     */
    serv->setPath(ui->lineEditPath->text());
    if(interface < 0 || interface == (serv->getAddressList().size() - 1))
    {
        serv->listen(QHostAddress::Null,port);
    }else{
        serv->listen(serv->getAddressList().at(interface),port);
    }
}

MainWindowServFinal::~MainWindowServFinal()
{
    delete ui;
}
