#include "mainwindow.h"
#include "ui_mainwindow.h"

#pragma execution_character_set("utf-8")
MainWindow::MainWindow(QWidget *parent) : FramelessMainWindow(parent), ui(new Ui::MainWindow)
{
   // qputenv("QT_SCALE_FACTOR", QString::number(1.0).toUtf8());
    ui->setupUi(this);
    this->initForm();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initForm()
{
    //���ñ������ؼ�
    ui->labTitle->setText("�ޱ߿���ʾ��-֧��win��linux��mac��ϵͳ (QQ: 517216493 WX: feiyangqingyun)");
    this->setWindowTitle(ui->labTitle->text());
    this->setTitleBar(ui->labTitle);

    //�����ź�
    connect(this, SIGNAL(titleDblClick()), this, SLOT(titleDblClick()));
    connect(this, SIGNAL(windowStateChange(bool)), this, SLOT(windowStateChange(bool)));

    //������ʽ��
    QStringList list;
    list << "#titleBar{background:#BBBBBB;}";
    list << "#titleBar{border-top-left-radius:8px;border-top-right-radius:8px;}";
    list << "#widgetMain{border:2px solid #BBBBBB;background:#FFFFFF;}";
    //list << "#widgetMain{border-bottom-left-radius:8px;border-bottom-right-radius:8px;}";
    this->setStyleSheet(list.join(""));
}

void MainWindow::titleDblClick()
{
    on_btnMenu_Max_clicked();
}

void MainWindow::windowStateChange(bool max)
{
    ui->btnMenu_Max->setText(max ? "normal" : "max");
}

void MainWindow::on_btnMenu_Min_clicked()
{
#ifdef Q_OS_MACOS
    this->setWindowFlags(this->windowFlags() & ~Qt::FramelessWindowHint);
#endif
    this->showMinimized();
}

void MainWindow::on_btnMenu_Max_clicked()
{
   if(this->isMaximized()){

      this->showNormal();
       ui->btnMenu_Max->setText("max");

    }
   else{

       this->showMaximized();
       ui->btnMenu_Max->setText("normal");
     }

}

void MainWindow::on_btnMenu_Close_clicked()
{
    this->close();
}
