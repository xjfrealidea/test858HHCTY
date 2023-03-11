/********************************************************************************
** Form generated from reading UI file 'popupmenus.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUPMENUS_H
#define UI_POPUPMENUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PopUpMenus
{
public:
    QFrame *frame;
    QLabel *upLabel;
    QLabel *leftLabel;
    QLabel *rightLabel;
    QLabel *downLabel;
    QLabel *typeLabel;

    void setupUi(QWidget *PopUpMenus)
    {
        if (PopUpMenus->objectName().isEmpty())
            PopUpMenus->setObjectName(QStringLiteral("PopUpMenus"));
        PopUpMenus->resize(400, 300);
        frame = new QFrame(PopUpMenus);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(6, 4, 61, 61));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        upLabel = new QLabel(frame);
        upLabel->setObjectName(QStringLiteral("upLabel"));
        upLabel->setGeometry(QRect(20, 0, 20, 20));
        upLabel->setAlignment(Qt::AlignCenter);
        leftLabel = new QLabel(frame);
        leftLabel->setObjectName(QStringLiteral("leftLabel"));
        leftLabel->setGeometry(QRect(0, 20, 20, 20));
        leftLabel->setAlignment(Qt::AlignCenter);
        rightLabel = new QLabel(frame);
        rightLabel->setObjectName(QStringLiteral("rightLabel"));
        rightLabel->setGeometry(QRect(40, 20, 20, 20));
        rightLabel->setAlignment(Qt::AlignCenter);
        downLabel = new QLabel(frame);
        downLabel->setObjectName(QStringLiteral("downLabel"));
        downLabel->setGeometry(QRect(20, 40, 20, 20));
        downLabel->setAlignment(Qt::AlignCenter);
        typeLabel = new QLabel(frame);
        typeLabel->setObjectName(QStringLiteral("typeLabel"));
        typeLabel->setGeometry(QRect(20, 20, 20, 20));
        typeLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(PopUpMenus);

        QMetaObject::connectSlotsByName(PopUpMenus);
    } // setupUi

    void retranslateUi(QWidget *PopUpMenus)
    {
        PopUpMenus->setWindowTitle(QApplication::translate("PopUpMenus", "Form", nullptr));
        upLabel->setText(QApplication::translate("PopUpMenus", "\342\226\262", nullptr));
        leftLabel->setText(QApplication::translate("PopUpMenus", "\342\227\200", nullptr));
        rightLabel->setText(QApplication::translate("PopUpMenus", "\342\226\266", nullptr));
        downLabel->setText(QApplication::translate("PopUpMenus", "\342\226\274", nullptr));
        typeLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PopUpMenus: public Ui_PopUpMenus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUPMENUS_H
