/****************************************************************************
** Meta object code from reading C++ file 'recognizer.h'
**
** Created: Thu Jun 3 11:48:37 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../recognizer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recognizer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Recognizer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      66,   61,   11,   11, 0x08,
      95,   11,   11,   11, 0x08,
     124,   11,   11,   11, 0x08,
     150,   11,   11,   11, 0x08,
     175,   11,   11,   11, 0x08,
     217,   11,   11,   11, 0x08,
     251,   11,   11,   11, 0x08,
     262,   11,   11,   11, 0x08,
     284,   11,   11,   11, 0x08,
     314,  305,   11,   11, 0x08,
     349,  340,   11,   11, 0x08,
     379,  375,   11,   11, 0x08,
     400,   11,   11,   11, 0x08,
     447,  430,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Recognizer[] = {
    "Recognizer\0\0NO,answer,isMbk\0"
    "sendAnswer(QString,QString,bool)\0sock\0"
    "on_connected(SocketManager*)\0"
    "on_loginResult(eLoginResult)\0"
    "on_m_online_toggled(bool)\0"
    "on_m_leave_toggled(bool)\0"
    "on_m_saveMBKPositionPix_stateChanged(int)\0"
    "on_m_saveYZMPix_stateChanged(int)\0"
    "on_timer()\0on_m_logout_clicked()\0"
    "on_m_login_clicked()\0mbkImage\0"
    "displayMbkImage(MbkImage)\0yzmImage\0"
    "displayYzmImage(YzmImage)\0msg\0"
    "showMessage(QString)\0on_submitPushButton_clicked()\0"
    "current,previous\0"
    "currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)\0"
};

const QMetaObject Recognizer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Recognizer,
      qt_meta_data_Recognizer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Recognizer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Recognizer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Recognizer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Recognizer))
        return static_cast<void*>(const_cast< Recognizer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Recognizer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendAnswer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: on_connected((*reinterpret_cast< SocketManager*(*)>(_a[1]))); break;
        case 2: on_loginResult((*reinterpret_cast< eLoginResult(*)>(_a[1]))); break;
        case 3: on_m_online_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: on_m_leave_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: on_m_saveMBKPositionPix_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: on_m_saveYZMPix_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: on_timer(); break;
        case 8: on_m_logout_clicked(); break;
        case 9: on_m_login_clicked(); break;
        case 10: displayMbkImage((*reinterpret_cast< const MbkImage(*)>(_a[1]))); break;
        case 11: displayYzmImage((*reinterpret_cast< const YzmImage(*)>(_a[1]))); break;
        case 12: showMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: on_submitPushButton_clicked(); break;
        case 14: currentItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Recognizer::sendAnswer(QString _t1, QString _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
