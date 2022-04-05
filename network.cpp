#include "network.h"

NetworkCommunication::NetworkCommunication()
{

   // qDebug<<"netWork constructor";
    tcpClient=new QTcpSocket(this);
    addr= getLocalIp();
    connect(tcpClient,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(tcpClient,SIGNAL(disconnected()),this,SLOT(onDisConnected()));
    connect(tcpClient,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));
    connect(tcpClient,SIGNAL(readyRead()),this,SLOT(onSocketReadyRead()));
}



void  NetworkCommunication::startConnect()
{
    addr=getLocalIp();
    tcpClient->connectToHost(addr,port);
    tcpClient->waitForConnected(1000);
 //   tcpClient->connectToHost(addr,port);
    qDebug()<<"startConnect";
 //   writeData();
}

QHostAddress NetworkCommunication::getLocalIp()
{
    QString localhostName=QHostInfo::localHostName();
    QHostInfo info=QHostInfo::fromName(localhostName);
    foreach(QHostAddress address,info.addresses()){
        if(address.protocol()==QAbstractSocket::IPv4Protocol){
            return address;
        }
    }
    return QHostAddress("");
}

void NetworkCommunication::writeData(Message* msg)
{
    msgList.append(msg);
    tcpClient->write(msg->getData());
}

void NetworkCommunication::onConnected()
{
    qDebug()<<"客户端已接入服务端";
    Message msg;
   
    //writeData();
}

void NetworkCommunication::onSocketReadyRead()
{

  qDebug()<<"onSocketReadyRead "<<tcpClient->readAll();
}

void Network::run() {
    NetworkCommunication& networkCommunication = NetworkCommunication::getInstance();
    networkCommunication.startConnect();
    exec();//事件循环
}
