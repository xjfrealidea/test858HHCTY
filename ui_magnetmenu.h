/********************************************************************************
** Form generated from reading UI file 'magnetmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAGNETMENU_H
#define UI_MAGNETMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <digitalclock.h>
#include "timelabel.h"

QT_BEGIN_NAMESPACE

class Ui_MagnetMenu
{
public:
    QWidget *centralwidget;
    TimeLabel *currentTime;
    QPushButton *sreachButton;
    QPushButton *simpleButton;
    QPushButton *mappedButton;
    QPushButton *baseButton;
    QPushButton *reviewButton;
    QPushButton *transferButton;
    QPushButton *setupButton;
    QLabel *titleLabel;
    QLabel *controlHint;
    DigitalClock *lcdTimeLabel;
    QPushButton *drawButton;

    void setupUi(QMainWindow *MagnetMenu)
    {
        if (MagnetMenu->objectName().isEmpty())
            MagnetMenu->setObjectName(QString::fromUtf8("MagnetMenu"));
        MagnetMenu->resize(1024, 576);
        centralwidget = new QWidget(MagnetMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        currentTime = new TimeLabel(centralwidget);
        currentTime->setObjectName(QString::fromUtf8("currentTime"));
        currentTime->setGeometry(QRect(-20, 520, 191, 20));
        currentTime->setStyleSheet(QString::fromUtf8("font: 75 11pt \"\351\273\221\344\275\223\";"));
        currentTime->setAlignment(Qt::AlignCenter);
        sreachButton = new QPushButton(centralwidget);
        sreachButton->setObjectName(QString::fromUtf8("sreachButton"));
        sreachButton->setGeometry(QRect(550, 180, 160, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        sreachButton->setFont(font);
        sreachButton->setFocusPolicy(Qt::StrongFocus);
        sreachButton->setStyleSheet(QString::fromUtf8("font: 75 20pt \"Times New Roman\";"));
        simpleButton = new QPushButton(centralwidget);
        simpleButton->setObjectName(QString::fromUtf8("simpleButton"));
        simpleButton->setGeometry(QRect(560, 280, 160, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(20);
        simpleButton->setFont(font1);
        simpleButton->setFocusPolicy(Qt::StrongFocus);
        mappedButton = new QPushButton(centralwidget);
        mappedButton->setObjectName(QString::fromUtf8("mappedButton"));
        mappedButton->setGeometry(QRect(680, 360, 160, 40));
        mappedButton->setFont(font1);
        mappedButton->setFocusPolicy(Qt::StrongFocus);
        baseButton = new QPushButton(centralwidget);
        baseButton->setObjectName(QString::fromUtf8("baseButton"));
        baseButton->setGeometry(QRect(350, 325, 160, 40));
        baseButton->setFont(font1);
        baseButton->setFocusPolicy(Qt::StrongFocus);
        reviewButton = new QPushButton(centralwidget);
        reviewButton->setObjectName(QString::fromUtf8("reviewButton"));
        reviewButton->setGeometry(QRect(540, 430, 160, 40));
        reviewButton->setFont(font1);
        reviewButton->setFocusPolicy(Qt::StrongFocus);
        transferButton = new QPushButton(centralwidget);
        transferButton->setObjectName(QString::fromUtf8("transferButton"));
        transferButton->setGeometry(QRect(380, 470, 160, 40));
        transferButton->setFont(font1);
        transferButton->setFocusPolicy(Qt::StrongFocus);
        setupButton = new QPushButton(centralwidget);
        setupButton->setObjectName(QString::fromUtf8("setupButton"));
        setupButton->setGeometry(QRect(350, 400, 160, 40));
        setupButton->setFont(font1);
        setupButton->setFocusPolicy(Qt::StrongFocus);
        setupButton->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(255, 255, 127);"));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(520, -10, 261, 81));
        titleLabel->setStyleSheet(QString::fromUtf8("font: 75 24pt \"Times New Roman\";\n"
""));
        titleLabel->setAlignment(Qt::AlignCenter);
        controlHint = new QLabel(centralwidget);
        controlHint->setObjectName(QString::fromUtf8("controlHint"));
        controlHint->setGeometry(QRect(480, 50, 331, 141));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(22);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        controlHint->setFont(font2);
        controlHint->setStyleSheet(QString::fromUtf8("font: 75 22pt \"Times New Roman\";"));
        controlHint->setAlignment(Qt::AlignCenter);
        controlHint->setWordWrap(true);
        lcdTimeLabel = new DigitalClock(centralwidget);
        lcdTimeLabel->setObjectName(QString::fromUtf8("lcdTimeLabel"));
        lcdTimeLabel->setGeometry(QRect(100, 190, 300, 50));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lcdTimeLabel->sizePolicy().hasHeightForWidth());
        lcdTimeLabel->setSizePolicy(sizePolicy);
        lcdTimeLabel->setMinimumSize(QSize(300, 50));
        lcdTimeLabel->setMaximumSize(QSize(500, 200));
        QFont font3;
        font3.setPointSize(30);
        lcdTimeLabel->setFont(font3);
        lcdTimeLabel->setFocusPolicy(Qt::StrongFocus);
        drawButton = new QPushButton(centralwidget);
        drawButton->setObjectName(QString::fromUtf8("drawButton"));
        drawButton->setGeometry(QRect(720, 400, 160, 40));
        drawButton->setFont(font1);
        drawButton->setFocusPolicy(Qt::StrongFocus);
        MagnetMenu->setCentralWidget(centralwidget);
        QWidget::setTabOrder(sreachButton, simpleButton);
        QWidget::setTabOrder(simpleButton, drawButton);
        QWidget::setTabOrder(drawButton, mappedButton);
        QWidget::setTabOrder(mappedButton, baseButton);
        QWidget::setTabOrder(baseButton, transferButton);
        QWidget::setTabOrder(transferButton, reviewButton);
        QWidget::setTabOrder(reviewButton, setupButton);
        QWidget::setTabOrder(setupButton, lcdTimeLabel);

        retranslateUi(MagnetMenu);

        QMetaObject::connectSlotsByName(MagnetMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MagnetMenu)
    {
        MagnetMenu->setWindowTitle(QApplication::translate("MagnetMenu", "MainWindow", nullptr));
        currentTime->setText(QApplication::translate("MagnetMenu", "1234567890", nullptr));
        sreachButton->setText(QApplication::translate("MagnetMenu", "\346\220\234\347\264\242\346\250\241\345\274\217", nullptr));
        simpleButton->setText(QApplication::translate("MagnetMenu", "\347\256\200\345\215\225\350\260\203\346\237\245\346\250\241\345\274\217", nullptr));
        mappedButton->setText(QApplication::translate("MagnetMenu", "\345\267\256\345\210\206\345\256\232\344\275\215\346\250\241\345\274\217", nullptr));
        baseButton->setText(QApplication::translate("MagnetMenu", "base station", nullptr));
        reviewButton->setText(QApplication::translate("MagnetMenu", "data review", nullptr));
        transferButton->setText(QApplication::translate("MagnetMenu", "\346\225\260\346\215\256\347\256\241\347\220\206", nullptr));
        setupButton->setText(QApplication::translate("MagnetMenu", "system setup", nullptr));
        titleLabel->setText(QApplication::translate("MagnetMenu", "MAGNETOMETER", nullptr));
        controlHint->setText(QApplication::translate("MagnetMenu", "Use arrow keys to select desired function.                                                                                                                 Confirm with \"ENTER\"", nullptr));
        drawButton->setText(QApplication::translate("MagnetMenu", "\347\273\230\345\233\276\350\260\203\346\237\245\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MagnetMenu: public Ui_MagnetMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAGNETMENU_H
