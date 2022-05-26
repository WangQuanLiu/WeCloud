#ifndef MCOMMON_H
#define MCOMMON_H
#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDialog>
#include <Windows.h>
#include <WinUser.h>
#include <wingdi.h>
#include <QDir>
#include <QLabel>
class MCommon
{
public:
    MCommon();
};
enum QEnumMessage {QEnumMsg_Login,QEnumMsg_SendMsg,QEnumMsg_Register};


bool readQss(const QString&QssFilename,QDialog*ptr);
void setLabelFontSize( QLabel* lineEdit,unsigned fontSize);
void setNormalShowScale();
#endif // MCOMMON_H
