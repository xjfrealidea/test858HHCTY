#include "escmessage.h"
#include "ui_escmessage.h"
#include <QVBoxLayout>

EscMessage::EscMessage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EscMessage)
{
    ui->setupUi(this);

    QVBoxLayout *mainLayout = new QVBoxLayout();

    mainLayout->addStretch(1);
    mainLayout->addWidget(ui->message1,1);
    mainLayout->addWidget(ui->message2,1);
    mainLayout->addWidget(ui->message3,1);
    mainLayout->addWidget(ui->message4,1);
    mainLayout->addWidget(ui->message5,1);
    mainLayout->addStretch(1);
    mainLayout->addWidget(ui->message6,1);
    mainLayout->addStretch(1);

    setLayout(mainLayout);
}

EscMessage::~EscMessage()
{
    delete ui;
}

void EscMessage::keyPressEvent(QKeyEvent *e)
{
    Q_UNUSED(e);
    this->close();
}

void EscMessage::closeEvent(QCloseEvent *e)
{
    Q_UNUSED(e);
    emit menuClose();
}

void EscMessage::mousePressEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    this->close();
}
