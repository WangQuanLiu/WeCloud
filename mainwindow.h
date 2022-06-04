#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "framelessmainwindow.h"
#include <QColor>
#include <QRgb>
#include <QLabel>
#include <QPainter>
#include <QEvent>
#include <initializer_list>
namespace Ui {
class MainWindow;
class MQObjects;
class MQObject;
/*
template<typename T>

template<typename T>

*/
typedef std::function<void(void)>FuncPtr;
}
using Ui::FuncPtr;
class MQObject{
public:
   // friend MQObjects<T>;
    MQObject()=default;
    MQObject(QLabel*object,FuncPtr unClickFuncPtr,FuncPtr clickFuncPtr){
        this->object=object;
        this->clickFuncPtr=clickFuncPtr;
        this->unClickFuncPtr=unClickFuncPtr;
    }
    MQObject operator=(const MQObject&obj){
        this->object=obj.object;
        this->clickFuncPtr=obj.clickFuncPtr;
        this->unClickFuncPtr=obj.unClickFuncPtr;
        return *this;
    }
    void  eventFilter(QObject*watched,QEvent*event){
        if(watched==object){
            if(event->type()==QEvent::MouseButtonPress){
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
private:
    bool isPressed=false;
    QLabel*object;
    FuncPtr clickFuncPtr,unClickFuncPtr;
};

class MQObjects{
public:
    using Object=MQObject;
    MQObjects()=default;
    MQObjects(std::initializer_list<Object>list){
        for(auto begin=list.begin();begin!=list.end();begin++)
            this->objectVec.push_back(*begin);
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

class MainWindow : public FramelessMainWindow
{
    Q_OBJECT

public:

    friend class MQObject;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
      bool eventFilter(QObject*,QEvent*);
private:
      void setLabelPixmap(const QString&imagePath,QLabel*label);
      void setLabelRoundRectPixmap(const QString&imagePath,QLabel*label);
      void labelMin_Clicked();
      void labelMax_Clicked();
      void labelClose_Clicked();
      void labelMenuLeftMessage_Clicked();
      void labelMenuLeftContact_Clicked();
      void labelMenuLeftMessage_unClicked();
      void labelMenuLeftContact_unClicked();
      void initFilter();
      void init();
      void initLabelPixmap();
private slots:
    void initForm();
    void titleDblClick();
private:
    MQObjects menuLeftobjects;
};

#endif // MAINWINDOW_H
