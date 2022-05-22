#include "mframelesswidget.h"

MFrameLessWidget::MFrameLessWidget(QWidget *parent)
    : QWidget(parent)
{
    init();
    initTitleWidget();
}

MFrameLessWidget::~MFrameLessWidget()
{

}

void MFrameLessWidget::setWindowSize(unsigned int width, unsigned int height)
{
    this->setMinimumSize(QSize(width,height));
}

void MFrameLessWidget::init()
{
    m_bMousePressed=false;
    m_nMouseResize=e_cursorNormal;
    m_bMouseResizePressed=false;
    m_pTitleWidget=nullptr;
    this->setMinimumSize(QSize(900,600));//窗口大小
    this->setWindowFlags(Qt::FramelessWindowHint);
    setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    setMouseTracking(true);
}

void MFrameLessWidget::initTitleWidget()
{
    m_pTitleWidget=new QWidget(this);
    m_pTitleWidget->setFixedHeight(40);
    m_pTitleWidget->setMinimumWidth(800);
    m_pTitleWidget->move(0,0);
    QHBoxLayout*layout=new QHBoxLayout;
    m_maxLabel=new QLabel("maxLabel");
    QPicture maxButtonPicture;
    maxButtonPicture.load(QString(":/images/minButton.png"));
    m_maxLabel->setPicture(maxButtonPicture);
    layout->addWidget(m_maxLabel);
    m_pTitleWidget->setLayout(layout);
    m_pTitleWidget->show();
}
void MFrameLessWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton&&
            m_pTitleWidget->rect().contains(event->globalPos()-this->frameGeometry().topLeft())){

        m_MousePressPos=event->globalPos();
        m_bMousePressed=true;
    }
    if(m_nMouseResize!=e_cursorNormal){
        m_bMouseResizePressed=true;
        m_ResizePressPos=event->pos();
    }
    event->ignore();
}

void MFrameLessWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bMousePressed){

        m_MouseMovePos=event->globalPos();
        this->move(this->pos()+m_MouseMovePos-m_MousePressPos);
        m_MousePressPos=m_MouseMovePos;
        return;
    }
    QPoint curPoint=event->pos();

    if(!m_bMouseResizePressed){
        m_nMouseResize=setCursorStyle(curPoint);
    }

    if(m_bMouseResizePressed&&!m_ResizePressPos.isNull()){

       switch(m_nMouseResize){

       case e_cursorHor:
           this->resize(curPoint.x(),this->height());
           break;
       case e_cursorVer:
           this->resize(this->width(),curPoint.y());
           break;
       case e_cursorHorVer:
           this->resize(curPoint.x(),curPoint.y());
           break;
       default:
           break;
       }
    }

       event->ignore();
}

void MFrameLessWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        m_bMousePressed=false;
        m_bMouseResizePressed=false;
        m_ResizePressPos.setX(0);
        m_ResizePressPos.setY(0);
        m_nMouseResize=setCursorStyle(event->pos());
    }
    event->ignore();
}
/*
 *功能：设置当前鼠标样式
 */
int MFrameLessWidget::setCursorStyle(const QPoint &curPoint)
{
    int nCurwidth=this->width();
    int nCurHeight=this->height();
    int nRes=e_cursorNormal;

    if((nCurwidth-curPoint.x()<=3)&&(nCurHeight-curPoint.y()<=3)){
        setCursor(Qt::SizeFDiagCursor);
        nRes=e_cursorHorVer;
    }
    else if(nCurwidth-curPoint.x()<=3){
        setCursor(Qt::SizeHorCursor);
        nRes=e_cursorHor;
    }
    else if(nCurHeight-curPoint.y()<=3){
        setCursor(Qt::SizeVerCursor);
        nRes=e_cursorVer;
    }else{
        setCursor(Qt::ArrowCursor);
        nRes=e_cursorNormal;
    }


    return nRes;
}
