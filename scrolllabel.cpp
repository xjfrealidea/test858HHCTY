#include "scrolllabel.h"
#include "macro.h"

ScrollLabel::ScrollLabel(int len, QWidget *parent) :
    QPushButton(parent)
{
    scrollover = false;
    lock = false;

    this->setFlat(true);
//    setStyleSheet("ScrollLabel:focus{background-color:white;border: 1px solid;border-color: black;}"
//                  "ScrollLabel{outline:none;}");
    action1 = NULL;
    action2 = NULL;

    step = 1;
    min = 0;
    max = len-1;

    connect(this,SIGNAL(textChanged()),
            this,SLOT(autoResize()));
    connect(this,SIGNAL(formatChanged()),
            this,SLOT(autoResize()));
}

int ScrollLabel::getValue()
{
    return value;
}

void ScrollLabel::valueUp()
{
    if (value < max)
    {
        value += step;
        if (value > max)
        {
            value = max;
        }
        setValue(value+1);
        execute();
    }
    else if (scrollover)
    {
        value = min;
        setValue(value+1);
        execute();
    }
}

void ScrollLabel::valueDown()
{
    if (value > min)
    {
        value -= step;
        if (value < min)
        {
            value = min;
        }
        setValue(value+1);
        execute();
    }
    else if (scrollover)
    {
        value = max;
        setValue(value+1);
        execute();
    }
}

void ScrollLabel::setScrollOver(bool flag)
{
    scrollover = flag;
}

void ScrollLabel::setSpecialStyle(QString &style)
{
    setStyleSheet(style);
}

void ScrollLabel::setAction(void (*action)(int))
{
    this->action1 = action;
}

void ScrollLabel::setAction(void (*action)(double))
{
    this->action2 = action;
}

void ScrollLabel::execute()
{
    if (NULL != action1)
    {
        (*action1)(value);
    }
    if (NULL != action2)
    {
        (*action2)(value);
    }
}

void ScrollLabel::setlock(bool flag)
{
    lock = flag;
}

void ScrollLabel::autoResize()
{
    resize(15*(this->text().length()-1)+10,this->height());
}


void ScrollLabel::keyPressEvent(QKeyEvent *e)
{

    if (e->key() == KEY_LEFT)
    {
        if (false == lock)
        {
            valueDown();
        }
    }
    else if (e->key() == KEY_RIGHT)
    {
        if (false == lock)
        {
            valueUp();
        }
    }
    else
    {
        QWidget::keyPressEvent(e);
    }

}

void ScrollLabel::mousePressEvent(QMouseEvent *e)
{
    if (e->pos().x() < this->width()/2)
    {
        valueDown();
    }
    else
    {
        valueUp();
    }
}
