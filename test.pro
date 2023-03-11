#-------------------------------------------------
#
# Project created by QtCreator 2018-01-24T14:12:58
#
#-------------------------------------------------

QT       += core gui serialport multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app

CONFIG += c++11

CONFIG   += qwt
DEFINES  += QT_DLL QWT_DLL

LIBS += -L"C:\Qt\Qt5.12.6\5.12.6\mingw73_64\lib" -lqwtd
#LIBS += -L"C:\Qt\Qt5.12.6\5.12.6\mingw73_64\lib" -lqwt
INCLUDEPATH += C:\Qt\Qt5.12.6\5.12.6\mingw73_64\include\qwt


#LIBS += -L/home/shtywx/qwt-6.1.3/lib -lqwt
#INCLUDEPATH += /home/shtywx/qwt-6.1.3/src/

SOURCES += main.cpp\
        mainwindow.cpp \
    timelabel.cpp \
    magnetmenu.cpp \
    unittime.cpp \
    systemsetupmenu.cpp \
    sreachmode.cpp \
    adjustmenu.cpp \
    systemdetail.cpp \
    abstractdatacollector.cpp \
    commdatacollector.cpp \
    dataanalyser.cpp \
    datacache.cpp \
    datacollectorfactory.cpp \
    filedatacollector.cpp \
    gdecode.cpp \
    mainfrm.cpp \
    plot.cpp \
    settings.cpp \
    scrollnumlabel.cpp \
    numentrylabel.cpp \
    Filter.cpp \
    scrolltextlabel.cpp \
    scrolllabel.cpp \
    simplemenu.cpp \
    simplemode.cpp \
    datasaver.cpp \
    simpleeditmenu.cpp \
    filedatacache.cpp \
    pausemessage.cpp \
    popupmenus.cpp \
    audiopopupmenu.cpp \
    scalepopupmenu.cpp \
    escmessage.cpp \
    widgetshowtype.cpp \
    gpio.cpp \
    datatransfermenu.cpp \
    manualtransfermenu.cpp \
    transferdialog.cpp \
    filedatawidget.cpp \
    filedatainfo.cpp \
    simpledownmenuwidget.cpp \
    audiooutput.cpp \
    cachedatasaver.cpp \
    erasedatamenu.cpp \
    erasecheckdialog.cpp \
    memoryformatdialog.cpp \
    rasterdata.cpp \
    spectrogramplot.cpp \
    mappedmenu.cpp \
    mappeddownmenuwidget.cpp \
    definemapmenu.cpp \
    mappedmode.cpp \
    GpsPathPlot.cpp \
    GpsInfoWeight.cpp \
    plotseriesdata.cpp \
    signaldata.cpp \
    logowindow.cpp \
    EndLineMsgWindow.cpp \
    RealTimeMapView.cpp \
    scrollnumlistlabel.cpp \
    timeeditdialog.cpp \
    digitalclock.cpp \
    timeedit.cpp \
    mythread.cpp \
    DownMenuWidget.cpp \
    drawmenu.cpp \
    drawmode.cpp \
    basemenu.cpp \
    basemode.cpp \
    basedownmenuwidget.cpp

HEADERS  += mainwindow.h \
    timelabel.h \
    magnetmenu.h \
    unittime.h \
    systemsetupmenu.h \
    sreachmode.h \
    adjustmenu.h \
    systemdetail.h \
    abstractdatacollector.h \
    commdatacollector.h \
    common.h \
    dataanalyser.h \
    datacache.h \
    datacollectorfactory.h \
    filedatacollector.h \
    gdecode.h \
    mainfrm.h \
    plot.h \
    settings.h \
    scrollnumlabel.h \
    numentrylabel.h \
    macro.h \
    Filter.h \
    scrolltextlabel.h \
    scrolllabel.h \
    simplemenu.h \
    simplemode.h \
    datasaver.h \
    simpleeditmenu.h \
    filedatacache.h \
    pausemessage.h \
    popupmenus.h \
    audiopopupmenu.h \
    scalepopupmenu.h \
    gpio.h \
    escmessage.h \
    widgetshowtype.h \
    datatransfermenu.h \
    manualtransfermenu.h \
    transferdialog.h \
    filedatawidget.h \
    filedatainfo.h \
    simpledownmenuwidget.h \
    audiooutput.h \
    cachedatasaver.h \
    erasedatamenu.h \
    erasecheckdialog.h \
    memoryformatdialog.h \
    rasterdata.h \
    spectrogramplot.h \
    mappedmenu.h \
    mappeddownmenuwidget.h \
    definemapmenu.h \
    mappedmode.h \
    GpsPathPlot.h \
    GpsInfoWeight.h \
    plotseriesdata.h \
    signaldata.h \
    logowindow.h \
    EndLineMsgWindow.h \
    RealTimeMapView.h \
    scrollnumlistlabel.h \
    timeeditdialog.h \
    digitalclock.h \
    timeedit.h \
    mythread.h \
    DownMenuWidget.h \
    drawmenu.h \
    drawmode.h \
    basemenu.h \
    basemode.h \
    basedownmenuwidget.h


FORMS    += mainwindow.ui \
    magnetmenu.ui \
    systemsetupmenu.ui \
    sreachmode.ui \
    adjustmenu.ui \
    simplemenu.ui \
    simplemode.ui \
    simpleeditmenu.ui \
    pausemessage.ui \
    popupmenus.ui \
    escmessage.ui \
    datatransfermenu.ui \
    manualtransfermenu.ui \
    transferdialog.ui \
    filedatawidget.ui \
    simpledownmenuwidget.ui \
    erasedatamenu.ui \
    erasecheckdialog.ui \
    memoryformatdialog.ui \
    spectrogram.ui \
    mappeddownmenuwidget.ui \
    definemapmenu.ui \
    mappedmenu.ui \
    mappedmode.ui \
    GpsInfoWeight.ui \
    logowindow.ui \
    EndLineMsgWindow.ui \
    RealTimeMapView.ui \
    timeeditdialog.ui \
    DownMenuWidget.ui \
    drawmenu.ui \
    drawmode.ui \
    basemenu.ui \
    basemode.ui \
    basedownmenuwidget.ui

RESOURCES += \
    pic.qrc
