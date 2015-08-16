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

#ifndef QMJSONTYPE_QSTRING_H
#define QMJSONTYPE_QSTRING_H

// ============================================================================
// Libraries
// ============================================================================

#include <qmjsonobject.h>
#include <qmjsonarray.h>

// ============================================================================
// Class Specialization Prototypes
// ============================================================================

template <> QMPointer<QMJsonValue> QM_JSON_EXPORT QMJsonType<QString>::fromJson(const QString &json, int32_t &index);
template <> QString QM_JSON_EXPORT QMJsonType<QString>::toJson(int32_t tab, QMJsonSort sort);

template <> bool QM_JSON_EXPORT QMJsonType<QString>::isBaseType(void);

#endif // QMJSONTYPE_QSTRING_H
