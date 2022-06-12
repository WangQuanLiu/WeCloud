#include "framelessdialog.h"

FrameLessDialog::FrameLessDialog(QWidget *parent) : QDialog(parent)
{
#if (QT_VERSION >= QT_VERSION_CHECK(5,3,0))
    this->setAttribute(Qt::WA_TranslucentBackground);
#endif
    flags = this->windowFlags();
    //�����ޱ߿�����
    this->setWindowFlags(flags | Qt::FramelessWindowHint);
    //��װ�¼�������ʶ���϶�
    this->installEventFilter(this);
}
