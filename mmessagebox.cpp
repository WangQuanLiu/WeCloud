#include "mmessagebox.h"
#include "ui_mmessagebox.h"

MMessageBox::MMessageBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MMessageBox)
{
    ui->setupUi(this);
    init();
}

MMessageBox::~MMessageBox()
{
    delete ui;
}

void MMessageBox::setMessageBox(const QString &pictureName, const QString &name, const QString &messageText, const QString &statusText, const QString &messageTime)
{
    this->pictureName=pictureName;
    this->messageText=messageText;
    this->name=name;
    this->statusText=statusText;
    this->messageTime=messageTime;
    initUi();
}

MMessageBox &MMessageBox::operator=(const MMessageBox &obj)
{
    this->pictureName=obj.pictureName;
    this->messageText=obj.messageText;
    this->name=obj.name;
    this->statusText=obj.statusText;
    this->messageTime=messageTime;
    initUi();
    return *this;
}

void MMessageBox::init()
{
    readQss("mMessageBox.qss",this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}

void MMessageBox::initUi()
{
    setLabelRoundRectPixmap(this->pictureName,ui->labelPicture,6);
    ui->labelName->setText(this->name);
    ui->labelMessage->setText(this->messageText);
    ui->labelStatus->setText(this->statusText);
    ui->labelTime->setText(this->messageTime);
}
