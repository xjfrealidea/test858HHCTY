#include "timeeditdialog.h"
#include "ui_timeeditdialog.h"
#include <QDebug>
#include <QTime>
#include <QDate>
#include "macro.h"
#include <QProcess>
#include "widgetshowtype.h"

TimeEditDialog::TimeEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeEditDialog)
{
    ui->setupUi(this);

    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    setWindowModality(Qt::WindowModal);
    setFixedSize(this->width(),this->height());

    connect(ui->dateTimeEdit,SIGNAL(enterPress()),
            this,SLOT(enterPress()));
    connect(ui->dateTimeEdit,SIGNAL(escPress()),
            this,SLOT(escPress()));
}

TimeEditDialog::~TimeEditDialog()
{
    delete ui;
    deleteLater();
}

bool TimeEditDialog::timeEdit()
{
    QDate date = ui->dateTimeEdit->date();
    QTime time = ui->dateTimeEdit->time();

    QString cmd(QString("date -s \""));
    cmd += date.toString("yyyy-MM-dd ");
  //  cmd += QString(" ");
    cmd += time.toString("hh:mm:ss\"");
//    cmd += QString("\"");
    qDebug() << cmd;
    QProcess p;
    p.start(cmd);
    p.waitForFinished();
    int ret = p.exitCode();
    if (ret != 0)
    {
        return false;
    }

    p.start("hwclock -w");
    p.waitForFinished();
    ret = p.exitCode();
    if (ret != 0)
    {
        return false;
    }

    return true;
}

void TimeEditDialog::getFocus()
{
    ui->dateTimeEdit->setFocus();
}

void TimeEditDialog::enterPress()
{
    qDebug() << "enter";
    timeEdit();
    this->close();
}

void TimeEditDialog::escPress()
{
    this->close();
}

void TimeEditDialog::showEvent(QShowEvent *event)
{
    qDebug() << "dialog show";
    ui->dateTimeEdit->setTime(QTime::currentTime());
    ui->dateTimeEdit->setDate(QDate::currentDate());

    int h = WidgetShow::getWindowHeight();
    int w = WidgetShow::getWindowWidth();

    this->setGeometry((w-this->width())/2,(h-this->height())/2,this->width(),this->height());
}

void TimeEditDialog::keyPressEvent(QKeyEvent *event)
{
//    if (KEY_ENTER == event->key())
//    {
//        qDebug() << "enter";
//        timeEdit();
//        this->close();
//    }
//    else if (KEY_ESC == event->key())
//    {
//        this->close();
//    }
//    else if (KEY_UP == event->key())
//    {

//    }
}
