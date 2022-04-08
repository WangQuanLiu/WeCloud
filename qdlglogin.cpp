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
    linedit->setFont(QFont("STKaiti", 12, QFont::Bold));

}

QENUM_Warning QDlgLogin::checkAccount(QLineEdit* lineEdit,  QLabel* WarningDialog)
{
    QRegularExpression re("^1\\d{10}$");
    QRegularExpressionMatch match = re.match(lineEdit->text());
    if (lineEdit->text() == lineEditAccountInitText) {
        WarningDialog->setText(QString::fromUtf8("账号不能为空"));
        WarningDialog->setVisible(true);
        return QENUM_Error;
    }
    else if (!match.hasMatch()) {//不匹配
        WarningDialog->setText(QString::fromUtf8("账号格式错误"));
        WarningDialog->setVisible(true);
        return QENUM_Error;
    }
    return QENUM_Normal;
}

QENUM_Warning QDlgLogin::checkAccount(const QString& text)
{
    QRegularExpression re("\\d{11,11}");
    QRegularExpressionMatch match = re.match(text);
    if (!match.hasMatch())
        return QENUM_Error;
    return QENUM_Normal;
}

QENUM_Warning QDlgLogin::checkPassword(QLineEdit* lineEdit,QLabel*WarningDialog)
{
    QRegularExpression re("^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d]{8,}$");
    QRegularExpressionMatch match = re.match(lineEdit->text());
    qDebug() << lineEdit->text();
    if (lineEdit->text() == lineEditPasswordInitText) {
        WarningDialog->setText(QString::fromUtf8("密码不能为空"));
        WarningDialog->setVisible(true);
        return QENUM_Error;
    }
    else if (!match.hasMatch()) {
        WarningDialog->setText(QString::fromUtf8("密码格式错误"));
        WarningDialog->setVisible(true);
        return QENUM_Error;
    }
    return QENUM_Normal;
}

QENUM_Warning QDlgLogin::checkPassword(const QString& text)
{
    QRegularExpression re("^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d]{8,}$");
    QRegularExpressionMatch match = re.match(text);
    if (!match.hasMatch())return QENUM_Error;
    return QENUM_Normal;
}

QENUM_Warning QDlgLogin::checkVerificationCode(QLineEdit* lineEdit)
{
    return QENUM_Warning();
}

void QDlgLogin::close()
{
    network->quit();
    timer->stop();
}

void QDlgLogin::onProgressBarLoader()
{
    
    static int i = 1;
    ui->page2ProgressBar->setValue(i++);
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

void QDlgLogin::setWarningDialogVisible(QLabel* label,const QString& dialogText,const QString& text, QENUM_LinEdit lineEditType)
{
    if (dialogText == text || text == QString(""))//未点击LineEdit，
        label->setVisible(false);
    else if (lineEditType == QENUM_Account && checkAccount(text) == QENUM_Error)
        label->setVisible(true);
    else label->setVisible(false);
}

QDlgLogin::QDlgLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QDlgLogin)
{
   ui->setupUi(this);
   initUi();
 //   QWidget widget;
   initProgressBar();
   network = new Network();
   network->start();
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
        lineEdit->setFont(QFont("STKaiti", 12, QFont::Bold));
}

void QDlgLogin::registerAccount_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

QDlgLogin::~QDlgLogin()
{
    delete ui;
    close();
}

inline void QDlgLogin::initProgressBar()
{
    ui->page2ProgressBar->setRange(0, 100);
    ui->page2ProgressBar->setValue(0);
    timer = new QTimer();
    timer->setInterval(50);
    connect(timer, SIGNAL(timeout()), this, SLOT(onProgressBarLoader()));
}

void QDlgLogin::initUi()
{
    setPalette(QPalette(Qt::white));//设置背景为白色
    setAutoFillBackground(true);//自动填充背景
    ui->page2ProgressBar->setFormat("");
    initFilter();
    initVisible();
    initLineEditText(ui->LineEditAccount,lineEditAccountInitText);
    initLineEditText(ui->LineEditPassword,lineEditPasswordInitText);
    initLineEditText(ui->page3LineEditAccount,lineEditAccountInitText);
    initLineEditText(ui->page3LineEditPassword,lineEditPasswordInitText);
    initLineEditText(ui->page3LineEditVerification,lineEditVerificationCodeInitText);

    lineEdits = { QMyLineEdit(ui->LineEditAccount,ui->labelAccountIcon,"accountIcon.jpg","accountIconBlue.jpg",lineEditAccountInitText ),
                  QMyLineEdit(ui->LineEditPassword,ui->labelPasswordIcon,"passwordIcon.jpg","passwordIconBlue.jpg",lineEditPasswordInitText,QENUM_Password),
                  QMyLineEdit(ui->page3LineEditAccount,ui->page3LabelAccountIcon,"accountIcon.jpg","accountIconBlue.jpg",lineEditAccountInitText),
                  QMyLineEdit(ui->page3LineEditPassword,ui->page3LabelPasswordIcon,"passwordIcon.jpg","passwordIconBlue.jpg",lineEditPasswordInitText,QENUM_Password),
                  QMyLineEdit(ui->page3LineEditVerification,ui->page3LabelVerification,"verificationCodeIconGray.jpg","verificationCodeIconBlue.jpg",lineEditVerificationCodeInitText)};

    setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);//设置最小化和关闭按钮
    setFixedSize(this->width(), this->height());//固定窗口大小，无法调整窗口大小

    ui->stackedWidget->setCurrentIndex(0);

}
void QDlgLogin::initVisible()
{
    ui->labelAccountWarningDialog->setVisible(false);
    ui->labelPasswordWarningDialog->setVisible(false);
    ui->page3LabelAccountWarningDialog->setVisible(false);
    ui->page3LabelPasswordWarningDialog->setVisible(false);
    ui->page3LabelVerificationCodeWarningDialog->setVisible(false);
    ui->Page4LabelAccountWarningDialog->setVisible(false);
    ui->Page4LabelPasswordWarningDialog->setVisible(false);
    ui->page4LabelVerificationCodeWarningDialog->setVisible(false);
}
void QDlgLogin::initFilter()
{
    ui->LineEditAccount->installEventFilter(this);//安装过滤器
    ui->LineEditPassword->installEventFilter(this);
    ui->labelRegisterAccount->installEventFilter(this);
    ui->page3LineEditAccount->installEventFilter(this);
    ui->page3LineEditPassword->installEventFilter(this);
    ui->page3LineEditVerification->installEventFilter(this);
    ui->page3LabelBackLogin->installEventFilter(this);
}
void QDlgLogin::on_btnOk_clicked()
{

}

void QDlgLogin::on_LineEditAccount_textChanged(const QString &text)
{
    setLineEditFontSize(ui->LineEditAccount, text);
    setWarningDialogVisible(ui->labelAccountWarningDialog, lineEditAccountInitText, text);
}


void QDlgLogin::on_LineEditPassword_textChanged(const QString &text)
{
    setLineEditFontSize(ui->LineEditPassword, text);
    setWarningDialogVisible(ui->labelPasswordWarningDialog, lineEditPasswordInitText, text,QENUM_Password);
}


bool QDlgLogin::eventFilter(QObject *watched, QEvent *event)
{
    lineEdits.eventFilter(watched,event);

  
    if (watched == ui->labelRegisterAccount) {
        if (event->type() == QEvent::MouseButtonPress)
            registerAccount_clicked();
    }
    else if (watched == ui->page3LabelBackLogin) {
        if (event->type() == QEvent::MouseButtonPress)
            ui->stackedWidget->setCurrentIndex(0);
    }
    return QDialog::eventFilter(watched,event);//交给上层
}

void QDlgLogin::close(QCloseEvent *event)
{

    close();
}


void QDlgLogin::on_pushButtonLogin_clicked()
{
    if (checkAccount(ui->LineEditAccount,ui->labelAccountWarningDialog) == QENUM_Error)return;
    if (checkPassword(ui->LineEditPassword, ui->labelPasswordWarningDialog) == QENUM_Error)return;
    ui->stackedWidget->setCurrentIndex(2);
    timer->start();
    userName = ui->LineEditAccount->text();
    password = ui->LineEditPassword->text();
   // network.start();
    QString text;
        text+=MSG_ACCOUNT(userName) + "\n";
        text += MSG_PASSWORD(password)+"\n";
    Message msg(ENUM_NetMsg_PassworkVerification_Request, text);
    network->addData(msg);
    network->sendData();
  
}


void QDlgLogin::on_pushButtonCancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//text 需要QString::fromUtf8转码
QMyLineEdit::QMyLineEdit(QLineEdit *lineEdit, QLabel *label,const QString &imageBefore, const QString&imageAfter,const QString &text, QENUM_LinEdit enumLineEdit)
{
    this->lineEdit=lineEdit;
    this->label=label;
    this->imageBefore=QString("image:url(:/images/%1);").arg(imageBefore);
    this->imageAfter=QString("image:url(:/images/%1);").arg(imageAfter);
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

void QDlgLogin::on_page3LineEditAccount_textChanged(const QString &text)
{
    setLineEditFontSize(ui->page3LineEditAccount, text);
}


void QDlgLogin::on_page3LineEditPassword_textChanged(const QString &text)
{
    setLineEditFontSize(ui->page3LineEditPassword,text);
}


void QDlgLogin::on_page3PushButtonRegister_clicked()
{
   

}

