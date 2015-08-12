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

void QMJsonObject::clear(void)
{
    for(const auto &value : mHash)
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

    for(const auto &key : this->keys())
        this->remove(key);
}

int32_t QMJsonObject::count(void) const
{
    return mHash.count();
}

bool QMJsonObject::contains(const QString &key) const
{
    return mHash.contains(key);
}

void QMJsonObject::insert(const QString &key, const QMPointer<QMJsonValue> &value)
{
    if(mHash.contains(key) == true)
        this->remove(key);

    if(value.isNull() == true)
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

void QMJsonObject::insert(const QString &key, const char *value)
{
    this->insert(key, QString(value));
}

void QMJsonObject::unite(const QMPointer<QMJsonObject> &object)
{
    if(object.isNull() == true)
        return;

    for(const auto &key : object->keys())
    {
        if(this->contains(key) == true)
        {
            const auto &value1 = this->value(key);
            const auto &value2 = object->value(key);

            if(value1->isObject() && value2->isObject())
            {
                value1->toObject()->unite(value2->toObject());
                continue;
            }

            if(value1->isArray() && value2->isArray())
            {
                value1->toArray()->unite(value2->toArray());
                continue;
            }

            this->insert(key, value2);
        }
        else
        {
            this->insert(key, object->value(key));
        }
    }
}

void QMJsonObject::remove(const QString &key)
{
    emit itemRemoved(key, mHash.take(key));
}

QList<QString> QMJsonObject::keys(void) const
{
    return mHash.keys();
}

QMPointer<QMJsonValue> QMJsonObject::value(const QString &key) const
{
    if(mHash.contains(key) == false)
        return QMPointer<QMJsonValue>(new QMJsonValue);

    return mHash.value(key);
}

QList<QMPointer<QMJsonValue> > QMJsonObject::values(void) const
{
    return mHash.values();
}

bool QMJsonObject::isBool(const QString &key) const
{
    auto iter = mHash.find(key);

    if(iter == mHash.end())
        return false;

    return iter.value()->isBool();
}

bool QMJsonObject::isDouble(const QString &key) const
{
    auto iter = mHash.find(key);

    if(iter == mHash.end())
        return false;

    return iter.value()->isDouble();
}

bool QMJsonObject::isString(const QString &key) const
{
    auto iter = mHash.find(key);

    if(iter == mHash.end())
        return false;

    return iter.value()->isString();
}

bool QMJsonObject::isArray(const QString &key) const
{
    auto iter = mHash.find(key);

    if(iter == mHash.end())
        return false;

    return iter.value()->isArray();
}

bool QMJsonObject::isObject(const QString &key) const
{
    auto iter = mHash.find(key);

    if(iter == mHash.end())
        return false;

    return iter.value()->isObject();
}

bool QMJsonObject::isJsonObject(const QString &key) const
{
    auto iter = mHash.find(key);

    if(iter == mHash.end())
        return false;

    return iter.value()->isJsonObject();
}

#ifdef QM_GUI_ENABLED

bool QMJsonObject::isRect(const QString &key) const
{
    auto iter = mHash.find(key);

    if(iter == mHash.end())
        return false;

    return iter.value()->isRect();
}

bool QMJsonObject::isSize(const QString &key) const
{
    auto iter = mHash.find(key);

    if(iter == mHash.end())
        return false;

    return iter.value()->isSize();
}

bool QMJsonObject::isPoint(const QString &key) const
{
    auto iter = mHash.find(key);

    if(iter == mHash.end())
        return false;

    return iter.value()->isPoint();
}

bool QMJsonObject::isColor(const QString &key) const
{
    auto iter = mHash.find(key);

    if(iter == mHash.end())
        return false;

    return iter.value()->isColor();
}

#endif

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

QMPointer<QMJsonArray> QMJsonObject::toArray(const QString &key) const
{
    return this->value(key)->toArray();
}

QMPointer<QMJsonObject> QMJsonObject::toObject(const QString &key) const
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

QString QMJsonObject::toString(const QString &key, const QString &defaultValue) const
{
    return this->value(key)->toString(defaultValue);
}

QMPointer<QMJsonArray> QMJsonObject::toArray(const QString &key, const QMPointer<QMJsonArray> &defaultValue) const
{
    return this->value(key)->toArray(defaultValue);
}

QMPointer<QMJsonObject> QMJsonObject::toObject(const QString &key, const QMPointer<QMJsonObject> &defaultValue) const
{
    return this->value(key)->toObject(defaultValue);
}

#ifdef QM_GUI_ENABLED

QRect QMJsonObject::toRect(const QString &key) const
{
    return this->value(key)->toRect();
}

QSize QMJsonObject::toSize(const QString &key) const
{
    return this->value(key)->toSize();
}

QPoint QMJsonObject::toPoint(const QString &key) const
{
    return this->value(key)->toPoint();
}

QColor QMJsonObject::toColor(const QString &key) const
{
    return this->value(key)->toColor();
}

QRect QMJsonObject::toRect(const QString &key, const QRect &defaultValue) const
{
    return this->value(key)->toRect(defaultValue);
}

QSize QMJsonObject::toSize(const QString &key, const QSize &defaultValue) const
{
    return this->value(key)->toSize(defaultValue);
}

QPoint QMJsonObject::toPoint(const QString &key, const QPoint &defaultValue) const
{
    return this->value(key)->toPoint(defaultValue);
}

QColor QMJsonObject::toColor(const QString &key, const QColor &defaultValue) const
{
    return this->value(key)->toColor(defaultValue);
}

#endif

const char *QMJsonObject::toChar(const QString &key) const
{
    return this->value(key)->toChar();
}

short QMJsonObject::toShort(const QString &key) const
{
    return this->value(key)->toShort();
}

unsigned short QMJsonObject::toUShort(const QString &key) const
{
    return this->value(key)->toUShort();
}

int QMJsonObject::toInt(const QString &key) const
{
    return this->value(key)->toInt();
}

unsigned int QMJsonObject::toUInt(const QString &key) const
{
    return this->value(key)->toUInt();
}

long QMJsonObject::toLong(const QString &key) const
{
    return this->value(key)->toLong();
}

unsigned long QMJsonObject::toULong(const QString &key) const
{
    return this->value(key)->toULong();
}

long long QMJsonObject::toLongLong(const QString &key) const
{
    return this->value(key)->toLongLong();
}

unsigned long long QMJsonObject::toULongLong(const QString &key) const
{
    return this->value(key)->toULongLong();
}

const char *QMJsonObject::toChar(const QString &key, const char *defaultValue) const
{
    return this->value(key)->toChar(defaultValue);
}

short QMJsonObject::toShort(const QString &key, short defaultValue) const
{
    return this->value(key)->toShort(defaultValue);
}

unsigned short QMJsonObject::toUShort(const QString &key, unsigned short defaultValue) const
{
    return this->value(key)->toUShort(defaultValue);
}

int QMJsonObject::toInt(const QString &key, int defaultValue) const
{
    return this->value(key)->toInt(defaultValue);
}

unsigned int QMJsonObject::toUInt(const QString &key, unsigned int defaultValue) const
{
    return this->value(key)->toUInt(defaultValue);
}

long QMJsonObject::toLong(const QString &key, long defaultValue) const
{
    return this->value(key)->toLong(defaultValue);
}

unsigned long QMJsonObject::toULong(const QString &key, unsigned long defaultValue) const
{
    return this->value(key)->toULong(defaultValue);
}

long long QMJsonObject::toLongLong(const QString &key, long long defaultValue) const
{
    return this->value(key)->toLongLong(defaultValue);
}

unsigned long long QMJsonObject::toULongLong(const QString &key, unsigned long long defaultValue) const
{
    return this->value(key)->toULongLong(defaultValue);
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

#ifdef QM_GUI_ENABLED

bool QMJsonObject::fromRect(const QString &key, const QRect &value)
{
    return this->value(key)->fromRect(value);
}

bool QMJsonObject::fromSize(const QString &key, const QSize &value)
{
    return this->value(key)->fromSize(value);
}

bool QMJsonObject::fromPoint(const QString &key, const QPoint &value)
{
    return this->value(key)->fromPoint(value);
}

bool QMJsonObject::fromColor(const QString &key, const QColor &value)
{
    return this->value(key)->fromColor(value);
}

#endif

bool QMJsonObject::fromChar(const QString &key, const char *value)
{
    return this->value(key)->fromChar(value);
}

bool QMJsonObject::fromShort(const QString &key, short value)
{
    return this->value(key)->fromShort(value);
}

bool QMJsonObject::fromUShort(const QString &key, unsigned short value)
{
    return this->value(key)->fromUShort(value);
}

bool QMJsonObject::fromInt(const QString &key, int value)
{
    return this->value(key)->fromInt(value);
}

bool QMJsonObject::fromUInt(const QString &key, unsigned int value)
{
    return this->value(key)->fromUInt(value);
}

bool QMJsonObject::fromLong(const QString &key, long value)
{
    return this->value(key)->fromLong(value);
}

bool QMJsonObject::fromULong(const QString &key, unsigned long value)
{
    return this->value(key)->fromULong(value);
}

bool QMJsonObject::fromLongLong(const QString &key, long long value)
{
    return this->value(key)->fromLongLong(value);
}

bool QMJsonObject::fromULongLong(const QString &key, unsigned long long value)
{
    return this->value(key)->fromULongLong(value);
}

QDebug operator<<(QDebug dbg, const QMJsonObject &object)
{
    auto started = false;

    auto space = dbg.autoInsertSpaces();
    dbg.setAutoInsertSpaces(false);

    dbg << "QMJsonObject";
    dbg << "{";

    for(const auto &key : object.keys())
    {
        if(started == true)
            dbg << ",";

        dbg << key << ":" << object.value(key);
        started = true;
    }

    dbg << "}";

    dbg.setAutoInsertSpaces(space);
    return dbg;
}

QDebug operator<<(QDebug dbg, const QMPointer<QMJsonObject> &value)
{
    if (value.isNull() == true)
    {
        auto space = dbg.autoInsertSpaces();
        dbg.setAutoInsertSpaces(false);

        dbg << "QMPointer<";
        dbg << "QMJsonObject" << ">: NULL";

        dbg.setAutoInsertSpaces(space);
        return dbg;
    }
    else
    {
        return dbg << *value;
    }
}
