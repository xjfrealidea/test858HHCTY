#include "simplemenu.h"
#include "ui_simplemenu.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include "macro.h"
#include <QDebug>
#include "systemdetail.h"
#include "widgetshowtype.h"
#include "digitalclock.h"

SimpleMenu::SimpleMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimpleMenu)
{
    ui->setupUi(this);
    connect(this,SIGNAL(changeSpeed(int)),
            &DataAnalyser::instance(),SLOT(changeSpeed(int)));

    simpleMode = new SimpleMode(this);
    connect(simpleMode,SIGNAL(menuClose()),
            this,SLOT(simpleModeClose()));
    connect(this,SIGNAL(simpleStart(int, int, long, long, int)),
            simpleMode,SLOT(simpleStart(int, int, long, long, int)));

    setStyleSheet("QPushButton{font-size:28px;}"
                  "QPushButton{border-radius:5px;}"
                  "QPushButton{outline:none;}"
                  "QLabel{font-size:28px;}");

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

    downMenuwidget = new SimpleDownMenuWidget(this);
    connect(downMenuwidget,SIGNAL(startclicked()),
            this,SLOT(startclicked()));

    QGridLayout *mainLayout = new QGridLayout(ui->centralwidget);
    mainLayout->addWidget(ui->titleLabel,0,1,1,2,Qt::AlignHCenter | Qt::AlignVCenter);
    mainLayout->addLayout(fileDataBox,1,1,1,2);
    mainLayout->addWidget(filedata,2,1,4,2);

    mainLayout->addWidget(downMenuwidget,7,1,5,3);

    ui->currentTime->setVisible(false);

    DigitalClock* currentTime = new DigitalClock();
    mainLayout->addWidget(currentTime,12,0,1,2);

}

SimpleMenu::~SimpleMenu()
{
    delete ui;
}

void SimpleMenu::simpleMenuStart()
{
    changeFileDataWidget();
    fileNumLabel->setFocus();
}

void SimpleMenu::closeEvent(QCloseEvent *e)
{
    Q_UNUSED(e);
    emit menuClose();
}

void SimpleMenu::keyPressEvent(QKeyEvent *e)
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
    else  if (e->key() == KEY_ENTER)
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
        if (focus_w == this->fileNumLabel)
        {
            if (true == downMenuwidget->isVisible())
            {
                this->startclicked();
            }
        }
    }
    else
    {

    }
}

void SimpleMenu::startclicked()
{
    int hz = downMenuwidget->getCycleTime();
    emit changeSpeed(hz);

    if (filedata->currentIndex() != 0)
    {
        emit simpleStart(fileNumLabel->getValue(), downMenuwidget->getSurveyMode(),fileDataWidget->getEndX().toLong()+1,
                        fileDataWidget->getNextPosition(),fileDataWidget->getDirection());
    }
    else
    {
        emit simpleStart(fileNumLabel->getValue(), downMenuwidget->getSurveyMode(),0,0,0);
    }
    WidgetShow::widgetShow(simpleMode);
//    this->hide();
}

void SimpleMenu::simpleModeClose()
{
    checkFileStatus();
//    this->showFullScreen();
//    this->show();
    fileNumLabel->setFocus();
    WidgetShow::widgetShow(this);
}

void SimpleMenu::checkFileStatus()
{
    FileDataInfo::instance().fileDataCheck(fileNumLabel->getValue());
    simpleMenuStart();
}

void SimpleMenu::changeFileDataWidget()
{
    int ret = FileDataInfo::instance().setFileDataWidget(fileNumLabel->getValue(),fileDataWidget);
    //qDebug() << "positon = " << fileDataWidget->getNextPosition();
    //qDebug() << "direction = " << fileDataWidget->getDirection();
    if (ret == -1)
    {
        filedata->setCurrentIndex(0);
        ui->fileStatusLabel->setText(QString::fromUtf8("空"));
        downMenuwidget->setVisible(true);
        downMenuwidget->setSurveyMode(EMPTY);
        downMenuwidget->setDefaultLine();
        return;
    }
    else
    {
        filedata->setCurrentIndex(1);
    }
    if (ret == SIMPLE)
    {
        ui->fileStatusLabel->setText(QString::fromUtf8("简单调查模式"));
        downMenuwidget->setVisible(true);
        downMenuwidget->setSurveyMode(fileDataWidget->getSurveyMode());
        downMenuwidget->setNextLine(fileDataWidget->getEndX());

    }
    else if (ret == MAPPED)
    {
        ui->fileStatusLabel->setText(QString::fromUtf8("GPS调查模式"));
        downMenuwidget->setVisible(false);
    }
    else if (ret == DRAW)
    {
        ui->fileStatusLabel->setText(QString::fromUtf8("绘图调查模式"));
        downMenuwidget->setVisible(false);
    }
    else if (ret == BASE)
    {
        ui->fileStatusLabel->setText(QString::fromUtf8("基站模式"));
        downMenuwidget->setVisible(false);
    }

}
