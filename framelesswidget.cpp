#include "framelesswidget.h"

FrameLessWidget::FrameLessWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrameLessWidget)
{
    ui->setupUi(this);
}

void FrameLessWidget::init()
{
    this->setMinimumSize(QSize(900,600));//´°¿Ú´óÐ¡

}

FrameLessWidget::~FrameLessWidget()
{
    delete ui;
}
