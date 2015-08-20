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

#include <qmjsontype_double.h>

// ============================================================================
// QMJsonType<double> Implementation
// ============================================================================

QMPointer<QMJsonValue> convert(const QString &json, int32_t &index, int32_t start)
{
    auto ok = false;
    auto result = json.mid(start, index - start).toDouble(&ok);

    if(ok == false)
        return QMPointer<QMJsonValue>(new QMJsonValue(0.0));

    return QMPointer<QMJsonValue>(new QMJsonValue(result));
}

template <>
QMPointer<QMJsonValue> QM_JSON_EXPORT QMJsonType<double>::fromJson(const QString &json, int32_t &index)
{
    auto start = index;

    while(1)
    {
        QMJsonValue::verifyIndex(json, index);

        switch(json[index].toLatin1())
        {
            case ']':
            case '}':
            case ':':
            case ',':
            case ' ':
            case '\t':
            case '\n':
            case '\r':
                return convert(json, index, start);

            default:
            {
                if(++index == json.length())
                    return convert(json, index, start);
            }
        };
    }

    return QMPointer<QMJsonValue>(new QMJsonValue());
}

template <>
QString QM_JSON_EXPORT QMJsonType<double>::toJson(int32_t tab, QMJsonSort sort)
{
    (void)tab;
    (void)sort;

    return QString::number(this->get(), 'g', 13);
}

template <>
bool QM_JSON_EXPORT QMJsonType<double>::isBaseType(void)
{
    return true;
}
