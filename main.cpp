#include <QApplication>
#include"qdlglogin.h"
#include "mainwindow.h""
#include "mcommon.h"
void init();
int main(int argc, char *argv[])
{
    //init();
    QApplication a(argc, argv);
    QDlgLogin*dlgLogin=new QDlgLogin();

   MainWindow m;
   m.show();
/*    if(dlgLogin->exec()==QDialog::Accepted){
        QDlgLogin login;
        login.show();

  }
*/
    return a.exec();
}
void init(){
    setNormalShowScale();

}
