/********************************************************************************
** Form generated from reading UI file 'simpledownmenuwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLEDOWNMENUWIDGET_H
#define UI_SIMPLEDOWNMENUWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimpleDownMenuWidget
{
public:
    QLabel *nextMarkDataLabel;
    QLabel *nextLineLabel;
    QLabel *surveyModeLabel;
    QLabel *cycleTimeLabel;
    QPushButton *startButton;
    QLabel *cycleTimeUnitLabel;
    QLabel *nextLineDataLabel;
    QLabel *nextMarkLabel;

    void setupUi(QWidget *SimpleDownMenuWidget)
    {
        if (SimpleDownMenuWidget->objectName().isEmpty())
            SimpleDownMenuWidget->setObjectName(QString::fromUtf8("SimpleDownMenuWidget"));
        SimpleDownMenuWidget->resize(647, 224);
        nextMarkDataLabel = new QLabel(SimpleDownMenuWidget);
        nextMarkDataLabel->setObjectName(QString::fromUtf8("nextMarkDataLabel"));
        nextMarkDataLabel->setGeometry(QRect(250, 148, 161, 31));
        nextMarkDataLabel->setAlignment(Qt::AlignCenter);
        nextLineLabel = new QLabel(SimpleDownMenuWidget);
        nextLineLabel->setObjectName(QString::fromUtf8("nextLineLabel"));
        nextLineLabel->setGeometry(QRect(10, 110, 141, 31));
        surveyModeLabel = new QLabel(SimpleDownMenuWidget);
        surveyModeLabel->setObjectName(QString::fromUtf8("surveyModeLabel"));
        surveyModeLabel->setGeometry(QRect(10, 30, 171, 31));
        cycleTimeLabel = new QLabel(SimpleDownMenuWidget);
        cycleTimeLabel->setObjectName(QString::fromUtf8("cycleTimeLabel"));
        cycleTimeLabel->setGeometry(QRect(10, 70, 151, 31));
        startButton = new QPushButton(SimpleDownMenuWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(70, 180, 301, 41));
        startButton->setFocusPolicy(Qt::NoFocus);
        cycleTimeUnitLabel = new QLabel(SimpleDownMenuWidget);
        cycleTimeUnitLabel->setObjectName(QString::fromUtf8("cycleTimeUnitLabel"));
        cycleTimeUnitLabel->setGeometry(QRect(330, 70, 41, 31));
        nextLineDataLabel = new QLabel(SimpleDownMenuWidget);
        nextLineDataLabel->setObjectName(QString::fromUtf8("nextLineDataLabel"));
        nextLineDataLabel->setGeometry(QRect(250, 110, 161, 31));
        nextLineDataLabel->setFocusPolicy(Qt::NoFocus);
        nextLineDataLabel->setAlignment(Qt::AlignCenter);
        nextMarkLabel = new QLabel(SimpleDownMenuWidget);
        nextMarkLabel->setObjectName(QString::fromUtf8("nextMarkLabel"));
        nextMarkLabel->setGeometry(QRect(10, 148, 141, 31));

        retranslateUi(SimpleDownMenuWidget);

        QMetaObject::connectSlotsByName(SimpleDownMenuWidget);
    } // setupUi

    void retranslateUi(QWidget *SimpleDownMenuWidget)
    {
        SimpleDownMenuWidget->setWindowTitle(QApplication::translate("SimpleDownMenuWidget", "Form", nullptr));
        nextMarkDataLabel->setText(QApplication::translate("SimpleDownMenuWidget", "0", nullptr));
        nextLineLabel->setText(QApplication::translate("SimpleDownMenuWidget", "Next Line:", nullptr));
        surveyModeLabel->setText(QApplication::translate("SimpleDownMenuWidget", "\351\207\207\351\233\206\346\250\241\345\274\217:", nullptr));
        cycleTimeLabel->setText(QApplication::translate("SimpleDownMenuWidget", "\351\207\207\351\233\206\351\242\221\347\216\207:", nullptr));
        startButton->setText(QApplication::translate("SimpleDownMenuWidget", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        cycleTimeUnitLabel->setText(QApplication::translate("SimpleDownMenuWidget", "Hz", nullptr));
        nextLineDataLabel->setText(QApplication::translate("SimpleDownMenuWidget", "0", nullptr));
        nextMarkLabel->setText(QApplication::translate("SimpleDownMenuWidget", "Next Mark:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SimpleDownMenuWidget: public Ui_SimpleDownMenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEDOWNMENUWIDGET_H
