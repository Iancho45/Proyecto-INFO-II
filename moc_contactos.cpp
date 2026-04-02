/****************************************************************************
** Meta object code from reading C++ file 'contactos.h'
**
** Created: Tue 22. Feb 20:11:48 2022
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "contactos.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contactos.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CONTACTOS[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      27,   10,   10,   10, 0x0a,
      40,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CONTACTOS[] = {
    "CONTACTOS\0\0BuscarPersona()\0OrdenarCer()\0"
    "OrdenarEst()\0"
};

void CONTACTOS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CONTACTOS *_t = static_cast<CONTACTOS *>(_o);
        switch (_id) {
        case 0: _t->BuscarPersona(); break;
        case 1: _t->OrdenarCer(); break;
        case 2: _t->OrdenarEst(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CONTACTOS::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CONTACTOS::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CONTACTOS,
      qt_meta_data_CONTACTOS, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CONTACTOS::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CONTACTOS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CONTACTOS::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CONTACTOS))
        return static_cast<void*>(const_cast< CONTACTOS*>(this));
    return QWidget::qt_metacast(_clname);
}

int CONTACTOS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
