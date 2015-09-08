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

#ifndef QMJSONARRAY_H
#define QMJSONARRAY_H

// ============================================================================
// Libraries
// ============================================================================

#include <qmjsonvalue.h>

// ============================================================================
// Class Definition
// ============================================================================

class QM_JSON_EXPORT QMJsonArray : public QObject
{
    Q_OBJECT

public:

    QMJsonArray();
    explicit QMJsonArray(const QList<QMPointer<QMJsonValue> > &list);
    virtual ~QMJsonArray();

    virtual void reserve(int32_t alloc);

    virtual void clear(void);

    virtual int32_t count(void) const;
    virtual int32_t length(void) const;
    virtual int32_t size(void) const;

    virtual bool isEmpty(void) const;
    virtual bool empty(void) const;

    virtual bool contains(const QMPointer<QMJsonValue> &value) const;
    virtual int32_t indexOf(const QMPointer<QMJsonValue> &value) const;
    virtual int32_t lastIndexOf(const QMPointer<QMJsonValue> &value, int32_t from = -1) const;

    virtual bool endsWith(const QMPointer<QMJsonValue> &value) const;
    virtual bool startsWith(const QMPointer<QMJsonValue> &value) const;

    virtual void prepend(const QMPointer<QMJsonValue> &value);
    virtual void append(const QMPointer<QMJsonValue> &value);
    virtual void insert(int32_t index, const QMPointer<QMJsonValue> &value);
    template<class T> void prepend(const T &value);
    template<class T> void append(const T &value);
    template<class T> void insert(int32_t index, const T &value);

    virtual void unite(const QMPointer<QMJsonArray> &array, QMJsonArrayUnitePolicy policy = QMJsonArrayUnitePolicy_Append);

    virtual void removeAll(const QMPointer<QMJsonValue> &value);
    virtual void removeOne(const QMPointer<QMJsonValue> &value);
    virtual void removeAt(int32_t index);
    virtual void removeFirst(void);
    virtual void removeLast(void);

    virtual QMPointer<QMJsonValue> takeFirst(void);
    virtual QMPointer<QMJsonValue> takeLast(void);
    virtual QMPointer<QMJsonValue> takeAt(int32_t index);
    virtual QMPointer<QMJsonValue> takeAt(int32_t index, const QMPointer<QMJsonValue> &defaultValue);
    template<class T> QMPointer<QMJsonValue> takeAt(int32_t index, const T &defaultValue);

    virtual const QMPointer<QMJsonValue> &front(void) const;
    virtual const QMPointer<QMJsonValue> &back(void) const;
    virtual const QMPointer<QMJsonValue> &value(int32_t index) const;
    virtual const QMPointer<QMJsonValue> &value(int32_t index, const QMPointer<QMJsonValue> &defaultValue) const;
    template<class T> QMPointer<QMJsonValue> value(int32_t index, const T &defaultValue) const;

    virtual QList<QMPointer<QMJsonValue> > values(void) const;
    virtual QList<QMPointer<QMJsonValue> > mid(int32_t pos, int32_t length = -1) const;

    virtual void move(int32_t from, int32_t to);
    virtual void replace(int32_t index, const QMPointer<QMJsonValue> &value);
    template<class T> void replace(int32_t index, const T &value);

    virtual bool isNull(int32_t index) const;
    virtual bool isBool(int32_t index) const;
    virtual bool isDouble(int32_t index) const;
    virtual bool isString(int32_t index) const;
    virtual bool isArray(int32_t index) const;
    virtual bool isObject(int32_t index) const;
    template<class T> bool is(int32_t index) const;

    virtual bool toBool(int32_t index) const;
    virtual double toDouble(int32_t index) const;
    virtual QString toString(int32_t index) const;
    virtual const QMPointer<QMJsonArray> &toArray(int32_t index) const;
    virtual const QMPointer<QMJsonObject> &toObject(int32_t index) const;

    virtual bool toBool(int32_t index, bool defaultValue) const;
    virtual double toDouble(int32_t index, double defaultValue) const;
    virtual const QString &toString(int32_t index, const QString &defaultValue) const;
    virtual const QMPointer<QMJsonArray> &toArray(int32_t index, const QMPointer<QMJsonArray> &defaultValue) const;
    virtual const QMPointer<QMJsonObject> &toObject(int32_t index, const QMPointer<QMJsonObject> &defaultValue) const;
    template<class T> const T &to(int32_t index, const T &defaultValue) const;

    virtual bool fromBool(int32_t index, bool value);
    virtual bool fromDouble(int32_t index, double value);
    virtual bool fromString(int32_t index, const QString &value);
    virtual bool fromArray(int32_t index, const QMPointer<QMJsonArray> &value);
    virtual bool fromObject(int32_t index, const QMPointer<QMJsonObject> &value);
    virtual bool from(int32_t index, const QMPointer<QMJsonValue> &value);
    template <class T> bool from(int32_t index, const T &value);

signals:

    void itemAdded(int32_t index, const QMPointer<QMJsonValue> &value);
    void itemRemoved(int32_t index, const QMPointer<QMJsonValue> &value);

private:

    Q_DISABLE_COPY(QMJsonArray);

    QList<QMPointer<QMJsonValue> > mList;
};

QDebug QM_JSON_EXPORT operator<<(QDebug dbg, const QMJsonArray &array);
QDebug QM_JSON_EXPORT operator<<(QDebug dbg, const QMPointer<QMJsonArray> &value);

// ============================================================================
// Class Implementation
// ============================================================================

template<class T>
void QMJsonArray::prepend(const T &value)
{
    this->prepend(QMPointer<QMJsonValue>(new QMJsonValue(value)));
}

template<class T>
void QMJsonArray::append(const T &value)
{
    this->append(QMPointer<QMJsonValue>(new QMJsonValue(value)));
}

template<class T>
void QMJsonArray::insert(int32_t index, const T &value)
{
    this->insert(index, QMPointer<QMJsonValue>(new QMJsonValue(value)));
}

template<class T>
QMPointer<QMJsonValue> QMJsonArray::takeAt(int32_t index, const T &defaultValue)
{
    if(index < 0 || index >= mList.count())
        return QMPointer<QMJsonValue>(new QMJsonValue(defaultValue));

    auto value = mList.takeAt(index);

    emit itemRemoved(index, value);
    return value;
}

template<class T>
QMPointer<QMJsonValue> QMJsonArray::value(int32_t index, const T &defaultValue) const
{
    if(index < 0 || index >= mList.count())
        return QMPointer<QMJsonValue>(new QMJsonValue(defaultValue));

    return mList.at(index);
}

template<class T>
void QMJsonArray::replace(int32_t index, const T &value)
{
    this->replace(index, QMPointer<QMJsonValue>(new QMJsonValue(value)));
}

template<class T>
bool QMJsonArray::is(int32_t index) const
{
    if(index < 0 || index >= this->count())
        return false;

    return mList.at(index)->is<T>();
}

template<class T>
const T &QMJsonArray::to(int32_t index, const T &defaultValue) const
{
    return this->value(index)->to<T>(defaultValue);
}

template<class T>
bool QMJsonArray::from(int32_t index, const T &value)
{
    return this->value(index)->from<T>(value);
}

#endif // QMJSONARRAY_H

/**
 * @page qmjsonarray QMJsonArray Overview
 *
 * The QMJsonArray implements a JSON array. Internally, the QMJsonArray is
 * a QList<QMPointer<QMJsonValue> >. Thus, all of the rules that apply to
 * QList with respect to performance are basically the same with QMJsonArray.
 * Like the rest of the QtMark JSON Library, all of the QMJsonValues stored
 * in the QMJsonArray as stored as QMPointers.
 *
 * ### Creation
 *
 * Like all of the classes in this library, QMJsonArray must be created using
 * a managed QMPointer.
 *
 * @code
 *
 * auto array = QMPointer<QMJsonArray>(new QMJsonArray());
 *
 * @endcode
 *
 * ### Array Manipulation
 *
 * There are a number of ways to add to QMJsonArray:
 *
 * - QMJsonArray::append
 * - QMJsonArray::prepend
 * - QMJsonArray::insert
 *
 * There is no needed to manually wrap a value in a QMJsonValue, as this
 * will be done for you:
 *
 * @code
 *
 * auto array = QMPointer<QMJsonArray>(new QMJsonArray());
 * array->append(4.8);
 *
 * @endcode
 *
 * There are also a number of functions to remove an item from the
 * QMJsonArray. The major ones are:
 *
 * - QMJsonArray::removeAt
 * - QMJsonArray::takeAt
 *
 * ### Array Information
 *
 * QMJsonArray::isEmpty will tell you if the QMJsonArray has any QMJsonValues
 * in it. You can also call QMJsonArray::count to get the current number of
 * QMJsonValues in the QMJsonArray.
 *
 * @code
 *
 * auto array = QMPointer<QMJsonArray>(new QMJsonArray());
 * array->append(4.8);
 *
 * qDebug() << array->isEmpty(); // false
 * qDebug() << array->count(); // 1
 *
 * @endcode
 *
 * ### Lookup Functions
 *
 * There are number of functions that perform their operations by doing a
 * lookup using an existing QMJsonValue.
 *
 * - QMJsonArray::contains
 * - QMJsonArray::indexOf
 * - QMJsonArray::lastIndexOf
 * - QMJsonArray::endsWith
 * - QMJsonArray::startsWith
 * - QMJsonArray::removeAll
 * - QMJsonArray::removeOne
 *
 * These functions do a pointer comparison to validate that the QMJsonValue being
 * referenced has been found. This means that currently, you cannot create
 * a second QMJsonValue with the same wrapped value, and expect these functions
 * to perform the intended results.
 *
 * @code
 *
 * auto array = QMPointer<QMJsonArray>(new QMJsonArray());
 * auto value = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
 * array->append(15.16);
 * array->append(value);
 *
 * qDebug() << array->contains(value); // true
 * qDebug() << array->contains(new QMJsonValue(4.8)); // false
 * qDebug() << array->contains(new QMJsonValue(15.16)); // false
 *
 * @endcode
 *
 * ### Convenience Functions
 *
 * Both the QMJsonObject and QMJsonArray classes provide the QMJsonValue
 * unwrap functions for convenience. This applies for:
 *
 * - QMJsonArray::is
 * - QMJsonArray::to
 * - QMJsonArray::from
 *
 * Allowing for shorthand conversions:
 *
 * @code
 *
 * auto array = QMPointer<QMJsonArray>(new QMJsonArray());
 * array->append(4.8);
 *
 * qDebug() << array->toDouble(0); // 4.8
 * qDebug() << array->toString(0); // "4.8"
 *
 * // Instead of
 *
 * qDebug() << array->value(0)->toDouble(); // 4.8
 * qDebug() << array->value(0)->toString(); // "4.8"
 *
 * @endcode
 *
 * ### To / From JSON
 *
 * To convert a QMJsonArray to JSON, you must wrap the QMJsonArray in a
 * QMJsonValue and use QMJsonValue::toJson and QMJsonValue::fromJson
 *
 * @code
 *
 * auto array = QMPointer<QMJsonArray>(new QMJsonArray());
 * auto document = QMPointer<QMJsonValue>(new QMJsonValue(array));
 * array->append(4.8);
 *
 * qDebug() << document->toJson(QMJsonFormat_Optimized); // "[4.8]"
 *
 * @endcode
 *
 */

/**
 * @fn QMJsonArray::QMJsonArray()
 * Default constructor, creates an empty QMJsonArray
 */

/**
 * @fn QMJsonArray::QMJsonArray(const QList<QMPointer<QMJsonValue> > &list)
 * Overloaded constructor, create a QMJsonArray and fills it with the
 * QMJsonValues provided in @e list
 */

/**
 * @fn void QMJsonArray::clear(void)
 * Clears the QMJsonArray
 */

/**
 * @fn int32_t QMJsonArray::count(void) const
 * Returns the number of QMJsonValues in the QMJsonArray
 */

/**
 * @fn int32_t QMJsonArray::length(void) const
 * Returns the number of QMJsonValues in the QMJsonArray
 */

/**
 * @fn int32_t QMJsonArray::size(void) const
 * Returns the number of QMJsonValues in the QMJsonArray
 */

/**
 * @fn bool QMJsonArray::isEmpty(void) const
 * Returns true if the QMJsonArray is empty
 */

/**
 * @fn bool QMJsonArray::empty(void) const
 * Returns true if the QMJsonArray is empty
 */

/**
 * @fn bool QMJsonArray::contains(const QMPointer<QMJsonValue> &value) const
 * Returns true is the QMJsonArray contains @e value.
 *
 * @note This function is doing a pointer comparison. It is not comparing the
 * value contained within the QMJsonValue with other QMJsonValues in the array.
 * Currently this library does not provide such comparisons.
 */

/**
 * @fn int32_t QMJsonArray::indexOf(const QMPointer<QMJsonValue> &value) const
 * Returns the index of @e if the QMJsonArray contains @e value, otherwise
 * returns -1
 *
 * @note This function is doing a pointer comparison. It is not comparing the
 * value contained within the QMJsonValue with other QMJsonValues in the array.
 * Currently this library does not provide such comparisons.
 */

/**
 * @fn int32_t QMJsonArray::lastIndexOf(const QMPointer<QMJsonValue> &value, int32_t from = -1) const
 * Returns the last index of @e if the QMJsonArray contains @e value, otherwise
 * returns -1
 *
 * @note This function is doing a pointer comparison. It is not comparing the
 * value contained within the QMJsonValue with other QMJsonValues in the array.
 * Currently this library does not provide such comparisons.
 */

/**
 * @fn bool QMJsonArray::endsWith(const QMPointer<QMJsonValue> &value) const
 * Returns true is the QMJsonArray ends with @e value.
 *
 * @note This function is doing a pointer comparison. It is not comparing the
 * value contained within the QMJsonValue with other QMJsonValues in the array.
 * Currently this library does not provide such comparisons.
 */

/**
 * @fn bool QMJsonArray::startsWith(const QMPointer<QMJsonValue> &value) const
 * Returns true is the QMJsonArray starts with @e value.
 *
 * @note This function is doing a pointer comparison. It is not comparing the
 * value contained within the QMJsonValue with other QMJsonValues in the array.
 * Currently this library does not provide such comparisons.
 */

/**
 * @fn void QMJsonArray::prepend(const QMPointer<QMJsonValue> &value)
 * Prepends @e value to the front of the QMJsonArray. If @e value is NULL, this
 * operation is ignored
 */

/**
 * @fn void QMJsonArray::append(const QMPointer<QMJsonValue> &value)
 * Appends @e value to the end of the QMJsonArray. If @e value is NULL, this
 * operation is ignored
 */

/**
 * @fn void QMJsonArray::insert(int32_t index, const QMPointer<QMJsonValue> &value)
 * Inserts @e value into the QMJsonArray. If index is less then 0, @e value is
 * prepended to the front of QMJsonArray. If index is greater than or equal to
 * the size of the QMJsonArray, @e value is appended to the end of QMJsonArray.
 * If @e value is NULL, this operation is ignored
 */

/**
 * @fn template<class T> void QMJsonArray::prepend(const T &value)
 * Wraps @e value in a QMJsonValue and prepends @e value to the front of the
 * QMJsonArray.
 */

/**
 * @fn template<class T> void QMJsonArray::append(const T &value)
 * Wraps @e value in a QMJsonValue and appends @e value to the end of the
 * QMJsonArray
 */

/**
 * @fn template<class T> void QMJsonArray::insert(int32_t index, const T &value)
 * Wraps @e value in a QMJsonValue and inserts @e value into the QMJsonArray.
 * If index is less then 0, @e value is prepended to the front of QMJsonArray.
 * If index is greater than or equal to the size of the QMJsonArray, @e value
 * is appended to the end of QMJsonArray
 */

/**
 * @fn void QMJsonArray::unite(const QMPointer<QMJsonArray> &array, QMJsonArrayUnitePolicy policy = QMJsonArrayUnitePolicy_Append)
 * Unites this QMJsonArray with @e array by appending all the QMJsonValues in
 * @e array to this QMJsonArray. If @e policy is set to
 * QMJsonArrayUnitePolicy_Prepend, the QMJsonValues in @e array are prepended
 * to this QMJsonArray. If @e array is NULL, this operation is ignored.
 */

/**
 * @fn void QMJsonArray::removeAll(const QMPointer<QMJsonValue> &value)
 * Removes all instances of @e value from the QMJsonArray.
 */

/**
 * @fn void QMJsonArray::removeOne(const QMPointer<QMJsonValue> &value)
 * Removes the first instance of @e value from the QMJsonArray.
 *
 * @note This is faster if you know that only one instance of @e value is in
 * the QMJsonArray
 */

/**
 * @fn void QMJsonArray::removeAt(int32_t index)
 * Removes the QMJsonValue at @e index. If @e index is less then 0, or greater
 * than or equal to the length of the QMJsonArray, this operation is ignored.
 */

/**
 * @fn void QMJsonArray::removeFirst(void)
 * Removes the first QMJsonValue in the QMJsonArray. If the QMJsonArray is
 * empty, this operation is ignored.
 */

/**
 * @fn void QMJsonArray::removeLast(void)
 * Removes the last QMJsonValue in the QMJsonArray. If the QMJsonArray is
 * empty, this operation is ignored.
 */

/**
 * @fn QMPointer<QMJsonValue> QMJsonArray::takeFirst(void)
 * Removes the first QMJsonValue in the QMJsonArray and returns the removed
 * QMJsonValue. If the QMJsonArray is empty, this operation returns a newly
 * constructed, default QMJsonValue
 */

/**
 * @fn QMPointer<QMJsonValue> QMJsonArray::takeLast(void)
 * Removes the last QMJsonValue in the QMJsonArray and returns the removed
 * QMJsonValue. If the QMJsonArray is empty, this operation returns a newly
 * constructed, default QMJsonValue
 */

/**
 * @fn QMPointer<QMJsonValue> QMJsonArray::takeAt(int32_t index)
 * Removes the QMJsonValue at @e index and returns the removed
 * QMJsonValue. If @e index is less than 0 or greater than or equal to the
 * length of this QMJsonArray, this operation returns a newly constructed,
 * default QMJsonValue
 */

/**
 * @fn QMPointer<QMJsonValue> QMJsonArray::takeAt(int32_t index, const QMPointer<QMJsonValue> &defaultValue)
 * Removes the QMJsonValue at @e index and returns the removed
 * QMJsonValue. If @e index is less than 0 or greater than or equal to the
 * length of this QMJsonArray, this operation returns @e defaultValue
 */

/**
 * @fn template<class T> QMPointer<QMJsonValue> QMJsonArray::takeAt(int32_t index, const T &defaultValue)
 * Removes the QMJsonValue at @e index and returns the removed
 * QMJsonValue. If @e index is less than 0 or greater than or equal to the
 * length of this QMJsonArray, this operation returns @e defaultValue wrapped
 * in a QMJsonValue
 */

/**
 * @fn const QMPointer<QMJsonValue> &QMJsonArray::front(void) const
 * Returns the first QMJsonValue in the QMJsonArray. If the QMJsonArray is
 * empty, a default constructed QMJsonValue is returned.
 */

/**
 * @fn const QMPointer<QMJsonValue> &QMJsonArray::back(void) const
 * Returns the last QMJsonValue in the QMJsonArray. If the QMJsonArray is
 * empty, a default constructed QMJsonValue is returned.
 */

/**
 * @fn const QMPointer<QMJsonValue> &QMJsonArray::value(int32_t index) const
 * Returns the QMJsonValue from the QMJsonArray at @e index. If @e index is
 * less than 0 or greater than or equal to the QMJsonArray's length,
 * a default constructed QMJsonValue is returned.
 */

/**
 * @fn const QMPointer<QMJsonValue> &QMJsonArray::value(int32_t index, const QMPointer<QMJsonValue> &defaultValue) const
 * Returns the QMJsonValue from the QMJsonArray at @e index. If @e index is
 * less than 0 or greater than or equal to the QMJsonArray's length,
 * @e defaultValue is returned.
 */

/**
 * @fn template<class T> QMPointer<QMJsonValue> QMJsonArray::value(int32_t index, const T &defaultValue) const
 * Returns the QMJsonValue from the QMJsonArray at @e index. If @e index is
 * less than 0 or greater than or equal to the QMJsonArray's length,
 * @e defaultValue is wrapped in a QMJsonValue and then returned.
 */

/**
 * @fn QList<QMPointer<QMJsonValue> > QMJsonArray::values(void) const
 * Returns the internal QList of QMJsonValues.
 */

/**
 * @fn QList<QMPointer<QMJsonValue> > QMJsonArray::mid(int32_t pos, int32_t length = -1) const;
 * Returns a section of the internal QList of QMJsonValues. If the internal
 * list is empty, an empty QList is returned. If @e pos is greater than or equal
 * to the length of the internal QList, an empty QList is returned. If the
 * @e pos is less than 0, pos is set to 0. If the @e length + @e pos is greater
 * than the total number of QMJsonValues in the QList, the rest of the QList
 * starting at @e pos is returned.
 */

/**
 * @fn void QMJsonArray::move(int32_t from, int32_t to)
 * Moves one element from index @e from, to index @e to. If the internal
 * QList is empty, this operation is ignored. If the @e from or @e to is
 * less than 0, or greater than or equal to the length of the QMJsonArray,
 * the operation is ignored. If @e to is equal to @e from, the operation
 * is ignored.
 */

/**
 * @fn void QMJsonArray::replace(int32_t index, const QMPointer<QMJsonValue> &value)
 * Replaced the QMJsonValue at @e index with @e value. If @e index is less than
 * 0 or greater than or equal to the QMJsonArray's length, the opration is
 * ignored. If @e value is NULL a default constructed QMJsonValue is used
 * instead.
 *
 * @note This function first emits itemRemoved for the QMJsonValue currently
 * in the QMJsonArray, and then emits itemAdded for @e value. These signals
 * are emitted after @e value has already replaced the previous QMJsonValue.
 * Querying the QMJsonArray during the itemRemoved signal wil result in
 * @e value showing up in it's place.
 */

/**
 * @fn void QMJsonArray::replace(int32_t index, const QMPointer<QMJsonValue> &value)
 * Replaced the QMJsonValue at @e index with @e value wrapped in a QMJsonValue.
 * If @e index is less than 0 or greater than or equal to the QMJsonArray's
 * length, the opration is ignored. If @e value is NULL a default constructed
 * QMJsonValue is used instead.
 *
 * @note This function first emits itemRemoved for the QMJsonValue currently
 * in the QMJsonArray, and then emits itemAdded for @e value. These signals
 * are emitted after @e value has already replaced the previous QMJsonValue.
 * Querying the QMJsonArray during the itemRemoved signal wil result in
 * @e value showing up in it's place.
 */

/**
 * @fn bool QMJsonArray::isNull(int32_t index) const
 * Returns true if the wrapped JSON value at @e index is a "null".
 *
 * @note Internally, "null" QMJsonValues have no internal type pointer.
 */

/**
 * @fn bool QMJsonArray::isBool(int32_t index) const
 * Returns true if the wrapped JSON value at @e index is a boolean
 */

/**
 * @fn bool QMJsonArray::isDouble(int32_t index) const
 * Returns true if the wrapped JSON value at @e index is a double.
 *
 * @note All numbers are stored as doubles, including integer types.
 */

/**
 * @fn bool QMJsonArray::isString(int32_t index) const
 * Returns true if the wrapped JSON value at @e index is a string.
 *
 * @note QtMark JSON stores all strings internally as QStrings.
 */

/**
 * @fn bool QMJsonArray::isArray(int32_t index) const
 * Returns true if the wrapped JSON value at @e index is a JSON array
 */

/**
 * @fn bool QMJsonArray::isObject(int32_t index) const
 * Returns true if the wrapped JSON value at @e index is a JSON object
 */

/**
 * @fn bool QMJsonArray::is(int32_t index) const
 * Returns true if the wrapped JSON value at @e index is of type T.
 * This function is meant to be used with custom, complex types as shown below:
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
 * @fn bool QMJsonArray::toBool(int32_t index) const
 * Unwraps the JSON value at @e index and returns the internal type.
 * The type of the JSON value, will dictate what is returned:
 *
 * - null: false
 * - bool: true / falue (native)
 * - double: false if the value is 0, true otherwise
 * - string: true if the value is "true", false otherwise
 * - else: false
 */

/**
 * @fn double QMJsonArray::toDouble(int32_t index) const
 * Unwraps the JSON value at @e index and returns the internal type.
 * The type of the JSON value, will dictate what is returned:
 *
 * - null: 0
 * - bool: false = 0, true = 1
 * - double: double (native)
 * - string: string converted to double, 0 if conversion fails.
 * - else: 0
 */

/**
 * @fn QString QMJsonArray::toString(int32_t index) const
 * Unwraps the JSON value at @e index and returns the internal type.
 * The type of the JSON value, will dictate what is returned:
 *
 * - null: "null"
 * - bool: "true" if true, "false" if false
 * - double: double converted to string
 * - string: string (native)
 * - else: 0
 */

/**
 * @fn const QMPointer<QMJsonArray> &QMJsonArray::toArray(int32_t index) const
 * Unwraps the JSON value at @e index and returns a QMJsonArray.
 * If the internal type is not a QMJsonArray, an empty QMJsonArray is returned.
 */

/**
 * @fn const QMPointer<QMJsonObject> &QMJsonArray::toObject(int32_t index) const
 * Unwraps the JSON value at @e index and returns a QMJsonObject.
 * If the internal type is not a QMJsonObject, an empty QMJsonObject is
 * returned.
 */

/**
 * @fn bool QMJsonArray::toBool(int32_t index, bool defaultValue) const
 * Unwraps the JSON value at @e index and returns the internal type.
 * If the internal type is not a boolean, the default value is returned instead.
 */

/**
 * @fn double QMJsonArray::toDouble(int32_t index, double defaultValue) const
 * Unwraps the JSON value at @e index and returns the internal type. If
 * the internal type is not a double, the default value is returned instead.
 */

/**
 * @fn const QString &QMJsonArray::toString(int32_t index, const QString &defaultValue) const
 * Unwraps the JSON value at @e index and returns the internal type.
 * If the internal type is not a string, the default value is returned instead.
 */

/**
 * @fn virtual const QMPointer<QMJsonArray> &QMJsonArray::toArray(int32_t index, const QMPointer<QMJsonArray> &defaultValue) const
 * Unwraps the JSON value at @e index and returns the internal type. If
 * the internal type is not an array, the default value is returned instead.
 */

/**
 * @fn virtual const QMPointer<QMJsonObject> &QMJsonArray::toObject(int32_t index, const QMPointer<QMJsonObject> &defaultValue) const
 * Unwraps the JSON value at @e index and returns the internal type.
 * If the internal type is not an object, the default value is returned instead.
 */

/**
 * @fn const T &QMJsonArray::to(int32_t index, const T &defaultValue) const
 * Unwraps the JSON value at @e index and returns the internal type.
 * If the internal type is not of type T, the default value is returned instead.
 * This function is meant to be used with custom, complex types as shown below:
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
 * @fn bool QMJsonArray::fromBool(int32_t index, bool value)
 * Unwraps the JSON value at @e index and sets the internal type.
 * The type of the JSON value, will dictate what the internal
 * type is set to:
 *
 * - null: (ignored, returns false)
 * - bool: true / falue (native)
 * - double: 0 if false, 1 if true
 * - string: "false" if false, "true" if true
 * - else: (ignored, returns false)
 */

 /**
 * @fn bool QMJsonArray::fromDouble(int32_t index, double value)
 * Unwraps the JSON value at @e index and sets the internal type.
 * The type of the JSON value, will dictate what the internal
 * type is set to:
 *
 * - null: (ignored, returns false)
 * - bool: false if 0, true otherwise
 * - double: double (native)
 * - string: double converted to string
 * - else: (ignored, returns false)
 */

 /**
 * @fn bool QMJsonArray::fromString(int32_t index, const QString &value);
 * Unwraps the JSON value at @e index and sets the internal type.
 * The type of the JSON value, will dictate what the
 * internal type is set to:
 *
 * - null: (ignored, returns false)
 * - bool: true if "true", false otherwise
 * - double: string converted to double. 0 if conversion fails.
 * - string: string (native)
 * - else: (ignored, returns false)
 */

/**
 * @fn bool QMJsonArray::fromArray(int32_t index, const QMPointer<QMJsonArray> &value);
 * Unwraps the JSON value at @e index and sets the internal type to a
 * QMJsonArray. If the internal type is not a QMJsonArray, the request is
 * ignored
 */

/**
 * @fn bool QMJsonArray::fromObject(int32_t index, const QMPointer<QMJsonObject> &value);
 * Unwraps the JSON value at @e index and sets the internal type to a
 * QMJsonObject. If the internal type is not a QMJsonObject, the request is
 * ignored
 */

 /**
 * @fn bool QMJsonArray::from(int32_t index, const QMPointer<QMJsonValue> &value);
 * Unwraps the JSON value at @e index and sets the internal type. The type of
 * the JSON value, will dictate what the internal type is set to:
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
 * @fn bool QMJsonArray::from(int32_t index, const T &value)
 * Unwraps the JSON value at @e index and sets the internal type. If the internal
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
