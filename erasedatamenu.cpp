#include "erasedatamenu.h"
#include "ui_erasedatamenu.h"
#include "filedatainfo.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include "macro.h"
#include <QFile>
#include "digitalclock.h"

EraseDataMenu::EraseDataMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EraseDataMenu)
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

    mainLayout->addWidget(ui->transferStatusLabel,6,1,1,2,Qt::AlignHCenter | Qt::AlignVCenter);
    mainLayout->addWidget(ui->deleteButton,7,1,1,2,Qt::AlignHCenter | Qt::AlignVCenter);

    ui->titleLabel->setText(QString::fromUtf8("数据删除菜单"));

    ui->currentTime->setVisible(false);
//    mainLayout->addWidget(ui->currentTime,9,0,1,4,Qt::AlignLeft);

    DigitalClock *currentTime = new DigitalClock();
    mainLayout->addWidget(currentTime,9,0,1,4,Qt::AlignLeft);

//    ui->deleteButton->setStyleSheet("QPushButton:focus{background-color:red;}"
//                                    "QPushButton{outline:none;}");

//    e = new EraseCheckDialog(this);
//    e->setMessage(QString::fromUtf8("数据将被删除!"));
    //e->setModal(true);
//    connect(e,SIGNAL(signalYes()),
//            this,SLOT(checkDelete()));
    //e->hide();

    t = new transferDialog(this);
    t->setMessageType(ERASE);
    //t->setModal(true);
    //t->close();

    ui->fileLabel->setText(QString::fromUtf8("文件"));
}

EraseDataMenu::~EraseDataMenu()
{
    delete ui;
}

void EraseDataMenu::dataErase(int index)
{
    QString filepath = QApplication::applicationDirPath() + "/data/";
    QString fileName = "FILE_" + QString::number(index) + ".stn";
    QString filePathName = filepath + fileName;

    QFile *file = new QFile(filePathName);
    //qDebug() << file->rename(fileName+QString::fromLocal8Bit(".erase"));
    //file->close();
    file->remove();
    delete file;
    file = NULL;

    FileDataInfo::instance().fileDataCheck(index);
}

void EraseDataMenu::changeFileDataWidget()
{
    int ret = FileDataInfo::instance().setFileDataWidget(fileNumLabel->getValue(),fileDataWidget);
    if (ret == -1)
    {
        filedata->setCurrentIndex(0);
        ui->fileStatusLabel->setText(QString::fromUtf8("空"));
        ui->deleteButton->setEnabled(false);
        ui->deleteButton->setText(" ");
        ui->transferStatusLabel->setText(" ");
        return;
    }

    filedata->setCurrentIndex(1);

    if (ret == SIMPLE)
    {
        ui->fileStatusLabel->setText(QString::fromUtf8("简单调查模式"));
        ui->deleteButton->setEnabled(true);
        ui->deleteButton->setText(QString::fromUtf8("删除当前数据"));
    }
    else if (ret == MAPPED)
    {
        ui->fileStatusLabel->setText(QString::fromUtf8("差分调查模式"));
        ui->deleteButton->setEnabled(true);
        ui->deleteButton->setText(QString::fromUtf8("删除当前数据"));
    }
    else if (ret == BASE)
    {
        ui->fileStatusLabel->setText("BASE STATION");
        ui->deleteButton->setEnabled(true);
        ui->deleteButton->setText(QString::fromUtf8("删除当前数据"));
    }
    if (FileDataInfo::instance().getTransferStatus(fileNumLabel->getValue()))
    {
        ui->transferStatusLabel->setText(" ");
    }
    else
    {
        ui->transferStatusLabel->setText("!!!  当前数据未被导出  !!!");
    }
}

void EraseDataMenu::eraseMenuStart()
{
    fileNumLabel->setValue(1);
    changeFileDataWidget();
    fileNumLabel->setFocus();
 //   fileNumLabel->autoResize();
    fileNumLabel->valueDown();
    fileNumLabel->valueUp();
}

void EraseDataMenu::closeEvent(QCloseEvent *e)
{
    Q_UNUSED(e);
    emit menuClose();
}

void EraseDataMenu::keyPressEvent(QKeyEvent *e)
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

void EraseDataMenu::on_deleteButton_clicked()
{
    e = new EraseCheckDialog();
    connect(e,SIGNAL(signalYes()),
            this,SLOT(checkDelete()));
    connect(e,SIGNAL(signalCancel()),
            this,SLOT(cancelDelete()));
    e->show();
    e->getFocus();
    //dataErase(fileNumLabel->getValue());
    //changeFileDataWidget();
}

void EraseDataMenu::checkDelete()
{
    disconnect(e,SIGNAL(signalYes()),
            this,SLOT(checkDelete()));
    disconnect(e,SIGNAL(signalCancel()),
            this,SLOT(cancelDelete()));
    e->close();
    delete e;
    e = nullptr;

    t->show();
    dataErase(fileNumLabel->getValue());
    changeFileDataWidget();
    t->onTimeOut(0);
}

void EraseDataMenu::cancelDelete()
{
    disconnect(e,SIGNAL(signalYes()),
            this,SLOT(checkDelete()));
    disconnect(e,SIGNAL(signalCancel()),
            this,SLOT(cancelDelete()));
    e->close();
    delete e;
    e = nullptr;
}
