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
 * @page qmjsonobject QMJsonObject
 *
 * Placeholder
 *
 *
 */
