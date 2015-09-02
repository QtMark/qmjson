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

// ============================================================================
// Includes
// ============================================================================

#include <qmjsonarray.h>
#include <qmjsonobject.h>

// ============================================================================
// QMJsonArray Implementation
// ============================================================================

QMJsonArray::QMJsonArray()
{
}

QMJsonArray::QMJsonArray(const QList<QMPointer<QMJsonValue> > &list)
{
    mList = list;
}

QMJsonArray::~QMJsonArray()
{
}

void QMJsonArray::reserve(int32_t alloc)
{
    mList.reserve(alloc);
}

void QMJsonArray::clear(void)
{
    for(const auto &value : mList)
    {
        if(value->isObject() == true)
        {
            value->toObject()->clear();
            continue;
        }

        if(value->isArray() == true)
        {
            value->toArray()->clear();
            continue;
        }
    }

    while(mList.count() > 0)
        this->removeFirst();
}

int32_t QMJsonArray::count(void) const
{
    return mList.count();
}

int32_t QMJsonArray::length(void) const
{
    return mList.length();
}

int32_t QMJsonArray::size(void) const
{
    return mList.size();
}

bool QMJsonArray::isEmpty(void) const
{
    return mList.isEmpty();
}

bool QMJsonArray::empty(void) const
{
    return mList.empty();
}

bool QMJsonArray::contains(const QMPointer<QMJsonValue> &value) const
{
    return mList.contains(value);
}

int32_t QMJsonArray::indexOf(const QMPointer<QMJsonValue> &value) const
{
    return mList.indexOf(value);
}

int32_t QMJsonArray::lastIndexOf(const QMPointer<QMJsonValue> &value, int32_t from) const
{
    return mList.lastIndexOf(value, from);
}

bool QMJsonArray::endsWith(const QMPointer<QMJsonValue> &value) const
{
    return mList.endsWith(value);
}

bool QMJsonArray::startsWith(const QMPointer<QMJsonValue> &value) const
{
    return mList.startsWith(value);
}

void QMJsonArray::prepend(const QMPointer<QMJsonValue> &value)
{
    this->insert(0, value);
}

void QMJsonArray::append(const QMPointer<QMJsonValue> &value)
{
    this->insert(mList.count(), value);
}

void QMJsonArray::insert(int32_t index, const QMPointer<QMJsonValue> &value)
{
    if(index < 0) index = 0;
    if(index > mList.count()) index = mList.count();

    if(value.isNull() == true)
    {
        auto newValue = QMPointer<QMJsonValue>(new QMJsonValue);

        mList.insert(index, newValue);
        emit itemAdded(index, newValue);
    }
    else
    {
        mList.insert(index, value);
        emit itemAdded(index, value);
    }
}

void QMJsonArray::unite(const QMPointer<QMJsonArray> &array, QMJsonArrayUnitePolicy policy)
{
    if(array.isNull() == true)
        return;

    for(const auto &value : array->values())
    {
        switch(policy)
        {
            case QMJsonArrayUnitePolicy_Prepend:
                this->prepend(value);
                break;

            case QMJsonArrayUnitePolicy_Append:
                this->append(value);
                break;
        }
    }
}

void QMJsonArray::removeAll(const QMPointer<QMJsonValue> &value)
{
    while(mList.contains(value) == true)
        this->removeAt(mList.indexOf(value));
}

void QMJsonArray::removeOne(const QMPointer<QMJsonValue> &value)
{
    this->removeAt(mList.indexOf(value));
}

void QMJsonArray::removeAt(int32_t index)
{
    if(index < 0 || index >= mList.count())
        return;

    emit itemRemoved(index, mList.takeAt(index));
}

void QMJsonArray::removeFirst(void)
{
    this->removeAt(0);
}

void QMJsonArray::removeLast(void)
{
    this->removeAt(mList.count() - 1);
}

QMPointer<QMJsonValue> QMJsonArray::takeFirst(void)
{
    return this->takeAt(0);
}

QMPointer<QMJsonValue> QMJsonArray::takeLast(void)
{
    return this->takeAt(mList.count() - 1);
}

QMPointer<QMJsonValue> QMJsonArray::takeAt(int32_t index)
{
    if(index < 0 || index >= mList.count())
        return QMPointer<QMJsonValue>(new QMJsonValue);

    auto value = mList.takeAt(index);

    emit itemRemoved(index, value);
    return value;
}

QMPointer<QMJsonValue> QMJsonArray::takeAt(int32_t index, const QMPointer<QMJsonValue> &defaultValue)
{
    if(index < 0 || index >= mList.count())
        return defaultValue;

    auto value = mList.takeAt(index);

    emit itemRemoved(index, value);
    return value;
}

const QMPointer<QMJsonValue> &QMJsonArray::front(void) const
{
    static auto defaultValue = QMPointer<QMJsonValue>(new QMJsonValue);

    if(mList.isEmpty() == true)
        return defaultValue;

    return mList.front();
}

const QMPointer<QMJsonValue> &QMJsonArray::back(void) const
{
    static auto defaultValue = QMPointer<QMJsonValue>(new QMJsonValue);

    if(mList.isEmpty() == true)
        return defaultValue;

    return mList.back();
}

const QMPointer<QMJsonValue> &QMJsonArray::value(int32_t index) const
{
    static auto defaultValue = QMPointer<QMJsonValue>(new QMJsonValue);

    if(index < 0 || index >= mList.count())
        return defaultValue;

    return mList.at(index);
}

const QMPointer<QMJsonValue> &QMJsonArray::value(int32_t index, const QMPointer<QMJsonValue> &defaultValue) const
{
    if(index < 0 || index >= mList.count())
        return defaultValue;

    return mList.at(index);
}

QList<QMPointer<QMJsonValue> > QMJsonArray::values(void) const
{
    return mList;
}

QList<QMPointer<QMJsonValue> > QMJsonArray::mid(int32_t pos, int32_t length) const
{
    if(mList.count() == 0)
        return QList<QMPointer<QMJsonValue> >();

    if(pos >= mList.count())
        return QList<QMPointer<QMJsonValue> >();

    if(pos < 0) pos = 0;

    return mList.mid(pos, length);
}

void QMJsonArray::move(int32_t from, int32_t to)
{
    if(mList.count() == 0)
        return;

    if(to < 0 || to >= mList.count()) return;
    if(from < 0 || from >= mList.count()) return;
    if(to == from) return;

    mList.move(from, to);
}

void QMJsonArray::replace(int32_t index, const QMPointer<QMJsonValue> &value)
{
    if(index < 0)
        return;

    if(index >= mList.count())
        return;

    auto removedValue = mList.at(index);

    if(value.isNull() == true)
        mList.replace(index, QMPointer<QMJsonValue>(new QMJsonValue));
    else
        mList.replace(index, value);

    emit itemRemoved(index, removedValue);
    emit itemAdded(index, value);
}

bool QMJsonArray::isNull(int32_t index) const
{
    if(index < 0 || index >= mList.count())
        return false;

    return mList.at(index)->isNull();
}

bool QMJsonArray::isBool(int32_t index) const
{
    if(index < 0 || index >= mList.count())
        return false;

    return mList.at(index)->isBool();
}

bool QMJsonArray::isDouble(int32_t index) const
{
    if(index < 0 || index >= mList.count())
        return false;

    return mList.at(index)->isDouble();
}

bool QMJsonArray::isString(int32_t index) const
{
    if(index < 0 || index >= mList.count())
        return false;

    return mList.at(index)->isString();
}

bool QMJsonArray::isArray(int32_t index) const
{
    if(index < 0 || index >= mList.count())
        return false;

    return mList.at(index)->isArray();
}

bool QMJsonArray::isObject(int32_t index) const
{
    if(index < 0 || index >= mList.count())
        return false;

    return mList.at(index)->isObject();
}

bool QMJsonArray::toBool(int32_t index) const
{
    return this->value(index)->toBool();
}

double QMJsonArray::toDouble(int32_t index) const
{
    return this->value(index)->toDouble();
}

QString QMJsonArray::toString(int32_t index) const
{
    return this->value(index)->toString();
}

const QMPointer<QMJsonArray> &QMJsonArray::toArray(int32_t index) const
{
    return this->value(index)->toArray();
}

const QMPointer<QMJsonObject> &QMJsonArray::toObject(int32_t index) const
{
    return this->value(index)->toObject();
}

bool QMJsonArray::toBool(int32_t index, bool defaultValue) const
{
    return this->value(index)->toBool(defaultValue);
}

double QMJsonArray::toDouble(int32_t index, double defaultValue) const
{
    return this->value(index)->toDouble(defaultValue);
}

const QString &QMJsonArray::toString(int32_t index, const QString &defaultValue) const
{
    return this->value(index)->toString(defaultValue);
}

const QMPointer<QMJsonArray> &QMJsonArray::toArray(int32_t index, const QMPointer<QMJsonArray> &defaultValue) const
{
    return this->value(index)->toArray(defaultValue);
}

const QMPointer<QMJsonObject> &QMJsonArray::toObject(int32_t index, const QMPointer<QMJsonObject> &defaultValue) const
{
    return this->value(index)->toObject(defaultValue);
}

bool QMJsonArray::fromBool(int32_t index, bool value)
{
    return this->value(index)->fromBool(value);
}

bool QMJsonArray::fromDouble(int32_t index, double value)
{
    return this->value(index)->fromDouble(value);
}

bool QMJsonArray::fromString(int32_t index, const QString &value)
{
    return this->value(index)->fromString(value);
}

bool QMJsonArray::fromArray(int32_t index, const QMPointer<QMJsonArray> &value)
{
    return this->value(index)->fromArray(value);
}

bool QMJsonArray::fromObject(int32_t index, const QMPointer<QMJsonObject> &value)
{
    return this->value(index)->fromObject(value);
}

bool QMJsonArray::from(int32_t index, const QMPointer<QMJsonValue> &value)
{
    return this->value(index)->from(value);
}

QDebug operator<<(QDebug dbg, const QMJsonArray &array)
{
    QDebugStateSaver saver(dbg);
    auto started = false;

    dbg.nospace() << "QMJsonArray[";

    for(const auto &value : array.values())
    {
        if(started == true)
            dbg << ",";

        dbg << value;
        started = true;
    }

    return dbg << "]";
}

QDebug operator<<(QDebug dbg, const QMPointer<QMJsonArray> &value)
{
    if(value.isNull() == true)
    {
        QDebugStateSaver saver(dbg);

        dbg.nospace() << "QMPointer<";
        dbg << "QMJsonArray" << ">: NULL";

        return dbg;
    }
    else
    {
        return dbg << *value;
    }
}
