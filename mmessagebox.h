#pragma execution_character_set("utf-8")
#ifndef MMESSAGEBOX_H
#define MMESSAGEBOX_H

#include <QWidget>
#include "mcommon.h"
#include <QPalette>
#include <QColor>
#include <QFont>
#include <QAction>
#include <QMenu>
#include <QCursor>
namespace Ui {
class MMessageBox;
}
using  Common::setLabelRoundRectPixmap;
class MMessageBox : public QWidget
{
    Q_OBJECT

public:
    explicit MMessageBox(QWidget *parent = nullptr);
    ~MMessageBox();
    void setMessageBox(const QString&pictureName,const QString&name,const QString&messageText,const QString&statusText,const QString&messageTime);
    MMessageBox& operator=(const MMessageBox&obj);
public slots:
    void contextMenuEvent(QContextMenuEvent*event);
private:
    void init();
    void initUi();
    QString pictureName,name,messageText,statusText,messageTime;
private:
    Ui::MMessageBox *ui;
    QMenu*menu;
    QAction*actTopMessageBox;//�ö�����
    QAction*actRemoveMessageBox;//�Ƴ��Ự
    QAction*actMessageNotDisturb;//��Ϣ�����
    QAction*actPersonalInformation;//��������
    QAction*actCleanMessageRecord;//��������¼
    QAction*actModifyFrinedNote;//�޸ĺ��ѱ�ע
    bool isTopMessageBox;//�Ƿ��ö�����
};

#endif // MMESSAGEBOX_H
