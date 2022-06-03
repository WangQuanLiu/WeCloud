#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "framelessmainwindow.h"
#include <QColor>
#include <QRgb>
#include <QLabel>
#include <QPainter>
#include <QEvent>
namespace Ui {
class MainWindow;
}
class MQLabels;
class MQLabel{
public:
    friend MQLabels;
    MQLabel(QLabel*label,void(*clickFuncPtr)(void)){
        this->label=label;
        this->clickFuncPtr=clickFuncPtr;
    }
    MQLabel operator=(const MQLabel&obj){
        this->label=obj.label;
        this->clickFuncPtr=obj.clickFuncPtr;
        return *this;
    }
    QLabel* getLabel(){
        return this->label;
    }
    void (*getClickFuncPtr(void))(){
        return this->clickFuncPtr;
    }
    void setLabel( QLabel*label){
        this->label=label;
    }
    void setClickFuncPtr( void(*clickFuncPtr)(void)){
        this->clickFuncPtr=clickFuncPtr;
    }
private:
    QLabel*label;
    void (*clickFuncPtr)(void);
};
class MQLabels{
public:
    void push_back(MQLabel&label){
        labelVec.push_back(label);
    }
    void eventFilter(QObject*watched,QEvent*event){
        for(int i=0;i<labelVec.size();i++){
            if(watched==labelVec[i].label){
                if(event->type() == QEvent::MouseButtonPress){
                    labelVec[i].clickFuncPtr();
                }
            }
        }
    }
private:
    std::vector<MQLabel>labelVec;
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
};

#endif // MAINWINDOW_H
