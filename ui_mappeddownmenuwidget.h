/********************************************************************************
** Form generated from reading UI file 'mappeddownmenuwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPPEDDOWNMENUWIDGET_H
#define UI_MAPPEDDOWNMENUWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
            MappedDownMenuWidget->setObjectName(QString::fromUtf8("MappedDownMenuWidget"));
        MappedDownMenuWidget->resize(647, 347);
        surveyModeLabel = new QLabel(MappedDownMenuWidget);
        surveyModeLabel->setObjectName(QString::fromUtf8("surveyModeLabel"));
        surveyModeLabel->setGeometry(QRect(10, 30, 171, 31));
        cycleTimeUnitLabel = new QLabel(MappedDownMenuWidget);
        cycleTimeUnitLabel->setObjectName(QString::fromUtf8("cycleTimeUnitLabel"));
        cycleTimeUnitLabel->setGeometry(QRect(330, 70, 41, 31));
        cycleTimeLabel = new QLabel(MappedDownMenuWidget);
        cycleTimeLabel->setObjectName(QString::fromUtf8("cycleTimeLabel"));
        cycleTimeLabel->setGeometry(QRect(10, 70, 151, 31));
        defineButton = new QPushButton(MappedDownMenuWidget);
        defineButton->setObjectName(QString::fromUtf8("defineButton"));
        defineButton->setGeometry(QRect(70, 110, 301, 41));
        defineButton->setFlat(false);
        startButton = new QPushButton(MappedDownMenuWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(70, 150, 301, 41));
        startButton->setFlat(false);
        atLabel = new QLabel(MappedDownMenuWidget);
        atLabel->setObjectName(QString::fromUtf8("atLabel"));
        atLabel->setGeometry(QRect(73, 190, 61, 41));
        xLabel = new QLabel(MappedDownMenuWidget);
        xLabel->setObjectName(QString::fromUtf8("xLabel"));
        xLabel->setGeometry(QRect(140, 190, 61, 41));
        yLabel = new QLabel(MappedDownMenuWidget);
        yLabel->setObjectName(QString::fromUtf8("yLabel"));
        yLabel->setGeometry(QRect(290, 190, 61, 41));
        goingLabel = new QLabel(MappedDownMenuWidget);
        goingLabel->setObjectName(QString::fromUtf8("goingLabel"));
        goingLabel->setGeometry(QRect(150, 230, 101, 41));

        retranslateUi(MappedDownMenuWidget);

        QMetaObject::connectSlotsByName(MappedDownMenuWidget);
    } // setupUi

    void retranslateUi(QWidget *MappedDownMenuWidget)
    {
        MappedDownMenuWidget->setWindowTitle(QApplication::translate("MappedDownMenuWidget", "Form", nullptr));
        surveyModeLabel->setText(QApplication::translate("MappedDownMenuWidget", "\351\207\207\351\233\206\346\250\241\345\274\217:", nullptr));
        cycleTimeUnitLabel->setText(QApplication::translate("MappedDownMenuWidget", "Hz", nullptr));
        cycleTimeLabel->setText(QApplication::translate("MappedDownMenuWidget", "\351\207\207\351\233\206\351\242\221\347\216\207:", nullptr));
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
