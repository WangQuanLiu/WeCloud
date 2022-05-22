#ifndef MMAINWINDOW_H
#define MMAINWINDOW_H

#include <QWidget>
#include <QHoverEvent>
#include <QMouseEvent>
#include <windowsx.h>
#include <windows.h>
namespace Ui {
class MMainWindow;
}

class MMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MMainWindow(QWidget *parent = nullptr);
    ~MMainWindow();

    void init();
private:
    /*
    bool event(QEvent *event);
    void mousePressEvent(QMouseEvent*event);
    bool m_bIsPressed=false,m_bIsResizing=false,m_bIsDoublePressed=false;
    void mouseMoveEvent(QMouseEvent*event);
    void restoreWidget();
    QPoint m_pressPoint=QPoint(0,0),m_movePoint=QPoint(0,0);
    */

    Ui::MMainWindow *ui;
};

#endif // MMAINWINDOW_H
