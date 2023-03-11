#ifndef NUMENTRYLABEL_H
#define NUMENTRYLABEL_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QFocusEvent>
#include <QKeyEvent>

class NumEntryLabel : public QWidget
{
    Q_OBJECT
public:
    explicit NumEntryLabel(double value, double min, double max, QWidget *parent = 0);
    void setValue(double value);
    double getValue();
    void setSize(int w,int h);

    void setAction(void (*action)(int));
    void setAction(void (*action)(double));
    void execute();

signals:
    void valueChanged();

public slots:

protected:
    virtual void focusInEvent(QFocusEvent * event);
    virtual void focusOutEvent(QFocusEvent * event);
    virtual void keyPressEvent(QKeyEvent *event);

private:
    QLineEdit lineedit;
    QLabel label1,label2;
    double value;
    double min;
    double max;
    bool flag;

    double lastValue;
    void (*action1)(int);
    void (*action2)(double);
};

#endif // NUMENTRYLABEL_H
