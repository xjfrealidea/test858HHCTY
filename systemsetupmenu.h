#ifndef SYSTEMSETUPMENU_H
#define SYSTEMSETUPMENU_H

#include <QMainWindow>
#include <QCloseEvent>

namespace Ui {
class SystemSetupMenu;
}

class SystemSetupMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit SystemSetupMenu(QWidget *parent = 0);
    ~SystemSetupMenu();

Q_SIGNALS:
    void menuClose();

protected:
    virtual void closeEvent(QCloseEvent *e);

private:
    Ui::SystemSetupMenu *ui;
};

#endif // SYSTEMSETUPMENU_H
