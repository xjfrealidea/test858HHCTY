#include "sreachmode.h"
#include "ui_sreachmode.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include "macro.h"
#include "dataanalyser.h"
#include <QDebug>
#include "widgetshowtype.h"
#include <QThread>
#include <unistd.h>
#include <QPushButton>

extern bool audioWork;
extern bool audioEnable;

SreachMode::SreachMode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SreachMode)
{
    ui->setupUi(this);
    connect(&DataAnalyser::instance(),SIGNAL(fieldData(int,double,double,double,double)),
            this,SLOT(setFieldLabel(int,double,double,double,double)));
    connect(this,SIGNAL(changeSpeed(int)),
            &DataAnalyser::instance(),SLOT(changeSpeed(int)));

    connect(this,SIGNAL(dataReset()),
            &DataAnalyser::instance(),SLOT(dataReset()));

    connect(this,SIGNAL(changeHz(double)),
            &(AudioOutput::instance()),SLOT(changeHz(double)));
    connect(this,SIGNAL(startAudio()),
            &(AudioOutput::instance()),SLOT(start()));
    connect(this,SIGNAL(stopAudio()),
            &(AudioOutput::instance()),SLOT(stop()));
    connect(this,SIGNAL(pauseAudio()),
            &(AudioOutput::instance()),SLOT(pause()));

    spaceWidget = new PopUpMenus(0,this);
    audioPopUpMenu = new AudioPopUpMenu(15000,this);
    connect(audioPopUpMenu,SIGNAL(timeOut(int)),
            this,SLOT(popUpMenuTimeOut(int)));
    audioPopUpMenu->setUi();
    audioPopUpMenu->setAudioType();
    audioPopUpMenu->setVisible(false);

    scalePopUpMenu = new ScalePopUpMenu(15000,this);
    connect(scalePopUpMenu,SIGNAL(timeOut(int)),
            this,SLOT(popUpMenuTimeOut(int)));
    scalePopUpMenu->setUi();
    scalePopUpMenu->setScaleType();
    scalePopUpMenu->setVisible(false);

    int index;
    popUpMenus = new QStackedWidget(this);
    index = popUpMenus->addWidget(spaceWidget);
    spaceWidget->setIndex(index);
    index = popUpMenus->addWidget(audioPopUpMenu);
    audioPopUpMenu->setIndex(index);
    index = popUpMenus->addWidget(scalePopUpMenu);
    scalePopUpMenu->setIndex(index);
    popUpCurrentIndex = spaceWidget->getIndex();

    mainLayout = new QHBoxLayout(ui->centralwidget);

    QVBoxLayout *fieldLayout = new QVBoxLayout();
    fieldLayout->addWidget(ui->fieldLabel);
    fieldLayout->addWidget(ui->fieldDataLabel);

    QVBoxLayout *qcLayout = new QVBoxLayout();
    qcLayout->addWidget(ui->qcLabel);
    qcLayout->addWidget(ui->qcDataLabel);
    ui->qcLabel->setText(QString::fromUtf8("数据源："));
    ui->qcDataLabel->setText(QString::fromUtf8("探头1"));

    QVBoxLayout *dataLayout = new QVBoxLayout();
    dataLayout->addLayout(fieldLayout);
    dataLayout->addWidget(ui->statusLabel);
    dataLayout->addLayout(qcLayout);

    QVBoxLayout *scaleLayout = new QVBoxLayout();
    scaleLayout->addWidget(ui->scaleLabel);
    scaleLayout->addWidget(ui->scaleDataLabel);
    ui->scaleDataLabel->setText(QString::fromUtf8("默认"));
    ui->scaleLabel->setVisible(false);
    ui->scaleDataLabel->setVisible(false);



    QVBoxLayout *adjustLayout = new QVBoxLayout();
    adjustLayout->addWidget(ui->adjustLabel);
    adjustLayout->addWidget(ui->adjustDataLabel);
    ui->adjustLabel->setVisible(false);
    ui->adjustDataLabel->setVisible(false);

    allDataLayout = new QVBoxLayout();
    allDataLayout->addWidget(ui->modeLabel);
    //allDataLayout->addStretch(1);
    allDataLayout->addWidget(popUpMenus,1);
    allDataLayout->addLayout(dataLayout);
//    allDataLayout->addStretch(1);
//    allDataLayout->addLayout(scaleLayout);
//    allDataLayout->addStretch(1);
//    allDataLayout->addLayout(adjustLayout);

    //displayPlot = NULL;
    displayPlot = new MainFrm();
    connect(this,SIGNAL(plotChange(int)),
            displayPlot,SLOT(deltaChangeSlot(int)));
    scalePopUpMenu->display = displayPlot;

    adjustMenu = new AdjustMenu(1,this);
    adjustMenu->setEnabled(false);
    adjustMenu->setDisplay(this->displayPlot);
    connect(adjustMenu,SIGNAL(centerTraceLabelClicked()),
            this,SLOT(setCenterTrace()));

    mainLayoutRight = new QStackedWidget(this);
    displayPlotIndex = mainLayoutRight->addWidget(displayPlot);
    adjustMenuIndex = mainLayoutRight->addWidget(adjustMenu);
    mainLayoutRight->setCurrentIndex(displayPlotIndex);

    mainLayout->addLayout(allDataLayout,1);
    mainLayout->addWidget(ui->line);
    mainLayout->addWidget(mainLayoutRight,6);

    dataCollector  = DataCollectorFactory::instance().getDataCollector();

    connect(dataCollector,SIGNAL(portOpenFailed(int)),
            this,SLOT(reStartTimerOn(int)));
    connect(dataCollector,SIGNAL(portOpenSuccessed()),
            this,SLOT(reStartTimerOff()));
    connect(&restartTimer,SIGNAL(timeout()),
            this,SLOT(reStart()));

//    connect(adjustMenu,SIGNAL(cycleTimeChanged()),
//            dataCollector,SLOT(changeSpeed()));
    ui->statusLabel->setText(QString::fromUtf8(" !不储存!"));

    connect(&(SystemDetail::instance()),SIGNAL(fullScaleChanged()),
            this,SLOT(setFullScale()));

    plotIndex = 1;
//    testFlag = false;
    menuStart = false;
    audiobaseFlag = false;
}

SreachMode::~SreachMode()
{
    delete ui;
}

void SreachMode::acquirePause()
{
    if (audioEnable == true)
    {
        emit pauseAudio();
    }
    if (pauseFlag)
    {
        ui->statusLabel->setText(QString::fromUtf8(" !不储存!"));
        dataCollector->startCollect();
    }
    else
    {
        ui->statusLabel->setText(QString::fromUtf8(" !暂停! "));
        dataCollector->stopCollect();
    }
    pauseFlag = !pauseFlag;
}

void SreachMode::showPopUpMenu(int index)
{
    popUpMenus->setCurrentIndex(index);
    popUpCurrentIndex = index;
    //qDebug() << "popUpCurrentIndex =" << popUpCurrentIndex;
}

void SreachMode::setAdjustMenu(bool show)
{
    if (show)
    {
        adjustMenu->setDetail();
        popUpMenus->setCurrentIndex(spaceWidget->getIndex());
        mainLayoutRight->setCurrentIndex(adjustMenuIndex);
        adjustMenu->setEnabled(true);
        adjustMenu->setMenuFocus();
        ui->adjustLabel->setText(QString::fromUtf8("返回:"));
        ui->adjustDataLabel->setText('"' + QString::fromUtf8("ESC") + '"');
    }
    else
    {
        mainLayoutRight->setCurrentIndex(displayPlotIndex);
        adjustMenu->setEnabled(false);
        this->setFocus();
        ui->adjustLabel->setText(QString::fromUtf8("调整:"));
        ui->adjustDataLabel->setText('"' + QString::fromUtf8("MENU") + '"');
    }
}

void SreachMode::setPlotXY()
{
    DETAIL detail = SystemDetail::instance().getDetail();
//    displayPlot->plot1->setDefault(DEFAULT);
    displayPlot->setZoomX(detail.rdngsScreen);
    displayPlot->setZoomY(detail.fullScale);
}

void SreachMode::sreachStart()
{
    pauseFlag = false;

    popUpMenus->setCurrentIndex(spaceWidget->getIndex());
    emit dataReset();
    //sleep(1);
    setPlotXY();
//    DETAIL detail = SystemDetail::instance().getDetail();
//    displayPlot->plot1->setDefault(DEFAULT);
//    displayPlot->plot1->setZoomX(detail.rdngsScreen);
//    displayPlot->plot1->setZoomY(detail.fullScale);
    ui->scaleDataLabel->setText("默认");

    emit changeSpeed(50);
    dataCollector->start();
    dataCollector->startCollect();

    menuStart = true;

    if (audioEnable == true)
    {
        audiobase1 = -1;
        audiobase2 = -1;
        audiobase3 = -1;
        audioWork = true;
        audiobaseFlag = false;
        emit startAudio();
    }
}

void SreachMode::setFieldLabel(int type, double data1, double data2, double lon, double lat)
{
    if (menuStart == false)
    {
        return;
    }
    Q_UNUSED(type);
    Q_UNUSED(lon);
    Q_UNUSED(lat);

    double data = 0.0;
    double delta = 0.0;

    if (audioEnable == true)
    {
        if (audiobaseFlag == false)
        {
            audiobase1 = data1;
            audiobase2 = data2;
            audiobase3 = data1 - data2;
            audiobaseFlag = true;
        }
    }

    if (1 == plotIndex)
    {
        data = data1;

        delta = (data - audiobase1);
        ui->qcDataLabel->setText(QString::fromUtf8("探头1"));
    }
    else if (2 == plotIndex)
    {
        data = data2;

        delta = (data - audiobase2);
        ui->qcDataLabel->setText(QString::fromUtf8("探头2"));
    }
    else if (3 == plotIndex)
    {
        data = data1-data2;

        delta = (data - audiobase3);
        ui->qcDataLabel->setText(QString::fromUtf8("梯度"));
    }

    QString dataStr;
    dataStr = QString::number(data,'f',3);
    if (data > 0.000001 || data < -0.000001)//data != 0.0
    {
        while ( dataStr.length() < 9)
        {
            dataStr = dataStr + "0";
        }

        if (dataStr.length() > 9)
        {
            dataStr.remove(9,dataStr.length()-9);
        }
    }
    ui->fieldDataLabel->setText(dataStr);

    //audio changed
    if (audioEnable == false)
    {
        return;
    }

    double ret = (fabs(delta)*2);
    if(ret > 0)
    {
        if (delta > 0)
        {
            emit changeHz(ret);
        }
        else
        {
            emit changeHz(-ret);
        }
    }
}

void SreachMode::popUpMenuTimeOut(int index)
{
    //qDebug() << "popupmenu timeout";
    if (index == popUpCurrentIndex)
    {
        showPopUpMenu(0);
    }
}

void SreachMode::reStartTimerOn(int index)
{
    if (index == 1)
    {
        ui->fieldDataLabel->setText(QString::fromUtf8("串口未打开"));
        restartTimer.start(1000);
    }
    else if (index == 2)
    {
        ui->fieldDataLabel->setText(QString::fromUtf8("串口无数据"));
    }
}

void SreachMode::reStartTimerOff()
{
    if (restartTimer.isActive())
    {
        restartTimer.stop();
    }
    ui->fieldDataLabel->setText(QString::fromUtf8("串口已打开"));
}

void SreachMode::reStart()
{
    dataCollector->start();
    restartTimer.stop();
}

void SreachMode::setCenterTrace()
{
    displayPlot->setCenterTrace();
    setAdjustMenu(false);
}

void SreachMode::setFullScale()
{
    if (displayPlot->getDefaultMode() == CUSTOM)
    {
        ui->scaleDataLabel->setText(QString::number(SystemDetail::instance().getDetail().fullScale));
        displayPlot->plot1->setStepFlag();
    }
}

void SreachMode::closeEvent(QCloseEvent *e)
{
    Q_UNUSED(e);

    if (audioEnable == true)
    {
        audioWork = false;
        emit stopAudio();
    }

    dataCollector->stopCollect();
    restartTimer.stop();
    menuStart = false;

    emit menuClose();
}

void SreachMode::keyPressEvent(QKeyEvent *e)
{
    if (mainLayoutRight->currentIndex() == displayPlotIndex)
    {
        if (e->key() == KEY_MENU)
        {
            setAdjustMenu(true);
        }
        else if (e->key() == KEY_ESC)
        {
            this->close();
        }
        else if (e->key() == KEY_PAUSE)
        {
            acquirePause();
        }
        else if (e->key() == KEY_AUDIO)
        {
            showPopUpMenu(audioPopUpMenu->getIndex());
        //    audioPopUpMenu->timerStart();
            //qDebug() << "KEY_AUDIO";
        }
        else if (e->key() == KEY_SCALE)
        {
            showPopUpMenu(scalePopUpMenu->getIndex());
//            scalePopUpMenu->timerStart();
            //qDebug() << "KEY_SCALE";
        }
        else if (e->key() == KEY_UP)
        {
            ((PopUpMenus *)popUpMenus->currentWidget())->upAction();
        }
        else if (e->key() == KEY_DOWN)
        {
            ((PopUpMenus *)popUpMenus->currentWidget())->downAction();
        }
        else if (e->key() == KEY_LEFT)
        {
            ((PopUpMenus *)popUpMenus->currentWidget())->leftAction();
        }
        else if (e->key() == KEY_RIGHT)
        {
            ((PopUpMenus *)popUpMenus->currentWidget())->rightAction();
        }
        else if (e->key() == KEY_MINUS)
        {

        }
        else if (e->key() == KEY_PERIOD)
        {
//            testFlag = !testFlag;
        }
        else if (e->key() == KEY_DEL)
        {
            //清屏
            emit dataReset();
        }
        else if (e->key() == Qt::Key_1)
        {
            //数据源切换
            emit plotChange(1);
            plotIndex = 1;
        }
        else if (e->key() == Qt::Key_2)
        {
            //数据源切换
            emit plotChange(2);
            plotIndex = 2;
        }
        else if (e->key() == Qt::Key_3)
        {
            //数据源切换
            emit plotChange(3);
            plotIndex = 3;
        }
    }
    else
    {
        if (e->key() == KEY_ESC)
        {
            setPlotXY();
            setAdjustMenu(false);
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
    }

}
