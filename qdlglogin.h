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
using std::initializer_list;
namespace Ui {
class QDlgLogin;
}
enum QENUM_LinEdit{QENUM_Account,QENUM_Password};//账号类、密码类
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
    QString m_user="";
    QString m_pswd="";
    int m_tryCount=0;//试错次数
    QMyLineEdits lineEdits;//lineEdit
    void readSettings();//读设置、注册表
    void writeSettings();//写设置
    QString encrypt(const QString&str);//字符串加密
    void initLineEditText(QLineEdit*,QString text);
protected:
    void mousePressEvent(QMouseEvent*event);//鼠标按下
    void mouseMoveEvent(QMouseEvent*event);//鼠标移动
    void MouseReleaseEvent(QMouseEvent*event);//鼠标释放
public:
    explicit QDlgLogin(QWidget *parent = nullptr);
   
    ~QDlgLogin();
private slots:
    void on_btnOk_clicked();

    void on_LineEditAccount_textChanged(const QString &arg1);

    void on_LineEditPassword_textChanged(const QString &arg1);
   
    void on_pushButtonLogin_clicked();

    void on_pushButtonCancel_clicked();



public slots:
  bool eventFilter(QObject*,QEvent*);
private:
    void initUi();
   Network& network=Network::getInstance();
    inline void setLineEditFontSize( QLineEdit* lineEdit, const QString& text);
    void registerAccount_clicked();
    Ui::QDlgLogin *ui;

};

#endif // QDLGLOGIN_H
