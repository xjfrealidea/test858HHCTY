#include "mappedmode.h"
#include "ui_mappedmode.h"
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
#include <qwt_scale_div.h>
#include <qwt_scale_draw.h>
#include <qwt_scale_engine.h>
#include <settings.h>
#include <QThread>

extern bool audioWork;
extern bool audioEnable;

MappedMode::MappedMode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MappedMode)
{
    ui->setupUi(this);

    connect(&DataAnalyser::instance(),SIGNAL(fieldData(int,double,double,double,double)),
            this,SLOT(setFieldLabel(int,double,double, double, double)));
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

    endlinemessage = new EndLineMsgWindow(this);
    connect(endlinemessage,SIGNAL(menuClose()),
            this,SLOT(endLineMessageClose()));
    connect(this,SIGNAL(lineEnd(long,long)),
            endlinemessage,SLOT(setLineAndMark(long,long)));
    connect(this,SIGNAL(endLineMessageStart(QString,short)),
            endlinemessage,SLOT(menuStart(QString,short)));
    connect(this,SIGNAL(showGpsPos(double,double)),
            endlinemessage,SLOT(setGpsPos(double,double)));
    endlinemessage->setTextUp(1);

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

//    QVBoxLayout *poseLayout = new QVBoxLayout();
//    poseLayout->addWidget(ui->poseLabel);
//    poseLayout->addWidget(ui->poseXLabel);
//    poseLayout->addWidget(ui->poseYLabel);
//    poseLayout->addWidget(ui->poseZLabel);
    ui->poseLabel->setVisible(false);
    ui->poseXLabel->setVisible(false);
    ui->poseYLabel->setVisible(false);
    ui->poseZLabel->setVisible(false);

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
//    connect(adjustMenu,SIGNAL(editLineMarkLabelClicked()),
//            this,SLOT(showEidtMenu()));

    displayLayout = new QVBoxLayout();

    gpsPath = new GpsPathPlot();
    gpsPathData = gpsPath->getSeriesData();
    //gpsPathData1 = gpsPath->getSeriesData1();
    connect(this,SIGNAL(setGpsRange(double,double,double,double)),
            gpsPath,SLOT(setIntervalRange(double,double,double,double)));
    gpsInfo = new GpsInfoWeight();
  //  connect(&DataAnalyser::instance(),SIGNAL(gpsStatus(int,int)),
  //          gpsInfo,SLOT(setGpsStatus(int,int)));
//    realTimeMapView = new RealTimeMapView();

//    connect(realTimeMapView,SIGNAL(mapData(RasterData*)),
//            this,SLOT(setMapWidget(RasterData*)));
//    connect(this,SIGNAL(mapFormat()),
//            realTimeMapView,SLOT(format()));

//    thread = new QThread(this);
//    realTimeMapView->moveToThread(thread);
//    thread->start();
//    emit mapFormat();

    mapWidget = new QStackedWidget(this);
    mapWidget->addWidget(gpsPath);
    mapWidgetSize = 0;

    gpsLayout = new QHBoxLayout();
    gpsLayout->addWidget(mapWidget,1);
    gpsLayout->addWidget(gpsInfo,1);

    displayLayout->addWidget(displayPlot,1);
    displayLayout->addLayout(gpsLayout,2);
/*
    mainLayoutRight = new QStackedWidget(this);;
    mainLayoutRight->addWidget(displayPlot);
    mainLayoutRight->addWidget(adjustMenu);
    mainLayoutRight->setCurrentIndex(0);
*/
    adjustMenu->setVisible(false);

    mainLayout->addLayout(allDataLayout,1);
    mainLayout->addWidget(ui->line);
//    mainLayout->addWidget(mainLayoutRight,6);
    mainLayout->addLayout(displayLayout,6);

    dataCollector  = DataCollectorFactory::instance().getDataCollector();

    connect(dataCollector,SIGNAL(portOpenFailed(int)),
            this,SLOT(reStartTimerOn(int)));
    connect(dataCollector,SIGNAL(portOpenSuccessed()),
            this,SLOT(reStartTimerOff()));

    savaType = MAPPED;
    ui->statusLabel->setText(QString::fromUtf8(" !就绪! "));

    setFullScale();
    connect(&(SystemDetail::instance()),SIGNAL(fullScaleChanged()),
            this,SLOT(setFullScale()));

    ui->scaleDataLabel->setText(QString::fromUtf8("默认"));
    ui->lineLabel->setText(QString::fromUtf8("经度:"));
    ui->markLabel->setText(QString::fromUtf8("纬度:"));

    plotIndex = 1;
    testFlag = false;
    menuStart = false;
    audiobaseFlag = false;
}

MappedMode::~MappedMode()
{
    delete ui;
//    thread->exit();
//    thread->deleteLater();
}

void MappedMode::mappedStart(int file, int type, long nextline, long markposition, int direction)
{
    max_gps_lon = -999.0;
    min_gps_lon = 999.0;
    max_gps_lat = -999.0;
    min_gps_lat = 999.0;
    gps_lon = 361.0;
    gps_lat = 361.0;
    gps_postype = 0;
    lastMapIdx = 0;

    acquiceType = type;
    //qDebug() << "acquiceType =" << type;
    discreteFlag = true;//"DISCRETE"
    pauseFlag = false;
    gps_pos_flag = false;

    line = nextline;
    mark = 0;
    //lastLine = 0;
    //lastMark = 0;
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
//    QObject::connect(dataCollector, SIGNAL(dataCollected(QByteArray,qint16)), pdataSaver, SLOT(onDataCollected(QByteArray)));
//    pdataSaver->start();

    FileDataCache::instance().setDataSaver(pdataSaver);

    popUpMenus->setCurrentIndex(spaceWidget->getIndex());
   // DataAnalyser::instance().dataReset();
    emit dataReset();
    reAcquire = false;

    displayPlot->plot1->setDefault(DEFAULT);
//    displayPlot->plot1->setZoomY(0.4);
    ui->scaleDataLabel->setText("默认");

    emit changeSpeed(50);
    dataCollector->start();
    dataCollector->startCollect();

    data_save_flag = false;
    QObject::connect(&DataAnalyser::instance(), SIGNAL(dataCollected(int, double,double,double,double)),
                             this,SLOT(dataSave(int, double,double,double,double)));

    gpsPathData->d_data.clearData();
    //gpsPathData1->d_data.clearData();

    mapWidget->setCurrentIndex(0);
//    QObject::connect(&DataAnalyser::instance(), SIGNAL(fieldData(int,double,double,double,double)),
//                     realTimeMapView, SLOT(addData(int,double,double,double,double)));
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

//    QObject::connect(&DataAnalyser::instance(), SIGNAL(fieldData(int,double,double,double,double)),
//                     realTimeMapView, SLOT(addData(int,double,double,double,double)));
}

void MappedMode::closeEvent(QCloseEvent *e)
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

void MappedMode::setFieldLabel(int type, double data1, double data2, double lon, double lat)
{
    if (menuStart == false)
    {
        return;
    }

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

    //gps data
    gps_postype = type;
    gpsInfo->setPostypeindex(gps_postype);

    if (gps_postype == 0)
    {
        ui->statusLabel->setText(QString::fromUtf8(" GPS未就绪"));
        return;
    }

    this->gps_lon = lon;
    this->gps_lat = lat;

    bool gps_range_changed = false;

    if (this->gps_lon > max_gps_lon)
    {
        max_gps_lon = this->gps_lon;
        gps_range_changed = true;
    }
    if (this->gps_lon < min_gps_lon)
    {
        min_gps_lon = this->gps_lon;
        gps_range_changed = true;
    }
    if (this->gps_lat > max_gps_lat)
    {
        max_gps_lat = this->gps_lat;
        gps_range_changed = true;
    }
    if (this->gps_lat < min_gps_lat)
    {
        min_gps_lat = this->gps_lat;
        gps_range_changed = true;
    }
    if (true == gps_range_changed)
    {
        emit setGpsRange(min_gps_lon - gps_offset, max_gps_lon + gps_offset, min_gps_lat - gps_offset, max_gps_lat + gps_offset);
    }

    ui->lineDataLabel->setText(QString::number(this->gps_lon,'f',6));
    ui->markDataLabel->setText(QString::number(this->gps_lat,'f',6));

    gpsPathData->d_data.append(QPointF(this->gps_lon,this->gps_lat));
//    gpsPathData1->d_data.append(QPointF(this->gps_lon-0.000001,this->gps_lat-0.000001));

    if (gps_pos_flag)
    {
        emit showGpsPos(this->gps_lon,this->gps_lat);
    }
    if (ui->statusLabel->text() == QString::fromUtf8(" GPS未就绪"))
    {
        if (statusValue == 1)
        {
            ui->statusLabel->setText(QString::fromUtf8(" !采集! "));
        }
        else
        {
            ui->statusLabel->setText(QString::fromUtf8(" !就绪! "));
        }
    }

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

void MappedMode::dataSave(int type, double data1, double data2, double lon, double lat)
{
 //   gpsInfo->setPostypeindex(type);
    if (data_save_flag)
    {
        QTime time = QTime::currentTime();
        QDate date = QDate::currentDate();
        char timestr[21];
        sprintf(timestr,"%.2d:%.2d:%.2d.%02d %.2d/%.2d/%2.d",
                time.hour(),time.minute(),time.second(),time.msec()/10,
                date.month(),date.day(),date.year()%100);

        char str[200];
        sprintf(str,"%-2u %10.3lf %10.3lf %15.11lf %15.11lf %3d %3d %s %3u",
                0,data1,data2,lon,lat,plotIndex-1,type,timestr,0);
        FileDataCache::instance().getData(READINGS,QString::fromLocal8Bit(str));

        if (!discreteFlag)//"DISCRETE"
        {
            discreteFlag = true;
        }
    }
}

void MappedMode::insertMark()
{
    if(gps_postype == 0)
    {
        ui->statusLabel->setText(QString::fromUtf8("GPS未就绪"));
        return;
    }

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
//        QObject::connect(&DataAnalyser::instance(), SIGNAL(dataCollected(int, double,double,double,double)),
//                         this,SLOT(dataSave(int, double, double,double,double)));
        data_save_flag = true;
        reAcquire = false;
        if (continueSurvey == false)
        {
            pdataSaver->start();
        }
    }

//    QObject::disconnect(&DataAnalyser::instance(), SIGNAL(fieldData(int,double,double,double,double)),
//                     realTimeMapView, SLOT(addData(int,double,double,double,double)));

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
        //ui->statusLabel->setText(QString::fromLocal8Bit("!ACQUIRE!"));
        ui->statusLabel->setText(QString::fromUtf8(" !采集! "));
    }
    else if (statusValue == 1)
    {
        //ui->statusLabel->setText(QString::fromLocal8Bit("!ACQUIRE!"));
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
 }

void MappedMode::insertLine()
{
    if (statusValue == 0)
    {
        return;
    }

    if (acquiceType != DISCRETE && !pauseFlag)
    {
        //dataCollector->stopCollect();
        pauseFlag = true;
    }
    if (acquiceType == DISCRETE)//"DISCRETE"
    {
        discreteFlag = false;
    }

    data_save_flag = false;


//    QObject::connect(&DataAnalyser::instance(), SIGNAL(fieldData(int,double,double,double,double)),
//                     realTimeMapView, SLOT(addData(int,double,double,double,double)));

    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    char timestr[21];
    sprintf(timestr,"%.2d:%.2d:%.2d.%02d %.2d/%.2d/%2.d",
            time.hour(),time.minute(),time.second(),time.msec()/10,
            date.month(),date.day(),date.year()%100);
    char str[100];
    sprintf(str,"%-2u %12.2lf %12.2lf %s %10ld %11ld %11ld %3u",
            3,(double)this->line,(double)markPosition,timestr,(long)0,line,mark,status[statusKey][2]);
//    pdataSaver->onDataCollected(QString::fromLocal8Bit(str));
//    qDebug() << QString::fromLocal8Bit(str);
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
 //   emit lineEnd(line,mark);

    line++;
    mark = 0;

    FileDataCache::instance().setRangeOfLon(max_gps_lon, min_gps_lon);
    FileDataCache::instance().setRangeOfLat(max_gps_lat, min_gps_lat);
    FileDataCache::instance().makeGpsGrid();
    //FileDataCache::instance().makeSimpleGrid();
    emit endLineMessageStart(FileDataCache::instance().getGridTextPath(),1);

//    endlinemessage->showFullScreen();
//    endlinemessage->show();
    WidgetShow::widgetShow(endlinemessage);
    gps_pos_flag = true;
    //this->hide();

}

void MappedMode::simpleEditMenuClose()
{
//    this->showFullScreen();
//    this->show();
    FileDataCache::instance().makeSimpleGrid();
    WidgetShow::widgetShow(this);
}

void MappedMode::setLineMark(long line, long mark)
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

void MappedMode::endLineMessageClose()
{
//    this->showFullScreen();
//    this->show();
    WidgetShow::widgetShow(this);
    gps_pos_flag = false;
}

void MappedMode::acquirePause()
{
    if (audioEnable == true)
    {
        emit pauseAudio();
    }
    //qDebug() << pauseFlag;
    if (statusValue != 0)
    {
        if (pauseFlag)
        {
            dataCollector->startCollect();
            ui->statusLabel->setText(QString::fromUtf8(" !采集! "));
        }
        else
        {
            dataCollector->stopCollect();
            ui->statusLabel->setText(QString::fromUtf8(" !暂停! "));
        }
        pauseFlag = !pauseFlag;
    }
}

void MappedMode::pauseMessageClose()
{
//    this->showFullScreen();
//    this->show();
    WidgetShow::widgetShow(this);
}

void MappedMode::popUpMenuTimeOut(int index)
{
    //qDebug() << "popupmenu timeout";
    if (index == popUpCurrentIndex)
    {
        showPopUpMenu(0);
    }
}

void MappedMode::escMessageClose()
{
//    this->showFullScreen();
//    this->show();
    WidgetShow::widgetShow(this);
}

void MappedMode::reStartTimerOn(int index)
{
    //restartTimer.start(2000);
    if (index == 1)
    {
        ui->fieldDataLabel->setText(QString::fromUtf8("串口未打开"));
    }
    else if (index == 2)
    {
        ui->fieldDataLabel->setText(QString::fromUtf8("串口无数据"));
    }
    //ui->fieldDataLabel->setText(QString::fromUtf8("串口未打开"));
}

void MappedMode::reStartTimerOff()
{
    if (restartTimer.isActive())
    {
        restartTimer.stop();
    }
    ui->fieldDataLabel->setText(QString::fromUtf8("串口已打开"));
}

void MappedMode::reStart()
{
    dataCollector->start();
    restartTimer.stop();
}

void MappedMode::setPerLineNum(int *perLineNum)
{
    memcpy(this->perLineNum,perLineNum,sizeof(int)*100);
}

void MappedMode::showPopUpMenu(int index)
{
    popUpMenus->setCurrentIndex(index);
    popUpCurrentIndex = index;
}

void MappedMode::showEscMessage()
{
    if (acquiceType!=2)
    {
        //dataCollector->stopCollect();
        pauseFlag = true;
        //ui->statusLabel->setText(QString::fromLocal8Bit(" !PAUSE! "));
        ui->statusLabel->setText(QString::fromUtf8(" !暂停! "));
    }
//    escmessage->showFullScreen();
//    escmessage->show();
    WidgetShow::widgetShow(escmessage);
    this->hide();
}

void MappedMode::setAdjustMenu(bool show)
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

void MappedMode::closephase()
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
        data_save_flag = false;
    }
    QObject::disconnect(&DataAnalyser::instance(), SIGNAL(dataCollected(int, double,double,double,double)),
                     this,SLOT(dataSave(int, double,double,double,double)));

//    QObject::disconnect(&DataAnalyser::instance(), SIGNAL(fieldData(int,double,double,double,double)),
//                     realTimeMapView, SLOT(addData(int,double,double,double,double)));

    restartTimer.stop();
}

void MappedMode::setCenterTrace()
{
    displayPlot->setCenterTrace();
    setAdjustMenu(false);
}

void MappedMode::setFullScale()
{
    if (displayPlot->getDefaultMode() == CUSTOM)
    {
        ui->scaleDataLabel->setText(QString::number(SystemDetail::instance().getDetail().fullScale));
    }
}

void MappedMode::setMapWidget(RasterData *data)
{
    if (statusValue != 0)
    {
        return;
    }

    SpectrogramPlot *map = new SpectrogramPlot();
    if (NULL == map)
    {
        return;
    }
    map->format(1,data);
    map->mapReplot();

    int newMapIdx = mapWidget->addWidget(map);
    mapWidget->setCurrentIndex(newMapIdx);
    mapWidgetSize++;
    if (5 < mapWidgetSize)
    {
        QWidget *w = mapWidget->widget(1);
        if (NULL != w)
        {
            if (w == gpsPath)
            {
                w = mapWidget->widget(2);
            }
            mapWidget->removeWidget(w);
            mapWidgetSize--;
        }
    }
}

void MappedMode::keyPressEvent(QKeyEvent *e)
{
  //  if (mainLayoutRight->currentIndex() == 0)
    {
        if (e->key() == KEY_MENU)
        {
          //  setAdjustMenu(true);
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
                if (((PopUpMenus *)popUpMenus->currentWidget())->getIndex() ==  spaceWidget->getIndex())
                {
                    mapWidget->setCurrentIndex(0);
                }
                else
                {
                    ((PopUpMenus *)popUpMenus->currentWidget())->upAction();
                }
            }
        }
        else if (e->key() == KEY_DOWN)
        {
            if (statusValue == 0)
            {
                if (((PopUpMenus *)popUpMenus->currentWidget())->getIndex() ==  spaceWidget->getIndex())
                {
                    mapWidget->setCurrentIndex(lastMapIdx);
                }
                else
                {
                    ((PopUpMenus *)popUpMenus->currentWidget())->downAction();
                }
            }
        }
        else if (e->key() == KEY_LEFT)
        {
            if (statusValue == 0)
            {
                if (((PopUpMenus *)popUpMenus->currentWidget())->getIndex() ==  spaceWidget->getIndex())
                {
                    int idx = mapWidget->currentIndex();
                    idx--;
                    if (idx < 0)
                    {
                        idx = lastMapIdx;
                    }
                    mapWidget->setCurrentIndex(idx);
                }
                else
                {
                    ((PopUpMenus *)popUpMenus->currentWidget())->leftAction();
                }
            }
        }
        else if (e->key() == KEY_RIGHT)
        {
            if (statusValue == 0)
            {
                if (((PopUpMenus *)popUpMenus->currentWidget())->getIndex() ==  spaceWidget->getIndex())
                {
                    int idx = mapWidget->currentIndex();
                    idx++;
                    if (idx > lastMapIdx)
                    {
                        idx = 0;
                    }
                    mapWidget->setCurrentIndex(idx);
                }
                else
                {
                    ((PopUpMenus *)popUpMenus->currentWidget())->rightAction();
                }
            }
        }
        else if (e->key() == KEY_MINUS)
        {

        }
        else if (e->key() == KEY_PERIOD)
        {
            if (statusValue == 0)
            {
                gpsPathData->d_data.clearData();
            //    gpsPathData1->d_data.clearData();
            }
        }
        else if (e->key() == KEY_DEL)
        {
            if (statusValue == 0)
            {
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
 /*   else
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
    }*/
}
