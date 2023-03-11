/********************************************************************************
** Form generated from reading UI file 'escmessage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESCMESSAGE_H
#define UI_ESCMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_EscMessage
{
public:
    QLabel *message1;
    QLabel *message2;
    QLabel *message4;
    QLabel *message6;
    QLabel *message3;
    QLabel *message5;

    void setupUi(QDialog *EscMessage)
    {
        if (EscMessage->objectName().isEmpty())
            EscMessage->setObjectName(QString::fromUtf8("EscMessage"));
        EscMessage->resize(1024, 576);
        message1 = new QLabel(EscMessage);
        message1->setObjectName(QString::fromUtf8("message1"));
        message1->setGeometry(QRect(200, 80, 681, 61));
        message1->setAlignment(Qt::AlignCenter);
        message2 = new QLabel(EscMessage);
        message2->setObjectName(QString::fromUtf8("message2"));
        message2->setGeometry(QRect(420, 150, 241, 31));
        message2->setAlignment(Qt::AlignCenter);
        message2->setWordWrap(true);
        message4 = new QLabel(EscMessage);
        message4->setObjectName(QString::fromUtf8("message4"));
        message4->setGeometry(QRect(430, 210, 201, 31));
        message4->setAlignment(Qt::AlignCenter);
        message4->setWordWrap(true);
        message6 = new QLabel(EscMessage);
        message6->setObjectName(QString::fromUtf8("message6"));
        message6->setGeometry(QRect(420, 290, 221, 31));
        message6->setAlignment(Qt::AlignCenter);
        message6->setWordWrap(true);
        message3 = new QLabel(EscMessage);
        message3->setObjectName(QString::fromUtf8("message3"));
        message3->setGeometry(QRect(450, 190, 161, 16));
        message3->setAlignment(Qt::AlignCenter);
        message5 = new QLabel(EscMessage);
        message5->setObjectName(QString::fromUtf8("message5"));
        message5->setGeometry(QRect(430, 240, 201, 31));
        message5->setAlignment(Qt::AlignCenter);

        retranslateUi(EscMessage);

        QMetaObject::connectSlotsByName(EscMessage);
    } // setupUi

    void retranslateUi(QDialog *EscMessage)
    {
        EscMessage->setWindowTitle(QApplication::translate("EscMessage", "Dialog", nullptr));
        message1->setText(QApplication::translate("EscMessage", "ERROR:", nullptr));
        message2->setText(QApplication::translate("EscMessage", "You must establish an ending position ", nullptr));
        message4->setText(QApplication::translate("EscMessage", "Press the END-LINE key to ", nullptr));
        message6->setText(QApplication::translate("EscMessage", "Press any key to continue.", nullptr));
        message3->setText(QApplication::translate("EscMessage", "before leaving the survey.", nullptr));
        message5->setText(QApplication::translate("EscMessage", "complete the line being acquired.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EscMessage: public Ui_EscMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESCMESSAGE_H
