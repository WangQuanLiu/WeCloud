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
#include <QPainter>
#include <QPainterPath>
class MCommon
{
public:
    MCommon();
};
enum QEnumMessage {QEnumMsg_Login,QEnumMsg_SendMsg,QEnumMsg_Register};


bool readQss(const QString&QssFilename,QWidget*ptr);
void setLabelFontSize( QLabel* lineEdit,unsigned fontSize);
void setNormalShowScale();
QPixmap pixmapScale(const QPixmap &image, const int &width,const int &heignt);
QPixmap getRoundRectPixmap(QPixmap pixmap,int radius);

#endif // MCOMMON_H
