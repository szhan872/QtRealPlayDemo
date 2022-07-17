/****************************************************************************
** Meta object code from reading C++ file 'qtrealplaydemo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qtrealplaydemo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtrealplaydemo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtRealPlayDemo_t {
    QByteArrayData data[12];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtRealPlayDemo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtRealPlayDemo_t qt_meta_stringdata_QtRealPlayDemo = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QtRealPlayDemo"
QT_MOC_LITERAL(1, 15, 13), // "login_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 13), // "start_clicked"
QT_MOC_LITERAL(4, 44, 12), // "draw_clicked"
QT_MOC_LITERAL(5, 57, 12), // "hang_clicked"
QT_MOC_LITERAL(6, 70, 12), // "talk_clicked"
QT_MOC_LITERAL(7, 83, 11), // "startReplay"
QT_MOC_LITERAL(8, 95, 13), // "audioCompress"
QT_MOC_LITERAL(9, 109, 13), // "stopRecording"
QT_MOC_LITERAL(10, 123, 8), // "startMP4"
QT_MOC_LITERAL(11, 132, 7) // "stopMP4"

    },
    "QtRealPlayDemo\0login_clicked\0\0"
    "start_clicked\0draw_clicked\0hang_clicked\0"
    "talk_clicked\0startReplay\0audioCompress\0"
    "stopRecording\0startMP4\0stopMP4"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtRealPlayDemo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
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

void QtRealPlayDemo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtRealPlayDemo *_t = static_cast<QtRealPlayDemo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->login_clicked(); break;
        case 1: _t->start_clicked(); break;
        case 2: _t->draw_clicked(); break;
        case 3: _t->hang_clicked(); break;
        case 4: _t->talk_clicked(); break;
        case 5: _t->startReplay(); break;
        case 6: _t->audioCompress(); break;
        case 7: _t->stopRecording(); break;
        case 8: _t->startMP4(); break;
        case 9: _t->stopMP4(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QtRealPlayDemo::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QtRealPlayDemo.data,
      qt_meta_data_QtRealPlayDemo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtRealPlayDemo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtRealPlayDemo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtRealPlayDemo.stringdata0))
        return static_cast<void*>(const_cast< QtRealPlayDemo*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QtRealPlayDemo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
