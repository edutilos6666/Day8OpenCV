/****************************************************************************
** Meta object code from reading C++ file 'sourcewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../sourcewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sourcewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SourceWidget_t {
    QByteArrayData data[10];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SourceWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SourceWidget_t qt_meta_stringdata_SourceWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SourceWidget"
QT_MOC_LITERAL(1, 13, 8), // "newImage"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 7), // "cv::Mat"
QT_MOC_LITERAL(4, 31, 12), // "videoStarted"
QT_MOC_LITERAL(5, 44, 14), // "videoCompleted"
QT_MOC_LITERAL(6, 59, 12), // "valueChanged"
QT_MOC_LITERAL(7, 72, 13), // "openVideoFile"
QT_MOC_LITERAL(8, 86, 17), // "updateProgressBar"
QT_MOC_LITERAL(9, 104, 1) // "i"

    },
    "SourceWidget\0newImage\0\0cv::Mat\0"
    "videoStarted\0videoCompleted\0valueChanged\0"
    "openVideoFile\0updateProgressBar\0i"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SourceWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,
       5,    0,   48,    2, 0x06 /* Public */,
       6,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   52,    2, 0x0a /* Public */,
       8,    1,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void SourceWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SourceWidget *_t = static_cast<SourceWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newImage((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 1: _t->videoStarted(); break;
        case 2: _t->videoCompleted(); break;
        case 3: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->openVideoFile(); break;
        case 5: _t->updateProgressBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SourceWidget::*_t)(cv::Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SourceWidget::newImage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SourceWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SourceWidget::videoStarted)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SourceWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SourceWidget::videoCompleted)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SourceWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SourceWidget::valueChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject SourceWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SourceWidget.data,
      qt_meta_data_SourceWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SourceWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SourceWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SourceWidget.stringdata0))
        return static_cast<void*>(const_cast< SourceWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SourceWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SourceWidget::newImage(cv::Mat _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SourceWidget::videoStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void SourceWidget::videoCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void SourceWidget::valueChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
