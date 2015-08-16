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
    explicit QMJsonValue(unsigned char value);
    explicit QMJsonValue(short value);
    explicit QMJsonValue(unsigned short value);
    explicit QMJsonValue(int value);
    explicit QMJsonValue(unsigned int value);
    explicit QMJsonValue(long value);
    explicit QMJsonValue(unsigned long value);
    explicit QMJsonValue(long long value);
    explicit QMJsonValue(unsigned long long value);

    virtual ~QMJsonValue();

    virtual bool isNull(void) const;
    virtual bool isValid(void) const;
    virtual bool isEmpty(void) const;

    virtual bool isBool(void) const;
    virtual bool isDouble(void) const;
    virtual bool isString(void) const;
    virtual bool isArray(void) const;
    virtual bool isObject(void) const;
    template<class T> bool is(void) const;

    virtual bool toBool(void) const;
    virtual double toDouble(void) const;
    virtual QString toString(void) const;
    virtual QMPointer<QMJsonArray> toArray(void) const;
    virtual QMPointer<QMJsonObject> toObject(void) const;

    virtual bool toBool(bool defaultValue) const;
    virtual double toDouble(double defaultValue) const;
    virtual QString toString(const QString &defaultValue) const;
    virtual QMPointer<QMJsonArray> toArray(const QMPointer<QMJsonArray> &defaultValue) const;
    virtual QMPointer<QMJsonObject> toObject(const QMPointer<QMJsonObject> &defaultValue) const;
    template<class T> T to(const T &defaultValue) const;

    virtual float toFloat(void) const;
    virtual char toChar(void) const;
    virtual unsigned char toUChar(void) const;
    virtual short toShort(void) const;
    virtual unsigned short toUShort(void) const;
    virtual int toInt(void) const;
    virtual unsigned int toUInt(void) const;
    virtual long toLong(void) const;
    virtual unsigned long toULong(void) const;
    virtual long long toLongLong(void) const;
    virtual unsigned long long toULongLong(void) const;

    virtual float toFloat(float defaultValue) const;
    virtual char toChar(char defaultValue) const;
    virtual unsigned char toUChar(unsigned char defaultValue) const;
    virtual short toShort(short defaultValue) const;
    virtual unsigned short toUShort(unsigned short defaultValue) const;
    virtual int toInt(int defaultValue) const;
    virtual unsigned int toUInt(unsigned int defaultValue) const;
    virtual long toLong(long defaultValue) const;
    virtual unsigned long toULong(unsigned long defaultValue) const;
    virtual long long toLongLong(long long defaultValue) const;
    virtual unsigned long long toULongLong(unsigned long long defaultValue) const;

    virtual bool fromBool(bool value);
    virtual bool fromDouble(double value);
    virtual bool fromString(const QString &value);
    virtual bool fromArray(const QMPointer<QMJsonArray> &value);
    virtual bool fromObject(const QMPointer<QMJsonObject> &value);
    template <class T> bool from(const T &value);

    virtual bool fromFloat(float value);
    virtual bool fromChar(char value);
    virtual bool fromUChar(unsigned char value);
    virtual bool fromShort(short value);
    virtual bool fromUShort(unsigned short value);
    virtual bool fromInt(int value);
    virtual bool fromUInt(unsigned int value);
    virtual bool fromLong(long value);
    virtual bool fromULong(unsigned long value);
    virtual bool fromLongLong(long long value);
    virtual bool fromULongLong(unsigned long long value);

    virtual QVariant toVariant(void);
    static QMPointer<QMJsonValue> fromVariant(const QVariant &value);

    virtual QMJsonValueType type(void) const;
    virtual QString typeString(void) const;

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
T QMJsonValue::to(const T &defaultValue) const
{
    auto type = qSharedPointerDynamicCast<QMJsonType<T> >(mValue);

    if(type == NULL)
        return defaultValue;

    return type->get();
}

template<class T>
bool QMJsonValue::from(const T &value)
{
    auto type = qSharedPointerDynamicCast<QMJsonType<T> >(mValue);

    if(type == NULL)
        return false;

    type->set(value);

    emit valueChanged();
    return true;
}

#endif // QMJSONVALUE_H
