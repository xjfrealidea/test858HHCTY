/********************************************************************************
** Form generated from reading UI file 'systemsetupmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMSETUPMENU_H
#define UI_SYSTEMSETUPMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemSetupMenu
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;

    void setupUi(QMainWindow *SystemSetupMenu)
    {
        if (SystemSetupMenu->objectName().isEmpty())
            SystemSetupMenu->setObjectName(QStringLiteral("SystemSetupMenu"));
        SystemSetupMenu->resize(600, 400);
        centralwidget = new QWidget(SystemSetupMenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setGeometry(QRect(153, 0, 94, 12));
        SystemSetupMenu->setCentralWidget(centralwidget);

        retranslateUi(SystemSetupMenu);

        QMetaObject::connectSlotsByName(SystemSetupMenu);
    } // setupUi

    void retranslateUi(QMainWindow *SystemSetupMenu)
    {
        SystemSetupMenu->setWindowTitle(QApplication::translate("SystemSetupMenu", "MainWindow", nullptr));
        titleLabel->setText(QApplication::translate("SystemSetupMenu", "systemsetupmenu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemSetupMenu: public Ui_SystemSetupMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMSETUPMENU_H
