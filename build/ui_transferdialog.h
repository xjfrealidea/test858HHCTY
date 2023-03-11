/********************************************************************************
** Form generated from reading UI file 'transferdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFERDIALOG_H
#define UI_TRANSFERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_transferDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *transferDialog)
    {
        if (transferDialog->objectName().isEmpty())
            transferDialog->setObjectName(QStringLiteral("transferDialog"));
        transferDialog->resize(400, 159);
        label = new QLabel(transferDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 381, 51));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(transferDialog);

        QMetaObject::connectSlotsByName(transferDialog);
    } // setupUi

    void retranslateUi(QDialog *transferDialog)
    {
        transferDialog->setWindowTitle(QApplication::translate("transferDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("transferDialog", "DATA IN TRANSMITTING...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class transferDialog: public Ui_transferDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFERDIALOG_H
