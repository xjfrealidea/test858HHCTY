/****************************************************************************
** Meta object code from reading C++ file 'EndLineMsgWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../EndLineMsgWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EndLineMsgWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EndLineMsgWindow_t {
    QByteArrayData data[23];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EndLineMsgWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EndLineMsgWindow_t qt_meta_stringdata_EndLineMsgWindow = {
    {
QT_MOC_LITERAL(0, 0, 16), // "EndLineMsgWindow"
QT_MOC_LITERAL(1, 17, 9), // "menuClose"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "setLineAndMark"
QT_MOC_LITERAL(4, 43, 4), // "line"
QT_MOC_LITERAL(5, 48, 4), // "mark"
QT_MOC_LITERAL(6, 53, 9), // "menuStart"
QT_MOC_LITERAL(7, 63, 12), // "gridFilePath"
QT_MOC_LITERAL(8, 76, 4), // "type"
QT_MOC_LITERAL(9, 81, 9), // "setGpsPos"
QT_MOC_LITERAL(10, 91, 3), // "lon"
QT_MOC_LITERAL(11, 95, 3), // "lat"
QT_MOC_LITERAL(12, 99, 9), // "setTextUp"
QT_MOC_LITERAL(13, 109, 6), // "typeUp"
QT_MOC_LITERAL(14, 116, 11), // "setTextDown"
QT_MOC_LITERAL(15, 128, 8), // "typeDown"
QT_MOC_LITERAL(16, 137, 11), // "zoomChanged"
QT_MOC_LITERAL(17, 149, 4), // "rect"
QT_MOC_LITERAL(18, 154, 7), // "markPos"
QT_MOC_LITERAL(19, 162, 1), // "x"
QT_MOC_LITERAL(20, 164, 1), // "y"
QT_MOC_LITERAL(21, 166, 7), // "setMark"
QT_MOC_LITERAL(22, 174, 7) // "initPos"

    },
    "EndLineMsgWindow\0menuClose\0\0setLineAndMark\0"
    "line\0mark\0menuStart\0gridFilePath\0type\0"
    "setGpsPos\0lon\0lat\0setTextUp\0typeUp\0"
    "setTextDown\0typeDown\0zoomChanged\0rect\0"
    "markPos\0x\0y\0setMark\0initPos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EndLineMsgWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   65,    2, 0x0a /* Public */,
       6,    2,   70,    2, 0x0a /* Public */,
       9,    2,   75,    2, 0x0a /* Public */,
      12,    1,   80,    2, 0x0a /* Public */,
      14,    1,   83,    2, 0x0a /* Public */,
      16,    1,   86,    2, 0x0a /* Public */,
      18,    3,   89,    2, 0x0a /* Public */,
      21,    0,   96,    2, 0x0a /* Public */,
      22,    0,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Long, QMetaType::Long,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::Short,    7,    8,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   10,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::QRectF,   17,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Int,   19,   20,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EndLineMsgWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EndLineMsgWindow *_t = static_cast<EndLineMsgWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->menuClose(); break;
        case 1: _t->setLineAndMark((*reinterpret_cast< long(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2]))); break;
        case 2: _t->menuStart((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< short(*)>(_a[2]))); break;
        case 3: _t->setGpsPos((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 4: _t->setTextUp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setTextDown((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->zoomChanged((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        case 7: _t->markPos((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->setMark(); break;
        case 9: _t->initPos(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (EndLineMsgWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EndLineMsgWindow::menuClose)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject EndLineMsgWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_EndLineMsgWindow.data,
      qt_meta_data_EndLineMsgWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EndLineMsgWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EndLineMsgWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EndLineMsgWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int EndLineMsgWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void EndLineMsgWindow::menuClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
