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

#ifndef QMJSONOBJECT_H
#define QMJSONOBJECT_H

// ============================================================================
// Libraries
// ============================================================================

#include <qmjsonvalue.h>

// ============================================================================
// Class Definition
// ============================================================================

class QM_JSON_EXPORT QMJsonObject : public QObject
{
    Q_OBJECT

public:

    QMJsonObject();
    explicit QMJsonObject(const QHash<QString, QMPointer<QMJsonValue> > &hash);
    virtual ~QMJsonObject();

    virtual void reserve(int32_t alloc);
    virtual int32_t capacity(void) const;
    virtual void squeeze(void);

    virtual void clear(void);

    virtual int32_t count(void) const;
    virtual int32_t size(void) const;

    virtual bool isEmpty(void) const;
    virtual bool empty(void) const;

    virtual bool contains(const QString &key) const;

    virtual void insert(const QString &key, const QMPointer<QMJsonValue> &value, QMJsonReplacementPolicy policy = QMJsonReplacementPolicy_Replace);
    template<class T> void insert(const QString &key, const T &value, QMJsonReplacementPolicy policy = QMJsonReplacementPolicy_Replace);

    virtual void unite(const QMPointer<QMJsonObject> &object, QMJsonReplacementPolicy replacementPolicy = QMJsonReplacementPolicy_Replace, QMJsonArrayUnitePolicy unitePolicy = QMJsonArrayUnitePolicy_Append);

    virtual void remove(const QString &key);
    virtual QMPointer<QMJsonValue> take(const QString &key);
    virtual QMPointer<QMJsonValue> take(const QString &key, const QMPointer<QMJsonValue> &defaultValue);
    template<class T> QMPointer<QMJsonValue> take(const QString &key, const T &defaultValue);

    virtual const QString key(const QMPointer<QMJsonValue> &value) const;
    virtual const QString key(const QMPointer<QMJsonValue> &value, const QString &defaultValue) const;

    virtual QHash<QString, QMPointer<QMJsonValue> >::iterator begin(void);
    virtual QHash<QString, QMPointer<QMJsonValue> >::iterator end(void);
    virtual QHash<QString, QMPointer<QMJsonValue> >::const_iterator cbegin(void) const;
    virtual QHash<QString, QMPointer<QMJsonValue> >::const_iterator cend(void) const;

    virtual const QHash<QString, QMPointer<QMJsonValue> >::iterator erase(const QHash<QString, QMPointer<QMJsonValue> >::iterator &iter);
    virtual QHash<QString, QMPointer<QMJsonValue> >::iterator find(const QString &key);
    virtual const QHash<QString, QMPointer<QMJsonValue> >::const_iterator cfind(const QString &key) const;

    virtual const QMPointer<QMJsonValue> &value(const QString &key) const;
    virtual const QMPointer<QMJsonValue> &value(const QString &key, const QMPointer<QMJsonValue> &defaultValue) const;
    template<class T> QMPointer<QMJsonValue> value(const QString &key, const T &defaultValue) const;

    virtual QList<QString> keys(void) const;
    virtual QList<QMPointer<QMJsonValue> > values(void) const;
    virtual QHash<QString, QMPointer<QMJsonValue> > hash(void) const;

    virtual bool isNull(const QString &key) const;
    virtual bool isBool(const QString &key) const;
    virtual bool isDouble(const QString &key) const;
    virtual bool isString(const QString &key) const;
    virtual bool isArray(const QString &key) const;
    virtual bool isObject(const QString &key) const;
    template<class T> bool is(const QString &key) const;

    virtual bool toBool(const QString &key) const;
    virtual double toDouble(const QString &key) const;
    virtual QString toString(const QString &key) const;
    virtual const QMPointer<QMJsonArray> &toArray(const QString &key) const;
    virtual const QMPointer<QMJsonObject> &toObject(const QString &key) const;

    virtual bool toBool(const QString &key, bool defaultValue) const;
    virtual double toDouble(const QString &key, double defaultValue) const;
    virtual const QString &toString(const QString &key, const QString &defaultValue) const;
    virtual const QMPointer<QMJsonArray> &toArray(const QString &key, const QMPointer<QMJsonArray> &defaultValue) const;
    virtual const QMPointer<QMJsonObject> &toObject(const QString &key, const QMPointer<QMJsonObject> &defaultValue) const;
    template<class T> const T &to(const QString &key, const T &defaultValue) const;

    virtual bool fromBool(const QString &key, bool value);
    virtual bool fromDouble(const QString &key, double value);
    virtual bool fromString(const QString &key, const QString &value);
    virtual bool fromArray(const QString &key, const QMPointer<QMJsonArray> &value);
    virtual bool fromObject(const QString &key, const QMPointer<QMJsonObject> &value);
    virtual bool from(const QString &key, const QMPointer<QMJsonValue> &value);
    template <class T> bool from(const QString &key, const T &value);

signals:

    void itemAdded(const QString &key, const QMPointer<QMJsonValue> &value);
    void itemRemoved(const QString &key, const QMPointer<QMJsonValue> &value);

private:

    Q_DISABLE_COPY(QMJsonObject);

    QHash<QString, QMPointer<QMJsonValue> > mHash;
};

QDebug QM_JSON_EXPORT operator<<(QDebug dbg, const QMJsonObject &object);
QDebug QM_JSON_EXPORT operator<<(QDebug dbg, const QMPointer<QMJsonObject> &value);

// ============================================================================
// Class Implementation
// ============================================================================

template<class T>
void QMJsonObject::insert(const QString &key, const T &value, QMJsonReplacementPolicy policy)
{
    this->insert(key, QMPointer<QMJsonValue>(new QMJsonValue(value)), policy);
}

template<class T>
QMPointer<QMJsonValue> QMJsonObject::take(const QString &key, const T &defaultValue)
{
    auto iter = mHash.find(key);

    if(iter == mHash.end())
        return QMPointer<QMJsonValue>(new QMJsonValue(defaultValue));

    this->erase(iter);

    return iter.value();
}

template<class T>
QMPointer<QMJsonValue> QMJsonObject::value(const QString &key, const T &defaultValue) const
{
    auto iter = mHash.constFind(key);

    if(iter == mHash.constEnd())
        return QMPointer<QMJsonValue>(new QMJsonValue(defaultValue));

    return iter.value();
}

template<class T>
bool QMJsonObject::is(const QString &key) const
{
    auto iter = mHash.constFind(key);

    if(iter == mHash.constEnd())
        return false;

    return iter.value()->is<T>();
}

template<class T>
const T &QMJsonObject::to(const QString &key, const T &defaultValue) const
{
    return this->value(key)->to<T>(defaultValue);
}

template<class T>
bool QMJsonObject::from(const QString &key, const T &value)
{
    return this->value(key)->from<T>(value);
}

#endif // QMJSONOBJECT_H

/**
 * @page qmjsonobject QMJsonObject Overview
 *
 * The QMJsonObject implements a JSON object. Internally, the QMJsonObject is
 * a QHash<QString, QMPointer<QMJsonValue> >. Thus, all of the rules that apply
 * to QHash with respect to performance are basically the same with
 * QMJsonObject. Like the rest of the QtMark JSON Library, all of the
 * QMJsonValues stored in the QMJsonObject as stored as QMPointers.
 *
 * ### Creation
 *
 * Like all of the classes in this library, QMJsonObject must be created using
 * a managed QMPointer.
 *
 * @code
 *
 * auto object = QMPointer<QMJsonObject>(new QMJsonObject());
 *
 * @endcode
 *
 * ### Object Manipulation
 *
 * There is basically one way to add items to a QMJsonObject:
 *
 * - QMJsonObject::insert
 *
 * There is no need to manually wrap a value in a QMJsonValue, as this
 * will be done for you:
 *
 * @code
 *
 * auto object = QMPointer<QMJsonObject>(new QMJsonObject());
 * object->insert("key0", 4.8);
 *
 * @endcode
 *
 * There are also a number of functions to remove an item from the
 * QMJsonObject. These are:
 *
 * - QMJsonObject::remove
 * - QMJsonObject::take
 *
 * ### Object Information
 *
 * QMJsonObject::isEmpty will tell you if the QMJsonObject has any QMJsonValues
 * in it. You can also call QMJsonObject::count to get the current number of
 * QMJsonValues in the QMJsonObject.
 *
 * @code
 *
 * auto object = QMPointer<QMJsonObject>(new QMJsonObject());
 * object->insert("key0", 4.8);
 *
 * qDebug() << object->isEmpty(); // false
 * qDebug() << object->count(); // 1
 *
 * @endcode
 *
 * ### Convenience Functions
 *
 * Both the QMJsonObject and QMJsonArray classes provide the QMJsonValue
 * unwrap functions for convenience. This applies for:
 *
 * - QMJsonObject::is
 * - QMJsonObject::to
 * - QMJsonObject::from
 *
 * Allowing for shorthand conversions:
 *
 * @code
 *
 * auto object = QMPointer<QMJsonObject>(new QMJsonObject());
 * object->insert("key0", 4.8);
 *
 * qDebug() << object->toDouble("key0"); // 4.8
 * qDebug() << object->toString("key0"); // "4.8"
 *
 * // Instead of
 *
 * qDebug() << object->value("key0")->toDouble(); // 4.8
 * qDebug() << object->value("key0")->toString(); // "4.8"
 *
 * @endcode
 *
 * ### To / From JSON
 *
 * To convert a QMJsonObject to JSON, you must wrap the QMJsonObject in a
 * QMJsonValue and use QMJsonValue::toJson and QMJsonValue::fromJson
 *
 * @code
 *
 * auto object = QMPointer<QMJsonObject>(new QMJsonObject());
 * auto document = QMPointer<QMJsonValue>(new QMJsonValue(object));
 * object->insert("key0", 4.8);
 *
 * qDebug() << document->toJson(QMJsonFormat_Optimized); // "{"key0":4.8}"
 *
 * @endcode
 *
 */

/**
 * @fn QMJsonObject::QMJsonObject()
 * Default constructor, creates an empty QMJsonObject
 */

/**
 * @fn QMJsonObject::QMJsonObject(const QHash<QString, QMPointer<QMJsonValue> > &hash);
 * Overloaded constructor, create a QMJsonObject and fills it with the
 * QMJsonValues provided in @e hash
 */

/**
 * @fn void QMJsonObject::clear(void)
 * Clears the QMJsonObject
 */

/**
 * @fn int32_t QMJsonObject::count(void) const
 * Returns the number of QMJsonValues in the QMJsonObject
 */

/**
 * @fn int32_t QMJsonObject::size(void) const
 * Returns the number of QMJsonValues in the QMJsonObject
 */

/**
 * @fn bool QMJsonObject::isEmpty(void) const
 * Returns true if the QMJsonObject is empty
 */

/**
 * @fn bool QMJsonObject::empty(void) const
 * Returns true if the QMJsonObject is empty
 */

/**
 * @fn bool QMJsonObject::contains(const QString &key) const
 * Returns true if the QMJsonObject contains an item with the @e key.
 * Otherwise returns false.
 */

/**
 * @fn void QMJsonObject::insert(const QString &key, const QMPointer<QMJsonValue> &value, QMJsonReplacementPolicy policy = QMJsonReplacementPolicy_Replace)
 * Inserts @e value into the QMJsonObject with @e key. If the QMJsonObject
 * alreday contains @e key, and @e policy is set to
 * QMJsonReplacementPolicy_Replace, the existing QMJsonValue is replaced. If
 * @e policy is set to QMJsonReplacementPolicy_Ignore, this operation is
 * ignored.
 */

/**
 * @fn void QMJsonObject::insert(const QString &key, const QMPointer<QMJsonValue> &value, QMJsonReplacementPolicy policy = QMJsonReplacementPolicy_Replace)
 * Wraps @e value in a QMJsonValue and inserts it into the QMJsonObject with
 * @e key. If the QMJsonObject alreday contains @e key, and @e policy is set to
 * QMJsonReplacementPolicy_Replace, the existing QMJsonValue is replaced. If
 * @e policy is set to QMJsonReplacementPolicy_Ignore, this operation is
 * ignored.
 */

/**
 * @fn void QMJsonObject::unite(const QMPointer<QMJsonObject> &object, QMJsonReplacementPolicy replacementPolicy = QMJsonReplacementPolicy_Replace, QMJsonArrayUnitePolicy unitePolicy = QMJsonArrayUnitePolicy_Append);
 * Unites this QMJsonObject with @e object by inserting all the QMJsonValues in
 * @e object into this QMJsonObject. If the QMJsonObject alreday contains a
 * QMJsonValue with the same key and @e replacementPolicy is set to
 * QMJsonReplacementPolicy_Replace, the existing QMJsonValue is replaced. If
 * @e replacementPolicy is set to QMJsonReplacementPolicy_Ignore,
 * the insertion is ignored. If a QMJsonArray is encountered in both objects
 * with the same key, QMJsonArray::unite is called, and @e unitePolicy is
 * passed as the unite policy.
 */

/**
 * @fn void QMJsonObject::remove(const QString &key)
 * Removes the QMJsonValue at @e key. If the QMJsonObject does not contain a
 * QMJsonValue with @e key, this operation is ignored.
 */

/**
 * @fn QMPointer<QMJsonValue> QMJsonObject::take(const QString &key)
 * Removes the QMJsonValue at @e key and returns the removed
 * QMJsonValue. If the QMJsonObject does not contain a
 * QMJsonValue with @e key, this operation returns a newly constructed,
 * default QMJsonValue
 */

/**
 * @fn QMPointer<QMJsonValue> QMJsonObject::take(const QString &key, const QMPointer<QMJsonValue> &defaultValue)
 * Removes the QMJsonValue at @e key and returns the removed
 * QMJsonValue. If the QMJsonObject does not contain a
 * QMJsonValue with @e key, this operation returns defaultValue
 */

/**
 * @fn template<class T> QMPointer<QMJsonValue> QMJsonObject::take(const QString &key, const T &defaultValue)
 * Removes the QMJsonValue at @e key and returns the removed
 * QMJsonValue. If the QMJsonObject does not contain a
 * QMJsonValue with @e key, this operation returns defaultValue wrapped in a
 * QMJsonValue
 */

/**
 * @fn const QString QMJsonObject::key(const QMPointer<QMJsonValue> &value) const
 * Returns the key associated with @e value. If the QMJsonObject does not
 * contain @e value, a default constructed QString is returned.
 */

/**
 * @fn const QString QMJsonObject::key(const QMPointer<QMJsonValue> &value, const QString &defaultValue) const
 * Returns the key associated with @e value. If the QMJsonObject does not
 * contain @e value, defaultValue is returned.
 */

/**
 * @fn QHash<QString, QMPointer<QMJsonValue> >::iterator QMJsonObject::begin(void)
 * Returns an STL-style iterator pointing to the first QMJsonValue in the
 * QMJsonObject.
 *
 * @note The use of iterators can speed up the performance of some operations on
 * QMJsonObjects as it can remove a second lookup (i.e. the user of
 * QMJsonObject::contains and then QMJsonObject::value). QMJsonObject provides
 * these iterators by simply exposing the QHash iterators that already exist.
 * The problem with Qt's iterators is they can be unsafe. Unlike the rest of
 * this library, you must do bounds checking on your own when using iterators,
 * otherwise segmentation faults could occur.
 */

/**
 * @fn QHash<QString, QMPointer<QMJsonValue> >::iterator QMJsonObject::end(void)
 * Returns an STL-style iterator pointing to the last QMJsonValue in the
 * QMJsonObject.
 *
 * @note The use of iterators can speed up the performance of some operations on
 * QMJsonObjects as it can remove a second lookup (i.e. the user of
 * QMJsonObject::contains and then QMJsonObject::value). QMJsonObject provides
 * these iterators by simply exposing the QHash iterators that already exist.
 * The problem with Qt's iterators is they can be unsafe. Unlike the rest of
 * this library, you must do bounds checking on your own when using iterators,
 * otherwise segmentation faults could occur.
 */

/**
 * @fn QHash<QString, QMPointer<QMJsonValue> >::const_iterator QMJsonObject::cbegin(void) const;
 * Returns an STL-style const iterator pointing to the first QMJsonValue in the
 * QMJsonObject.
 *
 * @note The use of iterators can speed up the performance of some operations on
 * QMJsonObjects as it can remove a second lookup (i.e. the user of
 * QMJsonObject::contains and then QMJsonObject::value). QMJsonObject provides
 * these iterators by simply exposing the QHash iterators that already exist.
 * The problem with Qt's iterators is they can be unsafe. Unlike the rest of
 * this library, you must do bounds checking on your own when using iterators,
 * otherwise segmentation faults could occur.
 */

/**
 * @fn QHash<QString, QMPointer<QMJsonValue> >::const_iterator QMJsonObject::cend(void) const;
 * Returns an STL-style const iterator pointing to the last QMJsonValue in the
 * QMJsonObject.
 *
 * @note The use of iterators can speed up the performance of some operations on
 * QMJsonObjects as it can remove a second lookup (i.e. the user of
 * QMJsonObject::contains and then QMJsonObject::value). QMJsonObject provides
 * these iterators by simply exposing the QHash iterators that already exist.
 * The problem with Qt's iterators is they can be unsafe. Unlike the rest of
 * this library, you must do bounds checking on your own when using iterators,
 * otherwise segmentation faults could occur.
 */


/**
 * @fn const QHash<QString, QMPointer<QMJsonValue> >::iterator QMJsonObject::erase(const QHash<QString, QMPointer<QMJsonValue> >::iterator &iter)
 * Removes the QMJsonValue associated with @e iter from the QMJsonObject, and
 * returns an iterator to the next item in the QMJsonObject.
 *
 * @note The use of iterators can speed up the performance of some operations on
 * QMJsonObjects as it can remove a second lookup (i.e. the user of
 * QMJsonObject::contains and then QMJsonObject::value). QMJsonObject provides
 * these iterators by simply exposing the QHash iterators that already exist.
 * The problem with Qt's iterators is they can be unsafe. Unlike the rest of
 * this library, you must do bounds checking on your own when using iterators,
 * otherwise segmentation faults could occur.
 */

/**
 * @fn QHash<QString, QMPointer<QMJsonValue> >::iterator QMJsonObject::find(const QString &key)
 * Returns the interator associated with @e key in the QMJsonObject. If no
 * iterator is found, QMJsonObject::end is returned.
 *
 * @note The use of iterators can speed up the performance of some operations on
 * QMJsonObjects as it can remove a second lookup (i.e. the user of
 * QMJsonObject::contains and then QMJsonObject::value). QMJsonObject provides
 * these iterators by simply exposing the QHash iterators that already exist.
 * The problem with Qt's iterators is they can be unsafe. Unlike the rest of
 * this library, you must do bounds checking on your own when using iterators,
 * otherwise segmentation faults could occur.
 */

/**
 * @fn const QHash<QString, QMPointer<QMJsonValue> >::const_iterator QMJsonObject::cfind(const QString &key) const
 * Returns the const interator associated with @e key in the QMJsonObject. If no
 * iterator is found, QMJsonObject::cend is returned.
 *
 * @note The use of iterators can speed up the performance of some operations on
 * QMJsonObjects as it can remove a second lookup (i.e. the user of
 * QMJsonObject::contains and then QMJsonObject::value). QMJsonObject provides
 * these iterators by simply exposing the QHash iterators that already exist.
 * The problem with Qt's iterators is they can be unsafe. Unlike the rest of
 * this library, you must do bounds checking on your own when using iterators,
 * otherwise segmentation faults could occur.
 */

/**
 * @fn const QMPointer<QMJsonValue> &QMJsonObject::value(const QString &key) const
 * Returns the value associated with @e key. If the QMJsonObject does not
 * contain @e key, a default constructed QMJsonValue is returned.
 */

/**
 * @fn const QMPointer<QMJsonValue> &QMJsonObject::value(const QString &key, const QMPointer<QMJsonValue> &defaultValue) const
 * Returns the value associated with @e key. If the QMJsonObject does not
 * contain @e key, defaultValue is returned.
 */

/**
 * @fn template<class T> QMPointer<QMJsonValue> QMJsonObject::value(const QString &key, const T &defaultValue) const
 * Returns the value associated with @e key. If the QMJsonObject does not
 * contain @e key, defaultValue is wrapped in a QMJsonValue and returned.
 */

/**
 * @fn QList<QString> QMJsonObject::keys(void) const
 * Returns a QList containing all of the keys in the QMJsonObject
 */

/**
 * @fn QList<QMPointer<QMJsonValue> > QMJsonObject::values(void) const
 * Returns a QList containing all of the QMJsonValues in the QMJsonObject
 */

/**
 * @fn QHash<QString, QMPointer<QMJsonValue> > QMJsonObject::hash(void) const
 * Returns the internal QHash of QMJsonObject
 */

/**
 * @fn bool QMJsonObject::isNull(const QString &key) const
 * Returns true if the wrapped JSON value at @e key is a "null".
 *
 * @note Internally, "null" QMJsonValues have no internal type pointer.
 */

/**
 * @fn bool QMJsonObject::isBool(const QString &key) const
 * Returns true if the wrapped JSON value at @e key is a boolean
 */

/**
 * @fn bool QMJsonObject::isDouble(const QString &key) const
 * Returns true if the wrapped JSON value at @e key is a double.
 *
 * @note All numbers are stored as doubles, including integer types.
 */

/**
 * @fn bool QMJsonObject::isString(const QString &key) const
 * Returns true if the wrapped JSON value at @e key is a string.
 *
 * @note QtMark JSON stores all strings internally as QStrings.
 */

/**
 * @fn bool QMJsonObject::isArray(const QString &key) const
 * Returns true if the wrapped JSON value at @e key is a JSON array
 */

/**
 * @fn bool QMJsonObject::isObject(const QString &key) const
 * Returns true if the wrapped JSON value at @e key is a JSON object
 */

/**
 * @fn bool QMJsonObject::is(const QString &key) const
 * Returns true if the wrapped JSON value at @e key is of type T.
 * This function is ment to be used with custom, complex types as show below:
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
 * @fn bool QMJsonObject::toBool(const QString &key) const
 * Unwraps the JSON value at @e key and returns the interanl type.
 * Depending on what type the JSON value is, will dictate what is returned:
 *
 * - null: false
 * - bool: true / falue (native)
 * - double: false if the value is 0, true otherwise
 * - string: true if the value is "true", false otherwise
 * - else: false
 */

/**
 * @fn double QMJsonObject::toDouble(const QString &key) const
 * Unwraps the JSON value at @e key and returns the interanl type.
 * Depending on what type the JSON value is, will dictate what is returned:
 *
 * - null: 0
 * - bool: false = 0, true = 1
 * - double: double (native)
 * - string: string converted to double, 0 if conversion fails.
 * - else: 0
 */

/**
 * @fn QString QMJsonObject::toString(const QString &key) const
 * Unwraps the JSON value at @e key and returns the interanl type.
 * Depending on what type the JSON value is, will dictate what is returned:
 *
 * - null: "null"
 * - bool: "true" if true, "false" if false
 * - double: double converted to string
 * - string: string (native)
 * - else: 0
 */

/**
 * @fn const QMPointer<QMJsonArray> &QMJsonObject::toArray(const QString &key) const
 * Unwraps the JSON value at @e key and returns a QMJsonArray.
 * If the internal type is not a QMJsonArray, an empty QMJsonArray is returned.
 */

/**
 * @fn const QMPointer<QMJsonObject> &QMJsonObject::toObject(const QString &key) const
 * Unwraps the JSON value at @e key and returns a QMJsonObject.
 * If the internal type is not a QMJsonObject, an empty QMJsonObject is
 * returned.
 */

/**
 * @fn bool QMJsonObject::toBool(const QString &key, bool defaultValue) const
 * Unwraps the JSON value at @e key and returns the interanl type.
 * If the interal type is not a boolean, the default value is returned instead.
 */

/**
 * @fn double QMJsonObject::toDouble(const QString &key, double defaultValue) const
 * Unwraps the JSON value at @e key and returns the interanl type. If
 * the interal type is not a double, the default value is returned instead.
 */

/**
 * @fn const QString &QMJsonObject::toString(const QString &key, const QString &defaultValue) const
 * Unwraps the JSON value at @e key and returns the interanl type.
 * If the interal type is not a string, the default value is returned instead.
 */

/**
 * @fn virtual const QMPointer<QMJsonArray> &QMJsonObject::toArray(const QString &key, const QMPointer<QMJsonArray> &defaultValue) const
 * Unwraps the JSON value at @e key and returns the interanl type. If
 * the interal type is not an array, the default value is returned instead.
 */

/**
 * @fn virtual const QMPointer<QMJsonObject> &QMJsonObject::toObject(const QString &key, const QMPointer<QMJsonObject> &defaultValue) const
 * Unwraps the JSON value at @e key and returns the interanl type.
 * If the interal type is not an object, the default value is returned instead.
 */

/**
 * @fn const T &QMJsonObject::to(const QString &key, const T &defaultValue) const
 * Unwraps the JSON value at @e key and returns the interanl type.
 * If the interal type is not of type T, the default value is returned instead.
 * This function is ment to be used with custom, complex types as show below:
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
 * @fn bool QMJsonObject::fromBool(const QString &key, bool value)
 * Unwraps the JSON value at @e key and sets the interanl type.
 * Depending on what type the JSON value is, will dictate what the internal
 * type is set to:
 *
 * - null: (ignored, returns false)
 * - bool: true / falue (native)
 * - double: 0 if false, 1 if true
 * - string: "false" if false, "true" if true
 * - else: (ignored, returns false)
 */

 /**
 * @fn bool QMJsonObject::fromDouble(const QString &key, double value)
 * Unwraps the JSON value at @e key and sets the interanl type.
 * Depending on what type the JSON value is, will dictate what the internal
 * type is set to:
 *
 * - null: (ignored, returns false)
 * - bool: false if 0, true otherwise
 * - double: double (native)
 * - string: double converted to string
 * - else: (ignored, returns false)
 */

 /**
 * @fn bool QMJsonObject::fromString(const QString &key, const QString &value);
 * Unwraps the JSON value at @e key and sets the interanl type.
 * Depending on what type the JSON value is, will dictate what the
 * internal type is set to:
 *
 * - null: (ignored, returns false)
 * - bool: true if "true", false otherwise
 * - double: string converted to double. 0 if conversion fails.
 * - string: string (native)
 * - else: (ignored, returns false)
 */

/**
 * @fn bool QMJsonObject::fromArray(const QString &key, const QMPointer<QMJsonArray> &value);
 * Unwraps the JSON value at @e key and sets the internal type to a
 * QMJsonArray. If the internal type is not a QMJsonArray, the request is
 * ignored
 */

/**
 * @fn bool QMJsonObject::fromObject(const QString &key, const QMPointer<QMJsonObject> &value);
 * Unwraps the JSON value at @e key and sets the internal type to a
 * QMJsonObject. If the internal type is not a QMJsonObject, the request is
 * ignored
 */

 /**
 * @fn bool QMJsonObject::from(const QString &key, const QMPointer<QMJsonValue> &value);
 * Unwraps the JSON value at @e key and sets the interanl type. Depending
 * on what type the JSON value is, will dictate what the internal type
 * is set to:
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
 * @fn bool QMJsonObject::from(const QString &key, const T &value)
 * Unwraps the JSON value at @e key and sets the interanl type. If the internal
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
