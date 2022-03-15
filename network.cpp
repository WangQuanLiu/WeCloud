#include "network.h"

Network::Network()
{

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

bool Network::onConnected()
{
    //连接信号槽
    return true;
}
