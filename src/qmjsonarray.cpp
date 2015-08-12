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

QMJsonArray::~QMJsonArray()
{
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

    while(this->count() > 0)
        this->removeFirst();
}

int32_t QMJsonArray::count(void) const
{
    return mList.count();
}

bool QMJsonArray::contains(const QMPointer<QMJsonValue> &value) const
{
    (void)value;

    // This function is here to catch when developers use this function with
    // QMJsonValue, which you cannot do. Remember that the value that is
    // stored within QMJsonValue is what you actually care about. The QMJsonValue
    // itself has no meaning because the pointer can be created automatically
    // multiple times. The value within however should always be the same,
    // so please use that instead. For example:
    //
    // QMPointer<QMJsonValue> test1 = new QMJsonValue(99);
    // QMPointer<QMJsonValue> test2 = new QMJsonValue(98);
    // QMPointer<QMJsonValue> test3 = new QMJsonValue(97);
    //
    // QMPointer<QMJsonArray> array = new QMJsonArray;
    // array->append(test1);
    // array->append(test2);
    // array->append(test3);
    //
    // Bad: array->contains(test1);
    // Good: array->contains(test1->toInt());

    return false;
}

int32_t QMJsonArray::indexOf(const QMPointer<QMJsonValue> &value) const
{
    (void)value;

    // This function is here to catch when developers use this function with
    // QMJsonValue, which you cannot do. Remember that the value that is
    // stored within QMJsonValue is what you actually care about. The QMJsonValue
    // itself has no meaning because the pointer can be created automatically
    // multiple times. The value within however should always be the same,
    // so please use that instead. For example:
    //
    // QMPointer<QMJsonValue> test1 = new QMJsonValue(99);
    // QMPointer<QMJsonValue> test2 = new QMJsonValue(98);
    // QMPointer<QMJsonValue> test3 = new QMJsonValue(97);
    //
    // QMPointer<QMJsonArray> array = new QMJsonArray;
    // array->append(test1);
    // array->append(test2);
    // array->append(test3);
    //
    // Bad: array->indexOf(test1);
    // Good: array->indexOf(test1->toInt());

    return -1;
}

void QMJsonArray::prepend(const QMPointer<QMJsonValue> &value)
{
    this->insert(0, value);
}

void QMJsonArray::append(const QMPointer<QMJsonValue> &value)
{
    this->insert(count(), value);
}

void QMJsonArray::insert(int32_t index, const QMPointer<QMJsonValue> &value)
{
    if(index <= 0) index = 0;
    if(index >= mList.count()) index = mList.count();

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

void QMJsonArray::prepend(const char *value)
{
    this->insert(0, QString(value));
}

void QMJsonArray::append(const char *value)
{
    this->insert(this->count(), QString(value));
}

void QMJsonArray::insert(int32_t index, char *value)
{
    this->insert(index, QString(value));
}

void QMJsonArray::unite(const QMPointer<QMJsonArray> &array)
{
    if(array.isNull() == true)
        return;

    for(const auto &value : array->values())
        this->append(value);
}

void QMJsonArray::removeAt(int32_t index)
{
    if(index < 0 || index >= count())
        return;

    emit itemRemoved(index, mList.takeAt(index));
}

void QMJsonArray::removeFirst(void)
{
    this->removeAt(0);
}

void QMJsonArray::removeLast(void)
{
    this->removeAt(this->count() - 1);
}

QMPointer<QMJsonValue> QMJsonArray::value(int32_t index) const
{
    if(index < 0 || index >= this->count())
        return QMPointer<QMJsonValue>(new QMJsonValue);

    return mList[index];
}

QList<QMPointer<QMJsonValue> > QMJsonArray::values(void) const
{
    return mList;
}

bool QMJsonArray::isBool(int32_t index) const
{
    if(index < 0 || index >= this->count())
        return false;

    return mList[index]->isBool();
}

bool QMJsonArray::isDouble(int32_t index) const
{
    if(index < 0 || index >= this->count())
        return false;

    return mList[index]->isDouble();
}

bool QMJsonArray::isString(int32_t index) const
{
    if(index < 0 || index >= this->count())
        return false;

    return mList[index]->isString();
}

bool QMJsonArray::isArray(int32_t index) const
{
    if(index < 0 || index >= this->count())
        return false;

    return mList[index]->isArray();
}

bool QMJsonArray::isObject(int32_t index) const
{
    if(index < 0 || index >= this->count())
        return false;

    return mList[index]->isObject();
}

bool QMJsonArray::isJsonObject(int32_t index) const
{
    if(index < 0 || index >= this->count())
        return false;

    return mList[index]->isJsonObject();
}

#ifdef QM_GUI_ENABLED

bool QMJsonArray::isRect(int32_t index) const
{
    if(index < 0 || index >= this->count())
        return false;

    return mList[index]->isRect();
}

bool QMJsonArray::isSize(int32_t index) const
{
    if(index < 0 || index >= this->count())
        return false;

    return mList[index]->isSize();
}

bool QMJsonArray::isPoint(int32_t index) const
{
    if(index < 0 || index >= this->count())
        return false;

    return mList[index]->isPoint();
}

bool QMJsonArray::isColor(int32_t index) const
{
    if(index < 0 || index >= this->count())
        return false;

    return mList[index]->isColor();
}

#endif

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

QMPointer<QMJsonArray> QMJsonArray::toArray(int32_t index) const
{
    return this->value(index)->toArray();
}

QMPointer<QMJsonObject> QMJsonArray::toObject(int32_t index) const
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

QString QMJsonArray::toString(int32_t index, const QString &defaultValue) const
{
    return this->value(index)->toString(defaultValue);
}

QMPointer<QMJsonArray> QMJsonArray::toArray(int32_t index, const QMPointer<QMJsonArray> &defaultValue) const
{
    return this->value(index)->toArray(defaultValue);
}

QMPointer<QMJsonObject> QMJsonArray::toObject(int32_t index, const QMPointer<QMJsonObject> &defaultValue) const
{
    return this->value(index)->toObject(defaultValue);
}

#ifdef QM_GUI_ENABLED

QRect QMJsonArray::toRect(int32_t index) const
{
    return this->value(index)->toRect();
}

QSize QMJsonArray::toSize(int32_t index) const
{
    return this->value(index)->toSize();
}

QPoint QMJsonArray::toPoint(int32_t index) const
{
    return this->value(index)->toPoint();
}

QColor QMJsonArray::toColor(int32_t index) const
{
    return this->value(index)->toColor();
}

QRect QMJsonArray::toRect(int32_t index, const QRect &defaultValue) const
{
    return this->value(index)->toRect(defaultValue);
}

QSize QMJsonArray::toSize(int32_t index, const QSize &defaultValue) const
{
    return this->value(index)->toSize(defaultValue);
}

QPoint QMJsonArray::toPoint(int32_t index, const QPoint &defaultValue) const
{
    return this->value(index)->toPoint(defaultValue);
}

QColor QMJsonArray::toColor(int32_t index, const QColor &defaultValue) const
{
    return this->value(index)->toColor(defaultValue);
}

#endif

const char *QMJsonArray::toChar(int32_t index) const
{
    return this->value(index)->toChar();
}

short QMJsonArray::toShort(int32_t index) const
{
    return this->value(index)->toShort();
}

unsigned short QMJsonArray::toUShort(int32_t index) const
{
    return this->value(index)->toUShort();
}

int QMJsonArray::toInt(int32_t index) const
{
    return this->value(index)->toInt();
}

unsigned int QMJsonArray::toUInt(int32_t index) const
{
    return this->value(index)->toUInt();
}

long QMJsonArray::toLong(int32_t index) const
{
    return this->value(index)->toLong();
}

unsigned long QMJsonArray::toULong(int32_t index) const
{
    return this->value(index)->toULong();
}

long long QMJsonArray::toLongLong(int32_t index) const
{
    return this->value(index)->toLongLong();
}

unsigned long long QMJsonArray::toULongLong(int32_t index) const
{
    return this->value(index)->toULongLong();
}

const char *QMJsonArray::toChar(int32_t index, const char *defaultValue) const
{
    return this->value(index)->toChar(defaultValue);
}

short QMJsonArray::toShort(int32_t index, short defaultValue) const
{
    return this->value(index)->toShort(defaultValue);
}

unsigned short QMJsonArray::toUShort(int32_t index, unsigned short defaultValue) const
{
    return this->value(index)->toUShort(defaultValue);
}

int QMJsonArray::toInt(int32_t index, int defaultValue) const
{
    return this->value(index)->toInt(defaultValue);
}

unsigned int QMJsonArray::toUInt(int32_t index, unsigned int defaultValue) const
{
    return this->value(index)->toUInt(defaultValue);
}

long QMJsonArray::toLong(int32_t index, long defaultValue) const
{
    return this->value(index)->toLong(defaultValue);
}

unsigned long QMJsonArray::toULong(int32_t index, unsigned long defaultValue) const
{
    return this->value(index)->toULong(defaultValue);
}

long long QMJsonArray::toLongLong(int32_t index, long long defaultValue) const
{
    return this->value(index)->toLongLong(defaultValue);
}

unsigned long long QMJsonArray::toULongLong(int32_t index, unsigned long long defaultValue) const
{
    return this->value(index)->toULongLong(defaultValue);
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

#ifdef QM_GUI_ENABLED

bool QMJsonArray::fromRect(int32_t index, const QRect &value)
{
    return this->value(index)->fromRect(value);
}

bool QMJsonArray::fromSize(int32_t index, const QSize &value)
{
    return this->value(index)->fromSize(value);
}

bool QMJsonArray::fromPoint(int32_t index, const QPoint &value)
{
    return this->value(index)->fromPoint(value);
}

bool QMJsonArray::fromColor(int32_t index, const QColor &value)
{
    return this->value(index)->fromColor(value);
}

#endif

bool QMJsonArray::fromChar(int32_t index, const char *value)
{
    return this->value(index)->fromChar(value);
}

bool QMJsonArray::fromShort(int32_t index, short value)
{
    return this->value(index)->fromShort(value);
}

bool QMJsonArray::fromUShort(int32_t index, unsigned short value)
{
    return this->value(index)->fromUShort(value);
}

bool QMJsonArray::fromInt(int32_t index, int value)
{
    return this->value(index)->fromInt(value);
}

bool QMJsonArray::fromUInt(int32_t index, unsigned int value)
{
    return this->value(index)->fromUInt(value);
}

bool QMJsonArray::fromLong(int32_t index, long value)
{
    return this->value(index)->fromLong(value);
}

bool QMJsonArray::fromULong(int32_t index, unsigned long value)
{
    return this->value(index)->fromULong(value);
}

bool QMJsonArray::fromLongLong(int32_t index, long long value)
{
    return this->value(index)->fromLongLong(value);
}

bool QMJsonArray::fromULongLong(int32_t index, unsigned long long value)
{
    return this->value(index)->fromULongLong(value);
}

QDebug operator<<(QDebug dbg, const QMJsonArray &array)
{
    auto started = false;

    auto space = dbg.autoInsertSpaces();
    dbg.setAutoInsertSpaces(false);

    dbg << "QMJsonArray";
    dbg << "[";

    for(const auto &value : array.values())
    {
        if(started == true)
            dbg << ",";

        dbg << value;
        started = true;
    }

    dbg << "]";

    dbg.setAutoInsertSpaces(space);
    return dbg;
}

QDebug operator<<(QDebug dbg, const QMPointer<QMJsonArray> &value)
{
    if (value.isNull() == true)
    {
        auto space = dbg.autoInsertSpaces();
        dbg.setAutoInsertSpaces(false);

        dbg << "QMPointer<";
        dbg << "QMJsonArray" << ">: NULL";

        dbg.setAutoInsertSpaces(space);
        return dbg;
    }
    else
    {
        return dbg << *value;
    }
}
