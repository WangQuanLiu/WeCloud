#ifndef QDLGLOGIN_H
#define QDLGLOGIN_H
#include <QDialog>
#include<QPalette>
#include<qpushbutton.h>
#include<QPainter>
#include<QSize>
#include<QPainterPath>
#include<QFont>
#include<qlineedit.h>
#include<QLabel>
#include"network.h"
#include<QList>
#include<initializer_list>
#include<qregularexpression.h>
#include<qthread.h>
using std::initializer_list;
namespace Ui {
class QDlgLogin;
}
enum QENUM_LinEdit{QENUM_Account,QENUM_Password,QENUM_VerificationCode};//账号类、密码类
enum QENUM_Warning{QENUM_Error,QENUM_Normal};
enum QENUM_Page{QENUM_Login_Page,QENUM_Register_Page};
class QMyLineEdit{
public:
    QMyLineEdit(QLineEdit*lineEdit,QLabel*label,const QString&imageBefore,const QString&imageAfter,const QString&text,QENUM_LinEdit enumLineEdit=QENUM_Account);
    void eventFilter(QObject *watched, QEvent *event);
    QMyLineEdit&operator=(const QMyLineEdit&lineEdit);
private:
    QMyLineEdit(){}
 QLineEdit*lineEdit;//输入框
 QLabel*label;//背景框
 QString imageBefore,imageAfter,text;//图片名和文本
QENUM_LinEdit enumLineEdit;
};
//QMyLineEdits类用来集lineEdit,并且进行集中事件过滤
class QMyLineEdits{

public:
    QMyLineEdits()=default;
    QMyLineEdits(initializer_list<QMyLineEdit>list);
    QMyLineEdits&operator=(const QMyLineEdits&lineEdits);
    void push_back(QMyLineEdit&obj);
    void eventFilter(QObject*watched,QEvent*event);
private:

    QList<QMyLineEdit>list;
};

class QDlgLogin : public QDialog
{
    Q_OBJECT

private:
    bool m_moving=false;//窗口是否在鼠标操作下移动
    QPoint m_lastPost;//上一次鼠标的位置
    QString userName="";
    QString password="";
    int m_tryCount=0;//试错次数
    QMyLineEdits lineEdits;//lineEdit
    void readSettings();//读设置、注册表
    void writeSettings();//写设置
    QString encrypt(const QString&str);//字符串加密
    void initLineEditText(QLineEdit*,QString text);
    QENUM_Warning checkAccount(QLineEdit* lineEdit,QLabel*WarningDialog);
    QENUM_Warning checkAccount(const QString& text);
    QENUM_Warning checkPassword(QLineEdit* lineEdit,QLabel*WarningDialog);
    QENUM_Warning checkPassword(const QString& text);
    QENUM_Warning checkVerificationCode(QLineEdit* lineEdit);
protected:
    void mousePressEvent(QMouseEvent*event);//鼠标按下
    void mouseMoveEvent(QMouseEvent*event);//鼠标移动
    void MouseReleaseEvent(QMouseEvent*event);//鼠标释放
    void setWarningDialogVisible(QLabel* label,const QString&dialogText,const QString& text,QENUM_LinEdit lineEditType =QENUM_Account);
public:
    explicit QDlgLogin(QWidget *parent = nullptr);
   
    ~QDlgLogin();
private slots:
    void on_btnOk_clicked();

    void on_LineEditAccount_textChanged(const QString &);

    void on_LineEditPassword_textChanged(const QString &);
   
    void on_pushButtonLogin_clicked();

    void on_pushButtonCancel_clicked();



    void on_page3LineEditAccount_textChanged(const QString &);

    void on_page3LineEditPassword_textChanged(const QString &);

    void on_page3PushButtonRegister_clicked();

public slots:
  bool eventFilter(QObject*,QEvent*);
private:
   inline void initUi();
  inline  void initVisible();
    void initFilter();
    Network& network= Network::getInstance();
    inline void setLineEditFontSize( QLineEdit* lineEdit, const QString& text);
    void registerAccount_clicked();
    Ui::QDlgLogin *ui;
    QString lineEditAccountInitText = QString::fromUtf8("手机号码");
    QString lineEditPasswordInitText = QString::fromUtf8("8位以上数字与字母组合");
    QString lineEditVerificationCodeInitText = QString::fromUtf8("验证码");
};

#endif // QDLGLOGIN_H
