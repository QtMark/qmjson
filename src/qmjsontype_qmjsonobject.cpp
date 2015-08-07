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

#include <qmjsontype_qmjsonobject.h>

// ============================================================================
// QMJsonType<QMPointer<QMJsonObject> > Implementation
// ============================================================================

template <>
QMPointer<QMJsonValue> QM_JSON_EXPORT QMJsonType<QMPointer<QMJsonObject> >::fromJson(const QString &json, int32_t &index)
{
    auto object = QMPointer<QMJsonObject>(new QMJsonObject);

    index++;

    do
    {
        QMJsonValue::skipSpaces(json, index);
        QMJsonValue::verifyIndex(json, index);

        switch(json[index].toLatin1())
        {
            case '}':
                index++;
                return QMPointer<QMJsonValue>(new QMJsonValue(object));

            case ',':
                index++;
                continue;

            default:
                break;
        };

        auto key = QMJsonValue::fromJson(json, index);

        if(key == NULL || key->isString() == false)
            QMJsonValue::throwError(json, index, "Key is not a string. Key's in a JSON object must be a valid JSON string");

        QMJsonValue::skipSpaces(json, index);
        QMJsonValue::verifyIndex(json, index);

        switch(json[index].toLatin1())
        {
            case ':':
                index++;
                break;

            default:
                QMJsonValue::throwError(json, index, "Expected \":\"");
        };

        QMJsonValue::skipSpaces(json, index);
        QMJsonValue::verifyIndex(json, index);

        object->insert(key->toString(), QMJsonValue::fromJson(json, index));
    }
    while(1);

    return QMPointer<QMJsonValue>(new QMJsonValue());
}

template <>
QString QM_JSON_EXPORT QMJsonType<QMPointer<QMJsonObject> >::toJson(int32_t tab)
{
    auto json = QString();
    const auto &object = this->get();

    if(object.isNull() == true)
        return "{}";

    if(object->count() == 0)
        return "{}";

    if(tab == QMJSONVALUE_OPTIMIZED)
    {
        json += '{';

        for(const auto &key : object->keys())
        {
            const auto &value = object->value(key);

            json += '"';
            json += key;
            json += "\":";
            json += value->toJson(tab);
            json += ',';
        }

        return json.replace(json.length() - 1, 1, '}');
    }
    else
    {
        json += '{';

        tab += 4;
        auto space = QString(tab, ' ');
        for(const auto &key : object->keys())
        {
            const auto &value = object->value(key);

            json += "\r\n";
            json += space;
            json += '"';
            json += key;
            json += "\":";
            json += value->toJson(tab);
            json += ',';

        }
        tab -= 4;

        json.remove(json.length() - 1, 1);
        json += "\r\n";
        json += QString(tab, ' ');
        json += '}';

        return json;
    }
}

template <>
bool QM_JSON_EXPORT QMJsonType<QMPointer<QMJsonObject> >::isBaseType(void)
{
    return true;
}
