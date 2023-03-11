#include "scrollnumlistlabel.h"
#include "macro.h"

ScrollNumListLabel::ScrollNumListLabel(int len, QVector<double> *text, QWidget *parent) :
    ScrollLabel(len,parent),
    labeltext(text)
{
    setValue(1);
    setFocusPolicy(Qt::StrongFocus);
    //setStyleSheet("ScrollNumLabel:focus{background-color:red;}");

    autoResize();
}

void ScrollNumListLabel::setLabelText(QVector<double> *text)
{
    this->labeltext = text;
}

void ScrollNumListLabel::setValue(int value)
{
    value--;
    if (value >= min && value <= max)
    {
        this->value = value;
        QString text;
        text.clear();
        if (false == lock)
        {
            text += QString::fromLocal8Bit(" <");
            text += QString::number((*(this->labeltext))[this->value]);
            text += QString::fromLocal8Bit("> ");
        }
        else
        {
            text += QString::fromLocal8Bit("  ");
            text += QString::number((*(this->labeltext))[this->value]);
            text += QString::fromLocal8Bit("  ");
        }
        this->setText(text);
        emit textChanged();
    }
}

void ScrollNumListLabel::formatValue(int value)
{
    value--;
    if (value >= min && value <= max)
    {
        this->value = value;
        QString text;
        text.clear();
        if (false == lock)
        {
            text += QString::fromLocal8Bit(" <");
            text += QString::number((*(this->labeltext))[this->value]);
            text += QString::fromLocal8Bit("> ");
        }
        else
        {
            text += QString::fromLocal8Bit("  ");
            text += QString::number((*(this->labeltext))[this->value]);
            text += QString::fromLocal8Bit("  ");
        }
        this->setText(text);
        emit formatChanged();
    }
}

int ScrollNumListLabel::getValue()
{
    return (*(this->labeltext))[this->value];
}

int ScrollNumListLabel::getIndex()
{
    return value+1;
}

void ScrollNumListLabel::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == KEY_LEFT)
    {
        valueDown();
    }
    else if (e->key() == KEY_RIGHT)
    {
        valueUp();
    }
    else
    {
        QWidget::keyPressEvent(e);
    }
}
