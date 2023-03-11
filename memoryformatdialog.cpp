#include "memoryformatdialog.h"
#include "ui_memoryformatdialog.h"
#include <QVBoxLayout>
#include "macro.h"

MemoryFormatDialog::MemoryFormatDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MemoryFormatDialog)
{
    ui->setupUi(this);

    QVBoxLayout *mainLayout = new QVBoxLayout();

    mainLayout->addStretch(1);
    mainLayout->addWidget(ui->message1,1);
    mainLayout->addWidget(ui->message2,1);
    mainLayout->addStretch(1);
    mainLayout->addWidget(ui->message3,1);
    mainLayout->addWidget(ui->message4,1);
    mainLayout->addStretch(1);
    mainLayout->addWidget(ui->message5,1);
    mainLayout->addStretch(1);
    mainLayout->addStretch(1);
    mainLayout->addWidget(ui->message6,1);
    mainLayout->addStretch(1);

    setLayout(mainLayout);

    resetPressCount();
}

MemoryFormatDialog::~MemoryFormatDialog()
{
    delete ui;
}

void MemoryFormatDialog::resetPressCount()
{
    pressCount = 0;
}

void MemoryFormatDialog::keyPressEvent(QKeyEvent *e)
{
    if (pressCount == 0)
    {
        if (e->key() == KEY_DEL)
        {
            pressCount++;
        }
        else
        {
            this->close();
        }
    }
    else if (pressCount == 1)
    {
        if (e->key() == KEY_ENTER)
        {
            emit memoryFormat();
        }
        this->close();
    }
}
