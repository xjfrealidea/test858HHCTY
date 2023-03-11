/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>

#include "digitalclock.h"
#include <QDebug>
#include <QString>

//! [0]
DigitalClock::DigitalClock(QWidget *parent)
    : QLCDNumber(parent)
{
    setSegmentStyle(Filled);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);

    setDigitCount(30);
    //设置显示模式为10进制
    setMode(QLCDNumber::Dec);
//    //设置模型样式
    setSegmentStyle(QLCDNumber::Flat);
//    //设置背景的作用
//    setBackgroundRole(QPalette::Background);

    QString style_Sheet = "DigitalClock{border: 1px solid;"
                          "border-color:qlineargradient(stop:0 rgb(186,237,254),stop:1 rgb(121,220,253));}";
    setStyleSheet(style_Sheet);

}

QString DigitalClock::getCurrentTime()
{
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    QString text(time.toString("hh:mm:ss"));
    text += "/t";
    text += date.toString("dd/MM/yy");
    return  text;
}

void DigitalClock::keyPressEvent(QKeyEvent *event)
{
    if (KEY_ENTER == event->key())
    {
        emit enterPress();
    }
    else if (KEY_UP == event->key() || KEY_DOWN == event->key())
    {
        emit focusOut(event->key());
    }
}

//! [0]

//! [1]
void DigitalClock::showTime()
//! [1] //! [2]
{
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
//    QString text = time.toString("hh:mm");
//    QString text = QString("%1:%2:%3    %4.%5.%6")
//       .arg(time.hour()).arg(time.minute()).arg(time.second())
//       .arg(data.month()).arg(data.day()).arg(data.year());
    QString text(time.toString("hh:mm:ss"));
    text += "/t";
    text += date.toString("dd-MM-yy");
    display(text);
}
//! [2]

