#include <QApplication>
#include"qdlglogin.h"
#include "mainwindow.h"
#include "mcommon.h"
#include "menuadddialog.h"
#include "accountpicturedialog.h"
#include "mmessagebox.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

 //  MMessageBox message;
  // message.setMessageBox(":images/mainWindow/friend/accountPicture/2510840085.jpg","123","123","","12:30");
  //  message.show();

    MainWindow m;
    //m.show();
    m.show();
    return a.exec();
}

