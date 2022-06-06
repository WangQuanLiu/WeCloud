#include "qdlglogin.h"
#include "ui_qdlglogin.h"

void QDlgLogin::writeSettings()
{

}
/*
 * 输入:linedite为行文本容器，text为文本内容
 * 功能：把linedit容器设置为text的文本内容，并设置成固定的字体颜色与大小
 * 输出：void
 */
void QDlgLogin::initLineEditText(QLineEdit *linedit, QString text)
{
    if(linedit==nullptr)return;
    QPalette palette;
    palette.setColor(QPalette::Text, QColor(213, 213, 213));
    linedit->setText(text);
    linedit->setPalette(palette);
    linedit->setFont(QFont("STKaiti", 12, QFont::Bold));

}
/*
 * 输入：lineEdit为文本容器,warningDialog为警告内容
 * 功能: 检验文本内的格式是否正确，如果错误则进行报错显示
 * 输出：输出是否格式正确,正确返回QENUM_Noraml，错误返回QEnum_Error
 */
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
/*
 * 输入：账号的文本内容
 * 功能：检验账号的文本内容
 * 输出：文本内容正确就返回QENUM_Normal，错误就返回QENUM_Error
 */
QENUM_Warning QDlgLogin::checkAccount(const QString& text)
{
    QRegularExpression re("\\d{11,11}");
    QRegularExpressionMatch match = re.match(text);
    if (!match.hasMatch())
        return QENUM_Error;
    return QENUM_Normal;
}
/*
 * 输入：lineEdit为密码的文本框对象，WarningDialog为警告框的对象
 * 功能：检验密码文本框的内容是否正确，若正确能不显示警告框，不正确就显示警告框
 * 输出：密码文本框的内容若正确返回QENUM_Normal，错误则返回QENUM_Error
 */
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
/*
 * 输入：密码的文本内容
 * 功能：检验密码的文本内容
 * 输出：文本内容正确就返回QENUM_Normal，错误就返回QENUM_Error
 */
QENUM_Warning QDlgLogin::checkPassword(const QString& text)
{
    QRegularExpression re("^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d]{8,}$");
    QRegularExpressionMatch match = re.match(text);
    if (!match.hasMatch())return QENUM_Error;
    return QENUM_Normal;
}
/*
 * 输入：验证码文本框对象
 * 功能：校验验证码是否正确
 * 输出：正确返回QENUM_Normal，错误返回QENUM_Warning
 */
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
/*
 * 输入：label为警告框对象,dialogText为label警告框所提示的对象的输入框的初始化文本，text为输入框的内容文本
 * 功能：根据文本框的内容来进行警告框的显示与隐藏
 * 输出：void
 */
void QDlgLogin::setWarningDialogVisible(QLabel* label,const QString& dialogText,const QString& text, QENUM_LinEdit lineEditType)
{
    if(label==nullptr)return;
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
  readQss("LoginQss.qss",this);
}
/*
输入：lineEdit为文本框对象，text为文本内容
功能：若文本内容为数字能设置字体为STKaiti,字体大小为18,若非数字则设置为STKaiti,字体大小为12
输出：
*/
void QDlgLogin::setLineEditFontSize( QLineEdit* lineEdit, const QString& text)
{
    if(lineEdit==nullptr)return;
    bool isDigit;
    text.toDouble(&isDigit);//判断是否为数字
    if (isDigit)
        lineEdit->setFont(QFont("STKaiti", 16, QFont::Bold));
    else
        lineEdit->setFont(QFont("STKaiti", 12, QFont::Bold));
}
/*
 * 功能：显示注册界面
 */
void QDlgLogin::registerAccount_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

QDlgLogin::~QDlgLogin()
{
    delete ui;
    close();
}
/*
 *
 * 功能：初始化登陆进度条
 */
inline void QDlgLogin::initProgressBar()
{
    ui->page2ProgressBar->setRange(0, 100);
    ui->page2ProgressBar->setValue(0);
    timer = new QTimer();
    timer->setInterval(50);
    connect(timer, SIGNAL(timeout()), this, SLOT(onProgressBarLoader()));
}
/*
 * 功能：进行初始化界面的设置
 */
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

    setLabelFontSize(ui->labelRegisterAccount,10);
    setLabelFontSize(ui->labelForgetPassword,10);
    setLabelFontSize(ui->page3LabelBackLogin,10);
    setLabelFontSize(ui->labelAccountWarningDialog,10);
    setLabelFontSize(ui->labelPasswordWarningDialog,10);

    lineEdits = { QMyLineEdit(ui->LineEditAccount,ui->labelAccountIcon,"accountIcon.jpg","accountIconBlue.jpg",lineEditAccountInitText ),
                  QMyLineEdit(ui->LineEditPassword,ui->labelPasswordIcon,"passwordIcon.jpg","passwordIconBlue.jpg",lineEditPasswordInitText,QENUM_Password),
                  QMyLineEdit(ui->page3LineEditAccount,ui->page3LabelAccountIcon,"accountIcon.jpg","accountIconBlue.jpg",lineEditAccountInitText),
                  QMyLineEdit(ui->page3LineEditPassword,ui->page3LabelPasswordIcon,"passwordIcon.jpg","passwordIconBlue.jpg",lineEditPasswordInitText,QENUM_Password),
                  QMyLineEdit(ui->page3LineEditVerification,ui->page3LabelVerification,"verificationCodeIconGray.jpg","verificationCodeIconBlue.jpg",lineEditVerificationCodeInitText)};

    setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);//设置最小化和关闭按钮
    setFixedSize(this->width(), this->height());//固定窗口大小，无法调整窗口大小

    ui->stackedWidget->setCurrentIndex(0);

}
/*
 * 功能：初始化各个对象框的可视化
 */
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
/*
 * 功能：初始化过滤器
 */
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

/*
 * 输入：watched为初始观察的对象,event为事件
 * 功能：进行事件的过滤，
 * 输出:成功返回true，失败返回false
 */
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
  Q_UNUSED(event);
    close();
}
/*
 *
 * 功能：登陆点击事件响应
 */

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
    this->imageBefore=QString("image:url(:/images/login/%1);").arg(imageBefore);
    this->imageAfter=QString("image:url(:/images/login/%1);").arg(imageAfter);
    this->text=text;
    this->enumLineEdit=enumLineEdit;
}
/*
 * 功能：事件过滤
 */
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
/*
 *
 * 功能：进行集体事件的过滤
 */
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

