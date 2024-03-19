/****************************************************************************
** Meta object code from reading C++ file 'accounts.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SRC/accounts.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'accounts.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Accounts_t {
    QByteArrayData data[20];
    char stringdata0[423];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Accounts_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Accounts_t qt_meta_stringdata_Accounts = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Accounts"
QT_MOC_LITERAL(1, 9, 26), // "set_accessibility_settings"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 24), // "update_inactivity_status"
QT_MOC_LITERAL(4, 62, 16), // "update_date_time"
QT_MOC_LITERAL(5, 79, 18), // "check_account_type"
QT_MOC_LITERAL(6, 98, 10), // "load_users"
QT_MOC_LITERAL(7, 109, 31), // "on_show_users_table_cellClicked"
QT_MOC_LITERAL(8, 141, 3), // "row"
QT_MOC_LITERAL(9, 145, 6), // "column"
QT_MOC_LITERAL(10, 152, 22), // "on_home_button_clicked"
QT_MOC_LITERAL(11, 175, 23), // "on_chats_button_clicked"
QT_MOC_LITERAL(12, 199, 24), // "on_groups_button_clicked"
QT_MOC_LITERAL(13, 224, 26), // "on_accounts_button_clicked"
QT_MOC_LITERAL(14, 251, 26), // "on_settings_button_clicked"
QT_MOC_LITERAL(15, 278, 26), // "on_shutdown_button_clicked"
QT_MOC_LITERAL(16, 305, 30), // "on_manage_users_button_clicked"
QT_MOC_LITERAL(17, 336, 31), // "on_manage_groups_button_clicked"
QT_MOC_LITERAL(18, 368, 29), // "on_manage_mods_button_clicked"
QT_MOC_LITERAL(19, 398, 24) // "on_logoff_button_clicked"

    },
    "Accounts\0set_accessibility_settings\0"
    "\0update_inactivity_status\0update_date_time\0"
    "check_account_type\0load_users\0"
    "on_show_users_table_cellClicked\0row\0"
    "column\0on_home_button_clicked\0"
    "on_chats_button_clicked\0"
    "on_groups_button_clicked\0"
    "on_accounts_button_clicked\0"
    "on_settings_button_clicked\0"
    "on_shutdown_button_clicked\0"
    "on_manage_users_button_clicked\0"
    "on_manage_groups_button_clicked\0"
    "on_manage_mods_button_clicked\0"
    "on_logoff_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Accounts[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    2,   99,    2, 0x08 /* Private */,
      10,    0,  104,    2, 0x08 /* Private */,
      11,    0,  105,    2, 0x08 /* Private */,
      12,    0,  106,    2, 0x08 /* Private */,
      13,    0,  107,    2, 0x08 /* Private */,
      14,    0,  108,    2, 0x08 /* Private */,
      15,    0,  109,    2, 0x08 /* Private */,
      16,    0,  110,    2, 0x08 /* Private */,
      17,    0,  111,    2, 0x08 /* Private */,
      18,    0,  112,    2, 0x08 /* Private */,
      19,    0,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void,
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

void Accounts::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Accounts *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->set_accessibility_settings(); break;
        case 1: _t->update_inactivity_status(); break;
        case 2: _t->update_date_time(); break;
        case 3: _t->check_account_type(); break;
        case 4: _t->load_users(); break;
        case 5: _t->on_show_users_table_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->on_home_button_clicked(); break;
        case 7: _t->on_chats_button_clicked(); break;
        case 8: _t->on_groups_button_clicked(); break;
        case 9: _t->on_accounts_button_clicked(); break;
        case 10: _t->on_settings_button_clicked(); break;
        case 11: _t->on_shutdown_button_clicked(); break;
        case 12: _t->on_manage_users_button_clicked(); break;
        case 13: _t->on_manage_groups_button_clicked(); break;
        case 14: _t->on_manage_mods_button_clicked(); break;
        case 15: _t->on_logoff_button_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Accounts::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Accounts.data,
    qt_meta_data_Accounts,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Accounts::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Accounts::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Accounts.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Accounts::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
