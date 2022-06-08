#ifndef FRAMELESSDIALOG_H
#define FRAMELESSDIALOG_H

#include <QObject>
#include <QDialog>
#ifdef quc
class Q_DECL_EXPORT FrameLessDialog:public QDialog
#else
namespace Ui{
    class MenuAddDialog;
}
class FrameLessDialog:public QDialog
#endif
{
    Q_OBJECT
public:
    explicit FrameLessDialog(QWidget *parent = 0);
private:
    //�洢����Ĭ�ϵ�����
    Qt::WindowFlags flags;
    Ui::MenuAddDialog* ui;
};

#endif // FRAMELESSDIALOG_H
