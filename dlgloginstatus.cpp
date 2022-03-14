#include "dlgloginstatus.h"
#include "ui_dlgloginstatus.h"

dlgLoginStatus::dlgLoginStatus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgLoginStatus)
{
    ui->setupUi(this);
}

dlgLoginStatus::~dlgLoginStatus()
{
    delete ui;
}
