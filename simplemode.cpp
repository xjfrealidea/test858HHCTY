#include "simplemode.h"
#include "ui_simplemode.h"
#include "macro.h"
//#include <QDateTime>
#include <QTime>
#include <QDate>
#include <cstdio>
#include <cstring>
#include <QDebug>
#include "dataanalyser.h"
#include "filedatacache.h"
#include "widgetshowtype.h"
#include <QPushButton>
#include "systemdetail.h"

extern bool audioWork;
extern bool audioEnable;

SimpleMode::SimpleMode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimpleMode)
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

    //popUpMenus->setCurrentIndex(spaceWidget->getIndex());
    popUpCurrentIndex = spaceWidget->getIndex();

    simpleeditmenu = new SimpleEditMenu(this);
    connect(simpleeditmenu,SIGNAL(menuClose()),
            this,SLOT(simpleEditMenuClose()));
    connect(this,SIGNAL(lineAndMark(long,long,int*)),
            simpleeditmenu,SLOT(setLineAndMark(long,long,int*)));
    connect(simpleeditmenu,SIGNAL(lineMarkChanged(long,long)),
            this,SLOT(setLineMark(long,long)));

    endlinemessage = new EndLineMsgWindow(this);
    connect(endlinemessage,SIGNAL(menuClose()),
            this,SLOT(endLineMessageClose()));
    connect(this,SIGNAL(lineEnd(long,long)),
            endlinemessage,SLOT(setLineAndMark(long,long)));
    connect(this,SIGNAL(endLineMessageStart(QString,short)),
            endlinemessage,SLOT(menuStart(QString,short)));
    endlinemessage->setTextUp(0);

    pausemessage = new PauseMessage(this);
    connect(pausemessage,SIGNAL(menuClose()),
            this,SLOT(pauseMessageClose()));
    connect(this,SIGNAL(lineEnd(long,long)),
            pausemessage,SLOT(setLineAndMark(long,long)));

    escmessage = new EscMessage(this);
    connect(escmessage,SIGNAL(menuClose()),
            this,SLOT(escMessageClose()));

    mainLayout = new QHBoxLayout(ui->centralwidget);

    QVBoxLayout *fieldLayout = new QVBoxLayout();
    fieldLayout->addWidget(ui->fieldLabel);
    fieldLayout->addWidget(ui->fieldDataLabel);

    QVBoxLayout *qcLayout = new QVBoxLayout();
    qcLayout->addWidget(ui->qcLabel);
    qcLayout->addWidget(ui->qcDataLabel);
    ui->qcLabel->setText(QString::fromUtf8("数据源："));
    ui->qcDataLabel->setText(QString::fromUtf8("探头1"));

    QVBoxLayout *scaleLayout = new QVBoxLayout();
    scaleLayout->addWidget(ui->scaleLabel);
    scaleLayout->addWidget(ui->scaleDataLabel);
    ui->scaleLabel->setVisible(false);
    ui->scaleDataLabel->setVisible(false);

    ////三轴显示
//    testFlag = false;//开关

//    QVBoxLayout *poseLayout = new QVBoxLayout();
//    poseLayout->addWidget(ui->poseLabel);
//    poseLayout->addWidget(ui->poseXLabel);
//    poseLayout->addWidget(ui->poseYLabel);
//    poseLayout->addWidget(ui->poseZLabel);
    ui->poseLabel->setVisible(false);
    ui->poseXLabel->setVisible(false);
    ui->poseYLabel->setVisible(false);
    ui->poseZLabel->setVisible(false);

//    QVBoxLayout *fluxLayout = new QVBoxLayout();
//    fluxLayout->addWidget(ui->fluxLabel);
//    fluxLayout->addWidget(ui->fluxXLabel);
//    fluxLayout->addWidget(ui->fluxYLabel);
//    fluxLayout->addWidget(ui->fluxZLabel);
    ui->fluxLabel->setVisible(false);
    ui->fluxXLabel->setVisible(false);
    ui->fluxYLabel->setVisible(false);
    ui->fluxZLabel->setVisible(false);

    QVBoxLayout *lineMarkLayout = new QVBoxLayout();
    lineMarkLayout->addWidget(ui->lineLabel);
    lineMarkLayout->addWidget(ui->lineDataLabel);
    lineMarkLayout->addWidget(ui->markLabel);
    lineMarkLayout->addWidget(ui->markDataLabel);

    QVBoxLayout *dataLayout = new QVBoxLayout();
    dataLayout->addLayout(fieldLayout);
    dataLayout->addWidget(ui->statusLabel);
    dataLayout->addLayout(qcLayout);

    QVBoxLayout *allDataLayout = new QVBoxLayout();
    allDataLayout->addWidget(ui->modeLabel);
    //allDataLayout->addStretch(1);
    allDataLayout->addWidget(popUpMenus,1);
    allDataLayout->addLayout(dataLayout);
    //allDataLayout->addStretch(1);
//    allDataLayout->addLayout(poseLayout);
//    allDataLayout->addLayout(fluxLayout);
    //allDataLayout->addLayout(scaleLayout);
    allDataLayout->addStretch(1);
    allDataLayout->addLayout(lineMarkLayout);

    displayPlot = new MainFrm(this);
    connect(this,SIGNAL(plotChange(int)),
            displayPlot,SLOT(deltaChangeSlot(int)));
    scalePopUpMenu->display = displayPlot;

    adjustMenu = new AdjustMenu(2,this);
    adjustMenu->setEnabled(false);
    adjustMenu->setDisplay(this->displayPlot);
    connect(adjustMenu,SIGNAL(editLineMarkLabelClicked()),
            this,SLOT(showEidtMenu()));

    mainLayoutRight = new QStackedWidget(this);;
    mainLayoutRight->addWidget(displayPlot);
    mainLayoutRight->addWidget(adjustMenu);
    mainLayoutRight->setCurrentIndex(0);

    mainLayout->addLayout(allDataLayout,1);
    mainLayout->addWidget(ui->line);
    mainLayout->addWidget(mainLayoutRight,6);

    dataCollector  = DataCollectorFactory::instance().getDataCollector();

    connect(dataCollector,SIGNAL(portOpenFailed(int)),
            this,SLOT(reStartTimerOn(int)));
    connect(dataCollector,SIGNAL(portOpenSuccessed()),
            this,SLOT(reStartTimerOff()));

    savaType = SIMPLE;
    ui->statusLabel->setText(QString::fromUtf8(" !就绪! "));
    ui->scaleDataLabel->setText(QString::fromUtf8("默认"));

    setFullScale();
    connect(&(SystemDetail::instance()),SIGNAL(fullScaleChanged()),
            this,SLOT(setFullScale()));

    plotIndex = 1;

    testFlag = false;
    menuStart = false;
    audiobaseFlag = false;
}

SimpleMode::~SimpleMode()
{
    delete ui;
}

void SimpleMode::simpleStart(int file, int type, long nextline, long markposition, int direction)
{
    acquiceType = type;

    discreteFlag = true;//"DISCRETE"
    pauseFlag = false;
    line = nextline;
    mark = 0;

    markPosition = markposition;
    memset(perLineNum,-1,sizeof(int)*100);
    if (direction != 0)
    {
        continueSurvey = true;
    }
    else
    {
        continueSurvey = false;
    }
    if (acquiceType == CONTINUOUS)
    {
        if (direction == 1
                || direction == 0)
        {
            statusKey = 0;
        }
        else
        {
            statusKey = 1;
        }
    }
    else if (acquiceType == DISCRETE)
    {
        if (direction == 1
                || direction == 0)
        {
            statusKey = 2;
        }
        else
        {
            statusKey = 3;
        }
    }
    statusValue = 0;
    ui->lineDataLabel->setText(QString::number(line));
    ui->markDataLabel->setText(QString::number(mark));
    pdataSaver = new DataSaver(file,savaType);
    connect(pdataSaver,SIGNAL(setPerLineNum(int*)),
            this,SLOT(setPerLineNum(int*)));

    FileDataCache::instance().setDataSaver(pdataSaver);

    popUpMenus->setCurrentIndex(spaceWidget->getIndex());

    emit dataReset();
    reAcquire = false;

    displayPlot->plot1->setDefault(DEFAULT);
//    displayPlot->plot1->setZoomX(1.0);
//    displayPlot->plot1->setZoomY(0.5);
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

    if (continueSurvey == true)
    {
        pdataSaver->continueStart();
    }
}

void SimpleMode::closeEvent(QCloseEvent *e)
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

void SimpleMode::setFieldLabel(int type, double data1, double data2, double lon, double lat)
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

void SimpleMode::dataSave(int type, double data1, double data2, double lon, double lat)
{
    Q_UNUSED(type);
    Q_UNUSED(lon);
    Q_UNUSED(lat);

    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    char timestr[21];
    sprintf(timestr,"%.2d:%.2d:%.2d.%02d %.2d/%.2d/%2.d",
            time.hour(),time.minute(),time.second(),time.msec()/10,
            date.month(),date.day(),date.year()%100);

    char str[150];
    sprintf(str,"%-2u %10.3lf %10.3lf %3d %s %3u",
            0,data1,data2,plotIndex-1,timestr,0);
    FileDataCache::instance().getData(READINGS,QString::fromLocal8Bit(str));
    if (!discreteFlag)//"DISCRETE"
    {
        discreteFlag = true;
    }
}

void SimpleMode::insertMark()
{
    if (pauseFlag)
    {
        dataCollector->startCollect();
        pauseFlag = false;
    }
    if (acquiceType == DISCRETE)//"DISCRETE"
    {
        discreteFlag = false;
    }
    if (statusValue == 0
            || reAcquire)
    {
        QObject::connect(&DataAnalyser::instance(), SIGNAL(dataCollected(int, double,double,double,double)),
                         this,SLOT(dataSave(int, double, double,double,double)));
        reAcquire = false;
        if (continueSurvey == false)
        {
            pdataSaver->start();
        }
    }
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    char timestr[21];
    sprintf(timestr,"%.2d:%.2d:%.2d.%02d %.2d/%.2d/%2.d",
            time.hour(),time.minute(),time.second(),time.msec()/10,
            date.month(),date.day(),date.year()%100);

    char str[100];
    sprintf(str,"%-2u %12.2lf %12.2lf %s %10ld %11ld %11ld %3u",
            3,(double)this->line,(double)markPosition,timestr,(long)0,line,mark,status[statusKey][statusValue]);

    FileDataCache::instance().getData(MARK,QString::fromLocal8Bit(str));
    if (statusValue == 0)
    {
        statusValue = 1;
        ui->statusLabel->setText(QString::fromUtf8(" !采集! "));
    }
    if (statusValue == 1)
    {
        ui->statusLabel->setText(QString::fromUtf8(" !采集! "));
    }
    if (statusKey == 0 || statusKey == 2)
    {
        markPosition++;
    }
    else
    {
        markPosition--;
    }
    mark++;
    ui->markDataLabel->setText(QString::number(mark));
}

void SimpleMode::insertLine()
{
    if (statusValue == 0)
    {
        return;
    }

    if (acquiceType != DISCRETE && pauseFlag == false)
    {
        pauseFlag = true;
    }
    if (acquiceType == DISCRETE)//"DISCRETE"
    {
        discreteFlag = false;
    }

    QObject::disconnect(&DataAnalyser::instance(), SIGNAL(dataCollected(int, double,double,double,double)),
                    this,SLOT(dataSave(int, double, double,double,double)));

    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    char timestr[21];
    sprintf(timestr,"%.2d:%.2d:%.2d.%02d %.2d/%.2d/%2.d",
            time.hour(),time.minute(),time.second(),time.msec()/10,
            date.month(),date.day(),date.year()%100);
    char str[100];
    sprintf(str,"%-2u %12.2lf %12.2lf %s %10ld %11ld %11ld %3u",
            3,(double)this->line,(double)markPosition,timestr,(long)0,line,mark,status[statusKey][2]);

    FileDataCache::instance().getData(ENDLINE,QString::fromLocal8Bit(str));
    statusValue = 0;
     if (statusKey == 0)
     {
         statusKey = 1;
     }
     else if (statusKey == 1)
     {
         statusKey = 0;
     }
     else if (statusKey == 2)
     {
         statusKey = 3;
     }
     else if (statusKey == 3)
     {
         statusKey = 2;
     }

    //ui->statusLabel->setText(QString::fromLocal8Bit(" !READY! "));
    ui->statusLabel->setText(QString::fromUtf8(" !就绪! "));

    perLineNum[line] = mark;
    //qDebug() << "perLineNum["<< line <<"] = " << mark;
    emit lineEnd(line,mark);

    line++;
    mark = 0;
    ui->lineDataLabel->setText(QString::number(line));
    ui->markDataLabel->setText(QString::number(mark));

    FileDataCache::instance().makeSimpleGrid();
    emit endLineMessageStart(FileDataCache::instance().getGridTextPath(),0);

//    endlinemessage->showFullScreen();
//    endlinemessage->show();
    WidgetShow::widgetShow(endlinemessage);
    //this->hide();
}

void SimpleMode::simpleEditMenuClose()
{
//    this->showFullScreen();
//    this->show();
    FileDataCache::instance().makeSimpleGrid();
    WidgetShow::widgetShow(this);
}

void SimpleMode::setLineMark(long line, long mark)
{
    if (mark == 0)
    {
        statusValue = 0;
    }
    if (this->line != line)
    {
        if (statusKey == 0)
        {
            statusKey = 1;
        }
        else if (statusKey == 1)
        {
            statusKey = 0;
        }
        else if (statusKey == 2)
        {
            statusKey = 3;
        }
        else if (statusKey == 3)
        {
            statusKey = 2;
        }
    }
    if (statusKey == 0 || statusKey == 2)
    {
        markPosition = mark;
    }
    else
    {
        markPosition = perLineNum[line-1] - mark;
    }
    this->line = line;
    this->mark = mark;
    ui->lineDataLabel->setText(QString::number(line));
    ui->markDataLabel->setText(QString::number(mark));
    if (this->mark != 0)
    {
        statusValue = 1;
        reAcquire = true;
    }
}

void SimpleMode::endLineMessageClose()
{
//    this->showFullScreen();
//    this->show();
    WidgetShow::widgetShow(this);
}

void SimpleMode::acquirePause()
{
    if (audioEnable == true)
    {
        emit pauseAudio();
    }
    if (pauseFlag)
    {
        dataCollector->startCollect();
        if (statusValue == 0)
        {
            ui->statusLabel->setText(QString::fromUtf8(" !就绪! "));
        }
        else
        {
            ui->statusLabel->setText(QString::fromUtf8(" !采集! "));
        }
    }
    else
    {
        dataCollector->stopCollect();
        ui->statusLabel->setText(QString::fromUtf8(" !暂停! "));
    }
    pauseFlag = !pauseFlag;
}

void SimpleMode::pauseMessageClose()
{
//    this->showFullScreen();
//    this->show();
    WidgetShow::widgetShow(this);
}

void SimpleMode::popUpMenuTimeOut(int index)
{
    //qDebug() << "popupmenu timeout";
    if (index == popUpCurrentIndex)
    {
        showPopUpMenu(0);
    }
}

void SimpleMode::escMessageClose()
{
//    this->showFullScreen();
//    this->show();
    WidgetShow::widgetShow(this);
}

void SimpleMode::reStartTimerOn(int index)
{
   // restartTimer.start(2000);
    if (index == 1)
    {
        ui->fieldDataLabel->setText(QString::fromUtf8("串口未打开"));
    }
    else if (index == 2)
    {
        ui->fieldDataLabel->setText(QString::fromUtf8("串口无数据"));
    }
}

void SimpleMode::reStartTimerOff()
{
    if (restartTimer.isActive())
    {
        restartTimer.stop();
    }
    ui->fieldDataLabel->setText(QString::fromUtf8("串口已打开"));
}

void SimpleMode::reStart()
{
    dataCollector->start();
    restartTimer.stop();
}

void SimpleMode::setPerLineNum(int *perLineNum)
{
    memcpy(this->perLineNum,perLineNum,sizeof(int)*100);
}

void SimpleMode::showPopUpMenu(int index)
{
    popUpMenus->setCurrentIndex(index);
    popUpCurrentIndex = index;
}

void SimpleMode::setAdjustMenu(bool show)
{
    if (show)
    {
        adjustMenu->setDetail();
        mainLayoutRight->setCurrentIndex(1);
        adjustMenu->setEnabled(true);
        adjustMenu->setMenuFocus();
    }
    else
    {
        mainLayoutRight->setCurrentIndex(0);
        adjustMenu->setEnabled(false);
        this->setFocus();
    }
}

void SimpleMode::closephase()
{
    FileDataCache::instance().checkLastLine(acquiceType);
    FileDataCache::instance().removeDataSaver();
    pdataSaver->stop();
    disconnect(pdataSaver,SIGNAL(setPerLineNum(int*)),
            this,SLOT(setPerLineNum(int*)));
    delete pdataSaver;
    pdataSaver = NULL;
    dataCollector->stopCollect();

    if (statusValue != 0)
    {
        QObject::disconnect(&DataAnalyser::instance(), SIGNAL(dataCollected(int, double,double,double,double)),
                         this,SLOT(dataSave(int, double,double,double,double)));
    }
    restartTimer.stop();
}

void SimpleMode::showEidtMenu()
{
    pauseFlag = true;
    ui->statusLabel->setText(QString::fromUtf8(" !就绪! "));

    emit lineAndMark(line,mark,perLineNum);

    WidgetShow::widgetShow(simpleeditmenu);
    this->hide();
}

void SimpleMode::setCenterTrace()
{
    displayPlot->setCenterTrace();
    setAdjustMenu(false);
}

void SimpleMode::setFullScale()
{
    if (displayPlot->getDefaultMode() == CUSTOM)
    {
        ui->scaleDataLabel->setText(QString::number(SystemDetail::instance().getDetail().fullScale));
    }
}

void SimpleMode::keyPressEvent(QKeyEvent *e)
{
    if (mainLayoutRight->currentIndex() == 0)
    {
        if (e->key() == KEY_MENU)
        {
            setAdjustMenu(true);
        }
        else if (e->key() == KEY_ESC)
        {
            if (statusValue == 0)
            {
                closephase();
                this->close();
            }
        }
        else if (e->key() == KEY_MARK)
        {
            insertMark();
        }
        else if (e->key() == KEY_ENDLINE)
        {
            insertLine();
        }
        else if (e->key() == KEY_PAUSE)
        {
            if (acquiceType != 2)
            {
                acquirePause();
            }
        }
        else if (e->key() == KEY_AUDIO)
        {
            if (statusValue == 0)
            {
                showPopUpMenu(audioPopUpMenu->getIndex());
                audioPopUpMenu->timerStart();
                //qDebug() << "KEY_AUDIO";
            }
        }
        else if (e->key() == KEY_SCALE)
        {
            if (statusValue == 0)
            {
                showPopUpMenu(scalePopUpMenu->getIndex());
                scalePopUpMenu->timerStart();
                //qDebug() << "KEY_SCALE";
            }
        }
        else if (e->key() == KEY_UP)
        {
            if (statusValue == 0)
            {
                ((PopUpMenus *)popUpMenus->currentWidget())->upAction();
            }
        }
        else if (e->key() == KEY_DOWN)
        {
            if (statusValue == 0)
            {
                ((PopUpMenus *)popUpMenus->currentWidget())->downAction();
            }
        }
        else if (e->key() == KEY_LEFT)
        {
            if (statusValue == 0)
            {
                ((PopUpMenus *)popUpMenus->currentWidget())->leftAction();
            }
        }
        else if (e->key() == KEY_RIGHT)
        {
            if (statusValue == 0)
            {
                ((PopUpMenus *)popUpMenus->currentWidget())->rightAction();
            }
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
            if (statusValue == 0)
            {
                //清屏
                emit dataReset();
            }
        }
        else if (e->key() == Qt::Key_1)
        {
            //数据源切换
            if (statusValue == 0)
            {
                emit plotChange(1);
                plotIndex = 1;
            }
        }
        else if (e->key() == Qt::Key_2)
        {
            //数据源切换
            if (statusValue == 0)
            {
                emit plotChange(2);
                plotIndex = 2;
            }
        }
        else if (e->key() == Qt::Key_3)
        {
            //数据源切换
            if (statusValue == 0)
            {
                emit plotChange(3);
                plotIndex = 3;
            }
        }
    }
    else
    {
        if (e->key() == KEY_ESC)
        {
            setAdjustMenu(false);
        }
        if (e->key() == KEY_UP)
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
