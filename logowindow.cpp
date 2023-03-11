#include "logowindow.h"
#include "ui_logowindow.h"

LogoWindow::LogoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogoWindow)
{
    ui->setupUi(this);

    setAutoFillBackground(true);
    state = false;
}

LogoWindow::~LogoWindow()
{
    delete ui;
}

void LogoWindow::timerStart()
{
    timer.start(5);
}

void LogoWindow::timerStop()
{
    timer.stop();
}

void LogoWindow::on_timer_out()
{
    state = true;
}
