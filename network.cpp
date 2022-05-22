#include "network.h"

NetworkCommunication::NetworkCommunication()
{
    tcpClient = new QTcpSocket(this);
    connect(tcpClient, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(tcpClient, SIGNAL(disconnected()), this, SLOT(onDisConnected()));
    connect(tcpClient, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
        this, SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));
    connect(tcpClient, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
    addr= getLocalIp();
}

/*
 *
 * 功能：开始与服务器连接
 *
 */

void  NetworkCommunication::startConnect()
{
    addr=getLocalIp();
    tcpClient->connectToHost(addr,port);
    tcpClient->waitForConnected(1000);
}
/*
 * 功能：获取本地Ip
 * 输出：返回本地IPv4地址
 */
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

void NetworkCommunication::addData(Message* msg)
{
    msgList.push_back(msg);
}

void NetworkCommunication::addData(Message msg)
{

    msgList.push_back(new Message(msg));
}


void NetworkCommunication::sendData( )
{
    if (msgList.size() <= 0)return;
    for (auto msg : msgList) {
        (*msg)++;
        tcpClient->write(msg->getData());
    }
    tcpClient->waitForBytesWritten(3000);
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
    networkCommunication = new NetworkCommunication();
    networkCommunication->startConnect();
    exec();//事件循环
  
}



void Network::sendData()
{
    networkCommunication->sendData();
}

void Network::stop()
{
   terminate();
    wait();
   
}

void Network::addData(Message* msg)
{
    networkCommunication->addData(msg);
}

void Network::addData(Message& msg)
{
    networkCommunication->addData(msg);
}

Network::Network() {
 
}
