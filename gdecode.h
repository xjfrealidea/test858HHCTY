#ifndef GDECODE_H
#define GDECODE_H



#include <QObject>

class GDeCode : public QObject
{
    Q_OBJECT
public:
    explicit GDeCode(QObject *parent = 0);
    int hextodec(char c);
    double funDeCode(char *code, unsigned char *len);
signals:

public slots:

};

#endif // GDECODE_H
