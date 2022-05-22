#ifndef MFRAMELESSWIDGET_H
#define MFRAMELESSWIDGET_H

#include <QObject>
#include <QWidget>
#include <windows.h>
#include <windowsx.h>
#include <QMouseEvent>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QPicture>
#include <QHBoxLayout>
class MFrameLessWidget : public QWidget
{
    enum tagCursorCtrlStyle{
        e_cursorNormal=0,//普通鼠标
        e_cursorHor, //水平拉伸
        e_cursorVer, //垂直拉伸
        e_cursorHorVer //水平和垂直拉伸
    };

    Q_OBJECT
public:
    explicit MFrameLessWidget(QWidget *parent = nullptr);
    ~MFrameLessWidget();
    void setWindowSize(unsigned int width,unsigned int height);
protected :
    void init();
    void initTitleWidget();
    void mousePressEvent(QMouseEvent*event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent*event)Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent*event)Q_DECL_OVERRIDE;
    int setCursorStyle(const QPoint&curPoint);
private:
   QPoint m_MousePressPos;//鼠标点击
   QPoint m_MouseMovePos;//鼠标移动
   bool m_bMousePressed;//鼠标是否按下
   int  m_nMouseResize;//鼠标设置大小
   bool m_bMouseResizePressed;//设置大小的按下
   QPoint m_ResizePressPos;//设置大小鼠标按下的点
   QWidget*m_pTitleWidget;//标题栏
   QLabel* m_maxLabel;
signals:

};

#endif // MFRAMELESSWIDGET_H
