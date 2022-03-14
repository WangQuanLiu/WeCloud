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
   initUi();
 //   QWidget widget;
    
    
}
/*
数字:18号字大小
非数字:14号字大小
*/
void QDlgLogin::setLineEditFontSize( QLineEdit* lineEdit, const QString& text)
{
    bool isDigit;
    text.toDouble(&isDigit);//判断是否为数字
    if (isDigit)
        lineEdit->setFont(QFont("STKaiti", 18, QFont::Bold));
    else
        lineEdit->setFont(QFont("STKaiti", 14, QFont::Bold));
}

QDlgLogin::~QDlgLogin()
{
    delete ui;
}

void QDlgLogin::initUi()
{
    setPalette(QPalette(Qt::white));//设置背景为白色
    setAutoFillBackground(true);//自动填充背景
  
   
    ui->LineEditAccount->setText(QString::fromUtf8("账号"));
    QPalette palette;
    palette.setColor(QPalette::Text, QColor(213, 213, 213));
    ui->LineEditAccount->setPalette(palette);
    ui->LineEditAccount->setFont(QFont("STKaiti", 14, QFont::Bold));

    ui->LineEditPassword->setText(QString::fromUtf8("密码"));
    ui->LineEditPassword->setPalette(palette);
    ui->LineEditPassword->setFont(QFont("STKaiti", 14, QFont::Bold));

    ui->LineEditAccount->installEventFilter(this);//安装过滤器
    ui->LineEditPassword->installEventFilter(this);
    setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);//设置最小化和关闭按钮
    setFixedSize(this->width(), this->height());//固定窗口大小，无法调整窗口大小

}
void QDlgLogin::on_btnOk_clicked()
{

}

void QDlgLogin::on_LineEditAccount_textChanged(const QString &text)
{
    setLineEditFontSize(ui->LineEditAccount, text);
}


void QDlgLogin::on_LineEditPassword_textChanged(const QString &text)
{
    setLineEditFontSize(ui->LineEditPassword, text);
}


bool QDlgLogin::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->LineEditAccount){

        if(event->type()==QEvent::FocusIn){//聚焦
            ui->labelAccountIcon->setStyleSheet("image:url(:/images/accountIconBlue.jpg);");
            if (ui->LineEditAccount->text() == QString::fromUtf8("账号"))
           ui->LineEditAccount->setText("");
        }
        else if (event->type() == QEvent::FocusOut) {
            ui->labelAccountIcon->setStyleSheet("image:url(:/images/accountIcon.jpg);");
            if (ui->LineEditAccount->text() == QString(""))
                ui->LineEditAccount->setText(QString::fromUtf8("账号"));
        }
    }
    if(watched==ui->LineEditPassword){
        if(event->type()==QEvent::FocusIn){
            ui->labelPasswordIcon->setStyleSheet("image:url(:/images/passwordIconBlue.jpg);");
            if (ui->LineEditPassword->text() == QString::fromUtf8("密码")) {
                ui->LineEditPassword->setText("");
                ui->LineEditPassword->setEchoMode(QLineEdit::Password);
            }
        }
        else if(event->type()==QEvent::FocusOut){
            ui->labelPasswordIcon->setStyleSheet("image:url(:/images/passwordIcon.jpg);");
            if (ui->LineEditPassword->text() == QString("")) {
                ui->LineEditPassword->setText(QString::fromUtf8("密码"));
                ui->LineEditPassword->setEchoMode(QLineEdit::Normal);
            }
        }
    }

    return QDialog::eventFilter(watched,event);//交给上层
}

