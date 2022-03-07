#include "qdlglogin.h"
#include "ui_qdlglogin.h"

QDlgLogin::QDlgLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QDlgLogin)
{
    ui->setupUi(this);
    ui
}

QDlgLogin::~QDlgLogin()
{
    delete ui;
}
