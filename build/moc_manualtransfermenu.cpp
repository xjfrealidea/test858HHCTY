/****************************************************************************
** Meta object code from reading C++ file 'manualtransfermenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../manualtransfermenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manualtransfermenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ManualTransferMenu_t {
    QByteArrayData data[14];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ManualTransferMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ManualTransferMenu_t qt_meta_stringdata_ManualTransferMenu = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ManualTransferMenu"
QT_MOC_LITERAL(1, 19, 9), // "menuClose"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 10), // "reTransfer"
QT_MOC_LITERAL(4, 41, 20), // "changeFileDataWidget"
QT_MOC_LITERAL(5, 62, 17), // "transferMenuStart"
QT_MOC_LITERAL(6, 80, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(7, 103, 12), // "dataTransfer"
QT_MOC_LITERAL(8, 116, 5), // "index"
QT_MOC_LITERAL(9, 122, 7), // "message"
QT_MOC_LITERAL(10, 130, 8), // "mountDev"
QT_MOC_LITERAL(11, 139, 3), // "idx"
QT_MOC_LITERAL(12, 143, 9), // "unmontDev"
QT_MOC_LITERAL(13, 153, 13) // "checkTransfer"

    },
    "ManualTransferMenu\0menuClose\0\0reTransfer\0"
    "changeFileDataWidget\0transferMenuStart\0"
    "on_startButton_clicked\0dataTransfer\0"
    "index\0message\0mountDev\0idx\0unmontDev\0"
    "checkTransfer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManualTransferMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    2,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   65,    2, 0x08 /* Private */,
       5,    0,   66,    2, 0x08 /* Private */,
       6,    0,   67,    2, 0x08 /* Private */,
       7,    2,   68,    2, 0x08 /* Private */,
      10,    1,   73,    2, 0x08 /* Private */,
      12,    1,   76,    2, 0x08 /* Private */,
      13,    3,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    2,    2,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    8,    9,
    QMetaType::Bool, QMetaType::Int,   11,
    QMetaType::Bool, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Int,    8,    9,   11,

       0        // eod
};

void ManualTransferMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ManualTransferMenu *_t = static_cast<ManualTransferMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->menuClose(); break;
        case 1: _t->reTransfer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: { int _r = _t->changeFileDataWidget();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->transferMenuStart(); break;
        case 4: _t->on_startButton_clicked(); break;
        case 5: _t->dataTransfer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: { bool _r = _t->mountDev((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->unmontDev((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->checkTransfer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ManualTransferMenu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ManualTransferMenu::menuClose)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ManualTransferMenu::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ManualTransferMenu::reTransfer)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ManualTransferMenu::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ManualTransferMenu.data,
      qt_meta_data_ManualTransferMenu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ManualTransferMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManualTransferMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ManualTransferMenu.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ManualTransferMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ManualTransferMenu::menuClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ManualTransferMenu::reTransfer(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
