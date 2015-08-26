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
    mType = QMJsonValueType_Null;
}

QMJsonValue::QMJsonValue(bool value)
{
    auto type = QMPointer<QMJsonType<bool> >(new QMJsonType<bool>(value));

    mType = QMJsonValueType_Bool;
    mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
}

QMJsonValue::QMJsonValue(double value)
{
    auto type = QMPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = QMJsonValueType_Double;
    mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
}

QMJsonValue::QMJsonValue(const QString &value)
{
    auto type = QMPointer<QMJsonType<QString> >(new QMJsonType<QString>(value));

    mType = QMJsonValueType_String;
    mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
}

QMJsonValue::QMJsonValue(const QMPointer<QMJsonValue> &value)
{
    if(value.isNull() == true)
    {
        mType = QMJsonValueType_Null;
        mValue = QMPointer<QMJsonTypeBase>();
    }
    else
    {
        mType = value->mType;
        mValue = value->mValue;
    }
}

QMJsonValue::QMJsonValue(const QMPointer<QMJsonArray> &value)
{
    mType = QMJsonValueType_Array;

    if(value.isNull() == true)
    {
        auto array = QMPointer<QMJsonArray>(new QMJsonArray());
        auto type = QMPointer<QMJsonType<QMPointer<QMJsonArray> > >(new QMJsonType<QMPointer<QMJsonArray> >(array));
        mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
    }
    else
    {
        auto type = QMPointer<QMJsonType<QMPointer<QMJsonArray> > >(new QMJsonType<QMPointer<QMJsonArray> >(value));
        mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
    }
}

QMJsonValue::QMJsonValue(const QMPointer<QMJsonObject> &value)
{
    mType = QMJsonValueType_Object;

    if(value.isNull() == true)
    {
        auto object = QMPointer<QMJsonObject>(new QMJsonObject());
        auto type = QMPointer<QMJsonType<QMPointer<QMJsonObject> > >(new QMJsonType<QMPointer<QMJsonObject> >(object));
        mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
    }
    else
    {
        auto type = QMPointer<QMJsonType<QMPointer<QMJsonObject> > >(new QMJsonType<QMPointer<QMJsonObject> >(value));
        mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
    }
}

QMJsonValue::QMJsonValue(QMJsonValue *value)
{
    if(value == NULL)
    {
        mType = QMJsonValueType_Null;
        mValue = QMPointer<QMJsonTypeBase>();
    }
    else
    {
        mType = value->mType;
        mValue = value->mValue;
    }
}

QMJsonValue::QMJsonValue(QMJsonArray *value)
{
    mType = QMJsonValueType_Array;

    if(value == NULL)
    {
        auto array = QMPointer<QMJsonArray>(new QMJsonArray());
        auto type = QMPointer<QMJsonType<QMPointer<QMJsonArray> > >(new QMJsonType<QMPointer<QMJsonArray> >(array));
        mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
    }
    else
    {
        auto array = QMPointer<QMJsonArray>(value);
        auto type = QMPointer<QMJsonType<QMPointer<QMJsonArray> > >(new QMJsonType<QMPointer<QMJsonArray> >(array));
        mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
    }
}

QMJsonValue::QMJsonValue(QMJsonObject *value)
{
    mType = QMJsonValueType_Object;

    if(value == NULL)
    {
        auto object = QMPointer<QMJsonObject>(new QMJsonObject());
        auto type = QMPointer<QMJsonType<QMPointer<QMJsonObject> > >(new QMJsonType<QMPointer<QMJsonObject> >(object));
        mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
    }
    else
    {
        auto object = QMPointer<QMJsonObject>(value);
        auto type = QMPointer<QMJsonType<QMPointer<QMJsonObject> > >(new QMJsonType<QMPointer<QMJsonObject> >(object));
        mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
    }
}

QMJsonValue::QMJsonValue(const char *value)
{
    auto type = QMPointer<QMJsonType<QString> >(new QMJsonType<QString>(value));

    mType = QMJsonValueType_String;
    mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
}

QMJsonValue::QMJsonValue(float value)
{
    auto type = QMPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = QMJsonValueType_Double;
    mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
}

QMJsonValue::QMJsonValue(char value)
{
    auto type = QMPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = QMJsonValueType_Double;
    mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
}

QMJsonValue::QMJsonValue(int8_t value)
{
    auto type = QMPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = QMJsonValueType_Double;
    mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
}

QMJsonValue::QMJsonValue(uint8_t value)
{
    auto type = QMPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = QMJsonValueType_Double;
    mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
}

QMJsonValue::QMJsonValue(int16_t value)
{
    auto type = QMPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = QMJsonValueType_Double;
    mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
}

QMJsonValue::QMJsonValue(uint16_t value)
{
    auto type = QMPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = QMJsonValueType_Double;
    mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
}

QMJsonValue::QMJsonValue(int32_t value)
{
    auto type = QMPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = QMJsonValueType_Double;
    mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
}

QMJsonValue::QMJsonValue(uint32_t value)
{
    auto type = QMPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = QMJsonValueType_Double;
    mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
}

QMJsonValue::QMJsonValue(int64_t value)
{
    auto type = QMPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = QMJsonValueType_Double;
    mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
}

QMJsonValue::QMJsonValue(uint64_t value)
{
    auto type = QMPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = QMJsonValueType_Double;
    mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
}

#if UINTPTR_MAX == 0xffffffff

QMJsonValue::QMJsonValue(long value)
{
    auto type = QMPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = QMJsonValueType_Double;
    mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
}

QMJsonValue::QMJsonValue(unsigned long value)
{
    auto type = QMPointer<QMJsonType<double> >(new QMJsonType<double>(value));

    mType = QMJsonValueType_Double;
    mValue = qSharedPointerDynamicCast<QMJsonTypeBase>(type);
}

#endif

QMJsonValue::~QMJsonValue()
{
}

bool QMJsonValue::isNull(void) const
{
    return mType == QMJsonValueType_Null;
}

bool QMJsonValue::isBool(void) const
{
    return mType == QMJsonValueType_Bool;
}

bool QMJsonValue::isDouble(void) const
{
    return mType == QMJsonValueType_Double;
}

bool QMJsonValue::isString(void) const
{
    return mType == QMJsonValueType_String;
}

bool QMJsonValue::isArray(void) const
{
    return mType == QMJsonValueType_Array;
}

bool QMJsonValue::isObject(void) const
{
    return mType == QMJsonValueType_Object;
}

bool QMJsonValue::toBool(void) const
{
    switch(mType)
    {
        case QMJsonValueType_Null:
            return false;

        case QMJsonValueType_Bool:
            return this->toBool(false);

        case QMJsonValueType_Double:
            if(this->toDouble(0) == 0)
                return false;
            else
                return true;

        case QMJsonValueType_String:
            if(this->toString("").toLower() == "true")
                return true;
            else
                return false;

        case QMJsonValueType_Array:
        case QMJsonValueType_Object:
        case QMJsonValueType_Custom:
            return false;
    };

    return false;
}

double QMJsonValue::toDouble(void) const
{
    switch(mType)
    {
        case QMJsonValueType_Null:
            return 0;

        case QMJsonValueType_Bool:
            if(this->toBool(false) == true)
                return 1;
            else
                return 0;

        case QMJsonValueType_Double:
            return this->toDouble(0);

        case QMJsonValueType_String:
            return this->toString("").toDouble();

        case QMJsonValueType_Array:
        case QMJsonValueType_Object:
        case QMJsonValueType_Custom:
            return 0;
    };

    return 0;
}

QString QMJsonValue::toString(void) const
{
    switch(mType)
    {
        case QMJsonValueType_Null:
            return "null";

        case QMJsonValueType_Bool:
            if(this->toBool(false) == true)
                return "true";
            else
                return "false";

        case QMJsonValueType_Double:
            return QString::number(this->toDouble(0));

        case QMJsonValueType_String:
            return this->toString(QString());

        case QMJsonValueType_Array:
        case QMJsonValueType_Object:
        case QMJsonValueType_Custom:
            return QString();
    };

    return QString();
}

const QMPointer<QMJsonArray> &QMJsonValue::toArray(void) const
{
    static auto defaultValue = QMPointer<QMJsonArray>(new QMJsonArray);
    auto type = qSharedPointerDynamicCast<QMJsonType<QMPointer<QMJsonArray> > >(mValue);

    if(type == NULL)
        return defaultValue;

    return type->get();
}

const QMPointer<QMJsonObject> &QMJsonValue::toObject(void) const
{
    static auto defaultValue = QMPointer<QMJsonObject>(new QMJsonObject);
    auto type = qSharedPointerDynamicCast<QMJsonType<QMPointer<QMJsonObject> > >(mValue);

    if(type == NULL)
        return defaultValue;

    return type->get();
}

bool QMJsonValue::toBool(bool defaultValue) const
{
    auto type = qSharedPointerDynamicCast<QMJsonType<bool> >(mValue);

    if(type == NULL)
        return defaultValue;

    return type->get();
}

double QMJsonValue::toDouble(double defaultValue) const
{
    auto type = qSharedPointerDynamicCast<QMJsonType<double> >(mValue);

    if(type == NULL)
        return defaultValue;

    return type->get();
}

const QString &QMJsonValue::toString(const QString &defaultValue) const
{
    auto type = qSharedPointerDynamicCast<QMJsonType<QString> >(mValue);

    if(type == NULL)
        return defaultValue;

    return type->get();
}

const QMPointer<QMJsonArray> &QMJsonValue::toArray(const QMPointer<QMJsonArray> &defaultValue) const
{
    auto type = qSharedPointerDynamicCast<QMJsonType<QMPointer<QMJsonArray> > >(mValue);

    if(type == NULL)
        return defaultValue;

    return type->get();
}

const QMPointer<QMJsonObject> &QMJsonValue::toObject(const QMPointer<QMJsonObject> &defaultValue) const
{
    auto type = qSharedPointerDynamicCast<QMJsonType<QMPointer<QMJsonObject> > >(mValue);

    if(type == NULL)
        return defaultValue;

    return type->get();
}

bool QMJsonValue::fromBool(bool value)
{
    switch(mType)
    {
        case QMJsonValueType_Null:
            return false;

        case QMJsonValueType_Bool:
            return this->set<bool>(value);

        case QMJsonValueType_Double:
            if(value == true)
                return this->set<double>(1);
            else
                return this->set<double>(0);

        case QMJsonValueType_String:
            if(value == true)
                return this->set<QString>("true");
            else
                return this->set<QString>("false");

        case QMJsonValueType_Array:
        case QMJsonValueType_Object:
        case QMJsonValueType_Custom:
            return false;
    };

    return false;
}

bool QMJsonValue::fromDouble(double value)
{
    switch(mType)
    {
        case QMJsonValueType_Null:
            return false;

        case QMJsonValueType_Bool:
            if(value == 0)
                return this->set<bool>(false);
            else
                return this->set<bool>(true);

        case QMJsonValueType_Double:
            return this->set<double>(value);

        case QMJsonValueType_String:
            return this->set<QString>(QString::number(value));

        case QMJsonValueType_Array:
        case QMJsonValueType_Object:
        case QMJsonValueType_Custom:
            return false;
    };

    return false;
}

bool QMJsonValue::fromString(const QString &value)
{
    switch(mType)
    {
        case QMJsonValueType_Null:
            return false;

        case QMJsonValueType_Bool:
            if(value == "true")
                return this->set<bool>(true);
            else
                return this->set<bool>(false);

        case QMJsonValueType_Double:
        {
            auto ok = false;
            auto result = value.toDouble(&ok);

            if(ok == false)
                return false;

            return this->set<double>(result);
        }

        case QMJsonValueType_String:
            return this->set<QString>(value);

        case QMJsonValueType_Array:
        case QMJsonValueType_Object:
        case QMJsonValueType_Custom:
            return false;
    };

    return false;
}

bool QMJsonValue::fromArray(const QMPointer<QMJsonArray> &value)
{
    switch(mType)
    {
        case QMJsonValueType_Null:
        case QMJsonValueType_Bool:
        case QMJsonValueType_Double:
        case QMJsonValueType_String:
            return false;

        case QMJsonValueType_Array:
            if(value.isNull() == true)
                return this->set<QMPointer<QMJsonArray> >(QMPointer<QMJsonArray>(new QMJsonArray));
            else
                return this->set<QMPointer<QMJsonArray> >(value);

        case QMJsonValueType_Object:
        case QMJsonValueType_Custom:
            return false;
    };

    return false;
}

bool QMJsonValue::fromObject(const QMPointer<QMJsonObject> &value)
{
    switch(mType)
    {
        case QMJsonValueType_Null:
        case QMJsonValueType_Bool:
        case QMJsonValueType_Double:
        case QMJsonValueType_String:
        case QMJsonValueType_Array:
            return false;

        case QMJsonValueType_Object:
            if(value.isNull() == true)
                return this->set<QMPointer<QMJsonObject> >(QMPointer<QMJsonObject>(new QMJsonObject));
            else
                return this->set<QMPointer<QMJsonObject> >(value);

        case QMJsonValueType_Custom:
            return false;
    };

    return false;
}

bool QMJsonValue::from(const QMPointer<QMJsonValue> &value)
{
    if(value.isNull() == true)
        return false;

    if(value->type() == QMJsonValueType_Custom)
        return false;

    switch(mType)
    {
        case QMJsonValueType_Null:
            return value->isNull();

        case QMJsonValueType_Bool:
            return this->fromBool(value->toBool());

        case QMJsonValueType_Double:
            return this->fromDouble(value->toDouble());

        case QMJsonValueType_String:
            return this->fromString(value->toString());

        case QMJsonValueType_Array:
            return this->fromArray(value->toArray());

        case QMJsonValueType_Object:
            return this->fromObject(value->toObject());

        case QMJsonValueType_Custom:
            return false;
    };

    return false;
}

const QMPointer<QMJsonValue> &QMJsonValue::value(int32_t index) const
{
    return this->toArray()->value(index);
}

const QMPointer<QMJsonValue> &QMJsonValue::value(const QString &key) const
{
    return this->toObject()->value(key);
}

QVariant QMJsonValue::toVariant(void)
{
    switch(mType)
    {
        case QMJsonValueType_Null:
            return QVariant();

        case QMJsonValueType_Bool:
            return QVariant(this->toBool());

        case QMJsonValueType_Double:
            return QVariant(this->toDouble());

        case QMJsonValueType_String:
            return QVariant(this->toString());

        case QMJsonValueType_Array:
        {
            auto list = QVariantList();

            for(const auto &value : this->toArray()->values())
                list.append(value->toVariant());

            return QVariant::fromValue(list);
        }

        case QMJsonValueType_Object:
        {
            auto hash = QVariantHash();
            const auto &object = this->toObject();

            for(const auto &key : object->keys())
                hash[key] = object->value(key)->toVariant();

            return QVariant::fromValue(hash);
        }

        case QMJsonValueType_Custom:
            return QVariant();
    };

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

        // case QMetaType::Void:
        //     return QMPointer<QMJsonValue>(new QMJsonValue());

        case QMetaType::Bool:
            return QMPointer<QMJsonValue>(new QMJsonValue(value.value<bool>()));

        case QMetaType::Int:
        case QMetaType::UInt:
        // case QMetaType::Float:
        case QMetaType::Double:
        // case QMetaType::Long:
        case QMetaType::LongLong:
        // case QMetaType::ULong:
        case QMetaType::ULongLong:
            // case QMetaType::Short:
            // case QMetaType::UShort:
            // case QMetaType::Char:
            // case QMetaType::SChar:
            // case QMetaType::UChar:
            return QMPointer<QMJsonValue>(new QMJsonValue(value.value<double>()));

        case QMetaType::QChar:
        case QMetaType::QString:
        case QMetaType::QByteArray:
            return QMPointer<QMJsonValue>(new QMJsonValue(value.value<QString>()));

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

QMJsonValueType QMJsonValue::type(void) const
{
    return mType;
}

const QString &QMJsonValue::typeString(void) const
{
    auto index = (int32_t)mType;
    static auto strings = QList<QString>()
                          << "QMJsonValueType_Null"
                          << "QMJsonValueType_Bool"
                          << "QMJsonValueType_Double"
                          << "QMJsonValueType_String"
                          << "QMJsonValueType_Array"
                          << "QMJsonValueType_Object"
                          << "QMJsonValueType_Custom"
                          << "QMJsonValueType_Unknown";

    if(index < 0) index = strings.count() - 1;
    if(index >= strings.count()) index = strings.count() - 1;

    return strings.at(index);
}

QString QMJsonValue::toJson(QMJsonFormat format, QMJsonSort sort) const
{
    if(mValue.isNull() == true)
        return "null";

    // When we convert to JSON, we need to check to see if this is a base type.
    // Base types don't need to be broken up into their base types, since they
    // already are base types. If this is not a base type, it's a complex type,
    // which means that we use it's complex version of toJson instead
    if(mValue->isBaseType() == true)
    {
        return mValue->toJson(format, sort);
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
        return value->toJson(format, sort);
    }
}

bool QMJsonValue::toJsonFile(const QString &filename, QMJsonFormat format, QMJsonSort sort) const
{
    QSaveFile file(filename);
    QTextStream stream(&file);

    if(file.open(QIODevice::WriteOnly | QIODevice::Text) == false)
        return false;

    stream << this->toJson(format, sort) << "\r\n";

    return file.commit();

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
                return value;

            auto result = func(obj);

            if(result.isNull() == true)
                return value;

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
    while(index < json.length() && json.at(index).isSpace() == true)
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

    switch(json.at(index).toLatin1())
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

            QMJsonValue::verifyIndex(json, index); valid &= json.at(index).toLower() == 'u'; index++;
            QMJsonValue::verifyIndex(json, index); valid &= json.at(index).toLower() == 'l'; index++;
            QMJsonValue::verifyIndex(json, index); valid &= json.at(index).toLower() == 'l'; index++;

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
    QDebugStateSaver saver(dbg);
    dbg.nospace() << "QMJsonValue(";

    if(value.mValue != NULL)
    {
        value.mValue->print(dbg);
        dbg << ")";
    }
    else
    {
        dbg << "NULL" << ")";
    }

    return dbg;
}

QDebug operator<<(QDebug dbg, const QMPointer<QMJsonValue> &value)
{
    if(value.isNull() == true)
    {
        QDebugStateSaver saver(dbg);

        dbg.nospace() << "QMPointer<";
        dbg << "QMJsonValue" << ">: NULL";

        return dbg;
    }
    else
    {
        return dbg << *value;
    }
}
