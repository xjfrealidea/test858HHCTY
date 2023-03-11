#ifndef MEMORYFORMATDIALOG_H
#define MEMORYFORMATDIALOG_H

#include <QDialog>
#include <QKeyEvent>

namespace Ui {
class MemoryFormatDialog;
}

class MemoryFormatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MemoryFormatDialog(QWidget *parent = 0);
    ~MemoryFormatDialog();
    void resetPressCount();

protected:
    virtual void keyPressEvent(QKeyEvent *e);

signals:
    void memoryFormat();

private:
    Ui::MemoryFormatDialog *ui;

    int pressCount;
};

#endif // MEMORYFORMATDIALOG_H
