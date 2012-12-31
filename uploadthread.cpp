#include "uploadthread.h"
#include <QDebug>
UploadThread::UploadThread(int socketDescriptor, QString pathFile, QObject * parent) : socketDescriptor(socketDescriptor),pathFile(pathFile+"/"), QThread(parent){
    reading=false;
    clientConnection = new QTcpSocket();
    connect(clientConnection,SIGNAL(readyRead()),this,SLOT(readData()));
    if (!clientConnection->setSocketDescriptor(socketDescriptor)) {
        emit error(clientConnection->error());
        return;
    }
    qDebug() << "[SERV] Waiting for signal readyRead()" ;
    bdContent = new MediaList();
}

void UploadThread::run(){
    /*
      ARTHUR 27/11 :
      Bloque tant qu'il n'y a rien à lire
     */
    clientConnection->waitForReadyRead(-1);
}

void UploadThread::readData(){
    if(reading)return;
    reading=true;
    qDebug() << "[SERV] - READ";
    fileName=readQStringSock(clientConnection);
    qDebug() << "[SERV] - File" << pathFile+fileName;
    sendData(fileName);
    reading=false;
}

void UploadThread::sendData(QString fileName){
    qDebug() << "[SERV] - SENDING DATA";
    QList < Media > mediaAlikeList = *bdContent->getMediaAlike(fileName);
    int mediaAlikeCount=mediaAlikeList.size();
    writeIntSock(&mediaAlikeCount,clientConnection);
    QString tmp;
    for(int i=0;i<mediaAlikeCount;i++){
        tmp=mediaAlikeList.at(i).getTitle();
        writeQStringSock(tmp,clientConnection);
        tmp=mediaAlikeList.at(i).getSynopsis();
        writeQStringSock(tmp,clientConnection);
        tmp=mediaAlikeList.at(i).getDate();
        writeQStringSock(tmp,clientConnection);
    }
    clientConnection->flush();
}

