#ifndef LOGOWINDOW_H
#define LOGOWINDOW_H

#include <QMainWindow>
#include <QTimer>
namespace Ui {
class LogoWindow;
}

class LogoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LogoWindow(QWidget *parent = 0);
    ~LogoWindow();

    bool state;
    void timerStart();
    void timerStop();

public slots:
    void on_timer_out();

private:
    Ui::LogoWindow *ui;

    QTimer timer;
};

#endif // LOGOWINDOW_H
