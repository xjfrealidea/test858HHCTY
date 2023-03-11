/********************************************************************************
** Form generated from reading UI file 'mappedmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPPEDMENU_H
#define UI_MAPPEDMENU_H

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

class Ui_MappedMenu
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QLabel *fileLabel;
    TimeLabel *currentTime;
    QLabel *fileTypeLabel;
    QLabel *fileStatusLabel;

    void setupUi(QMainWindow *MappedMenu)
    {
        if (MappedMenu->objectName().isEmpty())
            MappedMenu->setObjectName(QStringLiteral("MappedMenu"));
        MappedMenu->resize(1024, 576);
        centralwidget = new QWidget(MappedMenu);
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
        MappedMenu->setCentralWidget(centralwidget);

        retranslateUi(MappedMenu);

        QMetaObject::connectSlotsByName(MappedMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MappedMenu)
    {
        MappedMenu->setWindowTitle(QApplication::translate("MappedMenu", "MainWindow", nullptr));
        titleLabel->setText(QApplication::translate("MappedMenu", "GPS\350\260\203\346\237\245:\344\270\273\350\217\234\345\215\225", nullptr));
        fileLabel->setText(QApplication::translate("MappedMenu", "\346\226\207\344\273\266", nullptr));
        currentTime->setText(QApplication::translate("MappedMenu", "1234567890", nullptr));
        fileTypeLabel->setText(QApplication::translate("MappedMenu", "\345\244\207\346\263\250:", nullptr));
        fileStatusLabel->setText(QApplication::translate("MappedMenu", "EMPTY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MappedMenu: public Ui_MappedMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPPEDMENU_H
