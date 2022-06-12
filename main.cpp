#include <QApplication>
#include"qdlglogin.h"
#include "mainwindow.h"
#include "mcommon.h"
#include "menuadddialog.h"
#include "accountpicturedialog.h"
#include "mdialogmessage.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    MDialogMessage message;
    message.exec();

    MainWindow m;
    m.show();

    return a.exec();
}

