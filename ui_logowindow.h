/********************************************************************************
** Form generated from reading UI file 'logowindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGOWINDOW_H
#define UI_LOGOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogoWindow
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *LogoWindow)
    {
        if (LogoWindow->objectName().isEmpty())
            LogoWindow->setObjectName(QString::fromUtf8("LogoWindow"));
        LogoWindow->resize(800, 600);
        LogoWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(LogoWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        LogoWindow->setCentralWidget(centralwidget);

        retranslateUi(LogoWindow);

        QMetaObject::connectSlotsByName(LogoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LogoWindow)
    {
        LogoWindow->setWindowTitle(QApplication::translate("LogoWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogoWindow: public Ui_LogoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGOWINDOW_H
