#include "settings.h"
#include <QSettings>
#include <QFile>
#include <QStringList>
#include <QDebug>
Settings::Settings()
{

}

Settings::~Settings()
{

}

void Settings::loadFromFile(QString iniFilePathName)
{
    if(QFile(iniFilePathName).exists())//判断配置文件路径名字是否存在
    {
        QSettings *settings = new QSettings(iniFilePathName, QSettings::IniFormat);//QSettings::IniFormat 值为1
        QStringList childGroups = settings->childGroups();
        foreach(QString childGroup, childGroups)
        {
            settings->beginGroup(childGroup);
            QStringList childKeys = settings->childKeys();
            foreach(QString childKey, childKeys)
            {
                QString key = childGroup+"/"+childKey;
                m_settings[key] = settings->value(childKey);
            }
            settings->endGroup();
        }
    }
}

QVariant& Settings::operator[](QString keyName)
{
    map<QString, QVariant>::iterator iter = m_settings.find(keyName);
    if(iter != m_settings.end())
    {
        return iter->second;
        // return m_settings[keyName];  // 做了两次查找：除find外，下标访问[]内部也做了1次查找。如果希望找到直接使用就使用iter
    }
    return m_defaultValue;
}
