#ifndef MMESSAGEBOX_H
#define MMESSAGEBOX_H

#include <QWidget>
#include "mcommon.h"
#include <QPalette>
#include <QColor>
#include <QFont>
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
private:
    void init();
    void initUi();
    QString pictureName,name,messageText,statusText,messageTime;
private:
    Ui::MMessageBox *ui;
};

#endif // MMESSAGEBOX_H
