/****************************************************************************
** Meta object code from reading C++ file 'dataanalyser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dataanalyser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataanalyser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataAnalyser_t {
    QByteArrayData data[13];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataAnalyser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataAnalyser_t qt_meta_stringdata_DataAnalyser = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DataAnalyser"
QT_MOC_LITERAL(1, 13, 13), // "dataCollected"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "fieldData"
QT_MOC_LITERAL(4, 38, 9), // "gpsStatus"
QT_MOC_LITERAL(5, 48, 11), // "changeSpeed"
QT_MOC_LITERAL(6, 60, 2), // "hz"
QT_MOC_LITERAL(7, 63, 12), // "AnalyseData2"
QT_MOC_LITERAL(8, 76, 4), // "data"
QT_MOC_LITERAL(9, 81, 3), // "len"
QT_MOC_LITERAL(10, 85, 12), // "AnalyseData4"
QT_MOC_LITERAL(11, 98, 9), // "dataReset"
QT_MOC_LITERAL(12, 108, 10) // "setHzCount"

    },
    "DataAnalyser\0dataCollected\0\0fieldData\0"
    "gpsStatus\0changeSpeed\0hz\0AnalyseData2\0"
    "data\0len\0AnalyseData4\0dataReset\0"
    "setHzCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataAnalyser[] = {

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
       1,    5,   54,    2, 0x06 /* Public */,
       3,    5,   65,    2, 0x06 /* Public */,
       4,    2,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   81,    2, 0x0a /* Public */,
       7,    2,   84,    2, 0x0a /* Public */,
      10,    1,   89,    2, 0x0a /* Public */,
      11,    0,   92,    2, 0x0a /* Public */,
      12,    1,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Short,    8,    9,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void DataAnalyser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataAnalyser *_t = static_cast<DataAnalyser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataCollected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5]))); break;
        case 1: _t->fieldData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5]))); break;
        case 2: _t->gpsStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->changeSpeed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->AnalyseData2((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< qint16(*)>(_a[2]))); break;
        case 5: _t->AnalyseData4((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: _t->dataReset(); break;
        case 7: _t->setHzCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DataAnalyser::*_t)(int , double , double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAnalyser::dataCollected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DataAnalyser::*_t)(int , double , double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAnalyser::fieldData)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DataAnalyser::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataAnalyser::gpsStatus)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject DataAnalyser::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DataAnalyser.data,
      qt_meta_data_DataAnalyser,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DataAnalyser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataAnalyser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataAnalyser.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataAnalyser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DataAnalyser::dataCollected(int _t1, double _t2, double _t3, double _t4, double _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataAnalyser::fieldData(int _t1, double _t2, double _t3, double _t4, double _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataAnalyser::gpsStatus(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
