#ifndef MANUALTRANSFERMENU_H
#define MANUALTRANSFERMENU_H

#include <QMainWindow>
#include <QStackedWidget>
#include "filedatawidget.h"
#include "scrollnumlabel.h"
#include <QCloseEvent>
#include <QKeyEvent>
#include "transferdialog.h"
//#include "hintdialog.h"

namespace Ui {
class ManualTransferMenu;
}

class ManualTransferMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManualTransferMenu(QWidget *parent = 0);
    ~ManualTransferMenu();



    void transferCacheData();

signals:
    void menuClose();
    void reTransfer(int ,bool );

private slots:
    int changeFileDataWidget();
    void transferMenuStart();

    void on_startButton_clicked();

    void dataTransfer(int index,bool message);
    bool mountDev(int idx);
    bool unmontDev(int idx);
    void checkTransfer(int index, bool message, int idx);

protected:
    virtual void closeEvent(QCloseEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);

private:
    Ui::ManualTransferMenu *ui;

    ScrollNumLabel *fileNumLabel;

    QStackedWidget *filedata;
    FileDataWidget *spaceWidget;
    FileDataWidget *fileDataWidget;

    transferDialog *transferdialog;

};

#endif // MANUALTRANSFERMENU_H
