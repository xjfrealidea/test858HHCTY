/********************************************************************************
** Form generated from reading UI file 'endlinemessage.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDLINEMESSAGE_H
#define UI_ENDLINEMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_EndLineMessage
{
public:
    QLabel *message1;
    QLabel *message2;
    QLabel *lineLabel;
    QLabel *markLabel;
    QLabel *message3;
    QLabel *message4;
    QLabel *message5;
    QLabel *message6;
    QLabel *message7;
    QLabel *message8;
    QLabel *lineDataLabel;
    QLabel *markDataLabel;

    void setupUi(QDialog *EndLineMessage)
    {
        if (EndLineMessage->objectName().isEmpty())
            EndLineMessage->setObjectName(QStringLiteral("EndLineMessage"));
        EndLineMessage->resize(1024, 576);
        message1 = new QLabel(EndLineMessage);
        message1->setObjectName(QStringLiteral("message1"));
        message1->setGeometry(QRect(310, 40, 371, 31));
        message2 = new QLabel(EndLineMessage);
        message2->setObjectName(QStringLiteral("message2"));
        message2->setGeometry(QRect(310, 70, 391, 31));
        lineLabel = new QLabel(EndLineMessage);
        lineLabel->setObjectName(QStringLiteral("lineLabel"));
        lineLabel->setGeometry(QRect(310, 110, 54, 12));
        markLabel = new QLabel(EndLineMessage);
        markLabel->setObjectName(QStringLiteral("markLabel"));
        markLabel->setGeometry(QRect(310, 140, 54, 12));
        message3 = new QLabel(EndLineMessage);
        message3->setObjectName(QStringLiteral("message3"));
        message3->setGeometry(QRect(310, 170, 221, 16));
        message4 = new QLabel(EndLineMessage);
        message4->setObjectName(QStringLiteral("message4"));
        message4->setGeometry(QRect(310, 200, 231, 16));
        message5 = new QLabel(EndLineMessage);
        message5->setObjectName(QStringLiteral("message5"));
        message5->setGeometry(QRect(310, 230, 54, 12));
        message6 = new QLabel(EndLineMessage);
        message6->setObjectName(QStringLiteral("message6"));
        message6->setGeometry(QRect(310, 260, 221, 16));
        message7 = new QLabel(EndLineMessage);
        message7->setObjectName(QStringLiteral("message7"));
        message7->setGeometry(QRect(310, 290, 151, 16));
        message8 = new QLabel(EndLineMessage);
        message8->setObjectName(QStringLiteral("message8"));
        message8->setGeometry(QRect(310, 320, 111, 16));
        lineDataLabel = new QLabel(EndLineMessage);
        lineDataLabel->setObjectName(QStringLiteral("lineDataLabel"));
        lineDataLabel->setGeometry(QRect(400, 110, 91, 16));
        lineDataLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        markDataLabel = new QLabel(EndLineMessage);
        markDataLabel->setObjectName(QStringLiteral("markDataLabel"));
        markDataLabel->setGeometry(QRect(400, 140, 91, 16));
        markDataLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(EndLineMessage);

        QMetaObject::connectSlotsByName(EndLineMessage);
    } // setupUi

    void retranslateUi(QDialog *EndLineMessage)
    {
        EndLineMessage->setWindowTitle(QApplication::translate("EndLineMessage", "Dialog", nullptr));
        message1->setText(QApplication::translate("EndLineMessage", "\345\267\262\345\210\260\350\276\276\345\275\223\345\211\215\350\260\203\346\237\245\350\241\214\347\232\204\346\234\253\345\260\276\343\200\202", nullptr));
        message2->setText(QApplication::translate("EndLineMessage", "\345\275\223\345\211\215\344\275\215\347\275\256:", nullptr));
        lineLabel->setText(QApplication::translate("EndLineMessage", "LINE:", nullptr));
        markLabel->setText(QApplication::translate("EndLineMessage", "MARK:", nullptr));
        message3->setText(QApplication::translate("EndLineMessage", "\346\214\211\344\273\273\346\204\217\351\224\256\346\270\205\351\231\244\346\234\254\346\266\210\346\201\257\343\200\202", nullptr));
        message4->setText(QApplication::translate("EndLineMessage", "\344\271\213\345\220\216\346\214\211\"MARK\"\351\224\256\345\274\200\345\247\213\344\270\213\344\270\200\350\241\214\351\207\207\351\233\206", nullptr));
        message5->setText(QApplication::translate("EndLineMessage", "\346\210\226", nullptr));
        message6->setText(QApplication::translate("EndLineMessage", "\346\214\211\"MENU\"\351\224\256\345\271\266\351\200\211\346\213\251\"\347\274\226\350\276\221LINE\344\270\216MARK\"", nullptr));
        message7->setText(QApplication::translate("EndLineMessage", "\350\277\233\350\241\214\346\225\260\346\215\256\347\274\226\350\276\221", nullptr));
        message8->setText(QString());
        lineDataLabel->setText(QString());
        markDataLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EndLineMessage: public Ui_EndLineMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDLINEMESSAGE_H
