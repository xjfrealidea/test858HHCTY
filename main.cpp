#include "mainwindow.h"
#include <QApplication>
#include "widgetshowtype.h"
//#include "gpio.h"
#include "settings.h"
#include <QString>
#include <QCursor>
#include "filedatainfo.h"
#include "datasaver.h"
#include "manualtransfermenu.h"
#include <QFontDatabase>
#include <QTextCodec>
#include <datacollectorfactory.h>
#include <QThread>
#include <logowindow.h>
#include "magnetmenu.h"
#include "mythread.h"

bool audioWork;
bool audioEnable;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//ini.ini配置文件加载
    QString iniFilePathName = QApplication::applicationDirPath() + "/ini.ini";
    Settings::instance().loadFromFile(iniFilePathName);

//字体文件配置
    QString fontName = QApplication::applicationDirPath() + QString("/") + Settings::instance()["Fonts/Name"].toString();
    int fontId = QFontDatabase::addApplicationFont(fontName);
    if (-1 != fontId)
    {
        QString mysh = QFontDatabase::applicationFontFamilies(fontId).at(0);
        QFont font(mysh,10);
        QApplication::setFont(font);
    }

//既存文件信息载入
    FileDataInfo::instance().memorySizeCheck();
    FileDataInfo::instance().fileDataCheck();

//数据采集模块构造 串口采集/文件读取
    int type = Settings::instance()["DataCollect/DataSourceType"].toInt();
    DataCollectorFactory::instance().createDataCollector(type);
    //样式表文件配置
        QString styleSheetName = QApplication::applicationDirPath() + "/gsn.qss";
        QFile file(styleSheetName);
        if(true == file.open(QFile::ReadOnly))
        {
            a.setStyleSheet(QTextStream(&file).readAll());
            file.close();
        }


//Logo
    MainWindow logo;
//    WidgetShow::widgetShow(&logo);
    logo.showFullScreen();
    QCursor::setPos(logo.width(),logo.height());
//    QThread thread;
//    AudioOutput::instance().moveToThread(&thread);
//    thread.start();
//主界面
    MagnetMenu magnet;
    QObject::connect(&logo,SIGNAL(magnetShow()),
                     &magnet,SLOT(magnatShow()));


    audioWork = false;
    audioEnable = false;


//开始 logo倒计时
    logo.timerStart();

    a.exec();
//    thread.quit();

    return 0;

}
