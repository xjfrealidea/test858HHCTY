#ifndef AUDIOPOPUPMENU_H
#define AUDIOPOPUPMENU_H
#include <QWidget>
#include "popupmenus.h"

class AudioPopUpMenu : public PopUpMenus
{
    Q_OBJECT

public:
    AudioPopUpMenu(int showTime,QWidget *parent = 0);

    virtual bool upAction();
    virtual bool downAction();
    virtual bool leftAction();
    virtual bool rightAction();

signals:
    void hzChanged(int);
    void volumeChanged(int);

//    virtual void setAudio(AudioOutput *audio);

};

#endif // AUDIOPOPUPMENU_H
