#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mcommon.h"
#pragma execution_character_set("utf-8")
MainWindow::MainWindow(QWidget *parent) : FramelessMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->initForm();
    initFilter();
    init();

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    menuLeftobjects.eventFilter(watched,event);
    if(watched==this){
        if(event->type()==QEvent::WindowStateChange||
                event->type()==QEvent::Resize){
           ui->widgetLeft->resize(ui->widgetLeft->width(),ui->widgetMain->height());
        }

    }
    else if(watched==ui->menuLeftCalendar){
        if(event->type()==QEvent::ToolTip){
            int x=QCursor::pos().x()+10;
            int y=QCursor::pos().y()-18;
            QPoint point;
            point.setX(x);
            point .setY(y);
           QToolTip::showText(point,"日历",ui->menuLeftCalendar);
        }
    }
   else if(watched==ui->labelMenuMin){
        if(event->type()==QEvent::MouseButtonPress){
            labelMin_Clicked();
        }
    }
    else if(watched==ui->labelMenuMax){
        if(event->type()==QEvent::MouseButtonPress){
            labelMax_Clicked();
        }
    }
    else if(watched==ui->labelMenuClose){
        if(event->type()==QEvent::MouseButtonPress){
            labelClose_Clicked();
        }
    }

    return QMainWindow::eventFilter(watched,event);//交给上层
}

void MainWindow::showEvent(QShowEvent *event)
{
    //解决有时候窗体重新显示的时候假死不刷新的BUG
    setAttribute(Qt::WA_Mapped);
    QMainWindow::showEvent(event);
}

void MainWindow::setLabelPixmap(const QString &imagePath, QLabel *label)
{
    QPixmap pixmap;
    if(!pixmap.load(imagePath))return ;
    QPixmap newPixmap=pixmapScale(pixmap, label->width(),label->height());
    label->setPixmap(newPixmap);
}

void MainWindow::setLabelRoundRectPixmap(const QString &imagePath, QLabel *label)
{
    QPixmap pixmap;
    if(!pixmap.load(imagePath))return ;
    QPixmap newPixmap=pixmapScale(pixmap, label->width(),label->height());
    newPixmap=getRoundRectPixmap(newPixmap,5);
    label->setPixmap(newPixmap);
}

void MainWindow::labelMin_Clicked()
{
#ifdef Q_OS_MACOS
    this->setWindowFlags(this->windowFlags() & ~Qt::FramelessWindowHint);
#endif
    this->showMinimized();

}

void MainWindow::labelMax_Clicked()
{
    if(this->isMaximized()){
       this->showNormal();
     }
    else{
        this->showMaximized();
      }
}

void MainWindow::labelClose_Clicked()
{

    this->close();
}

void MainWindow::menuLeftMessage_Clicked()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuLeft/message_click.png",ui->menuLeftMessage);
}

void MainWindow::menuLeftContact_Clicked()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuLeft/contact_click.png",ui->menuLeftContact);
}

void MainWindow::menuLeftDocument_Clicked()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuLeft/document_click.png",ui->menuLeftDocument);
}

void MainWindow::menuLeftMeet_clicked()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuLeft/meet_click.png",ui->menuLeftMeet);
}

void MainWindow::menuLeftCloud_clicked()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuLeft/cloud_click.png",ui->menuLeftCloud);
}

void MainWindow::menuleftCalendar_clicked()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuLeft/calendar_click.png",ui->menuLeftCalendar);
}

void MainWindow::menuLeftSchedule_clicked()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuLeft/schedule_click.png",ui->menuLeftSchedule);
}

void MainWindow::menuLeftSetting_clicked()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuLeft/setting_click.png",ui->menuLeftSetting);
}

void MainWindow::menuLeftCalendar_unClicked()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuLeft/calendar.png",ui->menuLeftCalendar);
}

void MainWindow::menuLeftMessage_unClicked()
{
    setLabelPixmap(":images/mainWindow/menuLeft/message.png",ui->menuLeftMessage);
}

void MainWindow::menuLeftContact_unClicked()
{
    setLabelPixmap(":images/mainWindow/menuLeft/contact.png",ui->menuLeftContact);
}

void MainWindow::menuLeftDocument_unClicked()
{
    setLabelPixmap(":images/mainWindow/menuLeft/document.png",ui->menuLeftDocument);
}

void MainWindow::menuLeftMeet_unClicked()
{
    setLabelPixmap(":images/mainWindow/menuLeft/meet.png",ui->menuLeftMeet);
}

void MainWindow::menuLeftCloud_unClicked()
{
    setLabelPixmap(":images/mainWindow/menuLeft/cloud.png",ui->menuLeftCloud);
}

void MainWindow::menuLeftSchedule_unClicked()
{
    setLabelPixmap(":images/mainWindow/menuLeft/schedule.png",ui->menuLeftSchedule);
}

void MainWindow::menuLeftSetting_unClicked()
{
    setLabelPixmap(":images/mainWindow/menuLeft/setting.png",ui->menuLeftSetting);
}

void MainWindow::initFilter()
{
    ui->labelMenuMin->installEventFilter(this);
    ui->labelMenuMax->installEventFilter(this);
    ui->labelMenuClose->installEventFilter(this);
    ui->menuLeftMessage->installEventFilter(this);
    ui->menuLeftContact->installEventFilter(this);
    ui->menuLeftDocument->installEventFilter(this);
    ui->menuLeftMeet->installEventFilter(this);
    ui->menuLeftCloud->installEventFilter(this);
    ui->menuLeftCalendar->installEventFilter(this);
    ui->menuLeftSchedule->installEventFilter(this);
    ui->menuLeftSetting->installEventFilter(this);
    this->installEventFilter(this);

  //  ui->menuLeftCalendar->setToolTip("日历");
}



void MainWindow::init()
{

    QPalette pe;
    pe.setColor(QPalette::Background,Qt::black);
    pe.setColor(QPalette::WindowText,Qt::white);
    ui->label->setPalette(pe);
    QColor color;
    color.setRgb(235,235,235);
    pe.setColor(QPalette::Background,color);
    ui->widgetLeft->setAutoFillBackground(true);
    ui->widgetLeft->setPalette(pe);
    ui->widgetLeft->setMouseTracking(true);
    initLabelPixmap();
    menuLeftobjects={MQObject(ui->menuLeftMessage,std::bind(&MainWindow::menuLeftMessage_unClicked,this),std::bind(&MainWindow::menuLeftMessage_Clicked,this)),
             MQObject(ui->menuLeftContact,std::bind(&MainWindow::menuLeftContact_unClicked,this),std::bind(&MainWindow::menuLeftContact_Clicked,this)),
             MQObject(ui->menuLeftDocument,std::bind(&MainWindow::menuLeftDocument_unClicked,this),std::bind(&MainWindow::menuLeftDocument_Clicked,this)),
             MQObject(ui->menuLeftMeet,std::bind(&MainWindow::menuLeftMeet_unClicked,this),std::bind(&MainWindow::menuLeftMeet_clicked,this)),
             MQObject(ui->menuLeftCloud,std::bind(&MainWindow::menuLeftCloud_unClicked,this),std::bind(&MainWindow::menuLeftCloud_clicked,this)),
             MQObject(ui->menuLeftCalendar,std::bind(&MainWindow::menuLeftCalendar_unClicked,this),std::bind(&MainWindow::menuleftCalendar_clicked,this)),
             MQObject(ui->menuLeftSchedule,std::bind(&MainWindow::menuLeftSchedule_unClicked,this),std::bind(&MainWindow::menuLeftSchedule_clicked,this)),
             MQObject(ui->menuLeftSetting,std::bind(&MainWindow::menuLeftSetting_unClicked,this),std::bind(&MainWindow::menuLeftSetting_clicked,this))};

}

void MainWindow::initLabelPixmap()
{
    //setLabelPixmap(":images/menuLeftMessage.png",ui->labelMenuLeftMessage);
    //setLabelPixmap(":images/menuLeftContact.png",ui->labelMenuLeftContact);
    menuLeftMessage_unClicked();
    menuLeftContact_unClicked();
    menuLeftDocument_unClicked();
    menuLeftMeet_unClicked();
    menuLeftCloud_unClicked();
    menuLeftCalendar_unClicked();
    menuLeftSchedule_unClicked();
    menuLeftSetting_unClicked();
}

void MainWindow::initForm()
{
    this->resize(QSize(950,600));
    //设置标题栏控件
   // ui->lineEditMenuSearch->setText(" ");
   // this->setWindowTitle(ui->lineEditMenuSearch->text());
    this->setTitleBar(ui->titleBar);
    //关联信号
    connect(this, SIGNAL(titleDblClick()), this, SLOT(titleDblClick()));
    connect(this, SIGNAL(windowStateChange(bool)), this, SLOT(windowStateChange(bool)));
    readQss("mainWindow.qss",this);


}

void MainWindow::titleDblClick()
{
    labelMax_Clicked();
}





