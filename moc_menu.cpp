/****************************************************************************
** Meta object code from reading C++ file 'menu.h'
**
** Created: Tue 22. Feb 20:11:48 2022
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "menu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MENU[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x0a,
      24,    5,    5,    5, 0x0a,
      36,    5,    5,    5, 0x0a,
      49,    5,    5,    5, 0x0a,
      65,    5,    5,    5, 0x0a,
      79,    5,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MENU[] = {
    "MENU\0\0agregarContacto()\0cerrarApp()\0"
    "ordenarNom()\0botonCercania()\0botonEstado()\0"
    "botonCaract()\0"
};

void MENU::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MENU *_t = static_cast<MENU *>(_o);
        switch (_id) {
        case 0: _t->agregarContacto(); break;
        case 1: _t->cerrarApp(); break;
        case 2: _t->ordenarNom(); break;
        case 3: _t->botonCercania(); break;
        case 4: _t->botonEstado(); break;
        case 5: _t->botonCaract(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MENU::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MENU::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MENU,
      qt_meta_data_MENU, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MENU::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MENU::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MENU::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MENU))
        return static_cast<void*>(const_cast< MENU*>(this));
    return QWidget::qt_metacast(_clname);
}

int MENU::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
