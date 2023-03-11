#include "transferdialog.h"
#include "ui_transferdialog.h"
#include <unistd.h>

transferDialog::transferDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transferDialog)
{
    ui->setupUi(this);

    closeTimer = new QTimer(this);
    connect(closeTimer,SIGNAL(timeout()),
            this,SLOT(dialogClose()));

    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    setWindowModality(Qt::WindowModal);
    setFixedSize(this->width(),this->height());
}

transferDialog::~transferDialog()
{
   // delete ui;
}

void transferDialog::timeStart()
{
    QString message;
    if (type == TRANSFER)
    {
        message = QString::fromUtf8("数据传输中...");
    }
    else if (type == ERASE)
    {
        message = QString::fromUtf8("数据删除中...");
    }
    else if (type == FORMAT)
    {
        message = QString::fromUtf8("内存初始化中...");
    }
    else if (type == UPDATE)
    {
        message = QString::fromUtf8("更新中...");
    }
    //m_timer->start(120000);
    ui->label->setText(message);
}

void transferDialog::setMessageType(int type)
{
    this->type = type;
}

void transferDialog::onTimeOut(int type)
{
    if (type == 0)
    {
        ui->label->setText(QString::fromUtf8("完成"));
    }
    else if (type == 1)
    {
        ui->label->setText(QString::fromUtf8("失败"));
    }
    //m_timer->stop();
    //emit transferComplete();
    closeTimer->start(5000);
}

void transferDialog::dialogClose()
{
    closeTimer->stop();
    this->hide();
    emit transferComplete();
}
