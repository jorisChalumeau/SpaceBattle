/****************************************************************************
** Meta object code from reading C++ file 'creategamescene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ClientSB/creategamescene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'creategamescene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CreateGameScene_t {
    QByteArrayData data[9];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateGameScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateGameScene_t qt_meta_stringdata_CreateGameScene = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CreateGameScene"
QT_MOC_LITERAL(1, 16, 8), // "editName"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "name"
QT_MOC_LITERAL(4, 31, 13), // "editTimeLimit"
QT_MOC_LITERAL(5, 45, 5), // "index"
QT_MOC_LITERAL(6, 51, 11), // "editViewers"
QT_MOC_LITERAL(7, 63, 6), // "cancel"
QT_MOC_LITERAL(8, 70, 6) // "submit"

    },
    "CreateGameScene\0editName\0\0name\0"
    "editTimeLimit\0index\0editViewers\0cancel\0"
    "submit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateGameScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       6,    1,   45,    2, 0x0a /* Public */,
       7,    0,   48,    2, 0x0a /* Public */,
       8,    0,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CreateGameScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateGameScene *_t = static_cast<CreateGameScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->editName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->editTimeLimit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->editViewers((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->cancel(); break;
        case 4: _t->submit(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CreateGameScene::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateGameScene.data,
      qt_meta_data_CreateGameScene,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CreateGameScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateGameScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CreateGameScene.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CreateGameScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
