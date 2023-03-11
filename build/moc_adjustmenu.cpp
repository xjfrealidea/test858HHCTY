/****************************************************************************
** Meta object code from reading C++ file 'adjustmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../adjustmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adjustmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdjustMenu_t {
    QByteArrayData data[12];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdjustMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdjustMenu_t qt_meta_stringdata_AdjustMenu = {
    {
QT_MOC_LITERAL(0, 0, 10), // "AdjustMenu"
QT_MOC_LITERAL(1, 11, 9), // "menuClose"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 24), // "editLineMarkLabelClicked"
QT_MOC_LITERAL(4, 47, 23), // "centerTraceLabelClicked"
QT_MOC_LITERAL(5, 71, 19), // "masterVolumeChanged"
QT_MOC_LITERAL(6, 91, 19), // "wooweeVolumeChanged"
QT_MOC_LITERAL(7, 111, 18), // "wooweeLevelChanged"
QT_MOC_LITERAL(8, 130, 13), // "xScaleChanged"
QT_MOC_LITERAL(9, 144, 13), // "yScaleChanged"
QT_MOC_LITERAL(10, 158, 27), // "onEditLineMarkButtonClicked"
QT_MOC_LITERAL(11, 186, 25) // "onResetScaleButtonClicked"

    },
    "AdjustMenu\0menuClose\0\0editLineMarkLabelClicked\0"
    "centerTraceLabelClicked\0masterVolumeChanged\0"
    "wooweeVolumeChanged\0wooweeLevelChanged\0"
    "xScaleChanged\0yScaleChanged\0"
    "onEditLineMarkButtonClicked\0"
    "onResetScaleButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdjustMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    1,   92,    2, 0x06 /* Public */,
       6,    1,   95,    2, 0x06 /* Public */,
       7,    1,   98,    2, 0x06 /* Public */,
       8,    1,  101,    2, 0x06 /* Public */,
       9,    1,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AdjustMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AdjustMenu *_t = static_cast<AdjustMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->menuClose(); break;
        case 1: _t->editLineMarkLabelClicked(); break;
        case 2: _t->centerTraceLabelClicked(); break;
        case 3: _t->masterVolumeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->wooweeVolumeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->wooweeLevelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->xScaleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->yScaleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->masterVolumeChanged(); break;
        case 9: _t->wooweeVolumeChanged(); break;
        case 10: _t->wooweeLevelChanged(); break;
        case 11: _t->xScaleChanged(); break;
        case 12: _t->yScaleChanged(); break;
        case 13: _t->onEditLineMarkButtonClicked(); break;
        case 14: _t->onResetScaleButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AdjustMenu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdjustMenu::menuClose)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AdjustMenu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdjustMenu::editLineMarkLabelClicked)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AdjustMenu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdjustMenu::centerTraceLabelClicked)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (AdjustMenu::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdjustMenu::masterVolumeChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (AdjustMenu::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdjustMenu::wooweeVolumeChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (AdjustMenu::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdjustMenu::wooweeLevelChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (AdjustMenu::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdjustMenu::xScaleChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (AdjustMenu::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdjustMenu::yScaleChanged)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject AdjustMenu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AdjustMenu.data,
      qt_meta_data_AdjustMenu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AdjustMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdjustMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdjustMenu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AdjustMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void AdjustMenu::menuClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AdjustMenu::editLineMarkLabelClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AdjustMenu::centerTraceLabelClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AdjustMenu::masterVolumeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void AdjustMenu::wooweeVolumeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void AdjustMenu::wooweeLevelChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void AdjustMenu::xScaleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void AdjustMenu::yScaleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
