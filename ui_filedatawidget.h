/********************************************************************************
** Form generated from reading UI file 'filedatawidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEDATAWIDGET_H
#define UI_FILEDATAWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileDataWidget
{
public:
    QLabel *TimeLabel;
    QLabel *dateLabel;
    QLabel *xLabel;
    QLabel *yLabel;
    QLabel *startLabel;
    QLabel *endLabel;
    QLabel *startTimeLabal;
    QLabel *startDateLabel;
    QLabel *startXLabel;
    QLabel *startYLabel;
    QLabel *endTimeLabel;
    QLabel *endDateLabel;
    QLabel *endXLabel;
    QLabel *endYLabel;
    QLabel *fileSizeLabel;
    QLabel *fileSizeDataLabel;
    QLabel *readingsLabel;
    QLabel *readingsDataLabel;

    void setupUi(QWidget *FileDataWidget)
    {
        if (FileDataWidget->objectName().isEmpty())
            FileDataWidget->setObjectName(QString::fromUtf8("FileDataWidget"));
        FileDataWidget->resize(647, 232);
        TimeLabel = new QLabel(FileDataWidget);
        TimeLabel->setObjectName(QString::fromUtf8("TimeLabel"));
        TimeLabel->setGeometry(QRect(5, 30, 101, 31));
        TimeLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        dateLabel = new QLabel(FileDataWidget);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        dateLabel->setGeometry(QRect(5, 61, 101, 31));
        dateLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        xLabel = new QLabel(FileDataWidget);
        xLabel->setObjectName(QString::fromUtf8("xLabel"));
        xLabel->setGeometry(QRect(5, 91, 101, 31));
        xLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        yLabel = new QLabel(FileDataWidget);
        yLabel->setObjectName(QString::fromUtf8("yLabel"));
        yLabel->setGeometry(QRect(5, 121, 101, 31));
        yLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        startLabel = new QLabel(FileDataWidget);
        startLabel->setObjectName(QString::fromUtf8("startLabel"));
        startLabel->setGeometry(QRect(158, -2, 111, 31));
        startLabel->setAlignment(Qt::AlignCenter);
        endLabel = new QLabel(FileDataWidget);
        endLabel->setObjectName(QString::fromUtf8("endLabel"));
        endLabel->setGeometry(QRect(356, -2, 111, 31));
        endLabel->setAlignment(Qt::AlignCenter);
        startTimeLabal = new QLabel(FileDataWidget);
        startTimeLabal->setObjectName(QString::fromUtf8("startTimeLabal"));
        startTimeLabal->setGeometry(QRect(128, 31, 171, 31));
        startTimeLabal->setAlignment(Qt::AlignCenter);
        startDateLabel = new QLabel(FileDataWidget);
        startDateLabel->setObjectName(QString::fromUtf8("startDateLabel"));
        startDateLabel->setGeometry(QRect(128, 61, 171, 31));
        startDateLabel->setAlignment(Qt::AlignCenter);
        startXLabel = new QLabel(FileDataWidget);
        startXLabel->setObjectName(QString::fromUtf8("startXLabel"));
        startXLabel->setGeometry(QRect(98, 91, 211, 31));
        startXLabel->setAlignment(Qt::AlignCenter);
        startYLabel = new QLabel(FileDataWidget);
        startYLabel->setObjectName(QString::fromUtf8("startYLabel"));
        startYLabel->setGeometry(QRect(98, 121, 211, 31));
        startYLabel->setAlignment(Qt::AlignCenter);
        endTimeLabel = new QLabel(FileDataWidget);
        endTimeLabel->setObjectName(QString::fromUtf8("endTimeLabel"));
        endTimeLabel->setGeometry(QRect(326, 31, 171, 31));
        endTimeLabel->setAlignment(Qt::AlignCenter);
        endDateLabel = new QLabel(FileDataWidget);
        endDateLabel->setObjectName(QString::fromUtf8("endDateLabel"));
        endDateLabel->setGeometry(QRect(326, 61, 171, 31));
        endDateLabel->setAlignment(Qt::AlignCenter);
        endXLabel = new QLabel(FileDataWidget);
        endXLabel->setObjectName(QString::fromUtf8("endXLabel"));
        endXLabel->setGeometry(QRect(316, 91, 211, 31));
        endXLabel->setAlignment(Qt::AlignCenter);
        endYLabel = new QLabel(FileDataWidget);
        endYLabel->setObjectName(QString::fromUtf8("endYLabel"));
        endYLabel->setGeometry(QRect(316, 121, 211, 31));
        endYLabel->setAlignment(Qt::AlignCenter);
        fileSizeLabel = new QLabel(FileDataWidget);
        fileSizeLabel->setObjectName(QString::fromUtf8("fileSizeLabel"));
        fileSizeLabel->setGeometry(QRect(5, 153, 141, 51));
        fileSizeLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        fileSizeDataLabel = new QLabel(FileDataWidget);
        fileSizeDataLabel->setObjectName(QString::fromUtf8("fileSizeDataLabel"));
        fileSizeDataLabel->setGeometry(QRect(155, 154, 131, 51));
        fileSizeDataLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        readingsLabel = new QLabel(FileDataWidget);
        readingsLabel->setObjectName(QString::fromUtf8("readingsLabel"));
        readingsLabel->setGeometry(QRect(292, 153, 121, 51));
        readingsLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        readingsDataLabel = new QLabel(FileDataWidget);
        readingsDataLabel->setObjectName(QString::fromUtf8("readingsDataLabel"));
        readingsDataLabel->setGeometry(QRect(382, 154, 151, 51));
        readingsDataLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        retranslateUi(FileDataWidget);

        QMetaObject::connectSlotsByName(FileDataWidget);
    } // setupUi

    void retranslateUi(QWidget *FileDataWidget)
    {
        FileDataWidget->setWindowTitle(QApplication::translate("FileDataWidget", "Form", nullptr));
        TimeLabel->setText(QApplication::translate("FileDataWidget", "\346\227\266\351\227\264", nullptr));
        dateLabel->setText(QApplication::translate("FileDataWidget", "\346\227\245\346\234\237", nullptr));
        xLabel->setText(QString());
        yLabel->setText(QString());
        startLabel->setText(QApplication::translate("FileDataWidget", "\350\265\267\347\202\271", nullptr));
        endLabel->setText(QApplication::translate("FileDataWidget", "\347\273\210\347\202\271", nullptr));
        startTimeLabal->setText(QString());
        startDateLabel->setText(QString());
        startXLabel->setText(QString());
        startYLabel->setText(QString());
        endTimeLabel->setText(QString());
        endDateLabel->setText(QString());
        endXLabel->setText(QString());
        endYLabel->setText(QString());
        fileSizeLabel->setText(QApplication::translate("FileDataWidget", "\345\244\247\345\260\217:", nullptr));
        fileSizeDataLabel->setText(QString());
        readingsLabel->setText(QApplication::translate("FileDataWidget", "\350\257\273\346\225\260:", nullptr));
        readingsDataLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FileDataWidget: public Ui_FileDataWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEDATAWIDGET_H
