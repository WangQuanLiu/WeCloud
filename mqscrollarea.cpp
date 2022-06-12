#include "mqscrollarea.h"

MQScrollArea::MQScrollArea(QWidget *parent)
    : QScrollArea{parent}
{
    initUI();
}

void MQScrollArea::initUI()
{

   this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   QWidget*widget=new QWidget();
   if(widget==nullptr)return;

   QVBoxLayout* layout=new QVBoxLayout;

   MMessageBox*message=new MMessageBox();
   message->setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
   //layout->addStretch(0);
   layout->addWidget(message);
  //  widget->setLayout(layout);
    //this->setWidget(message);
   this->setLayout(layout);
}

