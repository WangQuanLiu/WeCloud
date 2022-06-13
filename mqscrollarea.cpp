#include "mqscrollarea.h"
#include "qpushbutton.h"

MQScrollArea::MQScrollArea(QWidget *parent)
    : QScrollArea{parent}
{
    initUI();
}

void MQScrollArea::initUI()
{
   // this->setStyleSheet("QScrollArea{background:#FFFFFF;}");
   this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QWidget*widget=new QWidget();
    if(widget==nullptr)return;
    QVBoxLayout* layout=new QVBoxLayout;
    layout->addSpacing(0);
    MMessageBox*message=new MMessageBox();
    message->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
    MMessageBox*message2=new MMessageBox();
    message2->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
    MMessageBox*message3=new MMessageBox();
    message3->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
    MMessageBox*message4=new MMessageBox();
    message4->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
    MMessageBox*message5=new MMessageBox();
    message5->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
    MMessageBox*message6=new MMessageBox();
    message6->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
    MMessageBox*message7=new MMessageBox();
    message7->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
    MMessageBox*message8=new MMessageBox();
    message8->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
    MMessageBox*message9=new MMessageBox();
    message9->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
    MMessageBox*message10=new MMessageBox();
    message10->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
    MMessageBox*message11=new MMessageBox();
    message11->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
    layout->addWidget(message);
    layout->addWidget(message2);
    layout->addWidget(message3);
    layout->addWidget(message4);
    layout->addWidget(message5);
    layout->addWidget(message6);
    layout->addWidget(message7);
    layout->addWidget(message8);
    layout->addWidget(message9);
    layout->addWidget(message10);
    layout->addWidget(message11);
    QPushButton*push1=new QPushButton();
    push1->setMinimumSize(100,100);
     push1->setMaximumSize(100,100);
    QPushButton*push2=new QPushButton();
    //layout->addWidget(push1);
    //layout->addWidget(push2);
    layout->addStretch();
    layout->setSpacing(0);
    layout->setMargin(0);
   // widget->setLayout(layout);
   //this->widget()->setLayout(layout);
  // this->setWidget(widget);
    this->setLayout(layout);
    this->setFrameShape(QFrame::NoFrame);

}

