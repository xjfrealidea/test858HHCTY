#ifndef UNITTIME_H
#define UNITTIME_H

#include <QObject>
#include <QTimer>
#include <QTime>
#include <QDate>

class UnitTime : public QObject
{
    Q_OBJECT
public:

    static UnitTime &instance();
    QString getCurrentTime();
    bool setCurrentTime(int h,int m,int s);
    bool setCurrentDate(int year,int month,int day);

signals:

public slots:
    void changeTime();

private:
    explicit UnitTime(QObject *parent = 0);
    QDate date;
    QTime time;
    QTimer *timer;
};

#endif // UNITTIME_H
