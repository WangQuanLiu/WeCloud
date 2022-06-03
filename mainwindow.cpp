#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mcommon.h"
#pragma execution_character_set("utf-8")
MainWindow::MainWindow(QWidget *parent) : FramelessMainWindow(parent), ui(new Ui::MainWindow)
{
   // qputenv("QT_SCALE_FACTOR", QString::number(1.0).toUtf8());
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
    if (watched == ui->labelMenuMin) {
        if (event->type() == QEvent::MouseButtonPress)
            labelMin_Clicked();
    }
    else if(watched==ui->labelMenuMax){
        if(event->type()==QEvent::MouseButtonPress)
            labelMax_Clicked();
    }
    else if(watched==ui->labelMenuClose){
        if(event->type()==QEvent::MouseButtonPress)
            labelClose_Clicked();
    }else if(watched==ui->labelMenuLeftMessage){
        if(event->type()==QEvent::MouseButtonPress){
            labelMenuLeftMessage_Clicked();
        }
    }else if(watched==ui->labelMenuLeftContact){
        if(event->type()==QEvent::MouseButtonPress)
            labelMenuLeftContact_Clicked();
    }
    return QMainWindow::eventFilter(watched,event);//交给上层
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

void MainWindow::initFilter()
{
    ui->labelMenuMin->installEventFilter(this);
    ui->labelMenuMax->installEventFilter(this);
    ui->labelMenuClose->installEventFilter(this);
    ui->labelMenuLeftMessage->installEventFilter(this);
    ui->labelMenuLeftContact->installEventFilter(this);
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


}

void MainWindow::initLabelPixmap()
{
    setLabelPixmap(":images/menuLeftMessage.png",ui->labelMenuLeftMessage);
    setLabelPixmap(":images/menuLeftContact.png",ui->labelMenuLeftContact);
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





