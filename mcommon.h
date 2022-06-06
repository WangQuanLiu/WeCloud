#ifndef MCOMMON_H
#define MCOMMON_H
#include "qcoreevent.h"
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
#include <QToolTip>
class MCommon
{
public:
    MCommon();
};
enum QEnumMessage {QEnumMsg_Login,QEnumMsg_SendMsg,QEnumMsg_Register};
class MQToolTips;
class MQToolTip{
public:
    MQToolTip()=default;
    MQToolTip(QWidget*widget,const QString&text){
        this->widget=widget;
        this->text=text;
    }
    MQToolTip operator=(const MQToolTip&obj){
        this->widget=obj.widget;
        this->text=obj.text;
        return *this;
    }
    QWidget*getQWidget(){
        return widget;
    }
    QString getText(){
        return text;
    }
 private:
    QWidget*widget;
    QString text;
};
class MQToolTips{
public:
    MQToolTips()=default;
    MQToolTips(std::initializer_list<MQToolTip>list){
        for(auto begin=list.begin();begin!=list.end();begin++){
            this->toolTips.push_back(*begin);
        }
    }
    void push_back(MQToolTip&object){
        toolTips.push_back(object);
    }
    void set_currentPosition_difference_x(int x){
       this->x=x;
    }
    void set_currentPosition_difference_y(int y){
        this->y=y;
    }
    void eventFilter(QObject*watched,QEvent*event){
            for(int i=0;i<toolTips.size();i++){
                QWidget*widget=toolTips[i].getQWidget();
                QString text=toolTips[i].getText();
                if(watched==widget){
                    if(event->type()==QEvent::ToolTip){
                        int x=QCursor::pos().x()+x;
                        int y=QCursor::pos().y()+y;
                        QPoint point;
                        point.setX(x);
                        point .setY(y);
                       QToolTip::showText(point,text,widget);
                    }
                }
            }
    }
private:
    QList<MQToolTip> toolTips;
    int x=0,y=0;
};

bool readQss(const QString&QssFilename,QWidget*ptr);
void setLabelFontSize( QLabel* lineEdit,unsigned fontSize);
void setNormalShowScale();
QPixmap pixmapScale(const QPixmap &image, const int &width,const int &heignt);
QPixmap getRoundRectPixmap(QPixmap pixmap,int radius);
void initTooltip();
#endif // MCOMMON_H
