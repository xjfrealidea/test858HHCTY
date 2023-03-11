/********************************************************************************
** Form generated from reading UI file 'datatransfermenu.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATATRANSFERMENU_H
#define UI_DATATRANSFERMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "timelabel.h"

QT_BEGIN_NAMESPACE

class Ui_DataTransferMenu
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QPushButton *pcTransferButton;
    QPushButton *manualTransferButton;
    QPushButton *eraseButton;
    QPushButton *formatButton;
    QPushButton *sendButton;
    QPushButton *receiveButton;
    TimeLabel *currentTime;
    QLabel *spaceLabel1;
    QLabel *spaceLabel2;

    void setupUi(QMainWindow *DataTransferMenu)
    {
        if (DataTransferMenu->objectName().isEmpty())
            DataTransferMenu->setObjectName(QStringLiteral("DataTransferMenu"));
        DataTransferMenu->resize(1024, 576);
        centralwidget = new QWidget(DataTransferMenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setGeometry(QRect(350, 50, 371, 71));
        titleLabel->setAlignment(Qt::AlignCenter);
        pcTransferButton = new QPushButton(centralwidget);
        pcTransferButton->setObjectName(QStringLiteral("pcTransferButton"));
        pcTransferButton->setGeometry(QRect(440, 160, 75, 23));
        manualTransferButton = new QPushButton(centralwidget);
        manualTransferButton->setObjectName(QStringLiteral("manualTransferButton"));
        manualTransferButton->setGeometry(QRect(440, 200, 75, 23));
        eraseButton = new QPushButton(centralwidget);
        eraseButton->setObjectName(QStringLiteral("eraseButton"));
        eraseButton->setGeometry(QRect(440, 240, 75, 23));
        formatButton = new QPushButton(centralwidget);
        formatButton->setObjectName(QStringLiteral("formatButton"));
        formatButton->setGeometry(QRect(440, 280, 75, 23));
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(440, 350, 75, 23));
        receiveButton = new QPushButton(centralwidget);
        receiveButton->setObjectName(QStringLiteral("receiveButton"));
        receiveButton->setGeometry(QRect(440, 380, 75, 23));
        currentTime = new TimeLabel(centralwidget);
        currentTime->setObjectName(QStringLiteral("currentTime"));
        currentTime->setGeometry(QRect(200, 470, 191, 20));
        currentTime->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\351\273\221\344\275\223\";"));
        currentTime->setAlignment(Qt::AlignCenter);
        spaceLabel1 = new QLabel(centralwidget);
        spaceLabel1->setObjectName(QStringLiteral("spaceLabel1"));
        spaceLabel1->setGeometry(QRect(440, 120, 54, 12));
        spaceLabel2 = new QLabel(centralwidget);
        spaceLabel2->setObjectName(QStringLiteral("spaceLabel2"));
        spaceLabel2->setGeometry(QRect(450, 320, 54, 12));
        DataTransferMenu->setCentralWidget(centralwidget);

        retranslateUi(DataTransferMenu);

        QMetaObject::connectSlotsByName(DataTransferMenu);
    } // setupUi

    void retranslateUi(QMainWindow *DataTransferMenu)
    {
        DataTransferMenu->setWindowTitle(QApplication::translate("DataTransferMenu", "MainWindow", nullptr));
        titleLabel->setText(QApplication::translate("DataTransferMenu", "DATA TRANSFER MENU", nullptr));
        pcTransferButton->setText(QApplication::translate("DataTransferMenu", "PC CONTROLLED TRANSFER ", nullptr));
        manualTransferButton->setText(QApplication::translate("DataTransferMenu", "\346\211\213\345\212\250\346\225\260\346\215\256\345\257\274\345\207\272", nullptr));
        eraseButton->setText(QApplication::translate("DataTransferMenu", "\345\210\240\351\231\244\346\225\260\346\215\256", nullptr));
        formatButton->setText(QApplication::translate("DataTransferMenu", "!!! \345\206\205\345\255\230\345\210\235\345\247\213\345\214\226 !!!", nullptr));
        sendButton->setText(QApplication::translate("DataTransferMenu", "SEND SET UP", nullptr));
        receiveButton->setText(QApplication::translate("DataTransferMenu", "RECEIVE SET UP", nullptr));
        currentTime->setText(QApplication::translate("DataTransferMenu", "1234567890", nullptr));
        spaceLabel1->setText(QString());
        spaceLabel2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DataTransferMenu: public Ui_DataTransferMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATATRANSFERMENU_H
