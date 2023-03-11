/********************************************************************************
** Form generated from reading UI file 'simplemode.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLEMODE_H
#define UI_SIMPLEMODE_H

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

class Ui_SimpleMode
{
public:
    QWidget *centralwidget;
    QLabel *qcDataLabel;
    QLabel *fieldLabel;
    QLabel *scaleDataLabel;
    QLabel *qcLabel;
    QLabel *modeLabel;
    QLabel *scaleLabel;
    QLabel *fieldDataLabel;
    QFrame *line;
    QLabel *statusLabel;
    QLabel *lineLabel;
    QLabel *lineDataLabel;
    QLabel *markLabel;
    QLabel *markDataLabel;
    QLabel *poseLabel;
    QLabel *poseXLabel;
    QLabel *poseYLabel;
    QLabel *poseZLabel;
    QLabel *fluxXLabel;
    QLabel *fluxYLabel;
    QLabel *fluxLabel;
    QLabel *fluxZLabel;

    void setupUi(QMainWindow *SimpleMode)
    {
        if (SimpleMode->objectName().isEmpty())
            SimpleMode->setObjectName(QStringLiteral("SimpleMode"));
        SimpleMode->resize(1024, 576);
        centralwidget = new QWidget(SimpleMode);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        qcDataLabel = new QLabel(centralwidget);
        qcDataLabel->setObjectName(QStringLiteral("qcDataLabel"));
        qcDataLabel->setGeometry(QRect(200, 270, 61, 16));
        fieldLabel = new QLabel(centralwidget);
        fieldLabel->setObjectName(QStringLiteral("fieldLabel"));
        fieldLabel->setGeometry(QRect(200, 190, 71, 16));
        fieldLabel->setStyleSheet(QStringLiteral(""));
        scaleDataLabel = new QLabel(centralwidget);
        scaleDataLabel->setObjectName(QStringLiteral("scaleDataLabel"));
        scaleDataLabel->setGeometry(QRect(200, 310, 61, 16));
        qcLabel = new QLabel(centralwidget);
        qcLabel->setObjectName(QStringLiteral("qcLabel"));
        qcLabel->setGeometry(QRect(200, 260, 61, 16));
        qcLabel->setStyleSheet(QStringLiteral(""));
        modeLabel = new QLabel(centralwidget);
        modeLabel->setObjectName(QStringLiteral("modeLabel"));
        modeLabel->setGeometry(QRect(200, 170, 101, 16));
        modeLabel->setStyleSheet(QStringLiteral(""));
        modeLabel->setWordWrap(true);
        scaleLabel = new QLabel(centralwidget);
        scaleLabel->setObjectName(QStringLiteral("scaleLabel"));
        scaleLabel->setGeometry(QRect(200, 290, 61, 16));
        scaleLabel->setStyleSheet(QStringLiteral(""));
        fieldDataLabel = new QLabel(centralwidget);
        fieldDataLabel->setObjectName(QStringLiteral("fieldDataLabel"));
        fieldDataLabel->setGeometry(QRect(200, 210, 81, 16));
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(273, 160, 20, 301));
        line->setAutoFillBackground(false);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(200, 230, 51, 31));
        statusLabel->setStyleSheet(QStringLiteral(""));
        statusLabel->setWordWrap(true);
        lineLabel = new QLabel(centralwidget);
        lineLabel->setObjectName(QStringLiteral("lineLabel"));
        lineLabel->setGeometry(QRect(200, 330, 54, 12));
        lineDataLabel = new QLabel(centralwidget);
        lineDataLabel->setObjectName(QStringLiteral("lineDataLabel"));
        lineDataLabel->setGeometry(QRect(200, 350, 54, 12));
        markLabel = new QLabel(centralwidget);
        markLabel->setObjectName(QStringLiteral("markLabel"));
        markLabel->setGeometry(QRect(200, 370, 54, 12));
        markDataLabel = new QLabel(centralwidget);
        markDataLabel->setObjectName(QStringLiteral("markDataLabel"));
        markDataLabel->setGeometry(QRect(200, 390, 54, 12));
        poseLabel = new QLabel(centralwidget);
        poseLabel->setObjectName(QStringLiteral("poseLabel"));
        poseLabel->setGeometry(QRect(200, 410, 61, 16));
        poseLabel->setStyleSheet(QStringLiteral(""));
        poseXLabel = new QLabel(centralwidget);
        poseXLabel->setObjectName(QStringLiteral("poseXLabel"));
        poseXLabel->setGeometry(QRect(200, 430, 61, 16));
        poseXLabel->setStyleSheet(QStringLiteral(""));
        poseYLabel = new QLabel(centralwidget);
        poseYLabel->setObjectName(QStringLiteral("poseYLabel"));
        poseYLabel->setGeometry(QRect(200, 450, 61, 16));
        poseYLabel->setStyleSheet(QStringLiteral(""));
        poseZLabel = new QLabel(centralwidget);
        poseZLabel->setObjectName(QStringLiteral("poseZLabel"));
        poseZLabel->setGeometry(QRect(200, 470, 61, 16));
        poseZLabel->setStyleSheet(QStringLiteral(""));
        fluxXLabel = new QLabel(centralwidget);
        fluxXLabel->setObjectName(QStringLiteral("fluxXLabel"));
        fluxXLabel->setGeometry(QRect(200, 520, 61, 16));
        fluxXLabel->setStyleSheet(QStringLiteral(""));
        fluxYLabel = new QLabel(centralwidget);
        fluxYLabel->setObjectName(QStringLiteral("fluxYLabel"));
        fluxYLabel->setGeometry(QRect(200, 540, 61, 16));
        fluxYLabel->setStyleSheet(QStringLiteral(""));
        fluxLabel = new QLabel(centralwidget);
        fluxLabel->setObjectName(QStringLiteral("fluxLabel"));
        fluxLabel->setGeometry(QRect(200, 500, 61, 16));
        fluxLabel->setStyleSheet(QStringLiteral(""));
        fluxZLabel = new QLabel(centralwidget);
        fluxZLabel->setObjectName(QStringLiteral("fluxZLabel"));
        fluxZLabel->setGeometry(QRect(200, 560, 61, 16));
        fluxZLabel->setStyleSheet(QStringLiteral(""));
        SimpleMode->setCentralWidget(centralwidget);

        retranslateUi(SimpleMode);

        QMetaObject::connectSlotsByName(SimpleMode);
    } // setupUi

    void retranslateUi(QMainWindow *SimpleMode)
    {
        SimpleMode->setWindowTitle(QApplication::translate("SimpleMode", "MainWindow", nullptr));
        qcDataLabel->setText(QString());
        fieldLabel->setText(QApplication::translate("SimpleMode", "\350\257\273\346\225\260:", nullptr));
        scaleDataLabel->setText(QApplication::translate("SimpleMode", "50", nullptr));
        qcLabel->setText(QApplication::translate("SimpleMode", "QC:", nullptr));
        modeLabel->setText(QApplication::translate("SimpleMode", "\347\256\200\345\215\225\350\260\203\346\237\245", nullptr));
        scaleLabel->setText(QApplication::translate("SimpleMode", "\345\210\273\345\272\246:", nullptr));
        fieldDataLabel->setText(QString());
        statusLabel->setText(QApplication::translate("SimpleMode", " !READY! ", nullptr));
        lineLabel->setText(QApplication::translate("SimpleMode", "Line:", nullptr));
        lineDataLabel->setText(QApplication::translate("SimpleMode", "0", nullptr));
        markLabel->setText(QApplication::translate("SimpleMode", "Mark:", nullptr));
        markDataLabel->setText(QApplication::translate("SimpleMode", "0", nullptr));
        poseLabel->setText(QApplication::translate("SimpleMode", "\345\247\277\346\200\201:", nullptr));
        poseXLabel->setText(QString());
        poseYLabel->setText(QString());
        poseZLabel->setText(QString());
        fluxXLabel->setText(QString());
        fluxYLabel->setText(QString());
        fluxLabel->setText(QApplication::translate("SimpleMode", "\344\270\211\350\275\264:", nullptr));
        fluxZLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SimpleMode: public Ui_SimpleMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEMODE_H
