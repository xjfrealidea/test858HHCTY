/****************************************************************************
** Meta object code from reading C++ file 'abstractdatacollector.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../abstractdatacollector.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'abstractdatacollector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AbstractDataCollector_t {
    QByteArrayData data[8];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AbstractDataCollector_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AbstractDataCollector_t qt_meta_stringdata_AbstractDataCollector = {
    {
QT_MOC_LITERAL(0, 0, 21), // "AbstractDataCollector"
QT_MOC_LITERAL(1, 22, 13), // "dataCollected"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 4), // "data"
QT_MOC_LITERAL(4, 42, 2), // "aa"
QT_MOC_LITERAL(5, 45, 9), // "cacheData"
QT_MOC_LITERAL(6, 55, 14), // "portOpenFailed"
QT_MOC_LITERAL(7, 70, 17) // "portOpenSuccessed"

    },
    "AbstractDataCollector\0dataCollected\0"
    "\0data\0aa\0cacheData\0portOpenFailed\0"
    "portOpenSuccessed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AbstractDataCollector[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       5,    2,   39,    2, 0x06 /* Public */,
       6,    1,   44,    2, 0x06 /* Public */,
       7,    0,   47,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Short,    3,    4,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Short,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void AbstractDataCollector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AbstractDataCollector *_t = static_cast<AbstractDataCollector *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataCollected((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< qint16(*)>(_a[2]))); break;
        case 1: _t->cacheData((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< qint16(*)>(_a[2]))); break;
        case 2: _t->portOpenFailed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->portOpenSuccessed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AbstractDataCollector::*_t)(QByteArray , qint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractDataCollector::dataCollected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AbstractDataCollector::*_t)(QByteArray , qint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractDataCollector::cacheData)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AbstractDataCollector::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractDataCollector::portOpenFailed)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (AbstractDataCollector::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractDataCollector::portOpenSuccessed)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject AbstractDataCollector::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AbstractDataCollector.data,
      qt_meta_data_AbstractDataCollector,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AbstractDataCollector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AbstractDataCollector::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AbstractDataCollector.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AbstractDataCollector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AbstractDataCollector::dataCollected(QByteArray _t1, qint16 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AbstractDataCollector::cacheData(QByteArray _t1, qint16 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AbstractDataCollector::portOpenFailed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AbstractDataCollector::portOpenSuccessed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
