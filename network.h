#ifndef NETWORK_H
#define NETWORK_H
#include <QObject>
#include <QTcpSocket>
#include<QtNetwork>
#include<qthread.h>
class NetworkCommunication:public QObject
{
    
public:
    static NetworkCommunication& getInstance(){
        static NetworkCommunication instance;
        return instance;
    }
    void startConnect();
    ~NetworkCommunication(){}
    NetworkCommunication(const NetworkCommunication&)=delete;
    NetworkCommunication&operator=(const NetworkCommunication&)=delete;

private slots:
    void onSocketReadyRead();
     void onConnected();
private:
    NetworkCommunication();
QString getLocalIp();
void writeData();
QTcpSocket* tcpClient;
QString addr;
qint32 port = 1200;
};

class Network :public QThread
{
    friend class QDlgLogin;
public:
    static Network& getInstance() {
        static Network instance;
        return instance;
    }
    ~Network() {}
    Network(const Network&) = delete;
    Network& operator=(const Network&) = delete;

protected:
    void run() Q_DECL_OVERRIDE;
private:
    Network() {}
};
#endif // NETWORK_H
