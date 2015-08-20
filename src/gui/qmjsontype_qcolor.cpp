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

#include <qcolor.h>
#include <qmjsontype_qcolor.h>

// ============================================================================
// QMJsonType<QColor> Implementation
// ============================================================================

#define COLOR_SPEC_KEY "spec"
#define RGB_RED_KEY "red"
#define RGB_GREEN_KEY "green"
#define RGB_BLUE_KEY "blue"
#define RGB_ALPHA_KEY "alpha"
#define HSV_HUE_KEY "hue"
#define HSV_SAT_KEY "saturation"
#define HSV_VALUE_KEY "value"
#define HSV_ALPHA_KEY "alpha"
#define CMYK_CYAN_KEY "cyan"
#define CMYK_MAGENTA_KEY "magenta"
#define CMYK_YELLOW_KEY "yellow"
#define CMYK_BLACK_KEY "black"
#define CMYK_ALPHA_KEY "alpha"
#define HSL_HUE_KEY "hue"
#define HSL_SAT_KEY "saturation"
#define HSL_LIGHT_KEY "light"
#define HSL_ALPHA_KEY "alpha"

template <>
void QM_JSON_EXPORT QMJsonType<QColor>::toComplexJson(const QMPointer<QMJsonObject> &obj)
{
    obj->insert("qmjsontype", "QColor");
    obj->insert(COLOR_SPEC_KEY, (int32_t)mValue.spec());

    switch(mValue.spec())
    {
        case QColor::Rgb:
        {
            obj->insert(RGB_RED_KEY, mValue.red());
            obj->insert(RGB_GREEN_KEY, mValue.green());
            obj->insert(RGB_BLUE_KEY, mValue.blue());
            obj->insert(RGB_ALPHA_KEY, mValue.alpha());
            break;
        }

        case QColor::Hsv:
        {
            obj->insert(HSV_HUE_KEY, mValue.hue());
            obj->insert(HSV_SAT_KEY, mValue.saturation());
            obj->insert(HSV_VALUE_KEY, mValue.value());
            obj->insert(HSV_ALPHA_KEY, mValue.alpha());
            break;
        }

        case QColor::Cmyk:
        {
            obj->insert(CMYK_CYAN_KEY, mValue.cyan());
            obj->insert(CMYK_MAGENTA_KEY, mValue.magenta());
            obj->insert(CMYK_YELLOW_KEY, mValue.yellow());
            obj->insert(CMYK_BLACK_KEY, mValue.black());
            obj->insert(CMYK_ALPHA_KEY, mValue.alpha());
            break;
        }

        case QColor::Hsl:
        {
            obj->insert(HSL_HUE_KEY, mValue.hslHue());
            obj->insert(HSL_SAT_KEY, mValue.hslSaturation());
            obj->insert(HSL_LIGHT_KEY, mValue.lightness());
            obj->insert(HSL_ALPHA_KEY, mValue.alpha());
            break;
        }

        default:
            break;
    }
}

template <>
QMPointer<QMJsonValue> QM_JSON_EXPORT QMJsonType<QColor>::fromComplexJson(const QMPointer<QMJsonObject> &obj)
{
    auto color = QColor();

    if(obj.isNull() == true)
        return QMPointer<QMJsonValue>(new QMJsonValue(color));

    switch((int32_t)obj->value(COLOR_SPEC_KEY)->toDouble())
    {
        case QColor::Rgb:
        {
            color.setRgb(obj->value(RGB_RED_KEY)->toDouble(),
                         obj->value(RGB_GREEN_KEY)->toDouble(),
                         obj->value(RGB_BLUE_KEY)->toDouble(),
                         obj->value(RGB_ALPHA_KEY)->toDouble());
            break;
        }

        case QColor::Hsv:
        {
            color.setHsv(obj->value(HSV_HUE_KEY)->toDouble(),
                         obj->value(HSV_SAT_KEY)->toDouble(),
                         obj->value(HSV_VALUE_KEY)->toDouble(),
                         obj->value(HSV_ALPHA_KEY)->toDouble());
            break;
        }

        case QColor::Cmyk:
        {
            color.setCmyk(obj->value(CMYK_CYAN_KEY)->toDouble(),
                          obj->value(CMYK_MAGENTA_KEY)->toDouble(),
                          obj->value(CMYK_YELLOW_KEY)->toDouble(),
                          obj->value(CMYK_BLACK_KEY)->toDouble(),
                          obj->value(CMYK_ALPHA_KEY)->toDouble());
            break;
        }

        case QColor::Hsl:
        {
            color.setHsl(obj->value(HSL_HUE_KEY)->toDouble(),
                         obj->value(HSL_SAT_KEY)->toDouble(),
                         obj->value(HSL_LIGHT_KEY)->toDouble(),
                         obj->value(HSL_ALPHA_KEY)->toDouble());
            break;
        }

        default:
            break;
    }

    return QMPointer<QMJsonValue>(new QMJsonValue(color));
}
