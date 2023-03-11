#include "mappedmenu.h"
#include "ui_mappedmenu.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include "macro.h"
#include <QDebug>
#include "systemdetail.h"
#include "widgetshowtype.h"
#include "datacollectorfactory.h"
#include "digitalclock.h"

MappedMenu::MappedMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MappedMenu)
{
    ui->setupUi(this);
    connect(this,SIGNAL(changeSpeed(int)),
            &DataAnalyser::instance(),SLOT(changeSpeed(int)));
    AbstractDataCollector *dataCollector = DataCollectorFactory::instance().getDataCollector();
    connect(this,SIGNAL(sendCommand(QString)),
            dataCollector,SLOT(sendCommand(QString)));

    mappedMode = new MappedMode(this);
    connect(mappedMode,SIGNAL(menuClose()),
            this,SLOT(mappedModeClose()));
    connect(this,SIGNAL(mappedStart(int, int, long, long, int)),
            mappedMode,SLOT(mappedStart(int, int, long, long, int)));

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
   /*
    mainLayout->addLayout(downLayout,6,1,4,2);
    mainLayout->addWidget(ui->startButton,10,1,1,2);*/
    //ui->spaceLabel->setStyleSheet("QLabel{background-color:transparent;}");
    //ui->spaceLabel->resize(10,20);
    //mainLayout->addWidget(ui->spaceLabel,6,0,1,1,Qt::AlignLeft);
    mainLayout->addWidget(downMenuwidget,6,1,4,3);

    ui->currentTime->setVisible(false);
//    mainLayout->addWidget(ui->currentTime,12,0,1,2);

    DigitalClock* currentTime = new DigitalClock();
    mainLayout->addWidget(currentTime,10,0,1,2);

    downMenuwidget->setNextLabelVisable(false);
}

MappedMenu::~MappedMenu()
{
    delete ui;
}

void MappedMenu::closeEvent(QCloseEvent *e)
{
    Q_UNUSED(e);
    emit menuClose();
}

void MappedMenu::keyPressEvent(QKeyEvent *e)
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

void MappedMenu::startclicked()
{
    emit changeSpeed(100);
    if (filedata->currentIndex() != 0)
    {
        emit mappedStart(fileNumLabel->getValue(), downMenuwidget->getSurveyMode(),fileDataWidget->getEndX().toLong()+1,
                        fileDataWidget->getNextPosition(),fileDataWidget->getDirection());
    }
    else
    {
        emit mappedStart(fileNumLabel->getValue(), downMenuwidget->getSurveyMode(),0,0,0);
    }

    //串口打开后打开GPS模块
    cmd = QString("<gps,1>");
    emit sendCommand(cmd);

    WidgetShow::widgetShow(mappedMode);
//    this->hide();
}

void MappedMenu::mappedModeClose()
{
    checkFileStatus();
//    this->showFullScreen();
//    this->show();
    fileNumLabel->setFocus();
    WidgetShow::widgetShow(this);
}

void MappedMenu::mappedMenuStart()
{
    changeFileDataWidget();
    fileNumLabel->setFocus();
    //DataCollectorFactory::instance().getGpsCollector()->start();
}

void MappedMenu::checkFileStatus()
{
    FileDataInfo::instance().fileDataCheck(fileNumLabel->getValue());
    mappedMenuStart();
}

void MappedMenu::changeFileDataWidget()
{
    int ret = FileDataInfo::instance().setFileDataWidget(fileNumLabel->getValue(),fileDataWidget);
    //qDebug() << "positon = " << fileDataWidget->getNextPosition();
    //qDebug() << "direction = " << fileDataWidget->getDirection();
    if (ret == -1)
    {
        filedata->setCurrentIndex(0);
        ui->fileStatusLabel->setText(QString::fromUtf8("空"));
        downMenuwidget->setVisible(true);
        downMenuwidget->setSurveyMode(MAPPEDMENU);
        downMenuwidget->setDefaultLine();
        return;
    }
    else
    {
        filedata->setCurrentIndex(1);
        downMenuwidget->setVisible(false);
    }
    if (ret == SIMPLE)
    {
        ui->fileStatusLabel->setText(QString::fromUtf8("简单调查模式"));
    }
    else if (ret == MAPPED)
    {
        ui->fileStatusLabel->setText(QString::fromUtf8("GPS调查模式"));
    }
    else if (ret == DRAW)
    {
        ui->fileStatusLabel->setText(QString::fromUtf8("绘图调查模式"));
    }
    else if (ret == BASE)
    {
        ui->fileStatusLabel->setText(QString::fromUtf8("基站模式"));
    }

}
