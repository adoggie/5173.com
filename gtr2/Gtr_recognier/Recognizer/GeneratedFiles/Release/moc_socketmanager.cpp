/****************************************************************************
** Meta object code from reading C++ file 'socketmanager.h'
**
** Created: Thu May 13 16:12:48 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../socketmanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'socketmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SocketManager[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   15,   14,   14, 0x05,
      49,   40,   14,   14, 0x05,
      84,   75,   14,   14, 0x05,
     115,  110,   14,   14, 0x05,
     143,  141,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     169,   14,   14,   14, 0x08,
     187,  181,   14,   14, 0x08,
     226,   14,   14,   14, 0x08,
     240,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SocketManager[] = {
    "SocketManager\0\0msg\0showMessage(QString)\0"
    "mbkImage\0displayMbkImage(MbkImage)\0"
    "yzmImage\0displayYzmImage(YzmImage)\0"
    "sock\0connected(SocketManager*)\0r\0"
    "loginResult(eLoginResult)\0readyRead()\0"
    "error\0tcpError(QAbstractSocket::SocketError)\0"
    "doConnected()\0doDisconnected()\0"
};

const QMetaObject SocketManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SocketManager,
      qt_meta_data_SocketManager, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SocketManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SocketManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SocketManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SocketManager))
        return static_cast<void*>(const_cast< SocketManager*>(this));
    return QObject::qt_metacast(_clname);
}

int SocketManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: showMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: displayMbkImage((*reinterpret_cast< const MbkImage(*)>(_a[1]))); break;
        case 2: displayYzmImage((*reinterpret_cast< const YzmImage(*)>(_a[1]))); break;
        case 3: connected((*reinterpret_cast< SocketManager*(*)>(_a[1]))); break;
        case 4: loginResult((*reinterpret_cast< eLoginResult(*)>(_a[1]))); break;
        case 5: readyRead(); break;
        case 6: tcpError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: doConnected(); break;
        case 8: doDisconnected(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void SocketManager::showMessage(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SocketManager::displayMbkImage(const MbkImage & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SocketManager::displayYzmImage(const YzmImage & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SocketManager::connected(SocketManager * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SocketManager::loginResult(eLoginResult _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
