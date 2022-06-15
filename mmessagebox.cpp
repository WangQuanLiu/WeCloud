#include "mmessagebox.h"
#include "qdebug.h"
#include "qevent.h"
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

void MMessageBox::setMessageBox(const QString &pictureName, const QString &name, const QString &messageText, const QString &statusText, const QString &messageTime,bool isNotDisturb)
{
    this->pictureName=pictureName;
    this->messageText=messageText;
    this->name=name;
    this->statusText=statusText;
    this->messageTime=messageTime;
    this->isNotDisturb=isNotDisturb;
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
    this->isNotDisturb=obj.isNotDisturb;
    initUi();
    return *this;
}

bool MMessageBox::getIsClick()
{
    return this->isClick;
}

void MMessageBox::setIsClick(bool isClick)
{
    this->isClick=isClick;
}
/*
 *
 *功能:取消被选择，设置isClick标志并重置会话框样式
 */
void MMessageBox::cancelSelected()
{
    setIsClick(false);
     QString styleSheet;
    if(this->isTopMessageBox){
        styleSheet="#MMessageBox,#widget{border:2px solid #F7F7F7;"
                       " background:#F7F7F7;border-radius: 8px;}"
                       "";

    }else{
        styleSheet="#MMessageBox,#widget{border:2px solid #FFFFFF;"
                       " background:#FFFFFF;border-radius: 8px;}"
                       "";
    }
    ui->widget->setStyleSheet(styleSheet);
}

void MMessageBox::cancelTopMessageBox()
{
    setIsTopMessageBox(false);
    emit sigCancelTopMessage(this);
}

bool MMessageBox::getIsTopMessageBox()
{
    return this->isTopMessageBox;
}

void MMessageBox::setIsTopMessageBox(bool isTopMessageBox)
{
    this->isTopMessageBox=isTopMessageBox;
    if(this->isTopMessageBox==true)
        this->actTopMessageBox->setText(QString::fromUtf8("取消置顶"));
    else
        this->actTopMessageBox->setText(QString::fromUtf8("置顶"));


}

void MMessageBox::setISNotDisturb(bool isNotDisturb)
{
    this->isNotDisturb=isNotDisturb;
    if(this->isNotDisturb==true)
        this->actMessageNotDisturb->setText(QString::fromUtf8("取消消息免打扰"));
    else
        this->actMessageNotDisturb->setText(QString::fromUtf8("消息免打扰"));
}

QString MMessageBox::getName()
{
    return this->name;
}

void MMessageBox::contextMenuEvent(QContextMenuEvent *)
{
    QCursor cur=this->cursor();
    QMenu*menu=new QMenu(this);//右键菜单栏
    menu->addAction(this->actTopMessageBox);
    menu->addAction(this->actRemoveMessageBox);
    menu->addAction(this->actMessageNotDisturb);
    menu->addAction(this->actCleanMessageRecord);
    menu->addAction(this->actPersonalInformation);
    menu->addAction(this->actModifyFrinedNote);
    menu->exec(cur.pos());//关联到光标
}

bool MMessageBox::eventFilter(QObject *watched, QEvent *event)
{

    QString styleSheet;
    if(event->type()==QEvent::HoverEnter){
        styleSheet="#MMessageBox,#widget{border:2px solid #F7F7F7;"
                       " background:#F7F7F7;border-radius: 8px;}"
                       "";
        ui->widget->setStyleSheet(styleSheet);
    }
    else if(event->type()==QEvent::HoverLeave){
        if(this->isClick){
           styleSheet="#MMessageBox,#widget{border:2px solid #F8F7F7;"
                      " background:#F8F7F7;border-radius: 8px;}"
                      "";
        }else if(this->isTopMessageBox){
            styleSheet="#MMessageBox,#widget{border:2px solid #F7F7F7;"
                           " background:#F7F7F7;border-radius: 8px;}"
                           "";
        }else{

        styleSheet="#MMessageBox,#widget{border:2px solid #FFFFFF;"
                       " background:#FFFFFF;border-radius: 8px;}"
                       "";
        }
        ui->widget->setStyleSheet(styleSheet);
    }
    return QWidget::eventFilter(watched,event);//交给上层
}

void MMessageBox::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::MouseButton::LeftButton){
        this->clicked();
    }
}

void MMessageBox::topMessageBox_triggered()
{
    QString styleSheet;
    if(this->isTopMessageBox==false){//置顶
       if(this->isClick==false){
            styleSheet="#MMessageBox,#widget{border:2px solid #FFFFFF;"
                       " background:#FFFFFF;border-radius: 8px;}"
                       "";

       }else{
           styleSheet="#MMessageBox,#widget{border:2px solid #F8F7F7;"
                      " background:#F8F7F7;border-radius: 8px;}"
                      "";
       }
         ui->widget->setStyleSheet(styleSheet);
        this->setIsTopMessageBox(true);
        emit sigTopMessge(this);
    }else{//取消置顶
        if(this->isClick==false){
             styleSheet="#MMessageBox,#widget{border:2px solid #FFFFFF;"
                           " background:#FFFFFF;border-radius: 8px;}"
                         "";
        }else{
            styleSheet="#MMessageBox,#widget{border:2px solid #F8F7F7;"
                       " background:#F8F7F7;border-radius: 8px;}"
                       "";
        }
          ui->widget->setStyleSheet(styleSheet);
       this->setIsTopMessageBox(false);
       emit sigCancelTopMessage(this);
    }

}

void MMessageBox::messageNotDisturb_triggered()
{
     setISNotDisturb(!this->isNotDisturb);
    if(this->isNotDisturb)
        setLabelRoundRectPixmap(":images/mainWindow/messageBox/notDisturb.png",ui->labelNotDisturb,0);
    else
        ui->labelNotDisturb->clear();

}

void MMessageBox::removeMessageBox_triggered()
{
    emit sigremoveMessageBox(this);
}

void MMessageBox::cleanMessageRecord_triggered()
{
     //this->messageText.clear();
    ui->labelMessage->clear();
}

void MMessageBox::modifyFriendNote_triggered()
{

}

void MMessageBox::init()
{
    readQss("mMessageBox.qss",this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    isTopMessageBox=false;
    isClick=false;
    this->installEventFilter(this);
}

void MMessageBox::initUi()
{
    setLabelRoundRectPixmap(this->pictureName,ui->labelPicture,6);
    ui->labelName->setText(this->name);
    ui->labelMessage->setText(this->messageText);
    ui->labelStatus->setText(this->statusText);
    ui->labelTime->setText(this->messageTime);

    this->actTopMessageBox=new QAction(QString::fromUtf8("置顶"),this);
    this->actRemoveMessageBox=new QAction(QString::fromUtf8("移除会话"),this);
    this->actMessageNotDisturb=new QAction(QString::fromUtf8("消息免打扰"),this);
    this->actCleanMessageRecord=new QAction(QString::fromUtf8("清空会话记录"),this);
    this->actPersonalInformation=new QAction(QString::fromUtf8("个人信息"),this);
    this->actModifyFrinedNote=new QAction(QString::fromUtf8("修改好友备注"),this);

    if(!this->actTopMessageBox||!this->actRemoveMessageBox||!this->actMessageNotDisturb||
       !this->actCleanMessageRecord||!this->actPersonalInformation||!this->actModifyFrinedNote)
        return;
    this->installEventFilter(this);
    connect(this->actTopMessageBox,&QAction::triggered,this,&MMessageBox::topMessageBox_triggered);
    connect(this->actMessageNotDisturb,&QAction::triggered,this,&MMessageBox::messageNotDisturb_triggered);
    connect(this->actRemoveMessageBox,&QAction::triggered,this,[&](){ emit sigremoveMessageBox(this);});
    connect(this->actCleanMessageRecord,&QAction::triggered,this,[&](){  ui->labelMessage->clear();});
    connect(this->actModifyFrinedNote,&QAction::triggered,this,&MMessageBox::modifyFriendNote_triggered);
}

void MMessageBox::clicked()
{
   QString styleSheet="#MMessageBox,#widget{border:2px solid #F8F7F7;"
                       " background:#F8F7F7;border-radius: 8px;}"
                       "";
   ui->widget->setStyleSheet(styleSheet);
   this->setIsClick(true);
    emit  sigClicked(this);
}

MMessageBoxs::MMessageBoxs()
{
    this->layout=new QVBoxLayout();
    this->layout->addStretch();
    this->layout->setSpacing(0);
    this->layout->setMargin(0);
    this->messageBoxClicked=nullptr;
}


MMessageBox *MMessageBoxs::at(int index)
{
    return this->messageBoxs.at(index);
}
QVBoxLayout* MMessageBoxs::getLayout()
{
    return this->layout;
}

QVBoxLayout* MMessageBoxs::topMessageBox(MMessageBox *messageBox)
{
    if(messageBox==nullptr)return nullptr;
    int i;
    bool flag=false;
    for( i=0;i<this->messageBoxs.size();i++){
        if(messageBoxs[i]==messageBox){
            messageBoxs.remove(i);
            flag=true;
        }
    }
    if(!flag)return this->layout;
    this->messageBoxs.insert(0,messageBox);
    this->layout=new QVBoxLayout();
    for(int i=0;i<this->messageBoxs.size();i++){
        this->layout->addWidget(messageBoxs[i]);
    }
    this->layout->addStretch();
    this->layout->setSpacing(0);
    this->layout->setMargin(0);
    return this->layout;
}

QVBoxLayout* MMessageBoxs::addMMessageBox(MMessageBox *messageBox)
{
    connect(messageBox,SIGNAL(sigClicked(MMessageBox*)),this,SLOT(messageBox_triggered(MMessageBox*)));
    connect(messageBox,SIGNAL(sigTopMessge(MMessageBox*)),this,SLOT(topMessageBox_triggered(MMessageBox*)));
    connect(messageBox,SIGNAL(sigCancelTopMessage(MMessageBox*)),this,SLOT(cancelTopMessageBox_triggered(MMessageBox*)));
    connect(messageBox,SIGNAL(sigremoveMessageBox(MMessageBox*)),this,SLOT(removeMessageBox_triggered(MMessageBox*)));
    int index=0;
    if(this->messageBoxs.size())
        index=this->messageBoxs.size();
    QLayoutItem*layoutItem=this->layout->itemAt(index);
   // qDebug()<<this->messageBoxs.size();
    layout->removeItem(layoutItem);
    this->messageBoxs.push_back(messageBox);
    this->layout->addWidget(messageBox);
    this->layout->addStretch();
    return this->layout;
}

QVBoxLayout *MMessageBoxs::cancelTopMessageBox(MMessageBox *messageBox)
{
    if(messageBox==nullptr)return nullptr;
    int count=0;
    int i;
    bool flag=false;
    for( i=0;i<this->messageBoxs.size();i++){
        if(messageBoxs[i]==messageBox){
            messageBoxs.remove(i);
            flag=true;
        }
        if(messageBoxs[i]->getIsTopMessageBox())count++;
    }
    if(!flag)return this->layout;
    this->messageBoxs.insert(count,messageBox);
    this->layout=new QVBoxLayout();
    for(int i=0;i<this->messageBoxs.size();i++){
       // qDebug()<<this->messageBoxs[i]->getName();
        this->layout->addWidget(messageBoxs[i]);
    }
    this->layout->addStretch();
    this->layout->setSpacing(0);
    this->layout->setMargin(0);
    return this->layout;
}

QVBoxLayout *MMessageBoxs::removeMessageBox(MMessageBox *messageBox)
{
    if(messageBox==nullptr)return nullptr;
    int i;
    for( i=0;i<this->messageBoxs.size();i++){
        if(messageBoxs[i]==messageBox){
            messageBoxs.remove(i);
        }
    }
    this->layout=new QVBoxLayout();
    for(int i=0;i<this->messageBoxs.size();i++){
        //qDebug()<<this->messageBoxs[i]->getName();
        this->layout->addWidget(messageBoxs[i]);
    }
    this->layout->addStretch();
    this->layout->setSpacing(0);
    this->layout->setMargin(0);
    return this->layout;
}

void MMessageBoxs::setScrollArea(QScrollArea *scrollArea)
{
    this->scrollArea=scrollArea;
}

void MMessageBoxs::messageBox_triggered(MMessageBox *messageBox)
{
    if(this->messageBoxClicked==nullptr||this->messageBoxClicked==messageBox){
            this->messageBoxClicked=messageBox;
            return;
        }
        this->messageBoxClicked->cancelSelected();
    this->messageBoxClicked=messageBox;
}

void MMessageBoxs::topMessageBox_triggered(MMessageBox *messageBox)
{
    QVBoxLayout* vBoxLayout=topMessageBox(messageBox);
    QLayout*layout=scrollArea->widget()->layout();
    delete layout;
    scrollArea->widget()->setLayout(vBoxLayout);
}

void MMessageBoxs::cancelTopMessageBox_triggered(MMessageBox *messageBox)
{
    QVBoxLayout*vBoxLayout=cancelTopMessageBox(messageBox);
    QLayout*layout=scrollArea->widget()->layout();
    delete layout;
    scrollArea->widget()->setLayout(vBoxLayout);
}

void MMessageBoxs::removeMessageBox_triggered(MMessageBox *messageBox)
{
   QVBoxLayout*vBoxLayout=removeMessageBox(messageBox);
   QLayout*layout=scrollArea->widget()->layout();
   delete layout;
   scrollArea->widget()->setLayout(vBoxLayout);
}
