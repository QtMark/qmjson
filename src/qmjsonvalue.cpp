//
// QtMark JSON Library
//
// Copyright (C) 2015 Assured Information Security, Inc.
// Author: Rian Quinn       <quinnr@ainfosec.com>
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
#include <qmjsonvalue.h>

#include <qmjsonarray.h>
#include <qmjsonobject.h>
#include <qmjsontype_bool.h>
#include <qmjsontype_double.h>
#include <qmjsontype_qstring.h>
#include <qmjsontype_qmjsonarray.h>
#include <qmjsontype_qmjsonobject.h>

#ifdef QM_DBUS_ENABLED
#include <QtDBus>
#endif

// ============================================================================
// Static Variables
// ============================================================================

QMap<QString, FromComplexJsonFunc> QMJsonValue::mFromFuncs;

// ============================================================================
// QMJsonValue Implementation
// ============================================================================

QMJsonValue::QMJsonValue()
{
    mType = "NULL";
}

QMJsonValue::QMJsonValue(bool value)
{
    QSharedPointer<QMJsonType<bool> > type = QSharedPointer<QMJsonType<bool> >(new QMJsonType<bool>(value));

    mType = "bool";
    mValue = type.dynamicCast<QMJsonTypeBase>();
}

QMJsonValue::QMJsonValue(double value)
{
    QSharedPointer<QMJsonType<double> > type = QSharedPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = "double";
    mValue = type.dynamicCast<QMJsonTypeBase>();
}

QMJsonValue::QMJsonValue(const QString &value)
{
    QSharedPointer<QMJsonType<QString> > type = QSharedPointer<QMJsonType<QString> >(new QMJsonType<QString>(value));

    mType = "QString";
    mValue = type.dynamicCast<QMJsonTypeBase>();
}

QMJsonValue::QMJsonValue(const QMPointer<QMJsonArray> &value)
{
    QSharedPointer<QMJsonType<QMPointer<QMJsonArray> > > type = QSharedPointer<QMJsonType<QMPointer<QMJsonArray> > >(new QMJsonType<QMPointer<QMJsonArray> >(value));

    mType = "QMPointer<QMJsonArray>";
    mValue = type.dynamicCast<QMJsonTypeBase>();
}

QMJsonValue::QMJsonValue(const QMPointer<QMJsonObject> &value)
{
    QSharedPointer<QMJsonType<QMPointer<QMJsonObject> > > type = QSharedPointer<QMJsonType<QMPointer<QMJsonObject> > >(new QMJsonType<QMPointer<QMJsonObject> >(value));

    mType = "QMPointer<QMJsonObject>";
    mValue = type.dynamicCast<QMJsonTypeBase>();
}

#ifdef QM_GUI_ENABLED

QMJsonValue::QMJsonValue(const QRect &value)
{
    QSharedPointer<QMJsonType<QRect> > type = QSharedPointer<QMJsonType<QRect> >(new QMJsonType<QRect>(value));

    mType = "QRect";
    mValue = type.dynamicCast<QMJsonTypeBase>();
}

QMJsonValue::QMJsonValue(const QSize &value)
{
    QSharedPointer<QMJsonType<QSize> > type = QSharedPointer<QMJsonType<QSize> >(new QMJsonType<QSize>(value));

    mType = "QSize";
    mValue = type.dynamicCast<QMJsonTypeBase>();
}

QMJsonValue::QMJsonValue(const QPoint &value)
{
    QSharedPointer<QMJsonType<QPoint> > type = QSharedPointer<QMJsonType<QPoint> >(new QMJsonType<QPoint>(value));

    mType = "QPoint";
    mValue = type.dynamicCast<QMJsonTypeBase>();
}

QMJsonValue::QMJsonValue(const QColor &value)
{
    QSharedPointer<QMJsonType<QColor> > type = QSharedPointer<QMJsonType<QColor> >(new QMJsonType<QColor>(value));

    mType = "QColor";
    mValue = type.dynamicCast<QMJsonTypeBase>();
}
#endif

QMJsonValue::QMJsonValue(const char *value)
{
    QSharedPointer<QMJsonType<QString> > type = QSharedPointer<QMJsonType<QString> >(new QMJsonType<QString>(value));

    mType = "QString";
    mValue = type.dynamicCast<QMJsonTypeBase>();
}

QMJsonValue::QMJsonValue(short value)
{
    QSharedPointer<QMJsonType<double> > type = QSharedPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = "double";
    mValue = type.dynamicCast<QMJsonTypeBase>();
}

QMJsonValue::QMJsonValue(unsigned short value)
{
    QSharedPointer<QMJsonType<double> > type = QSharedPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = "double";
    mValue = type.dynamicCast<QMJsonTypeBase>();
}

QMJsonValue::QMJsonValue(int value)
{
    QSharedPointer<QMJsonType<double> > type = QSharedPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = "double";
    mValue = type.dynamicCast<QMJsonTypeBase>();
}

QMJsonValue::QMJsonValue(unsigned int value)
{
    QSharedPointer<QMJsonType<double> > type = QSharedPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = "double";
    mValue = type.dynamicCast<QMJsonTypeBase>();
}

QMJsonValue::QMJsonValue(long value)
{
    QSharedPointer<QMJsonType<double> > type = QSharedPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = "double";
    mValue = type.dynamicCast<QMJsonTypeBase>();
}

QMJsonValue::QMJsonValue(unsigned long value)
{
    QSharedPointer<QMJsonType<double> > type = QSharedPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = "double";
    mValue = type.dynamicCast<QMJsonTypeBase>();
}

QMJsonValue::QMJsonValue(long long value)
{
    QSharedPointer<QMJsonType<double> > type = QSharedPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = "double";
    mValue = type.dynamicCast<QMJsonTypeBase>();
}

QMJsonValue::QMJsonValue(unsigned long long value)
{
    QSharedPointer<QMJsonType<double> > type = QSharedPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = "double";
    mValue = type.dynamicCast<QMJsonTypeBase>();
}

QMJsonValue::~QMJsonValue()
{
}

bool QMJsonValue::isNull(void) const
{
    return mValue.isNull();
}

bool QMJsonValue::isValid(void) const
{
    return !this->isNull();
}

bool QMJsonValue::isEmpty(void) const
{
    return this->isNull();
}

bool QMJsonValue::isBool(void) const
{
    return this->is<bool>();
}

bool QMJsonValue::isDouble(void) const
{
    return this->is<double>();
}

bool QMJsonValue::isString(void) const
{
    return this->is<QString>();
}

bool QMJsonValue::isArray(void) const
{
    return this->is<QMPointer<QMJsonArray> >();
}

bool QMJsonValue::isObject(void) const
{
    return this->is<QMPointer<QMJsonObject> >();
}

bool QMJsonValue::isJsonObject(void) const
{
    if(mValue.isNull() == true)
        return false;

    return this->is<QMPointer<QMJsonObject> >() || (mValue->isBaseType() == false);
}

#ifdef QM_GUI_ENABLED

bool QMJsonValue::isRect(void) const
{
    return this->is<QRect>();
}

bool QMJsonValue::isSize(void) const
{
    return this->is<QSize>();
}

bool QMJsonValue::isPoint(void) const
{
    return this->is<QPoint>();
}

bool QMJsonValue::isColor(void) const
{
    return this->is<QColor>();
}
#endif

bool QMJsonValue::toBool(void) const
{
    return this->to<bool>(false);
}

double QMJsonValue::toDouble(void) const
{
    return this->to<double>(0);
}

QString QMJsonValue::toString(void) const
{
    return this->to<QString>(QString());
}

QMPointer<QMJsonArray> QMJsonValue::toArray(void) const
{
    if(this->isArray() == false)
        return QMPointer<QMJsonArray>(new QMJsonArray);

    return this->to<QMPointer<QMJsonArray> >();
}

QMPointer<QMJsonObject> QMJsonValue::toObject(void) const
{
    if(this->isObject() == false)
        return QMPointer<QMJsonObject>(new QMJsonObject);

    return this->to<QMPointer<QMJsonObject> >();
}

bool QMJsonValue::toBool(bool defaultValue) const
{
    return this->to<bool>(defaultValue);
}

double QMJsonValue::toDouble(double defaultValue) const
{
    return this->to<double>(defaultValue);
}

QString QMJsonValue::toString(const QString &defaultValue) const
{
    return this->to<QString>(defaultValue);
}

QMPointer<QMJsonArray> QMJsonValue::toArray(const QMPointer<QMJsonArray> &defaultValue) const
{
    if(this->isArray() == false)
    {
        if(defaultValue.isNull() == true)
            return QMPointer<QMJsonArray>(new QMJsonArray);

        return defaultValue;
    }

    return this->to<QMPointer<QMJsonArray> >();
}

QMPointer<QMJsonObject> QMJsonValue::toObject(const QMPointer<QMJsonObject> &defaultValue) const
{
    if(this->isObject() == false)
    {
        if(defaultValue.isNull() == true)
            return QMPointer<QMJsonObject>(new QMJsonObject);

        return defaultValue;
    }

    return this->to<QMPointer<QMJsonObject> >();
}

#ifdef QM_GUI_ENABLED

QRect QMJsonValue::toRect(void) const
{
    return this->to<QRect>(QRect());
}

QSize QMJsonValue::toSize(void) const
{
    return this->to<QSize>(QSize());
}

QPoint QMJsonValue::toPoint(void) const
{
    return this->to<QPoint>(QPoint());
}

QColor QMJsonValue::toColor(void) const
{
    return this->to<QColor>(QColor());
}

QRect QMJsonValue::toRect(const QRect &defaultValue) const
{
    return this->to<QRect>(defaultValue);
}

QSize QMJsonValue::toSize(const QSize &defaultValue) const
{
    return this->to<QSize>(defaultValue);
}

QPoint QMJsonValue::toPoint(const QPoint &defaultValue) const
{
    return this->to<QPoint>(defaultValue);
}

QColor QMJsonValue::toColor(const QColor &defaultValue) const
{
    return this->to<QColor>(defaultValue);
}
#endif

const char *QMJsonValue::toChar(void) const
{
    return this->toString().toUtf8().constData();
}

short QMJsonValue::toShort(void) const
{
    return this->toDouble();
}

unsigned short QMJsonValue::toUShort(void) const
{
    return this->toDouble();
}

int QMJsonValue::toInt(void) const
{
    return this->toDouble();
}

unsigned int QMJsonValue::toUInt(void) const
{
    return this->toDouble();
}

long QMJsonValue::toLong(void) const
{
    return this->toDouble();
}

unsigned long QMJsonValue::toULong(void) const
{
    return this->toDouble();
}

long long QMJsonValue::toLongLong(void) const
{
    return this->toDouble();
}

unsigned long long QMJsonValue::toULongLong(void) const
{
    return this->toDouble();
}

const char *QMJsonValue::toChar(const char *defaultValue) const
{
    return this->toString(defaultValue).toUtf8().constData();
}

short QMJsonValue::toShort(short defaultValue) const
{
    return this->toDouble(defaultValue);
}

unsigned short QMJsonValue::toUShort(unsigned short defaultValue) const
{
    return this->toDouble(defaultValue);
}

int QMJsonValue::toInt(int defaultValue) const
{
    return this->toDouble(defaultValue);
}

unsigned int QMJsonValue::toUInt(unsigned int defaultValue) const
{
    return this->toDouble(defaultValue);
}

long QMJsonValue::toLong(long defaultValue) const
{
    return this->toDouble(defaultValue);
}

unsigned long QMJsonValue::toULong(unsigned long defaultValue) const
{
    return this->toDouble(defaultValue);
}

long long QMJsonValue::toLongLong(long long defaultValue) const
{
    return this->toDouble(defaultValue);
}

unsigned long long QMJsonValue::toULongLong(unsigned long long defaultValue) const
{
    return this->toDouble(defaultValue);
}

bool QMJsonValue::fromBool(bool value)
{
    return this->from<bool>(value);
}

bool QMJsonValue::fromDouble(double value)
{
    return this->from<double>(value);
}

bool QMJsonValue::fromString(const QString &value)
{
    return this->from<QString>(value);
}

bool QMJsonValue::fromArray(const QMPointer<QMJsonArray> &value)
{
    return this->from<QMPointer<QMJsonArray> >(value);
}

bool QMJsonValue::fromObject(const QMPointer<QMJsonObject> &value)
{
    return this->from<QMPointer<QMJsonObject> >(value);
}

#ifdef QM_GUI_ENABLED

bool QMJsonValue::fromRect(const QRect &value)
{
    return this->from<QRect>(value);
}

bool QMJsonValue::fromSize(const QSize &value)
{
    return this->from<QSize>(value);
}

bool QMJsonValue::fromPoint(const QPoint &value)
{
    return this->from<QPoint>(value);
}

bool QMJsonValue::fromColor(const QColor &value)
{
    return this->from<QColor>(value);
}
#endif

bool QMJsonValue::fromChar(const char *value)
{
    return this->fromString(QString(value));
}

bool QMJsonValue::fromShort(short value)
{
    return this->fromDouble(value);
}

bool QMJsonValue::fromUShort(unsigned short value)
{
    return this->fromDouble(value);
}

bool QMJsonValue::fromInt(int value)
{
    return this->fromDouble(value);
}

bool QMJsonValue::fromUInt(unsigned int value)
{
    return this->fromDouble(value);
}

bool QMJsonValue::fromLong(long value)
{
    return this->fromDouble(value);
}

bool QMJsonValue::fromULong(unsigned long value)
{
    return this->fromDouble(value);
}

bool QMJsonValue::fromLongLong(long long value)
{
    return this->fromDouble(value);
}

bool QMJsonValue::fromULongLong(unsigned long long value)
{
    return this->fromDouble(value);
}

QVariant QMJsonValue::toVariant(void)
{
    if(this->isNull() == true)
        return QVariant();

    if(this->isBool() == true)
        return QVariant(this->toBool());

    if(this->isDouble() == true)
        return QVariant(this->toDouble());

    if(this->isString() == true)
        return QVariant(this->toString());

    if(this->isArray() == true)
    {
        auto list = QVariantList();

        for(const auto &value : this->toArray()->values())
            list.append(value->toVariant());

        return QVariant::fromValue(list);
    }

    if(this->isObject() == true)
    {
        auto hash = QVariantHash();
        const auto &object = this->toObject();

        for(const auto &key : object->keys())
            hash[key] = object->value(key)->toVariant();

        return QVariant::fromValue(hash);
    }

#ifdef QM_GUI_ENABLED

    if(this->isRect() == true)
        return QVariant(this->toRect());

    if(this->isSize() == true)
        return QVariant(this->toSize());

    if(this->isPoint() == true)
        return QVariant(this->toPoint());

    if(this->isColor() == true)
        return QVariant(this->toColor());

#endif

    return QVariant();
}

QMPointer<QMJsonValue> QMJsonValue::fromVariant(const QVariant &value)
{
    switch(value.type())
    {
        case QMetaType::QVariantMap:
        case QMetaType::QVariantHash:
        {
            auto object = QMPointer<QMJsonObject>(new QMJsonObject);
            auto iterable = value.value<QAssociativeIterable>();
            auto it = iterable.begin();
            const auto end = iterable.end();

            for(; it != end; ++it)
                object->insert(it.key().toString(), QMJsonValue::fromVariant(it.value()));

            return QMPointer<QMJsonValue>(new QMJsonValue(object));
        }

        case QMetaType::QVariantList:
        {
            auto array = QMPointer<QMJsonArray>(new QMJsonArray);

            for(const auto &variant : value.value<QSequentialIterable>())
                array->append(QMJsonValue::fromVariant(variant));

            return QMPointer<QMJsonValue>(new QMJsonValue(array));
        }

        case QMetaType::Bool:
            return QMPointer<QMJsonValue>(new QMJsonValue(value.value<bool>()));

        case QMetaType::Double:
        case QMetaType::UInt:
        case QMetaType::Int:
        case QMetaType::LongLong:
        case QMetaType::ULongLong:
            return QMPointer<QMJsonValue>(new QMJsonValue(value.value<double>()));

        case QMetaType::QChar:
        case QMetaType::QByteArray:
        case QMetaType::QString:
            return QMPointer<QMJsonValue>(new QMJsonValue(value.value<QString>()));

#ifdef QM_GUI_ENABLED

        case QMetaType::QRect:
            return QMPointer<QMJsonValue>(new QMJsonValue(value.value<QRect>()));

        case QMetaType::QSize:
            return QMPointer<QMJsonValue>(new QMJsonValue(value.value<QSize>()));

        case QMetaType::QPoint:
            return QMPointer<QMJsonValue>(new QMJsonValue(value.value<QPoint>()));

        case QMetaType::QColor:
            return QMPointer<QMJsonValue>(new QMJsonValue(value.value<QColor>()));

#endif
        case QMetaType::User:
        {

#ifdef QM_DBUS_ENABLED

            if(value.canConvert<QDBusArgument>() == true)
            {
                const auto &arg = value.value<QDBusArgument>();

                switch(arg.currentType())
                {
                    case QDBusArgument::BasicType:
                    case QDBusArgument::VariantType:
                    case QDBusArgument::StructureType:
                        return QMJsonValue::fromVariant(arg.asVariant());

                    case QDBusArgument::ArrayType:
                    {
                        auto array = QMPointer<QMJsonArray>(new QMJsonArray);

                        arg.beginArray();
                        while(!arg.atEnd())
                            array->append(QMJsonValue::fromVariant(arg.asVariant()));
                        arg.endArray();

                        return QMPointer<QMJsonValue>(new QMJsonValue(array));
                    }

                    default:
                        return QMPointer<QMJsonValue>(new QMJsonValue());
                }
            }

            if(value.canConvert<QDBusObjectPath>() == true)
                return QMPointer<QMJsonValue>(new QMJsonValue(value.value<QDBusObjectPath>().path()));

            if(value.canConvert<QDBusVariant>() == true)
                return QMJsonValue::fromVariant(value.value<QDBusVariant>().variant());

#endif
            break;
        }

        default:
            break;
    }

    return QMPointer<QMJsonValue>(new QMJsonValue());
}

QString QMJsonValue::type(void) const
{
    return mType;
}

QString QMJsonValue::toJson(int32_t prettyPrint) const
{
    if(mValue.isNull() == true)
        return QString();

    // When we convert to JSON, we need to check to see if this is a base type.
    // Base types don't need to be broken up into their base types, since they
    // already are base types. If this is not a base type, it's a complex type,
    // which means that we use it's complex version of toJson instead
    if(mValue->isBaseType() == true)
    {
        return mValue->toJson(prettyPrint);
    }
    else
    {
        // Since this is a complex type, we need to first create a JSON Object,
        // so that the conversion code can convert this type to an Object
        // for us. Once this is done, we can just call the toJson on that
        // object. Note that since this is a tree structure, the conversion
        // function can provide other complex types. This same function will
        // be recursively called and will handle embedded complex types for us
        // auto-magically.
        auto obj = QMPointer<QMJsonObject>(new QMJsonObject());
        auto value = QMPointer<QMJsonValue>(new QMJsonValue(obj));

        // Do the conversion.
        mValue->toComplexJson(obj);

        // We don't really care about what's in the object since this is
        // custom, but we do care that at minimum, we have the type information.
        // Otherwise, bad things are going to happen.
        if(obj->contains("qmjsontype") == false)
            return QString();

        // Now all that is left, is to convert the class to the base types.
        // Note that the object might have complex types embedded in it, which
        // means that this code will be called again.
        return value->toJson(prettyPrint);
    }
}

QString QMJsonValue::toJsonFile(const QString &filename, int32_t prettyPrint) const
{
    QFile file(filename);
    QTextStream stream(&file);

    auto json = this->toJson(prettyPrint);

    if(file.open(QIODevice::WriteOnly | QIODevice::Text) == false)
        return QString();

    stream << json << "\r\n";

    file.flush();
    file.close();

    return json;
}

QMPointer<QMJsonValue> QMJsonValue::fromJson(const QString &json)
{
    auto index = 0;
    auto value = QMPointer<QMJsonValue>();

    try
    {
        QMJsonValue::skipSpaces(json, index);

        if(index >= json.length())
            return QMPointer<QMJsonValue>(new QMJsonValue());

        value = QMJsonValue::fromJson(json, index);

        if(value.isNull() == false)
            return value;
    }

    catch(const QString &str)
    {
        qDebug() << "QMJsonValue::fromJson Failed -" + str;
    }

    return QMPointer<QMJsonValue>(new QMJsonValue());
}

QMPointer<QMJsonValue> QMJsonValue::fromComplexJson(const QMPointer<QMJsonValue> &value)
{
    if(value.isNull() == true)
        return QMPointer<QMJsonValue>(new QMJsonValue());

    if(value->isObject() == true)
    {
        auto obj = value->toObject();

        if(obj->contains("qmjsontype") == true)
        {
            auto func = mFromFuncs[obj->value("qmjsontype")->toString()];

            if(func == NULL)
                return QMPointer<QMJsonValue>(new QMJsonValue());

            auto result = func(obj);

            if(result.isNull() == true)
                return QMPointer<QMJsonValue>(new QMJsonValue());

            return result;
        }
    }

    return value;
}

void QMJsonValue::registerFromComplexJson(const QString &qmjsontype, FromComplexJsonFunc func)
{
    if(qmjsontype.isEmpty() == true)
        return;

    if(func == NULL)
        return;

    mFromFuncs[qmjsontype] = func;
}

void QMJsonValue::skipSpaces(const QString &json, int32_t &index)
{
    while(index < json.length() && json[index].isSpace() == true)
        index++;
}

void QMJsonValue::verifyIndex(const QString &json, int32_t &index)
{
    if(index >= json.length())
        QMJsonValue::throwError(json, index, "Incomplete JSON");
}

QMPointer<QMJsonValue> QMJsonValue::fromJson(const QString &json, int32_t &index)
{
    auto value = QMPointer<QMJsonValue>();

    QMJsonValue::skipSpaces(json, index);
    QMJsonValue::verifyIndex(json, index);

    // Per the JSON spec, we are in a JSON "value" which means that we need
    // to figure out type we actually have. In other words, we need to
    // traverse this state machine:
    //
    // | --|------- string --------|-- |
    //     |------- number --------|
    //     |------- object --------|
    //     |------- array  --------|
    //     |------- true   --------|
    //     |------- false  --------|
    //     |------- null   --------|
    //
    // To do this, we need to look at "how" we can detect which type we are
    // dealing with.
    // - A string starts with "
    // - A number is the last thing we check (no good way to know up front)
    // - An object starts with {
    // - An array starts with [
    // - true, false, and null are just string comparisons.
    //
    // So the following logic takes this approach. It basically looks for
    // what type we are dealing with and attempts to parse based on what
    // the next character is.
    //
    // Note that we use a single pass implementation based on the state
    // machines outline in the JSON spec. This means that we only know
    // what we are currently looking at.
    //
    // Note that we use the default case as the number. This is because
    // there is no easy way to detect if this is a number, so we just
    // assume that if the the switch statement cannot make heads or
    // tails of the current character, that it must be a number. The number
    // logic will make sure that this is actually a number that we can parse.
    //
    // Note that this is a recursive function, so you do not know what the
    // value of index is at a given time, and you don't know what type you are
    // currently looking at. Its safe to assume that you are probably starting
    // with a JSON object or array, but other than that, all bets are off.

    switch(json[index].toLatin1())
    {
        case '"':
            return QMJsonType<QString>::fromJson(json, index);

        case '{':
            return QMJsonValue::fromComplexJson(QMJsonType<QMPointer<QMJsonObject> >::fromJson(json, index));

        case '[':
            return QMJsonType<QMPointer<QMJsonArray> >::fromJson(json, index);

        case 'T':
        case 't':
        case 'F':
        case 'f':
            return QMJsonType<bool>::fromJson(json, index);

        case 'N':
        case 'n':
        {
            auto valid = true;

            index++;

            QMJsonValue::verifyIndex(json, index); valid &= json[index].toLower() == 'u'; index++;
            QMJsonValue::verifyIndex(json, index); valid &= json[index].toLower() == 'l'; index++;
            QMJsonValue::verifyIndex(json, index); valid &= json[index].toLower() == 'l'; index++;

            if(valid == false)
                QMJsonValue::throwError(json, index, "Unexpected token. Expected \"NULL\" while parsing JSON.");

            return QMPointer<QMJsonValue>(new QMJsonValue());
        }

        case ']':
        case '}':
            QMJsonValue::throwError(json, index, "Unexpected closing bracket. Are there too many commas?");

        default:
            return QMJsonType<double>::fromJson(json, index);
    }

    return QMPointer<QMJsonValue>(new QMJsonValue());
}

QMPointer<QMJsonValue> QMJsonValue::fromJsonFile(const QString &filename)
{
    QFile file(filename);

    if(file.exists() == false)
        return QMPointer<QMJsonValue>();

    if(file.open(QIODevice::ReadOnly | QIODevice::Text) == false)
        return QMPointer<QMJsonValue>();

    return QMJsonValue::fromJson(file.readAll());
}

void QMJsonValue::throwError(const QString &json, int32_t index, QString error)
{
    throw(error + " - Line Number: " + QString::number(json.left(index).count("\n")));
}

QDebug operator<<(QDebug dbg, const QMJsonValue &value)
{
    auto space = dbg.autoInsertSpaces();
    dbg.setAutoInsertSpaces(false);

    dbg << "QMJsonValue(";

    if(value.mValue != NULL)
    {
        value.mValue->print(dbg);
        dbg << ")";
    }
    else
    {
        dbg << "NULL" << ")";
    }

    dbg.setAutoInsertSpaces(space);
    return dbg;
}

QDebug operator<<(QDebug dbg, const QMPointer<QMJsonValue> &value)
{
    if (value.isNull() == true)
    {
        auto space = dbg.autoInsertSpaces();
        dbg.setAutoInsertSpaces(false);

        dbg << "QMPointer<";
        dbg << "QMJsonValue" << ">: NULL";

        dbg.setAutoInsertSpaces(space);
        return dbg;
    }
    else
    {
        return dbg << *value;
    }
}
