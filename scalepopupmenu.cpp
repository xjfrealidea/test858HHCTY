#include "scalepopupmenu.h"
#include "systemdetail.h"

ScalePopUpMenu::ScalePopUpMenu(int showTime,QWidget *parent):
    PopUpMenus(showTime,parent)
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),
            this,SLOT(timeOut()));
}

void ScalePopUpMenu::stepTimerStart()
{
    timer->start(1000);
}

void ScalePopUpMenu::timeOut()
{
    step = 1;
}

bool ScalePopUpMenu::rightAction()
{
    if (display != NULL)
    {
        bool ret = display->setZoomXUp();

        if (ret == true)
        {
            short ret1 = SystemDetail::instance().getDetail().rdngsScreen;
            SystemDetail::instance().setRdngsScreen(ret1+1);
        }
    }
    return true;
}

bool ScalePopUpMenu::leftAction()
{
    if (display != NULL)
    {
        bool ret = display->setZoomXDown();

        if (ret == true)
        {
            short ret1 = SystemDetail::instance().getDetail().rdngsScreen;
            SystemDetail::instance().setRdngsScreen(ret1-1);
        }
    }
    return true;
}

bool ScalePopUpMenu::downAction()
{
    if (display != NULL)
    {
        bool ret = display->setZoomYDown();

        if (ret == true)
        {
            short ret1 = SystemDetail::instance().getDetail().fullScale;
            SystemDetail::instance().setFullScale(ret1-1);
        }
    }
    return true;
}

bool ScalePopUpMenu::upAction()
{
    if (display != NULL)
    {
        bool ret = display->setZoomYUp();

        if (ret == true)
        {
            short ret1 = SystemDetail::instance().getDetail().fullScale;
            SystemDetail::instance().setFullScale(ret1+1);
        }
    }
    return true;
}
