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

#include <qmjsontype_qpoint.h>

// ============================================================================
// QMJsonType<QPoint> Implementation
// ============================================================================

template <>
void QM_JSON_EXPORT QMJsonType<QPoint>::toComplexJson(const QMPointer<QMJsonObject> &obj)
{
    if (obj.isNull() == true)
        return;

    obj->insert("qmjsontype", "QPoint");
    obj->insert("x", mValue.x());
    obj->insert("y", mValue.y());
}

template <>
QMPointer<QMJsonValue> QM_JSON_EXPORT QMJsonType<QPoint>::fromComplexJson(const QMPointer<QMJsonObject> &obj)
{
    auto point = QPoint();

    if (obj.isNull() == true)
        return QMPointer<QMJsonValue>(new QMJsonValue(point));

    point.setX(obj->value("x")->toDouble());
    point.setY(obj->value("y")->toDouble());

    return QMPointer<QMJsonValue>(new QMJsonValue(point));
}
