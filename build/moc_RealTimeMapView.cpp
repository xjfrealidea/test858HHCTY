/****************************************************************************
** Meta object code from reading C++ file 'RealTimeMapView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RealTimeMapView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RealTimeMapView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RealTimeMapView_t {
    QByteArrayData data[19];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RealTimeMapView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RealTimeMapView_t qt_meta_stringdata_RealTimeMapView = {
    {
QT_MOC_LITERAL(0, 0, 15), // "RealTimeMapView"
QT_MOC_LITERAL(1, 16, 6), // "newMap"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "QWidget*"
QT_MOC_LITERAL(4, 33, 1), // "w"
QT_MOC_LITERAL(5, 35, 7), // "mapData"
QT_MOC_LITERAL(6, 43, 11), // "RasterData*"
QT_MOC_LITERAL(7, 55, 4), // "data"
QT_MOC_LITERAL(8, 60, 6), // "format"
QT_MOC_LITERAL(9, 67, 7), // "addData"
QT_MOC_LITERAL(10, 75, 4), // "type"
QT_MOC_LITERAL(11, 80, 4), // "mag1"
QT_MOC_LITERAL(12, 85, 4), // "mag2"
QT_MOC_LITERAL(13, 90, 3), // "lon"
QT_MOC_LITERAL(14, 94, 3), // "lat"
QT_MOC_LITERAL(15, 98, 9), // "onTimeOut"
QT_MOC_LITERAL(16, 108, 10), // "timerStart"
QT_MOC_LITERAL(17, 119, 4), // "msec"
QT_MOC_LITERAL(18, 124, 9) // "timerStop"

    },
    "RealTimeMapView\0newMap\0\0QWidget*\0w\0"
    "mapData\0RasterData*\0data\0format\0addData\0"
    "type\0mag1\0mag2\0lon\0lat\0onTimeOut\0"
    "timerStart\0msec\0timerStop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RealTimeMapView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   60,    2, 0x0a /* Public */,
       9,    5,   61,    2, 0x0a /* Public */,
      15,    0,   72,    2, 0x0a /* Public */,
      16,    1,   73,    2, 0x0a /* Public */,
      16,    0,   76,    2, 0x2a /* Public | MethodCloned */,
      18,    0,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,   10,   11,   12,   13,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RealTimeMapView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RealTimeMapView *_t = static_cast<RealTimeMapView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newMap((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 1: _t->mapData((*reinterpret_cast< RasterData*(*)>(_a[1]))); break;
        case 2: _t->format(); break;
        case 3: _t->addData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5]))); break;
        case 4: _t->onTimeOut(); break;
        case 5: _t->timerStart((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->timerStart(); break;
        case 7: _t->timerStop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RealTimeMapView::*_t)(QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RealTimeMapView::newMap)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RealTimeMapView::*_t)(RasterData * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RealTimeMapView::mapData)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject RealTimeMapView::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RealTimeMapView.data,
      qt_meta_data_RealTimeMapView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RealTimeMapView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RealTimeMapView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RealTimeMapView.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RealTimeMapView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void RealTimeMapView::newMap(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RealTimeMapView::mapData(RasterData * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
