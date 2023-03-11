#ifndef TIMEEDITDIALOG_H
#define TIMEEDITDIALOG_H

#include <QDialog>
#include <QShowEvent>

namespace Ui {
class TimeEditDialog;
}

class TimeEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TimeEditDialog(QWidget *parent = 0);
    ~TimeEditDialog();
    bool timeEdit();

public slots:
    void getFocus();

    void enterPress();
    void escPress();

protected:
    virtual void showEvent(QShowEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::TimeEditDialog *ui;
};

#endif // TIMEEDITDIALOG_H
