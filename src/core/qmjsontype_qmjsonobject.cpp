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

        switch (json.at(index).toLatin1())
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

        if (key == NULL || key->isString() == false)
            QMJsonValue::throwError(json, index, "Key is not a string. Key's in a JSON object must be a valid JSON string");

        QMJsonValue::skipSpaces(json, index);
        QMJsonValue::verifyIndex(json, index);

        switch (json.at(index).toLatin1())
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
    while (1);

    return QMPointer<QMJsonValue>();
}

template <>
QString QM_JSON_EXPORT QMJsonType<QMPointer<QMJsonObject> >::toJson(int32_t tab, QMJsonSort sort)
{
    auto json = QString();
    const auto &object = this->get();

    // Note: This functions is basically written with 4 different implementaions
    // with as much code being shared as possible. Instead of trying to create
    // a generic way of handling all of this, the following provides better
    // optimized paths depending on what your attempting to do. If you modify
    // one, make sure the other three are updated as well (if needed)

    if (object.isNull() == true)
        return "{}";

    if (object->count() == 0)
        return "{}";

    if (tab == (int32_t)QMJsonFormat_Optimized)
    {
        json += '{';

        switch (sort)
        {
            case QMJsonSort_None:
            {
                auto iter = object->cbegin();

                while (iter != object->cend())
                {
                    if (iter.value().isNull() == true)
                        continue;

                    json += '"';
                    json += iter.key();
                    json += "\":";
                    json += iter.value()->toJson((QMJsonFormat)tab, sort);
                    json += ',';

                    iter++;
                }

                break;
            }

            default:
            {
                QStringList keys = object->keys();
                keys.sort(convertQMJsonSort(sort));

                for (const auto &key : keys)
                {
                    const auto &value = object->value(key);

                    json += '"';
                    json += key;
                    json += "\":";
                    json += value->toJson((QMJsonFormat)tab, sort);
                    json += ',';
                }
            }
        }

        return json.replace(json.length() - 1, 1, '}');
    }
    else
    {
        json += '{';

        tab += 4;
        auto space = QString(tab, ' ');
        switch (sort)
        {
            case QMJsonSort_None:
            {
                auto iter = object->cbegin();

                while (iter != object->cend())
                {
                    if (iter.value().isNull() == true)
                        continue;

                    json += "\n";
                    json += space;
                    json += '"';
                    json += iter.key();
                    json += "\":";
                    json += iter.value()->toJson((QMJsonFormat)tab, sort);
                    json += ',';

                    iter++;
                }

                break;
            }

            default:
            {
                QStringList keys = object->keys();
                keys.sort(convertQMJsonSort(sort));

                for (const auto &key : keys)
                {
                    const auto &value = object->value(key);

                    json += "\n";
                    json += space;
                    json += '"';
                    json += key;
                    json += "\":";
                    json += value->toJson((QMJsonFormat)tab, sort);
                    json += ',';
                }
            }
        }
        tab -= 4;

        json.remove(json.length() - 1, 1);
        json += "\n";
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
