/********************************************************************************
** Form generated from reading UI file 'RealTimeMapView.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REALTIMEMAPVIEW_H
#define UI_REALTIMEMAPVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RealTimeMapView
{
public:

    void setupUi(QWidget *RealTimeMapView)
    {
        if (RealTimeMapView->objectName().isEmpty())
            RealTimeMapView->setObjectName(QStringLiteral("RealTimeMapView"));
        RealTimeMapView->resize(400, 300);

        retranslateUi(RealTimeMapView);

        QMetaObject::connectSlotsByName(RealTimeMapView);
    } // setupUi

    void retranslateUi(QWidget *RealTimeMapView)
    {
        RealTimeMapView->setWindowTitle(QApplication::translate("RealTimeMapView", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RealTimeMapView: public Ui_RealTimeMapView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REALTIMEMAPVIEW_H
