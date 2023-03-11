#include "audiopopupmenu.h"
#include "audiooutput.h"

AudioPopUpMenu::AudioPopUpMenu(int showTime, QWidget *parent):
    PopUpMenus(showTime,parent)
{
    connect(this,SIGNAL(hzChanged(int)),
            &(AudioOutput::instance()),SLOT(hzChangedSlot(int)));
    connect(this,SIGNAL(volumeChanged(int)),
            &(AudioOutput::instance()),SLOT(volumeChangedSlot(int)));
}

bool AudioPopUpMenu::upAction()
{
//    emit volumeChanged(1);

    bool ret = AudioOutput::instance().volumeChangedSlot(1);
    if (ret == true)
    {
        short ret1 = SystemDetail::instance().getDetail().masterVolume;
        SystemDetail::instance().setRdngsScreen(ret1+1);
    }
    return true;
}

bool AudioPopUpMenu::downAction()
{
//    emit volumeChanged(-1);

    bool ret = AudioOutput::instance().volumeChangedSlot(-1);
    if (ret == true)
    {
        short ret1 = SystemDetail::instance().getDetail().masterVolume;
        SystemDetail::instance().setRdngsScreen(ret1-1);
    }
    return true;
}

bool AudioPopUpMenu::leftAction()
{
//    emit hzChanged(-2);

    bool ret = AudioOutput::instance().hzChangedSlot(-2);
    if (ret == true)
    {
        short ret1 = SystemDetail::instance().getDetail().wooweeSensitivity;
        SystemDetail::instance().setWooweeSensitivity(ret1-2);
    }
    return true;
}

bool AudioPopUpMenu::rightAction()
{
//    emit hzChanged(2);

    bool ret = AudioOutput::instance().hzChangedSlot(2);
    if (ret == true)
    {
        short ret1 = SystemDetail::instance().getDetail().wooweeSensitivity;
        SystemDetail::instance().setWooweeSensitivity(ret1+2);
    }
    return true;
}
