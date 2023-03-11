#include "widgetshowtype.h"
#include <QDebug>


void widgetSize(QWidget *w)
{
    qDebug() << "widget width = " << w->width();
    qDebug() << "widget hieght = " << w->height();
}


bool mouseClickInWidget(QMouseEvent *e, QWidget *w)
{
    return (e->pos().x() >= w->x()
            && e->pos().x() <= (w->x()+w->width())
            && e->pos().y() >= w->y()
            && e->pos().y() <= (w->y()+w->height()));
}

int WidgetShow::m_windowHeight = 0;
int WidgetShow::m_windowWidth = 0;

WidgetShow::WidgetShow(QObject *parent) : QObject(parent)
{

}

void WidgetShow::widgetShow(QWidget *w)
{
//#if FLAG
    w->setGeometry(0,0,800,480);
    w->show();
//#endif
//#if !FLAG
//    w->setGeometry(0,0,m_windowWidth,m_windowHeight);
//    w->showFullScreen();
//#endif
}

void WidgetShow::setWindowSize(int width, int height )
{
    m_windowHeight = height;
    m_windowWidth = width;
}

int &WidgetShow::getWindowHeight()
{
    return m_windowHeight;
}

int &WidgetShow::getWindowWidth()
{
    return m_windowWidth;
}
