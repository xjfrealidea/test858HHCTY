/********************************************************************************
** Form generated from reading UI file 'adjustmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADJUSTMENU_H
#define UI_ADJUSTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdjustMenu
{
public:
    QLabel *masterVolumeLabel;
    QLabel *wooweeLabel;
    QLabel *wooweeVolumeLabel;
    QLabel *wooweeSensitivityLabel;
    QLabel *qcWarningLabel;
    QLabel *qcWarningVolumeLabel;
    QLabel *qcWarningLevelLabel;
    QLabel *fullScaleLabel;
    QLabel *rdngsScreenLabel;
    QLabel *cycleTimeLabel;
    QLabel *wooweeSensitivityUnitLabel;
    QLabel *qcWarningLevelUnitLabel;
    QLabel *fullScaleUnitLabel;
    QLabel *cycleTimeUnitLabel;
    QPushButton *editLineMarkLabel;
    QPushButton *centerTraceLabel;

    void setupUi(QWidget *AdjustMenu)
    {
        if (AdjustMenu->objectName().isEmpty())
            AdjustMenu->setObjectName(QString::fromUtf8("AdjustMenu"));
        AdjustMenu->resize(1000, 576);
        AdjustMenu->setFocusPolicy(Qt::NoFocus);
        masterVolumeLabel = new QLabel(AdjustMenu);
        masterVolumeLabel->setObjectName(QString::fromUtf8("masterVolumeLabel"));
        masterVolumeLabel->setGeometry(QRect(160, 70, 221, 31));
        QFont font;
        font.setPointSize(20);
        masterVolumeLabel->setFont(font);
        masterVolumeLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        wooweeLabel = new QLabel(AdjustMenu);
        wooweeLabel->setObjectName(QString::fromUtf8("wooweeLabel"));
        wooweeLabel->setGeometry(QRect(170, 120, 131, 31));
        wooweeLabel->setFont(font);
        wooweeLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        wooweeVolumeLabel = new QLabel(AdjustMenu);
        wooweeVolumeLabel->setObjectName(QString::fromUtf8("wooweeVolumeLabel"));
        wooweeVolumeLabel->setGeometry(QRect(190, 150, 161, 31));
        wooweeVolumeLabel->setFont(font);
        wooweeVolumeLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        wooweeSensitivityLabel = new QLabel(AdjustMenu);
        wooweeSensitivityLabel->setObjectName(QString::fromUtf8("wooweeSensitivityLabel"));
        wooweeSensitivityLabel->setGeometry(QRect(190, 170, 181, 31));
        wooweeSensitivityLabel->setFont(font);
        wooweeSensitivityLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        qcWarningLabel = new QLabel(AdjustMenu);
        qcWarningLabel->setObjectName(QString::fromUtf8("qcWarningLabel"));
        qcWarningLabel->setGeometry(QRect(170, 210, 151, 31));
        qcWarningLabel->setFont(font);
        qcWarningLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        qcWarningVolumeLabel = new QLabel(AdjustMenu);
        qcWarningVolumeLabel->setObjectName(QString::fromUtf8("qcWarningVolumeLabel"));
        qcWarningVolumeLabel->setGeometry(QRect(200, 240, 131, 31));
        qcWarningVolumeLabel->setFont(font);
        qcWarningVolumeLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        qcWarningLevelLabel = new QLabel(AdjustMenu);
        qcWarningLevelLabel->setObjectName(QString::fromUtf8("qcWarningLevelLabel"));
        qcWarningLevelLabel->setGeometry(QRect(200, 270, 141, 31));
        qcWarningLevelLabel->setFont(font);
        qcWarningLevelLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        fullScaleLabel = new QLabel(AdjustMenu);
        fullScaleLabel->setObjectName(QString::fromUtf8("fullScaleLabel"));
        fullScaleLabel->setGeometry(QRect(170, 310, 181, 31));
        fullScaleLabel->setFont(font);
        fullScaleLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        rdngsScreenLabel = new QLabel(AdjustMenu);
        rdngsScreenLabel->setObjectName(QString::fromUtf8("rdngsScreenLabel"));
        rdngsScreenLabel->setGeometry(QRect(200, 390, 181, 31));
        rdngsScreenLabel->setFont(font);
        rdngsScreenLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        cycleTimeLabel = new QLabel(AdjustMenu);
        cycleTimeLabel->setObjectName(QString::fromUtf8("cycleTimeLabel"));
        cycleTimeLabel->setGeometry(QRect(212, 430, 171, 31));
        cycleTimeLabel->setFont(font);
        cycleTimeLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        wooweeSensitivityUnitLabel = new QLabel(AdjustMenu);
        wooweeSensitivityUnitLabel->setObjectName(QString::fromUtf8("wooweeSensitivityUnitLabel"));
        wooweeSensitivityUnitLabel->setGeometry(QRect(510, 180, 121, 31));
        wooweeSensitivityUnitLabel->setFont(font);
        wooweeSensitivityUnitLabel->setAlignment(Qt::AlignCenter);
        qcWarningLevelUnitLabel = new QLabel(AdjustMenu);
        qcWarningLevelUnitLabel->setObjectName(QString::fromUtf8("qcWarningLevelUnitLabel"));
        qcWarningLevelUnitLabel->setGeometry(QRect(510, 280, 61, 31));
        qcWarningLevelUnitLabel->setFont(font);
        qcWarningLevelUnitLabel->setAlignment(Qt::AlignCenter);
        fullScaleUnitLabel = new QLabel(AdjustMenu);
        fullScaleUnitLabel->setObjectName(QString::fromUtf8("fullScaleUnitLabel"));
        fullScaleUnitLabel->setGeometry(QRect(510, 320, 61, 31));
        fullScaleUnitLabel->setFont(font);
        fullScaleUnitLabel->setAlignment(Qt::AlignCenter);
        cycleTimeUnitLabel = new QLabel(AdjustMenu);
        cycleTimeUnitLabel->setObjectName(QString::fromUtf8("cycleTimeUnitLabel"));
        cycleTimeUnitLabel->setGeometry(QRect(510, 440, 61, 31));
        cycleTimeUnitLabel->setFont(font);
        cycleTimeUnitLabel->setAlignment(Qt::AlignCenter);
        editLineMarkLabel = new QPushButton(AdjustMenu);
        editLineMarkLabel->setObjectName(QString::fromUtf8("editLineMarkLabel"));
        editLineMarkLabel->setGeometry(QRect(124, 500, 281, 31));
        editLineMarkLabel->setFlat(true);
        centerTraceLabel = new QPushButton(AdjustMenu);
        centerTraceLabel->setObjectName(QString::fromUtf8("centerTraceLabel"));
        centerTraceLabel->setGeometry(QRect(214, 532, 281, 31));
        centerTraceLabel->setFlat(true);

        retranslateUi(AdjustMenu);

        QMetaObject::connectSlotsByName(AdjustMenu);
    } // setupUi

    void retranslateUi(QWidget *AdjustMenu)
    {
        AdjustMenu->setWindowTitle(QApplication::translate("AdjustMenu", "Form", nullptr));
        masterVolumeLabel->setText(QApplication::translate("AdjustMenu", "\344\270\273\351\237\263\351\207\217:    ", nullptr));
        wooweeLabel->setText(QApplication::translate("AdjustMenu", " woowee:       ", nullptr));
        wooweeVolumeLabel->setText(QApplication::translate("AdjustMenu", "  \351\237\263\351\207\217:     ", nullptr));
        wooweeSensitivityLabel->setText(QApplication::translate("AdjustMenu", "  \347\201\265\346\225\217\345\272\246:   ", nullptr));
        qcWarningLabel->setText(QApplication::translate("AdjustMenu", "QC \350\255\246\345\221\212:    ", nullptr));
        qcWarningVolumeLabel->setText(QApplication::translate("AdjustMenu", "  \351\237\263\351\207\217:     ", nullptr));
        qcWarningLevelLabel->setText(QApplication::translate("AdjustMenu", "  \347\255\211\347\272\247:     ", nullptr));
        fullScaleLabel->setText(QApplication::translate("AdjustMenu", "\346\273\241\345\210\273\345\272\246:   ", nullptr));
        rdngsScreenLabel->setText(QApplication::translate("AdjustMenu", "\346\257\217\345\261\217\350\257\273\346\225\260: ", nullptr));
        cycleTimeLabel->setText(QApplication::translate("AdjustMenu", "\345\221\250\346\234\237:   ", nullptr));
        wooweeSensitivityUnitLabel->setText(QApplication::translate("AdjustMenu", "Hz/nT", nullptr));
        qcWarningLevelUnitLabel->setText(QApplication::translate("AdjustMenu", "nT", nullptr));
        fullScaleUnitLabel->setText(QApplication::translate("AdjustMenu", "nT", nullptr));
        cycleTimeUnitLabel->setText(QApplication::translate("AdjustMenu", "s", nullptr));
        editLineMarkLabel->setText(QApplication::translate("AdjustMenu", "\347\274\226\350\276\221LINE\344\270\216MARK", nullptr));
        centerTraceLabel->setText(QApplication::translate("AdjustMenu", "\344\270\255\345\277\203\350\277\275\350\270\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdjustMenu: public Ui_AdjustMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADJUSTMENU_H
