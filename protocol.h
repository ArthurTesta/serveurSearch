#ifndef PROTOCOL_H
#define PROTOCOL_Hs
#include <QString>
#include <QtNetwork>

class Exception;
void readCharSock(char * dest, int length,QTcpSocket * t);
void readIntSock(int * dest, QTcpSocket * t);
QString & readQStringSock(QTcpSocket * t);
QByteArray & readDataSock(QTcpSocket * t) throw (Exception);
void writeIntSock(int * source, QTcpSocket * t);
void writeQStringSock(QString & source,QTcpSocket * t);

#endif // PROTOCOL_H
