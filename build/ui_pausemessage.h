/********************************************************************************
** Form generated from reading UI file 'pausemessage.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSEMESSAGE_H
#define UI_PAUSEMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_PauseMessage
{
public:
    QLabel *message8;
    QLabel *message1;
    QLabel *message6;
    QLabel *message5;
    QLabel *message7;
    QLabel *markDataLabel;
    QLabel *markLabel;
    QLabel *message2;
    QLabel *lineDataLabel;
    QLabel *lineLabel;
    QLabel *message3;
    QLabel *message4;

    void setupUi(QDialog *PauseMessage)
    {
        if (PauseMessage->objectName().isEmpty())
            PauseMessage->setObjectName(QStringLiteral("PauseMessage"));
        PauseMessage->resize(1024, 576);
        message8 = new QLabel(PauseMessage);
        message8->setObjectName(QStringLiteral("message8"));
        message8->setGeometry(QRect(340, 390, 111, 16));
        message1 = new QLabel(PauseMessage);
        message1->setObjectName(QStringLiteral("message1"));
        message1->setGeometry(QRect(340, 110, 371, 31));
        message6 = new QLabel(PauseMessage);
        message6->setObjectName(QStringLiteral("message6"));
        message6->setGeometry(QRect(340, 330, 221, 16));
        message5 = new QLabel(PauseMessage);
        message5->setObjectName(QStringLiteral("message5"));
        message5->setGeometry(QRect(340, 300, 54, 12));
        message7 = new QLabel(PauseMessage);
        message7->setObjectName(QStringLiteral("message7"));
        message7->setGeometry(QRect(340, 360, 151, 16));
        markDataLabel = new QLabel(PauseMessage);
        markDataLabel->setObjectName(QStringLiteral("markDataLabel"));
        markDataLabel->setGeometry(QRect(430, 210, 54, 12));
        markLabel = new QLabel(PauseMessage);
        markLabel->setObjectName(QStringLiteral("markLabel"));
        markLabel->setGeometry(QRect(340, 210, 54, 12));
        message2 = new QLabel(PauseMessage);
        message2->setObjectName(QStringLiteral("message2"));
        message2->setGeometry(QRect(340, 140, 391, 31));
        lineDataLabel = new QLabel(PauseMessage);
        lineDataLabel->setObjectName(QStringLiteral("lineDataLabel"));
        lineDataLabel->setGeometry(QRect(430, 180, 54, 12));
        lineLabel = new QLabel(PauseMessage);
        lineLabel->setObjectName(QStringLiteral("lineLabel"));
        lineLabel->setGeometry(QRect(340, 180, 54, 12));
        message3 = new QLabel(PauseMessage);
        message3->setObjectName(QStringLiteral("message3"));
        message3->setGeometry(QRect(340, 240, 221, 16));
        message4 = new QLabel(PauseMessage);
        message4->setObjectName(QStringLiteral("message4"));
        message4->setGeometry(QRect(340, 270, 231, 16));

        retranslateUi(PauseMessage);

        QMetaObject::connectSlotsByName(PauseMessage);
    } // setupUi

    void retranslateUi(QDialog *PauseMessage)
    {
        PauseMessage->setWindowTitle(QApplication::translate("PauseMessage", "Dialog", nullptr));
        message8->setText(QApplication::translate("PauseMessage", "FOR EDITING", nullptr));
        message1->setText(QApplication::translate("PauseMessage", "YOU HAVE JUST PAUSED.", nullptr));
        message6->setText(QApplication::translate("PauseMessage", "PRESS \"MENU\" AND SELECT", nullptr));
        message5->setText(QApplication::translate("PauseMessage", "OR", nullptr));
        message7->setText(QApplication::translate("PauseMessage", "\"EDIT LINE AND MARK\"", nullptr));
        markDataLabel->setText(QString());
        markLabel->setText(QApplication::translate("PauseMessage", "MARK:", nullptr));
        message2->setText(QApplication::translate("PauseMessage", "YOU CURRENTLY GOING TO:", nullptr));
        lineDataLabel->setText(QString());
        lineLabel->setText(QApplication::translate("PauseMessage", "LINE:", nullptr));
        message3->setText(QApplication::translate("PauseMessage", "PRESS ANY KEY TO CLEAR THIS MESSAGE", nullptr));
        message4->setText(QApplication::translate("PauseMessage", "THEN PRESS \"MARK\" TO START NEXT LINE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PauseMessage: public Ui_PauseMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSEMESSAGE_H
