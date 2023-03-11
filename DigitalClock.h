#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QLCDNumber>
#include <QString>
#include "macro.h"

//! [0]
class DigitalClock : public QLCDNumber
{
    Q_OBJECT

public:
    DigitalClock(QWidget *parent = 0);

    QString getCurrentTime();

    void flashTime() {showTime();}

protected:
    virtual void keyPressEvent(QKeyEvent *event);

signals:
    void enterPress();
    void focusOut(int);

private slots:
    void showTime();
};
//! [0]

#endif
