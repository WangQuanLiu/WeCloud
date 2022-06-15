#include "mainwindow.h"
#include "qpushbutton.h"
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
    toolTips.eventFilter(watched,event);

    if(watched==this){
        if(event->type()==QEvent::WindowStateChange||
                event->type()==QEvent::Resize){
           ui->widgetLeft->resize(ui->widgetLeft->width(),ui->widgetMain->height());
            this->stackedWidgetPageResize(ui->stackedWidget->currentWidget());
        }

    }
    else if(event->type()==QEvent::MouseButtonPress){
        if(watched==ui->labelMenuMin)
            labelMin_Clicked();
        else if(watched==ui->labelMenuMax)
            labelMax_Clicked();
        else if(watched==ui->labelMenuClose)
            labelClose_Clicked();
        else if(watched==ui->labelMenuAdd)
            labelMenuAdd_Clicked();
        else if(watched==ui->labelAccountPicture)
            labelAccountPicture_Clicked();

    }





    return QMainWindow::eventFilter(watched,event);//交给上层
}

void MainWindow::showEvent(QShowEvent *event)
{
    //解决有时候窗体重新显示的时候假死不刷新的BUG
    setAttribute(Qt::WA_Mapped);
    QMainWindow::showEvent(event);
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

void MainWindow::labelMenuAdd_Clicked()
{
    QPoint point=ui->labelMenuAdd->pos();
    int x,y;
    x=this->frameGeometry().x()+ui->titleBar->width()-480;
    y=this->frameGeometry().y()+ui->titleBar->height()-11;
    menuAddDialog->move(QPoint(x,y));
    menuAddDialog->showed();
}

void MainWindow::labelAccountPicture_Clicked()
{
    int x,y;
    x=this->x();
    y=this->frameGeometry().y()+ui->titleBar->height()-11;
    accountPictureDialog->move(QPoint(x,y));
    accountPictureDialog->show();
}


void MainWindow::labelAccountPicture_unClicked()
{
    setLabelRoundRectPixmap(":images/accountPicture.jpg",ui->labelAccountPicture,10);
}

void MainWindow::menuLeftMessage_Clicked()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuLeft/message_click.png",ui->menuLeftMessage,5);
    ui->stackedWidget->setCurrentWidget(ui->pageMessage);
}

void MainWindow::menuLeftContact_Clicked()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuLeft/contact_click.png",ui->menuLeftContact,5);
}

void MainWindow::menuLeftDocument_Clicked()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuLeft/document_click.png",ui->menuLeftDocument,5);
}

void MainWindow::menuLeftMeet_clicked()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuLeft/meet_click.png",ui->menuLeftMeet,5);
}

void MainWindow::menuLeftCloud_clicked()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuLeft/cloud_click.png",ui->menuLeftCloud,5);
}

void MainWindow::menuleftCalendar_clicked()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuLeft/calendar_click.png",ui->menuLeftCalendar,5);
}

void MainWindow::menuLeftSchedule_clicked()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuLeft/schedule_click.png",ui->menuLeftSchedule,5);
}

void MainWindow::menuLeftSetting_clicked()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuLeft/setting_click.png",ui->menuLeftSetting,5);
}

void MainWindow::menuLeftCalendar_unClicked()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuLeft/calendar.png",ui->menuLeftCalendar,5);
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
    ui->labelMenuAdd->installEventFilter(this);

    ui->menuLeftMessage->installEventFilter(this);
    ui->menuLeftContact->installEventFilter(this);
    ui->menuLeftDocument->installEventFilter(this);
    ui->menuLeftMeet->installEventFilter(this);
    ui->menuLeftCloud->installEventFilter(this);
    ui->menuLeftCalendar->installEventFilter(this);
    ui->menuLeftSchedule->installEventFilter(this);
    ui->menuLeftSetting->installEventFilter(this);
    ui->labelAccountPicture->installEventFilter(this);
    this->installEventFilter(this);


}



void MainWindow::init()
{

    QPalette pe;
    pe.setColor(QPalette::Background,Qt::black);
    pe.setColor(QPalette::WindowText,Qt::white);

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

    toolTips={MQToolTip(ui->menuLeftMessage,"消息"),
              MQToolTip(ui->menuLeftContact,"通讯录"),
              MQToolTip(ui->menuLeftDocument,"文档"),
              MQToolTip(ui->menuLeftMeet,"会议"),
              MQToolTip(ui->menuLeftCloud,"云盘"),
              MQToolTip(ui->menuLeftCalendar,"日程"),
              MQToolTip(ui->menuLeftSchedule,"待办"),
              MQToolTip(ui->menuLeftSetting,"设置")};
    menuAddDialog=new MenuAddDialog();
    accountPictureDialog=new AccountPictureDialog();
    initPageMessageScrollArea();
    menuLeftMessage_Clicked();
    this->messageBoxs.setScrollArea(ui->pageMessageScrollArea);
    this->messageBoxs.setWidget(this);
}

void MainWindow::initPageMessageScrollArea()
{
    ui->pageMessageScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->pageMessageScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

     QVBoxLayout* layout=new QVBoxLayout;
     if(layout==nullptr)return;
     layout->addSpacing(0);
     MMessageBox*message=new MMessageBox();
     message->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");

     MMessageBox*message2=new MMessageBox();
     message2->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","321","321","","12:30");

     MMessageBox*message3=new MMessageBox();
     message3->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
     MMessageBox*message4=new MMessageBox();
     message4->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
     MMessageBox*message5=new MMessageBox();
     message5->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
     MMessageBox*message6=new MMessageBox();
     message6->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
     MMessageBox*message7=new MMessageBox();
     message7->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
     MMessageBox*message8=new MMessageBox();
     message8->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
     MMessageBox*message9=new MMessageBox();
     message9->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
     MMessageBox*message10=new MMessageBox();
     message10->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
     MMessageBox*message11=new MMessageBox();
     message11->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");

   // addMMessageBox(message);
   // addMMessageBox(message2);
   // addMMessageBox(message3);
  //  addMMessageBox(message4);
  //  addMMessageBox(message5);
  //  addMMessageBox(message6);
  //  addMMessageBox(message7);
   // addMMessageBox(message8);
  //  addMMessageBox(message9);
  //  addMMessageBox(message10);
       this->messageBoxs.addMMessageBox(message);
       this->messageBoxs.addMMessageBox(message2);
       this->messageBoxs.addMMessageBox(message3);
       this->messageBoxs.addMMessageBox(message4);
       this->messageBoxs.addMMessageBox(message5);
       this->messageBoxs.addMMessageBox(message6);
       this->messageBoxs.addMMessageBox(message7);
       this->messageBoxs.addMMessageBox(message8);
       this->messageBoxs.addMMessageBox(message9);
     ui->pageMessageScrollArea->widget()->setLayout(this->messageBoxs.getLayout());

     ui->pageMessageScrollArea->setFrameShape(QFrame::NoFrame);


}

void MainWindow::initLabelPixmap()
{

    menuLeftMessage_unClicked();
    menuLeftContact_unClicked();
    menuLeftDocument_unClicked();
    menuLeftMeet_unClicked();
    menuLeftCloud_unClicked();
    menuLeftCalendar_unClicked();
    menuLeftSchedule_unClicked();
    menuLeftSetting_unClicked();
    labelAccountPicture_unClicked();
}

void MainWindow::stackedWidgetPageResize(QWidget *widget)
{
    if(widget==nullptr)return;
    if(widget==ui->pageMessage){
        ui->stackedWidget->resize(ui->stackedWidget->width(),ui->widgetMain->height());
        ui->pageMessage->resize(ui->pageMessage->width(),ui->widgetMain->height());
        ui->pageMessageScrollArea->resize(ui->pageMessageScrollArea->width(),ui->widgetMain->height());
        ui->pageMessageScrollAreaWidgetContents->resize(ui->pageMessageScrollAreaWidgetContents->width(),ui->widgetMain->height());

    }
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






