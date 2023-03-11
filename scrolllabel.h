#ifndef SCROLLLABEL_H
#define SCROLLLABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPushButton>

class ScrollLabel : public QPushButton
{
    Q_OBJECT
public:
    explicit ScrollLabel(int len, QWidget *parent = 0);

    virtual void setValue(int value) = 0;
    virtual void formatValue(int value) {Q_UNUSED(value);}
    virtual int getValue();

    void valueUp();
    void valueDown();

    void setScrollOver(bool flag);
    void setSpecialStyle(QString &style);

    void setAction(void (*action)(int));
    void setAction(void (*action)(double));
    void execute();

    void setlock(bool flag);

signals:
    void textChanged();

    void formatChanged();

public slots:
    virtual void autoResize();

protected:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);


    int value;
    int min;
    int max;
    int step;
    bool scrollover;
    bool lock;

private:
    void (*action1)(int);
    void (*action2)(double);

};

#endif // SCROLLLABEL_H
