#ifndef TRANSFERDIALOG_H
#define TRANSFERDIALOG_H

#include <QDialog>
#include <QTimer>
enum
{
    TRANSFER,
    ERASE,
    FORMAT,
    UPDATE
};
namespace Ui {
class transferDialog;
}

class transferDialog : public QDialog
{
    Q_OBJECT

public:
    explicit transferDialog(QWidget *parent = 0);
    ~transferDialog();

    void timeStart();
    void setMessageType(int type);

Q_SIGNALS:
    void transferComplete();

public slots:
    void onTimeOut(int type);
    void dialogClose();

private:
    Ui::transferDialog *ui;
    QTimer *closeTimer;

    int type;
};

#endif // TRANSFERDIALOG_H
