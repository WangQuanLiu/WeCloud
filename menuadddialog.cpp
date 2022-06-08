#include "menuadddialog.h"
#include "ui_menuadddialog.h"

MenuAddDialog::MenuAddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuAddDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    ui->widget->setStyleSheet("#widget,#MenuAddDialog{border:2px solid #EAEAEA;background:#EAEAEA;border-radius: 8px;}QLabel{color:#777777;}");
    message_unClick();
    contact_unClick();
    meet_unClick();
    calendar_unClcik();
    schedule_unClick();
    team_unClick();
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

void MenuAddDialog::message_unClick()
{
    setLabelRoundRectPixmap(":images/mainWindow/menuAdd/message.png",ui->labelMessage,10);
}
