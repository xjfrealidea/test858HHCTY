/********************************************************************************
** Form generated from reading UI file 'basemenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASEMENU_H
#define UI_BASEMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include "timelabel.h"

QT_BEGIN_NAMESPACE

class Ui_BaseMenu
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QLabel *fileLabel;
    TimeLabel *currentTime;
    QLabel *fileTypeLabel;
    QLabel *fileStatusLabel;

    void setupUi(QMainWindow *BaseMenu)
    {
        if (BaseMenu->objectName().isEmpty())
            BaseMenu->setObjectName(QString::fromUtf8("BaseMenu"));
        BaseMenu->resize(1024, 576);
        centralwidget = new QWidget(BaseMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(340, 70, 181, 31));
        fileLabel = new QLabel(centralwidget);
        fileLabel->setObjectName(QString::fromUtf8("fileLabel"));
        fileLabel->setGeometry(QRect(220, 130, 51, 31));
        currentTime = new TimeLabel(centralwidget);
        currentTime->setObjectName(QString::fromUtf8("currentTime"));
        currentTime->setGeometry(QRect(90, 490, 191, 20));
        currentTime->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\351\273\221\344\275\223\";"));
        currentTime->setAlignment(Qt::AlignCenter);
        fileTypeLabel = new QLabel(centralwidget);
        fileTypeLabel->setObjectName(QString::fromUtf8("fileTypeLabel"));
        fileTypeLabel->setGeometry(QRect(383, 150, 31, 31));
        fileStatusLabel = new QLabel(centralwidget);
        fileStatusLabel->setObjectName(QString::fromUtf8("fileStatusLabel"));
        fileStatusLabel->setGeometry(QRect(483, 150, 41, 31));
        BaseMenu->setCentralWidget(centralwidget);

        retranslateUi(BaseMenu);

        QMetaObject::connectSlotsByName(BaseMenu);
    } // setupUi

    void retranslateUi(QMainWindow *BaseMenu)
    {
        BaseMenu->setWindowTitle(QApplication::translate("BaseMenu", "MainWindow", nullptr));
        titleLabel->setText(QApplication::translate("BaseMenu", "\345\237\272\347\253\231\350\260\203\346\237\245:\344\270\273\350\217\234\345\215\225", nullptr));
        fileLabel->setText(QApplication::translate("BaseMenu", "\346\226\207\344\273\266", nullptr));
        currentTime->setText(QApplication::translate("BaseMenu", "1234567890", nullptr));
        fileTypeLabel->setText(QApplication::translate("BaseMenu", "\345\244\207\346\263\250:", nullptr));
        fileStatusLabel->setText(QApplication::translate("BaseMenu", "EMPTY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BaseMenu: public Ui_BaseMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASEMENU_H
