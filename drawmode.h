#ifndef DRAWMODE_H
#define DRAWMODE_H

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
#include "audiooutput.h"
#include "GpsPathPlot.h"

#define EMPTY 0
#define CONTINUOUS 1
#define DISCRETE 2
#define MAPPEDMENU 3

namespace Ui {
class DrawMode;
}

class DrawMode : public QMainWindow
{
    Q_OBJECT

    typedef struct
    {
        int surveyDirection;
        int parallelAxis;
        double LLx;
        double LLy;
        double URx;
        double URy;
        double spaceLine;
        double spaceMark;
    }DEFINEDATA;

public:
    explicit DrawMode(QWidget *parent = 0);
    ~DrawMode();
    void insertMark();
    void insertLine();
    void showPopUpMenu(int index);
    void acquirePause();
    void setAdjustMenu(bool show);

    void closephase();

    void getDefineData();

    void updateMap();

Q_SIGNALS:
    void menuClose();
    void lineAndMark(long,long,int*);
    void lineEnd(long,long);
    void endLineMessageStart(QString gridFilePath,short type, double LLx, double LLy, double URx, double URy);
    void dataReset();
    void plotChange(int);
    void changeHz(double);
    void startAudio();
    void stopAudio();
    void pauseAudio();
    void changeSpeed(int);

    void setRange(double,double,double,double);

public Q_SLOTS:
    void drawStart(int file, int type, long nextline, long markposition, DEFINEDATA data);
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
//    void showEidtMenu();
    void setCenterTrace();
    void setFullScale();


protected:
    virtual void closeEvent(QCloseEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);

private:
    Ui::DrawMode *ui;

    AdjustMenu *adjustMenu;
    SimpleEditMenu *simpleeditmenu;
    EndLineMsgWindow *endlinemessage;
    PauseMessage *pausemessage;
    EscMessage *escmessage;
    QHBoxLayout *mainLayout;

    AbstractDataCollector *dataCollector;
    QStackedWidget *mainLayoutRight;
    MainFrm *displayPlot;

    DataSaver  *pdataSaver;
    int datatype;
    long line;
    long mark;
    double Xpos;//当前调查坐标
    double Ypos;//当前调查坐标
    //边界
    double lowX;
    double lowY;
    double upX;
    double upY;

    int markPosition;
    int direction;//调查当前方向
    int axis;//调查轴向 1 Y轴 2 X轴
    int surveyDirection;//调查单双向 1 双向 2 单向
    unsigned int status[4][3] = {{38,6,7},
                                 {36,4,5},
                                 {32,0,1},
                                 {32,0,1}};
    int perLineNum[100];

    int statusKey;
    int statusValue;
    int saveType;
    int acquiceType;

    int popUpCurrentIndex;
    QStackedWidget *popUpMenus;
    PopUpMenus *spaceWidget;
    PopUpMenus *audioPopUpMenu;
    PopUpMenus *scalePopUpMenu;

    bool reAcquire;
    bool continueSurvey;

    volatile bool discreteFlag;
    bool testFlag;
    bool pauseFlag;
    bool menuStart;
    bool audiobaseFlag;

    QTimer restartTimer;

    int plotIndex;

    ////audio
    double audiobase1;
    double audiobase2;
    double audiobase3;


    //define
    DEFINEDATA defineData;//地图参数
    double perLine;//line步进
    double perMark;//mark步进

    double maxX ;
    double minX ;
    double maxY ;
    double minY ;

    QVector<QPointF> *map;
    QVector<QPointF> *mapLineMark;

    GpsPathPlot *gpsPath;
    PlotSeriesData *gpsPathData;
};

#endif // DRAWMODE_H
