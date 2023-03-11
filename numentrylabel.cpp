#include "numentrylabel.h"
#include <QHBoxLayout>
#include "macro.h"

NumEntryLabel::NumEntryLabel(double value, double min, double max, QWidget *parent) :
    QWidget(parent),
    value(value),
    min(min),
    max(max)

{
    this->setFocusPolicy(Qt::StrongFocus);

    QHBoxLayout *layout = new QHBoxLayout(this);
    label1.setText(QString::fromLocal8Bit("["));
    label1.setStyleSheet("background-color: qlineargradient(stop:0 rgb(186,237,254),stop:1 rgb(121,220,253))");
//    label1.setStyleSheet("background-color: rgb(0,191,255)");
    label1.resize(20,31);
    label1.move(label1.x(),0);
    label2.setText(QString::fromLocal8Bit("]"));
    label2.setStyleSheet("background-color: qlineargradient(stop:0 rgb(186,237,254),stop:1 rgb(121,220,253))");
//    label2.setStyleSheet("background-color: rgb(0,191,255)");
    label2.resize(20,31);
    label2.move(this->width()-label2.width(),0);
    lineedit.setStyleSheet("QLineEdit{font-size:28px;}"
                           "QLineEdit{border:5px;}");

    lineedit.setFocusPolicy(Qt::NoFocus);
    //lineedit.resize(100,40);
//    layout->addStretch(1);
    layout->addWidget(&label1);
    layout->addWidget(&lineedit);
    layout->addWidget(&label2);
    //layout->addStretch(1);
 //   layout->setContentsMargins(this->width()/6,0,this->width()/6,0);

    setValue(value);
    flag = true;
//    this->resize(200,40);
    action1 = NULL;
    action2 = NULL;

    this->resize(210,50);
}

void NumEntryLabel::setValue(double value)
{
    this->value = value;
    lineedit.setText(QString::number(this->value));
}

double NumEntryLabel::getValue()
{
    return value;
}

void NumEntryLabel::setSize(int w, int h)
{
    this->resize(w,h);
}

void NumEntryLabel::setAction(void (*action)(int))
{
    this->action1 = action;
}

void NumEntryLabel::setAction(void (*action)(double))
{
    this->action2 = action;
}

void NumEntryLabel::execute()
{
    if (NULL != action1)
    {
        (*action1)(value);
        emit valueChanged();
    }
    if (NULL != action2)
    {
        (*action2)(value);
        emit valueChanged();
    }
}

void NumEntryLabel::focusInEvent(QFocusEvent *event)
{
    setStyleSheet(QStringLiteral("QLineEdit{color:rgb(255,255,255);"
                                 "background-color:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 rgb(70,70,70),stop:1 rgb(110,110,110));}"));

    lineedit.setStyleSheet("QLineEdit{font-size:28px;}"
                           "QLineEdit{border: 5px;}");

    QWidget::focusInEvent(event);
    this->resize(210,50);
}

void NumEntryLabel::focusOutEvent(QFocusEvent *event)
{
    setStyleSheet(QStringLiteral("background-color:qlineargradient(stop:0 rgb(186,237,254),stop:1 rgb(121,220,253))"));
//    setStyleSheet(QStringLiteral("background-color: rgb(0,191,255)"));
    lineedit.setStyleSheet("QLineEdit{font-size:28px;}"
                           "QLineEdit{border:5px;}");

    QWidget::focusInEvent(event);
}

void NumEntryLabel::keyPressEvent(QKeyEvent *event)
{
    if (flag)
    {
        if (event->key() == KEY_DEL)
        {
            lineedit.setFocus();
            lineedit.setText("");
            lastValue = value;
            flag = false;
        }
        else
        {
            QWidget::keyPressEvent(event);
        }
    }
    else
    {
        if (event->key() == KEY_ENTER)
        {
            this->setFocus();
            flag = true;
            value = this->lineedit.text().toDouble();
            if (value < min || value > max)
            {
                value = lastValue;
                setValue(value);
            }
            else if (value != lastValue)
            {
                execute();
            }
        }
        else
        {
            //QLineEdit:keyPressEvent(event);
        }
    }
}
