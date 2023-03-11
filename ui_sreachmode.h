/********************************************************************************
** Form generated from reading UI file 'sreachmode.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SREACHMODE_H
#define UI_SREACHMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SreachMode
{
public:
    QWidget *centralwidget;
    QLabel *statusLabel;
    QLabel *adjustDataLabel;
    QLabel *adjustLabel;
    QLabel *scaleDataLabel;
    QLabel *scaleLabel;
    QLabel *qcDataLabel;
    QLabel *qcLabel;
    QLabel *fieldDataLabel;
    QLabel *fieldLabel;
    QLabel *modeLabel;
    QFrame *line;
    QWidget *popUpMenu;

    void setupUi(QMainWindow *SreachMode)
    {
        if (SreachMode->objectName().isEmpty())
            SreachMode->setObjectName(QString::fromUtf8("SreachMode"));
        SreachMode->resize(800, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SreachMode->sizePolicy().hasHeightForWidth());
        SreachMode->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(SreachMode);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(127, 170, 51, 31));
        statusLabel->setStyleSheet(QString::fromUtf8(""));
        statusLabel->setWordWrap(true);
        adjustDataLabel = new QLabel(centralwidget);
        adjustDataLabel->setObjectName(QString::fromUtf8("adjustDataLabel"));
        adjustDataLabel->setGeometry(QRect(127, 290, 61, 16));
        adjustDataLabel->setStyleSheet(QString::fromUtf8(""));
        adjustLabel = new QLabel(centralwidget);
        adjustLabel->setObjectName(QString::fromUtf8("adjustLabel"));
        adjustLabel->setGeometry(QRect(127, 270, 61, 16));
        adjustLabel->setStyleSheet(QString::fromUtf8(""));
        scaleDataLabel = new QLabel(centralwidget);
        scaleDataLabel->setObjectName(QString::fromUtf8("scaleDataLabel"));
        scaleDataLabel->setGeometry(QRect(127, 250, 61, 16));
        scaleLabel = new QLabel(centralwidget);
        scaleLabel->setObjectName(QString::fromUtf8("scaleLabel"));
        scaleLabel->setGeometry(QRect(127, 230, 61, 16));
        scaleLabel->setStyleSheet(QString::fromUtf8(""));
        qcDataLabel = new QLabel(centralwidget);
        qcDataLabel->setObjectName(QString::fromUtf8("qcDataLabel"));
        qcDataLabel->setGeometry(QRect(127, 210, 61, 16));
        qcLabel = new QLabel(centralwidget);
        qcLabel->setObjectName(QString::fromUtf8("qcLabel"));
        qcLabel->setGeometry(QRect(127, 200, 61, 16));
        qcLabel->setStyleSheet(QString::fromUtf8(""));
        fieldDataLabel = new QLabel(centralwidget);
        fieldDataLabel->setObjectName(QString::fromUtf8("fieldDataLabel"));
        fieldDataLabel->setGeometry(QRect(127, 150, 81, 16));
        fieldLabel = new QLabel(centralwidget);
        fieldLabel->setObjectName(QString::fromUtf8("fieldLabel"));
        fieldLabel->setGeometry(QRect(127, 130, 71, 16));
        fieldLabel->setStyleSheet(QString::fromUtf8(""));
        modeLabel = new QLabel(centralwidget);
        modeLabel->setObjectName(QString::fromUtf8("modeLabel"));
        modeLabel->setGeometry(QRect(127, 110, 101, 16));
        modeLabel->setStyleSheet(QString::fromUtf8(""));
        modeLabel->setWordWrap(true);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(200, 100, 20, 301));
        line->setAutoFillBackground(false);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        popUpMenu = new QWidget(centralwidget);
        popUpMenu->setObjectName(QString::fromUtf8("popUpMenu"));
        popUpMenu->setGeometry(QRect(360, 390, 171, 131));
        SreachMode->setCentralWidget(centralwidget);

        retranslateUi(SreachMode);

        QMetaObject::connectSlotsByName(SreachMode);
    } // setupUi

    void retranslateUi(QMainWindow *SreachMode)
    {
        SreachMode->setWindowTitle(QApplication::translate("SreachMode", "MainWindow", nullptr));
        statusLabel->setText(QString());
        adjustDataLabel->setText(QApplication::translate("SreachMode", "\"MENU\"", nullptr));
        adjustLabel->setText(QApplication::translate("SreachMode", "\350\260\203\346\225\264:", nullptr));
        scaleDataLabel->setText(QApplication::translate("SreachMode", "default", nullptr));
        scaleLabel->setText(QApplication::translate("SreachMode", "\345\210\273\345\272\246:", nullptr));
        qcDataLabel->setText(QString());
        qcLabel->setText(QApplication::translate("SreachMode", "QC:", nullptr));
        fieldDataLabel->setText(QString());
        fieldLabel->setText(QApplication::translate("SreachMode", "\350\257\273\346\225\260:", nullptr));
        modeLabel->setText(QApplication::translate("SreachMode", "\346\220\234\347\264\242\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SreachMode: public Ui_SreachMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SREACHMODE_H
