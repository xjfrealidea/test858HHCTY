#ifndef SCROLLTEXTLABEL_H
#define SCROLLTEXTLABEL_H

#include <QObject>
#include <QVector>
#include <QString>
#include "scrolllabel.h"
#include <QFocusEvent>

class ScrollTextLabel : public ScrollLabel
{
    Q_OBJECT
public:
    explicit ScrollTextLabel(int len, QVector<QString> *text, QWidget *parent = 0);
    void setLabelText(QVector<QString> *text);

    virtual int getValue();

    virtual void setValue(int value);

signals:

public slots:
    virtual void autoResize();

protected:
    virtual void focusInEvent(QFocusEvent *e);

private:
    QVector<QString> *labeltext;
};

#endif // SCROLLTEXTLABEL_H
