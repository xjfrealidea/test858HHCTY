#ifndef MAPPEDMODE_H
#define MAPPEDMODE_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QCloseEvent>
#include <QKeyEvent>
#include <QStackedWidget>
#include "dataanalyser.h"
#include "datacollector.h"
#include "settings.h"
#include "datacollectorfactory.h"
#include "mainfrm.h"
#include "adjustmenu.h"
#include "datasaver.h"
#include "simpleeditmenu.h"
#include "EndLineMsgWindow.h"
#include "pausemessage.h"
#include "audiopopupmenu.h"
#include "scalepopupmenu.h"
#include "escmessage.h"
#include <QTimer>
#include <QMouseEvent>
#include <QVBoxLayout>
#include "GpsInfoWeight.h"
#include "GpsPathPlot.h"
#include "RealTimeMapView.h"
#include <QStackedWidget>
#include "audiooutput.h"

#define EMPTY 0
#define CONTINUOUS 1
#define DISCRETE 2
#define MAPPEDMENU 3

namespace Ui {
class MappedMode;
}

class MappedMode : public QMainWindow
{
    Q_OBJECT

public:
    explicit MappedMode(QWidget *parent = 0);
    ~MappedMode();
    void insertMark();
    void insertLine();
    void showPopUpMenu(int index);
    void acquirePause();
    void showEscMessage();
    void setAdjustMenu(bool show);

    void closephase();

Q_SIGNALS:
    void menuClose();
    void lineAndMark(long,long,int*);
    void lineEnd(long,long);
    void endLineMessageStart(QString gridFilePath,short type);
    void showGpsPos(double,double);
    void setGpsRange(double,double,double,double);
    void dataReset();

    void mapFormat();
    void mapClear();

    void plotChange(int);

    void changeHz(double);
    void startAudio();
    void stopAudio();
    void pauseAudio();
    void changeSpeed(int);

public Q_SLOTS:
    void mappedStart(int file, int type, long nextline, long markposition, int direction);
    void setFieldLabel(int type, double data1, double data2, double lon, double lat);
    void dataSave(int type, double data1, double data2, double lon, double lat);
    void simpleEditMenuClose();
    void setLineMark(long line,long mark);
    void endLineMessageClose();
    void pauseMessageClose();
    void popUpMenuTimeOut(int index);
    void escMessageClose();
    void reStartTimerOn(int index);
    void reStartTimerOff();
    void reStart();
    void setPerLineNum(int *perLineNum);
    void setCenterTrace();
    void setFullScale();
    void setMapWidget(RasterData *data);

protected:
    virtual void closeEvent(QCloseEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);

private:
    Ui::MappedMode *ui;

    AdjustMenu *adjustMenu;
    EndLineMsgWindow *endlinemessage;
    PauseMessage *pausemessage;
    EscMessage *escmessage;
    QHBoxLayout *mainLayout;

    AbstractDataCollector *dataCollector;
    QStackedWidget *mainLayoutRight;
    MainFrm *displayPlot;
    QVBoxLayout *displayLayout;
    GpsInfoWeight *gpsInfo;
    GpsPathPlot *gpsPath;
    PlotSeriesData *gpsPathData;
    PlotSeriesData *gpsPathData1;
//    RealTimeMapView *realTimeMapView;
    QThread *thread;
    QHBoxLayout *gpsLayout;
    QStackedWidget *mapWidget;

    DataSaver  *pdataSaver;
    int datatype;
    long line;
    long mark;
    int markPosition;
    unsigned int status[4][3] = {{38,6,7},
                                 {36,4,5},
                                 {32,0,1},
                                 {32,0,1}};
    int perLineNum[100];

    int statusKey;
    int statusValue;
    int savaType;
    int acquiceType;

    QStackedWidget *popUpMenus;
    PopUpMenus *spaceWidget;
    PopUpMenus *audioPopUpMenu;
    PopUpMenus *scalePopUpMenu;
    int popUpCurrentIndex;

    bool pauseFlag;
    bool testFlag;
    volatile bool discreteFlag;
    QTimer restartTimer;

    bool reAcquire;
    bool continueSurvey;
    bool gps_pos_flag;
    bool data_save_flag;

    bool menuStart;

    int gps_postype;

    double max_gps_lon;
    double min_gps_lon;
    double max_gps_lat;
    double min_gps_lat;
    double gps_lon;
    double gps_lat;

    double gps_offset = 0.000001;

    double m_pose_x;
    double m_pose_y;
    double m_pose_z;

    int lastMapIdx;
    int plotIndex;
    int mapWidgetSize;

    ////audio
    double audiobase1;
    double audiobase2;
    double audiobase3;

    bool audiobaseFlag;
};

#endif // MAPPEDMODE_H
