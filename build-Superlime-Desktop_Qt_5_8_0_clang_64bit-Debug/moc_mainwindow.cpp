/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[426];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "closeEvent"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "QCloseEvent*"
QT_MOC_LITERAL(4, 36, 5), // "event"
QT_MOC_LITERAL(5, 42, 13), // "isTextChanged"
QT_MOC_LITERAL(6, 56, 28), // "on_action_New_File_triggered"
QT_MOC_LITERAL(7, 85, 24), // "on_action_Copy_triggered"
QT_MOC_LITERAL(8, 110, 25), // "on_action_Paste_triggered"
QT_MOC_LITERAL(9, 136, 23), // "on_action_Cut_triggered"
QT_MOC_LITERAL(10, 160, 24), // "on_action_Undo_triggered"
QT_MOC_LITERAL(11, 185, 24), // "on_action_Redo_triggered"
QT_MOC_LITERAL(12, 210, 28), // "on_actionOpen_File_triggered"
QT_MOC_LITERAL(13, 239, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(14, 263, 26), // "on_actionSave_As_triggered"
QT_MOC_LITERAL(15, 290, 25), // "on_treeView_doubleClicked"
QT_MOC_LITERAL(16, 316, 5), // "index"
QT_MOC_LITERAL(17, 322, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(18, 347, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(19, 371, 26), // "on_actionZoom_In_triggered"
QT_MOC_LITERAL(20, 398, 27) // "on_actionZoom_Out_triggered"

    },
    "MainWindow\0closeEvent\0\0QCloseEvent*\0"
    "event\0isTextChanged\0on_action_New_File_triggered\0"
    "on_action_Copy_triggered\0"
    "on_action_Paste_triggered\0"
    "on_action_Cut_triggered\0"
    "on_action_Undo_triggered\0"
    "on_action_Redo_triggered\0"
    "on_actionOpen_File_triggered\0"
    "on_actionSave_triggered\0"
    "on_actionSave_As_triggered\0"
    "on_treeView_doubleClicked\0index\0"
    "on_actionClose_triggered\0"
    "on_actionExit_triggered\0"
    "on_actionZoom_In_triggered\0"
    "on_actionZoom_Out_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    1,  107,    2, 0x08 /* Private */,
      17,    0,  110,    2, 0x08 /* Private */,
      18,    0,  111,    2, 0x08 /* Private */,
      19,    0,  112,    2, 0x08 /* Private */,
      20,    0,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
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
    QMetaType::Void, QMetaType::QModelIndex,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 1: _t->isTextChanged(); break;
        case 2: _t->on_action_New_File_triggered(); break;
        case 3: _t->on_action_Copy_triggered(); break;
        case 4: _t->on_action_Paste_triggered(); break;
        case 5: _t->on_action_Cut_triggered(); break;
        case 6: _t->on_action_Undo_triggered(); break;
        case 7: _t->on_action_Redo_triggered(); break;
        case 8: _t->on_actionOpen_File_triggered(); break;
        case 9: _t->on_actionSave_triggered(); break;
        case 10: _t->on_actionSave_As_triggered(); break;
        case 11: _t->on_treeView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 12: _t->on_actionClose_triggered(); break;
        case 13: _t->on_actionExit_triggered(); break;
        case 14: _t->on_actionZoom_In_triggered(); break;
        case 15: _t->on_actionZoom_Out_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
