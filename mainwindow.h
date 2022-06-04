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
}
template<typename T>
class MQObjects;
template<typename T>
class MQObject{
public:
    friend MQObjects<T>;
    MQObject(T*object,void(*clickFuncPtr)(void)){
        this->object=object;
        this->clickFuncPtr=clickFuncPtr;
    }
    MQObject operator=(const MQObject&obj){
        this->object=obj.object;
        this->clickFuncPtr=obj.clickFuncPtr;
        return *this;
    }
    void  eventFilter(QObject*watched,QEvent*event){
        if(watched==object){
            if(event->type()==QEvent::MouseButtonPress){
                   this->clickFuncPtr();
            }
        }
    }
    T* getLabel(){
        return this->object;
    }
    void (*getClickFuncPtr(void))(){
        return this->clickFuncPtr;
    }
    void setLabel( T*object){
        this->object=object;
    }
    void setClickFuncPtr( void(*clickFuncPtr)(void)){
        this->clickFuncPtr=clickFuncPtr;
    }
private:
    T*object;
    void (*clickFuncPtr)();
};
template<typename T>
class MQObjects{
public:
    MQObjects()=default;
    MQObjects(std::initializer_list<MQObject<T>>list){
        for(auto begin=list.begin();begin!=list.end();begin++)
            this->objectVec.push_back(*begin);
    }
    void push_back(MQObject<T>&object){
        objectVec.push_back(object);
    }
    void eventFilter(QObject*watched,QEvent*event){
        for(int i=0;i<objectVec.size();i++){
            objectVec[i].eventFilter();
        }
    }
private:
    std::vector<MQObject<T>>objectVec;
};

class MainWindow : public FramelessMainWindow
{
    Q_OBJECT

public:
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
      void initFilter();
      void init();
      void initLabelPixmap();
private slots:
    void initForm();
    void titleDblClick();
private:
    MQObjects<QLabel> mqlabes;
};

#endif // MAINWINDOW_H
