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
    virtual bool isEmpty(void) const;

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

    virtual void unite(const QMPointer<QMJsonArray> &array);

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

    virtual QMPointer<QMJsonValue> first(void) const;
    virtual QMPointer<QMJsonValue> last(void) const;
    virtual QMPointer<QMJsonValue> value(int32_t index) const;
    virtual QMPointer<QMJsonValue> value(int32_t index, const QMPointer<QMJsonValue> &defaultValue) const;
    template<class T> QMPointer<QMJsonValue> value(int32_t index, const T &defaultValue) const;

    virtual QList<QMPointer<QMJsonValue> > values(void) const;
    virtual QList<QMPointer<QMJsonValue> > mid(int32_t pos, int32_t length = -1) const;

    virtual void move(int32_t from, int32_t to);
    virtual void replace(int32_t index, const QMPointer<QMJsonValue> &value);

    virtual bool isBool(int32_t index) const;
    virtual bool isDouble(int32_t index) const;
    virtual bool isString(int32_t index) const;
    virtual bool isArray(int32_t index) const;
    virtual bool isObject(int32_t index) const;
    template<class T> bool is(int32_t index) const;

    virtual bool toBool(int32_t index) const;
    virtual double toDouble(int32_t index) const;
    virtual QString toString(int32_t index) const;
    virtual QMPointer<QMJsonArray> toArray(int32_t index) const;
    virtual QMPointer<QMJsonObject> toObject(int32_t index) const;

    virtual bool toBool(int32_t index, bool defaultValue) const;
    virtual double toDouble(int32_t index, double defaultValue) const;
    virtual QString toString(int32_t index, const QString &defaultValue) const;
    virtual QMPointer<QMJsonArray> toArray(int32_t index, const QMPointer<QMJsonArray> &defaultValue) const;
    virtual QMPointer<QMJsonObject> toObject(int32_t index, const QMPointer<QMJsonObject> &defaultValue) const;
    template<class T> T to(int32_t index, const T &defaultValue) const;

    virtual float toFloat(int32_t index) const;
    virtual char toChar(int32_t index) const;
    virtual unsigned char toUChar(int32_t index) const;
    virtual short toShort(int32_t index) const;
    virtual unsigned short toUShort(int32_t index) const;
    virtual int toInt(int32_t index) const;
    virtual unsigned int toUInt(int32_t index) const;
    virtual long toLong(int32_t index) const;
    virtual unsigned long toULong(int32_t index) const;
    virtual long long toLongLong(int32_t index) const;
    virtual unsigned long long toULongLong(int32_t index) const;

    virtual float toFloat(int32_t index, float defaultValue) const;
    virtual char toChar(int32_t index, char defaultValue) const;
    virtual unsigned char toUChar(int32_t index, unsigned char defaultValue) const;
    virtual short toShort(int32_t index, short defaultValue) const;
    virtual unsigned short toUShort(int32_t index, unsigned short defaultValue) const;
    virtual int toInt(int32_t index, int defaultValue) const;
    virtual unsigned int toUInt(int32_t index, unsigned int defaultValue) const;
    virtual long toLong(int32_t index, long defaultValue) const;
    virtual unsigned long toULong(int32_t index, unsigned long defaultValue) const;
    virtual long long toLongLong(int32_t index, long long defaultValue) const;
    virtual unsigned long long toULongLong(int32_t index, unsigned long long defaultValue) const;

    virtual bool fromBool(int32_t index, bool value);
    virtual bool fromDouble(int32_t index, double value);
    virtual bool fromString(int32_t index, const QString &value);
    virtual bool fromArray(int32_t index, const QMPointer<QMJsonArray> &value);
    virtual bool fromObject(int32_t index, const QMPointer<QMJsonObject> &value);
    template <class T> bool from(int32_t index, const T &value);

    virtual bool fromFloat(int32_t index, float value);
    virtual bool fromChar(int32_t index, char value);
    virtual bool fromUChar(int32_t index, unsigned char value);
    virtual bool fromShort(int32_t index, short value);
    virtual bool fromUShort(int32_t index, unsigned short value);
    virtual bool fromInt(int32_t index, int value);
    virtual bool fromUInt(int32_t index, unsigned int value);
    virtual bool fromLong(int32_t index, long value);
    virtual bool fromULong(int32_t index, unsigned long value);
    virtual bool fromLongLong(int32_t index, long long value);
    virtual bool fromULongLong(int32_t index, unsigned long long value);

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
bool QMJsonArray::is(int32_t index) const
{
    if(index < 0 || index >= this->count())
        return false;

    return mList[index]->is<T>();
}

template<class T>
T QMJsonArray::to(int32_t index, const T &defaultValue) const
{
    return this->value(index)->to<T>(defaultValue);
}

template<class T>
bool QMJsonArray::from(int32_t index, const T &value)
{
    return this->value(index)->from<T>(value);
}

#endif // QMJSONARRAY_H
