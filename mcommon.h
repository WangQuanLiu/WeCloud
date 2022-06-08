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
namespace Common{
typedef std::function<void(void)>FuncPtr;

void setLabelPixmap(const QString&imagePath,QLabel*label);
void setLabelRoundRectPixmap(const QString&imagePath,QLabel*label,int radius);
class MQObject{
public:
    friend class MQObjects;
    MQObject()=default;
    MQObject(QLabel*object,FuncPtr unClickFuncPtr,FuncPtr clickFuncPtr,QEvent::Type eventType=QEvent::MouseButtonPress ){
        this->object=object;
        this->clickFuncPtr=clickFuncPtr;
        this->unClickFuncPtr=unClickFuncPtr;
        this->eventType=eventType;
    }
    MQObject operator=(const MQObject&obj){
        this->object=obj.object;
        this->clickFuncPtr=obj.clickFuncPtr;
        this->unClickFuncPtr=obj.unClickFuncPtr;
        this->eventType=obj.eventType;
        return *this;
    }
    void  eventFilter(QObject*watched,QEvent*event){
        if(watched==object){
            if(event->type()==eventType){
                   (this->clickFuncPtr)();
                isPressed=true;
            }
        }
    }
    void unClickFunc(){
        this->unClickFuncPtr();
        isPressed=false;
    }
    bool getIsPressed(){
        return isPressed;
    }
    void setObject( QLabel*object){
        this->object=object;
    }
    void setUnClickFuncPtr(FuncPtr unClickFuncPtr){
        this->unClickFuncPtr=unClickFuncPtr;
    }
    void setClickFuncPtr( FuncPtr clickFuncPtr){
        this->clickFuncPtr=clickFuncPtr;
    }
    void setEventType(QEvent::Type eventType){
        this->eventType=eventType;
    }
private:
    bool isPressed=false;
    QLabel*object;
    FuncPtr clickFuncPtr,unClickFuncPtr;
    QEvent::Type eventType;
};

class MQObjects{
public:
    using Object=MQObject;
    MQObjects()=default;
    MQObjects(std::initializer_list<Object>list){
        for(auto begin=list.begin();begin!=list.end();begin++){
            this->objectVec.push_back(*begin);
        }
    }
    void push_back(Object&object){
        objectVec.push_back(object);
    }
    void eventFilter(QObject*watched,QEvent*event){
       static int index=-1;
       int i;
        for( i=0;i<objectVec.size();i++){
            objectVec[i].eventFilter(watched,event);
            if(objectVec[i].getIsPressed()==true&&i!=index){
                //index=i;
                break;
            }
        }
        if(i!=index&&i<objectVec.size()){
            index=i;
        for(int j=0;j<objectVec.size();j++){
            if(index!=j){
                objectVec[j].unClickFunc();
            }
        }
        }
    }
private:
    std::vector<Object>objectVec;
};
}
using Common::FuncPtr;
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
    MQToolTips(){
        this->x=10;
        this->y=-18;
    }
    MQToolTips(std::initializer_list<MQToolTip>list){
        for(auto begin=list.begin();begin!=list.end();begin++){
            this->toolTips.push_back(*begin);
        }
        this->x=10;
        this->y=-18;
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
                        int x=QCursor::pos().x()+this->x;
                        int y=QCursor::pos().y()+this->y;
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
    int x,y;
};

bool readQss(const QString&QssFilename,QWidget*ptr);
void setLabelFontSize( QLabel* lineEdit,unsigned fontSize);
void setNormalShowScale();

void initTooltip();
#endif // MCOMMON_H
