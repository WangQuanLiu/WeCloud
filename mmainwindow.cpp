#include "mmainwindow.h"
#include "ui_mmainwindow.h"

MMainWindow::MMainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MMainWindow)
{
    ui->setupUi(this);
    init();
}

MMainWindow::~MMainWindow()
{
    delete ui;
}
/*
   初始化窗口
*/
void MMainWindow::init() {

    this->setMinimumSize(QSize(900,600));//窗口大小
   // this->setWindowFlags(this->windowFlags()|Qt::FramelessWindowHint);

   // setWindowFlags(Qt::FramelessWindowHint);//无边框
    //setAttribute(Qt::WA_TranslucentBackground);
    //setAttribute(Qt::WA_StyledBackground);
    //setAttribute(Qt::WA_Hover);

}


/*
bool MMainWindow::event(QEvent *event)
{
    if(event->type()==QEvent::HoverMove){
        QHoverEvent*hoverEvent=static_cast<QHoverEvent*>(event);
        QMouseEvent mouseEvent(QEvent::MouseMove,hoverEvent->pos(), Qt::NoButton,Qt::NoButton,Qt::NoModifier);
        mouseMoveEvent(&mouseEvent);
    }
    return QWidget::event(event);
}

void MMainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        m_bIsPressed=true;
        m_pressPoint=event->globalPos();
    }
    return QWidget::mousePressEvent(event);
}

void MMainWindow::mouseMoveEvent(QMouseEvent *event)
{

    if(m_bIsPressed){
        if(m_bIsResizing){
            m_movePoint=event->globalPos()-m_pressPoint;
            m_pressPoint+=m_movePoint;
        }else{
            if(!m_bIsDoublePressed&&windowState()==Qt::WindowMaximized){


            }
        }
    }
}

void MMainWindow::restoreWidget()
{

}
*/

