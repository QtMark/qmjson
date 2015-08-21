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

#include <test.h>

void TestJson::QMJsonGui_qsize(void)
{
    auto value00 = QMPointer<QMJsonValue>(new QMJsonValue(QSize()));
    auto value01 = QMPointer<QMJsonValue>(new QMJsonValue(QSize(-4, 8)));
    auto value02 = QMPointer<QMJsonValue>(new QMJsonValue(QSize(4, -8)));

    auto ojson00 = value00->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson01 = value01->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson02 = value02->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto pjson00 = value00->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson01 = value01->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson02 = value02->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);

    QVERIFY(QMJsonValue::fromJson(ojson00)->to<QSize>(QSize()) == QSize());
    QVERIFY(QMJsonValue::fromJson(ojson01)->to<QSize>(QSize()) == QSize(-4, 8));
    QVERIFY(QMJsonValue::fromJson(ojson02)->to<QSize>(QSize()) == QSize(4, -8));
    QVERIFY(QMJsonValue::fromJson(pjson00)->to<QSize>(QSize()) == QSize());
    QVERIFY(QMJsonValue::fromJson(pjson01)->to<QSize>(QSize()) == QSize(-4, 8));
    QVERIFY(QMJsonValue::fromJson(pjson02)->to<QSize>(QSize()) == QSize(4, -8));
}

void TestJson::QMJsonGui_qpoint(void)
{
    auto value00 = QMPointer<QMJsonValue>(new QMJsonValue(QPoint()));
    auto value01 = QMPointer<QMJsonValue>(new QMJsonValue(QPoint(-4, 8)));
    auto value02 = QMPointer<QMJsonValue>(new QMJsonValue(QPoint(4, -8)));

    auto ojson00 = value00->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson01 = value01->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson02 = value02->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto pjson00 = value00->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson01 = value01->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson02 = value02->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);

    QVERIFY(QMJsonValue::fromJson(ojson00)->to<QPoint>(QPoint()) == QPoint());
    QVERIFY(QMJsonValue::fromJson(ojson01)->to<QPoint>(QPoint()) == QPoint(-4, 8));
    QVERIFY(QMJsonValue::fromJson(ojson02)->to<QPoint>(QPoint()) == QPoint(4, -8));
    QVERIFY(QMJsonValue::fromJson(pjson00)->to<QPoint>(QPoint()) == QPoint());
    QVERIFY(QMJsonValue::fromJson(pjson01)->to<QPoint>(QPoint()) == QPoint(-4, 8));
    QVERIFY(QMJsonValue::fromJson(pjson02)->to<QPoint>(QPoint()) == QPoint(4, -8));
}

void TestJson::QMJsonGui_qrect(void)
{
    auto value00 = QMPointer<QMJsonValue>(new QMJsonValue(QRect()));
    auto value01 = QMPointer<QMJsonValue>(new QMJsonValue(QRect(-4, 8, 15, 16)));
    auto value02 = QMPointer<QMJsonValue>(new QMJsonValue(QRect(4, -8, 15, 16)));

    auto ojson00 = value00->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson01 = value01->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson02 = value02->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto pjson00 = value00->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson01 = value01->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson02 = value02->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);

    QVERIFY(QMJsonValue::fromJson(ojson00)->to<QRect>(QRect()) == QRect());
    QVERIFY(QMJsonValue::fromJson(ojson01)->to<QRect>(QRect()) == QRect(-4, 8, 15, 16));
    QVERIFY(QMJsonValue::fromJson(ojson02)->to<QRect>(QRect()) == QRect(4, -8, 15, 16));
    QVERIFY(QMJsonValue::fromJson(pjson00)->to<QRect>(QRect()) == QRect());
    QVERIFY(QMJsonValue::fromJson(pjson01)->to<QRect>(QRect()) == QRect(-4, 8, 15, 16));
    QVERIFY(QMJsonValue::fromJson(pjson02)->to<QRect>(QRect()) == QRect(4, -8, 15, 16));
}

void TestJson::QMJsonGui_qcolor(void)
{
    auto color01 = QColor(Qt::blue).convertTo(QColor::Rgb);
    auto color02 = QColor(Qt::blue).convertTo(QColor::Hsv);
    auto color03 = QColor(Qt::blue).convertTo(QColor::Cmyk);
    auto color04 = QColor(Qt::blue).convertTo(QColor::Hsl);

    auto value00 = QMPointer<QMJsonValue>(new QMJsonValue(QColor()));
    auto value01 = QMPointer<QMJsonValue>(new QMJsonValue(color01));
    auto value02 = QMPointer<QMJsonValue>(new QMJsonValue(color02));
    auto value03 = QMPointer<QMJsonValue>(new QMJsonValue(color03));
    auto value04 = QMPointer<QMJsonValue>(new QMJsonValue(color04));

    auto ojson00 = value00->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson01 = value01->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson02 = value02->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson03 = value03->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson04 = value04->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto pjson00 = value00->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson01 = value01->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson02 = value02->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson03 = value03->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson04 = value04->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);

    QVERIFY(QMJsonValue::fromJson(ojson00)->to<QColor>(QColor()) == QColor());
    QVERIFY(QMJsonValue::fromJson(ojson01)->to<QColor>(QColor()) == color01);
    QVERIFY(QMJsonValue::fromJson(ojson02)->to<QColor>(QColor()) == color02);
    QVERIFY(QMJsonValue::fromJson(ojson03)->to<QColor>(QColor()) == color03);
    QVERIFY(QMJsonValue::fromJson(ojson04)->to<QColor>(QColor()) == color04);
    QVERIFY(QMJsonValue::fromJson(pjson00)->to<QColor>(QColor()) == QColor());
    QVERIFY(QMJsonValue::fromJson(pjson01)->to<QColor>(QColor()) == color01);
    QVERIFY(QMJsonValue::fromJson(pjson02)->to<QColor>(QColor()) == color02);
    QVERIFY(QMJsonValue::fromJson(pjson03)->to<QColor>(QColor()) == color03);
    QVERIFY(QMJsonValue::fromJson(pjson04)->to<QColor>(QColor()) == color04);
}

