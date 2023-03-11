/********************************************************************************
** Form generated from reading UI file 'erasecheckdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERASECHECKDIALOG_H
#define UI_ERASECHECKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EraseCheckDialog
{
public:
    QPushButton *yesButton;
    QPushButton *cancelButton;
    QLabel *label;

    void setupUi(QDialog *EraseCheckDialog)
    {
        if (EraseCheckDialog->objectName().isEmpty())
            EraseCheckDialog->setObjectName(QString::fromUtf8("EraseCheckDialog"));
        EraseCheckDialog->resize(400, 159);
        yesButton = new QPushButton(EraseCheckDialog);
        yesButton->setObjectName(QString::fromUtf8("yesButton"));
        yesButton->setGeometry(QRect(48, 110, 111, 41));
        cancelButton = new QPushButton(EraseCheckDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(240, 110, 111, 41));
        label = new QLabel(EraseCheckDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 381, 81));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(EraseCheckDialog);

        QMetaObject::connectSlotsByName(EraseCheckDialog);
    } // setupUi

    void retranslateUi(QDialog *EraseCheckDialog)
    {
        EraseCheckDialog->setWindowTitle(QApplication::translate("EraseCheckDialog", "Dialog", nullptr));
        yesButton->setText(QApplication::translate("EraseCheckDialog", "Yes", nullptr));
        cancelButton->setText(QApplication::translate("EraseCheckDialog", "Cancel", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EraseCheckDialog: public Ui_EraseCheckDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERASECHECKDIALOG_H
