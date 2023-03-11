#ifndef SCROLLNUMLISTLABEL_H
#define SCROLLNUMLISTLABEL_H

#include <QObject>
#include <QString>
#include "scrolllabel.h"
#include <QTimer>

class ScrollNumListLabel : public ScrollLabel
{
    Q_OBJECT
public:
    explicit ScrollNumListLabel(int len, QVector<double> *text, QWidget *parent = 0);
    void setLabelText(QVector<double> *text);

    virtual void setValue(int value);
    virtual void formatValue(int value);
    virtual int getValue();
    int getIndex();

signals:

public slots:

protected:
    virtual void keyPressEvent(QKeyEvent *e);

private:
    QVector<double> *labeltext;

};

#endif // SCROLLNUMLISTLABEL_H
