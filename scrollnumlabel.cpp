#include "scrollnumlabel.h"
#include "macro.h"

ScrollNumLabel::ScrollNumLabel(int len, QWidget *parent) :
    ScrollLabel(len,parent)
{
    setValue(1);
    setFocusPolicy(Qt::StrongFocus);
    //setStyleSheet("ScrollNumLabel:focus{background-color:red;}");
    if ((int)(len) / 10 > 1 )
    {
        step = (int)(len) / 10;
        if (step>500)
        {
            step = 500;
        }
    }

    m_skiptimer = new QTimer();
    connect(m_skiptimer,SIGNAL(timeout()),
            this,SLOT(skipTimeOut()));
    skipFlag = false;
}

void ScrollNumLabel::setValue(int value)
{
    value--;
    if (value >= min && value <=max)
    {
        this->value = value;
        QString text;
        text.clear();
        if (false == lock)
        {
            text += QString::fromLocal8Bit(" <");
            text += QString::number(value+1);
            text += QString::fromLocal8Bit("> ");
        }
        else
        {
            text += QString::fromLocal8Bit("  ");
            text += QString::number(value+1);
            text += QString::fromLocal8Bit("  ");
        }
        setText(text);
        emit textChanged();
    }
}

void ScrollNumLabel::formatValue(int value)
{
    value--;
    if (value >= min && value <=max)
    {
        this->value = value;
        QString text;
        text.clear();
        if (false == lock)
        {
            text += QString::fromLocal8Bit(" <");
            text += QString::number(value+1);
            text += QString::fromLocal8Bit("> ");
        }
        else
        {
            text += QString::fromLocal8Bit("  ");
            text += QString::number(value+1);
            text += QString::fromLocal8Bit("  ");
        }
        setText(text);
        emit formatChanged();
    }
}

int ScrollNumLabel::getValue()
{
    return (value+1);
}

void ScrollNumLabel::setStep(int step)
{
    this->step = step;
}

void ScrollNumLabel::skipTimeOut()
{
    skipFlag = false;
}

void ScrollNumLabel::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == KEY_LEFT)
    {
        valueDown();
    }
    else if (e->key() == KEY_RIGHT)
    {
        valueUp();
    }
    else if (e->key() >= Qt::Key_0 && e->key() <= Qt::Key_9)
    {
        if (false == skipFlag)
        {
            skipFlag = true;
            m_skiptimer->start(2000);
            setValue((int)(e->key() - Qt::Key_0));
        }
        else if (true == skipFlag)
        {
            int value = getValue();
            setValue(value*10+(int)(e->key() - Qt::Key_0));
        }
    }
    else
    {
        QWidget::keyPressEvent(e);
    }
}
