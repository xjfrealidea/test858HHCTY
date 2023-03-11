#include "timelabel.h"
#include "unittime.h"

TimeLabel::TimeLabel(QWidget *parent) :
    QLabel(parent)
{
    setCurrentTime();
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),
            this,SLOT(setCurrentTime()));
            timer->start(1000);
}

void TimeLabel::setCurrentTime()
{
    QString timeStr = UnitTime::instance().getCurrentTime();
    setText(timeStr);
}

