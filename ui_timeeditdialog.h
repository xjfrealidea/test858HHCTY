/********************************************************************************
** Form generated from reading UI file 'timeeditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMEEDITDIALOG_H
#define UI_TIMEEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include "timeedit.h"

QT_BEGIN_NAMESPACE

class Ui_TimeEditDialog
{
public:
    timeEdit *dateTimeEdit;

    void setupUi(QDialog *TimeEditDialog)
    {
        if (TimeEditDialog->objectName().isEmpty())
            TimeEditDialog->setObjectName(QString::fromUtf8("TimeEditDialog"));
        TimeEditDialog->resize(360, 110);
        dateTimeEdit = new timeEdit(TimeEditDialog);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(20, 30, 320, 50));
        QFont font;
        font.setPointSize(21);
        dateTimeEdit->setFont(font);
        dateTimeEdit->setFocusPolicy(Qt::StrongFocus);
        dateTimeEdit->setCurrentSection(QDateTimeEdit::YearSection);
        dateTimeEdit->setCurrentSectionIndex(0);

        retranslateUi(TimeEditDialog);

        QMetaObject::connectSlotsByName(TimeEditDialog);
    } // setupUi

    void retranslateUi(QDialog *TimeEditDialog)
    {
        TimeEditDialog->setWindowTitle(QApplication::translate("TimeEditDialog", "Dialog", nullptr));
        dateTimeEdit->setDisplayFormat(QApplication::translate("TimeEditDialog", "yyyy/MM/dd HH:mm:ss", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimeEditDialog: public Ui_TimeEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMEEDITDIALOG_H
