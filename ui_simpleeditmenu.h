/********************************************************************************
** Form generated from reading UI file 'simpleeditmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLEEDITMENU_H
#define UI_SIMPLEEDITMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimpleEditMenu
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QLabel *currentPositionLabel;
    QLabel *currentLineLabel;
    QLabel *currentLineDataLabel;
    QLabel *currentMarkLabel;
    QLabel *currentMarkDataLabel;
    QLabel *lastLineLabel;
    QLabel *lastLineDataLabel;
    QLabel *lastMarkLabel;
    QLabel *lastMarkDataLabel;
    QLabel *deleteLineLabel;
    QLabel *deleteLineDataLabel;
    QPushButton *lastPositionLabel;
    QPushButton *deleteLabel;
    QPushButton *returnLabel;

    void setupUi(QMainWindow *SimpleEditMenu)
    {
        if (SimpleEditMenu->objectName().isEmpty())
            SimpleEditMenu->setObjectName(QString::fromUtf8("SimpleEditMenu"));
        SimpleEditMenu->resize(1024, 576);
        centralwidget = new QWidget(SimpleEditMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(410, 60, 54, 12));
        currentPositionLabel = new QLabel(centralwidget);
        currentPositionLabel->setObjectName(QString::fromUtf8("currentPositionLabel"));
        currentPositionLabel->setGeometry(QRect(410, 110, 54, 26));
        currentLineLabel = new QLabel(centralwidget);
        currentLineLabel->setObjectName(QString::fromUtf8("currentLineLabel"));
        currentLineLabel->setGeometry(QRect(370, 150, 54, 12));
        currentLineDataLabel = new QLabel(centralwidget);
        currentLineDataLabel->setObjectName(QString::fromUtf8("currentLineDataLabel"));
        currentLineDataLabel->setGeometry(QRect(470, 150, 54, 12));
        currentMarkLabel = new QLabel(centralwidget);
        currentMarkLabel->setObjectName(QString::fromUtf8("currentMarkLabel"));
        currentMarkLabel->setGeometry(QRect(370, 180, 54, 12));
        currentMarkDataLabel = new QLabel(centralwidget);
        currentMarkDataLabel->setObjectName(QString::fromUtf8("currentMarkDataLabel"));
        currentMarkDataLabel->setGeometry(QRect(470, 180, 54, 12));
        lastLineLabel = new QLabel(centralwidget);
        lastLineLabel->setObjectName(QString::fromUtf8("lastLineLabel"));
        lastLineLabel->setGeometry(QRect(370, 260, 54, 12));
        lastLineDataLabel = new QLabel(centralwidget);
        lastLineDataLabel->setObjectName(QString::fromUtf8("lastLineDataLabel"));
        lastLineDataLabel->setGeometry(QRect(470, 260, 54, 12));
        lastMarkLabel = new QLabel(centralwidget);
        lastMarkLabel->setObjectName(QString::fromUtf8("lastMarkLabel"));
        lastMarkLabel->setGeometry(QRect(370, 290, 54, 12));
        lastMarkDataLabel = new QLabel(centralwidget);
        lastMarkDataLabel->setObjectName(QString::fromUtf8("lastMarkDataLabel"));
        lastMarkDataLabel->setGeometry(QRect(470, 290, 54, 12));
        deleteLineLabel = new QLabel(centralwidget);
        deleteLineLabel->setObjectName(QString::fromUtf8("deleteLineLabel"));
        deleteLineLabel->setGeometry(QRect(370, 350, 54, 12));
        deleteLineDataLabel = new QLabel(centralwidget);
        deleteLineDataLabel->setObjectName(QString::fromUtf8("deleteLineDataLabel"));
        deleteLineDataLabel->setGeometry(QRect(470, 350, 54, 12));
        lastPositionLabel = new QPushButton(centralwidget);
        lastPositionLabel->setObjectName(QString::fromUtf8("lastPositionLabel"));
        lastPositionLabel->setGeometry(QRect(390, 210, 75, 23));
        lastPositionLabel->setFlat(true);
        deleteLabel = new QPushButton(centralwidget);
        deleteLabel->setObjectName(QString::fromUtf8("deleteLabel"));
        deleteLabel->setGeometry(QRect(390, 310, 75, 23));
        deleteLabel->setFlat(true);
        returnLabel = new QPushButton(centralwidget);
        returnLabel->setObjectName(QString::fromUtf8("returnLabel"));
        returnLabel->setGeometry(QRect(390, 380, 75, 23));
        returnLabel->setFlat(true);
        SimpleEditMenu->setCentralWidget(centralwidget);

        retranslateUi(SimpleEditMenu);

        QMetaObject::connectSlotsByName(SimpleEditMenu);
    } // setupUi

    void retranslateUi(QMainWindow *SimpleEditMenu)
    {
        SimpleEditMenu->setWindowTitle(QApplication::translate("SimpleEditMenu", "MainWindow", nullptr));
        titleLabel->setText(QApplication::translate("SimpleEditMenu", "\347\256\200\345\215\225\350\260\203\346\237\245:\347\274\226\350\276\221\350\217\234\345\215\225", nullptr));
        currentPositionLabel->setText(QApplication::translate("SimpleEditMenu", "\344\270\213\344\270\200\344\270\252\344\275\215\347\275\256:", nullptr));
        currentLineLabel->setText(QApplication::translate("SimpleEditMenu", "Line:", nullptr));
        currentLineDataLabel->setText(QApplication::translate("SimpleEditMenu", "0", nullptr));
        currentMarkLabel->setText(QApplication::translate("SimpleEditMenu", "Mark:", nullptr));
        currentMarkDataLabel->setText(QApplication::translate("SimpleEditMenu", "0", nullptr));
        lastLineLabel->setText(QApplication::translate("SimpleEditMenu", "Line:", nullptr));
        lastLineDataLabel->setText(QApplication::translate("SimpleEditMenu", "0", nullptr));
        lastMarkLabel->setText(QApplication::translate("SimpleEditMenu", "Mark:", nullptr));
        lastMarkDataLabel->setText(QApplication::translate("SimpleEditMenu", "0", nullptr));
        deleteLineLabel->setText(QApplication::translate("SimpleEditMenu", "Line:", nullptr));
        deleteLineDataLabel->setText(QApplication::translate("SimpleEditMenu", "0", nullptr));
        lastPositionLabel->setText(QApplication::translate("SimpleEditMenu", "\345\233\236\345\210\260\346\234\200\345\220\216\344\275\215\347\275\256:", nullptr));
        deleteLabel->setText(QApplication::translate("SimpleEditMenu", "\345\210\240\351\231\244\350\241\214:", nullptr));
        returnLabel->setText(QApplication::translate("SimpleEditMenu", "\350\277\224\345\233\236\350\260\203\346\237\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SimpleEditMenu: public Ui_SimpleEditMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEEDITMENU_H
