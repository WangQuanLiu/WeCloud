#ifndef MDIALOGMESSAGE_H
#define MDIALOGMESSAGE_H

#include <QDialog>
#include "mcommon.h"
namespace Ui {
class MDialogMessage;
}

class MDialogMessage : public QDialog
{
    Q_OBJECT

public:
    explicit MDialogMessage(QWidget *parent = nullptr);
    ~MDialogMessage();

private:
    void init();
    Ui::MDialogMessage *ui;
};

#endif // MDIALOGMESSAGE_H
