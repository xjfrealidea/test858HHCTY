#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QDebug>
#include "macro.h"
#include "widgetshowtype.h"
#include "datacollectorfactory.h"
#include "digitalclock.h"
#include <qdebug.h>
#include <QTextCodec>
#include <QPainter>
#include <QPixmap>
#include "settings.h"
#include "datacollectorfactory.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),
            this,SLOT(onTimerOut()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerStart()
{
    timer->start(5000);
}

void MainWindow::onTimerOut()
{
    timer->stop();
    emit magnetShow();
    this->hide();
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/src/logo.jpg"));
    e->ignore();

    WidgetShow::setWindowSize(this->width(),this->height());
}


void MainWindow::keyPressEvent(QKeyEvent *e)
{

}
