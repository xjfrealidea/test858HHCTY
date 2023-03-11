/********************************************************************************
** Form generated from reading UI file 'mappeddownmenuwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPPEDDOWNMENUWIDGET_H
#define UI_MAPPEDDOWNMENUWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MappedDownMenuWidget
{
public:
    QLabel *surveyModeLabel;
    QLabel *cycleTimeUnitLabel;
    QLabel *cycleTimeLabel;
    QPushButton *defineButton;
    QPushButton *startButton;
    QLabel *atLabel;
    QLabel *xLabel;
    QLabel *yLabel;
    QLabel *goingLabel;

    void setupUi(QWidget *MappedDownMenuWidget)
    {
        if (MappedDownMenuWidget->objectName().isEmpty())
            MappedDownMenuWidget->setObjectName(QStringLiteral("MappedDownMenuWidget"));
        MappedDownMenuWidget->resize(647, 347);
        surveyModeLabel = new QLabel(MappedDownMenuWidget);
        surveyModeLabel->setObjectName(QStringLiteral("surveyModeLabel"));
        surveyModeLabel->setGeometry(QRect(70, 15, 171, 31));
        cycleTimeUnitLabel = new QLabel(MappedDownMenuWidget);
        cycleTimeUnitLabel->setObjectName(QStringLiteral("cycleTimeUnitLabel"));
        cycleTimeUnitLabel->setGeometry(QRect(420, 55, 41, 31));
        cycleTimeLabel = new QLabel(MappedDownMenuWidget);
        cycleTimeLabel->setObjectName(QStringLiteral("cycleTimeLabel"));
        cycleTimeLabel->setGeometry(QRect(70, 55, 151, 31));
        defineButton = new QPushButton(MappedDownMenuWidget);
        defineButton->setObjectName(QStringLiteral("defineButton"));
        defineButton->setGeometry(QRect(120, 95, 221, 41));
        defineButton->setFlat(true);
        startButton = new QPushButton(MappedDownMenuWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(110, 155, 241, 41));
        startButton->setFlat(true);
        atLabel = new QLabel(MappedDownMenuWidget);
        atLabel->setObjectName(QStringLiteral("atLabel"));
        atLabel->setGeometry(QRect(73, 205, 61, 41));
        xLabel = new QLabel(MappedDownMenuWidget);
        xLabel->setObjectName(QStringLiteral("xLabel"));
        xLabel->setGeometry(QRect(140, 205, 61, 41));
        yLabel = new QLabel(MappedDownMenuWidget);
        yLabel->setObjectName(QStringLiteral("yLabel"));
        yLabel->setGeometry(QRect(290, 206, 61, 41));
        goingLabel = new QLabel(MappedDownMenuWidget);
        goingLabel->setObjectName(QStringLiteral("goingLabel"));
        goingLabel->setGeometry(QRect(150, 250, 101, 41));

        retranslateUi(MappedDownMenuWidget);

        QMetaObject::connectSlotsByName(MappedDownMenuWidget);
    } // setupUi

    void retranslateUi(QWidget *MappedDownMenuWidget)
    {
        MappedDownMenuWidget->setWindowTitle(QApplication::translate("MappedDownMenuWidget", "Form", nullptr));
        surveyModeLabel->setText(QApplication::translate("MappedDownMenuWidget", "\351\207\207\351\233\206\346\250\241\345\274\217:", nullptr));
        cycleTimeUnitLabel->setText(QApplication::translate("MappedDownMenuWidget", "s", nullptr));
        cycleTimeLabel->setText(QApplication::translate("MappedDownMenuWidget", "\345\221\250   \346\234\237:", nullptr));
        defineButton->setText(QApplication::translate("MappedDownMenuWidget", "define map", nullptr));
        startButton->setText(QApplication::translate("MappedDownMenuWidget", "begin survey", nullptr));
        atLabel->setText(QApplication::translate("MappedDownMenuWidget", "At", nullptr));
        xLabel->setText(QApplication::translate("MappedDownMenuWidget", "X", nullptr));
        yLabel->setText(QApplication::translate("MappedDownMenuWidget", "Y", nullptr));
        goingLabel->setText(QApplication::translate("MappedDownMenuWidget", "going", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MappedDownMenuWidget: public Ui_MappedDownMenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPPEDDOWNMENUWIDGET_H
