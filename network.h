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
        friend class Network;
public:
    
    NetworkCommunication();
    void startConnect();
    ~NetworkCommunication(){}
private slots:
    void onSocketReadyRead();
     void onConnected();
     void addData(Message* msg);
     void addData(Message msg);
private:
    
    QHostAddress getLocalIp();
    void writeData( );
    QTcpSocket* tcpClient;
    QHostAddress addr;
    qint32 port = 1800;
    QList<Message*>msgList;
};

class Network :public QThread
{
    Q_OBJECT
    friend class QDlgLogin;
public:
    Network();
    ~Network() {
    
        terminate();
        wait();
    }
    Network(const Network&) = delete;
    Network& operator=(const Network&) = delete;
   
   
    void stop();
    void addData(Message* msg);
    void addData(Message& msg);
    void writeData();
protected:
    void run() Q_DECL_OVERRIDE;
   
private:
    NetworkCommunication* networkCommunication ;
  
    QList<Message>msgMan;
   
};
#endif // NETWORK_H
