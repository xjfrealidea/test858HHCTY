/********************************************************************************
** Form generated from reading UI file 'spectrogram.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPECTROGRAM_H
#define UI_SPECTROGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Spectrogram
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *Spectrogram)
    {
        if (Spectrogram->objectName().isEmpty())
            Spectrogram->setObjectName(QStringLiteral("Spectrogram"));
        Spectrogram->resize(567, 385);
        centralWidget = new QWidget(Spectrogram);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Spectrogram->setCentralWidget(centralWidget);

        retranslateUi(Spectrogram);

        QMetaObject::connectSlotsByName(Spectrogram);
    } // setupUi

    void retranslateUi(QMainWindow *Spectrogram)
    {
        Spectrogram->setWindowTitle(QApplication::translate("Spectrogram", "Spectrogram", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Spectrogram: public Ui_Spectrogram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECTROGRAM_H
