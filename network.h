#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QTcpSocket>
#include<QtNetwork>
class Network:public QObject
{
   Q_OBJECT
public:
    Network();

private:
    QString getLocalIp();
private:
QTcpSocket*tcpClient;
QString addr;
qint32 port=1200;

};

#endif // NETWORK_H
