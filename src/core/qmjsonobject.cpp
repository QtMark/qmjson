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

#include <qmjsonobject.h>
#include <qmjsonarray.h>

// ============================================================================
// QMJsonObject Implementation
// ============================================================================

QMJsonObject::QMJsonObject()
{
}

QMJsonObject::~QMJsonObject()
{
}

QMJsonObject::QMJsonObject(const QHash<QString, QMPointer<QMJsonValue> > &hash)
{
    mHash = hash;
}

void QMJsonObject::reserve(int32_t alloc)
{
    mHash.reserve(alloc);
}

int32_t QMJsonObject::capacity(void) const
{
    return mHash.capacity();
}

void QMJsonObject::squeeze(void)
{
    mHash.squeeze();
}

void QMJsonObject::clear(void)
{
    auto iter = mHash.begin();

    while (iter != mHash.end())
    {
        if (iter.value().isNull() == true)
            continue;

        else if (iter.value()->isObject() == true)
            iter.value()->toObject()->clear();

        else if (iter.value()->isArray() == true)
            iter.value()->toArray()->clear();

        iter = this->erase(iter);
    }
}

int32_t QMJsonObject::count(void) const
{
    return mHash.count();
}

int32_t QMJsonObject::size(void) const
{
    return mHash.size();
}

bool QMJsonObject::isEmpty(void) const
{
    return mHash.isEmpty();
}

bool QMJsonObject::empty(void) const
{
    return mHash.empty();
}

bool QMJsonObject::contains(const QString &key) const
{
    return mHash.contains(key);
}

void QMJsonObject::insert(const QString &key, const QMPointer<QMJsonValue> &value, QMJsonReplacementPolicy policy)
{
    if (key.isEmpty() == true)
        return;

    auto iter = mHash.find(key);

    if (iter != mHash.end())
    {
        switch (policy)
        {
            case QMJsonReplacementPolicy_Replace:
                this->erase(iter);
                break;

            case QMJsonReplacementPolicy_Ignore:
                return;
        };
    }

    if (value.isNull() == true)
    {
        auto newValue = QMPointer<QMJsonValue>(new QMJsonValue);

        mHash.insert(key, newValue);
        emit itemAdded(key, newValue);
    }
    else
    {
        mHash.insert(key, value);
        emit itemAdded(key, value);
    }
}

void QMJsonObject::unite(const QMPointer<QMJsonObject> &object, QMJsonReplacementPolicy replacementPolicy, QMJsonArrayUnitePolicy unitePolicy)
{
    if (object.isNull() == true)
        return;

    auto iter1 = object->cbegin();

    while (iter1 != object->cend())
    {
        auto iter2 = mHash.constFind(iter1.key());

        if (iter2 != mHash.constEnd())
        {
            const auto &value1 = iter1.value();
            const auto &value2 = iter2.value();

            if (value1.isNull() == true ||
                value2.isNull() == true)
            {
                continue;
            }

            else if (value1->isObject() && value2->isObject())
                value2->toObject()->unite(value1->toObject(), replacementPolicy, unitePolicy);

            else if (value1->isArray() && value2->isArray())
                value2->toArray()->unite(value1->toArray(), unitePolicy);

            else
                this->insert(iter1.key(), value1, replacementPolicy);
        }
        else
        {
            this->insert(iter1.key(), iter1.value(), replacementPolicy);
        }

        iter1++;
    }
}

void QMJsonObject::remove(const QString &key)
{
    auto iter = mHash.find(key);

    if (iter == mHash.end())
        return;

    this->erase(iter);
}

QMPointer<QMJsonValue> QMJsonObject::take(const QString &key)
{
    auto iter = mHash.find(key);

    if (iter == mHash.end())
        return QMPointer<QMJsonValue>(new QMJsonValue);

    this->erase(iter);

    return iter.value();
}

QMPointer<QMJsonValue> QMJsonObject::take(const QString &key, const QMPointer<QMJsonValue> &defaultValue)
{
    auto iter = mHash.find(key);

    if (iter == mHash.end())
        return defaultValue;

    this->erase(iter);

    return iter.value();
}

const QString QMJsonObject::key(const QMPointer<QMJsonValue> &value) const
{
    return mHash.key(value);
}

const QString QMJsonObject::key(const QMPointer<QMJsonValue> &value, const QString &defaultValue) const
{
    return mHash.key(value, defaultValue);
}

QHash<QString, QMPointer<QMJsonValue> >::iterator QMJsonObject::begin(void)
{
    return mHash.begin();
}

QHash<QString, QMPointer<QMJsonValue> >::iterator QMJsonObject::end(void)
{
    return mHash.end();
}

QHash<QString, QMPointer<QMJsonValue> >::const_iterator QMJsonObject::cbegin(void) const
{
    return mHash.cbegin();
}

QHash<QString, QMPointer<QMJsonValue> >::const_iterator QMJsonObject::cend(void) const
{
    return mHash.cend();
}

const QHash<QString, QMPointer<QMJsonValue> >::iterator QMJsonObject::erase(const QHash<QString, QMPointer<QMJsonValue> >::iterator &iter)
{
    if (iter == mHash.end())
        return mHash.end();

    auto key = iter.key();
    auto value = iter.value();

    auto niter = mHash.erase(iter);
    emit itemRemoved(key, value);

    return niter;
}

QHash<QString, QMPointer<QMJsonValue> >::iterator QMJsonObject::find(const QString &key)
{
    return mHash.find(key);
}

const QHash<QString, QMPointer<QMJsonValue> >::const_iterator QMJsonObject::cfind(const QString &key) const
{
    return mHash.constFind(key);
}

const QMPointer<QMJsonValue> &QMJsonObject::value(const QString &key) const
{
    auto iter = mHash.constFind(key);
    static auto defaultValue = QMPointer<QMJsonValue>(new QMJsonValue);

    if (iter == mHash.constEnd())
        return defaultValue;

    return iter.value();
}

const QMPointer<QMJsonValue> &QMJsonObject::value(const QString &key, const QMPointer<QMJsonValue> &defaultValue) const
{
    auto iter = mHash.constFind(key);

    if (iter == mHash.constEnd())
        return defaultValue;

    return iter.value();
}

QList<QString> QMJsonObject::keys(void) const
{
    return mHash.keys();
}

QList<QMPointer<QMJsonValue> > QMJsonObject::values(void) const
{
    return mHash.values();
}

QHash<QString, QMPointer<QMJsonValue> > QMJsonObject::hash(void) const
{
    return mHash;
}

bool QMJsonObject::isNull(const QString &key) const
{
    auto iter = mHash.constFind(key);

    if (iter == mHash.constEnd())
        return false;

    return iter.value()->isNull();
}

bool QMJsonObject::isBool(const QString &key) const
{
    auto iter = mHash.constFind(key);

    if (iter == mHash.constEnd())
        return false;

    return iter.value()->isBool();
}

bool QMJsonObject::isDouble(const QString &key) const
{
    auto iter = mHash.constFind(key);

    if (iter == mHash.constEnd())
        return false;

    return iter.value()->isDouble();
}

bool QMJsonObject::isString(const QString &key) const
{
    auto iter = mHash.constFind(key);

    if (iter == mHash.constEnd())
        return false;

    return iter.value()->isString();
}

bool QMJsonObject::isArray(const QString &key) const
{
    auto iter = mHash.constFind(key);

    if (iter == mHash.constEnd())
        return false;

    return iter.value()->isArray();
}

bool QMJsonObject::isObject(const QString &key) const
{
    auto iter = mHash.constFind(key);

    if (iter == mHash.constEnd())
        return false;

    return iter.value()->isObject();
}

bool QMJsonObject::toBool(const QString &key) const
{
    return this->value(key)->toBool();
}

double QMJsonObject::toDouble(const QString &key) const
{
    return this->value(key)->toDouble();
}

QString QMJsonObject::toString(const QString &key) const
{
    return this->value(key)->toString();
}

const QMPointer<QMJsonArray> &QMJsonObject::toArray(const QString &key) const
{
    return this->value(key)->toArray();
}

const QMPointer<QMJsonObject> &QMJsonObject::toObject(const QString &key) const
{
    return this->value(key)->toObject();
}

bool QMJsonObject::toBool(const QString &key, bool defaultValue) const
{
    return this->value(key)->toBool(defaultValue);
}

double QMJsonObject::toDouble(const QString &key, double defaultValue) const
{
    return this->value(key)->toDouble(defaultValue);
}

const QString &QMJsonObject::toString(const QString &key, const QString &defaultValue) const
{
    return this->value(key)->toString(defaultValue);
}

const QMPointer<QMJsonArray> &QMJsonObject::toArray(const QString &key, const QMPointer<QMJsonArray> &defaultValue) const
{
    return this->value(key)->toArray(defaultValue);
}

const QMPointer<QMJsonObject> &QMJsonObject::toObject(const QString &key, const QMPointer<QMJsonObject> &defaultValue) const
{
    return this->value(key)->toObject(defaultValue);
}

bool QMJsonObject::fromBool(const QString &key, bool value)
{
    return this->value(key)->fromBool(value);
}

bool QMJsonObject::fromDouble(const QString &key, double value)
{
    return this->value(key)->fromDouble(value);
}

bool QMJsonObject::fromString(const QString &key, const QString &value)
{
    return this->value(key)->fromString(value);
}

bool QMJsonObject::fromArray(const QString &key, const QMPointer<QMJsonArray> &value)
{
    return this->value(key)->fromArray(value);
}

bool QMJsonObject::fromObject(const QString &key, const QMPointer<QMJsonObject> &value)
{
    return this->value(key)->fromObject(value);
}

bool QMJsonObject::from(const QString &key, const QMPointer<QMJsonValue> &value)
{
    return this->value(key)->from(value);
}

QDebug operator<<(QDebug dbg, const QMJsonObject &object)
{
    QDebugStateSaver saver(dbg);
    auto started = false;

    dbg.nospace() << "QMJsonObject{";

    foreach (const auto &key, object.keys())
    {
        if (started == true)
            dbg << ",";

        dbg << key << ":" << object.value(key);
        started = true;
    }

    return dbg << "}";
}

QDebug operator<<(QDebug dbg, const QMPointer<QMJsonObject> &value)
{
    if (value.isNull() == true)
    {
        QDebugStateSaver saver(dbg);

        dbg.nospace() << "QMPointer<";
        dbg << "QMJsonObject" << ">: NULL";

        return dbg;
    }
    else
    {
        return dbg << *value;
    }
}
