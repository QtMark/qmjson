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
    virtual ~QMJsonObject();

    virtual void clear(void);
    virtual int32_t count(void) const;

    virtual bool contains(const QString &key) const;

    virtual void insert(const QString &key, const QMPointer<QMJsonValue> &value);
    template<class T> void insert(const QString &key, const T &value);
    template<class T> void insert(const QString &key, const T *value);
    virtual void insert(const QString &key, const char *value);

    virtual void unite(const QMPointer<QMJsonObject> &object);

    virtual void remove(const QString &key);

    virtual QList<QString> keys(void) const;
    virtual QMPointer<QMJsonValue> value(const QString &key) const;
    virtual QList<QMPointer<QMJsonValue> > values(void) const;

    virtual bool isBool(const QString &key) const;
    virtual bool isDouble(const QString &key) const;
    virtual bool isString(const QString &key) const;
    virtual bool isArray(const QString &key) const;
    virtual bool isObject(const QString &key) const;
    virtual bool isJsonObject(const QString &key) const;

#ifdef QM_GUI_ENABLED

    virtual bool isRect(const QString &key) const;
    virtual bool isSize(const QString &key) const;
    virtual bool isPoint(const QString &key) const;
    virtual bool isColor(const QString &key) const;

#endif

    virtual bool toBool(const QString &key) const;
    virtual double toDouble(const QString &key) const;
    virtual QString toString(const QString &key) const;
    virtual QMPointer<QMJsonArray> toArray(const QString &key) const;
    virtual QMPointer<QMJsonObject> toObject(const QString &key) const;

    virtual bool toBool(const QString &key, bool defaultValue) const;
    virtual double toDouble(const QString &key, double defaultValue) const;
    virtual QString toString(const QString &key, const QString &defaultValue) const;
    virtual QMPointer<QMJsonArray> toArray(const QString &key, const QMPointer<QMJsonArray> &defaultValue) const;
    virtual QMPointer<QMJsonObject> toObject(const QString &key, const QMPointer<QMJsonObject> &defaultValue) const;

#ifdef QM_GUI_ENABLED

    virtual QRect toRect(const QString &key) const;
    virtual QSize toSize(const QString &key) const;
    virtual QPoint toPoint(const QString &key) const;
    virtual QColor toColor(const QString &key) const;

    virtual QRect toRect(const QString &key, const QRect &defaultValue) const;
    virtual QSize toSize(const QString &key, const QSize &defaultValue) const;
    virtual QPoint toPoint(const QString &key, const QPoint &defaultValue) const;
    virtual QColor toColor(const QString &key, const QColor &defaultValue) const;

#endif
    virtual const char *toChar(const QString &key) const;
    virtual short toShort(const QString &key) const;
    virtual unsigned short toUShort(const QString &key) const;
    virtual int toInt(const QString &key) const;
    virtual unsigned int toUInt(const QString &key) const;
    virtual long toLong(const QString &key) const;
    virtual unsigned long toULong(const QString &key) const;
    virtual long long toLongLong(const QString &key) const;
    virtual unsigned long long toULongLong(const QString &key) const;

    virtual const char *toChar(const QString &key, const char *defaultValue) const;
    virtual short toShort(const QString &key, short defaultValue) const;
    virtual unsigned short toUShort(const QString &key, unsigned short defaultValue) const;
    virtual int toInt(const QString &key, int defaultValue) const;
    virtual unsigned int toUInt(const QString &key, unsigned int defaultValue) const;
    virtual long toLong(const QString &key, long defaultValue) const;
    virtual unsigned long toULong(const QString &key, unsigned long defaultValue) const;
    virtual long long toLongLong(const QString &key, long long defaultValue) const;
    virtual unsigned long long toULongLong(const QString &key, unsigned long long defaultValue) const;

    virtual bool fromBool(const QString &key, bool value);
    virtual bool fromDouble(const QString &key, double value);
    virtual bool fromString(const QString &key, const QString &value);
    virtual bool fromArray(const QString &key, const QMPointer<QMJsonArray> &value);
    virtual bool fromObject(const QString &key, const QMPointer<QMJsonObject> &value);

#ifdef QM_GUI_ENABLED

    virtual bool fromRect(const QString &key, const QRect &value);
    virtual bool fromSize(const QString &key, const QSize &value);
    virtual bool fromPoint(const QString &key, const QPoint &value);
    virtual bool fromColor(const QString &key, const QColor &value);

#endif

    virtual bool fromChar(const QString &key, const char *value);
    virtual bool fromShort(const QString &key, short value);
    virtual bool fromUShort(const QString &key, unsigned short value);
    virtual bool fromInt(const QString &key, int value);
    virtual bool fromUInt(const QString &key, unsigned int value);
    virtual bool fromLong(const QString &key, long value);
    virtual bool fromULong(const QString &key, unsigned long value);
    virtual bool fromLongLong(const QString &key, long long value);
    virtual bool fromULongLong(const QString &key, unsigned long long value);

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
void QMJsonObject::insert(const QString &key, const T &value)
{
    this->insert(key, QMPointer<QMJsonValue>(new QMJsonValue(value)));
}

template<class T>
void QMJsonObject::insert(const QString &key, const T *value)
{
    this->insert(key, QMPointer<QMJsonValue>(new QMJsonValue(QMPointer<T>(value))));
}

#endif // QMJSONOBJECT_H
