/********************************************************************************
** Form generated from reading UI file 'memoryformatdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMORYFORMATDIALOG_H
#define UI_MEMORYFORMATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_MemoryFormatDialog
{
public:
    QLabel *message4;
    QLabel *message1;
    QLabel *message5;
    QLabel *message2;
    QLabel *message3;
    QLabel *message6;

    void setupUi(QDialog *MemoryFormatDialog)
    {
        if (MemoryFormatDialog->objectName().isEmpty())
            MemoryFormatDialog->setObjectName(QStringLiteral("MemoryFormatDialog"));
        MemoryFormatDialog->resize(1024, 576);
        message4 = new QLabel(MemoryFormatDialog);
        message4->setObjectName(QStringLiteral("message4"));
        message4->setGeometry(QRect(270, 160, 201, 31));
        message4->setAlignment(Qt::AlignCenter);
        message4->setWordWrap(true);
        message1 = new QLabel(MemoryFormatDialog);
        message1->setObjectName(QStringLiteral("message1"));
        message1->setGeometry(QRect(40, 30, 681, 61));
        message1->setAlignment(Qt::AlignCenter);
        message5 = new QLabel(MemoryFormatDialog);
        message5->setObjectName(QStringLiteral("message5"));
        message5->setGeometry(QRect(270, 190, 201, 31));
        message5->setAlignment(Qt::AlignCenter);
        message2 = new QLabel(MemoryFormatDialog);
        message2->setObjectName(QStringLiteral("message2"));
        message2->setGeometry(QRect(260, 100, 241, 31));
        message2->setAlignment(Qt::AlignCenter);
        message2->setWordWrap(true);
        message3 = new QLabel(MemoryFormatDialog);
        message3->setObjectName(QStringLiteral("message3"));
        message3->setGeometry(QRect(290, 140, 161, 16));
        message3->setAlignment(Qt::AlignCenter);
        message6 = new QLabel(MemoryFormatDialog);
        message6->setObjectName(QStringLiteral("message6"));
        message6->setGeometry(QRect(260, 240, 221, 31));
        message6->setAlignment(Qt::AlignCenter);
        message6->setWordWrap(true);

        retranslateUi(MemoryFormatDialog);

        QMetaObject::connectSlotsByName(MemoryFormatDialog);
    } // setupUi

    void retranslateUi(QDialog *MemoryFormatDialog)
    {
        MemoryFormatDialog->setWindowTitle(QApplication::translate("MemoryFormatDialog", "Dialog", nullptr));
        message4->setText(QApplication::translate("MemoryFormatDialog", "AND \"ENTER\" TO FORMAT MEMORY", nullptr));
        message1->setText(QApplication::translate("MemoryFormatDialog", "YOU ARE ABOUT TO FORMAT THE MEMORY!", nullptr));
        message5->setText(QApplication::translate("MemoryFormatDialog", "PRESS ANY OTHER KEY TO CANCEL", nullptr));
        message2->setText(QApplication::translate("MemoryFormatDialog", "ALL SURVEY DATA WILL BE LOST", nullptr));
        message3->setText(QApplication::translate("MemoryFormatDialog", "PRESS \"DEL\" TO COMFIRM", nullptr));
        message6->setText(QApplication::translate("MemoryFormatDialog", "Press DEL then ENTER to confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MemoryFormatDialog: public Ui_MemoryFormatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMORYFORMATDIALOG_H
