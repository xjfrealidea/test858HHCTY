/****************************************************************************
** Meta object code from reading C++ file 'spectrogramplot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../spectrogramplot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spectrogramplot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SpectrogramPlot_t {
    QByteArrayData data[11];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SpectrogramPlot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SpectrogramPlot_t qt_meta_stringdata_SpectrogramPlot = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SpectrogramPlot"
QT_MOC_LITERAL(1, 16, 11), // "showContour"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 2), // "on"
QT_MOC_LITERAL(4, 32, 15), // "showSpectrogram"
QT_MOC_LITERAL(5, 48, 11), // "setColorMap"
QT_MOC_LITERAL(6, 60, 4), // "type"
QT_MOC_LITERAL(7, 65, 18), // "const QwtInterval*"
QT_MOC_LITERAL(8, 84, 8), // "interval"
QT_MOC_LITERAL(9, 93, 8), // "setAlpha"
QT_MOC_LITERAL(10, 102, 5) // "alpha"

    },
    "SpectrogramPlot\0showContour\0\0on\0"
    "showSpectrogram\0setColorMap\0type\0"
    "const QwtInterval*\0interval\0setAlpha\0"
    "alpha"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpectrogramPlot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       5,    2,   45,    2, 0x0a /* Public */,
       5,    1,   50,    2, 0x2a /* Public | MethodCloned */,
       9,    1,   53,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void SpectrogramPlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SpectrogramPlot *_t = static_cast<SpectrogramPlot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showContour((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->showSpectrogram((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setColorMap((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QwtInterval*(*)>(_a[2]))); break;
        case 3: _t->setColorMap((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setAlpha((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SpectrogramPlot::staticMetaObject = {
    { &QwtPlot::staticMetaObject, qt_meta_stringdata_SpectrogramPlot.data,
      qt_meta_data_SpectrogramPlot,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SpectrogramPlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpectrogramPlot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SpectrogramPlot.stringdata0))
        return static_cast<void*>(this);
    return QwtPlot::qt_metacast(_clname);
}

int SpectrogramPlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
