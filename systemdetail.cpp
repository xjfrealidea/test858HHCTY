#include "systemdetail.h"
#include <QDebug>

SystemDetail &SystemDetail::instance()
{
    static SystemDetail systemDetail;
    return systemDetail;
}

SystemDetail::SystemDetail(QObject *parent):QObject(parent)
{
    detail.masterVolume = 5;
    detail.wooweeVolume = 5;
    detail.wooweeSensitivity = 5;
    detail.qcVolume = 4;
    detail.qcLevel = 9.999;
    detail.fullScale = 4;
    detail.rdngsScreen = 4;
    detail.cycleTime = 0.1;
}

DETAIL &SystemDetail::getDetail()
{
    return detail;
}

void SystemDetail::changeMasterVolume(short change)
{
    detail.masterVolume = change;
}

void SystemDetail::changeWooweeVolume(short change)
{
    detail.wooweeVolume = change;
}

void SystemDetail::changeWooweeSensitivity(int change)
{
    detail.wooweeSensitivity = change;
}

void SystemDetail::changeQcVolume(int change)
{
    detail.qcVolume = change;
}

void SystemDetail::changeQcLevel(double change)
{
    detail.qcLevel = change;
}

void SystemDetail::changeFullScale(int change)
{
    if (change > 80000)
    {
        change = 80000;
    }
    detail.fullScale = change;

    emit fullScaleChanged();
}

void SystemDetail::changeRdngsScreen(int change)
{
    detail.rdngsScreen = change;
}

void SystemDetail::changeCycleTime(double change)
{
    detail.cycleTime = change;
}

void SystemDetail::setMasterVolume(int value)
{
    SystemDetail::instance().changeMasterVolume(value);
}

void SystemDetail::setWooweeVolume(int value)
{
    SystemDetail::instance().changeWooweeVolume(value);
}

void SystemDetail::setWooweeSensitivity(int value)
{
    SystemDetail::instance().changeWooweeSensitivity(value);
}

void SystemDetail::setQcVolume(int value)
{
    SystemDetail::instance().changeQcVolume(value);
}

void SystemDetail::setQcLevel(double value)
{
    SystemDetail::instance().changeQcLevel(value);
}

void SystemDetail::setFullScale(int value)
{
    SystemDetail::instance().changeFullScale(value);
}

void SystemDetail::setRdngsScreen(int value)
{
    SystemDetail::instance().changeRdngsScreen(value);
}

void SystemDetail::setCycleTime(double value)
{
    SystemDetail::instance().changeCycleTime(value);
}

