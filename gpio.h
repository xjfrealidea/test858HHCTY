#ifndef GPIO_H
#define GPIO_H

#include <QString>
#include <QByteArray>
#include <QFile>
#include <QTextStream>
#include <cstdlib>

#define USER_LED 19
#define BUZZER 117

#define USER_GPIO_SPACE_IN 30//PIN24(GPIO1_30)
#define USER_GPIO_PRESS_IN 106//PIN22(GPIO4_10)

#define USER_GPIO_MODULE_OUT 28//PIN23(GPIO1_28)
#define USER_GPIO_VIDEO_OUT 29//PIN23(GPIO1_29)
#define USER_GPIO_REST_OUT 87//PIN23(GPIO3_23)
#define USER_GPIO_LED0_OUT 94//PIN23(GPIO3_30)
#define USER_GPIO_LED1_OUT 95//PIN23(GPIO3_31)
#define USER_GPIO_LED2_OUT 130//PIN23(GPIO5_2)

#define USER_GPIO_SOUND_OUT 80

#define HIGH 1
#define LOW 0

#define IN "in"
#define OUT "out"

void GPIOInit();//Init the GPIOs for CS800480

void setGPIOValue(int gpio,int value);
void setGPIOModel(int gpio,QString model);
int getGPIOValue(int gpio);

#endif // GPIO_H
