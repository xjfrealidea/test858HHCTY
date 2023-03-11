/********************************************************************************
** Form generated from reading UI file 'basedownmenuwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASEDOWNMENUWIDGET_H
#define UI_BASEDOWNMENUWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BaseDownMenuWidget
{
public:
    QLabel *BaudLabel;
    QLabel *surveyModeLabel;
    QLabel *cycleTimeLabel;
    QPushButton *startButton;
    QLabel *cycleTimeUnitLabel;
    QLabel *saveModeLabel;

    void setupUi(QWidget *BaseDownMenuWidget)
    {
        if (BaseDownMenuWidget->objectName().isEmpty())
            BaseDownMenuWidget->setObjectName(QString::fromUtf8("BaseDownMenuWidget"));
        BaseDownMenuWidget->resize(647, 224);
        BaudLabel = new QLabel(BaseDownMenuWidget);
        BaudLabel->setObjectName(QString::fromUtf8("BaudLabel"));
        BaudLabel->setGeometry(QRect(10, 110, 141, 31));
        surveyModeLabel = new QLabel(BaseDownMenuWidget);
        surveyModeLabel->setObjectName(QString::fromUtf8("surveyModeLabel"));
        surveyModeLabel->setGeometry(QRect(10, 30, 171, 31));
        cycleTimeLabel = new QLabel(BaseDownMenuWidget);
        cycleTimeLabel->setObjectName(QString::fromUtf8("cycleTimeLabel"));
        cycleTimeLabel->setGeometry(QRect(10, 148, 151, 31));
        startButton = new QPushButton(BaseDownMenuWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(70, 180, 301, 41));
        startButton->setFocusPolicy(Qt::NoFocus);
        cycleTimeUnitLabel = new QLabel(BaseDownMenuWidget);
        cycleTimeUnitLabel->setObjectName(QString::fromUtf8("cycleTimeUnitLabel"));
        cycleTimeUnitLabel->setGeometry(QRect(330, 148, 41, 31));
        saveModeLabel = new QLabel(BaseDownMenuWidget);
        saveModeLabel->setObjectName(QString::fromUtf8("saveModeLabel"));
        saveModeLabel->setGeometry(QRect(10, 70, 141, 31));

        retranslateUi(BaseDownMenuWidget);

        QMetaObject::connectSlotsByName(BaseDownMenuWidget);
    } // setupUi

    void retranslateUi(QWidget *BaseDownMenuWidget)
    {
        BaseDownMenuWidget->setWindowTitle(QApplication::translate("BaseDownMenuWidget", "Form", nullptr));
        BaudLabel->setText(QApplication::translate("BaseDownMenuWidget", "\346\263\242 \347\211\271 \347\216\207:", nullptr));
        surveyModeLabel->setText(QApplication::translate("BaseDownMenuWidget", "\351\207\207\351\233\206\346\250\241\345\274\217:", nullptr));
        cycleTimeLabel->setText(QApplication::translate("BaseDownMenuWidget", "\351\207\207\351\233\206\351\242\221\347\216\207:", nullptr));
        startButton->setText(QApplication::translate("BaseDownMenuWidget", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        cycleTimeUnitLabel->setText(QApplication::translate("BaseDownMenuWidget", "Hz", nullptr));
        saveModeLabel->setText(QApplication::translate("BaseDownMenuWidget", "\345\255\230\345\202\250\346\250\241\345\274\217:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BaseDownMenuWidget: public Ui_BaseDownMenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASEDOWNMENUWIDGET_H
