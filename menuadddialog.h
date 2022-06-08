#ifndef MENUADDDIALOG_H
#define MENUADDDIALOG_H

#include <QDialog>
#include "framelessdialog.h"
#include "mcommon.h"
namespace Ui {
class MenuAddDialog;
}
using namespace Common;
class MenuAddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MenuAddDialog(QWidget *parent = nullptr);
    ~MenuAddDialog();
    void message_unClick();
    void contact_unClick();
    void meet_unClick();
    void calendar_unClcik();
    void schedule_unClick();
    void team_unClick();
private:
    MQObjects objects;
    Ui::MenuAddDialog *ui;
};

#endif // MENUADDDIALOG_H
