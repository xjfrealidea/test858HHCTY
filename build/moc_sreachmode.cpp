/****************************************************************************
** Meta object code from reading C++ file 'sreachmode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sreachmode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sreachmode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SreachMode_t {
    QByteArrayData data[24];
    char stringdata0[237];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SreachMode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SreachMode_t qt_meta_stringdata_SreachMode = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SreachMode"
QT_MOC_LITERAL(1, 11, 9), // "menuClose"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "dataReset"
QT_MOC_LITERAL(4, 32, 10), // "plotChange"
QT_MOC_LITERAL(5, 43, 8), // "changeHz"
QT_MOC_LITERAL(6, 52, 10), // "startAudio"
QT_MOC_LITERAL(7, 63, 9), // "stopAudio"
QT_MOC_LITERAL(8, 73, 10), // "pauseAudio"
QT_MOC_LITERAL(9, 84, 11), // "changeSpeed"
QT_MOC_LITERAL(10, 96, 11), // "sreachStart"
QT_MOC_LITERAL(11, 108, 13), // "setFieldLabel"
QT_MOC_LITERAL(12, 122, 4), // "type"
QT_MOC_LITERAL(13, 127, 5), // "data1"
QT_MOC_LITERAL(14, 133, 5), // "data2"
QT_MOC_LITERAL(15, 139, 3), // "lon"
QT_MOC_LITERAL(16, 143, 3), // "lat"
QT_MOC_LITERAL(17, 147, 16), // "popUpMenuTimeOut"
QT_MOC_LITERAL(18, 164, 5), // "index"
QT_MOC_LITERAL(19, 170, 14), // "reStartTimerOn"
QT_MOC_LITERAL(20, 185, 15), // "reStartTimerOff"
QT_MOC_LITERAL(21, 201, 7), // "reStart"
QT_MOC_LITERAL(22, 209, 14), // "setCenterTrace"
QT_MOC_LITERAL(23, 224, 12) // "setFullScale"

    },
    "SreachMode\0menuClose\0\0dataReset\0"
    "plotChange\0changeHz\0startAudio\0stopAudio\0"
    "pauseAudio\0changeSpeed\0sreachStart\0"
    "setFieldLabel\0type\0data1\0data2\0lon\0"
    "lat\0popUpMenuTimeOut\0index\0reStartTimerOn\0"
    "reStartTimerOff\0reStart\0setCenterTrace\0"
    "setFullScale"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SreachMode[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,
       4,    1,   96,    2, 0x06 /* Public */,
       5,    1,   99,    2, 0x06 /* Public */,
       6,    0,  102,    2, 0x06 /* Public */,
       7,    0,  103,    2, 0x06 /* Public */,
       8,    0,  104,    2, 0x06 /* Public */,
       9,    1,  105,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  108,    2, 0x0a /* Public */,
      11,    5,  109,    2, 0x0a /* Public */,
      17,    1,  120,    2, 0x0a /* Public */,
      19,    1,  123,    2, 0x0a /* Public */,
      20,    0,  126,    2, 0x0a /* Public */,
      21,    0,  127,    2, 0x0a /* Public */,
      22,    0,  128,    2, 0x0a /* Public */,
      23,    0,  129,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,   12,   13,   14,   15,   16,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SreachMode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SreachMode *_t = static_cast<SreachMode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->menuClose(); break;
        case 1: _t->dataReset(); break;
        case 2: _t->plotChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->changeHz((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->startAudio(); break;
        case 5: _t->stopAudio(); break;
        case 6: _t->pauseAudio(); break;
        case 7: _t->changeSpeed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->sreachStart(); break;
        case 9: _t->setFieldLabel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5]))); break;
        case 10: _t->popUpMenuTimeOut((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->reStartTimerOn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->reStartTimerOff(); break;
        case 13: _t->reStart(); break;
        case 14: _t->setCenterTrace(); break;
        case 15: _t->setFullScale(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SreachMode::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SreachMode::menuClose)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SreachMode::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SreachMode::dataReset)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SreachMode::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SreachMode::plotChange)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SreachMode::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SreachMode::changeHz)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (SreachMode::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SreachMode::startAudio)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (SreachMode::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SreachMode::stopAudio)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (SreachMode::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SreachMode::pauseAudio)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (SreachMode::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SreachMode::changeSpeed)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject SreachMode::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SreachMode.data,
      qt_meta_data_SreachMode,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SreachMode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SreachMode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SreachMode.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SreachMode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void SreachMode::menuClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SreachMode::dataReset()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SreachMode::plotChange(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SreachMode::changeHz(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SreachMode::startAudio()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SreachMode::stopAudio()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void SreachMode::pauseAudio()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void SreachMode::changeSpeed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
