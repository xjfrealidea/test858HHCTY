#include "manualtransfermenu.h"
#include "ui_manualtransfermenu.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include "filedatainfo.h"
#include "macro.h"
#include <QFile>
#include <QDir>
#include <QString>
#include <QTextStream>
#include <cstdlib>
#include <QDebug>
#include <QProcess>
#include "datacollectorfactory.h"
#include "digitalclock.h"


ManualTransferMenu::ManualTransferMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManualTransferMenu)
{
    ui->setupUi(this);

    fileNumLabel = new ScrollNumLabel(MAXNUM,this);
    fileNumLabel->setStep(1);
    fileNumLabel->setFocusPolicy(Qt::StrongFocus);
    fileNumLabel->setScrollOver(true);
    connect(fileNumLabel,SIGNAL(textChanged()),
            this,SLOT(changeFileDataWidget()));

    QHBoxLayout *fileDataBox = new QHBoxLayout();
    fileDataBox->addWidget(ui->fileLabel);
    fileDataBox->addWidget(fileNumLabel);
    fileDataBox->addWidget(ui->fileTypeLabel,0,Qt::AlignLeft);
    fileDataBox->addWidget(ui->fileStatusLabel,1,Qt::AlignHCenter);



    filedata = new QStackedWidget(this);
    spaceWidget = new FileDataWidget(this);
    fileDataWidget = new FileDataWidget(this);
    fileDataWidget->setUi();
    filedata->addWidget(spaceWidget);
    filedata->addWidget(fileDataWidget);
    filedata->setCurrentIndex(0);

    QGridLayout *mainLayout = new QGridLayout(ui->centralwidget);
    mainLayout->addWidget(ui->titleLabel,0,1,1,2,Qt::AlignHCenter | Qt::AlignVCenter);
    mainLayout->addLayout(fileDataBox,1,1,1,2);
    mainLayout->addWidget(filedata,2,1,4,2);

    mainLayout->addWidget(ui->startButton,7,1,1,2,Qt::AlignHCenter | Qt::AlignVCenter);

    ui->currentTime->setVisible(false);
//    mainLayout->addWidget(ui->currentTime,9,0,1,4,Qt::AlignLeft);

    DigitalClock *currentTime = new DigitalClock();
    mainLayout->addWidget(currentTime,9,0,1,4,Qt::AlignLeft);

    ui->titleLabel->setText(QString::fromUtf8("数据导出菜单"));
    ui->fileLabel->setText(QString::fromUtf8("文件"));

//    ui->startButton->setStyleSheet("QPushButton:focus{background-color:red;}"
//                                    "QPushButton{outline:none;}");

    transferdialog = new transferDialog(this);
    transferdialog->setMessageType(TRANSFER);
//    connect(transferdialog,SIGNAL(transferComplete()),
  //          this,SLOT(umount()));


    connect(this,SIGNAL(reTransfer(int,bool)),
            this,SLOT(dataTransfer(int,bool)));
}

ManualTransferMenu::~ManualTransferMenu()
{
    delete ui;
}

int ManualTransferMenu::changeFileDataWidget()
{
    int ret = FileDataInfo::instance().setFileDataWidget(fileNumLabel->getValue(),fileDataWidget);
    if (ret == -1)
    {
        filedata->setCurrentIndex(0);
        ui->fileStatusLabel->setText(QString::fromUtf8("空"));
        //ui->startButton->setVisible(false);
        ui->startButton->setEnabled(false);
        ui->startButton->setText(" ");
        return ret;
    }

    filedata->setCurrentIndex(1);

    if (ret == SIMPLE)
    {
        ui->fileStatusLabel->setText(QString::fromUtf8("简单调查模式"));
        ui->startButton->setEnabled(true);
        ui->startButton->setText(QString::fromUtf8("导出当前数据"));
    }
    else if (ret == MAPPED)
    {
        ui->fileStatusLabel->setText(QString::fromUtf8("差分调查模式"));
        ui->startButton->setEnabled(true);
        ui->startButton->setText(QString::fromUtf8("导出当前数据"));
    }
    else if (ret == BASE)
    {
        ui->fileStatusLabel->setText("BASE STATION");
        ui->startButton->setEnabled(true);
        ui->startButton->setText(QString::fromUtf8("导出当前数据"));
    }
    return ret;
}

void ManualTransferMenu::transferMenuStart()
{
    fileNumLabel->setValue(1);
    changeFileDataWidget();

    fileNumLabel->setFocus();
 //   fileNumLabel->autoResize();
    fileNumLabel->valueDown();
    fileNumLabel->valueUp();
}

void ManualTransferMenu::closeEvent(QCloseEvent *e)
{
    Q_UNUSED(e);
    emit menuClose();
}

void ManualTransferMenu::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == KEY_ESC)
    {
        this->close();
    }
    else if (e->key() == KEY_UP)
    {
        this->focusPreviousChild();
    }
    else if (e->key() == KEY_DOWN)
    {
        this->focusNextChild();
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

void ManualTransferMenu::on_startButton_clicked()
{
    ui->startButton->setText((QString::fromUtf8("数据传输中...")));
    dataTransfer(fileNumLabel->getValue(),true);
    changeFileDataWidget();
}

void ManualTransferMenu::checkTransfer(int index,bool message, int idx)
{
    bool umountFlag = unmontDev(idx);
    if (umountFlag == false)
    {
        if (message)
        {
            transferdialog->onTimeOut(1);
        }
        return;
    }

    bool mountFlag = mountDev(idx);
    if (mountFlag == false)
    {
        if (message)
        {
            transferdialog->onTimeOut(1);
        }
        return;
    }

    QString filepath = QApplication::applicationDirPath() + "/data/";
    QString fileName = "FILE_" + QString::number(index) + ".stn";
    QString filePathName = filepath + fileName;
    QFile *file = new QFile(filePathName);
    QString savepath("/mnt/usb/data/");
    QString savePathName = savepath + fileName;
    if (!QFile::exists(savePathName))
    {
        umountFlag = unmontDev(idx);
        if (umountFlag == false)
        {
            if (message)
            {
                transferdialog->onTimeOut(1);
            }
            return;
        }

        emit reTransfer(fileNumLabel->getValue(),true);
        transferdialog->close();
        return;
    }

    QFile *saveFile = new QFile(savePathName);
    if (file->size() != saveFile->size())
    {

        umountFlag = unmontDev(idx);
        if (umountFlag == false)
        {
            if (message)
            {
                transferdialog->onTimeOut(1);
            }
            return;
        }

        emit reTransfer(fileNumLabel->getValue(),true);
        transferdialog->close();
        return;
    }

    umountFlag = unmontDev(idx);
    if (umountFlag == false)
    {
        if (message)
        {
            transferdialog->onTimeOut(1);
        }
        return;
    }

    if (message)
    {
        transferdialog->onTimeOut(0);
    }
    file->close();
    saveFile->close();

    delete file;
    file = NULL;
    delete saveFile;
    saveFile = NULL;
    ui->startButton->setText(QString::fromLocal8Bit("导出当前数据"));
}

void ManualTransferMenu::dataTransfer(int index, bool message)
{
//    unmontDev();

    if (message)
    {
        transferdialog->show();
    }
    QString filepath = QApplication::applicationDirPath() + "/data/";
    int idx = -1;
    if (QFile::exists("/dev/sda1"))
    {
        idx = 0;
    }
    if (QFile::exists("/dev/sdb1"))
    {
        idx = 1;
    }
    if (idx < 0)
    {
        if (message)
        {
            transferdialog->onTimeOut(1);
        }
        return;
    }

    QString fileName = "FILE_" + QString::number(index) + ".stn";
    QString filePathName = filepath + fileName;
    if (!QFile::exists(filePathName))
    {
        if (message)
        {
            transferdialog->onTimeOut(1);
        }
        return;
    }

    QFile *file = new QFile(filePathName);
    if (!file->open(QIODevice::ReadOnly))
    {
        if (message)
        {
            transferdialog->onTimeOut(1);
        }
        return;
    }

    bool mountFlag = mountDev(idx);
    if (mountFlag == false)
    {
        if (message)
        {
            transferdialog->onTimeOut(1);
        }
        return;
    }

    QString savepath("/mnt/usb/data/");
    QDir().mkpath(savepath);
    QString savePathName = savepath + fileName;

    QFile *saveFile = new QFile(savePathName);
    saveFile->open(QIODevice::WriteOnly);
    QTextStream *m_saver = new QTextStream(saveFile);

    char buf[1024];
    while (1)
    {
        int ret = file->readLine(buf, sizeof(buf));
        if (ret == -1)
        {
            break;
        }
        *m_saver<< buf;
        (*saveFile).flush();
    }
    file->close();
    saveFile->close();

    QProcess process;
    process.start("sync");

    delete file;
    file = NULL;
    delete saveFile;
    saveFile = NULL;
    delete m_saver;
    m_saver = NULL;

    FileDataInfo::instance().setTransferStatus(index,true);

    checkTransfer(index,message,idx);
}

bool ManualTransferMenu::mountDev(int idx)
{
    int count = 0;
    while (1)
    {
        QProcess p;
        if (idx == 0)
        {
            p.start("mount /dev/sda1 /mnt/usb/");
        }
        else
        {
            p.start("mount /dev/sdb1 /mnt/usb/");
        }
        p.waitForFinished();
        int ret = p.exitCode();
        if (ret == 0)
        {
            count = 0;
            break;
        }

        count++;
        if (count > 10)
        {
            break;
        }
    }

    if (count >10)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool ManualTransferMenu::unmontDev(int idx)
{
    int count = 0;
    while (1)
    {
        QProcess p;
        if (idx == 0)
        {
            p.start("umount /dev/sda1");
        }
        else
        {
            p.start("umount /dev/sdb1");
        }
        p.waitForFinished();
        int ret = p.exitCode();
        if (ret == 0)
        {
            break;
        }

        count++;
        if (count > 10)
        {
            break;
        }
    }

    if (count >10)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void ManualTransferMenu::transferCacheData()
{/*
    QString fileName = DataCollectorFactory::instance().getCacheDataSaver()->getFilePathName();
    QFile *file = new QFile(fileName);
    if (!file->open(QIODevice::ReadOnly))
    {
        return;
    }

    QString savepath("/mnt/usb/data/");
    QString savePathName = savepath + fileName;

    QFile *saveFile = new QFile(savePathName);
    saveFile->open(QIODevice::WriteOnly);
    QTextStream *m_saver = new QTextStream(saveFile);

    char buf[1024];
    while (1)
    {
        int ret = file->readLine(buf, sizeof(buf));
        if (ret == -1)
        {
            break;
        }
        *m_saver<< buf;
        (*saveFile).flush();

    }
    file->close();
    saveFile->close();

    QProcess process;
    process.start("sync");

    delete file;
    file = NULL;
    delete saveFile;
    saveFile = NULL;
    delete m_saver;
    m_saver = NULL;*/
}
