#include "scrolltextlabel.h"
#include <QDebug>

ScrollTextLabel::ScrollTextLabel(int len,  QVector<QString> *text, QWidget *parent) :
    ScrollLabel(len,parent),
    labeltext(text)
{
    setValue(1);
    setFocusPolicy(Qt::StrongFocus);
    //setStyleSheet("ScrollTextLabel{outline:none;}");
}

void ScrollTextLabel::setLabelText(QVector<QString> *text)
{
    this->labeltext = text;
}

int ScrollTextLabel::getValue()
{
    return (value+1);
}

void ScrollTextLabel::setValue(int value)
{
    value--;
    this->value = value;
    QString text;
    text.clear();
    if (false == lock)
    {
        text += QString::fromLocal8Bit(" <");
        text += (*(this->labeltext))[this->value];
        text += QString::fromLocal8Bit("> ");
    }
    else
    {
        text += QString::fromLocal8Bit("  ");
        text += (*(this->labeltext))[this->value];
        text += QString::fromLocal8Bit("  ");
    }

    this->setText(text);
    emit textChanged();
}

void ScrollTextLabel::autoResize()
{
    resize(15*this->text().length()+35,this->height());
    //qDebug() << "resize";
}

void ScrollTextLabel::focusInEvent(QFocusEvent *e)
{
    Q_UNUSED(e);
//    setStyleSheet("ScrollTextLabel:focus{border: 1px solid;border-color:black;background:white;}");
    setStyleSheet("ScrollTextLabel:focus{"
                  "border:2px solid ;"
                  "border-color:black;"
                  "color:rgb(255,255,255);"
                  "background-color:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 rgb(70,70,70),stop:1 rgb(110,110,110));}");
    this->autoResize();
    //qDebug() << "focus in";
}
