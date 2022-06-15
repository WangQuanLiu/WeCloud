#ifndef MODIFYFRENDNOTEDIALOG_H
#define MODIFYFRENDNOTEDIALOG_H

#include <QDialog>

namespace Ui {
class ModifyFrendNoteDialog;
}

class ModifyFrendNoteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyFrendNoteDialog(QWidget *parent = nullptr);
    ~ModifyFrendNoteDialog();

private:
    Ui::ModifyFrendNoteDialog *ui;
};

#endif // MODIFYFRENDNOTEDIALOG_H
