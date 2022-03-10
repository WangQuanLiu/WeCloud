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

QDlgLogin::~QDlgLogin()
{
    delete ui;
}

void QDlgLogin::initUi()
{
    setPalette(QPalette(Qt::white));//设置背景为白色
    setAutoFillBackground(true);//自动填充背景
    drawAccountPicutre();
}

bool QDlgLogin::drawAccountPicutre()
{
  /*  int w=ui->labelAccountPicture->width();
    int h=ui->labelAccountPicture->height();
    QPixmap pixmapa(":/images/accountPicture.jpg");
    QPixmap pximap(w,h);
    pximap.fill(Qt::transparent);
    QPainter painter(&pximap);
    painter.setRenderHints(QPainter::Antialiasing);
    QPainterPath path;
    path.addEllipse(0,0,w,h);
    painter.setClipPath(path);
    painter.drawPixmap(0,0,w,h,pixmapa);
    ui->labelAccountPicture->setPixmap(pximap);
*/
 /*   QPixmap pixmap(":/images/accountPicture.jpg");
    QPixmap fitpixmap=pixmap.scaled(80,80,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    QSize size(80,80);
    QBitmap mask(size);
    QPainter painter(&mask);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.fillRect(0,0,size.width(),size.height(),Qt::white);
    painter.setBrush(QColor(0,0,0));
    painter.drawRoundedRect(0,0,size.width(),size.height(),80,80);

    fitpixmap.setMask(mask);
    ui->labelAccountPicture->setPixmap(fitpixmap);
*/
  /*  int radius=80;
    QPixmap pixmapa("/images/accountPicture.jpg");
    QPixmap pixmap(radius,radius);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform);
    QPainterPath path;
    path.addEllipse(0,0,radius,radius);
    painter.setClipPath(path);
    painter.drawPixmap(0,0,radius,radius,pixmapa);
*/
    return true;
}

void QDlgLogin::on_btnOk_clicked()
{

}
/*账号文字输入改变*/

void QDlgLogin::on_LineEditAccount_textChanged(const QString &arg1)
{
   ui->LineEditAccount->setFont(QFont("STKaiti",18,QFont::Bold));
}


void QDlgLogin::on_LineEditPassword_textChanged(const QString &arg1)
{
    ui->LineEditPassword->setFont(QFont("STKaiti",12,QFont::Bold));
    ui->LineEditPassword->setEchoMode(QLineEdit::Password);
}

