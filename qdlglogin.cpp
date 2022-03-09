#include "qdlglogin.h"
#include "ui_qdlglogin.h"

void QDlgLogin::mousePressEvent(QMouseEvent *event)
{

}

void QDlgLogin::mouseMoveEvent(QMouseEvent *event)
{

}

void QDlgLogin::MouseReleaseEvent(QMouseEvent *event)
{

}

QDlgLogin::QDlgLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QDlgLogin)
{
    ui->setupUi(this);
    QWidget widget;
    setPalette(QPalette(Qt::white));//设置背景为白色
    setAutoFillBackground(true);//自动填充背景



}

QDlgLogin::~QDlgLogin()
{
    delete ui;
}

void QDlgLogin::on_btnOk_clicked()
{

}
