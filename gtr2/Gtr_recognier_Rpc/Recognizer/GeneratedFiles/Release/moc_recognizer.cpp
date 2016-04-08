/****************************************************************************
** Meta object code from reading C++ file 'recognizer.h'
**
** Created: Mon May 24 14:11:21 2010
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
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      61,   11,   11,   11, 0x08,
      72,   11,   11,   11, 0x08,
      94,   11,   11,   11, 0x08,
     119,  115,   11,   11, 0x08,
     140,   11,   11,   11, 0x08,
     187,  170,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Recognizer[] = {
    "Recognizer\0\0NO,answer,isMbk\0"
    "sendAnswer(QString,QString,bool)\0"
    "on_timer()\0on_m_logout_clicked()\0"
    "on_m_login_clicked()\0msg\0showMessage(QString)\0"
    "on_submitPushButton_clicked()\0"
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
        case 1: on_timer(); break;
        case 2: on_m_logout_clicked(); break;
        case 3: on_m_login_clicked(); break;
        case 4: showMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: on_submitPushButton_clicked(); break;
        case 6: currentItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 7;
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
