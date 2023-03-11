#ifndef ERASECHECKDIALOG_H
#define ERASECHECKDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class EraseCheckDialog;
}

class EraseCheckDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EraseCheckDialog(QWidget *parent = 0);
    ~EraseCheckDialog();
    void setMessage(QString message);
    void getFocus();

signals:
    void signalYes();
    void signalCancel();

private slots:
    void on_yesButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::EraseCheckDialog *ui;
};

#endif // ERASECHECKDIALOG_H
