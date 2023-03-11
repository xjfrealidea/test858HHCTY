#include "DownMenuWidget.h"
#include "ui_DownMenuWidget.h"

DownMenuWidget::DownMenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DownMenuWidget)
{
    ui->setupUi(this);
}

DownMenuWidget::~DownMenuWidget()
{
    delete ui;
}
