#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include<QTime>
#include<QDateTime>
//#include<network.h>
enum  ENUM_Network_Massage {
ENUM_NetMsg_NULL=1,
ENUM_NetMsg_PassworkVerification_Request
};

class  NetworkMessage {
   // friend NetworkCommunication;
public:
    NetworkMessage() = default;
    ~NetworkMessage() = default;
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
protected:
    void setMsgType(ENUM_Network_Massage msgType);
    void setData(const QByteArray& data);
    ENUM_Network_Massage msgType;//消息类型
    QByteArray data;
};

class Message:public NetworkMessage
{
  //  friend class NetworkCommunication;
public:

    explicit Message();
    Message&operator++();
    Message&operator++(int val);
    Message& operator=(const Message& obj);
    QString getId();
    unsigned int getTryCount();
    ENUM_Network_Massage getMsgType();
    QByteArray& getData();
   
private:
  void setId(const QString& id);
  QDateTime curDateTime;
  QString id;
  unsigned int tryCount;
  //NetworkMessage networkMessage;
};

#endif // MESSAGE_H
