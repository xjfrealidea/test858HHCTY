#ifndef POPUPMENUS_H
#define POPUPMENUS_H

#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include "systemdetail.h"
#include "mainfrm.h"
#include "audiooutput.h"

namespace Ui {
class PopUpMenus;
}

class PopUpMenus : public QWidget
{
    Q_OBJECT

public:
    explicit PopUpMenus(int showTime,QWidget *parent = 0);
    ~PopUpMenus();

    void setUi();
    void timerStart();
    int getIndex();
    void setIndex(int index);

    void setAudioType();
    void setScaleType();

    void stepUp();

    virtual bool upAction() {return false;}
    virtual bool downAction() {return false;}
    virtual bool leftAction() {return false;}
    virtual bool rightAction() {return false;}

    virtual void stepTimerStart() {}
//    virtual void setAudio(AudioOutput *audio) {}

    MainFrm *display;
    int step;

public slots:
    void timeOver();
    virtual void timeOut(){}

signals:
    void timeOut(int);

protected:
    QTimer *m_timer;
    int showTime;
    //virtual void keyPressEvent(QKeyEvent *e);

private:
    Ui::PopUpMenus *ui;
    int index;


};

#endif // POPUPMENUS_H
