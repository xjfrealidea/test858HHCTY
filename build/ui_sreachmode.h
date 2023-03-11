/********************************************************************************
** Form generated from reading UI file 'sreachmode.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SREACHMODE_H
#define UI_SREACHMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
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
    QLabel *poseXLabel;
    QLabel *poseLabel;
    QLabel *poseYLabel;
    QLabel *poseZLabel;
    QLabel *fluxLabel;
    QLabel *fluxZLabel;
    QLabel *fluxXLabel;
    QLabel *fluxYLabel;

    void setupUi(QMainWindow *SreachMode)
    {
        if (SreachMode->objectName().isEmpty())
            SreachMode->setObjectName(QStringLiteral("SreachMode"));
        SreachMode->resize(1024, 576);
        centralwidget = new QWidget(SreachMode);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(127, 170, 51, 31));
        statusLabel->setStyleSheet(QStringLiteral(""));
        statusLabel->setWordWrap(true);
        adjustDataLabel = new QLabel(centralwidget);
        adjustDataLabel->setObjectName(QStringLiteral("adjustDataLabel"));
        adjustDataLabel->setGeometry(QRect(127, 290, 61, 16));
        adjustDataLabel->setStyleSheet(QStringLiteral(""));
        adjustLabel = new QLabel(centralwidget);
        adjustLabel->setObjectName(QStringLiteral("adjustLabel"));
        adjustLabel->setGeometry(QRect(127, 270, 61, 16));
        adjustLabel->setStyleSheet(QStringLiteral(""));
        scaleDataLabel = new QLabel(centralwidget);
        scaleDataLabel->setObjectName(QStringLiteral("scaleDataLabel"));
        scaleDataLabel->setGeometry(QRect(127, 250, 61, 16));
        scaleLabel = new QLabel(centralwidget);
        scaleLabel->setObjectName(QStringLiteral("scaleLabel"));
        scaleLabel->setGeometry(QRect(127, 230, 61, 16));
        scaleLabel->setStyleSheet(QStringLiteral(""));
        qcDataLabel = new QLabel(centralwidget);
        qcDataLabel->setObjectName(QStringLiteral("qcDataLabel"));
        qcDataLabel->setGeometry(QRect(127, 210, 61, 16));
        qcLabel = new QLabel(centralwidget);
        qcLabel->setObjectName(QStringLiteral("qcLabel"));
        qcLabel->setGeometry(QRect(127, 200, 61, 16));
        qcLabel->setStyleSheet(QStringLiteral(""));
        fieldDataLabel = new QLabel(centralwidget);
        fieldDataLabel->setObjectName(QStringLiteral("fieldDataLabel"));
        fieldDataLabel->setGeometry(QRect(127, 150, 81, 16));
        fieldLabel = new QLabel(centralwidget);
        fieldLabel->setObjectName(QStringLiteral("fieldLabel"));
        fieldLabel->setGeometry(QRect(127, 130, 71, 16));
        fieldLabel->setStyleSheet(QStringLiteral(""));
        modeLabel = new QLabel(centralwidget);
        modeLabel->setObjectName(QStringLiteral("modeLabel"));
        modeLabel->setGeometry(QRect(127, 110, 101, 16));
        modeLabel->setStyleSheet(QStringLiteral(""));
        modeLabel->setWordWrap(true);
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(200, 100, 20, 301));
        line->setAutoFillBackground(false);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        popUpMenu = new QWidget(centralwidget);
        popUpMenu->setObjectName(QStringLiteral("popUpMenu"));
        popUpMenu->setGeometry(QRect(360, 390, 171, 131));
        poseXLabel = new QLabel(centralwidget);
        poseXLabel->setObjectName(QStringLiteral("poseXLabel"));
        poseXLabel->setGeometry(QRect(127, 330, 61, 16));
        poseXLabel->setStyleSheet(QStringLiteral(""));
        poseLabel = new QLabel(centralwidget);
        poseLabel->setObjectName(QStringLiteral("poseLabel"));
        poseLabel->setGeometry(QRect(127, 310, 61, 16));
        poseLabel->setStyleSheet(QStringLiteral(""));
        poseYLabel = new QLabel(centralwidget);
        poseYLabel->setObjectName(QStringLiteral("poseYLabel"));
        poseYLabel->setGeometry(QRect(127, 350, 61, 16));
        poseYLabel->setStyleSheet(QStringLiteral(""));
        poseZLabel = new QLabel(centralwidget);
        poseZLabel->setObjectName(QStringLiteral("poseZLabel"));
        poseZLabel->setGeometry(QRect(127, 370, 61, 16));
        poseZLabel->setStyleSheet(QStringLiteral(""));
        fluxLabel = new QLabel(centralwidget);
        fluxLabel->setObjectName(QStringLiteral("fluxLabel"));
        fluxLabel->setGeometry(QRect(130, 410, 61, 16));
        fluxLabel->setStyleSheet(QStringLiteral(""));
        fluxZLabel = new QLabel(centralwidget);
        fluxZLabel->setObjectName(QStringLiteral("fluxZLabel"));
        fluxZLabel->setGeometry(QRect(130, 470, 61, 16));
        fluxZLabel->setStyleSheet(QStringLiteral(""));
        fluxXLabel = new QLabel(centralwidget);
        fluxXLabel->setObjectName(QStringLiteral("fluxXLabel"));
        fluxXLabel->setGeometry(QRect(130, 430, 61, 16));
        fluxXLabel->setStyleSheet(QStringLiteral(""));
        fluxYLabel = new QLabel(centralwidget);
        fluxYLabel->setObjectName(QStringLiteral("fluxYLabel"));
        fluxYLabel->setGeometry(QRect(130, 450, 61, 16));
        fluxYLabel->setStyleSheet(QStringLiteral(""));
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
        poseXLabel->setText(QString());
        poseLabel->setText(QApplication::translate("SreachMode", "\345\247\277\346\200\201:", nullptr));
        poseYLabel->setText(QString());
        poseZLabel->setText(QString());
        fluxLabel->setText(QApplication::translate("SreachMode", "\344\270\211\350\275\264:", nullptr));
        fluxZLabel->setText(QString());
        fluxXLabel->setText(QString());
        fluxYLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SreachMode: public Ui_SreachMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SREACHMODE_H
