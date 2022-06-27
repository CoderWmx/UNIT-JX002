/****************************************************************************
** Meta object code from reading C++ file 'getusbdate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../USB/getusbdate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'getusbdate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GetUSBDate_t {
    QByteArrayData data[10];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GetUSBDate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GetUSBDate_t qt_meta_stringdata_GetUSBDate = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GetUSBDate"
QT_MOC_LITERAL(1, 11, 15), // "SigOutErrorInfo"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "error"
QT_MOC_LITERAL(4, 34, 10), // "SigUSBDate"
QT_MOC_LITERAL(5, 45, 11), // "SigOutImage"
QT_MOC_LITERAL(6, 57, 12), // "SigHistogram"
QT_MOC_LITERAL(7, 70, 6), // "short*"
QT_MOC_LITERAL(8, 77, 14), // "SlotStopthread"
QT_MOC_LITERAL(9, 92, 13) // "SlotGetOneY16"

    },
    "GetUSBDate\0SigOutErrorInfo\0\0error\0"
    "SigUSBDate\0SigOutImage\0SigHistogram\0"
    "short*\0SlotStopthread\0SlotGetOneY16"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GetUSBDate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       5,    1,   50,    2, 0x06 /* Public */,
       6,    2,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   58,    2, 0x0a /* Public */,
       9,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void, QMetaType::QImage, 0x80000000 | 7,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GetUSBDate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GetUSBDate *_t = static_cast<GetUSBDate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SigOutErrorInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->SigUSBDate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->SigOutImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 3: _t->SigHistogram((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< short*(*)>(_a[2]))); break;
        case 4: _t->SlotStopthread(); break;
        case 5: _t->SlotGetOneY16(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GetUSBDate::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GetUSBDate::SigOutErrorInfo)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GetUSBDate::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GetUSBDate::SigUSBDate)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GetUSBDate::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GetUSBDate::SigOutImage)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (GetUSBDate::*_t)(QImage , short * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GetUSBDate::SigHistogram)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject GetUSBDate::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_GetUSBDate.data,
      qt_meta_data_GetUSBDate,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GetUSBDate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GetUSBDate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GetUSBDate.stringdata0))
        return static_cast<void*>(const_cast< GetUSBDate*>(this));
    return QThread::qt_metacast(_clname);
}

int GetUSBDate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void GetUSBDate::SigOutErrorInfo(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GetUSBDate::SigUSBDate(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GetUSBDate::SigOutImage(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GetUSBDate::SigHistogram(QImage _t1, short * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
