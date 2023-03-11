#ifndef SIMPLEEDITMENU_H
#define SIMPLEEDITMENU_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QKeyEvent>
#include <QMouseEvent>

namespace Ui {
class SimpleEditMenu;
}

class SimpleEditMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimpleEditMenu(QWidget *parent = 0);
    ~SimpleEditMenu();
    void goBackToLastPosition();
    void deleteLine();
    void setTextNum();

Q_SIGNALS:
    void menuClose();
    void lineMarkChanged(long,long);

private slots:
    void setLineAndMark(long line, long mark, int *perLineNum);

    void on_lastPositionLabel_clicked();

    void on_deleteLabel_clicked();

    void on_returnLabel_clicked();

protected:
    virtual void closeEvent(QCloseEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);

private:
    Ui::SimpleEditMenu *ui;

    long currentLine;
    long currentMark;
    int *perLineNum;
};

#endif // SIMPLEEDITMENU_H
