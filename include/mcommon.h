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


bool readQss(const QString&QssFilename,QDialog*ptr);
#endif // MCOMMON_H
