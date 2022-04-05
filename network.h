#ifndef NETWORK_H
#define NETWORK_H
#include <QObject>
#include <QTcpSocket>
#include<QtNetwork>
#include<qthread.h>
#include<qlist.h>
#include<message.h>
class NetworkCommunication:public QObject
{
    Q_OBJECT
    
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
    QHostAddress getLocalIp();
void writeData(Message*msg);
QTcpSocket* tcpClient;
QHostAddress addr;
qint32 port = 1800;
QList<Message*>msgList;
};

class Network :public QThread
{
    friend class QDlgLogin;
public:
    static Network& getInstance() {
        static Network instance;
        return instance;
    }
    ~Network() {
    
        terminate();
        wait();
    }
    Network(const Network&) = delete;
    Network& operator=(const Network&) = delete;

protected:
    void run() Q_DECL_OVERRIDE;
private:
    Network() {}
};
#endif // NETWORK_H
