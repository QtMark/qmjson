//
// QtMark JSON Library
//
// Copyright (C) 2015 Assured Information Security, Inc.
// Author: Rian Quinn       <quinnr@ainfosec.com>
// Author: Rodney Forbes    <forbesr@ainfosec.com>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#include <QtTest/QtTest>

#ifndef DISABLE_QMJSON_GUI

#include <QtGui>
#include <qmjson.h>
#include <qmjsongui.h>

#else

#include <QtCore>
#include <qmjson.h>

#endif

class TestJson: public QObject
{
    Q_OBJECT

private slots:

    virtual void initTestCase(void);

    virtual void QMJsonValue_create(void);
    virtual void QMJsonValue_file(void);
    virtual void QMJsonValue_sort(void);
    virtual void QMJsonValue_bool(void);
    virtual void QMJsonValue_double(void);
    virtual void QMJsonValue_string(void);
    virtual void QMJsonValue_array(void);
    virtual void QMJsonValue_object(void);
    virtual void QMJsonValue_custom(void);
    virtual void QMJsonValue_value(void);
    virtual void QMJsonValue_from(void);
    virtual void QMJsonValue_variant(void);
    virtual void QMJsonValue_signals(void);
    virtual void QMJsonValue_tofromjson_null(void);
    virtual void QMJsonValue_tofromjson_bool(void);
    virtual void QMJsonValue_tofromjson_double(void);
    virtual void QMJsonValue_tofromjson_string(void);
    virtual void QMJsonValue_tofromjson_array(void);
    virtual void QMJsonValue_tofromjson_object(void);
    virtual void QMJsonValue_fromjson(void);

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
    virtual void QMJsonObject_hash(void);
    virtual void QMJsonObject_null(void);
    virtual void QMJsonObject_bool(void);
    virtual void QMJsonObject_double(void);
    virtual void QMJsonObject_string(void);
    virtual void QMJsonObject_array(void);
    virtual void QMJsonObject_object(void);
    virtual void QMJsonObject_custom(void);
    virtual void QMJsonObject_signals(void);

#ifndef DISABLE_QMJSON_GUI

    virtual void QMJsonGui_qsize(void);
    virtual void QMJsonGui_qpoint(void);
    virtual void QMJsonGui_qrect(void);
    virtual void QMJsonGui_qcolor(void);

#endif

    virtual void signaled(void);

private:

    int32_t mCount;
};
