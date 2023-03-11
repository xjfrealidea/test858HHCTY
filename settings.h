#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <map>
#include <QVariant>
#include "common.h"

using namespace std;

class Settings;

class Settings : public QObject
{
    Q_OBJECT

    SINGLETON(Settings)
public:
    //explicit Settings(QObject *parent = 0);

    void loadFromFile(QString iniFilePathName);

    QVariant& operator[](QString keyName);
    map<QString, QVariant> getSettings() { return m_settings; }

private:
    map<QString, QVariant> m_settings;
    QVariant m_defaultValue;
};

#endif // SETTINGS_H
