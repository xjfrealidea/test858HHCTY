#ifndef ERASEDATAMENU_H
#define ERASEDATAMENU_H

#include <QMainWindow>
#include <QStackedWidget>
#include "filedatawidget.h"
#include "scrollnumlabel.h"
#include <QCloseEvent>
#include <QKeyEvent>
#include "erasecheckdialog.h"
#include "transferdialog.h"

namespace Ui {
class EraseDataMenu;
}

class EraseDataMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit EraseDataMenu(QWidget *parent = 0);
    ~EraseDataMenu();

    void dataErase(int index);

signals:
    void menuClose();

private slots:
    void changeFileDataWidget();
    void eraseMenuStart();

    void on_deleteButton_clicked();

    void checkDelete();
    void cancelDelete();

protected:
    virtual void closeEvent(QCloseEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);

private:
    Ui::EraseDataMenu *ui;

    ScrollNumLabel *fileNumLabel;

    QStackedWidget *filedata;
    FileDataWidget *spaceWidget;
    FileDataWidget *fileDataWidget;

    EraseCheckDialog *e;
    transferDialog *t;
};

#endif // ERASEDATAMENU_H
