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
#include <QList>
#include <QVector>
#include <QVBoxLayout>
#include <QScrollArea>
namespace Ui {
class MMessageBox;
class MMessageBoxs;
}
using  Common::setLabelRoundRectPixmap;
using MMessageBox_ptr=Ui::MMessageBox*;
class MMessageBox : public QWidget
{
    Q_OBJECT

public:
    explicit MMessageBox(QWidget *parent = nullptr);
    ~MMessageBox();
    void setMessageBox(const QString&pictureName,const QString&name,const QString&messageText,const QString&statusText,const QString&messageTime,bool isNotDisturb=false);
    MMessageBox& operator=(const MMessageBox&obj);
    bool getIsClick();
    void setIsClick(bool isClick);
    void cancelSelected();
    void cancelTopMessageBox();
    bool getIsTopMessageBox();
    void setIsTopMessageBox(bool isTopMessageBox);
    void setISNotDisturb(bool isNotDisturb);
    QString getName();
public slots:
    void contextMenuEvent(QContextMenuEvent*event);
    bool eventFilter(QObject*watched,QEvent*event);
    void mousePressEvent(QMouseEvent*event);
private slots:
       void topMessageBox_triggered();
       void messageNotDisturb_triggered();
       void removeMessageBox_triggered();
       void cleanMessageRecord_triggered();
       void modifyFriendNote_triggered();
private:
   inline void init();
   inline void initUi();
   inline void clicked();
    QString pictureName,name,messageText,statusText,messageTime;
Q_SIGNALS:
    void sigClicked(MMessageBox*);
    void sigTopMessge(MMessageBox*);
    void sigNotDisturb(MMessageBox*);
    void sigCancelTopMessage(MMessageBox*);
    void sigremoveMessageBox(MMessageBox*);
    void sigCleanMessageRecord(MMessageBox*);
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
    bool isClick;//�Ƿ���
    bool isNotDisturb;//�Ƿ��������
};
class MMessageBoxs: public QWidget{
        Q_OBJECT
public:
    MMessageBoxs();
    MMessageBox*at(int index);
    QVBoxLayout* getLayout();
    QVBoxLayout* addMMessageBox(MMessageBox*messageBox);
    void setScrollArea(QScrollArea*scrollArea);
public slots:
       void messageBox_triggered(MMessageBox*);
       void topMessageBox_triggered(MMessageBox*);
       void cancelTopMessageBox_triggered(MMessageBox*);
       void removeMessageBox_triggered(MMessageBox*);
private:
       inline QVBoxLayout* topMessageBox(MMessageBox*messageBox);
       inline QVBoxLayout* cancelTopMessageBox(MMessageBox*messageBox);
       inline QVBoxLayout* removeMessageBox(MMessageBox*messageBox);
private:
    QScrollArea*scrollArea;
    QVector<MMessageBox*>messageBoxs;
    QVBoxLayout*layout;
    MMessageBox*messageBoxClicked;
};

#endif // MMESSAGEBOX_H
