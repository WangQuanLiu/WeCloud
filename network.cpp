#include "network.h"

Network::Network()
{

   // qDebug<<"netWork constructor";
    tcpClient=new QTcpSocket();
    addr=getLocalIp();
    tcpClient->connectToHost(addr,port);
    connect(tcpClient,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(tcpClient,SIGNAL(disconnected()),this,SLOT(onDisConnected()));
    connect(tcpClient,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));
    connect(tcpClient,SIGNAL(readyRead()),this,SLOT(onSocketReadyRead()));
}



void  Network::startConnect()
{
    tcpClient->connectToHost(addr,port);
    tcpClient->waitForConnected(10000);
  //  tcpClient->write("goto");
    qDebug()<<"startConnect";
    writeData();
}

QString Network::getLocalIp()
{
    QString localhostName=QHostInfo::localHostName();
    QHostInfo info=QHostInfo::fromName(localhostName);
    foreach(QHostAddress address,info.addresses()){
        if(address.protocol()==QAbstractSocket::IPv4Protocol){
            return address.toString();
        }
    }
    return "";
}

void Network::writeData()
{
    QByteArray text="test write data";
    tcpClient->write(text);
}

void Network::onConnected()
{
    qDebug()<<"客户端已接入服务端";


}

void Network::onSocketReadyRead()
{

  qDebug()<<"onSocketReadyRead "<<tcpClient->readAll();
}
