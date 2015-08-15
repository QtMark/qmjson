#include <QtTest/QtTest>

#include <qmjson.h>
#include <qmjsongui.h>

class TestJson: public QObject
{
    Q_OBJECT

private slots:

    virtual void QMJsonValue_create(void);

    virtual void QMJsonArray_create(void);
    virtual void QMJsonArray_prepend(void);
    virtual void QMJsonArray_append(void);
    virtual void QMJsonArray_insert(void);
    virtual void QMJsonArray_indexOf(void);
    virtual void QMJsonArray_lastIndexOf(void);
    virtual void QMJsonArray_contains(void);
    virtual void QMJsonArray_removeAll(void);

    virtual void QMJsonObject_create(void);
    virtual void QMJsonObject_insert(void);
    virtual void QMJsonObject_remove(void);
};
