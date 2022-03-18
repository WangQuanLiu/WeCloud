#include "qdlglogin.h"
#include "ui_qdlglogin.h"

void QDlgLogin::writeSettings()
{

}

void QDlgLogin::initLineEditText(QLineEdit *linedit, QString text)
{
    QPalette palette;
   palette.setColor(QPalette::Text, QColor(213, 213, 213));
     linedit->setText(text);
    linedit->setPalette(palette);
    linedit->setFont(QFont("STKaiti", 14, QFont::Bold));

}

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

void QDlgLogin::registerAccount_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

QDlgLogin::~QDlgLogin()
{
    delete ui;
}

void QDlgLogin::initUi()
{
    setPalette(QPalette(Qt::white));//设置背景为白色
    setAutoFillBackground(true);//自动填充背景
  

    initLineEditText(ui->LineEditAccount,"手机号码");
    initLineEditText(ui->LineEditPassword,"密码");
    initLineEditText(ui->page3LineEditAccount,"手机号码");
    initLineEditText(ui->page3LineEditPassword,"密码");
    initLineEditText(ui->page3LineEditVerification,"验证码");



    ui->LineEditAccount->installEventFilter(this);//安装过滤器
    ui->LineEditPassword->installEventFilter(this);
    ui->labelRegisterAccount->installEventFilter(this);
    ui->page3LineEditAccount->installEventFilter(this);
    ui->page3LineEditPassword->installEventFilter(this);
    ui->page3LineEditVerification->installEventFilter(this);

    setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);//设置最小化和关闭按钮
    setFixedSize(this->width(), this->height());//固定窗口大小，无法调整窗口大小

    ui->stackedWidget->setCurrentIndex(0);

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
            if (ui->LineEditAccount->text() == QString::fromUtf8("手机号码"))
           ui->LineEditAccount->setText("");
        }
        else if (event->type() == QEvent::FocusOut) {
            ui->labelAccountIcon->setStyleSheet("image:url(:/images/accountIcon.jpg);");
            if (ui->LineEditAccount->text() == QString(""))
                ui->LineEditAccount->setText(QString::fromUtf8("手机号码"));
        }
    }
    else if(watched==ui->LineEditPassword){
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
    if(watched==ui->page3LineEditAccount){
        if(event->type()==QEvent::FocusIn){
            ui->page3LabelAccountIcon->setStyleSheet("image:url(:/images/accountIconBlue.jpg);");
            if (ui->page3LineEditAccount->text() == QString::fromUtf8("手机号码"))
           ui->page3LineEditAccount->setText("");
        }
        else if (event->type() == QEvent::FocusOut) {
            ui->page3LabelAccountIcon->setStyleSheet("image:url(:/images/accountIcon.jpg);");
            if (ui->page3LineEditAccount->text() == QString(""))
                ui->page3LineEditAccount->setText(QString::fromUtf8("手机号码"));
        }
    }

    else if(watched==ui->page3LineEditPassword){
        if(event->type()==QEvent::FocusIn){
            ui->page3LabelPasswordIcon->setStyleSheet("image:url(:/images/passwordIconBlue.jpg);");
            if (ui->page3LineEditPassword->text() == QString::fromUtf8("密码")) {
                ui->page3LineEditPassword->setText("");
                ui->page3LineEditPassword->setEchoMode(QLineEdit::Password);
            }
        }
        else if(event->type()==QEvent::FocusOut){
            ui->page3LabelPasswordIcon->setStyleSheet("image:url(:/images/passwordIcon.jpg);");
            if (ui->page3LineEditPassword->text() == QString("")) {
                ui->page3LineEditPassword->setText(QString::fromUtf8("密码"));
                ui->page3LineEditPassword->setEchoMode(QLineEdit::Normal);
            }
        }
    }
    else if(watched==ui->labelRegisterAccount)
        if(event->type()==QEvent::MouseButtonPress)
        registerAccount_clicked();
    return QDialog::eventFilter(watched,event);//交给上层
}


void QDlgLogin::on_pushButtonLogin_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    network.startConnect();
}


void QDlgLogin::on_pushButtonCancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


QMyLineEdit::QMyLineEdit(QLineEdit *lineEdit, QLabel *label, QString &imageBefore, QString&imageAfter,QString &text, QENUM_LinEdit enumLineEdit)
{
    this->lineEdit=lineEdit;
    this->label=label;
    this->imageBefore=QString("image:url(:/images/%1.jpg);").arg(imageBefore);
    this->imageAfter=QString("image:url(:/images/%1.jpg);").arg(imageAfter);
    this->text=text;
    this->enumLineEdit=enumLineEdit;
}

void QMyLineEdit::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==lineEdit){
        if(event->type()==QEvent::FocusIn){//聚集
            label->setStyleSheet(imageAfter);
            if(lineEdit->text()==text){
                lineEdit->setText("");
                if(enumLineEdit==QENUM_Password)
                    lineEdit->setEchoMode(QLineEdit::Password);
                }
        }else if(event->type()==QEvent::FocusOut){
            label->setStyleSheet(imageBefore);
            if(lineEdit->text()==QString("")){
                lineEdit->setText(text);
                if(enumLineEdit==QENUM_Password)
                    lineEdit->setEchoMode(QLineEdit::Normal);
            }
        }
    }


}

QMyLineEdit &QMyLineEdit::operator=(const QMyLineEdit &lineEdit)
{
    this->enumLineEdit=lineEdit.enumLineEdit;
    this->imageAfter=lineEdit.imageAfter;
    this->imageBefore=lineEdit.imageBefore;
    this->label=lineEdit.label;
    this->lineEdit=lineEdit.lineEdit;
    this->text=lineEdit.text;
    return *this;
}



QMyLineEdits::QMyLineEdits(initializer_list<QMyLineEdit> list)
{
    for(auto begin=list.begin();begin!=list.end();begin++)
        this->list.push_back(*begin);
}

QMyLineEdits &QMyLineEdits::operator=(const QMyLineEdits &lineEdits)
{
    for(auto begin=lineEdits.list.begin();begin!=lineEdits.list.end();begin++)
       this->list.push_back(*begin);
    return *this;
}

void QMyLineEdits::push_back(QMyLineEdit &obj)
{
    list.push_back(obj);
}

void QMyLineEdits::eventFilter(QObject *watched, QEvent *event)
{
    for(auto begin=list.begin();begin!=list.end();begin++)
        begin->eventFilter(watched,event);
}
