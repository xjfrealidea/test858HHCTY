#include "drawmenu.h"
#include "ui_drawmenu.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include "macro.h"
#include <QDebug>
#include "systemdetail.h"
#include "widgetshowtype.h"
#include "digitalclock.h"
#include <QMetaType>

DrawMenu::DrawMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DrawMenu)
{
    qRegisterMetaType<DEFINEDATA>("DEFINEDATA");


    ui->setupUi(this);
    connect(this,SIGNAL(changeSpeed(int)),
            &DataAnalyser::instance(),SLOT(changeSpeed(int)));

    drawMode = new DrawMode(this);
    connect(drawMode,SIGNAL(menuClose()),
            this,SLOT(drawModeClose()));
    connect(this,SIGNAL(drawStart(int, int, long, long, DEFINEDATA)),
            drawMode,SLOT(drawStart(int, int, long, long, DEFINEDATA)));

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

    downMenuwidget = new MappedDownMenuWidget(this);
    connect(downMenuwidget,SIGNAL(startclicked()),
            this,SLOT(startclicked()));
    connect(downMenuwidget,SIGNAL(defineclicked()),
            this,SLOT(defineclicked()));

    defineMapMenu = new DefineMapMenu();
    connect(this,SIGNAL(defineMenuShow()),
            defineMapMenu,SLOT(defineMenuShow()));

    QGridLayout *mainLayout = new QGridLayout(ui->centralwidget);
    mainLayout->addWidget(ui->titleLabel,0,1,1,2,Qt::AlignHCenter | Qt::AlignVCenter);
    mainLayout->addLayout(fileDataBox,1,1,1,2);
    mainLayout->addWidget(filedata,2,1,4,2);

    mainLayout->addWidget(downMenuwidget,7,1,5,3);

    ui->currentTime->setVisible(false);

    DigitalClock* currentTime = new DigitalClock();
    mainLayout->addWidget(currentTime,12,0,1,2);

}

DrawMenu::~DrawMenu()
{
    delete ui;
}

void DrawMenu::drawMenuStart()
{
    changeFileDataWidget();
    fileNumLabel->setFocus();
}

void DrawMenu::closeEvent(QCloseEvent *e)
{
    Q_UNUSED(e);
    emit menuClose();
}

void DrawMenu::keyPressEvent(QKeyEvent *e)
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

void DrawMenu::startclicked()
{
    int hz = downMenuwidget->getCycleTime();
    emit changeSpeed(hz);

    defineDate.LLx=this->defineMapMenu->getLLxData();
    defineDate.LLy=this->defineMapMenu->getLLyData();
    defineDate.URx=this->defineMapMenu->getURxData();
    defineDate.URy=this->defineMapMenu->getURyData();
    defineDate.spaceLine = this->defineMapMenu->getSpaceLineData();
    defineDate.spaceMark = this->defineMapMenu->getSpaceMarkData();
    defineDate.surveyDirection = this->defineMapMenu->getDirectionMode();//1 双向 2 单向
    defineDate.parallelAxis = this->defineMapMenu->getParallelAxis();//1 Y轴 2 X轴
//    if (filedata->currentIndex() != 0)
//    {
//        emit drawStart(fileNumLabel->getValue(), downMenuwidget->getSurveyMode(),fileDataWidget->getEndX().toLong()+1,
//                        fileDataWidget->getNextPosition(),fileDataWidget->getDirection());
//    }
//    else
    {
        emit drawStart(fileNumLabel->getValue(), downMenuwidget->getSurveyMode(),0,0,defineDate);
    }
    WidgetShow::widgetShow(drawMode);
//    this->hide();
}

void DrawMenu::drawModeClose()
{
    checkFileStatus();
//    this->showFullScreen();
//    this->show();
    fileNumLabel->setFocus();
    WidgetShow::widgetShow(this);
}

void DrawMenu::checkFileStatus()
{
    FileDataInfo::instance().fileDataCheck(fileNumLabel->getValue());
    drawMenuStart();
}

void DrawMenu::changeFileDataWidget()
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
        downMenuwidget->setVisible(false);
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

void DrawMenu::defineclicked()
{
    emit defineMenuShow();
    WidgetShow::widgetShow(defineMapMenu);
}
