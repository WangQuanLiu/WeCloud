#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QTcpSocket>
#include<QtNetwork>
class Network:public QObject
{
    friend class QDlgLogin;
   Q_OBJECT
public:
    static Network& getInstance(){
        static Network instance;
        return instance;
    }
    void startConnect();
    ~Network(){}
    Network(const Network&)=delete;
    Network&operator=(const Network&)=delete;
private:

    Network();
    QString getLocalIp();
    bool onConnected();
private:
QTcpSocket*tcpClient;
QString addr;
qint32 port=1200;
};

#endif // NETWORK_H
