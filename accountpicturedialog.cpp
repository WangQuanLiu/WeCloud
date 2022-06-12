#include "accountpicturedialog.h"
#include "ui_accountpicturedialog.h"
#include "mcommon.h"
bool AccountPictureDialog::eventFilter(QObject *watched, QEvent *event)
{
     if(event->type()==QEvent::ActivationChange){

             if(QApplication::activeWindow()!=this){

                 this->hide();
             }
     }
      return QDialog::eventFilter(watched,event);//½»¸øÉÏ²ã
}

AccountPictureDialog::AccountPictureDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountPictureDialog)
{
    ui->setupUi(this);
    init();
}

AccountPictureDialog::~AccountPictureDialog()
{
    delete ui;
}

void AccountPictureDialog::init()
{
    readQss("accountPictureDialog.qss",this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    ui->labelPersonalInfomation->installEventFilter(this);
    this->installEventFilter(this);
}
