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

        switch (json.at(index).toLatin1())
        {
            case '\\':
            {
                index++;
                QMJsonValue::verifyIndex(json, index);

                const int32_t CHARS_IN_UNICODE_ESCAPE = 4;
                const int32_t HEX_BASE = 16;
                switch (json.at(index).toLatin1())
                {
                    case '"': result += '"'; break;
                    case '\\': result += '\\'; break;
                    case '/': result += '/'; break;
                    case 'b': result += '\b'; break;
                    case 'f': result += '\f'; break;
                    case 'n': result += '\n'; break;
                    case 'r': result += '\r'; break;
                    case 't': result += '\t'; break;
                    case 'u':
                        QMJsonValue::verifyIndex(json, index + CHARS_IN_UNICODE_ESCAPE);
                        result += json.mid(index + 1, CHARS_IN_UNICODE_ESCAPE).toUShort(Q_NULLPTR, HEX_BASE);
                        index += CHARS_IN_UNICODE_ESCAPE;
                        break;

                    default:
                        break;
                };

                index++;
                break;
            }

            case '"':
                index++;
                return QMPointer<QMJsonValue>(new QMJsonValue(result));

            default:
                result += json.at(index++);
                break;
        };
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
        auto c = str.at(i).toLatin1();

        switch (c)
        {
            case '\\':
                result += "\\\\";
                break;
            case '"':
                result += "\\\"";
                break;

            case '/':
                result += "\\/";
                break;

            case '\b':
                result += "\\b";
                break;

            case '\f':
                result += "\\f";
                break;

            case '\n':
                result += "\\n";
                break;

            case '\r':
                result += "\\r";
                break;

            case '\t':
                result += "\\t";
                break;

            default:
                result += c;
                break;
        }

    }
    result += '"';

    return result;
}

template <>
bool QM_JSON_EXPORT QMJsonType<QString>::isBaseType(void)
{
    return true;
}
