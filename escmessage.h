#ifndef ESCMESSAGE_H
#define ESCMESSAGE_H

#include <QDialog>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QMouseEvent>

namespace Ui {
class EscMessage;
}

class EscMessage : public QDialog
{
    Q_OBJECT

public:
    explicit EscMessage(QWidget *parent = 0);
    ~EscMessage();

protected:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void closeEvent(QCloseEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);

signals:
    void menuClose();

private:
    Ui::EscMessage *ui;
};

#endif // ESCMESSAGE_H
