/********************************************************************************
** Form generated from reading UI file 'simplemenu.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLEMENU_H
#define UI_SIMPLEMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include "timelabel.h"

QT_BEGIN_NAMESPACE

class Ui_SimpleMenu
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QLabel *fileLabel;
    TimeLabel *currentTime;
    QLabel *fileTypeLabel;
    QLabel *fileStatusLabel;

    void setupUi(QMainWindow *SimpleMenu)
    {
        if (SimpleMenu->objectName().isEmpty())
            SimpleMenu->setObjectName(QStringLiteral("SimpleMenu"));
        SimpleMenu->resize(1024, 576);
        centralwidget = new QWidget(SimpleMenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setGeometry(QRect(340, 70, 181, 31));
        fileLabel = new QLabel(centralwidget);
        fileLabel->setObjectName(QStringLiteral("fileLabel"));
        fileLabel->setGeometry(QRect(220, 130, 51, 31));
        currentTime = new TimeLabel(centralwidget);
        currentTime->setObjectName(QStringLiteral("currentTime"));
        currentTime->setGeometry(QRect(90, 490, 191, 20));
        currentTime->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\351\273\221\344\275\223\";"));
        currentTime->setAlignment(Qt::AlignCenter);
        fileTypeLabel = new QLabel(centralwidget);
        fileTypeLabel->setObjectName(QStringLiteral("fileTypeLabel"));
        fileTypeLabel->setGeometry(QRect(383, 150, 31, 31));
        fileStatusLabel = new QLabel(centralwidget);
        fileStatusLabel->setObjectName(QStringLiteral("fileStatusLabel"));
        fileStatusLabel->setGeometry(QRect(483, 150, 41, 31));
        SimpleMenu->setCentralWidget(centralwidget);

        retranslateUi(SimpleMenu);

        QMetaObject::connectSlotsByName(SimpleMenu);
    } // setupUi

    void retranslateUi(QMainWindow *SimpleMenu)
    {
        SimpleMenu->setWindowTitle(QApplication::translate("SimpleMenu", "MainWindow", nullptr));
        titleLabel->setText(QApplication::translate("SimpleMenu", "\347\256\200\345\215\225\350\260\203\346\237\245:\344\270\273\350\217\234\345\215\225", nullptr));
        fileLabel->setText(QApplication::translate("SimpleMenu", "\346\226\207\344\273\266", nullptr));
        currentTime->setText(QApplication::translate("SimpleMenu", "1234567890", nullptr));
        fileTypeLabel->setText(QApplication::translate("SimpleMenu", "\345\244\207\346\263\250:", nullptr));
        fileStatusLabel->setText(QApplication::translate("SimpleMenu", "EMPTY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SimpleMenu: public Ui_SimpleMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEMENU_H
