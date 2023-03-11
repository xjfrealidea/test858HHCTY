#include "timeedit.h"
#include "macro.h"

timeEdit::timeEdit(QWidget *parent):QDateTimeEdit(parent)
{

}

void timeEdit::keyPressEvent(QKeyEvent *e)
{
    if ((e->key() >= Qt::Key_0 && e->key() <= Qt::Key_9)
            || e->key() == KEY_UP
            || e->key() == KEY_DOWN
            || e->key() == KEY_LEFT
            || e->key() == KEY_RIGHT
            || e->key() == KEY_DEL)
    {
        QDateTimeEdit::keyPressEvent(e);
    }
    else if (e->key() == KEY_ESC)
    {
        emit escPress();
    }
    else if (e->key() == KEY_ENTER)
    {
        emit enterPress();
    }
    else
    {

    }
}
