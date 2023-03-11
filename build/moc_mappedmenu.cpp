/****************************************************************************
** Meta object code from reading C++ file 'mappedmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mappedmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mappedmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MappedMenu_t {
    QByteArrayData data[15];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MappedMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MappedMenu_t qt_meta_stringdata_MappedMenu = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MappedMenu"
QT_MOC_LITERAL(1, 11, 11), // "changeSpeed"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "menuClose"
QT_MOC_LITERAL(4, 34, 11), // "mappedStart"
QT_MOC_LITERAL(5, 46, 4), // "file"
QT_MOC_LITERAL(6, 51, 4), // "type"
QT_MOC_LITERAL(7, 56, 4), // "line"
QT_MOC_LITERAL(8, 61, 12), // "markposition"
QT_MOC_LITERAL(9, 74, 9), // "direction"
QT_MOC_LITERAL(10, 84, 12), // "startclicked"
QT_MOC_LITERAL(11, 97, 15), // "mappedModeClose"
QT_MOC_LITERAL(12, 113, 15), // "mappedMenuStart"
QT_MOC_LITERAL(13, 129, 15), // "checkFileStatus"
QT_MOC_LITERAL(14, 145, 20) // "changeFileDataWidget"

    },
    "MappedMenu\0changeSpeed\0\0menuClose\0"
    "mappedStart\0file\0type\0line\0markposition\0"
    "direction\0startclicked\0mappedModeClose\0"
    "mappedMenuStart\0checkFileStatus\0"
    "changeFileDataWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MappedMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    0,   57,    2, 0x06 /* Public */,
       4,    5,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   69,    2, 0x08 /* Private */,
      11,    0,   70,    2, 0x08 /* Private */,
      12,    0,   71,    2, 0x08 /* Private */,
      13,    0,   72,    2, 0x08 /* Private */,
      14,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Long, QMetaType::Long, QMetaType::Int,    5,    6,    7,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MappedMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MappedMenu *_t = static_cast<MappedMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeSpeed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->menuClose(); break;
        case 2: _t->mappedStart((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< long(*)>(_a[3])),(*reinterpret_cast< long(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 3: _t->startclicked(); break;
        case 4: _t->mappedModeClose(); break;
        case 5: _t->mappedMenuStart(); break;
        case 6: _t->checkFileStatus(); break;
        case 7: _t->changeFileDataWidget(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MappedMenu::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MappedMenu::changeSpeed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MappedMenu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MappedMenu::menuClose)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MappedMenu::*_t)(int , int , long , long , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MappedMenu::mappedStart)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MappedMenu::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MappedMenu.data,
      qt_meta_data_MappedMenu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MappedMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MappedMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MappedMenu.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MappedMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MappedMenu::changeSpeed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MappedMenu::menuClose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MappedMenu::mappedStart(int _t1, int _t2, long _t3, long _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
