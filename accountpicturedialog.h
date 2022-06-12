#ifndef ACCOUNTPICTUREDIALOG_H
#define ACCOUNTPICTUREDIALOG_H

#include <QDialog>

namespace Ui {
class AccountPictureDialog;
}

class AccountPictureDialog : public QDialog
{
    Q_OBJECT
public slots:
      bool eventFilter(QObject*,QEvent*);
public:
    explicit AccountPictureDialog(QWidget *parent = nullptr);
    ~AccountPictureDialog();

private:
    void init();
    Ui::AccountPictureDialog *ui;
};

#endif // ACCOUNTPICTUREDIALOG_H
