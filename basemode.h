#ifndef BASEMODE_H
#define BASEMODE_H

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

#define EMPTY 0
#define CONTINUOUS 1
#define DISCRETE 2
#define MAPPEDMENU 3

namespace Ui {
class BaseMode;
}

class BaseMode : public QMainWindow
{
    Q_OBJECT

public:
    explicit BaseMode(QWidget *parent = 0);
    ~BaseMode();
    void insertMark();
    void insertLine();
    void showPopUpMenu(int index);
    void acquirePause();
    void setAdjustMenu(bool show);

    void closephase();

Q_SIGNALS:
    void menuClose();
    void lineAndMark(long,long,int*);
    void lineEnd(long,long);
    void endLineMessageStart(QString gridFilePath,short type);
    void dataReset();
    void plotChange(int);
    void changeHz(double);
    void startAudio();
    void stopAudio();
    void pauseAudio();
    void changeSpeed(int);

public Q_SLOTS:
    void baseStart(int file, int type, long nextline, long markposition, int direction);
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
    Ui::BaseMode *ui;

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

};

#endif // BASEMODE_H
