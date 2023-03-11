#include "endlinemessage.h"
#include "ui_endlinemessage.h"

endLineMessage::endLineMessage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::endLineMessage)
{
    ui->setupUi(this);
}

endLineMessage::~endLineMessage()
{
    delete ui;
}
