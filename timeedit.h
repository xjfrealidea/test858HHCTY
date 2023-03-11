#ifndef TIMEEDIT_H
#define TIMEEDIT_H
#include <QDateTimeEdit>
#include <QKeyEvent>

class timeEdit : public QDateTimeEdit
{
    Q_OBJECT
public:
    explicit timeEdit(QWidget *parent = 0);

protected:
    virtual void keyPressEvent(QKeyEvent *e);

signals:
    void enterPress();
    void escPress();
};

#endif // TIMEEDIT_H
