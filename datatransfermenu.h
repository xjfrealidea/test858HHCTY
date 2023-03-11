#ifndef DATATRANSFERMENU_H
#define DATATRANSFERMENU_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QKeyEvent>
#include "transferdialog.h"
#include "manualtransfermenu.h"
#include "erasedatamenu.h"
#include "memoryformatdialog.h"

namespace Ui {
class DataTransferMenu;
}

class DataTransferMenu : public QMainWindow
{
    Q_OBJECT


public:
    explicit DataTransferMenu(QWidget *parent = 0);
    ~DataTransferMenu();

Q_SIGNALS:
    void menuClose();
    void manualtransferStart();
    void erasedataStart();

protected:
    virtual void closeEvent(QCloseEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);

private slots:
    void on_manualTransferButton_clicked();
    void manualtransferClose();

    void on_eraseButton_clicked();
    void erasedataClose();

    void on_formatButton_clicked();
    void checkFormat();
    void cancelFormat();

private:
    Ui::DataTransferMenu *ui;

    transferDialog *d;
    ManualTransferMenu *manualtransfermenu;
    EraseDataMenu *erasedatamenu;
    MemoryFormatDialog *memoryformat;

    EraseCheckDialog *e;
    transferDialog *t;
};

#endif // DATATRANSFERMENU_H
