/****************************************************************************
** Meta object code from reading C++ file 'selectionDossier.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../test1/selectionDossier.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectionDossier.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_selectionDossier_t {
    QByteArrayData data[5];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_selectionDossier_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_selectionDossier_t qt_meta_stringdata_selectionDossier = {
    {
QT_MOC_LITERAL(0, 0, 16), // "selectionDossier"
QT_MOC_LITERAL(1, 17, 17), // "enregistrerChemin"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 16), // "ouvrirRepertoire"
QT_MOC_LITERAL(4, 53, 5) // "index"

    },
    "selectionDossier\0enregistrerChemin\0\0"
    "ouvrirRepertoire\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_selectionDossier[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    1,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,

       0        // eod
};

void selectionDossier::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        selectionDossier *_t = static_cast<selectionDossier *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->enregistrerChemin(); break;
        case 1: _t->ouvrirRepertoire((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject selectionDossier::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_selectionDossier.data,
      qt_meta_data_selectionDossier,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *selectionDossier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *selectionDossier::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_selectionDossier.stringdata0))
        return static_cast<void*>(const_cast< selectionDossier*>(this));
    return QWidget::qt_metacast(_clname);
}

int selectionDossier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
