/****************************************************************************
** Meta object code from reading C++ file 'audiooutput.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../audiooutput.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audiooutput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Generator_t {
    QByteArrayData data[1];
    char stringdata0[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Generator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Generator_t qt_meta_stringdata_Generator = {
    {
QT_MOC_LITERAL(0, 0, 9) // "Generator"

    },
    "Generator"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Generator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Generator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Generator::staticMetaObject = {
    { &QIODevice::staticMetaObject, qt_meta_stringdata_Generator.data,
      qt_meta_data_Generator,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Generator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Generator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Generator.stringdata0))
        return static_cast<void*>(this);
    return QIODevice::qt_metacast(_clname);
}

int Generator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QIODevice::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_AudioOutput_t {
    QByteArrayData data[13];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AudioOutput_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AudioOutput_t qt_meta_stringdata_AudioOutput = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AudioOutput"
QT_MOC_LITERAL(1, 12, 17), // "volumeChangedSlot"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "value"
QT_MOC_LITERAL(4, 37, 13), // "hzChangedSlot"
QT_MOC_LITERAL(5, 51, 8), // "changeHz"
QT_MOC_LITERAL(6, 60, 1), // "v"
QT_MOC_LITERAL(7, 62, 11), // "resetVolume"
QT_MOC_LITERAL(8, 74, 7), // "resetHz"
QT_MOC_LITERAL(9, 82, 5), // "start"
QT_MOC_LITERAL(10, 88, 4), // "stop"
QT_MOC_LITERAL(11, 93, 5), // "pause"
QT_MOC_LITERAL(12, 99, 9) // "onTimeOut"

    },
    "AudioOutput\0volumeChangedSlot\0\0value\0"
    "hzChangedSlot\0changeHz\0v\0resetVolume\0"
    "resetHz\0start\0stop\0pause\0onTimeOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AudioOutput[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    1,   62,    2, 0x0a /* Public */,
       5,    1,   65,    2, 0x0a /* Public */,
       7,    1,   68,    2, 0x0a /* Public */,
       8,    1,   71,    2, 0x0a /* Public */,
       9,    0,   74,    2, 0x0a /* Public */,
      10,    0,   75,    2, 0x0a /* Public */,
      11,    0,   76,    2, 0x0a /* Public */,
      12,    0,   77,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::Int,    3,
    QMetaType::Bool, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AudioOutput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AudioOutput *_t = static_cast<AudioOutput *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->volumeChangedSlot((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->hzChangedSlot((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->changeHz((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->resetVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->resetHz((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->start(); break;
        case 6: _t->stop(); break;
        case 7: _t->pause(); break;
        case 8: _t->onTimeOut(); break;
        default: ;
        }
    }
}

const QMetaObject AudioOutput::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AudioOutput.data,
      qt_meta_data_AudioOutput,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AudioOutput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AudioOutput::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AudioOutput.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AudioOutput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
