#include "menuadddialog.h"
#include "ui_menuadddialog.h"

bool MenuAddDialog::eventFilter(QObject *watched, QEvent *event)
{
   if(watched==ui->labelMessage){
        if(event->type()==QEvent::HoverEnter){
             message_hover();

        }else if(event->type()==QEvent::HoverLeave){
             message_unClick();
        }
   }
   else if(watched==ui->labelContact){
        if(event->type()==QEvent::HoverEnter){
            contact_hover();

        } else if(event->type()==QEvent::HoverLeave){
            contact_unClick();
        }
    }
   else if(watched==ui->labelCalendar){
        if(event->type()==QEvent::HoverEnter){
            calendar_hover();
        }else if(event->type()==QEvent::HoverLeave){
            calendar_unClcik();
        }
   }
   else if(watched==ui->labelMeet){
       if(event->type()==QEvent::HoverEnter){
           meet_hover();
       }else if(event->type()==QEvent::HoverLeave){
           meet_unClick();
       }
    }
   else if(watched==ui->labelSchedule){
        if(event->type()==QEvent::HoverEnter){
            schedule_hover();
        }  else if(event->type()==QEvent::HoverLeave){
            schedule_unClick();
        }
    }
     return QDialog::eventFilter(watched,event);//½»¸øÉÏ²ã
}

MenuAddDialog::MenuAddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuAddDialog)
{
    ui->setupUi(this);

  //  ui->widget->setStyleSheet("#widget,#MenuAddDialog{border:2px solid #EAEAEA;background:#EAEAEA;border-radius: 8px;}QLabel{color:#777777;}");
    init();

}

MenuAddDialog::~MenuAddDialog()
{
    delete ui;
}

void MenuAddDialog::contact_unClick()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/contact.png",ui->labelContact,10);
}

void MenuAddDialog::meet_unClick()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/meet.png",ui->labelMeet,10);
}

void MenuAddDialog::calendar_unClcik()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/calendar.png",ui->labelCalendar,10);
}

void MenuAddDialog::schedule_unClick()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/schedule.png",ui->labelSchedule,10);
}

void MenuAddDialog::team_unClick()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/team.png",ui->labelTeam,10);
}

void MenuAddDialog::message_hover()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/message_hover.png",ui->labelMessage,10);
}

void MenuAddDialog::contact_hover()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/contact_hover.png",ui->labelContact,10);
}

void MenuAddDialog::meet_hover()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/meet_hover.png",ui->labelMeet,10);
}

void MenuAddDialog::calendar_hover()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/calendar_hover.png",ui->labelCalendar,10);
}

void MenuAddDialog::schedule_hover()
{
     setLabelRoundRectPixmap(":images/mainWindow/menuAdd/schedule_hover.png",ui->labelSchedule,10);
}

void MenuAddDialog::init()
{
    readQss("menuAdd.qss",this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    message_unClick();
    contact_unClick();
    meet_unClick();
    calendar_unClcik();
    schedule_unClick();
    team_unClick();
    this->setAttribute(Qt::WA_Hover,true);
    this->installEventFilter(this);
    ui->labelMessage->installEventFilter(this);
    ui->labelCalendar->installEventFilter(this);
    ui->labelContact->installEventFilter(this);
    ui->labelSchedule->installEventFilter(this);
    ui->labelMeet->installEventFilter(this);
    ui->labelTeam->installEventFilter(this);
}

void MenuAddDialog::message_unClick()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/message.png",ui->labelMessage,10);
}


