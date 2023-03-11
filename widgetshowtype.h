#ifndef WIDGETSHOWTYPE_H
#define WIDGETSHOWTYPE_H
#include <QWidget>
#include <QMouseEvent>
#define FLAG 0


void setWindowSize(int w, int h);

void widgetShow(QWidget *w);

void widgetSize(QWidget *w);

bool mouseClickInWidget(QMouseEvent *e,QWidget *w);


class WidgetShow : public QObject
{
    Q_OBJECT
public:
    static void widgetShow(QWidget *w);
    //void widgetShow(QWidget *w);
    static void setWindowSize(int width, int height);
    static int &getWindowHeight();
    static int &getWindowWidth();

signals:

public slots:

private:
    explicit WidgetShow(QObject *parent = 0);

    static int m_windowHeight;
    static int m_windowWidth;
};

#endif // WIDGETSHOWTYPE_H
