#include "simpleeditmenu.h"
#include "ui_simpleeditmenu.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "macro.h"
#include <QDebug>
#include "filedatacache.h"
#include "widgetshowtype.h"

SimpleEditMenu::SimpleEditMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimpleEditMenu)
{
    ui->setupUi(this);

    QGridLayout *mainLayout = new QGridLayout(ui->centralwidget);
    QLabel *space1 = new QLabel(this);
    QLabel *space2 = new QLabel(this);
    QLabel *space3 = new QLabel(this);
    QLabel *space4 = new QLabel(this);
    //ui->lastPositionLabel->setFocusPolicy(Qt::StrongFocus);
    //ui->deleteLabel->setFocusPolicy(Qt::StrongFocus);
    //ui->returnLabel->setFocusPolicy(Qt::StrongFocus);
    setStyleSheet("QPushButton:focus{background-color:red;}"
                  "QPushButton{outline:none;}");

    mainLayout->addWidget(ui->titleLabel,0,1,1,1,Qt::AlignHCenter|Qt::AlignVCenter);
    mainLayout->addWidget(space1,1,0,1,3);
    mainLayout->addWidget(ui->currentPositionLabel,2,1,1,1,Qt::AlignHCenter|Qt::AlignVCenter);

    QHBoxLayout *currentLine = new QHBoxLayout();
    currentLine->addWidget(ui->currentLineLabel,1,Qt::AlignRight);
    currentLine->addWidget(ui->currentLineDataLabel,1,Qt::AlignLeft);
    QHBoxLayout *currentMark = new QHBoxLayout();
    currentMark->addWidget(ui->currentMarkLabel,1,Qt::AlignRight);
    currentMark->addWidget(ui->currentMarkDataLabel,1,Qt::AlignLeft);

    mainLayout->addLayout(currentLine,3,1,1,1,Qt::AlignHCenter|Qt::AlignVCenter);
    mainLayout->addLayout(currentMark,4,1,1,1,Qt::AlignHCenter|Qt::AlignVCenter);
    mainLayout->addWidget(space2,5,0,1,3);

    mainLayout->addWidget(ui->lastPositionLabel,6,1,1,1,Qt::AlignHCenter|Qt::AlignVCenter);
    QHBoxLayout *lastLine = new QHBoxLayout();
    lastLine->addWidget(ui->lastLineLabel,1,Qt::AlignRight);
    lastLine->addWidget(ui->lastLineDataLabel,1,Qt::AlignLeft);
    QHBoxLayout *lastMark = new QHBoxLayout();
    lastMark->addWidget(ui->lastMarkLabel,1,Qt::AlignRight);
    lastMark->addWidget(ui->lastMarkDataLabel,1,Qt::AlignLeft);

    mainLayout->addLayout(lastLine,7,1,1,1,Qt::AlignHCenter|Qt::AlignVCenter);
    mainLayout->addLayout(lastMark,8,1,1,1,Qt::AlignHCenter|Qt::AlignVCenter);
    mainLayout->addWidget(space3,9,0,1,3);

    mainLayout->addWidget(ui->deleteLabel,10,1,1,1,Qt::AlignHCenter|Qt::AlignVCenter);
    QHBoxLayout *deleteLine = new QHBoxLayout();
    deleteLine->addWidget(ui->deleteLineLabel,1,Qt::AlignRight);
    deleteLine->addWidget(ui->deleteLineDataLabel,1,Qt::AlignLeft);

    mainLayout->addLayout(deleteLine,11,1,1,1,Qt::AlignHCenter|Qt::AlignVCenter);
    mainLayout->addWidget(space4,12,0,1,3);
    mainLayout->addWidget(ui->returnLabel,13,1,1,1,Qt::AlignHCenter|Qt::AlignVCenter);
}

SimpleEditMenu::~SimpleEditMenu()
{
    delete ui;
}

void SimpleEditMenu::goBackToLastPosition()
{
    //GO BACK TO LAST POSITION
    FileDataCache::instance().goBackToLastPosition();
    if (currentMark > 0)
    {
        currentMark--;
    }
    else if (currentLine > 0)
    {
        currentLine--;
        currentMark = perLineNum[currentLine];
    }
    setTextNum();
}

void SimpleEditMenu::deleteLine()
{
    //DELETE LINE
    FileDataCache::instance().deleteLine();
    if (currentMark > 0)
    {
        currentMark = 0;
    }
    else if (currentLine > 0)
    {
        currentLine--;
        currentMark = 0;
    }
    setTextNum();
}

void SimpleEditMenu::setTextNum()
{
    ui->currentLineDataLabel->setText(QString::number(currentLine));
    ui->currentMarkDataLabel->setText(QString::number(currentMark));
    if (currentMark > 0)
    {
        ui->lastLineDataLabel->setText(QString::number(currentLine));
        ui->lastMarkDataLabel->setText(QString::number(currentMark - 1));
        ui->deleteLineDataLabel->setText(QString::number(currentLine));
    }
    else if (currentLine > 0)
    {
        ui->lastLineDataLabel->setText(QString::number(currentLine - 1));
        ui->lastMarkDataLabel->setText(QString::number(perLineNum[currentLine - 1]));
        ui->deleteLineDataLabel->setText(QString::number(currentLine - 1));
    }
    else
    {
        ui->lastLineDataLabel->setText(QString::number(currentLine));
        ui->lastMarkDataLabel->setText(QString::number(currentMark));
        ui->deleteLineDataLabel->setText(QString::number(currentLine));
    }
}

void SimpleEditMenu::setLineAndMark(long line, long mark, int *perLineNum)
{
    ui->returnLabel->setFocus();

    this->currentLine = line;
    this->currentMark = mark;
    this->perLineNum = perLineNum;
    setTextNum();
}

void SimpleEditMenu::closeEvent(QCloseEvent *e)
{    
    Q_UNUSED(e);
    emit lineMarkChanged(currentLine,currentMark);
    emit menuClose();
}

void SimpleEditMenu::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == KEY_ESC)
    {
        this->close();
    }
    else if (e->key() == KEY_UP)
    {
        this->focusPreviousChild();
    }
    else if (e->key() == KEY_DOWN)
    {
        this->focusNextChild();
    }
    else  if (e->key() == KEY_ENTER)
    {
        QWidget *focus_w = this->focusWidget();
        if (!focus_w)
        {
            return;
        }
        QPushButton *btn = qobject_cast<QPushButton*>(focus_w);
        if (btn)
        {
            btn->click();
        }
    }
}

void SimpleEditMenu::mousePressEvent(QMouseEvent *e)
{
    if (mouseClickInWidget(e,ui->lastPositionLabel))
    {
        //qDebug() << "GO BACK TO LAST POSITION";
        goBackToLastPosition();
    }
    else if (mouseClickInWidget(e,ui->deleteLabel))
    {
        //qDebug() << "DELETE LINE";
        deleteLine();
    }
    else if (mouseClickInWidget(e,ui->returnLabel))
    {
        this->close();
    }
}

void SimpleEditMenu::on_lastPositionLabel_clicked()
{
    //qDebug() << "GO BACK TO LAST POSITION";
    goBackToLastPosition();
}

void SimpleEditMenu::on_deleteLabel_clicked()
{
    //qDebug() << "DELETE LINE";
    deleteLine();
}

void SimpleEditMenu::on_returnLabel_clicked()
{
    this->close();
}
