#ifndef QDLGLOGIN_H
#define QDLGLOGIN_H
#include <QDialog>
#include<QPalette>
#include<qpushbutton.h>
#include<QPainter>
#include<QSize>
#include<QPainterPath>
#include<QFont>
#include<qregexp.h>
#include<qlineedit.h>
#include"network.h"
namespace Ui {
class QDlgLogin;
}
 
class QDlgLogin : public QDialog
{
    Q_OBJECT

private:
    bool m_moving=false;//窗口是否在鼠标操作下移动
    QPoint m_lastPost;//上一次鼠标的位置
    QString m_user="";
    QString m_pswd="";
    int m_tryCount=0;//试错次数
    void readSettings();//读设置、注册表
    void writeSettings();//写设置
    QString encrypt(const QString&str);//字符串加密
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
   
    inline void setLineEditFontSize( QLineEdit* lineEdit, const QString& text);
    Ui::QDlgLogin *ui;
  
};

#endif // QDLGLOGIN_H
