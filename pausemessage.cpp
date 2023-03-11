#include "pausemessage.h"
#include "ui_pausemessage.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

PauseMessage::PauseMessage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PauseMessage)
{
    ui->setupUi(this);

    QVBoxLayout *mainLayout = new QVBoxLayout();

    QHBoxLayout *lineData = new QHBoxLayout();
    lineData->addWidget(ui->lineLabel,1,Qt::AlignRight);
    lineData->addWidget(ui->lineDataLabel,1,Qt::AlignLeft);

    QHBoxLayout *markData = new QHBoxLayout();
    markData->addWidget(ui->markLabel,1,Qt::AlignRight);
    markData->addWidget(ui->markDataLabel,1,Qt::AlignLeft);

    mainLayout->addWidget(ui->message1,1,Qt::AlignHCenter);
    mainLayout->addWidget(ui->message2,1,Qt::AlignHCenter);
    mainLayout->addLayout(lineData,1);
    mainLayout->addLayout(markData,1);
    mainLayout->addWidget(ui->message3,1,Qt::AlignHCenter);
    mainLayout->addWidget(ui->message4,1,Qt::AlignHCenter);
    mainLayout->addWidget(ui->message5,1,Qt::AlignHCenter);
    mainLayout->addWidget(ui->message6,1,Qt::AlignHCenter);
    mainLayout->addWidget(ui->message7,1,Qt::AlignHCenter);
    mainLayout->addWidget(ui->message8,1,Qt::AlignHCenter);

    setLayout(mainLayout);
}

PauseMessage::~PauseMessage()
{
    delete ui;
}

void PauseMessage::setLineAndMark(long line, long mark)
{
    ui->lineDataLabel->setText(QString::number(line));
    ui->markDataLabel->setText(QString::number(mark));
}

void PauseMessage::closeEvent(QCloseEvent *e)
{
    Q_UNUSED(e);
    emit menuClose();
}

void PauseMessage::keyPressEvent(QKeyEvent *e)
{
    Q_UNUSED(e);
    this->close();
}

void PauseMessage::mousePressEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    this->close();
}
