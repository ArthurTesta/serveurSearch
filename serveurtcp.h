#ifndef SERVEURTCP_H
#define SERVEURTCP_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QNetworkInterface>
#include <QMessageBox>
#include "medialist.h"

class ServeurTcp : public QTcpServer
{
    Q_OBJECT
public:
    ServeurTcp();
    QList<QHostAddress> getAddressList();
    /*
      ARTHUR 27/11 : Ajout afin d'utiliser un listen traditionnel plus lisible
      (Désolé Arnaud on code vraiment pas pareil =D)
     */
    void setPath(QString path);
    /*
      ARTHUR 27/11 : Supprimer au profit de listen traditionnel
    void listenPerso(QHostAddress add, int port,QString pathFile);
     */
    ~ServeurTcp();
protected:
    /*
      ARTHUR 27/11 : Ajout pour les threads
     */
    void incomingConnection(int socketDescriptor);
private:
    /*
      ARTHUR 27/11 : Déplacer dans ReceiveThread
      QTcpSocket * clientConnection;
     */
    QList<QHostAddress> ipAddressesList;
    QString pathFile;

    /*
      ARTHUR 27/11 : Permets de ne pas allez faire de select chaque fois qu'on doit envoyer un film
     */
    MediaList * bdContent;

    /*
      ARTHUR 27/11 : Debug, permets d'envoyer sur le debug une liste de média
     */
    void debugMediaList();
signals:
    
public slots:

private slots:
    /*
      ARTHUR 27/11 : Remplacer par incominConnection
      void connexion();
     */
    /*
      ARTHUR 27/11 : Déplacer dans ReceiveThread
      void lire_data();
     */
};

#endif // SERVEURTCP_H
