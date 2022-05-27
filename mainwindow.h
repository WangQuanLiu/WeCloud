#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "framelessmainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public FramelessMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
      bool eventFilter(QObject*,QEvent*);
private:
      void labelMin_Clicked();
      void labelMax_Clicked();
      void labelClose_Clicked();
      void initFilter();
private slots:
    void initForm();
    void titleDblClick();
};

#endif // MAINWINDOW_H
