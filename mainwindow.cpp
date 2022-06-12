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
    toolTips.eventFilter(watched,event);

    if(watched==this){
        if(event->type()==QEvent::WindowStateChange||
                event->type()==QEvent::Resize){
           ui->widgetLeft->resize(ui->widgetLeft->width(),ui->widgetMain->height());
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





    return QMainWindow::eventFilter(watched,event);//�����ϲ�
}

void MainWindow::showEvent(QShowEvent *event)
{
    //�����ʱ����������ʾ��ʱ�������ˢ�µ�BUG
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
  //  menuAddDialog->show();
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

  //  ui->menuLeftCalendar->setToolTip("����");
}



void MainWindow::init()
{

    QPalette pe;
    pe.setColor(QPalette::Background,Qt::black);
    pe.setColor(QPalette::WindowText,Qt::white);
   // ui->label->setPalette(pe);
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
 //   toolTips.set_currentPosition_difference_x(50);
 //   toolTips.set_currentPosition_difference_y(-10);
    toolTips={MQToolTip(ui->menuLeftMessage,"��Ϣ"),
              MQToolTip(ui->menuLeftContact,"ͨѶ¼"),
              MQToolTip(ui->menuLeftDocument,"�ĵ�"),
              MQToolTip(ui->menuLeftMeet,"����"),
              MQToolTip(ui->menuLeftCloud,"����"),
              MQToolTip(ui->menuLeftCalendar,"�ճ�"),
              MQToolTip(ui->menuLeftSchedule,"����"),
              MQToolTip(ui->menuLeftSetting,"����")};
    menuAddDialog=new MenuAddDialog();
    accountPictureDialog=new AccountPictureDialog();
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
    labelAccountPicture_unClicked();
}

void MainWindow::initForm()
{
    this->resize(QSize(950,600));
    //���ñ������ؼ�
   // ui->lineEditMenuSearch->setText(" ");
   // this->setWindowTitle(ui->lineEditMenuSearch->text());
    this->setTitleBar(ui->titleBar);
    //�����ź�
    connect(this, SIGNAL(titleDblClick()), this, SLOT(titleDblClick()));
    connect(this, SIGNAL(windowStateChange(bool)), this, SLOT(windowStateChange(bool)));
    readQss("mainWindow.qss",this);


}

void MainWindow::titleDblClick()
{
    labelMax_Clicked();
}





