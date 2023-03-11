#ifndef SREACHMODE_H
#define SREACHMODE_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QCloseEvent>
#include <QKeyEvent>
#include <QStackedWidget>
#include "adjustmenu.h"
#include "dataanalyser.h"
#include "datacollector.h"
#include "settings.h"
#include "datacollectorfactory.h"
#include "mainfrm.h"
#include "audiopopupmenu.h"
#include "scalepopupmenu.h"
#include <QTimer>
#include <QMouseEvent>
#include "audiooutput.h"

namespace Ui {
class SreachMode;
}

class SreachMode : public QMainWindow
{
    Q_OBJECT

public:
    explicit SreachMode(QWidget *parent = 0);
    ~SreachMode();
/*
    void getDetail();
    void setDetail();
*/
    void acquirePause();
    void showPopUpMenu(int index);

    void setAdjustMenu(bool show);

    void setPlotXY();

Q_SIGNALS:
    void menuClose();
    void dataReset();
    void plotChange(int);
    void changeHz(double);
    void startAudio();
    void stopAudio();
    void pauseAudio();
    void changeSpeed(int);

public Q_SLOTS:
    void sreachStart();
    void setFieldLabel(int type, double data1, double data2, double lon, double lat);
    void popUpMenuTimeOut(int index);
    void reStartTimerOn(int index);
    void reStartTimerOff();
    void reStart();
    void setCenterTrace();
    void setFullScale();

protected:
    virtual void closeEvent(QCloseEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);

private:
    Ui::SreachMode *ui;

    AdjustMenu *adjustMenu;
    QHBoxLayout *mainLayout;
    QVBoxLayout *allDataLayout;

    AbstractDataCollector *dataCollector;
    QStackedWidget *mainLayoutRight;
    MainFrm *displayPlot;

    QStackedWidget *popUpMenus;
    PopUpMenus *spaceWidget;
    PopUpMenus *audioPopUpMenu;
    PopUpMenus *scalePopUpMenu;

//    AudioOutput *audiooutput;

    QTimer restartTimer;

    int popUpCurrentIndex;
    int displayPlotIndex;
    int adjustMenuIndex;

    int plotIndex;

    double audiobase1;
    double audiobase2;
    double audiobase3;

    bool testFlag;
    bool pauseFlag;
    bool menuStart;
    bool audiobaseFlag;
};

#endif // SREACHMODE_H
