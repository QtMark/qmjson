#include <QtTest/QtTest>

#include <qmjson.h>
#include <qmjsongui.h>

class TestJson: public QObject
{
    Q_OBJECT

private slots:

    virtual void QMJsonValue_create(void);
    virtual void QMJsonValue_file(void);
    virtual void QMJsonValue_sort(void);
    virtual void QMJsonValue_bool(void);
    virtual void QMJsonValue_double(void);
    virtual void QMJsonValue_string(void);
    virtual void QMJsonValue_array(void);
    virtual void QMJsonValue_object(void);
    virtual void QMJsonValue_value(void);
    virtual void QMJsonValue_from(void);

    virtual void QMJsonArray_create(void);
    virtual void QMJsonArray_prepend(void);
    virtual void QMJsonArray_append(void);
    virtual void QMJsonArray_insert(void);
    virtual void QMJsonArray_indexOf(void);
    virtual void QMJsonArray_lastIndexOf(void);
    virtual void QMJsonArray_contains(void);
    virtual void QMJsonArray_unite(void);
    virtual void QMJsonArray_count(void);
    virtual void QMJsonArray_clear(void);
    virtual void QMJsonArray_empty(void);
    virtual void QMJsonArray_with(void);
    virtual void QMJsonArray_remove(void);
    virtual void QMJsonArray_take(void);
    virtual void QMJsonArray_value(void);
    virtual void QMJsonArray_values(void);
    virtual void QMJsonArray_move(void);
    virtual void QMJsonArray_replace(void);
    virtual void QMJsonArray_null(void);
    virtual void QMJsonArray_bool(void);
    virtual void QMJsonArray_double(void);
    virtual void QMJsonArray_string(void);
    virtual void QMJsonArray_array(void);
    virtual void QMJsonArray_object(void);
    virtual void QMJsonArray_custom(void);
    virtual void QMJsonArray_signals(void);

    virtual void QMJsonObject_create(void);
    virtual void QMJsonObject_insert(void);
    virtual void QMJsonObject_unite(void);
    virtual void QMJsonObject_iter(void);
    virtual void QMJsonObject_count(void);
    virtual void QMJsonObject_clear(void);
    virtual void QMJsonObject_empty(void);
    virtual void QMJsonObject_contains(void);
    virtual void QMJsonObject_remove(void);
    virtual void QMJsonObject_key(void);
    virtual void QMJsonObject_value(void);
    virtual void QMJsonObject_keys(void);
    virtual void QMJsonObject_values(void);
    virtual void QMJsonObject_null(void);
    virtual void QMJsonObject_bool(void);
    virtual void QMJsonObject_double(void);
    virtual void QMJsonObject_string(void);
    virtual void QMJsonObject_array(void);
    virtual void QMJsonObject_object(void);
    virtual void QMJsonObject_custom(void);
    virtual void QMJsonObject_signals(void);

    virtual void signaled(void);

private:

    int32_t mCount;
};
