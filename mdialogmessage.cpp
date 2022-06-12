#include "mdialogmessage.h"
#include "ui_mdialogmessage.h"

MDialogMessage::MDialogMessage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MDialogMessage)
{
    ui->setupUi(this);
    init();
}

MDialogMessage::~MDialogMessage()
{
    delete ui;
}

void MDialogMessage::init()
{
    readQss("mDialogMessage.qss",this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}
