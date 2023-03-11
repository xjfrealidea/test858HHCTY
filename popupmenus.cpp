#include "popupmenus.h"
#include "ui_popupmenus.h"

PopUpMenus::PopUpMenus(int showTime, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PopUpMenus)
{

    this->showTime = showTime;
    m_timer = new QTimer(this);
    connect(m_timer,SIGNAL(timeout()),
            this,SLOT(timeOver()));
    setStyleSheet("QLabel{font-size:18px;}");

    display = NULL;
    step = 1;
}

PopUpMenus::~PopUpMenus()
{
    delete ui;
}

void PopUpMenus::setUi()
{
    ui->setupUi(this);
}

void PopUpMenus::timerStart()
{
    m_timer->start(showTime);
}

int PopUpMenus::getIndex()
{
    return index;
}

void PopUpMenus::setIndex(int index)
{
    this->index = index;
}

void PopUpMenus::setScaleType()
{
    ui->typeLabel->setText("S");
}

void PopUpMenus::setAudioType()
{
    ui->typeLabel->setText("A");
}

void PopUpMenus::stepUp()
{
    step+=1;
}

void PopUpMenus::timeOver()
{
    m_timer->stop();
    emit timeOut(index);
    //qDebug() << "popupmenu emit timeout";
}
/*
void PopUpMenus::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Up)
    {
        upAction();
    }
    else if (e->key() == Qt::Key_Down)
    {
        downAction();
    }
    else if (e->key() == Qt::Key_Left)
    {
        leftAction();
    }
    else if (e->key() == Qt::Key_Right)
    {
        rightAction();
    }
}
*/
