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

#ifndef QMJSONTYPE_SIZE_H
#define QMJSONTYPE_SIZE_H

// ============================================================================
// Libraries
// ============================================================================

#include <qmjsontype_bool.h>
#include <qmjsontype_double.h>
#include <qmjsontype_qstring.h>
#include <qmjsontype_qmjsonarray.h>
#include <qmjsontype_qmjsonobject.h>

// ============================================================================
// Class Specialization Prototypes
// ============================================================================

template <> void QM_JSON_EXPORT QMJsonType<QSize>::toComplexJson(const QMPointer<QMJsonObject> &obj);
template <> QMPointer<QMJsonValue> QM_JSON_EXPORT QMJsonType<QSize>::fromComplexJson(const QMPointer<QMJsonObject> &obj);

#endif // QMJSONTYPE_SIZE_H
