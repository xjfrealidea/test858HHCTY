/********************************************************************************
** Form generated from reading UI file 'manualtransfermenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUALTRANSFERMENU_H
#define UI_MANUALTRANSFERMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "timelabel.h"

QT_BEGIN_NAMESPACE

class Ui_ManualTransferMenu
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QLabel *fileLabel;
    QLabel *fileStatusLabel;
    QLabel *fileTypeLabel;
    TimeLabel *currentTime;
    QPushButton *startButton;

    void setupUi(QMainWindow *ManualTransferMenu)
    {
        if (ManualTransferMenu->objectName().isEmpty())
            ManualTransferMenu->setObjectName(QString::fromUtf8("ManualTransferMenu"));
        ManualTransferMenu->resize(1024, 576);
        centralwidget = new QWidget(ManualTransferMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(300, 30, 271, 51));
        fileLabel = new QLabel(centralwidget);
        fileLabel->setObjectName(QString::fromUtf8("fileLabel"));
        fileLabel->setGeometry(QRect(267, 100, 51, 31));
        fileStatusLabel = new QLabel(centralwidget);
        fileStatusLabel->setObjectName(QString::fromUtf8("fileStatusLabel"));
        fileStatusLabel->setGeometry(QRect(530, 120, 41, 31));
        fileTypeLabel = new QLabel(centralwidget);
        fileTypeLabel->setObjectName(QString::fromUtf8("fileTypeLabel"));
        fileTypeLabel->setGeometry(QRect(430, 120, 31, 31));
        currentTime = new TimeLabel(centralwidget);
        currentTime->setObjectName(QString::fromUtf8("currentTime"));
        currentTime->setGeometry(QRect(160, 410, 191, 20));
        currentTime->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\351\273\221\344\275\223\";"));
        currentTime->setAlignment(Qt::AlignCenter);
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(380, 350, 75, 23));
        startButton->setFlat(true);
        ManualTransferMenu->setCentralWidget(centralwidget);

        retranslateUi(ManualTransferMenu);

        QMetaObject::connectSlotsByName(ManualTransferMenu);
    } // setupUi

    void retranslateUi(QMainWindow *ManualTransferMenu)
    {
        ManualTransferMenu->setWindowTitle(QApplication::translate("ManualTransferMenu", "MainWindow", nullptr));
        titleLabel->setText(QApplication::translate("ManualTransferMenu", "MANUAL ASCII TRANSFER MENU", nullptr));
        fileLabel->setText(QApplication::translate("ManualTransferMenu", "\346\226\207\344\273\266", nullptr));
        fileStatusLabel->setText(QApplication::translate("ManualTransferMenu", "EMPTY", nullptr));
        fileTypeLabel->setText(QApplication::translate("ManualTransferMenu", "\345\244\207\346\263\250:", nullptr));
        currentTime->setText(QApplication::translate("ManualTransferMenu", "1234567890", nullptr));
        startButton->setText(QApplication::translate("ManualTransferMenu", "START TRANSFER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManualTransferMenu: public Ui_ManualTransferMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUALTRANSFERMENU_H
