/********************************************************************************
** Form generated from reading UI file 'drawmode.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWMODE_H
#define UI_DRAWMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawMode
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

    void setupUi(QMainWindow *DrawMode)
    {
        if (DrawMode->objectName().isEmpty())
            DrawMode->setObjectName(QString::fromUtf8("DrawMode"));
        DrawMode->resize(1024, 576);
        centralwidget = new QWidget(DrawMode);
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
        poseLabel->setGeometry(QRect(200, 410, 61, 16));
        poseLabel->setStyleSheet(QString::fromUtf8(""));
        poseXLabel = new QLabel(centralwidget);
        poseXLabel->setObjectName(QString::fromUtf8("poseXLabel"));
        poseXLabel->setGeometry(QRect(200, 430, 61, 16));
        poseXLabel->setStyleSheet(QString::fromUtf8(""));
        poseYLabel = new QLabel(centralwidget);
        poseYLabel->setObjectName(QString::fromUtf8("poseYLabel"));
        poseYLabel->setGeometry(QRect(200, 450, 61, 16));
        poseYLabel->setStyleSheet(QString::fromUtf8(""));
        poseZLabel = new QLabel(centralwidget);
        poseZLabel->setObjectName(QString::fromUtf8("poseZLabel"));
        poseZLabel->setGeometry(QRect(200, 470, 61, 16));
        poseZLabel->setStyleSheet(QString::fromUtf8(""));
        fluxXLabel = new QLabel(centralwidget);
        fluxXLabel->setObjectName(QString::fromUtf8("fluxXLabel"));
        fluxXLabel->setGeometry(QRect(200, 520, 61, 16));
        fluxXLabel->setStyleSheet(QString::fromUtf8(""));
        fluxYLabel = new QLabel(centralwidget);
        fluxYLabel->setObjectName(QString::fromUtf8("fluxYLabel"));
        fluxYLabel->setGeometry(QRect(200, 540, 61, 16));
        fluxYLabel->setStyleSheet(QString::fromUtf8(""));
        fluxLabel = new QLabel(centralwidget);
        fluxLabel->setObjectName(QString::fromUtf8("fluxLabel"));
        fluxLabel->setGeometry(QRect(200, 500, 61, 16));
        fluxLabel->setStyleSheet(QString::fromUtf8(""));
        fluxZLabel = new QLabel(centralwidget);
        fluxZLabel->setObjectName(QString::fromUtf8("fluxZLabel"));
        fluxZLabel->setGeometry(QRect(200, 560, 61, 16));
        fluxZLabel->setStyleSheet(QString::fromUtf8(""));
        DrawMode->setCentralWidget(centralwidget);

        retranslateUi(DrawMode);

        QMetaObject::connectSlotsByName(DrawMode);
    } // setupUi

    void retranslateUi(QMainWindow *DrawMode)
    {
        DrawMode->setWindowTitle(QApplication::translate("DrawMode", "MainWindow", nullptr));
        qcDataLabel->setText(QString());
        fieldLabel->setText(QApplication::translate("DrawMode", "\350\257\273\346\225\260:", nullptr));
        scaleDataLabel->setText(QApplication::translate("DrawMode", "50", nullptr));
        qcLabel->setText(QApplication::translate("DrawMode", "QC:", nullptr));
        modeLabel->setText(QApplication::translate("DrawMode", "\347\273\230\345\233\276\350\260\203\346\237\245", nullptr));
        scaleLabel->setText(QApplication::translate("DrawMode", "\345\210\273\345\272\246:", nullptr));
        fieldDataLabel->setText(QString());
        statusLabel->setText(QApplication::translate("DrawMode", " !READY! ", nullptr));
        lineLabel->setText(QApplication::translate("DrawMode", "X:", nullptr));
        lineDataLabel->setText(QApplication::translate("DrawMode", "0", nullptr));
        markLabel->setText(QApplication::translate("DrawMode", "Y:", nullptr));
        markDataLabel->setText(QApplication::translate("DrawMode", "0", nullptr));
        poseLabel->setText(QApplication::translate("DrawMode", "\345\247\277\346\200\201:", nullptr));
        poseXLabel->setText(QString());
        poseYLabel->setText(QString());
        poseZLabel->setText(QString());
        fluxXLabel->setText(QString());
        fluxYLabel->setText(QString());
        fluxLabel->setText(QApplication::translate("DrawMode", "\344\270\211\350\275\264:", nullptr));
        fluxZLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DrawMode: public Ui_DrawMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWMODE_H
