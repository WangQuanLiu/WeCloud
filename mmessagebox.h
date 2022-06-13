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
    QAction*actTopMessageBox;//置顶聊天
    QAction*actRemoveMessageBox;//移除会话
    QAction*actMessageNotDisturb;//消息免打扰
    QAction*actPersonalInformation;//个人资料
    QAction*actCleanMessageRecord;//清空聊天记录
    QAction*actModifyFrinedNote;//修改好友备注
    bool isTopMessageBox;//是否置顶聊天
};

#endif // MMESSAGEBOX_H
