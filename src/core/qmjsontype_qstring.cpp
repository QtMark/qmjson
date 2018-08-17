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

#include <qmjsontype_qstring.h>

// ============================================================================
// QMJsonType<QString> Implementation
// ============================================================================

template <>
QMPointer<QMJsonValue> QM_JSON_EXPORT QMJsonType<QString>::fromJson(const QString &json, int32_t &index)
{
    auto result = QString();

    index++;

    while (1)
    {
        QMJsonValue::verifyIndex(json, index);

        auto c = json.at(index);
        if (c == '\\')
        {
            index++;
            QMJsonValue::verifyIndex(json, index);

            const int32_t CHARS_IN_UNICODE_ESCAPE = 4;
            const int32_t HEX_BASE = 16;
            auto cc = json.at(index);
            if (cc == '"')
                result += '"';
            else if (cc == '\\')
                result += '\\';
            else if (cc == '/')
                result += '/';
            else if (cc == 'b')
                result += '\b';
            else if (cc == 'f')
                result += '\f';
            else if (cc == 'n')
                result += '\n';
            else if (cc == 'r')
                result += '\r';
            else if (cc == 't')
                result += '\t';
            else if (cc == 'u')
            {
                QMJsonValue::verifyIndex(json, index + CHARS_IN_UNICODE_ESCAPE);
                result += json.mid(index + 1, CHARS_IN_UNICODE_ESCAPE).toUShort(Q_NULLPTR, HEX_BASE);
                index += CHARS_IN_UNICODE_ESCAPE;
            }

            index++;
        } else if (c == '"')
        {
            index++;
            return QMPointer<QMJsonValue>(new QMJsonValue(result));
        }
        else
            result += json.at(index++);
    }

    return QMPointer<QMJsonValue>();
}

template <>
QString QM_JSON_EXPORT QMJsonType<QString>::toJson(int32_t tab, QMJsonSort sort)
{
    (void)tab;
    (void)sort;

    auto result = QString();
    const auto &str = this->get();

    result += '"';
    for (int i = 0; i < str.length(); i++)
    {
        auto c = str.at(i);

        if (c =='\\')
            result += "\\\\";
        else if (c =='"')
            result += "\\\"";
#ifdef QMJSON_ESCAPE_SLASH
        else if (c =='/')
            result += "\\/";
#endif
        else if (c =='\b')
            result += "\\b";
        else if (c =='\f')
            result += "\\f";
        else if (c =='\n')
            result += "\\n";
        else if (c =='\r')
            result += "\\r";
        else if (c =='\t')
            result += "\\t";
        else
            result += c;

    }
    result += '"';

    return result;
}

template <>
bool QM_JSON_EXPORT QMJsonType<QString>::isBaseType(void)
{
    return true;
}
