#include "systemsetupmenu.h"
#include "ui_systemsetupmenu.h"

SystemSetupMenu::SystemSetupMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SystemSetupMenu)
{
    ui->setupUi(this);
}

SystemSetupMenu::~SystemSetupMenu()
{
    delete ui;
}

void SystemSetupMenu::closeEvent(QCloseEvent *e)
{
    Q_UNUSED(e);
    emit menuClose();
}
