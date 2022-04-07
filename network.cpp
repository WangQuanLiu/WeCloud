#include "network.h"

NetworkCommunication::NetworkCommunication()
{
    tcpClient = new QTcpSocket(this);
    connect(tcpClient, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(tcpClient, SIGNAL(disconnected()), this, SLOT(onDisConnected()));
    connect(tcpClient, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
        this, SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));
    connect(tcpClient, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
   // qDebug<<"netWork constructor";
    
    addr= getLocalIp();
  
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

void NetworkCommunication::addData(Message* msg)
{
    msgList.push_back(msg);
}

void NetworkCommunication::addData(Message msg)
{

    msgList.push_back(new Message(msg));
}


void NetworkCommunication::writeData( )
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
    Message msg(ENUM_NetMsg_PassworkVerification_Request, "245");
   QByteArray temp = msg.getData();
    tcpClient->write(temp);
    
   //writeData();
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



void Network::writeData()
{
    networkCommunication->writeData();
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
