#include "datatransfermenu.h"
#include "ui_datatransfermenu.h"
#include "macro.h"
#include <QGridLayout>
#include <cstdlib>
#include <QString>
#include <QFile>
#include "widgetshowtype.h"
#include "digitalclock.h"
#include <QDebug>
#include <QDir>
#include "filedatainfo.h"

DataTransferMenu::DataTransferMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataTransferMenu)
{
    ui->setupUi(this);

    QGridLayout *layout = new QGridLayout(ui->centralwidget);
    layout->addWidget(ui->titleLabel,0,0,1,5);
    layout->addWidget(ui->spaceLabel1,1,1,1,3);
    layout->addWidget(ui->pcTransferButton,2,2,1,1);
    layout->addWidget(ui->manualTransferButton,3,2,1,1);
    layout->addWidget(ui->eraseButton,4,2,1,1);
    layout->addWidget(ui->formatButton,5,2,1,1);
    layout->addWidget(ui->spaceLabel2,6,2,1,1);
    layout->addWidget(ui->sendButton,7,2,1,1);
    layout->addWidget(ui->receiveButton,8,2,1,1);

    ui->titleLabel->setText(QString::fromUtf8("数据管理菜单"));
    ui->pcTransferButton->setVisible(false);
    ui->manualTransferButton->setText((QString::fromUtf8("数据导出")));
    ui->eraseButton->setText(QString::fromUtf8("数据删除"));
    ui->formatButton->setText(QString::fromUtf8("!!! 内存初始化 !!!"));
    ui->sendButton->setVisible(false);
    ui->receiveButton->setVisible(false);

    ui->currentTime->setVisible(false);
//    layout->addWidget(ui->currentTime,9,0,1,2);

    DigitalClock* currentTime = new DigitalClock();
    layout->addWidget(currentTime,9,0,1,2);
    layout->setVerticalSpacing(2);
    layout->setContentsMargins(5,5,5,0);

    //d = new transferDialog(this);
    //d->setMessageType(TRANSFER);
    //connect(d,SIGNAL(transferComplete()),
            //this,SLOT(transferComplete()));

    manualtransfermenu = new ManualTransferMenu(this);
    connect(this,SIGNAL(manualtransferStart()),
            manualtransfermenu,SLOT(transferMenuStart()));
    connect(manualtransfermenu,SIGNAL(menuClose()),
            this,SLOT(manualtransferClose()));

    erasedatamenu = new EraseDataMenu(this);
    connect(this,SIGNAL(erasedataStart()),
            erasedatamenu,SLOT(eraseMenuStart()));
    connect(erasedatamenu,SIGNAL(menuClose()),
            this,SLOT(erasedataClose()));
/*
    memoryformat = new MemoryFormatDialog(this);
    connect(memoryformat,SIGNAL(memoryFormat()),
            this,SLOT(memoryFormat()));
*/

//    e = new EraseCheckDialog(this);
//    e->setMessage(QString::fromUtf8("内存将被初始化!"));
//    //e->setModal(true);
//    connect(e,SIGNAL(signalYes()),
//            this,SLOT(checkDelete()));
    //e->hide();

    t = new transferDialog(this);
    t->setMessageType(FORMAT);
    //t->setModal(true);
    //t->close();
}

DataTransferMenu::~DataTransferMenu()
{
    delete ui;
}

void DataTransferMenu::closeEvent(QCloseEvent *e)
{
    Q_UNUSED(e);
    emit menuClose();
}

void DataTransferMenu::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == KEY_ESC)
    {
        this->close();
    }
    else if (e->key() == KEY_ENTER)
    {
        QWidget *focus_w = this->focusWidget();
        if (!focus_w)
        {
            return;
        }
        QPushButton *btn = qobject_cast<QPushButton*>(focus_w);
        if (btn)
        {
            btn->click();
        }
    }
    else
    {
        QMainWindow::keyPressEvent(e);
    }
}

void DataTransferMenu::on_manualTransferButton_clicked()
{
    //transferData();
    emit manualtransferStart();
    WidgetShow::widgetShow(manualtransfermenu);
    this->hide();
}

void DataTransferMenu::manualtransferClose()
{
    WidgetShow::widgetShow(this);
}

void DataTransferMenu::on_eraseButton_clicked()
{
    emit erasedataStart();
    WidgetShow::widgetShow(erasedatamenu);
    this->hide();
}

void DataTransferMenu::erasedataClose()
{
    WidgetShow::widgetShow(this);
}

void DataTransferMenu::on_formatButton_clicked()
{
    e = new EraseCheckDialog();
    e->setMessage(QString::fromUtf8("内存将被初始化!"));
    //e->setModal(true);
    connect(e,SIGNAL(signalYes()),
            this,SLOT(checkFormat()));
    connect(e,SIGNAL(signalCancel()),
            this,SLOT(cancelFormat()));
    e->show();
    e->getFocus();
}
void DataTransferMenu::checkFormat()
{
    disconnect(e,SIGNAL(signalYes()),
            this,SLOT(checkFormat()));
    disconnect(e,SIGNAL(signalCancel()),
            this,SLOT(cancelFormat()));
    e->close();
    delete e;
    e = nullptr;

    t->show();

    QString dirpath = QApplication::applicationDirPath() + "/data/";
    QDir dir(dirpath);
    dir.setFilter(QDir::Files);
    int filecount = dir.count();
    for (int i = 0; i < filecount; i++)
    {
        dir.remove(dir[i]);
    }
    FileDataInfo::instance().fileDataCheck();

    t->onTimeOut(0);
}

void DataTransferMenu::cancelFormat()
{
    disconnect(e,SIGNAL(signalYes()),
            this,SLOT(checkFormat()));
    disconnect(e,SIGNAL(signalCancel()),
            this,SLOT(cancelFormat()));
    e->close();
    delete e;
    e = nullptr;
}
