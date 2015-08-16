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

#ifndef QMJSONTYPE_H
#define QMJSONTYPE_H

// ============================================================================
// Libraries
// ============================================================================

#include <qmjsonfeatures.h>

#include <QtCore>

#if defined(QM_JSON_LIBRARY)
#define QM_JSON_EXPORT Q_DECL_EXPORT
#else
#define QM_JSON_EXPORT Q_DECL_IMPORT
#endif

#include <qmpointer.h>

// ============================================================================
// Enums
// ============================================================================

enum QMJsonValueType
{
    QMJsonValueType_Null = 0,
    QMJsonValueType_Bool = 1,
    QMJsonValueType_Double = 2,
    QMJsonValueType_String = 3,
    QMJsonValueType_Array = 4,
    QMJsonValueType_Object = 5,
    QMJsonValueType_Custom = 6
};

enum QMJsonReplacementPolicy
{
    QMJsonReplacementPolicy_Replace = 1,
    QMJsonReplacementPolicy_Ignore = 2,
};

enum QMJsonFormat
{
    QMJsonFormat_Optimized = -1,
    QMJsonFormat_Pretty = 0
};

enum QMJsonSort
{
    QMJsonSort_None = 0,
    QMJsonSort_CaseInsensitive = 1,
    QMJsonSort_CaseSensitive = 2
};

// ============================================================================
// Class Prototypes
// ============================================================================

class QMJsonValue;
class QMJsonObject;

// ============================================================================
// Base Type
// ============================================================================

class QM_JSON_EXPORT QMJsonTypeBase
{
public:

    QMJsonTypeBase() {}
    virtual ~QMJsonTypeBase() {}

    virtual QDebug print(QDebug dbg) = 0;
    virtual bool isBaseType(void) = 0;

    virtual QString toJson(int32_t tab, QMJsonSort sort) = 0;
    virtual void toComplexJson(const QMPointer<QMJsonObject> &obj) = 0;
};

// ============================================================================
// Class Definition
// ============================================================================

template <class T>
class QMJsonType : public QMJsonTypeBase
{

public:

    QMJsonType(T value);
    virtual ~QMJsonType();

    virtual void set(const T &value);
    virtual T &get(void);

    virtual QDebug print(QDebug dbg) override;
    virtual bool isBaseType(void) override;

    virtual QString toJson(int32_t tab, QMJsonSort sort) override;
    static QMPointer<QMJsonValue> fromJson(const QString &json, int32_t &index);

    virtual void toComplexJson(const QMPointer<QMJsonObject> &obj) override;
    static QMPointer<QMJsonValue> fromComplexJson(const QMPointer<QMJsonObject> &obj);

private:

    T mValue;
};

// ============================================================================
// Class Implementation
// ============================================================================

template <class T>
QMJsonType<T>::QMJsonType(T value) :
    mValue(value)
{
}

template <class T>
QMJsonType<T>::~QMJsonType()
{
}

template <class T>
void QMJsonType<T>::set(const T &value)
{
    mValue = value;
}

template <class T>
T &QMJsonType<T>::get(void)
{
    return mValue;
}

template <class T>
QDebug QMJsonType<T>::print(QDebug dbg)
{
    return dbg << mValue;
}

template <class T>
QString QMJsonType<T>::toJson(int32_t tab, QMJsonSort sort)
{
    (void) tab;
    (void) sort;

    return QString();
}

template <class T>
QMPointer<QMJsonValue> QMJsonType<T>::fromJson(const QString &json, int32_t &index)
{
    (void) json;
    (void) index;

    return NULL;
}

template <class T>
void QMJsonType<T>::toComplexJson(const QMPointer<QMJsonObject> &obj)
{
    (void) obj;
}

template <class T>
bool QMJsonType<T>::isBaseType(void)
{
    return false;
}

#endif // QMJSONTYPE_H
