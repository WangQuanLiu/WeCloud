#ifndef MQSCROLLAREA_H
#define MQSCROLLAREA_H

#include <QObject>
#include <QWidget>
#include <QScrollArea>
#include <QScrollBar>
#include <QVBoxLayout>
#include "mmessagebox.h"
class MQScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    explicit MQScrollArea(QWidget *parent = nullptr);
    void initUI();
signals:

};

#endif // MQSCROLLAREA_H
