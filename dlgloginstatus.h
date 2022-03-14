#ifndef DLGLOGINSTATUS_H
#define DLGLOGINSTATUS_H

#include <QDialog>

namespace Ui {
class dlgLoginStatus;
}

class dlgLoginStatus : public QDialog
{
    Q_OBJECT

public:
    explicit dlgLoginStatus(QWidget *parent = nullptr);
    ~dlgLoginStatus();

private:
    Ui::dlgLoginStatus *ui;
};

#endif // DLGLOGINSTATUS_H
