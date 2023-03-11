/********************************************************************************
** Form generated from reading UI file 'DownMenuWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNMENUWIDGET_H
#define UI_DOWNMENUWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DownMenuWidget
{
public:

    void setupUi(QWidget *DownMenuWidget)
    {
        if (DownMenuWidget->objectName().isEmpty())
            DownMenuWidget->setObjectName(QString::fromUtf8("DownMenuWidget"));
        DownMenuWidget->resize(400, 300);

        retranslateUi(DownMenuWidget);

        QMetaObject::connectSlotsByName(DownMenuWidget);
    } // setupUi

    void retranslateUi(QWidget *DownMenuWidget)
    {
        DownMenuWidget->setWindowTitle(QApplication::translate("DownMenuWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DownMenuWidget: public Ui_DownMenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNMENUWIDGET_H
