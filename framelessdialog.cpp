#include "framelessdialog.h"

FrameLessDialog::FrameLessDialog(QWidget *parent) : QDialog(parent)
{
#if (QT_VERSION >= QT_VERSION_CHECK(5,3,0))
    this->setAttribute(Qt::WA_TranslucentBackground);
#endif
    flags = this->windowFlags();
    //设置无边框属性
    this->setWindowFlags(flags | Qt::FramelessWindowHint);
    //安装事件过滤器识别拖动
    this->installEventFilter(this);
}
