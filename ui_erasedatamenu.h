/********************************************************************************
** Form generated from reading UI file 'erasedatamenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERASEDATAMENU_H
#define UI_ERASEDATAMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "timelabel.h"

QT_BEGIN_NAMESPACE

class Ui_EraseDataMenu
{
public:
    QWidget *centralwidget;
    TimeLabel *currentTime;
    QLabel *titleLabel;
    QLabel *fileTypeLabel;
    QPushButton *deleteButton;
    QLabel *fileLabel;
    QLabel *fileStatusLabel;
    QLabel *transferStatusLabel;

    void setupUi(QMainWindow *EraseDataMenu)
    {
        if (EraseDataMenu->objectName().isEmpty())
            EraseDataMenu->setObjectName(QString::fromUtf8("EraseDataMenu"));
        EraseDataMenu->resize(1024, 576);
        centralwidget = new QWidget(EraseDataMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        currentTime = new TimeLabel(centralwidget);
        currentTime->setObjectName(QString::fromUtf8("currentTime"));
        currentTime->setGeometry(QRect(260, 430, 191, 20));
        currentTime->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\351\273\221\344\275\223\";"));
        currentTime->setAlignment(Qt::AlignCenter);
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(400, 50, 271, 51));
        fileTypeLabel = new QLabel(centralwidget);
        fileTypeLabel->setObjectName(QString::fromUtf8("fileTypeLabel"));
        fileTypeLabel->setGeometry(QRect(530, 140, 31, 31));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(480, 370, 75, 23));
        deleteButton->setFlat(true);
        fileLabel = new QLabel(centralwidget);
        fileLabel->setObjectName(QString::fromUtf8("fileLabel"));
        fileLabel->setGeometry(QRect(367, 120, 51, 31));
        fileStatusLabel = new QLabel(centralwidget);
        fileStatusLabel->setObjectName(QString::fromUtf8("fileStatusLabel"));
        fileStatusLabel->setGeometry(QRect(630, 140, 41, 31));
        transferStatusLabel = new QLabel(centralwidget);
        transferStatusLabel->setObjectName(QString::fromUtf8("transferStatusLabel"));
        transferStatusLabel->setGeometry(QRect(470, 330, 54, 12));
        EraseDataMenu->setCentralWidget(centralwidget);

        retranslateUi(EraseDataMenu);

        QMetaObject::connectSlotsByName(EraseDataMenu);
    } // setupUi

    void retranslateUi(QMainWindow *EraseDataMenu)
    {
        EraseDataMenu->setWindowTitle(QApplication::translate("EraseDataMenu", "MainWindow", nullptr));
        currentTime->setText(QApplication::translate("EraseDataMenu", "1234567890", nullptr));
        titleLabel->setText(QApplication::translate("EraseDataMenu", "ERASE DATA MENU", nullptr));
        fileTypeLabel->setText(QApplication::translate("EraseDataMenu", "\345\244\207\346\263\250:", nullptr));
        deleteButton->setText(QApplication::translate("EraseDataMenu", "DELETE THIS DATA", nullptr));
        fileLabel->setText(QApplication::translate("EraseDataMenu", "File", nullptr));
        fileStatusLabel->setText(QApplication::translate("EraseDataMenu", "EMPTY", nullptr));
        transferStatusLabel->setText(QApplication::translate("EraseDataMenu", "!!! DATA SET NOT TRANSFERRED	!!!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EraseDataMenu: public Ui_EraseDataMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERASEDATAMENU_H
