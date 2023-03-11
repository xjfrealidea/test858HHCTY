#ifndef DOWNMENUWIDGET_H
#define DOWNMENUWIDGET_H

#include <QWidget>

namespace Ui {
class DownMenuWidget;
}

class DownMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DownMenuWidget(QWidget *parent = 0);
    ~DownMenuWidget();

private:
    Ui::DownMenuWidget *ui;
};

#endif // DOWNMENUWIDGET_H
