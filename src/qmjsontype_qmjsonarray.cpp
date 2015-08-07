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

#include <qmjsontype_qmjsonarray.h>

// ============================================================================
// QMJsonType<QMPointer<QMJsonArray> > Implementation
// ============================================================================

template <>
QMPointer<QMJsonValue> QM_JSON_EXPORT QMJsonType<QMPointer<QMJsonArray> >::fromJson(const QString &json, int32_t &index)
{
    auto array = QMPointer<QMJsonArray>(new QMJsonArray);

    index++;

    do
    {
        QMJsonValue::skipSpaces(json, index);
        QMJsonValue::verifyIndex(json, index);

        switch(json[index].toLatin1())
        {
            case ']':
                index++;
                return QMPointer<QMJsonValue>(new QMJsonValue(array));

            case ',':
                index++;
                continue;

            default:
                array->append(QMJsonValue::fromJson(json, index));
        }
    }
    while(1);

    return QMPointer<QMJsonValue>(new QMJsonValue());
}

template <>
QString QM_JSON_EXPORT QMJsonType<QMPointer<QMJsonArray> >::toJson(int32_t tab)
{
    auto json = QString();
    const auto &array = this->get();

    if(array.isNull() == true)
        return "[]";

    if(array->count() == 0)
        return "[]";

    if(tab == QMJSONVALUE_OPTIMIZED)
    {
        json += '[';

        for(const auto &value : array->values())
        {
            json += value->toJson(tab);
            json += ',';
        }

        return json.replace(json.length() - 1, 1, ']');
    }
    else
    {
        json += '[';

        tab += 4;
        auto space = QString(tab, ' ');
        for(const auto &value : array->values())
        {
            json += "\r\n";
            json += space;
            json += value->toJson(tab);
            json += ',';
        }
        tab -= 4;

        json.remove(json.length() - 1, 1);
        json += "\r\n";
        json += QString(tab, ' ');
        json += ']';

        return json;
    }
}

template <>
bool QM_JSON_EXPORT QMJsonType<QMPointer<QMJsonArray> >::isBaseType(void)
{
    return true;
}
