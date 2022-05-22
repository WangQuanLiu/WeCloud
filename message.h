#ifndef MESSAGE_H
#define MESSAGE_H
#include<string>
#include <QObject>
#include<QTime>
#include<QDateTime>
enum  ENUM_Network_Massage {
ENUM_NetMsg_NULL=1,
ENUM_NetMsg_PassworkVerification_Request
};
#define MSG_ID_BEGIN "<Id>"
#define MSG_ID_END "</Id>"
#define MSG_ID(X) MSG_ID_BEGIN+QString(X)+MSG_ID_END

#define MSG_TYPE_BEGIN "<Type>"
#define MSG_TYPE_END "</Type>"
#define MSG_TYPE(X) MSG_TYPE_BEGIN+QString(X)+MSG_TYPE_END

#define MSG_ACCOUNT_BEGIN "<Account>"
#define MSG_ACCOUNT_END "</Account>"
#define MSG_ACCOUNT(X) MSG_ACCOUNT_BEGIN+QString(X)+MSG_ACCOUNT_END

#define MSG_PASSWORD_BEGIN "<Password>"
#define MSG_PASSWORD_END "</Password>"
#define MSG_PASSWORD(X) MSG_PASSWORD_BEGIN+QString(X)+MSG_PASSWORD_END

#define MSG_DATA_BEGIN "<Data>"
#define MSG_DATA_END "</Data>"
#define MSG_DATA(X) MSG_DATA_BEGIN+QString(X)+MSG_DATA_END

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
    QByteArray data;//消息数据
};
/*
 * Message为消息类包括
 * msgType 消息类型
 * data 消息数据
 * id 数据的序号
 * curDataTime发送时间
 * tryCount 尝试发送消息的次数
 */
class Message:public NetworkMessage
{
public:
    explicit Message(){
         curDateTime = QDateTime::currentDateTime();
         id = curDateTime.toString("yyyy-MM-dd-hh:mm:ss:zzz");
         tryCount = 0;
        }
    explicit Message(const NetworkMessage& obj) :Message(){
        this->msgType = obj.msgType;
        this->data = obj.data;
    }
     Message(ENUM_Network_Massage msgType, const QString& text):Message() {
        this->msgType = msgType;
        this->data = text.toUtf8();
    }
    explicit Message(ENUM_Network_Massage msgType, const QByteArray& text) :Message() {
        this->msgType = msgType;
        this->data = text;
    }
    explicit  Message(ENUM_Network_Massage msgType, const char* text) {
        this->msgType = msgType;
        this->data = text;
    }
    Message&operator++();
    Message operator++(int val);
    Message& operator=(const Message* obj);
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
