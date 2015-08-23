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

#ifndef QMJSONVALUE_H
#define QMJSONVALUE_H

// ============================================================================
// Libraries
// ============================================================================

#include <qmjsontype.h>

// ============================================================================
// Class Prototypes
// ============================================================================

class QMJsonArray;
class QMJsonObject;

// ============================================================================
// Typedefs
// ============================================================================

typedef QMPointer<QMJsonValue> (*FromComplexJsonFunc)(const QMPointer<QMJsonObject> &obj);

// ============================================================================
// Class Definition
// ============================================================================

class QM_JSON_EXPORT QMJsonValue : public QObject
{
    Q_OBJECT

    template<class T> friend class QMJsonType;
    friend QDebug QM_JSON_EXPORT operator<<(QDebug dbg, const QMJsonValue &value);

public:

    QMJsonValue();
    explicit QMJsonValue(bool value);
    explicit QMJsonValue(double value);
    explicit QMJsonValue(const QString &value);
    explicit QMJsonValue(const QMPointer<QMJsonValue> &value);
    explicit QMJsonValue(const QMPointer<QMJsonArray> &value);
    explicit QMJsonValue(const QMPointer<QMJsonObject> &value);
    explicit QMJsonValue(QMJsonValue *value);
    explicit QMJsonValue(QMJsonArray *value);
    explicit QMJsonValue(QMJsonObject *value);
    template<class T> explicit QMJsonValue(const T &value);

    explicit QMJsonValue(const char *value);
    explicit QMJsonValue(float value);
    explicit QMJsonValue(char value);
    explicit QMJsonValue(long value);
    explicit QMJsonValue(unsigned long value);
    explicit QMJsonValue(int8_t value);
    explicit QMJsonValue(uint8_t value);
    explicit QMJsonValue(int16_t value);
    explicit QMJsonValue(uint16_t value);
    explicit QMJsonValue(int32_t value);
    explicit QMJsonValue(uint32_t value);
    explicit QMJsonValue(int64_t value);
    explicit QMJsonValue(uint64_t value);

    virtual ~QMJsonValue();

    virtual bool isNull(void) const;
    virtual bool isBool(void) const;
    virtual bool isDouble(void) const;
    virtual bool isString(void) const;
    virtual bool isArray(void) const;
    virtual bool isObject(void) const;
    template<class T> bool is(void) const;

    virtual bool toBool(void) const;
    virtual double toDouble(void) const;
    virtual QString toString(void) const;
    virtual const QMPointer<QMJsonArray> &toArray(void) const;
    virtual const QMPointer<QMJsonObject> &toObject(void) const;

    virtual bool toBool(bool defaultValue) const;
    virtual double toDouble(double defaultValue) const;
    virtual const QString &toString(const QString &defaultValue) const;
    virtual const QMPointer<QMJsonArray> &toArray(const QMPointer<QMJsonArray> &defaultValue) const;
    virtual const QMPointer<QMJsonObject> &toObject(const QMPointer<QMJsonObject> &defaultValue) const;
    template<class T> const T &to(const T &defaultValue) const;

    virtual bool fromBool(bool value);
    virtual bool fromDouble(double value);
    virtual bool fromString(const QString &value);
    virtual bool fromArray(const QMPointer<QMJsonArray> &value);
    virtual bool fromObject(const QMPointer<QMJsonObject> &value);
    virtual bool from(const QMPointer<QMJsonValue> &value);
    template <class T> bool from(const T &value);

    virtual const QMPointer<QMJsonValue> &value(int32_t index) const;
    virtual const QMPointer<QMJsonValue> &value(const QString &key) const;

    virtual QVariant toVariant(void);
    static QMPointer<QMJsonValue> fromVariant(const QVariant &value);

    virtual QMJsonValueType type(void) const;
    virtual const QString &typeString(void) const;

    virtual QString toJson(QMJsonFormat format = QMJsonFormat_Pretty, QMJsonSort sort = QMJsonSort_None) const;
    virtual bool toJsonFile(const QString &filename, QMJsonFormat format = QMJsonFormat_Pretty, QMJsonSort sort = QMJsonSort_None) const;
    static QMPointer<QMJsonValue> fromJson(const QString &json);
    static QMPointer<QMJsonValue> fromJsonFile(const QString &filename);

    static void registerFromComplexJson(const QString &qmjsontype, FromComplexJsonFunc func);

signals:

    void valueChanged(void);

private:

    static void skipSpaces(const QString &json, int32_t &index);
    static void verifyIndex(const QString &json, int32_t &index);
    static QMPointer<QMJsonValue> fromJson(const QString &json, int32_t &index);
    static QMPointer<QMJsonValue> fromComplexJson(const QMPointer<QMJsonValue> &value);
    static void throwError(const QString &json, int32_t index, QString error);

    template <class T> bool set(const T &value);

private:

    Q_DISABLE_COPY(QMJsonValue);

    QMJsonValueType mType;
    QMPointer<QMJsonTypeBase> mValue;

    static QMap<QString, FromComplexJsonFunc> mFromFuncs;
};

// ============================================================================
// Template Specializations
// ============================================================================

QDebug QM_JSON_EXPORT operator<<(QDebug dbg, const QMJsonValue &value);
QDebug QM_JSON_EXPORT operator<<(QDebug dbg, const QMPointer<QMJsonValue> &value);

// ============================================================================
// Class Implementation
// ============================================================================

template<class T>
QMJsonValue::QMJsonValue(const T &value)
{
    auto type = QSharedPointer<QMJsonType<T> >(new QMJsonType<T>(value));

    mType = QMJsonValueType_Custom;
    mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
}

template<class T>
bool QMJsonValue::is(void) const
{
    return qSharedPointerDynamicCast<QMJsonType<T> >(mValue) != NULL;
}

template<class T>
const T &QMJsonValue::to(const T &defaultValue) const
{
    auto type = qSharedPointerDynamicCast<QMJsonType<T> >(mValue);

    if(type == NULL)
        return defaultValue;

    return type->get();
}

template<class T>
bool QMJsonValue::from(const T &value)
{
    switch(mType)
    {
        case QMJsonValueType_Null:
            return false;

        case QMJsonValueType_Bool:
        case QMJsonValueType_Double:
        case QMJsonValueType_String:
            return this->set<T>(value);

        case QMJsonValueType_Array:
        case QMJsonValueType_Object:
            return false;

        case QMJsonValueType_Custom:
            return this->set<T>(value);
    };

    return false;
}

template<class T>
bool QMJsonValue::set(const T &value)
{
    auto type = qSharedPointerDynamicCast<QMJsonType<T> >(mValue);

    if(type == NULL)
        return false;

    type->set(value);

    emit valueChanged();
    return true;
}

#endif // QMJSONVALUE_H

/**
 * @page qmjsonvalue QMJsonValue
 *
 * Placeholder
 *
 *
 */

/**
 * @fn QMJsonValue::QMJsonValue()
 * Creates a JSON "null" value.
 */

/**
 * @fn QMJsonValue::QMJsonValue(bool value)
 * Creates a JSON boolean value.
 */

/**
 * @fn QMJsonValue::QMJsonValue(double value)
 * Creates a JSON number value.
 */

/**
 * @fn QMJsonValue::QMJsonValue(const QString &value)
 * Creates a JSON string value.
 *
 * @note QtMark JSON stores all strings internally as QStrings.
 */

/**
 * @fn QMJsonValue::QMJsonValue(const QMPointer<QMJsonValue> &value)
 * Creates a new JSON value from an existing JSON value.
 *
 * Both JSON values share the same internal pointer, and thus modifying one
 * of the values, modifies them all.
 *
 * @note If the user provides a NULL QMJsonValue, a default, "null" JSON
 * value will be created in it's place.
 */

/**
 * @fn QMJsonValue::QMJsonValue(const QMPointer<QMJsonArray> &value)
 * Creates a JSON array, wrapped in a JSON value.
 *
 * @note If the user provides a NULL QMJsonArray, a default, JSON array
 * will be created in it's place.
 */

/**
 * @fn QMJsonValue::QMJsonValue(const QMPointer<QMJsonObject> &value)
 * Creates a JSON object, wrapped in a JSON value.
 *
 * @note If the user provides a NULL QMJsonObject, a default, JSON object
 * will be created in it's place.
 */

/**
 * @fn QMJsonValue::QMJsonValue(QMJsonValue *value)
 * Creates a new JSON value from an existing JSON value.
 *
 * Both JSON values share the same internal pointer, and thus modifying one
 * of the values, modifies them all.
 *
 * @note If the user provides a NULL QMJsonValue, a default, "null" JSON
 * value will be created in it's place.
 */

/**
 * @fn QMJsonValue::QMJsonValue(QMJsonArray *value)
 * Creates a JSON array, wrapped in a JSON value.
 *
 * @note If the user provides a NULL QMJsonArray, a default, JSON array
 * will be created in it's place.
 *
 * @note This function wraps the QMJsonArray in a QMPointer, since the
 * QtMark JSON Library only supported managed pointers. For this reason,
 * user's of this API should be aware that the pointer will become managed
 * once used. The most common use for this function is when creating new
 * JSON arrays as shown below
 *
 * @code
 *
 * auto value = QMPointer<QMJsonValue>(new QMJsonArray);
 *
 * @endcode
 */

/**
 * @fn QMJsonValue::QMJsonValue(QMJsonObject *value)
 * Creates a JSON object, wrapped in a JSON value.
 *
 * @note If the user provides a NULL QMJsonObject, a default, JSON object
 * will be created in it's place.
 *
 * @note This function wraps the QMJsonObject in a QMPointer, since the
 * QtMark JSON Library only supported managed pointers. For this reason,
 * user's of this API should be aware that the pointer will become managed
 * once used. The most common use for this function is when creating new
 * JSON objects as shown below
 *
 * @code
 *
 * auto value = QMPointer<QMJsonValue>(new QMJsonObject);
 *
 * @endcode
 */

/**
 * @fn template<class T> QMJsonValue::QMJsonValue(const T &value)
 * Creates a JSON value with type T.
 *
 * The QtMark JSON Library supports wraping almost anything in a JSON
 * value. If you use this function, the compiler will likely require that you
 * provide a QDebug overload for this type (if one does not already exist).
 *
 * If you wish to use toJson and fromJson with a non-standard type, you need
 * to provide the Complex JSON template overloads. For an example of how to
 * do this, see the qmjsontype_qsize.cpp file.
 *
 * This library also supported nested complex types. To see an example of how
 * this works, see the qmjsontype_qrect.cpp file, as the QRect implementation
 * relys on QSize and QPoint.
 *
 * @code
 *
 * auto value = QMPointer<QMJsonValue>(QSize(4, 8));
 *
 * @endcode
 */
