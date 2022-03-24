#ifndef MCOMMON_H
#define MCOMMON_H
#include<QObject>
#include<QString>
#include<QFile>
#include<QTextStream>
#include<QDialog>
class MCommon
{
public:
    MCommon();
};
enum QEnumMessage {QEnumMsg_Login,QEnumMsg_SendMsg,QEnumMsg_Register};
class Message{
    QEnumMessage QEnumMsg;
    QString sendAccount;
};

class UserAccountVerification:public Message{
    QString userName;
    QString password;
};
class SendMsg:public Message{
    QString receiveAccount;
    QString sendText;
};

bool readQss(const QString&QssFilename,QDialog*ptr);
#endif // MCOMMON_H
