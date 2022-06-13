#include "mmessagebox.h"
#include "ui_mmessagebox.h"

MMessageBox::MMessageBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MMessageBox)
{
    ui->setupUi(this);
    init();
    initUi();
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
    this->isTopMessageBox=obj.isTopMessageBox;
    initUi();
    return *this;
}

void MMessageBox::contextMenuEvent(QContextMenuEvent *event)
{
    QCursor cur=this->cursor();
    QMenu*menu=new QMenu(this);//�Ҽ��˵���
    menu->addAction(this->actTopMessageBox);
    menu->addAction(this->actRemoveMessageBox);
    menu->addAction(this->actMessageNotDisturb);
    menu->addAction(this->actCleanMessageRecord);
    menu->addAction(this->actPersonalInformation);
    menu->addAction(this->actModifyFrinedNote);
    menu->exec(cur.pos());//���������
}

void MMessageBox::init()
{
    readQss("mMessageBox.qss",this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    isTopMessageBox=false;
}

void MMessageBox::initUi()
{
    setLabelRoundRectPixmap(this->pictureName,ui->labelPicture,6);
    ui->labelName->setText(this->name);
    ui->labelMessage->setText(this->messageText);
    ui->labelStatus->setText(this->statusText);
    ui->labelTime->setText(this->messageTime);

    this->actTopMessageBox=new QAction(QString::fromUtf8("�ö�"),this);
    this->actRemoveMessageBox=new QAction(QString::fromUtf8("�Ƴ��Ự"),this);
    this->actMessageNotDisturb=new QAction(QString::fromUtf8("��Ϣ�����"),this);
    this->actCleanMessageRecord=new QAction(QString::fromUtf8("��ջỰ��¼"),this);
    this->actPersonalInformation=new QAction(QString::fromUtf8("������Ϣ"),this);
    this->actModifyFrinedNote=new QAction(QString::fromUtf8("�޸ĺ��ѱ�ע"),this);
}
