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

#include <qmjsontype_qrect.h>

// ============================================================================
// QMJsonType<QPoint> Implementation
// ============================================================================

template <>
void QM_JSON_EXPORT QMJsonType<QRect>::toComplexJson(const QMPointer<QMJsonObject> &obj)
{
    if(obj.isNull() == true)
        return;

    obj->insert("qmjsontype", "QRect");
    obj->insert("point", mValue.topLeft());
    obj->insert("size", mValue.size());
}

template <>
QMPointer<QMJsonValue> QM_JSON_EXPORT QMJsonType<QRect>::fromComplexJson(const QMPointer<QMJsonObject> &obj)
{
    auto rect = QRect();

    if(obj.isNull() == true)
        return QMPointer<QMJsonValue>(new QMJsonValue(rect));

    auto size = QMJsonValue::fromComplexJson(obj->value("size"));
    auto point = QMJsonValue::fromComplexJson(obj->value("point"));

    rect.setSize(size->to<QSize>());
    rect.setTopLeft(point->to<QPoint>());

    return QMPointer<QMJsonValue>(new QMJsonValue(rect));
}
