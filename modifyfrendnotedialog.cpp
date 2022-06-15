#include "modifyfrendnotedialog.h"
#include "ui_modifyfrendnotedialog.h"

ModifyFrendNoteDialog::ModifyFrendNoteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyFrendNoteDialog)
{
    ui->setupUi(this);
}

ModifyFrendNoteDialog::~ModifyFrendNoteDialog()
{
    delete ui;
}
