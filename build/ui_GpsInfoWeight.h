/********************************************************************************
** Form generated from reading UI file 'GpsInfoWeight.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GPSINFOWEIGHT_H
#define UI_GPSINFOWEIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GpsInfoWeight
{
public:
    QLabel *solstatlabel;
    QLabel *postypelabel;
    QLabel *solstattext;
    QLabel *postypetext;
    QLabel *spacelabel1;
    QLabel *spacelabel2;
    QLabel *lonlabel;
    QLabel *latlabel;
    QLabel *lontext;
    QLabel *lattext;

    void setupUi(QWidget *GpsInfoWeight)
    {
        if (GpsInfoWeight->objectName().isEmpty())
            GpsInfoWeight->setObjectName(QStringLiteral("GpsInfoWeight"));
        GpsInfoWeight->resize(400, 300);
        solstatlabel = new QLabel(GpsInfoWeight);
        solstatlabel->setObjectName(QStringLiteral("solstatlabel"));
        solstatlabel->setGeometry(QRect(20, 90, 72, 15));
        postypelabel = new QLabel(GpsInfoWeight);
        postypelabel->setObjectName(QStringLiteral("postypelabel"));
        postypelabel->setGeometry(QRect(20, 150, 72, 15));
        solstattext = new QLabel(GpsInfoWeight);
        solstattext->setObjectName(QStringLiteral("solstattext"));
        solstattext->setGeometry(QRect(220, 90, 72, 15));
        postypetext = new QLabel(GpsInfoWeight);
        postypetext->setObjectName(QStringLiteral("postypetext"));
        postypetext->setGeometry(QRect(220, 150, 72, 15));
        spacelabel1 = new QLabel(GpsInfoWeight);
        spacelabel1->setObjectName(QStringLiteral("spacelabel1"));
        spacelabel1->setGeometry(QRect(20, 50, 72, 15));
        spacelabel2 = new QLabel(GpsInfoWeight);
        spacelabel2->setObjectName(QStringLiteral("spacelabel2"));
        spacelabel2->setGeometry(QRect(20, 180, 72, 15));
        lonlabel = new QLabel(GpsInfoWeight);
        lonlabel->setObjectName(QStringLiteral("lonlabel"));
        lonlabel->setGeometry(QRect(20, 230, 67, 17));
        latlabel = new QLabel(GpsInfoWeight);
        latlabel->setObjectName(QStringLiteral("latlabel"));
        latlabel->setGeometry(QRect(20, 260, 67, 17));
        lontext = new QLabel(GpsInfoWeight);
        lontext->setObjectName(QStringLiteral("lontext"));
        lontext->setGeometry(QRect(130, 230, 67, 17));
        lattext = new QLabel(GpsInfoWeight);
        lattext->setObjectName(QStringLiteral("lattext"));
        lattext->setGeometry(QRect(130, 260, 67, 17));

        retranslateUi(GpsInfoWeight);

        QMetaObject::connectSlotsByName(GpsInfoWeight);
    } // setupUi

    void retranslateUi(QWidget *GpsInfoWeight)
    {
        GpsInfoWeight->setWindowTitle(QApplication::translate("GpsInfoWeight", "Form", nullptr));
        solstatlabel->setText(QApplication::translate("GpsInfoWeight", "TextLabel", nullptr));
        postypelabel->setText(QApplication::translate("GpsInfoWeight", "TextLabel", nullptr));
        solstattext->setText(QString());
        postypetext->setText(QString());
        spacelabel1->setText(QString());
        spacelabel2->setText(QString());
        lonlabel->setText(QApplication::translate("GpsInfoWeight", "\347\273\217\345\272\246", nullptr));
        latlabel->setText(QApplication::translate("GpsInfoWeight", "\347\272\254\345\272\246", nullptr));
        lontext->setText(QString());
        lattext->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GpsInfoWeight: public Ui_GpsInfoWeight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GPSINFOWEIGHT_H
