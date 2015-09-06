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
    explicit QMJsonValue(int8_t value);
    explicit QMJsonValue(uint8_t value);
    explicit QMJsonValue(int16_t value);
    explicit QMJsonValue(uint16_t value);
    explicit QMJsonValue(int32_t value);
    explicit QMJsonValue(uint32_t value);
    explicit QMJsonValue(int64_t value);
    explicit QMJsonValue(uint64_t value);

#if UINTPTR_MAX == 0xffffffff

    explicit QMJsonValue(long value);
    explicit QMJsonValue(unsigned long value);

#elif UINTPTR_MAX == 0xffffffffffffffff

    explicit QMJsonValue(long long value);
    explicit QMJsonValue(unsigned long long value);

#endif

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
 * @page qmjsonvalue QMJsonValue Overview
 *
 * ### Overview
 *
 * With respect to JSON, there are several different basic types:
 *
 * - null
 * - boolean
 * - number
 * - string
 * - array
 * - object
 *
 * A QMJsonValue is a wrapper that can take on any of the above types. This
 * provides a convenient mechanism in C++ to implement the JSON array and object
 * as these data structures can take on any combintation of basic types
 * themselves. That is, in JSON this is perfectly valid:
 *
 * @code
 *
 * [true, 4.8, "Hello World"]
 *
 * @endcode
 *
 * In other high level languages, this can be done, but in C++, this is more
 * difficult. To overcome this, the JSON array / object is implemented as
 * an array / hash of QMJsonValues.
 *
 * @code
 *
 * [QMJsonValue(true), QMJsonValue(4.8), QMJsonValue("Hello World")]
 *
 * @endcode
 *
 * Unlike other librarys, the QMJsonValue takes this one step further and
 * provides support for complex JSON types, allowing for automatic marshaling
 * and unmarshaling of custom types to and from JSON. For more information
 * about JSON, see the following:
 *
 * http://www.json.org
 *
 * ### Creation
 *
 * Like all of the classes in this library, QMJsonValue must be created using
 * a managed QMPointer.
 *
 * @code
 *
 * auto value = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
 *
 * @endcode
 *
 * The QMJsonValue provides constructors for all of the basic types, as well
 * as some non-JSON specific types to ease the use of this API. For example,
 * without additional constructors, type casting would be required constantly:
 *
 * @code
 *
 * auto value = QMPointer<QMJsonValue>(new QMJsonValue((double)4));
 *
 * @endcode
 *
 * This library provides constructor overloads for all of the integer types
 * (8bit s/u to 64bit s/u), as well as floating point and ASCII character
 * pointers.
 *
 * ### Getting / Setting
 *
 * Once a QMJsonValue is created, it's internal type cannot be changed. That is
 * to say, it's not possible to take an existing QMJsonValue that is currently
 * storing a double, and tell it to start storing a string. With some of the
 * basic  types, it is however possible to convert from one type to another.
 * For example,
 *
 * @code
 *
 * auto value = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
 * qDebug() << value->toString(); // "4.8"
 *
 * @endcode
 *
 * Ideally, if the internal type is a bool, you would only use the toBool and
 * fromBool functions. Furthermore, automatic type conversions are not provided
 * if the user provides a default value.
 *
 * @code
 *
 * auto value = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
 * qDebug() << value->toString("test"); // "test"
 *
 * @endcode
 *
 * If the QMJsonValue is storing a complex type, the to<T> and from<T>
 * functions must be used, as generics are not provided.
 *
 * @code
 *
 * auto value = QMPointer<QMJsonValue>(new QMJsonValue(QSize(4, 8)));
 * qDebug() << value->to<QSize>(QSize(15, 16)); // QSize(4, 8)
 * qDebug() << value->from<QSize>(QSize(15, 16)); // true
 *
 * @endcode
 *
 * ### Testing
 *
 * There are multiple ways to determine what type a QMJsonValue is if the type is
 * basic.
 *
 * - isNull, isBool, isDouble, isString, isArray, isObject
 * - type
 * - typeString
 * - is<bool>, is<double>, is<QString>, is<QMPointer<QMJsonArray> >, is<QMPointer<QMJsonObject> >
 *
 * Genreally speaking, the isNull, isBool, isDouble, isString, isArray,
 * isObject are preferred as they are faster and more concise. If the type you
 * are attempting to identify is a complex type, you need to use the is<xxx>
 * function as this is the only way to identify a complex type.
 *
 * @code
 *
 * auto value = QMPointer<QMJsonValue>(new QMJsonValue(QSize(4, 8)));
 * qDebug() << value->is<QSize>(); // true
 *
 * @endcode
 *
 * ### To / From JSON
 *
 * With most JSON, at some point, you will likely need to convert the JSON
 * to and from a JSON string. This can be done with the QMJsonValue::toJson
 * and QMJsonValue::fromJson functions. This library also provides file
 * operations as well, which allow for JSON to be read / written to / from a
 * file using QMJsonValue::toJsonFile and QMJsonValue::fromJsonFile
 *
 * ### Complex Types
 *
 * QMJsonValue can store any JSON type natively. There is nothing the user must
 * do for basic support other than provide a couple of support functions for
 * the class if they are not already provided, which include:
 *
 * - Default constructor
 * - Equals operator
 * - QDebug Overload
 *
 * If these are not provided, it's like the compiler will complain in an attempt
 * to put the complex type inside the QMJsonValue (as the compiler attempts to
 * create the template type). If the user would like to use QMJsonValue::toJson
 * and QMJsonValue::fromJson, three things must be done. First, the user must
 * create template overloads for QMJsonType::toComplexJson and
 * QMJsonType::fromComplexJson, and then the user must register the
 * QMJsonType::fromComplexJson function using
 * QMJsonValue::registerFromComplexJson.
 *
 * For a complete exmaple, see main.cpp, qmjsontype_qsize.cpp and
 * qmjsontype_qrect.cpp
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
 *
 * @note QtMark JSON stores all numbers internally as a double.
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
 * value will be created in its place.
 */

/**
 * @fn QMJsonValue::QMJsonValue(const QMPointer<QMJsonArray> &value)
 * Creates a JSON array, wrapped in a JSON value.
 *
 * @note If the user provides a NULL QMJsonArray, a default, JSON array
 * will be created in its place.
 */

/**
 * @fn QMJsonValue::QMJsonValue(const QMPointer<QMJsonObject> &value)
 * Creates a JSON object, wrapped in a JSON value.
 *
 * @note If the user provides a NULL QMJsonObject, a default, JSON object
 * will be created in its place.
 */

/**
 * @fn QMJsonValue::QMJsonValue(QMJsonValue *value)
 * Creates a new JSON value from an existing JSON value.
 *
 * Both JSON values share the same internal pointer, and thus modifying one
 * of the values, modifies them all.
 *
 * @note If the user provides a NULL QMJsonValue, a default, "null" JSON
 * value will be created in its place.
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
 * users of this API should be aware that the pointer will become managed
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
 * users of this API should be aware that the pointer will become managed
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
 * @fn QMJsonValue::QMJsonValue(const T &value)
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

/**
 * @fn template<class T> QMJsonValue::QMJsonValue(const char *value)
 * Creates a JSON string value.
 *
 * @note QtMark JSON stores all strings internally as QStrings.
 */

/**
 * @fn QMJsonValue::QMJsonValue(float value)
 * Creates a JSON number value.
 *
 * @note QtMark JSON stores all numbers internally as a double.
 */

/**
 * @fn QMJsonValue::QMJsonValue(char value)
 * Creates a JSON number value.
 *
 * @note QtMark JSON stores all numbers internally as a double.
 */

/**
 * @fn QMJsonValue::QMJsonValue(int8_t value)
 * Creates a JSON number value.
 *
 * @note QtMark JSON stores all numbers internally as a double.
 */

/**
 * @fn QMJsonValue::QMJsonValue(uint8_t value)
 * Creates a JSON number value.
 *
 * @note QtMark JSON stores all numbers internally as a double.
 */

/**
 * @fn QMJsonValue::QMJsonValue(int16_t value)
 * Creates a JSON number value.
 *
 * @note QtMark JSON stores all numbers internally as a double.
 */

/**
 * @fn QMJsonValue::QMJsonValue(uint16_t value)
 * Creates a JSON number value.
 *
 * @note QtMark JSON stores all numbers internally as a double.
 */

/**
 * @fn QMJsonValue::QMJsonValue(int32_t value)
 * Creates a JSON number value.
 *
 * @note QtMark JSON stores all numbers internally as a double.
 */

/**
 * @fn QMJsonValue::QMJsonValue(uint32_t value)
 * Creates a JSON number value.
 *
 * @note QtMark JSON stores all numbers internally as a double.
 */

/**
 * @fn QMJsonValue::QMJsonValue(int64_t value)
 * Creates a JSON number value.
 *
 * @note QtMark JSON stores all numbers internally as a double.
 */

/**
 * @fn QMJsonValue::QMJsonValue(uint64_t value)
 * Creates a JSON number value.
 *
 * @note QtMark JSON stores all numbers internally as a double.
 */

/**
 * @fn bool QMJsonValue::isNull(void) const
 * Returns true if the wrapped JSON value is a "null".
 *
 * @note Internally, "null" QMJsonValues have no internal type pointer.
 */

/**
 * @fn bool QMJsonValue::isBool(void) const
 * Returns true if the wrapped JSON value is a boolean
 */

/**
 * @fn bool QMJsonValue::isDouble(void) const
 * Returns true if the wrapped JSON value is a double.
 *
 * @note All numbers are stored as doubles, including integer types.
 */

/**
 * @fn bool QMJsonValue::isString(void) const
 * Returns true if the wrapped JSON value is a string.
 *
 * @note QtMark JSON stores all strings internally as QStrings.
 */

/**
 * @fn bool QMJsonValue::isArray(void) const
 * Returns true if the wrapped JSON value is a JSON array
 */

/**
 * @fn bool QMJsonValue::isObject(void) const
 * Returns true if the wrapped JSON value is a JSON object
 */

/**
 * @fn bool QMJsonValue::is(void) const
 * Returns true if the wrapped JSON value is of type T. This function is meant
 * to be used with custom, complex types as show below:
 *
 * @code
 *
 *  auto value = QMPointer<QMJsonValue>(new QMJsonValue(QSize()));
 *
 *  qDebug() << value->is<QSize>(); // true
 *
 * @endcode
 */

/**
 * @fn bool QMJsonValue::toBool(void) const
 * Unwraps the JSON value and returns the internal type. Depending on what
 * type the JSON value is, will dictate what is returned:
 *
 * - null: false
 * - bool: true / falue (native)
 * - double: false if the value is 0, true otherwise
 * - string: true if the value is "true", false otherwise
 * - else: false
 */

/**
 * @fn double QMJsonValue::toDouble(void) const
 * Unwraps the JSON value and returns the internal type. Depending on what
 * type the JSON value is, will dictate what is returned:
 *
 * - null: 0
 * - bool: false = 0, true = 1
 * - double: double (native)
 * - string: string converted to double, 0 if conversion fails.
 * - else: 0
 */

/**
 * @fn QString QMJsonValue::toString(void) const
 * Unwraps the JSON value and returns the internal type. Depending on what
 * type the JSON value is, will dictate what is returned:
 *
 * - null: "null"
 * - bool: "true" if true, "false" if false
 * - double: double converted to string
 * - string: string (native)
 * - else: 0
 */

/**
 * @fn const QMPointer<QMJsonArray> &QMJsonValue::toArray(void) const
 * Unwraps the JSON value and returns a QMJsonArray. If the internal type
 * is not a QMJsonArray, an empty QMJsonArray is returned.
 */

/**
 * @fn const QMPointer<QMJsonObject> &QMJsonValue::toObject(void) const
 * Unwraps the JSON value and returns a QMJsonObject. If the internal type
 * is not a QMJsonObject, an empty QMJsonObject is returned.
 */

/**
 * @fn bool QMJsonValue::toBool(bool defaultValue) const
 * Unwraps the JSON value and returns the interanl type. If the internal
 * type is not a boolean, the default value is returned instead.
 */

/**
 * @fn double QMJsonValue::toDouble(double defaultValue) const
 * Unwraps the JSON value and returns the interanl type. If the internal
 * type is not a double, the default value is returned instead.
 */

/**
 * @fn const QString &QMJsonValue::toString(const QString &defaultValue) const
 * Unwraps the JSON value and returns the interanl type. If the internal
 * type is not a string, the default value is returned instead.
 */

/**
 * @fn virtual const QMPointer<QMJsonArray> &QMJsonValue::toArray(const QMPointer<QMJsonArray> &defaultValue) const
 * Unwraps the JSON value and returns the interanl type. If the internal
 * type is not an array, the default value is returned instead.
 */

/**
 * @fn virtual const QMPointer<QMJsonObject> &QMJsonValue::toObject(const QMPointer<QMJsonObject> &defaultValue) const
 * Unwraps the JSON value and returns the interanl type. If the internal
 * type is not an object, the default value is returned instead.
 */

/**
 * @fn const T &QMJsonValue::to(const T &defaultValue) const
 * Unwraps the JSON value and returns the internal type. If the internal
 * type is not of type T, the default value is returned instead. This function
 * is meant to be used with custom, complex types as shown below:
 *
 * @code
 *
 *  auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(false));
 *  auto value2 = QMPointer<QMJsonValue>(new QMJsonValue(QSize(4, 8)));
 *
 *  qDebug() << value1->to<QSize>(15, 16); // QSize(15, 16)
 *  qDebug() << value2->to<QSize>(15, 16); // QSize(4, 8)
 *
 * @endcode
 */

 /**
 * @fn bool QMJsonValue::fromBool(bool value)
 * Unwraps the JSON value and sets the internal type. Depending on what
 * type the JSON value is, will dictate what the internal type is set to:
 *
 * - null: (ignored, returns false)
 * - bool: true / falue (native)
 * - double: 0 if false, 1 if true
 * - string: "false" if false, "true" if true
 * - else: (ignored, returns false)
 */

 /**
 * @fn bool QMJsonValue::fromDouble(double value)
 * Unwraps the JSON value and sets the internal type. Depending on what
 * type the JSON value is, will dictate what the internal type is set to:
 *
 * - null: (ignored, returns false)
 * - bool: false if 0, true otherwise
 * - double: double (native)
 * - string: double converted to string
 * - else: (ignored, returns false)
 */

 /**
 * @fn bool QMJsonValue::fromString(const QString &value);
 * Unwraps the JSON value and sets the internal type. Depending on what
 * type the JSON value is, will dictate what the internal type is set to:
 *
 * - null: (ignored, returns false)
 * - bool: true if "true", false otherwise
 * - double: string converted to double. 0 if conversion fails.
 * - string: string (native)
 * - else: (ignored, returns false)
 */

/**
 * @fn bool QMJsonValue::fromArray(const QMPointer<QMJsonArray> &value);
 * Unwraps the JSON value and sets the internal type to a QMJsonArray.
 * If the internal type is not a QMJsonArray, the request is ignored
 */

/**
 * @fn bool QMJsonValue::fromObject(const QMPointer<QMJsonObject> &value);
 * Unwraps the JSON value and sets the internal type to a QMJsonObject.
 * If the internal type is not a QMJsonObject, the request is ignored
 */

 /**
 * @fn bool QMJsonValue::from(const QMPointer<QMJsonValue> &value);
 * Unwraps the JSON value and sets the interanl type. Depending on what
 * type the JSON value is, will dictate what the internal type is set to:
 *
 * - null: if both values are NULL, returns true, otherwise returns false
 * - bool: @ref fromBool
 * - double: @ref fromDouble
 * - string: @ref fromString
 * - array: @ref fromArray
 * - object: @ref fromObject
 * - else: returns false
 */

/**
 * @fn bool QMJsonValue::from(const T &value)
 * Unwraps the JSON value and sets the internal type. If the internal
 * type is not of type T, the request is ignored. This function
 * is meant to be used with custom, complex types as shown below:
 *
 * @code
 *
 *  auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(false));
 *  auto value2 = QMPointer<QMJsonValue>(new QMJsonValue(QSize(4, 8)));
 *
 *  qDebug() << value1->from<QSize>(15, 16); // false
 *  qDebug() << value2->from<QSize>(15, 16); // true
 *
 * @endcode
 */

/**
 * @fn const QMPointer<QMJsonValue> &QMJsonValue::value(int32_t index) const
 * A convenience function. The following two statements are equvilant:
 *
 * @code
 *
 *  qDebug() << value->value(index); // QMJsonValue()
 *  qDebug() << value->toArray()->value(index); // QMJsonValue()
 *
 * @endcode
 */

/**
 * @fn const QMPointer<QMJsonValue> &QMJsonValue::value(const QString &key) const;
 * A convenience function. The following two statements are equvilant:
 *
 * @code
 *
 *  qDebug() << value->value(key); // QMJsonValue()
 *  qDebug() << value->toObject()->value(key); // QMJsonValue()
 *
 * @endcode
 */

/**
 * @fn QVariant QMJsonValue::toVariant(void)
 * Converts the JSON value to a Variant. QMJsonArrays and QMJsonObjects are
 * converted into QVariantLists and QVariantHashs, and wrapped in a QVariant.
 */

/**
 * @fn static QMPointer<QMJsonValue> QMJsonValue::fromVariant(const QVariant &value)
 * Converts a QVariant into a QMJsonValue. QVariants can take on a lot of
 * different types. Types that are not supported by this library return
 * QVariant's default constructor.
 */

/**
 * @fn QMJsonValueType QMJsonValue::type(void) const
 * Returns the internal type for this QMJsonValue.
 */

/**
 * @fn const QString &QMJsonValue::typeString(void) const
 * Returns a string representation of the internal type for this QMJsonValue.
 */

/**
 * @fn QString QMJsonValue::toJson(QMJsonFormat format = QMJsonFormat_Pretty, QMJsonSort sort = QMJsonSort_None) const
 * Returns a string representation of this QMJsonValue. If
 * QMJsonFormat_Optimized is provided, the returned string does not contain
 * added whitespace or newlines. This function provides better performance when
 * sort is set to QMJsonSort_None, however sorting is needed if you wish to
 * compare the output of two JSON values.
 *
 * Non-standard JSON types (i.e. complex types) are converted into their
 * JSON equivalents using the toComplexJson and fromComplexJson template
 * overloads. To see an exmaple of how this is done, see the template overloads
 * withing the GUI portion of this library. Specificaly the overloads for
 * QSize and QRect which demonstration coverting a complex type into native
 * JSON (i.e. QSize) and converting a complex type into other complex types
 * (i.e. QRect)
 *
 * @see registerFromComplexJson
 */

/**
 * @fn bool QMJsonValue::toJsonFile(const QString &filename, QMJsonFormat format = QMJsonFormat_Pretty, QMJsonSort sort = QMJsonSort_None) const
 * Converts the QMJsonValue to a string and saves the results to filename.
 * If the save fails, this function returns false, otherwise true.
 *
 * @see toJson
 */

/**
 * @fn QMPointer<QMJsonValue> QMJsonValue::fromJson(const QString &json)
 * Converts the provided sting into the QMJsonValue equivlant.
 *
 * If the provided string contains a JSON object that has a key named
 * 'qmjsontype', QMJsonValue will attempt to convert the JSON object to its
 * complex type using the fromComplexJson function that was registered with
 * registerFromComplexJson. If no fromComplexJson exists for the type defined
 * by 'qmjsontype', or has not been registered, the JSON object will be treated
 * as a standard JSON object.
 *
 * @see registerFromComplexJson
 */

/**
 * @fn static QMPointer<QMJsonValue> QMJsonValue::fromJsonFile(const QString &filename)
 * Read in the contents of filename, and converts the resulting sting into
 * the QMJsonValue equivlant.
 *
 * @see fromJson
 */

/**
 * @fn static void QMJsonValue::registerFromComplexJson(const QString &qmjsontype, FromComplexJsonFunc func)
 * Registers a fromComplexJson function with the QMJsonValue class. When
 * fromJson or fromJsonFile are called, fromComplexJson that are registered will
 * be used to convert JSON objects that contain 'qmjsontype' into their
 * complex equivalents.
 *
 * @see main.cpp
 */
