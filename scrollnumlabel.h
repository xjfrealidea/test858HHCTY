#ifndef SCROLLNUMLABEL_H
#define SCROLLNUMLABEL_H

#include <QObject>
#include <QString>
#include "scrolllabel.h"
#include <QTimer>

class ScrollNumLabel : public ScrollLabel
{
    Q_OBJECT
public:
    explicit ScrollNumLabel(int len, QWidget *parent = 0);
    virtual void setValue(int value);
    virtual void formatValue(int value);
    virtual int getValue();

    void setStep(int step);

signals:

public slots:
    void skipTimeOut();

protected:
    virtual void keyPressEvent(QKeyEvent *e);

private:
    QTimer *m_skiptimer;
    bool skipFlag;

};

#endif // SCROLLNUMLABEL_H
