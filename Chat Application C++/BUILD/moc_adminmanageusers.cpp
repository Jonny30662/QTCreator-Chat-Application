/****************************************************************************
** Meta object code from reading C++ file 'adminmanageusers.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SRC/adminmanageusers.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminmanageusers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdminManageUsers_t {
    QByteArrayData data[18];
    char stringdata0[389];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdminManageUsers_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdminManageUsers_t qt_meta_stringdata_AdminManageUsers = {
    {
QT_MOC_LITERAL(0, 0, 16), // "AdminManageUsers"
QT_MOC_LITERAL(1, 17, 16), // "update_date_time"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 26), // "set_accessibility_settings"
QT_MOC_LITERAL(4, 62, 24), // "update_inactivity_status"
QT_MOC_LITERAL(5, 87, 18), // "check_account_type"
QT_MOC_LITERAL(6, 106, 26), // "on_tableWidget_cellClicked"
QT_MOC_LITERAL(7, 133, 3), // "row"
QT_MOC_LITERAL(8, 137, 6), // "column"
QT_MOC_LITERAL(9, 144, 24), // "on_delete_button_clicked"
QT_MOC_LITERAL(10, 169, 23), // "on_reset_button_clicked"
QT_MOC_LITERAL(11, 193, 22), // "on_home_button_clicked"
QT_MOC_LITERAL(12, 216, 30), // "on_manage_users_button_clicked"
QT_MOC_LITERAL(13, 247, 31), // "on_manage_groups_button_clicked"
QT_MOC_LITERAL(14, 279, 29), // "on_manage_mods_button_clicked"
QT_MOC_LITERAL(15, 309, 27), // "on_main_menu_button_clicked"
QT_MOC_LITERAL(16, 337, 24), // "on_logoff_button_clicked"
QT_MOC_LITERAL(17, 362, 26) // "on_shutdown_button_clicked"

    },
    "AdminManageUsers\0update_date_time\0\0"
    "set_accessibility_settings\0"
    "update_inactivity_status\0check_account_type\0"
    "on_tableWidget_cellClicked\0row\0column\0"
    "on_delete_button_clicked\0"
    "on_reset_button_clicked\0on_home_button_clicked\0"
    "on_manage_users_button_clicked\0"
    "on_manage_groups_button_clicked\0"
    "on_manage_mods_button_clicked\0"
    "on_main_menu_button_clicked\0"
    "on_logoff_button_clicked\0"
    "on_shutdown_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminManageUsers[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    2,   88,    2, 0x08 /* Private */,
       9,    0,   93,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    0,   96,    2, 0x08 /* Private */,
      13,    0,   97,    2, 0x08 /* Private */,
      14,    0,   98,    2, 0x08 /* Private */,
      15,    0,   99,    2, 0x08 /* Private */,
      16,    0,  100,    2, 0x08 /* Private */,
      17,    0,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AdminManageUsers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdminManageUsers *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_date_time(); break;
        case 1: _t->set_accessibility_settings(); break;
        case 2: _t->update_inactivity_status(); break;
        case 3: _t->check_account_type(); break;
        case 4: _t->on_tableWidget_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->on_delete_button_clicked(); break;
        case 6: _t->on_reset_button_clicked(); break;
        case 7: _t->on_home_button_clicked(); break;
        case 8: _t->on_manage_users_button_clicked(); break;
        case 9: _t->on_manage_groups_button_clicked(); break;
        case 10: _t->on_manage_mods_button_clicked(); break;
        case 11: _t->on_main_menu_button_clicked(); break;
        case 12: _t->on_logoff_button_clicked(); break;
        case 13: _t->on_shutdown_button_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AdminManageUsers::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_AdminManageUsers.data,
    qt_meta_data_AdminManageUsers,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AdminManageUsers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminManageUsers::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdminManageUsers.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int AdminManageUsers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
