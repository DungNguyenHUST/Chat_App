/****************************************************************************
** Meta object code from reading C++ file 'main.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "main.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChatEngine_t {
    QByteArrayData data[8];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatEngine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatEngine_t qt_meta_stringdata_ChatEngine = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ChatEngine"
QT_MOC_LITERAL(1, 11, 9), // "sendToQml"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "username"
QT_MOC_LITERAL(4, 31, 7), // "message"
QT_MOC_LITERAL(5, 39, 4), // "time"
QT_MOC_LITERAL(6, 44, 6), // "isUser"
QT_MOC_LITERAL(7, 51, 14) // "receiveFromQml"

    },
    "ChatEngine\0sendToQml\0\0username\0message\0"
    "time\0isUser\0receiveFromQml"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatEngine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    3,    4,    5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void ChatEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChatEngine *_t = static_cast<ChatEngine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendToQml((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 1: _t->receiveFromQml((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ChatEngine::*_t)(QString , QString , QString , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChatEngine::sendToQml)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ChatEngine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ChatEngine.data,
      qt_meta_data_ChatEngine,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChatEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChatEngine.stringdata0))
        return static_cast<void*>(const_cast< ChatEngine*>(this));
    return QObject::qt_metacast(_clname);
}

int ChatEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ChatEngine::sendToQml(QString _t1, QString _t2, QString _t3, bool _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_Receiver_t {
    QByteArrayData data[5];
    char stringdata0[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Receiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Receiver_t qt_meta_stringdata_Receiver = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Receiver"
QT_MOC_LITERAL(1, 9, 11), // "messageSend"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 4), // "arg1"
QT_MOC_LITERAL(4, 27, 4) // "arg2"

    },
    "Receiver\0messageSend\0\0arg1\0arg2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Receiver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x4a /* Public | isScriptable */,

 // slots: parameters
    QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,

       0        // eod
};

void Receiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Receiver *_t = static_cast<Receiver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->messageSend((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject Receiver::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Receiver.data,
      qt_meta_data_Receiver,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Receiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Receiver::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Receiver.stringdata0))
        return static_cast<void*>(const_cast< Receiver*>(this));
    return QObject::qt_metacast(_clname);
}

int Receiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
