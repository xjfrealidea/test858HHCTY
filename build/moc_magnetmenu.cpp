/****************************************************************************
** Meta object code from reading C++ file 'magnetmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../magnetmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'magnetmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MagnetMenu_t {
    QByteArrayData data[20];
    char stringdata0[332];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MagnetMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MagnetMenu_t qt_meta_stringdata_MagnetMenu = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MagnetMenu"
QT_MOC_LITERAL(1, 11, 11), // "sreachStart"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 15), // "simpleMenuStart"
QT_MOC_LITERAL(4, 40, 11), // "mappedStart"
QT_MOC_LITERAL(5, 52, 18), // "setMemoryUsedLabel"
QT_MOC_LITERAL(6, 71, 10), // "magnatShow"
QT_MOC_LITERAL(7, 82, 14), // "timeLabelPress"
QT_MOC_LITERAL(8, 97, 17), // "timeLabelFocusOut"
QT_MOC_LITERAL(9, 115, 4), // "type"
QT_MOC_LITERAL(10, 120, 22), // "on_setupButton_clicked"
QT_MOC_LITERAL(11, 143, 15), // "sreachModeClose"
QT_MOC_LITERAL(12, 159, 20), // "systemSetupMenuClose"
QT_MOC_LITERAL(13, 180, 15), // "simpleModeClose"
QT_MOC_LITERAL(14, 196, 21), // "dataTransferMenuClose"
QT_MOC_LITERAL(15, 218, 15), // "mappedModeClose"
QT_MOC_LITERAL(16, 234, 23), // "on_sreachButton_clicked"
QT_MOC_LITERAL(17, 258, 23), // "on_simpleButton_clicked"
QT_MOC_LITERAL(18, 282, 25), // "on_transferButton_clicked"
QT_MOC_LITERAL(19, 308, 23) // "on_mappedButton_clicked"

    },
    "MagnetMenu\0sreachStart\0\0simpleMenuStart\0"
    "mappedStart\0setMemoryUsedLabel\0"
    "magnatShow\0timeLabelPress\0timeLabelFocusOut\0"
    "type\0on_setupButton_clicked\0sreachModeClose\0"
    "systemSetupMenuClose\0simpleModeClose\0"
    "dataTransferMenuClose\0mappedModeClose\0"
    "on_sreachButton_clicked\0on_simpleButton_clicked\0"
    "on_transferButton_clicked\0"
    "on_mappedButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MagnetMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,
       4,    0,  101,    2, 0x06 /* Public */,
       5,    1,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  105,    2, 0x0a /* Public */,
       7,    0,  106,    2, 0x0a /* Public */,
       8,    1,  107,    2, 0x0a /* Public */,
      10,    0,  110,    2, 0x08 /* Private */,
      11,    0,  111,    2, 0x08 /* Private */,
      12,    0,  112,    2, 0x08 /* Private */,
      13,    0,  113,    2, 0x08 /* Private */,
      14,    0,  114,    2, 0x08 /* Private */,
      15,    0,  115,    2, 0x08 /* Private */,
      16,    0,  116,    2, 0x08 /* Private */,
      17,    0,  117,    2, 0x08 /* Private */,
      18,    0,  118,    2, 0x08 /* Private */,
      19,    0,  119,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MagnetMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MagnetMenu *_t = static_cast<MagnetMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sreachStart(); break;
        case 1: _t->simpleMenuStart(); break;
        case 2: _t->mappedStart(); break;
        case 3: _t->setMemoryUsedLabel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->magnatShow(); break;
        case 5: _t->timeLabelPress(); break;
        case 6: _t->timeLabelFocusOut((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_setupButton_clicked(); break;
        case 8: _t->sreachModeClose(); break;
        case 9: _t->systemSetupMenuClose(); break;
        case 10: _t->simpleModeClose(); break;
        case 11: _t->dataTransferMenuClose(); break;
        case 12: _t->mappedModeClose(); break;
        case 13: _t->on_sreachButton_clicked(); break;
        case 14: _t->on_simpleButton_clicked(); break;
        case 15: _t->on_transferButton_clicked(); break;
        case 16: _t->on_mappedButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MagnetMenu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MagnetMenu::sreachStart)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MagnetMenu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MagnetMenu::simpleMenuStart)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MagnetMenu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MagnetMenu::mappedStart)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MagnetMenu::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MagnetMenu::setMemoryUsedLabel)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject MagnetMenu::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MagnetMenu.data,
      qt_meta_data_MagnetMenu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MagnetMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MagnetMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MagnetMenu.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MagnetMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MagnetMenu::sreachStart()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MagnetMenu::simpleMenuStart()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MagnetMenu::mappedStart()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MagnetMenu::setMemoryUsedLabel(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
