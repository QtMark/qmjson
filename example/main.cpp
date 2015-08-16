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

#include <QtGui>

#include <qmjson.h>
#include <qmjsongui.h>

int main(int argc, char const *argv[])
{
    (void) argc;
    (void) argv;

    //--------------------------------------------------------------------------
    // Setup
    //--------------------------------------------------------------------------

    QMJsonValue::registerFromComplexJson("QColor", &QMJsonType<QColor>::fromComplexJson);
    QMJsonValue::registerFromComplexJson("QPoint", &QMJsonType<QPoint>::fromComplexJson);
    QMJsonValue::registerFromComplexJson("QRect", &QMJsonType<QRect>::fromComplexJson);
    QMJsonValue::registerFromComplexJson("QSize", &QMJsonType<QSize>::fromComplexJson);

    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(5.5));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto array = QMPointer<QMJsonArray>(new QMJsonArray());
    auto object = QMPointer<QMJsonObject>(new QMJsonObject());
    auto tree = QMPointer<QMJsonObject>(new QMJsonObject());
    auto document = QMPointer<QMJsonValue>(new QMJsonValue(tree));

    array->append(value1);
    array->append(value2);
    array->append(value3);

    object->insert("key1", value1);
    object->insert("key2", value2);
    object->insert("key3", value3);

    tree->insert("array", array);
    tree->insert("object", object);

    auto complexValue1 = QMPointer<QMJsonValue>(new QMJsonValue(QColor("red")));
    auto complexValue2 = QMPointer<QMJsonValue>(new QMJsonValue(QPoint(2, 2)));
    auto complexValue3 = QMPointer<QMJsonValue>(new QMJsonValue(QRect(5, 5, 3, 3)));
    auto complexValue4 = QMPointer<QMJsonValue>(new QMJsonValue(QSize(10, 10)));

    //--------------------------------------------------------------------------
    // Valid
    //--------------------------------------------------------------------------

    qDebug() << "Valid:";

    qDebug() << "  " << value1;
    qDebug() << "  " << value2;
    qDebug() << "  " << value3;

    qDebug() << "  " << array;
    qDebug() << "  " << object;

    qDebug() << "  " << array->toDouble(0);
    qDebug() << "  " << array->toString(1);
    qDebug() << "  " << array->toBool(2);

    qDebug() << "  " << array->value(0);
    qDebug() << "  " << array->value(1);
    qDebug() << "  " << array->value(2);

    qDebug() << "  " << object->toDouble("key1");
    qDebug() << "  " << object->toString("key2");
    qDebug() << "  " << object->toBool("key3");

    qDebug() << "  " << object->value("key1");
    qDebug() << "  " << object->value("key2");
    qDebug() << "  " << object->value("key3");

    qDebug() << "";

    //--------------------------------------------------------------------------
    // Invalid
    //--------------------------------------------------------------------------

    qDebug() << "Invalid:";

    qDebug() << "  " << array->toString(0);
    qDebug() << "  " << array->toBool(1);
    qDebug() << "  " << array->toDouble(2);

    qDebug() << "  " << array->toDouble(3);
    qDebug() << "  " << array->toString(4);
    qDebug() << "  " << array->toBool(5);

    qDebug() << "  " << array->value(6);
    qDebug() << "  " << array->value(7);
    qDebug() << "  " << array->value(8);

    qDebug() << "  " << object->toString("key1");
    qDebug() << "  " << object->toBool("key2");
    qDebug() << "  " << object->toDouble("key3");

    qDebug() << "  " << object->toDouble("key4");
    qDebug() << "  " << object->toString("key5");
    qDebug() << "  " << object->toBool("key6");

    qDebug() << "  " << object->value("key7");
    qDebug() << "  " << object->value("key8");
    qDebug() << "  " << object->value("key9");

    qDebug() << "";

    //--------------------------------------------------------------------------
    // From (Setting)
    //--------------------------------------------------------------------------

    qDebug() << "From:";

    value1->fromDouble(10.3);
    value2->fromString("World");
    value3->fromBool(false);

    qDebug() << "  " << value1;
    qDebug() << "  " << value2;
    qDebug() << "  " << value3;
    qDebug() << "";

    //--------------------------------------------------------------------------
    // Tree Example
    //--------------------------------------------------------------------------

    qDebug() << "Tree:";
    qDebug() << "  " << tree;
    qDebug() << "";

    //--------------------------------------------------------------------------
    // Save
    //--------------------------------------------------------------------------

    qDebug() << "Save:";
    qDebug() << document->toJsonFile("example.json", QMJSONVALUE_PRETTY);
    qDebug() << "";

    //--------------------------------------------------------------------------
    // Load
    //--------------------------------------------------------------------------

    qDebug() << "Load:";
    qDebug() << QMJsonValue::fromJsonFile("example.json");
    qDebug() << "";

    //--------------------------------------------------------------------------
    // Complex Types
    //--------------------------------------------------------------------------


    qDebug() << "Complex Values:";
    qDebug() << complexValue1;
    qDebug() << complexValue2;
    qDebug() << complexValue3;
    qDebug() << complexValue4;
    qDebug() << "";

    qDebug() << "Is:";
    qDebug() << complexValue1->is<QColor>();
    qDebug() << complexValue2->is<QPoint>();
    qDebug() << complexValue3->is<QRect>();
    qDebug() << complexValue4->is<QSize>();
    qDebug() << "";

    qDebug() << "To:";
    qDebug() << complexValue1->to<QColor>();
    qDebug() << complexValue2->to<QPoint>();
    qDebug() << complexValue3->to<QRect>();
    qDebug() << complexValue4->to<QSize>();
    qDebug() << "";

    qDebug() << "From:";
    qDebug() << complexValue1->from<QColor>(QColor("blue"));
    qDebug() << complexValue2->from<QPoint>(QPoint(4, 8));
    qDebug() << complexValue3->from<QRect>(QRect(15, 16, 23, 42));
    qDebug() << complexValue4->from<QSize>(QSize(21, 12));
    qDebug() << "";

    qDebug() << "Complex to JSON:";
    qDebug() << complexValue1->toJson();
    qDebug() << complexValue2->toJson();
    qDebug() << complexValue3->toJson();
    qDebug() << complexValue4->toJson();
    qDebug() << "";

    qDebug() << "Complex from JSON:";
    qDebug() << QMJsonValue::fromJson(complexValue1->toJson());
    qDebug() << QMJsonValue::fromJson(complexValue2->toJson());
    qDebug() << QMJsonValue::fromJson(complexValue3->toJson());
    qDebug() << QMJsonValue::fromJson(complexValue4->toJson());
    qDebug() << "";

    return 0;
}
