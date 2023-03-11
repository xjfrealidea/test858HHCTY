#include "erasecheckdialog.h"
#include "ui_erasecheckdialog.h"

EraseCheckDialog::EraseCheckDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EraseCheckDialog)
{
    ui->setupUi(this);

    setStyleSheet("QPushButton{font-size:28px;}"
                  "QPushButton:focus{background-color:red;}"
                  "QPushButton{outline:none;}"
                  "QLabel{font-size:28px;}");

    setWindowModality(Qt::WindowModal);
    setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    setFixedSize(this->width(),this->height());

    ui->yesButton->setText(QString::fromUtf8("确认"));
    ui->cancelButton->setText(QString::fromUtf8("取消"));

    setMessage(QString::fromUtf8("数据将被删除!"));
}

EraseCheckDialog::~EraseCheckDialog()
{
    delete ui;
}

void EraseCheckDialog::setMessage(QString message)
{
    ui->label->setText(message);
}

void EraseCheckDialog::getFocus()
{
    ui->cancelButton->setFocus();
}

void EraseCheckDialog::on_yesButton_clicked()
{
    emit signalYes();
}

void EraseCheckDialog::on_cancelButton_clicked()
{
    emit signalCancel();
}
