/********************************************************************************
** Form generated from reading UI file 'mappedmode.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPPEDMODE_H
#define UI_MAPPEDMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MappedMode
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

    void setupUi(QMainWindow *MappedMode)
    {
        if (MappedMode->objectName().isEmpty())
            MappedMode->setObjectName(QString::fromUtf8("MappedMode"));
        MappedMode->resize(1280, 720);
        centralwidget = new QWidget(MappedMode);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        qcDataLabel = new QLabel(centralwidget);
        qcDataLabel->setObjectName(QString::fromUtf8("qcDataLabel"));
        qcDataLabel->setGeometry(QRect(200, 270, 61, 16));
        fieldLabel = new QLabel(centralwidget);
        fieldLabel->setObjectName(QString::fromUtf8("fieldLabel"));
        fieldLabel->setGeometry(QRect(200, 190, 71, 16));
        fieldLabel->setStyleSheet(QString::fromUtf8(""));
        scaleDataLabel = new QLabel(centralwidget);
        scaleDataLabel->setObjectName(QString::fromUtf8("scaleDataLabel"));
        scaleDataLabel->setGeometry(QRect(200, 310, 61, 16));
        qcLabel = new QLabel(centralwidget);
        qcLabel->setObjectName(QString::fromUtf8("qcLabel"));
        qcLabel->setGeometry(QRect(200, 260, 61, 16));
        qcLabel->setStyleSheet(QString::fromUtf8(""));
        modeLabel = new QLabel(centralwidget);
        modeLabel->setObjectName(QString::fromUtf8("modeLabel"));
        modeLabel->setGeometry(QRect(200, 170, 101, 16));
        modeLabel->setStyleSheet(QString::fromUtf8(""));
        modeLabel->setWordWrap(true);
        scaleLabel = new QLabel(centralwidget);
        scaleLabel->setObjectName(QString::fromUtf8("scaleLabel"));
        scaleLabel->setGeometry(QRect(200, 290, 61, 16));
        scaleLabel->setStyleSheet(QString::fromUtf8(""));
        fieldDataLabel = new QLabel(centralwidget);
        fieldDataLabel->setObjectName(QString::fromUtf8("fieldDataLabel"));
        fieldDataLabel->setGeometry(QRect(200, 210, 81, 16));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(273, 160, 20, 301));
        line->setAutoFillBackground(false);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(200, 230, 51, 31));
        statusLabel->setStyleSheet(QString::fromUtf8(""));
        statusLabel->setWordWrap(true);
        lineLabel = new QLabel(centralwidget);
        lineLabel->setObjectName(QString::fromUtf8("lineLabel"));
        lineLabel->setGeometry(QRect(200, 330, 54, 12));
        lineDataLabel = new QLabel(centralwidget);
        lineDataLabel->setObjectName(QString::fromUtf8("lineDataLabel"));
        lineDataLabel->setGeometry(QRect(200, 350, 54, 12));
        markLabel = new QLabel(centralwidget);
        markLabel->setObjectName(QString::fromUtf8("markLabel"));
        markLabel->setGeometry(QRect(200, 370, 54, 12));
        markDataLabel = new QLabel(centralwidget);
        markDataLabel->setObjectName(QString::fromUtf8("markDataLabel"));
        markDataLabel->setGeometry(QRect(200, 390, 54, 12));
        poseLabel = new QLabel(centralwidget);
        poseLabel->setObjectName(QString::fromUtf8("poseLabel"));
        poseLabel->setGeometry(QRect(190, 410, 61, 16));
        poseLabel->setStyleSheet(QString::fromUtf8(""));
        poseXLabel = new QLabel(centralwidget);
        poseXLabel->setObjectName(QString::fromUtf8("poseXLabel"));
        poseXLabel->setGeometry(QRect(190, 430, 61, 16));
        poseXLabel->setStyleSheet(QString::fromUtf8(""));
        poseYLabel = new QLabel(centralwidget);
        poseYLabel->setObjectName(QString::fromUtf8("poseYLabel"));
        poseYLabel->setGeometry(QRect(190, 450, 61, 16));
        poseYLabel->setStyleSheet(QString::fromUtf8(""));
        poseZLabel = new QLabel(centralwidget);
        poseZLabel->setObjectName(QString::fromUtf8("poseZLabel"));
        poseZLabel->setGeometry(QRect(190, 470, 61, 16));
        poseZLabel->setStyleSheet(QString::fromUtf8(""));
        MappedMode->setCentralWidget(centralwidget);

        retranslateUi(MappedMode);

        QMetaObject::connectSlotsByName(MappedMode);
    } // setupUi

    void retranslateUi(QMainWindow *MappedMode)
    {
        MappedMode->setWindowTitle(QApplication::translate("MappedMode", "MainWindow", nullptr));
        qcDataLabel->setText(QString());
        fieldLabel->setText(QApplication::translate("MappedMode", "\350\257\273\346\225\260:", nullptr));
        scaleDataLabel->setText(QApplication::translate("MappedMode", "50", nullptr));
        qcLabel->setText(QApplication::translate("MappedMode", "QC:", nullptr));
        modeLabel->setText(QApplication::translate("MappedMode", "GPS\350\260\203\346\237\245", nullptr));
        scaleLabel->setText(QApplication::translate("MappedMode", "\345\210\273\345\272\246:", nullptr));
        fieldDataLabel->setText(QString());
        statusLabel->setText(QApplication::translate("MappedMode", " !READY! ", nullptr));
        lineLabel->setText(QApplication::translate("MappedMode", "Lon", nullptr));
        lineDataLabel->setText(QApplication::translate("MappedMode", "0", nullptr));
        markLabel->setText(QApplication::translate("MappedMode", "Lat:", nullptr));
        markDataLabel->setText(QApplication::translate("MappedMode", "0", nullptr));
        poseLabel->setText(QApplication::translate("MappedMode", "\345\247\277\346\200\201:", nullptr));
        poseXLabel->setText(QString());
        poseYLabel->setText(QString());
        poseZLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MappedMode: public Ui_MappedMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPPEDMODE_H
