#include "message.h"

Message &Message::operator++()
{
    this->tryCount++;
    return *this;
}
Message &Message::operator++(int){
    Message temp=*this;
    this->tryCount++;
    return temp;
}
Message& Message::operator=(const Message& obj)
{
    this->id = obj.id;
    this->msgType = obj.msgType;
    this->data = obj.data;
    this->tryCount = obj.tryCount;
    return *this;
}
QString Message::getId()
{
    return id;
}
unsigned int Message::getTryCount()
{
    return tryCount;
}
ENUM_Network_Massage Message::getMsgType()
{
    return getMsgType();
}
QByteArray Message::getData()
{
    QByteArray data;
    data.append("id:");
    data.append(id.toStdString().c_str());
    data.append('\n');
    data.append("type:");
    data.append(QString::number(msgType).toStdString().c_str());
    data.append('\n');
    data.append("data:" + this->data);
    return data;
}
void Message::setId(const QString& id)
{
    this->id = id;
}
NetworkMessage::NetworkMessage(const NetworkMessage& obj)
{
    *this = obj;
}
NetworkMessage &NetworkMessage::operator=(const NetworkMessage &obj)
{
    this->msgType=obj.msgType;
    this->data=obj.data;
   return *this;
}

ENUM_Network_Massage NetworkMessage::getMsgType()
{
    return msgType;
}

QByteArray NetworkMessage::getData()
{
    return data;
}

void NetworkMessage::setMsgType(ENUM_Network_Massage msgType)
{
    this->msgType = msgType;
}

void NetworkMessage::setData(const QByteArray &data)
{
    this->data=data;
}
