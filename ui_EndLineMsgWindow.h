/********************************************************************************
** Form generated from reading UI file 'EndLineMsgWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDLINEMSGWINDOW_H
#define UI_ENDLINEMSGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EndLineMsgWindow
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *EndLineMsgWindow)
    {
        if (EndLineMsgWindow->objectName().isEmpty())
            EndLineMsgWindow->setObjectName(QString::fromUtf8("EndLineMsgWindow"));
        EndLineMsgWindow->resize(800, 600);
        centralwidget = new QWidget(EndLineMsgWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        EndLineMsgWindow->setCentralWidget(centralwidget);

        retranslateUi(EndLineMsgWindow);

        QMetaObject::connectSlotsByName(EndLineMsgWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EndLineMsgWindow)
    {
        EndLineMsgWindow->setWindowTitle(QApplication::translate("EndLineMsgWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EndLineMsgWindow: public Ui_EndLineMsgWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDLINEMSGWINDOW_H
