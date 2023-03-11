#include "magnetmenu.h"
#include "ui_magnetmenu.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "macro.h"
#include "widgetshowtype.h"
#include "digitalclock.h"
#include "filedatainfo.h"
#include "audiooutput.h"
#include <QThread>
#include <QProcess>
#include <QDateTime>

MagnetMenu::MagnetMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MagnetMenu)
{
    ui->setupUi(this);


    sreachMode = new SreachMode(this);
    connect(sreachMode, SIGNAL(menuClose()),
            this,SLOT(sreachModeClose()));
    connect(this,SIGNAL(sreachStart()),
            sreachMode,SLOT(sreachStart()));

    simpleMenu = new SimpleMenu(this);
    connect(simpleMenu,SIGNAL(menuClose()),
            this,SLOT(simpleModeClose()));
    connect(this,SIGNAL(simpleMenuStart()),
            simpleMenu,SLOT(simpleMenuStart()));

    mappedMenu = new MappedMenu(this);
    connect(mappedMenu,SIGNAL(menuClose()),
            this,SLOT(mappedModeClose()));
    connect(this,SIGNAL(mappedStart()),
            mappedMenu,SLOT(mappedMenuStart()));

    dataTransferMenu = new DataTransferMenu(this);
    connect(dataTransferMenu,SIGNAL(menuClose()),
            this,SLOT(dataTransferMenuClose()));

    drawMenu = new DrawMenu(this);
    connect(drawMenu,SIGNAL(menuClose()),
            this,SLOT(drawModeClose()));
    connect(this,SIGNAL(drawMenuStart()),
            drawMenu,SLOT(drawMenuStart()));

    baseMenu = new BaseMenu(this);
    connect(baseMenu,SIGNAL(menuClose()),
            this,SLOT(baseMenuClose()));
    connect(this,SIGNAL(baseMenuStart()),
            baseMenu,SLOT(baseMenuStart()));


//    DigitalClock* currentTime = new DigitalClock(this);
//    currentTime->setFocusPolicy(Qt::StrongFocus);
//    connect(currentTime,SIGNAL(enterPress()),
//            this,SLOT(timeLabelPress()));
//    connect(currentTime,SIGNAL(focusOut(int)),
//            this,SLOT(timeLabelFocusOut(int)));

    connect(ui->lcdTimeLabel,SIGNAL(enterPress()),
            this,SLOT(timeLabelPress()));
    connect(ui->lcdTimeLabel,SIGNAL(focusOut(int)),
            this,SLOT(timeLabelFocusOut(int)));


    QLabel *memoryUsedLabel = new QLabel(this);
    connect(this, SIGNAL(setMemoryUsedLabel(QString)),
            memoryUsedLabel, SLOT(setText(QString)));

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(ui->titleLabel,0,0,1,5);
    layout->addWidget(ui->controlHint,1,1,1,3);
    layout->addWidget(ui->sreachButton,2,2,1,1);
    layout->addWidget(ui->simpleButton,3,2,1,1);
    layout->addWidget(ui->drawButton,4,2,1,1);
    layout->addWidget(ui->mappedButton,5,2,1,1);
    layout->addWidget(ui->baseButton,6,2,1,1);
    layout->addWidget(ui->reviewButton,7,2,1,1);
    layout->addWidget(ui->transferButton,8,2,1,1);
    layout->addWidget(ui->setupButton,9,2,1,1);
//    layout->setVerticalSpacing(2);
//    layout->setContentsMargins(5,5,5,0);

    ui->titleLabel->setText(QString::fromUtf8("磁力仪菜单"));
    ui->controlHint->setText(QString::fromUtf8("方向键选择功能,ENTER键进入"));
    ui->sreachButton->setText(QString::fromUtf8("搜索模式"));
    ui->simpleButton->setText(QString::fromUtf8("简单调查模式"));
    ui->drawButton->setText(QString::fromUtf8("绘图调查模式"));
    ui->mappedButton->setText(QString::fromUtf8("GPS调查模式"));
    ui->baseButton->setText(QString::fromUtf8("基准站模式"));
    ui->reviewButton->setVisible(false);
    ui->transferButton->setText(QString::fromUtf8("数据管理"));
    ui->setupButton->setVisible(false);

    ui->currentTime->setVisible(false);

    QHBoxLayout *otherLayout = new QHBoxLayout();
    otherLayout->addWidget(ui->lcdTimeLabel);
    otherLayout->addWidget(memoryUsedLabel,0,Qt::AlignHCenter);

    QVBoxLayout *mainLayout = new QVBoxLayout(ui->centralwidget);
    mainLayout->addLayout(layout,4);
    mainLayout->addLayout(otherLayout,1);

    setStyleSheet("QPushButton{font-size: 38px;}"
                  "QPushButton{border-radius: 5px;}"
                  "QLabel{font-size: 38px;}");

    ui->sreachButton->setStyleSheet("   ");

    this->memoryUsed = FileDataInfo::instance().getMemoryUsed();

    transferdialog = new transferDialog(this);
    transferdialog->setMessageType(UPDATE);
//    timeEdit = new TimeEditDialog();
//    timeEdit->hide();

}
MagnetMenu::~MagnetMenu()
{
    delete ui;
}

void MagnetMenu::setMemoryUsed()
{
    FileDataInfo::instance().memorySizeCheck();
    double memoryUsed = FileDataInfo::instance().getMemoryUsed() * 100.0;
    QString str = QString::fromUtf8("内存使用：%1%").arg(memoryUsed,0,'f',2);
    emit setMemoryUsedLabel(str);
}

void MagnetMenu::updateexe()
{
    qDebug() << "updateexe";
    transferdialog->show();
    int count = 0;
    int ret = 0;
    QProcess p;
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
        transferdialog->onTimeOut(1);
        return;
    }
    while (1)
    {
        if (idx == 0)
        {
            p.start("mount /dev/sda1 /mnt/usb/");
        }
        else if (idx == 1)
        {
            p.start("mount /dev/sdb1 /mnt/usb/");
        }
        p.waitForFinished();
        ret = p.exitCode();
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
        transferdialog->onTimeOut(1);
        return;
    }

    p.start("cp /mnt/usb/858update/new.exe /usr/gsn/");
    p.waitForFinished();
    ret = p.exitCode();
    if (ret != 0)
    {
        transferdialog->onTimeOut(1);
        return;
    }

    while (1)
    {
        if (idx == 0)
        {
            p.start("umount /dev/sda1");
        }
        else if (idx == 1)
        {
            p.start("umount /dev/sdb1");
        }
        p.waitForFinished();
        ret = p.exitCode();
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
        transferdialog->onTimeOut(1);
        return;
    }

    p.start("cp /usr/gsn/new.exe /usr/gsn/CT858");
    p.waitForFinished();
    ret = p.exitCode();
    if (ret != 0)
    {
        transferdialog->onTimeOut(1);
        return;
    }

    p.start("cp /usr/gsn/CT858 /usr/gsn/CT858-run");
    p.waitForFinished();
    ret = p.exitCode();
    if (ret != 0)
    {
        transferdialog->onTimeOut(1);
        return;
    }

    transferdialog->onTimeOut(0);
}

void MagnetMenu::updateini()
{
    qDebug() << "updateini";
    transferdialog->show();
    int count = 0;
    int ret = 0;
    QProcess p;
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
        transferdialog->onTimeOut(1);
        return;
    }
    while (1)
    {
        if (idx == 0)
        {
            p.start("mount /dev/sda1 /mnt/usb/");
        }
        else if (idx == 1)
        {
            p.start("mount /dev/sdb1 /mnt/usb/");
        }
        p.waitForFinished();
        ret = p.exitCode();
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
        transferdialog->onTimeOut(1);
        return;
    }

    p.start("cp /mnt/usb/858update/new.ini /usr/gsn/");
    p.waitForFinished();
    ret = p.exitCode();
    if (ret != 0)
    {
        transferdialog->onTimeOut(1);
        return;
    }

    while (1)
    {
        if (idx == 0)
        {
            p.start("umount /dev/sda1");
        }
        else if (idx == 1)
        {
            p.start("umount /dev/sdb1");
        }
        p.waitForFinished();
        ret = p.exitCode();
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
        transferdialog->onTimeOut(1);
        return;
    }

    p.start("cp /usr/gsn/new.ini /usr/gsn/ini.ini");
    p.waitForFinished();
    ret = p.exitCode();
    if (ret != 0)
    {
        transferdialog->onTimeOut(1);
        return;
    }

    transferdialog->onTimeOut(0);
}

void MagnetMenu::updateqss()
{
    qDebug() << "updateqss";
    transferdialog->show();
    int count = 0;
    int ret = 0;
    QProcess p;
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
        transferdialog->onTimeOut(1);
        return;
    }
    while (1)
    {
        if (idx == 0)
        {
            p.start("mount /dev/sda1 /mnt/usb/");
        }
        else if (idx == 1)
        {
            p.start("mount /dev/sdb1 /mnt/usb/");
        }
        p.waitForFinished();
        ret = p.exitCode();
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
        transferdialog->onTimeOut(1);
        return;
    }

    p.start("cp /mnt/usb/858update/new.qss /usr/gsn/");
    p.waitForFinished();
    ret = p.exitCode();
    if (ret != 0)
    {
        transferdialog->onTimeOut(1);
        return;
    }

    while (1)
    {
        if (idx == 0)
        {
            p.start("umount /dev/sda1");
        }
        else if (idx == 1)
        {
            p.start("umount /dev/sdb1");
        }
        p.waitForFinished();
        ret = p.exitCode();
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
        transferdialog->onTimeOut(1);
        return;
    }

    p.start("cp /usr/gsn/new.qss /usr/gsn/gsn.qss");
    p.waitForFinished();
    ret = p.exitCode();
    if (ret != 0)
    {
        transferdialog->onTimeOut(1);
        return;
    }

    transferdialog->onTimeOut(0);
}

void MagnetMenu::exportStnData()
{
    qDebug() << "export stn";
    transferdialog->show();
    int count = 0;
    int ret = 0;
    QProcess p;
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
        transferdialog->onTimeOut(1);
        return;
    }
    while (1)
    {
        if (idx == 0)
        {
            p.start("mount /dev/sda1 /mnt/usb/");
        }
        else if (idx == 1)
        {
            p.start("mount /dev/sdb1 /mnt/usb/");
        }
        p.waitForFinished();
        ret = p.exitCode();
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
        transferdialog->onTimeOut(1);
        return;
    }

    QString savepath("/mnt/usb/data_"+ QDateTime::currentDateTime().toString("yyyy-MM-dd HH-mm-ss")+ "/");
    QDir().mkpath(savepath);

    p.start("cp /usr/gsn/data/*.stn /mnt/usb/data/");
    p.waitForFinished();
    ret = p.exitCode();
    if (ret != 0)
    {
        transferdialog->onTimeOut(1);
        return;
    }

    while (1)
    {
        if (idx == 0)
        {
            p.start("umount /dev/sda1");
        }
        else if (idx == 1)
        {
            p.start("umount /dev/sdb1");
        }
        p.waitForFinished();
        ret = p.exitCode();
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
        transferdialog->onTimeOut(1);
        return;
    }

    transferdialog->onTimeOut(0);
}

void MagnetMenu::exportGirdData()
{
    qDebug() << "export grid";
    transferdialog->show();
    int count = 0;
    int ret = 0;
    QProcess p;
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
        transferdialog->onTimeOut(1);
        return;
    }
    while (1)
    {
        if (idx == 0)
        {
            p.start("mount /dev/sda1 /mnt/usb/");
        }
        else if (idx == 1)
        {
            p.start("mount /dev/sdb1 /mnt/usb/");
        }
        p.waitForFinished();
        ret = p.exitCode();
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
        transferdialog->onTimeOut(1);
        return;
    }

    QString savepath("/mnt/usb/data_"+ QDateTime::currentDateTime().toString("yyyy-MM-dd HH-mm-ss")+ "/");
    QDir().mkpath(savepath);

    p.start("cp /usr/gsn/data/grid*.txt /mnt/usb/data/");
    p.waitForFinished();
    ret = p.exitCode();
    if (ret != 0)
    {
        transferdialog->onTimeOut(1);
        return;
    }

    while (1)
    {
        if (idx == 0)
        {
            p.start("umount /dev/sda1");
        }
        else if (idx == 1)
        {
            p.start("umount /dev/sdb1");
        }
        p.waitForFinished();
        ret = p.exitCode();
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
        transferdialog->onTimeOut(1);
        return;
    }

    transferdialog->onTimeOut(0);
}

void MagnetMenu::magnatShow()
{
    setMemoryUsed();

    WidgetShow::widgetShow(this);
}

void MagnetMenu::timeLabelPress()
{
   // qDebug() << "time label press";
    TimeEditDialog *timeEdit = new TimeEditDialog();
    timeEdit->show();
    timeEdit->getFocus();
}

void MagnetMenu::timeLabelFocusOut(int type)
{
    if (type == KEY_UP)
    {
        this->focusPreviousChild();
    }
    else if (type == KEY_DOWN)
    {
        this->focusNextChild();
    }
}

void MagnetMenu::on_setupButton_clicked()
{

}

void MagnetMenu::sreachModeClose()
{
    setMemoryUsed();
}

void MagnetMenu::systemSetupMenuClose()
{
    setMemoryUsed();
}

void MagnetMenu::on_simpleButton_clicked()
{
    emit simpleMenuStart();
    WidgetShow::widgetShow(simpleMenu);
}

void MagnetMenu::simpleModeClose()
{
    setMemoryUsed();
}

void MagnetMenu::dataTransferMenuClose()
{
    setMemoryUsed();
}

void MagnetMenu::mappedModeClose()
{
    setMemoryUsed();
}

void MagnetMenu::drawModeClose()
{
    setMemoryUsed();
}

void MagnetMenu::baseMenuClose()
{
    setMemoryUsed();
}

void MagnetMenu::on_drawButton_clicked()
{
    emit drawMenuStart();
    WidgetShow::widgetShow(drawMenu);
}

void MagnetMenu::on_sreachButton_clicked()
{
    emit sreachStart();
    WidgetShow::widgetShow(sreachMode);
}

void MagnetMenu::on_transferButton_clicked()
{
    WidgetShow::widgetShow(dataTransferMenu);
}

void MagnetMenu::keyPressEvent(QKeyEvent *e)
{
    static int closeFlag = 0;
    if (e->modifiers() == Qt::ControlModifier && e->key() == Qt::Key_C)
    {
        qApp->quit();//Ctrl+C实现程序强制退出
    }
    else if (KEY_ESC == e->key())
    {
//        qDebug() << "closeFlag " << closeFlag;
        if (85800 == closeFlag)
        {
            this->close();
        }
        else if (85801 == closeFlag)
        {
            updateexe();
        }
        else if (85802 == closeFlag)
        {
            updateini();
        }
        else if (85803 == closeFlag)
        {
            updateqss();
        }
        else if (85810 == closeFlag)
        {
            exportStnData();
        }
        else if (85811 == closeFlag)
        {
            exportGirdData();
        }
        closeFlag = 0;
    }
    else if (e->key() == KEY_UP)
    {
        this->focusPreviousChild();
        closeFlag = 0;
    }
    else if (e->key() == KEY_DOWN)
    {
        this->focusNextChild();
        closeFlag = 0;
    }
    else if (KEY_ENTER == e->key())
    {
        closeFlag = 0;
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
        if (e->key() >= Qt::Key_0 && Qt::Key_9 >= e->key())
        {
            closeFlag = closeFlag * 10 + e->key() - Qt::Key_0;
            if (closeFlag > 99999)
            {
                closeFlag = 0;
            }
//            qDebug() << "closeFlag " << closeFlag;
        }
        else
	{
            closeFlag = 0;
	}
//        QMainWindow::keyPressEvent(e);
    }
}

void MagnetMenu::on_mappedButton_clicked()
{
    emit mappedStart();
    WidgetShow::widgetShow(mappedMenu);
}

void MagnetMenu::on_baseButton_clicked()
{
    emit baseMenuStart();
    WidgetShow::widgetShow(baseMenu);
}
