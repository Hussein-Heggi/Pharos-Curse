/****************************************************************************
** Meta object code from reading C++ file 'boss.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../New_Project/boss.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'boss.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_boss_t {
    const uint offsetsAndSize[16];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_boss_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_boss_t qt_meta_stringdata_boss = {
    {
QT_MOC_LITERAL(0, 4), // "boss"
QT_MOC_LITERAL(5, 4), // "move"
QT_MOC_LITERAL(10, 0), // ""
QT_MOC_LITERAL(11, 4), // "find"
QT_MOC_LITERAL(16, 6), // "attack"
QT_MOC_LITERAL(23, 9), // "collision"
QT_MOC_LITERAL(33, 8), // "Defeated"
QT_MOC_LITERAL(42, 5) // "Spawn"

    },
    "boss\0move\0\0find\0attack\0collision\0"
    "Defeated\0Spawn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_boss[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x0a,    1 /* Public */,
       3,    0,   51,    2, 0x0a,    2 /* Public */,
       4,    0,   52,    2, 0x0a,    3 /* Public */,
       5,    0,   53,    2, 0x0a,    4 /* Public */,
       6,    0,   54,    2, 0x0a,    5 /* Public */,
       7,    0,   55,    2, 0x0a,    6 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void boss::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<boss *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->move(); break;
        case 1: _t->find(); break;
        case 2: _t->attack(); break;
        case 3: _t->collision(); break;
        case 4: _t->Defeated(); break;
        case 5: _t->Spawn(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject boss::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_boss.offsetsAndSize,
    qt_meta_data_boss,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_boss_t
, QtPrivate::TypeAndForceComplete<boss, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *boss::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *boss::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_boss.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(this);
    return QObject::qt_metacast(_clname);
}

int boss::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
