#ifndef DEFINEMAPMENU_H
#define DEFINEMAPMENU_H

#include <QMainWindow>
#include "scrolltextlabel.h"
#include "numentrylabel.h"
#include "macro.h"

#define BI_DIRECTIONAL 1
#define UNI_DIRECTIONAL 2

#define Y_AXIS 1
#define X_AXIS 2

namespace Ui {
class DefineMapMenu;
}

class DefineMapMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit DefineMapMenu(QWidget *parent = 0);
    ~DefineMapMenu();

    void format();
    int getDirectionMode();
    int getParallelAxis();
    double getLLxData();
    double getLLyData();
    double getURxData();
    double getURyData();
    double getSpaceLineData();
    double getSpaceMarkData();

    void setText();

Q_SIGNALS:
    void menuClose();

protected:
    void closeEvent(QCloseEvent *e);
    void keyPressEvent(QKeyEvent *e);

private slots:
    void on_doneEnteringInfoButton_clicked();

public slots:
    void defineMenuShow();

private:
    Ui::DefineMapMenu *ui;

    ScrollTextLabel *directionModeLabel;
    ScrollTextLabel *parallelAxisLabel;
    NumEntryLabel *LLxDataLabel;
    NumEntryLabel *LLyDataLabel;
    NumEntryLabel *URxDataLabel;
    NumEntryLabel *URyDataLabel;
    NumEntryLabel *spaceLineDataLabel;
    NumEntryLabel *spaceMarkDataLabel;

    bool update;
};

#endif // DEFINEMAPMENU_H
