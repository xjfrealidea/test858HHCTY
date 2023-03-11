#ifndef PAUSEMESSAGE_H
#define PAUSEMESSAGE_H

#include <QDialog>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QMouseEvent>

namespace Ui {
class PauseMessage;
}

class PauseMessage : public QDialog
{
    Q_OBJECT

public:
    explicit PauseMessage(QWidget *parent = 0);
    ~PauseMessage();

signals:
    void menuClose();

public Q_SLOTS:
    void setLineAndMark(long line,long mark);

protected:
    virtual void closeEvent(QCloseEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);

private:
    Ui::PauseMessage *ui;
};

#endif // PAUSEMESSAGE_H
