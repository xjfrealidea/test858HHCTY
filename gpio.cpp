#include "gpio.h"

void GPIOInit()
{
    //USER_LED
    //setGPIOModel(UESR_LED,OUT);

    //USER_GPIO
    setGPIOModel(USER_GPIO_SOUND_OUT,OUT);

    //Play sound
    setGPIOValue(USER_GPIO_SOUND_OUT,1);

    //Stop
    setGPIOValue(USER_GPIO_SOUND_OUT,0);
}


void setGPIOValue(int gpio, int value)
{
    QString sys = "echo " + QString("%1").arg(value)
            + " > /sys/class/gpio/gpio" + QString("%1").arg(gpio)
            + "/value";
    char *ch;
    QByteArray ba = sys.toLatin1();
    ch = ba.data();
    system(ch);
}


int getGPIOValue(int gpio)
{
    QString filePath = "/sys/class/gpio/gpio"
            + QString("%1").arg(gpio) + "/value";
    QFile f(filePath);
    f.open(QIODevice::ReadWrite);
    QTextStream in(&f);
    QString res = in.readLine();
    f.close();
    return res.toInt();
}


void setGPIOModel(int gpio, QString model)
{
    //"echo 80 > /sys/class/gpio/export"
    QString sys = "echo " + QString("%1").arg(gpio) + " > /sys/class/gpio/export";
    char *ch;
    QByteArray ba = sys.toLatin1();
    ch = ba.data();
    system(ch);

    //"echo \"out\" > /sys/class/gpio/gpio80/direction"
    sys = "echo " + model + " > /sys/class/gpio/gpio" + QString("%1").arg(gpio)
            + "/direction";
    ba = sys.toLatin1();
    ch = ba.data();
    system(ch);
}
