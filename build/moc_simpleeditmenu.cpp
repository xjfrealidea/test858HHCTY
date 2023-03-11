/****************************************************************************
** Meta object code from reading C++ file 'simpleeditmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../simpleeditmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simpleeditmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SimpleEditMenu_t {
    QByteArrayData data[12];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SimpleEditMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SimpleEditMenu_t qt_meta_stringdata_SimpleEditMenu = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SimpleEditMenu"
QT_MOC_LITERAL(1, 15, 9), // "menuClose"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 15), // "lineMarkChanged"
QT_MOC_LITERAL(4, 42, 14), // "setLineAndMark"
QT_MOC_LITERAL(5, 57, 4), // "line"
QT_MOC_LITERAL(6, 62, 4), // "mark"
QT_MOC_LITERAL(7, 67, 4), // "int*"
QT_MOC_LITERAL(8, 72, 10), // "perLineNum"
QT_MOC_LITERAL(9, 83, 28), // "on_lastPositionLabel_clicked"
QT_MOC_LITERAL(10, 112, 22), // "on_deleteLabel_clicked"
QT_MOC_LITERAL(11, 135, 22) // "on_returnLabel_clicked"

    },
    "SimpleEditMenu\0menuClose\0\0lineMarkChanged\0"
    "setLineAndMark\0line\0mark\0int*\0perLineNum\0"
    "on_lastPositionLabel_clicked\0"
    "on_deleteLabel_clicked\0on_returnLabel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SimpleEditMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    2,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    3,   50,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,
      10,    0,   58,    2, 0x08 /* Private */,
      11,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Long, QMetaType::Long,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Long, QMetaType::Long, 0x80000000 | 7,    5,    6,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SimpleEditMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SimpleEditMenu *_t = static_cast<SimpleEditMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->menuClose(); break;
        case 1: _t->lineMarkChanged((*reinterpret_cast< long(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2]))); break;
        case 2: _t->setLineAndMark((*reinterpret_cast< long(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2])),(*reinterpret_cast< int*(*)>(_a[3]))); break;
        case 3: _t->on_lastPositionLabel_clicked(); break;
        case 4: _t->on_deleteLabel_clicked(); break;
        case 5: _t->on_returnLabel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SimpleEditMenu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimpleEditMenu::menuClose)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SimpleEditMenu::*_t)(long , long );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SimpleEditMenu::lineMarkChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SimpleEditMenu::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SimpleEditMenu.data,
      qt_meta_data_SimpleEditMenu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SimpleEditMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SimpleEditMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SimpleEditMenu.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SimpleEditMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SimpleEditMenu::menuClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SimpleEditMenu::lineMarkChanged(long _t1, long _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
