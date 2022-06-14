#ifndef MENUADDDIALOG_H
#define MENUADDDIALOG_H

#include <QDialog>
#include "mcommon.h"
namespace Ui {
class MenuAddDialog;
}
using namespace Common;
class MenuAddDialog : public QDialog
{
    Q_OBJECT
public slots:
      bool eventFilter(QObject*,QEvent*);
public:
    explicit MenuAddDialog(QWidget *parent = nullptr);
    ~MenuAddDialog();

    bool getIsShow();
    void showed();
    void hiddened();
private slots:


private:
    void message_unClick();
    void contact_unClick();
    void meet_unClick();
    void calendar_unClcik();
    void schedule_unClick();
    void team_unClick();

    void message_hover();
    void contact_hover();
    void meet_hover();
    void calendar_hover();
    void schedule_hover();
    void team_hover();
    void init();

    bool isShow;
    Ui::MenuAddDialog *ui;
};

#endif // MENUADDDIALOG_H
