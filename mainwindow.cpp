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
        if(event->type()==QEvent::WindowStateChange){
            ui->widgetLeft->resize(ui->widgetLeft->width(),ui->widgetMain->height());
        }
        else if(event->type()==QEvent::Resize){
            ui->widgetLeft->resize(ui->widgetLeft->width(),ui->widgetMain->height());
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
    newPixmap=getRoundRectPixmap(newPixmap,8);
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

void MainWindow::labelMenuLeftMessage_Clicked()
{
    setLabelRoundRectPixmap(":images/menuLeftMessage_click.png",ui->labelMenuLeftMessage);
}

void MainWindow::labelMenuLeftContact_Clicked()
{
    setLabelRoundRectPixmap(":images/menuLeftContact_click.png",ui->labelMenuLeftContact);
}

void MainWindow::labelMenuLeftMessage_unClicked()
{
    setLabelPixmap(":images/menuLeftMessage.png",ui->labelMenuLeftMessage);
}

void MainWindow::labelMenuLeftContact_unClicked()
{
     setLabelPixmap(":images/menuLeftContact.png",ui->labelMenuLeftContact);
}

void MainWindow::initFilter()
{
    ui->labelMenuMin->installEventFilter(this);
    ui->labelMenuMax->installEventFilter(this);
    ui->labelMenuClose->installEventFilter(this);
    ui->labelMenuLeftMessage->installEventFilter(this);
    ui->labelMenuLeftContact->installEventFilter(this);
    this->installEventFilter(this);
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

    initLabelPixmap();
    menuLeftobjects={MQObject(ui->labelMenuLeftMessage,std::bind(&MainWindow::labelMenuLeftMessage_unClicked,this),std::bind(&MainWindow::labelMenuLeftMessage_Clicked,this)),
             MQObject(ui->labelMenuLeftContact,std::bind(&MainWindow::labelMenuLeftContact_unClicked,this),std::bind(&MainWindow::labelMenuLeftContact_Clicked,this))};

}

void MainWindow::initLabelPixmap()
{
    //setLabelPixmap(":images/menuLeftMessage.png",ui->labelMenuLeftMessage);
    //setLabelPixmap(":images/menuLeftContact.png",ui->labelMenuLeftContact);
    labelMenuLeftMessage_unClicked();
    labelMenuLeftContact_unClicked();
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





