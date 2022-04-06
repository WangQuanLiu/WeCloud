#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include<QTime>
#include<QDateTime>
enum  ENUM_Network_Massage {
ENUM_NetMsg_NULL=1,
ENUM_NetMsg_PassworkVerification_Request
};

class  NetworkMessage {
    friend class Message;
public:
    NetworkMessage() = default;
    ~NetworkMessage() = default;
    NetworkMessage(const  NetworkMessage& obj);
    NetworkMessage &operator=(const NetworkMessage&obj);
    explicit NetworkMessage(ENUM_Network_Massage msgType) {
        this->msgType = msgType;
    }
    explicit  NetworkMessage(ENUM_Network_Massage msgType, const QString& text) {
        this->msgType = msgType;
        this->data = text.toUtf8();
   }
    explicit  NetworkMessage(ENUM_Network_Massage msgType, const QByteArray& text) {
        this->msgType = msgType;
        this->data = text;
   }
    ENUM_Network_Massage getMsgType();
    QByteArray getData();
    void setMsgType(ENUM_Network_Massage msgType);
    void setData(const QByteArray& data);
protected:
    ENUM_Network_Massage msgType;//消息类型
    QByteArray data;
};

class Message:public NetworkMessage
{
public:
    explicit Message(){
         curDateTime = QDateTime::currentDateTime();
         id = curDateTime.toString("yyyy-MM-dd hh:mm:ss:zzz");
         tryCount = 1;
        }
    explicit Message(const NetworkMessage& obj) :Message(){
        this->msgType = obj.msgType;
        this->data = obj.data;
    }
    explicit Message(ENUM_Network_Massage msgType, const QString& text):Message() {
        this->msgType = msgType;
        this->data = text.toUtf8();
    }
    explicit Message(ENUM_Network_Massage msgType, const QByteArray& text) :Message() {
        this->msgType = msgType;
        this->data = text;
    }
    Message&operator++();
    Message&operator++(int val);
    Message& operator=(const Message& obj);
    QString getId();
    unsigned int getTryCount();
    ENUM_Network_Massage getMsgType();
    QByteArray getData();
   
private:
  void setId(const QString& id);
  QDateTime curDateTime;
  QString id;
  unsigned int tryCount;//尝试发送次数
  //NetworkMessage networkMessage;
};

#endif // MESSAGE_H
