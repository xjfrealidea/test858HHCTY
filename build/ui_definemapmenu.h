/********************************************************************************
** Form generated from reading UI file 'definemapmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFINEMAPMENU_H
#define UI_DEFINEMAPMENU_H

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

class Ui_DefineMapMenu
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QLabel *hintLabel;
    QLabel *directionSurveyLabel;
    QLabel *LLDisplayLabel;
    QLabel *LLxDisplayLabel;
    QLabel *LLyDisplayLabel;
    QLabel *URyDisplayLabel;
    QLabel *URxDisplayLabel;
    QLabel *URDisplayLabel;
    QLabel *parallelDisplayLabel;
    QLabel *parallelAxisDisplayLabel;
    QLabel *spaceLineDisplayLabel;
    QLabel *spaceMarkDisplayLabel;
    QPushButton *doneEnteringInfoButton;
    QLabel *spaceLabel;
    QLabel *spaceLabel2;
    TimeLabel *currentTime;
    QLabel *spaceLabel4;
    QLabel *spaceLabel3;
    QLabel *spaceLabel5;
    QLabel *spaceLabel7;
    QLabel *spaceLabel6;
    QLabel *spaceLabel8;

    void setupUi(QMainWindow *DefineMapMenu)
    {
        if (DefineMapMenu->objectName().isEmpty())
            DefineMapMenu->setObjectName(QStringLiteral("DefineMapMenu"));
        DefineMapMenu->resize(1024, 576);
        centralwidget = new QWidget(DefineMapMenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setGeometry(QRect(460, 10, 121, 31));
        hintLabel = new QLabel(centralwidget);
        hintLabel->setObjectName(QStringLiteral("hintLabel"));
        hintLabel->setGeometry(QRect(160, 60, 501, 41));
        hintLabel->setWordWrap(true);
        directionSurveyLabel = new QLabel(centralwidget);
        directionSurveyLabel->setObjectName(QStringLiteral("directionSurveyLabel"));
        directionSurveyLabel->setGeometry(QRect(600, 110, 54, 12));
        LLDisplayLabel = new QLabel(centralwidget);
        LLDisplayLabel->setObjectName(QStringLiteral("LLDisplayLabel"));
        LLDisplayLabel->setGeometry(QRect(330, 130, 181, 16));
        LLxDisplayLabel = new QLabel(centralwidget);
        LLxDisplayLabel->setObjectName(QStringLiteral("LLxDisplayLabel"));
        LLxDisplayLabel->setGeometry(QRect(360, 170, 54, 12));
        LLyDisplayLabel = new QLabel(centralwidget);
        LLyDisplayLabel->setObjectName(QStringLiteral("LLyDisplayLabel"));
        LLyDisplayLabel->setGeometry(QRect(480, 170, 54, 12));
        URyDisplayLabel = new QLabel(centralwidget);
        URyDisplayLabel->setObjectName(QStringLiteral("URyDisplayLabel"));
        URyDisplayLabel->setGeometry(QRect(480, 260, 54, 12));
        URxDisplayLabel = new QLabel(centralwidget);
        URxDisplayLabel->setObjectName(QStringLiteral("URxDisplayLabel"));
        URxDisplayLabel->setGeometry(QRect(360, 260, 54, 12));
        URDisplayLabel = new QLabel(centralwidget);
        URDisplayLabel->setObjectName(QStringLiteral("URDisplayLabel"));
        URDisplayLabel->setGeometry(QRect(330, 220, 181, 16));
        parallelDisplayLabel = new QLabel(centralwidget);
        parallelDisplayLabel->setObjectName(QStringLiteral("parallelDisplayLabel"));
        parallelDisplayLabel->setGeometry(QRect(330, 300, 141, 16));
        parallelAxisDisplayLabel = new QLabel(centralwidget);
        parallelAxisDisplayLabel->setObjectName(QStringLiteral("parallelAxisDisplayLabel"));
        parallelAxisDisplayLabel->setGeometry(QRect(500, 300, 54, 12));
        spaceLineDisplayLabel = new QLabel(centralwidget);
        spaceLineDisplayLabel->setObjectName(QStringLiteral("spaceLineDisplayLabel"));
        spaceLineDisplayLabel->setGeometry(QRect(330, 340, 111, 16));
        spaceMarkDisplayLabel = new QLabel(centralwidget);
        spaceMarkDisplayLabel->setObjectName(QStringLiteral("spaceMarkDisplayLabel"));
        spaceMarkDisplayLabel->setGeometry(QRect(330, 380, 111, 16));
        doneEnteringInfoButton = new QPushButton(centralwidget);
        doneEnteringInfoButton->setObjectName(QStringLiteral("doneEnteringInfoButton"));
        doneEnteringInfoButton->setGeometry(QRect(440, 420, 141, 23));
        doneEnteringInfoButton->setFlat(true);
        spaceLabel = new QLabel(centralwidget);
        spaceLabel->setObjectName(QStringLiteral("spaceLabel"));
        spaceLabel->setGeometry(QRect(340, 510, 54, 12));
        spaceLabel2 = new QLabel(centralwidget);
        spaceLabel2->setObjectName(QStringLiteral("spaceLabel2"));
        spaceLabel2->setGeometry(QRect(600, 510, 54, 12));
        currentTime = new TimeLabel(centralwidget);
        currentTime->setObjectName(QStringLiteral("currentTime"));
        currentTime->setGeometry(QRect(110, 530, 191, 20));
        currentTime->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\351\273\221\344\275\223\";"));
        currentTime->setAlignment(Qt::AlignCenter);
        spaceLabel4 = new QLabel(centralwidget);
        spaceLabel4->setObjectName(QStringLiteral("spaceLabel4"));
        spaceLabel4->setGeometry(QRect(820, 550, 54, 12));
        spaceLabel3 = new QLabel(centralwidget);
        spaceLabel3->setObjectName(QStringLiteral("spaceLabel3"));
        spaceLabel3->setGeometry(QRect(560, 550, 54, 12));
        spaceLabel5 = new QLabel(centralwidget);
        spaceLabel5->setObjectName(QStringLiteral("spaceLabel5"));
        spaceLabel5->setGeometry(QRect(730, 450, 54, 12));
        spaceLabel7 = new QLabel(centralwidget);
        spaceLabel7->setObjectName(QStringLiteral("spaceLabel7"));
        spaceLabel7->setGeometry(QRect(990, 450, 54, 12));
        spaceLabel6 = new QLabel(centralwidget);
        spaceLabel6->setObjectName(QStringLiteral("spaceLabel6"));
        spaceLabel6->setGeometry(QRect(730, 490, 54, 12));
        spaceLabel8 = new QLabel(centralwidget);
        spaceLabel8->setObjectName(QStringLiteral("spaceLabel8"));
        spaceLabel8->setGeometry(QRect(990, 490, 54, 12));
        DefineMapMenu->setCentralWidget(centralwidget);

        retranslateUi(DefineMapMenu);

        QMetaObject::connectSlotsByName(DefineMapMenu);
    } // setupUi

    void retranslateUi(QMainWindow *DefineMapMenu)
    {
        DefineMapMenu->setWindowTitle(QApplication::translate("DefineMapMenu", "MainWindow", nullptr));
        titleLabel->setText(QApplication::translate("DefineMapMenu", "SET UP DISPLAY", nullptr));
        hintLabel->setText(QApplication::translate("DefineMapMenu", "This menu sets up how the X and Y axes are displayed on the map.", nullptr));
        directionSurveyLabel->setText(QApplication::translate("DefineMapMenu", "Survey", nullptr));
        LLDisplayLabel->setText(QApplication::translate("DefineMapMenu", "Lower Left corner of display:", nullptr));
        LLxDisplayLabel->setText(QApplication::translate("DefineMapMenu", "X : ", nullptr));
        LLyDisplayLabel->setText(QApplication::translate("DefineMapMenu", "Y : ", nullptr));
        URyDisplayLabel->setText(QApplication::translate("DefineMapMenu", "Y : ", nullptr));
        URxDisplayLabel->setText(QApplication::translate("DefineMapMenu", "X : ", nullptr));
        URDisplayLabel->setText(QApplication::translate("DefineMapMenu", "Upper Right corner of display:", nullptr));
        parallelDisplayLabel->setText(QApplication::translate("DefineMapMenu", "Survey parallel to ", nullptr));
        parallelAxisDisplayLabel->setText(QApplication::translate("DefineMapMenu", "axis", nullptr));
        spaceLineDisplayLabel->setText(QApplication::translate("DefineMapMenu", "Line spacing : ", nullptr));
        spaceMarkDisplayLabel->setText(QApplication::translate("DefineMapMenu", "Mark spacing : ", nullptr));
        doneEnteringInfoButton->setText(QApplication::translate("DefineMapMenu", "DONE ENTERING INFO", nullptr));
        spaceLabel->setText(QString());
        spaceLabel2->setText(QString());
        currentTime->setText(QApplication::translate("DefineMapMenu", "1725650274", nullptr));
        spaceLabel4->setText(QString());
        spaceLabel3->setText(QString());
        spaceLabel5->setText(QString());
        spaceLabel7->setText(QString());
        spaceLabel6->setText(QString());
        spaceLabel8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DefineMapMenu: public Ui_DefineMapMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFINEMAPMENU_H
