/****************************************************************************
** Meta object code from reading C++ file 'upx.h'
**
** Created: Thu Mar 25 12:07:15 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../upx.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'upx.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_upx[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x0a,
      20,    4,    4,    4, 0x0a,
      38,    4,    4,    4, 0x0a,
      53,    4,    4,    4, 0x0a,
      63,    4,    4,    4, 0x0a,
      78,   73,    4,    4, 0x0a,
     109,    4,    4,    4, 0x0a,
     124,    4,    4,    4, 0x0a,
     139,    4,    4,    4, 0x0a,
     149,    4,    4,    4, 0x0a,
     162,    4,    4,    4, 0x0a,
     175,    4,    4,    4, 0x0a,
     188,    4,    4,    4, 0x0a,
     202,    4,    4,    4, 0x0a,
     216,    4,    4,    4, 0x0a,
     233,    4,    4,    4, 0x0a,
     244,    4,    4,    4, 0x0a,
     256,    4,    4,    4, 0x0a,
     272,    4,    4,    4, 0x0a,
     288,    4,    4,    4, 0x0a,
     305,    4,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_upx[] = {
    "upx\0\0addHostGroup()\0updateHostGroup()\0"
    "delHostGroup()\0addHost()\0delHost()\0"
    "item\0groupClicked(QListWidgetItem*)\0"
    "saveSettings()\0saveLog2File()\0addGame()\0"
    "updateGame()\0deleteGame()\0calcGigest()\0"
    "gameRefresh()\0addGameHost()\0"
    "deleteGameHost()\0gameStop()\0gameStart()\0"
    "diffGameFiles()\0syncGameFiles()\0"
    "selectGamePath()\0selectGameItem()\0"
};

const QMetaObject upx::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_upx,
      qt_meta_data_upx, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &upx::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *upx::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *upx::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_upx))
        return static_cast<void*>(const_cast< upx*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int upx::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addHostGroup(); break;
        case 1: updateHostGroup(); break;
        case 2: delHostGroup(); break;
        case 3: addHost(); break;
        case 4: delHost(); break;
        case 5: groupClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: saveSettings(); break;
        case 7: saveLog2File(); break;
        case 8: addGame(); break;
        case 9: updateGame(); break;
        case 10: deleteGame(); break;
        case 11: calcGigest(); break;
        case 12: gameRefresh(); break;
        case 13: addGameHost(); break;
        case 14: deleteGameHost(); break;
        case 15: gameStop(); break;
        case 16: gameStart(); break;
        case 17: diffGameFiles(); break;
        case 18: syncGameFiles(); break;
        case 19: selectGamePath(); break;
        case 20: selectGameItem(); break;
        default: ;
        }
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
