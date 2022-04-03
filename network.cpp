#include "network.h"

NetworkCommunication::NetworkCommunication()
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



void  NetworkCommunication::startConnect()
{
    tcpClient->connectToHost(addr,port);
    tcpClient->waitForConnected(10000);
  //  tcpClient->write("goto");
    qDebug()<<"startConnect";
    writeData();
}

QString NetworkCommunication::getLocalIp()
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

void NetworkCommunication::writeData()
{
    QByteArray text="test write data";
    tcpClient->write(text);
}

void NetworkCommunication::onConnected()
{
    qDebug()<<"客户端已接入服务端";


}

void NetworkCommunication::onSocketReadyRead()
{

  qDebug()<<"onSocketReadyRead "<<tcpClient->readAll();
}

void Network::run() {
    NetworkCommunication& networkCommunication = NetworkCommunication::getInstance();
    networkCommunication.startConnect();
}
