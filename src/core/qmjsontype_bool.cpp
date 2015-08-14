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

#include <qmjsontype_bool.h>

// ============================================================================
// QMJsonType<bool> Implementation
// ============================================================================

template <>
QMPointer<QMJsonValue> QM_JSON_EXPORT QMJsonType<bool>::fromJson(const QString &json, int32_t &index)
{
    auto valid = true;

    QMJsonValue::verifyIndex(json, index);

    switch(json[index++].toLatin1())
    {
        case 't':
        case 'T':
        {
            QMJsonValue::verifyIndex(json, index); valid &= json[index].toLower() == 'r'; index++;
            QMJsonValue::verifyIndex(json, index); valid &= json[index].toLower() == 'u'; index++;
            QMJsonValue::verifyIndex(json, index); valid &= json[index].toLower() == 'e'; index++;

            if(valid == false)
                QMJsonValue::throwError(json, index, "Unexpected token. Expected a boolean value of \"true\" while parsing JSON.");

            return QMPointer<QMJsonValue>(new QMJsonValue(true));
        }

        case 'f':
        case 'F':
        {
            QMJsonValue::verifyIndex(json, index); valid &= json[index].toLower() == 'a'; index++;
            QMJsonValue::verifyIndex(json, index); valid &= json[index].toLower() == 'l'; index++;
            QMJsonValue::verifyIndex(json, index); valid &= json[index].toLower() == 's'; index++;
            QMJsonValue::verifyIndex(json, index); valid &= json[index].toLower() == 'e'; index++;

            if(valid == false)
                QMJsonValue::throwError(json, index, "Unexpected token. Expected a boolean value of \"false\" while parsing JSON.");

            return QMPointer<QMJsonValue>(new QMJsonValue(false));
        }

        default:
            QMJsonValue::throwError(json, index, "Parse Error in QMJsonType<bool>::fromJson");
    }

    return QMPointer<QMJsonValue>(new QMJsonValue());
}

template <>
QString QM_JSON_EXPORT QMJsonType<bool>::toJson(int32_t tab)
{
    (void)tab;

    return this->get() ? "true" : "false";
}

template <>
bool QM_JSON_EXPORT QMJsonType<bool>::isBaseType(void)
{
    return true;
}

