#ifndef RECEIVEMEDIA_H
#define RECEIVEMEDIA_H
#include <QThread>
#include <QTcpSocket>
/*
  ARTHUR 27/11 : Thread servant à la gestion des réceptions de média
 */

class ReceiveThread: public QThread
{
    Q_OBJECT

public:
    /*
      ARTHUR 27/11 :
      socketDescriptor Permet de crée un QTcpSocket pour chaque client
      pathFile Permet de savoir à quel endroit sur le serveur les videos doivent se trouver
      parent ...
     */
    ReceiveThread(int socketDescriptor, QString pathFile, QObject * parent);
    /*
      ARTHUR 27/11 :
      Bloquant tant qu'il n'y a rien à lire
      NB : Economie de ressources vs boucle
     */
    void run();
signals:
    /*
      ARTHUR 27/11 : Si la création du socket foire
     */
    void error(QTcpSocket::SocketError socketError);
private:
    /*
      ARTHUR 27/11 :
      socketDescriptor Permet de crée un QTcpSocket pour chaque client
      clientConnection Le QTcpSocket crée à partir de socketDescriptor
      pathFile Permet de savoir à quel endroit sur le serveur les videos doivent se trouver
     */
    int socketDescriptor;
    QTcpSocket * clientConnection;
    QString pathFile;
private slots:
    /*
      ARTHUR 27/11 : Déclancher quand run est débloqué
     */
    void lire_data();
};

#endif // RECEIVEMEDIA_H
