#ifndef ENDLINEMESSAGE_H
#define ENDLINEMESSAGE_H

#include <QDialog>

namespace Ui {
class endLineMessage;
}

class endLineMessage : public QDialog
{
    Q_OBJECT

public:
    explicit endLineMessage(QWidget *parent = 0);
    ~endLineMessage();

private:
    Ui::endLineMessage *ui;
};

#endif // ENDLINEMESSAGE_H
