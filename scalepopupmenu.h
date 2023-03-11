#ifndef SCALEPOPUPMENU_H
#define SCALEPOPUPMENU_H
#include "popupmenus.h"
#include <QTimer>

class ScalePopUpMenu : public PopUpMenus
{
public:
    ScalePopUpMenu(int showTime, QWidget *parent = 0);

    virtual bool upAction();
    virtual bool downAction();
    virtual bool leftAction();
    virtual bool rightAction();

    virtual void stepTimerStart();

public slots:
    virtual void timeOut();

private:
    QTimer *timer;
};

#endif // SCALEPOPUPMENU_H
