#include "mqscrollarea.h"

MQScrollArea::MQScrollArea(QWidget *parent)
    : QWidget{parent}
{

}

void MQScrollArea::initUI()
{
   QScrollArea*scrollArea=new QScrollArea();
   if(scrollArea==nullptr)return;
   scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   QWidget*widget=new QWidget();
   if(scrollArea==nullptr)return;
   scrollArea->setWidget(widget);
   QVBoxLayout* layout=new QVBoxLayout;
   widget->setLayout(layout);
}
