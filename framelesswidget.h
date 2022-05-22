#ifndef FRAMELESSWIDGET_H
#define FRAMELESSWIDGET_H

#include <QWidget>

namespace Ui {
class FrameLessWidget;
}

class FrameLessWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FrameLessWidget(QWidget *parent = nullptr);
    void init();
    ~FrameLessWidget();
protected:
    bool nativeEvent(const QByteArray&eventType,void*message,long*result);
    void mousePresssEvent(QMouseEvent*e);
    void mouseMoveEvent(QMouseEvent*e);

private:

    Ui::FrameLessWidget *ui;
};

#endif // FRAMELESSWIDGET_H
