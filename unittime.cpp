#include "unittime.h"
#include <cstdio>

UnitTime &UnitTime::instance()
{
    static UnitTime unitTime;
    return unitTime;
}

QString UnitTime::getCurrentTime()
{
    char str[21] = "";
//    QString tmp  = "2018-01-29 10:30:22";
    sprintf(str,"%02d:%02d:%02d    %02d/%02d/%02d",
            time.hour(),time.minute(),time.second(),
            date.month(),date.day(),date.year() % 100);


    return QString::fromLocal8Bit(str);
}

bool UnitTime::setCurrentTime(int h, int m, int s)
{
    return time.setHMS(h,m,s);
}

bool UnitTime::setCurrentDate(int year, int month, int day)
{
    return date.setDate(year,month,day);
}

void UnitTime::changeTime()
{
    time = time.addSecs(1);
    if (time.hour() == 0
            && time.minute() == 0
            && time.second() == 0)
    {
        date = date.addDays(1);
    }
}

UnitTime::UnitTime(QObject *parent) :
    QObject(parent)
{
    date = QDate::currentDate();
    time = QTime::currentTime();
    timer = new QTimer();
    timer->start(1000);
    connect(timer,SIGNAL(timeout()),
            this,SLOT(changeTime()));
}

