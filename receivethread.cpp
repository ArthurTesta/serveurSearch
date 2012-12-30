#include "receivethread.h"
#include <QtNetwork>
ReceiveThread::ReceiveThread(int socketDescriptor, QString pathFile, QObject * parent):socketDescriptor(socketDescriptor), pathFile(pathFile), QThread(parent){
    /*
      ARTHUR 27/11 :
      Cree le thread avec le socketDescriptor et le pathfile ou on doit stocker les videos
      Puis création du QTcpSocket grâce au socket descriptor
      Bind du readyread avec la fonction lire_data()
     */
    clientConnection = new QTcpSocket();
    if (!clientConnection->setSocketDescriptor(socketDescriptor)) {
        emit error(clientConnection->error());
        return;
    }
    connect(clientConnection,SIGNAL(readyRead()),this,SLOT(lire_data()));
}

void ReceiveThread::run(){
    qDebug() << "[SERV] Waiting for signal readyRead()" ;
    /*
      ARTHUR 27/11 :
      Bloque tant qu'il n'y a rien à lire
     */
    clientConnection->waitForReadyRead(-1);
}

void ReceiveThread::lire_data(){
    qDebug() << "[SERV] - READ";
    int sizeName=0,sizeFile=0,fileBytesWritten=0;
    char * tmp = new char[40];
    QByteArray data;
    /*
      ARTHUR 27/11 :
      Lecture de la longueur en byte du nom de fichier
     */
    clientConnection->read(((char*)&sizeName),4);
    /*
      ARTHUR 27/11 :
      Lecture + création du pathFile indiquant ou sera stocké le fichier
     */
    int cpt = clientConnection->read(tmp,sizeName);
    pathFile += "/";
    for (int cpt=0;cpt<sizeName-1;cpt++){
        pathFile += tmp[cpt];
    }
    qDebug() << "[SERV] - NEW PATHFILE" << pathFile;
    /*
      ARTHUR 27/11 :
      Lecture du nombre de la taille du fichier pour la boucle while
     */
    clientConnection->read((char *)&sizeFile,4);
    qDebug() << "[SERV] - SIZE FILE READ" << sizeFile;
    while (fileBytesWritten<sizeFile){
        /*
          ARTHUR 27/11 :
          Bloque tant qu'il n'y a rien à lire
         */
        clientConnection->waitForReadyRead(-1);
        /*
          ARTHUR 27/11 :
          Ajoute au QByteArray ce qui est lu
         */
        fileBytesWritten+=clientConnection->bytesAvailable();
        /*
          ARTHUR 27/11 :
          Lit ce qui est disponnible uniquement
         */
        data +=clientConnection->read(clientConnection->bytesAvailable());
        /*
          ARTHUR 27/11 :
          Vide (normalement inutile)
         */
        clientConnection->flush();
    }
    /*
      ARTHUR 27/11 :
      Write dans le fichier une fois que tout est récupéré
     */
    QFile * entry = new QFile(pathFile);
    if(entry->open(QIODevice::Append)){
        qDebug() << "[SERV] - WRITE";
        entry->write(data);
    }
    qDebug() << "[SERV] - BYTES WRITTEN" << fileBytesWritten;
    entry->close();
    qDebug() << "WRITE OK";
    clientConnection->close();
}
