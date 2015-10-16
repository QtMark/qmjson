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

void TestJson::QMJsonValue_create(void)
{
    auto value00 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value01 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value02 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto value03 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value04 = QMPointer<QMJsonValue>(new QMJsonValue(QString("Hello World")));
    auto value05 = QMPointer<QMJsonValue>(new QMJsonValue(QMPointer<QMJsonValue>()));
    auto value06 = QMPointer<QMJsonValue>(new QMJsonValue(QMPointer<QMJsonArray>()));
    auto value07 = QMPointer<QMJsonValue>(new QMJsonValue(QMPointer<QMJsonObject>()));
    auto value08 = QMPointer<QMJsonValue>(new QMJsonValue(QMPointer<QMJsonValue>(new QMJsonValue())));
    auto value09 = QMPointer<QMJsonValue>(new QMJsonValue(QMPointer<QMJsonArray>(new QMJsonArray())));
    auto value10 = QMPointer<QMJsonValue>(new QMJsonValue(QMPointer<QMJsonObject>(new QMJsonObject())));
    auto value11 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonValue()));
    auto value12 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonArray()));
    auto value13 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonObject()));
    auto value14 = QMPointer<QMJsonValue>(new QMJsonValue(QRect()));
    auto value15 = QMPointer<QMJsonValue>(new QMJsonValue((float)4.8));
    auto value16 = QMPointer<QMJsonValue>(new QMJsonValue((char)4.8));
    auto value17 = QMPointer<QMJsonValue>(new QMJsonValue((long)4.8));
    auto value18 = QMPointer<QMJsonValue>(new QMJsonValue((unsigned long)4.8));
    auto value19 = QMPointer<QMJsonValue>(new QMJsonValue((int8_t)15));
    auto value20 = QMPointer<QMJsonValue>(new QMJsonValue((uint8_t)16));
    auto value21 = QMPointer<QMJsonValue>(new QMJsonValue((int16_t)23));
    auto value22 = QMPointer<QMJsonValue>(new QMJsonValue((uint16_t)42));
    auto value23 = QMPointer<QMJsonValue>(new QMJsonValue((int32_t)4));
    auto value24 = QMPointer<QMJsonValue>(new QMJsonValue((uint32_t)8));
    auto value25 = QMPointer<QMJsonValue>(new QMJsonValue((int64_t)15));
    auto value26 = QMPointer<QMJsonValue>(new QMJsonValue((uint64_t)16));
    auto value27 = QMPointer<QMJsonValue>(new QMJsonValue((char)15));
    auto value28 = QMPointer<QMJsonValue>(new QMJsonValue((unsigned char)16));
    auto value29 = QMPointer<QMJsonValue>(new QMJsonValue((short)15));
    auto value30 = QMPointer<QMJsonValue>(new QMJsonValue((unsigned short)16));
    auto value31 = QMPointer<QMJsonValue>(new QMJsonValue((int)15));
    auto value32 = QMPointer<QMJsonValue>(new QMJsonValue((unsigned int)16));
    auto value33 = QMPointer<QMJsonValue>(new QMJsonValue((long long)15));
    auto value34 = QMPointer<QMJsonValue>(new QMJsonValue((unsigned long long)16));

    QVERIFY(value00->type() == QMJsonValueType_Null);
    QVERIFY(value01->type() == QMJsonValueType_Bool);
    QVERIFY(value02->type() == QMJsonValueType_Double);
    QVERIFY(value03->type() == QMJsonValueType_String);
    QVERIFY(value04->type() == QMJsonValueType_String);
    QVERIFY(value05->type() == QMJsonValueType_Null);
    QVERIFY(value06->type() == QMJsonValueType_Array);
    QVERIFY(value07->type() == QMJsonValueType_Object);
    QVERIFY(value08->type() == QMJsonValueType_Null);
    QVERIFY(value09->type() == QMJsonValueType_Array);
    QVERIFY(value10->type() == QMJsonValueType_Object);
    QVERIFY(value11->type() == QMJsonValueType_Null);
    QVERIFY(value12->type() == QMJsonValueType_Array);
    QVERIFY(value13->type() == QMJsonValueType_Object);
    QVERIFY(value14->type() == QMJsonValueType_Custom);
    QVERIFY(value15->type() == QMJsonValueType_Double);
    QVERIFY(value16->type() == QMJsonValueType_Double);
    QVERIFY(value17->type() == QMJsonValueType_Double);
    QVERIFY(value18->type() == QMJsonValueType_Double);
    QVERIFY(value19->type() == QMJsonValueType_Double);
    QVERIFY(value20->type() == QMJsonValueType_Double);
    QVERIFY(value21->type() == QMJsonValueType_Double);
    QVERIFY(value22->type() == QMJsonValueType_Double);
    QVERIFY(value23->type() == QMJsonValueType_Double);
    QVERIFY(value24->type() == QMJsonValueType_Double);
    QVERIFY(value25->type() == QMJsonValueType_Double);
    QVERIFY(value26->type() == QMJsonValueType_Double);
    QVERIFY(value27->type() == QMJsonValueType_Double);
    QVERIFY(value28->type() == QMJsonValueType_Double);
    QVERIFY(value29->type() == QMJsonValueType_Double);
    QVERIFY(value30->type() == QMJsonValueType_Double);
    QVERIFY(value31->type() == QMJsonValueType_Double);
    QVERIFY(value32->type() == QMJsonValueType_Double);
    QVERIFY(value33->type() == QMJsonValueType_Double);
    QVERIFY(value34->type() == QMJsonValueType_Double);

    QVERIFY(value00->typeString() == "QMJsonValueType_Null");
    QVERIFY(value01->typeString() == "QMJsonValueType_Bool");
    QVERIFY(value02->typeString() == "QMJsonValueType_Double");
    QVERIFY(value03->typeString() == "QMJsonValueType_String");
    QVERIFY(value04->typeString() == "QMJsonValueType_String");
    QVERIFY(value05->typeString() == "QMJsonValueType_Null");
    QVERIFY(value06->typeString() == "QMJsonValueType_Array");
    QVERIFY(value07->typeString() == "QMJsonValueType_Object");
    QVERIFY(value08->typeString() == "QMJsonValueType_Null");
    QVERIFY(value09->typeString() == "QMJsonValueType_Array");
    QVERIFY(value10->typeString() == "QMJsonValueType_Object");
    QVERIFY(value11->typeString() == "QMJsonValueType_Null");
    QVERIFY(value12->typeString() == "QMJsonValueType_Array");
    QVERIFY(value13->typeString() == "QMJsonValueType_Object");
    QVERIFY(value14->typeString() == "QMJsonValueType_Custom");
    QVERIFY(value15->typeString() == "QMJsonValueType_Double");
    QVERIFY(value16->typeString() == "QMJsonValueType_Double");
    QVERIFY(value17->typeString() == "QMJsonValueType_Double");
    QVERIFY(value18->typeString() == "QMJsonValueType_Double");
    QVERIFY(value19->typeString() == "QMJsonValueType_Double");
    QVERIFY(value20->typeString() == "QMJsonValueType_Double");
    QVERIFY(value21->typeString() == "QMJsonValueType_Double");
    QVERIFY(value22->typeString() == "QMJsonValueType_Double");
    QVERIFY(value23->typeString() == "QMJsonValueType_Double");
    QVERIFY(value24->typeString() == "QMJsonValueType_Double");
    QVERIFY(value25->typeString() == "QMJsonValueType_Double");
    QVERIFY(value26->typeString() == "QMJsonValueType_Double");
    QVERIFY(value27->typeString() == "QMJsonValueType_Double");
    QVERIFY(value28->typeString() == "QMJsonValueType_Double");
    QVERIFY(value29->typeString() == "QMJsonValueType_Double");
    QVERIFY(value30->typeString() == "QMJsonValueType_Double");
    QVERIFY(value31->typeString() == "QMJsonValueType_Double");
    QVERIFY(value32->typeString() == "QMJsonValueType_Double");
    QVERIFY(value33->typeString() == "QMJsonValueType_Double");
    QVERIFY(value34->typeString() == "QMJsonValueType_Double");
}

void TestJson::QMJsonValue_file(void)
{
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto document1 = QMPointer<QMJsonValue>(new QMJsonValue(object1));

    object1->insert("key1", value1);
    object1->insert("key2", value2);
    object1->insert("key3", value3);

    QVERIFY(document1->toJsonFile("test.json") == true);

    auto document2 = QMJsonValue::fromJsonFile("test.json");

    QVERIFY(document2.isNull() == false);
    QVERIFY(document1->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) ==
            document2->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive));

    QVERIFY(QMJsonValue::fromJsonFile("blah.json").isNull() == true);
}

void TestJson::QMJsonValue_sort(void)
{
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto object2 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto object3 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto object4 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto object5 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto object6 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto document1 = QMPointer<QMJsonValue>(new QMJsonValue(object5));
    auto document2 = QMPointer<QMJsonValue>(new QMJsonValue(object6));

    object1->insert("apple", value1);
    object1->insert("Baseball", value2);
    object1->insert("cat", value3);

    object2->insert("Baseball", value2);
    object2->insert("apple", value1);
    object2->insert("cat", value3);

    object3->insert("cat", value3);
    object3->insert("apple", value1);
    object3->insert("Baseball", value2);

    object4->insert("cat", value3);
    object4->insert("Baseball", value2);
    object4->insert("apple", value1);

    object5->insert("dog", object1);
    object5->insert("evil", object2);

    object6->insert("evil", object4);
    object6->insert("dog", object3);

    QVERIFY(document1->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) !=
            document2->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseInsensitive));

    QVERIFY(document1->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseInsensitive) ==
            document2->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseInsensitive));

    QVERIFY(document1->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) ==
            document2->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive));
}

void TestJson::QMJsonValue_bool(void)
{
    auto value00 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value01 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value02 = QMPointer<QMJsonValue>(new QMJsonValue(false));
    auto value03 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto value04 = QMPointer<QMJsonValue>(new QMJsonValue(0));
    auto value05 = QMPointer<QMJsonValue>(new QMJsonValue("true"));
    auto value06 = QMPointer<QMJsonValue>(new QMJsonValue("false"));
    auto value07 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value08 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonArray));
    auto value09 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonObject));
    auto value10 = QMPointer<QMJsonValue>(new QMJsonValue(QRect()));

    QVERIFY(value00->isBool() == false);
    QVERIFY(value01->isBool() == true);
    QVERIFY(value02->isBool() == true);
    QVERIFY(value03->isBool() == false);
    QVERIFY(value04->isBool() == false);
    QVERIFY(value05->isBool() == false);
    QVERIFY(value06->isBool() == false);
    QVERIFY(value07->isBool() == false);
    QVERIFY(value08->isBool() == false);
    QVERIFY(value09->isBool() == false);
    QVERIFY(value10->isBool() == false);

    QVERIFY(value00->toBool() == false);
    QVERIFY(value01->toBool() == true);
    QVERIFY(value02->toBool() == false);
    QVERIFY(value03->toBool() == true);
    QVERIFY(value04->toBool() == false);
    QVERIFY(value05->toBool() == true);
    QVERIFY(value06->toBool() == false);
    QVERIFY(value07->toBool() == false);
    QVERIFY(value08->toBool() == false);
    QVERIFY(value09->toBool() == false);
    QVERIFY(value10->toBool() == false);

    QVERIFY(value00->toBool(true) == true);
    QVERIFY(value01->toBool(true) == true);
    QVERIFY(value02->toBool(true) == false);
    QVERIFY(value03->toBool(true) == true);
    QVERIFY(value04->toBool(true) == true);
    QVERIFY(value05->toBool(true) == true);
    QVERIFY(value06->toBool(true) == true);
    QVERIFY(value07->toBool(true) == true);
    QVERIFY(value08->toBool(true) == true);
    QVERIFY(value09->toBool(true) == true);
    QVERIFY(value10->toBool(true) == true);

    QVERIFY(value00->to<bool>(true) == true);
    QVERIFY(value01->to<bool>(true) == true);
    QVERIFY(value02->to<bool>(true) == false);
    QVERIFY(value03->to<bool>(true) == true);
    QVERIFY(value04->to<bool>(true) == true);
    QVERIFY(value05->to<bool>(true) == true);
    QVERIFY(value06->to<bool>(true) == true);
    QVERIFY(value07->to<bool>(true) == true);
    QVERIFY(value08->to<bool>(true) == true);
    QVERIFY(value09->to<bool>(true) == true);
    QVERIFY(value10->to<bool>(true) == true);

    QVERIFY(value00->fromBool(true) == false);
    QVERIFY(value01->fromBool(true) == true);
    QVERIFY(value02->fromBool(false) == true);
    QVERIFY(value03->fromBool(true) == true);
    QVERIFY(value04->fromBool(false) == true);
    QVERIFY(value05->fromBool(true) == true);
    QVERIFY(value06->fromBool(false) == true);
    QVERIFY(value07->fromBool(true) == true);
    QVERIFY(value08->fromBool(true) == false);
    QVERIFY(value09->fromBool(true) == false);
    QVERIFY(value10->fromBool(true) == false);

    QVERIFY(value01->toBool() == true);
    QVERIFY(value02->toBool() == false);
    QVERIFY(value03->toDouble() == 1);
    QVERIFY(value04->toDouble() == 0);
    QVERIFY(value05->toString() == "true");
    QVERIFY(value06->toString() == "false");
    QVERIFY(value07->toString() == "true");

    QVERIFY(value00->from<bool>(true) == false);
    QVERIFY(value01->from<bool>(true) == true);
    QVERIFY(value02->from<bool>(true) == true);
    QVERIFY(value03->from<bool>(true) == false);
    QVERIFY(value04->from<bool>(true) == false);
    QVERIFY(value05->from<bool>(true) == false);
    QVERIFY(value06->from<bool>(true) == false);
    QVERIFY(value07->from<bool>(true) == false);
    QVERIFY(value08->from<bool>(true) == false);
    QVERIFY(value09->from<bool>(true) == false);
    QVERIFY(value10->from<bool>(true) == false);
}

void TestJson::QMJsonValue_double(void)
{
    auto value00 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value01 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value02 = QMPointer<QMJsonValue>(new QMJsonValue(false));
    auto value03 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto value04 = QMPointer<QMJsonValue>(new QMJsonValue("4.8"));
    auto value05 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value06 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonArray));
    auto value07 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonObject));
    auto value08 = QMPointer<QMJsonValue>(new QMJsonValue(QRect()));
    auto value09 = QMPointer<QMJsonValue>(new QMJsonValue((float)4.8));
    auto value10 = QMPointer<QMJsonValue>(new QMJsonValue((int8_t)15));
    auto value11 = QMPointer<QMJsonValue>(new QMJsonValue((uint8_t)16));
    auto value12 = QMPointer<QMJsonValue>(new QMJsonValue((int16_t)23));
    auto value13 = QMPointer<QMJsonValue>(new QMJsonValue((uint16_t)42));
    auto value14 = QMPointer<QMJsonValue>(new QMJsonValue((int32_t)4));
    auto value15 = QMPointer<QMJsonValue>(new QMJsonValue((uint32_t)8));
    auto value16 = QMPointer<QMJsonValue>(new QMJsonValue((int64_t)15));
    auto value17 = QMPointer<QMJsonValue>(new QMJsonValue((uint64_t)16));

    QVERIFY(value00->isDouble() == false);
    QVERIFY(value01->isDouble() == false);
    QVERIFY(value02->isDouble() == false);
    QVERIFY(value03->isDouble() == true);
    QVERIFY(value04->isDouble() == false);
    QVERIFY(value05->isDouble() == false);
    QVERIFY(value06->isDouble() == false);
    QVERIFY(value07->isDouble() == false);
    QVERIFY(value08->isDouble() == false);
    QVERIFY(value09->isDouble() == true);
    QVERIFY(value10->isDouble() == true);
    QVERIFY(value11->isDouble() == true);
    QVERIFY(value12->isDouble() == true);
    QVERIFY(value13->isDouble() == true);
    QVERIFY(value14->isDouble() == true);
    QVERIFY(value15->isDouble() == true);
    QVERIFY(value16->isDouble() == true);
    QVERIFY(value17->isDouble() == true);

    QVERIFY(value00->toDouble() == 0);
    QVERIFY(value01->toDouble() == 1);
    QVERIFY(value02->toDouble() == 0);
    QVERIFY(value03->toDouble() == 4.8);
    QVERIFY(value04->toDouble() == 4.8);
    QVERIFY(value05->toDouble() == 0);
    QVERIFY(value06->toDouble() == 0);
    QVERIFY(value07->toDouble() == 0);
    QVERIFY(value08->toDouble() == 0);
    QVERIFY(value09->toDouble() == (float)4.8);
    QVERIFY(value10->toDouble() == 15);
    QVERIFY(value11->toDouble() == 16);
    QVERIFY(value12->toDouble() == 23);
    QVERIFY(value13->toDouble() == 42);
    QVERIFY(value14->toDouble() == 4);
    QVERIFY(value15->toDouble() == 8);
    QVERIFY(value16->toDouble() == 15);
    QVERIFY(value17->toDouble() == 16);

    QVERIFY(value00->toDouble(15.16) == 15.16);
    QVERIFY(value01->toDouble(15.16) == 15.16);
    QVERIFY(value02->toDouble(15.16) == 15.16);
    QVERIFY(value03->toDouble(15.16) == 4.8);
    QVERIFY(value04->toDouble(15.16) == 15.16);
    QVERIFY(value05->toDouble(15.16) == 15.16);
    QVERIFY(value06->toDouble(15.16) == 15.16);
    QVERIFY(value07->toDouble(15.16) == 15.16);
    QVERIFY(value08->toDouble(15.16) == 15.16);
    QVERIFY(value09->toDouble(15.16) == (float)4.8);
    QVERIFY(value10->toDouble(15.16) == 15);
    QVERIFY(value11->toDouble(15.16) == 16);
    QVERIFY(value12->toDouble(15.16) == 23);
    QVERIFY(value13->toDouble(15.16) == 42);
    QVERIFY(value14->toDouble(15.16) == 4);
    QVERIFY(value15->toDouble(15.16) == 8);
    QVERIFY(value16->toDouble(15.16) == 15);
    QVERIFY(value17->toDouble(15.16) == 16);

    QVERIFY(value00->to<double>(15.16) == 15.16);
    QVERIFY(value01->to<double>(15.16) == 15.16);
    QVERIFY(value02->to<double>(15.16) == 15.16);
    QVERIFY(value03->to<double>(15.16) == 4.8);
    QVERIFY(value04->to<double>(15.16) == 15.16);
    QVERIFY(value05->to<double>(15.16) == 15.16);
    QVERIFY(value06->to<double>(15.16) == 15.16);
    QVERIFY(value07->to<double>(15.16) == 15.16);
    QVERIFY(value08->to<double>(15.16) == 15.16);
    QVERIFY(value09->to<double>(15.16) == (float)4.8);
    QVERIFY(value10->to<double>(15.16) == 15);
    QVERIFY(value11->to<double>(15.16) == 16);
    QVERIFY(value12->to<double>(15.16) == 23);
    QVERIFY(value13->to<double>(15.16) == 42);
    QVERIFY(value14->to<double>(15.16) == 4);
    QVERIFY(value15->to<double>(15.16) == 8);
    QVERIFY(value16->to<double>(15.16) == 15);
    QVERIFY(value17->to<double>(15.16) == 16);

    QVERIFY(value00->fromDouble(4.8) == false);
    QVERIFY(value01->fromDouble(1) == true);
    QVERIFY(value02->fromDouble(0) == true);
    QVERIFY(value03->fromDouble(23.42) == true);
    QVERIFY(value04->fromDouble(4.8) == true);
    QVERIFY(value05->fromDouble(23.42) == true);
    QVERIFY(value06->fromDouble(4.8) == false);
    QVERIFY(value07->fromDouble(4.8) == false);
    QVERIFY(value08->fromDouble(4.8) == false);
    QVERIFY(value09->fromDouble(4.8) == true);
    QVERIFY(value10->fromDouble(4.8) == true);
    QVERIFY(value11->fromDouble(4.8) == true);
    QVERIFY(value12->fromDouble(4.8) == true);
    QVERIFY(value13->fromDouble(4.8) == true);
    QVERIFY(value14->fromDouble(4.8) == true);
    QVERIFY(value15->fromDouble(4.8) == true);
    QVERIFY(value16->fromDouble(4.8) == true);
    QVERIFY(value17->fromDouble(4.8) == true);

    QVERIFY(value01->toBool() == true);
    QVERIFY(value02->toBool() == false);
    QVERIFY(value03->toDouble() == 23.42);
    QVERIFY(value04->toString() == "4.8");
    QVERIFY(value05->toString() == "23.42");

    QVERIFY(value00->from<double>(4.8) == false);
    QVERIFY(value01->from<double>(4.8) == false);
    QVERIFY(value02->from<double>(4.8) == false);
    QVERIFY(value03->from<double>(4.8) == true);
    QVERIFY(value04->from<double>(4.8) == false);
    QVERIFY(value05->from<double>(4.8) == false);
    QVERIFY(value06->from<double>(4.8) == false);
    QVERIFY(value07->from<double>(4.8) == false);
    QVERIFY(value08->from<double>(4.8) == false);
    QVERIFY(value09->from<double>(4.8) == true);
    QVERIFY(value10->from<double>(4.8) == true);
    QVERIFY(value11->from<double>(4.8) == true);
    QVERIFY(value12->from<double>(4.8) == true);
    QVERIFY(value13->from<double>(4.8) == true);
    QVERIFY(value14->from<double>(4.8) == true);
    QVERIFY(value15->from<double>(4.8) == true);
    QVERIFY(value16->from<double>(4.8) == true);
    QVERIFY(value17->from<double>(4.8) == true);
}

void TestJson::QMJsonValue_string(void)
{
    auto value00 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value01 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value02 = QMPointer<QMJsonValue>(new QMJsonValue(false));
    auto value03 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto value04 = QMPointer<QMJsonValue>(new QMJsonValue(0));
    auto value05 = QMPointer<QMJsonValue>(new QMJsonValue("true"));
    auto value06 = QMPointer<QMJsonValue>(new QMJsonValue("false"));
    auto value07 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value08 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonArray));
    auto value09 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonObject));
    auto value10 = QMPointer<QMJsonValue>(new QMJsonValue(QRect()));

    QVERIFY(value00->isString() == false);
    QVERIFY(value01->isString() == false);
    QVERIFY(value02->isString() == false);
    QVERIFY(value03->isString() == false);
    QVERIFY(value04->isString() == false);
    QVERIFY(value05->isString() == true);
    QVERIFY(value06->isString() == true);
    QVERIFY(value07->isString() == true);
    QVERIFY(value08->isString() == false);
    QVERIFY(value09->isString() == false);
    QVERIFY(value10->isString() == false);

    QVERIFY(value00->toString() == "null");
    QVERIFY(value01->toString() == "true");
    QVERIFY(value02->toString() == "false");
    QVERIFY(value03->toString() == "4.8");
    QVERIFY(value04->toString() == "0");
    QVERIFY(value05->toString() == "true");
    QVERIFY(value06->toString() == "false");
    QVERIFY(value07->toString() == "Hello World");
    QVERIFY(value08->toString() == "");
    QVERIFY(value09->toString() == "");
    QVERIFY(value10->toString() == "");

    QVERIFY(value00->toString("15.16") == "15.16");
    QVERIFY(value01->toString("15.16") == "15.16");
    QVERIFY(value02->toString("15.16") == "15.16");
    QVERIFY(value03->toString("15.16") == "15.16");
    QVERIFY(value04->toString("15.16") == "15.16");
    QVERIFY(value05->toString("15.16") == "true");
    QVERIFY(value06->toString("15.16") == "false");
    QVERIFY(value07->toString("15.16") == "Hello World");
    QVERIFY(value08->toString("15.16") == "15.16");
    QVERIFY(value09->toString("15.16") == "15.16");
    QVERIFY(value10->toString("15.16") == "15.16");

    QVERIFY(value00->to<QString>("15.16") == "15.16");
    QVERIFY(value01->to<QString>("15.16") == "15.16");
    QVERIFY(value02->to<QString>("15.16") == "15.16");
    QVERIFY(value03->to<QString>("15.16") == "15.16");
    QVERIFY(value04->to<QString>("15.16") == "15.16");
    QVERIFY(value05->to<QString>("15.16") == "true");
    QVERIFY(value06->to<QString>("15.16") == "false");
    QVERIFY(value07->to<QString>("15.16") == "Hello World");
    QVERIFY(value08->to<QString>("15.16") == "15.16");
    QVERIFY(value09->to<QString>("15.16") == "15.16");
    QVERIFY(value10->to<QString>("15.16") == "15.16");

    QVERIFY(value00->to<const char *>("15.16") == QString("15.16"));
    QVERIFY(value01->to<const char *>("15.16") == QString("15.16"));
    QVERIFY(value02->to<const char *>("15.16") == QString("15.16"));
    QVERIFY(value03->to<const char *>("15.16") == QString("15.16"));
    QVERIFY(value04->to<const char *>("15.16") == QString("15.16"));
    QVERIFY(value05->to<const char *>("15.16") == QString("15.16"));
    QVERIFY(value06->to<const char *>("15.16") == QString("15.16"));
    QVERIFY(value07->to<const char *>("15.16") == QString("15.16"));
    QVERIFY(value08->to<const char *>("15.16") == QString("15.16"));
    QVERIFY(value09->to<const char *>("15.16") == QString("15.16"));
    QVERIFY(value10->to<const char *>("15.16") == QString("15.16"));

    QVERIFY(value00->fromString("Test") == false);
    QVERIFY(value01->fromString("true") == true);
    QVERIFY(value02->fromString("false") == true);
    QVERIFY(value03->fromString("Test") == false);
    QVERIFY(value04->fromString("15.16") == true);
    QVERIFY(value05->fromString("Test1") == true);
    QVERIFY(value06->fromString("Test2") == true);
    QVERIFY(value07->fromString("Test3") == true);
    QVERIFY(value08->fromString("Test") == false);
    QVERIFY(value09->fromString("Test") == false);
    QVERIFY(value10->fromString("Test") == false);

    QVERIFY(value01->toBool() == true);
    QVERIFY(value02->toBool() == false);
    QVERIFY(value03->toDouble() == 4.8);
    QVERIFY(value04->toDouble() == 15.16);
    QVERIFY(value05->toString() == "Test1");
    QVERIFY(value06->toString() == "Test2");
    QVERIFY(value07->toString() == "Test3");

    QVERIFY(value00->from<QString>("Test") == false);
    QVERIFY(value01->from<QString>("Test") == false);
    QVERIFY(value02->from<QString>("Test") == false);
    QVERIFY(value03->from<QString>("Test") == false);
    QVERIFY(value04->from<QString>("Test") == false);
    QVERIFY(value05->from<QString>("Test") == true);
    QVERIFY(value06->from<QString>("Test") == true);
    QVERIFY(value07->from<QString>("Test") == true);
    QVERIFY(value08->from<QString>("Test") == false);
    QVERIFY(value09->from<QString>("Test") == false);
    QVERIFY(value10->from<QString>("Test") == false);
}

void TestJson::QMJsonValue_array(void)
{
    auto value00 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value01 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value02 = QMPointer<QMJsonValue>(new QMJsonValue(false));
    auto value03 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto value04 = QMPointer<QMJsonValue>(new QMJsonValue(0));
    auto value05 = QMPointer<QMJsonValue>(new QMJsonValue("true"));
    auto value06 = QMPointer<QMJsonValue>(new QMJsonValue("false"));
    auto value07 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value08 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonArray));
    auto value09 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonObject));
    auto value10 = QMPointer<QMJsonValue>(new QMJsonValue(QRect()));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());

    value08->toArray()->append(value00);
    value08->toArray()->append(value00);
    value08->toArray()->append(value00);

    array1->append(value00);
    array1->append(value00);

    QVERIFY(value00->isArray() == false);
    QVERIFY(value01->isArray() == false);
    QVERIFY(value02->isArray() == false);
    QVERIFY(value03->isArray() == false);
    QVERIFY(value04->isArray() == false);
    QVERIFY(value05->isArray() == false);
    QVERIFY(value06->isArray() == false);
    QVERIFY(value07->isArray() == false);
    QVERIFY(value08->isArray() == true);
    QVERIFY(value09->isArray() == false);
    QVERIFY(value10->isArray() == false);

    QVERIFY(value00->toArray()->count() == 0);
    QVERIFY(value01->toArray()->count() == 0);
    QVERIFY(value02->toArray()->count() == 0);
    QVERIFY(value03->toArray()->count() == 0);
    QVERIFY(value04->toArray()->count() == 0);
    QVERIFY(value05->toArray()->count() == 0);
    QVERIFY(value06->toArray()->count() == 0);
    QVERIFY(value07->toArray()->count() == 0);
    QVERIFY(value08->toArray()->count() == 3);
    QVERIFY(value09->toArray()->count() == 0);
    QVERIFY(value10->toArray()->count() == 0);

    QVERIFY(value00->toArray(array1)->count() == 2);
    QVERIFY(value01->toArray(array1)->count() == 2);
    QVERIFY(value02->toArray(array1)->count() == 2);
    QVERIFY(value03->toArray(array1)->count() == 2);
    QVERIFY(value04->toArray(array1)->count() == 2);
    QVERIFY(value05->toArray(array1)->count() == 2);
    QVERIFY(value06->toArray(array1)->count() == 2);
    QVERIFY(value07->toArray(array1)->count() == 2);
    QVERIFY(value08->toArray(array1)->count() == 3);
    QVERIFY(value09->toArray(array1)->count() == 2);
    QVERIFY(value10->toArray(array1)->count() == 2);

    QVERIFY(value00->to<QMPointer<QMJsonArray> >(array1)->count() == 2);
    QVERIFY(value01->to<QMPointer<QMJsonArray> >(array1)->count() == 2);
    QVERIFY(value02->to<QMPointer<QMJsonArray> >(array1)->count() == 2);
    QVERIFY(value03->to<QMPointer<QMJsonArray> >(array1)->count() == 2);
    QVERIFY(value04->to<QMPointer<QMJsonArray> >(array1)->count() == 2);
    QVERIFY(value05->to<QMPointer<QMJsonArray> >(array1)->count() == 2);
    QVERIFY(value06->to<QMPointer<QMJsonArray> >(array1)->count() == 2);
    QVERIFY(value07->to<QMPointer<QMJsonArray> >(array1)->count() == 2);
    QVERIFY(value08->to<QMPointer<QMJsonArray> >(array1)->count() == 3);
    QVERIFY(value09->to<QMPointer<QMJsonArray> >(array1)->count() == 2);
    QVERIFY(value10->to<QMPointer<QMJsonArray> >(array1)->count() == 2);

    QVERIFY(value00->fromArray(QMPointer<QMJsonArray>()) == false);
    QVERIFY(value01->fromArray(QMPointer<QMJsonArray>()) == false);
    QVERIFY(value02->fromArray(QMPointer<QMJsonArray>()) == false);
    QVERIFY(value03->fromArray(QMPointer<QMJsonArray>()) == false);
    QVERIFY(value04->fromArray(QMPointer<QMJsonArray>()) == false);
    QVERIFY(value05->fromArray(QMPointer<QMJsonArray>()) == false);
    QVERIFY(value06->fromArray(QMPointer<QMJsonArray>()) == false);
    QVERIFY(value07->fromArray(QMPointer<QMJsonArray>()) == false);
    QVERIFY(value08->fromArray(QMPointer<QMJsonArray>()) == true);
    QVERIFY(value09->fromArray(QMPointer<QMJsonArray>()) == false);
    QVERIFY(value10->fromArray(QMPointer<QMJsonArray>()) == false);

    QVERIFY(value00->from<QMPointer<QMJsonArray> >(QMPointer<QMJsonArray>()) == false);
    QVERIFY(value01->from<QMPointer<QMJsonArray> >(QMPointer<QMJsonArray>()) == false);
    QVERIFY(value02->from<QMPointer<QMJsonArray> >(QMPointer<QMJsonArray>()) == false);
    QVERIFY(value03->from<QMPointer<QMJsonArray> >(QMPointer<QMJsonArray>()) == false);
    QVERIFY(value04->from<QMPointer<QMJsonArray> >(QMPointer<QMJsonArray>()) == false);
    QVERIFY(value05->from<QMPointer<QMJsonArray> >(QMPointer<QMJsonArray>()) == false);
    QVERIFY(value06->from<QMPointer<QMJsonArray> >(QMPointer<QMJsonArray>()) == false);
    QVERIFY(value07->from<QMPointer<QMJsonArray> >(QMPointer<QMJsonArray>()) == false);
    QVERIFY(value08->from<QMPointer<QMJsonArray> >(QMPointer<QMJsonArray>()) == false);
    QVERIFY(value09->from<QMPointer<QMJsonArray> >(QMPointer<QMJsonArray>()) == false);
    QVERIFY(value10->from<QMPointer<QMJsonArray> >(QMPointer<QMJsonArray>()) == false);
}

void TestJson::QMJsonValue_object(void)
{
    auto value00 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value01 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value02 = QMPointer<QMJsonValue>(new QMJsonValue(false));
    auto value03 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto value04 = QMPointer<QMJsonValue>(new QMJsonValue(0));
    auto value05 = QMPointer<QMJsonValue>(new QMJsonValue("true"));
    auto value06 = QMPointer<QMJsonValue>(new QMJsonValue("false"));
    auto value07 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value08 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonArray));
    auto value09 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonObject));
    auto value10 = QMPointer<QMJsonValue>(new QMJsonValue(QRect()));
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());

    value09->toObject()->insert("key1", value00);
    value09->toObject()->insert("key2", value00);
    value09->toObject()->insert("key3", value00);

    object1->insert("key1", value00);
    object1->insert("key2", value00);

    QVERIFY(value00->isObject() == false);
    QVERIFY(value01->isObject() == false);
    QVERIFY(value02->isObject() == false);
    QVERIFY(value03->isObject() == false);
    QVERIFY(value04->isObject() == false);
    QVERIFY(value05->isObject() == false);
    QVERIFY(value06->isObject() == false);
    QVERIFY(value07->isObject() == false);
    QVERIFY(value08->isObject() == false);
    QVERIFY(value09->isObject() == true);
    QVERIFY(value10->isObject() == false);

    QVERIFY(value00->toObject()->count() == 0);
    QVERIFY(value01->toObject()->count() == 0);
    QVERIFY(value02->toObject()->count() == 0);
    QVERIFY(value03->toObject()->count() == 0);
    QVERIFY(value04->toObject()->count() == 0);
    QVERIFY(value05->toObject()->count() == 0);
    QVERIFY(value06->toObject()->count() == 0);
    QVERIFY(value07->toObject()->count() == 0);
    QVERIFY(value08->toObject()->count() == 0);
    QVERIFY(value09->toObject()->count() == 3);
    QVERIFY(value10->toObject()->count() == 0);

    QVERIFY(value00->toObject(object1)->count() == 2);
    QVERIFY(value01->toObject(object1)->count() == 2);
    QVERIFY(value02->toObject(object1)->count() == 2);
    QVERIFY(value03->toObject(object1)->count() == 2);
    QVERIFY(value04->toObject(object1)->count() == 2);
    QVERIFY(value05->toObject(object1)->count() == 2);
    QVERIFY(value06->toObject(object1)->count() == 2);
    QVERIFY(value07->toObject(object1)->count() == 2);
    QVERIFY(value08->toObject(object1)->count() == 2);
    QVERIFY(value09->toObject(object1)->count() == 3);
    QVERIFY(value10->toObject(object1)->count() == 2);

    QVERIFY(value00->to<QMPointer<QMJsonObject> >(object1)->count() == 2);
    QVERIFY(value01->to<QMPointer<QMJsonObject> >(object1)->count() == 2);
    QVERIFY(value02->to<QMPointer<QMJsonObject> >(object1)->count() == 2);
    QVERIFY(value03->to<QMPointer<QMJsonObject> >(object1)->count() == 2);
    QVERIFY(value04->to<QMPointer<QMJsonObject> >(object1)->count() == 2);
    QVERIFY(value05->to<QMPointer<QMJsonObject> >(object1)->count() == 2);
    QVERIFY(value06->to<QMPointer<QMJsonObject> >(object1)->count() == 2);
    QVERIFY(value07->to<QMPointer<QMJsonObject> >(object1)->count() == 2);
    QVERIFY(value08->to<QMPointer<QMJsonObject> >(object1)->count() == 2);
    QVERIFY(value09->to<QMPointer<QMJsonObject> >(object1)->count() == 3);
    QVERIFY(value10->to<QMPointer<QMJsonObject> >(object1)->count() == 2);

    QVERIFY(value00->fromObject(QMPointer<QMJsonObject>()) == false);
    QVERIFY(value01->fromObject(QMPointer<QMJsonObject>()) == false);
    QVERIFY(value02->fromObject(QMPointer<QMJsonObject>()) == false);
    QVERIFY(value03->fromObject(QMPointer<QMJsonObject>()) == false);
    QVERIFY(value04->fromObject(QMPointer<QMJsonObject>()) == false);
    QVERIFY(value05->fromObject(QMPointer<QMJsonObject>()) == false);
    QVERIFY(value06->fromObject(QMPointer<QMJsonObject>()) == false);
    QVERIFY(value07->fromObject(QMPointer<QMJsonObject>()) == false);
    QVERIFY(value08->fromObject(QMPointer<QMJsonObject>()) == false);
    QVERIFY(value09->fromObject(QMPointer<QMJsonObject>()) == true);
    QVERIFY(value10->fromObject(QMPointer<QMJsonObject>()) == false);

    QVERIFY(value00->from<QMPointer<QMJsonObject> >(QMPointer<QMJsonObject>()) == false);
    QVERIFY(value01->from<QMPointer<QMJsonObject> >(QMPointer<QMJsonObject>()) == false);
    QVERIFY(value02->from<QMPointer<QMJsonObject> >(QMPointer<QMJsonObject>()) == false);
    QVERIFY(value03->from<QMPointer<QMJsonObject> >(QMPointer<QMJsonObject>()) == false);
    QVERIFY(value04->from<QMPointer<QMJsonObject> >(QMPointer<QMJsonObject>()) == false);
    QVERIFY(value05->from<QMPointer<QMJsonObject> >(QMPointer<QMJsonObject>()) == false);
    QVERIFY(value06->from<QMPointer<QMJsonObject> >(QMPointer<QMJsonObject>()) == false);
    QVERIFY(value07->from<QMPointer<QMJsonObject> >(QMPointer<QMJsonObject>()) == false);
    QVERIFY(value08->from<QMPointer<QMJsonObject> >(QMPointer<QMJsonObject>()) == false);
    QVERIFY(value09->from<QMPointer<QMJsonObject> >(QMPointer<QMJsonObject>()) == false);
    QVERIFY(value10->from<QMPointer<QMJsonObject> >(QMPointer<QMJsonObject>()) == false);
}

void TestJson::QMJsonValue_custom(void)
{
    auto value00 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value01 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value02 = QMPointer<QMJsonValue>(new QMJsonValue(false));
    auto value03 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto value04 = QMPointer<QMJsonValue>(new QMJsonValue(0));
    auto value05 = QMPointer<QMJsonValue>(new QMJsonValue("true"));
    auto value06 = QMPointer<QMJsonValue>(new QMJsonValue("false"));
    auto value07 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value08 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonArray));
    auto value09 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonObject));
    auto value10 = QMPointer<QMJsonValue>(new QMJsonValue(QSize()));

    QVERIFY(value00->is<QSize>() == false);
    QVERIFY(value01->is<QSize>() == false);
    QVERIFY(value02->is<QSize>() == false);
    QVERIFY(value03->is<QSize>() == false);
    QVERIFY(value04->is<QSize>() == false);
    QVERIFY(value05->is<QSize>() == false);
    QVERIFY(value06->is<QSize>() == false);
    QVERIFY(value07->is<QSize>() == false);
    QVERIFY(value08->is<QSize>() == false);
    QVERIFY(value09->is<QSize>() == false);
    QVERIFY(value10->is<QSize>() == true);

    QVERIFY(value00->to<QSize>(QSize(10, 10)) == QSize(10, 10));
    QVERIFY(value01->to<QSize>(QSize(10, 10)) == QSize(10, 10));
    QVERIFY(value02->to<QSize>(QSize(10, 10)) == QSize(10, 10));
    QVERIFY(value03->to<QSize>(QSize(10, 10)) == QSize(10, 10));
    QVERIFY(value04->to<QSize>(QSize(10, 10)) == QSize(10, 10));
    QVERIFY(value05->to<QSize>(QSize(10, 10)) == QSize(10, 10));
    QVERIFY(value06->to<QSize>(QSize(10, 10)) == QSize(10, 10));
    QVERIFY(value07->to<QSize>(QSize(10, 10)) == QSize(10, 10));
    QVERIFY(value08->to<QSize>(QSize(10, 10)) == QSize(10, 10));
    QVERIFY(value09->to<QSize>(QSize(10, 10)) == QSize(10, 10));
    QVERIFY(value10->to<QSize>(QSize(10, 10)) == QSize());

    QVERIFY(value00->from<QSize>(QSize()) == false);
    QVERIFY(value01->from<QSize>(QSize()) == false);
    QVERIFY(value02->from<QSize>(QSize()) == false);
    QVERIFY(value03->from<QSize>(QSize()) == false);
    QVERIFY(value04->from<QSize>(QSize()) == false);
    QVERIFY(value05->from<QSize>(QSize()) == false);
    QVERIFY(value06->from<QSize>(QSize()) == false);
    QVERIFY(value07->from<QSize>(QSize()) == false);
    QVERIFY(value08->from<QSize>(QSize()) == false);
    QVERIFY(value09->from<QSize>(QSize()) == false);
    QVERIFY(value10->from<QSize>(QSize()) == true);
}


void TestJson::QMJsonValue_value(void)
{
    auto value01 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value02 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto array2 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto object2 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto value03 = QMPointer<QMJsonValue>(new QMJsonValue(object1));

    object1->insert("array1", array1);
    object2->insert("array2", array2);
    array1->append(object2);
    array2->append(value01);
    array2->append(value02);
    array2->append(value03);

    QVERIFY(value03->value("array1")->value(0)->value("array2")->value(0)->toBool() == true);
    QVERIFY(value03->value("array1")->value(0)->value("array2")->value(1)->toDouble() == 4.8);
}

void TestJson::QMJsonValue_from(void)
{
    auto value00 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value01 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value02 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto value03 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value04 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonArray));
    auto value05 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonObject));
    auto value06 = QMPointer<QMJsonValue>(new QMJsonValue(QRect()));

    auto value10 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value11 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value12 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto value13 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value14 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonArray));
    auto value15 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonObject));
    auto value16 = QMPointer<QMJsonValue>(new QMJsonValue(QRect()));

    QVERIFY(value00->from(value10) == true);
    QVERIFY(value00->from(value11) == false);
    QVERIFY(value00->from(value12) == false);
    QVERIFY(value00->from(value13) == false);
    QVERIFY(value00->from(value14) == false);
    QVERIFY(value00->from(value15) == false);
    QVERIFY(value00->from(value16) == false);

    QVERIFY(value01->from(value10) == true);
    QVERIFY(value01->toBool() == false);
    QVERIFY(value01->from(value11) == true);
    QVERIFY(value01->toBool() == true);
    QVERIFY(value01->from(value12) == true);
    QVERIFY(value01->toBool() == true);
    QVERIFY(value01->from(value13) == true);
    QVERIFY(value01->toBool() == false);
    QVERIFY(value01->from(value14) == true);
    QVERIFY(value01->toBool() == false);
    QVERIFY(value01->from(value15) == true);
    QVERIFY(value01->toBool() == false);
    QVERIFY(value01->from(value16) == false);
    QVERIFY(value01->toBool() == false);

    QVERIFY(value02->from(value10) == true);
    QVERIFY(value02->toDouble() == 0);
    QVERIFY(value02->from(value11) == true);
    QVERIFY(value02->toDouble() == 1);
    QVERIFY(value02->from(value12) == true);
    QVERIFY(value02->toDouble() == 4.8);
    QVERIFY(value02->from(value13) == true);
    QVERIFY(value02->toDouble() == 0);
    QVERIFY(value02->from(value14) == true);
    QVERIFY(value02->toDouble() == 0);
    QVERIFY(value02->from(value15) == true);
    QVERIFY(value02->toDouble() == 0);
    QVERIFY(value02->from(value16) == false);
    QVERIFY(value02->toDouble() == 0);

    QVERIFY(value03->from(value10) == true);
    QVERIFY(value03->toString() == "null");
    QVERIFY(value03->from(value11) == true);
    QVERIFY(value03->toString() == "true");
    QVERIFY(value03->from(value12) == true);
    QVERIFY(value03->toString() == "4.8");
    QVERIFY(value03->from(value13) == true);
    QVERIFY(value03->toString() == "Hello World");
    QVERIFY(value03->from(value14) == true);
    QVERIFY(value03->toString() == "");
    QVERIFY(value03->from(value15) == true);
    QVERIFY(value03->toString() == "");
    QVERIFY(value03->from(value16) == false);
    QVERIFY(value03->toString() == "");

    QVERIFY(value04->from(value10) == true);
    QVERIFY(value04->from(value11) == true);
    QVERIFY(value04->from(value12) == true);
    QVERIFY(value04->from(value13) == true);
    QVERIFY(value04->from(value14) == true);
    QVERIFY(value04->from(value15) == true);
    QVERIFY(value04->from(value16) == false);

    QVERIFY(value05->from(value10) == true);
    QVERIFY(value05->from(value11) == true);
    QVERIFY(value05->from(value12) == true);
    QVERIFY(value05->from(value13) == true);
    QVERIFY(value05->from(value14) == true);
    QVERIFY(value05->from(value15) == true);
    QVERIFY(value05->from(value16) == false);

    QVERIFY(value06->from(value10) == false);
    QVERIFY(value06->from(value11) == false);
    QVERIFY(value06->from(value12) == false);
    QVERIFY(value06->from(value13) == false);
    QVERIFY(value06->from(value14) == false);
    QVERIFY(value06->from(value15) == false);
    QVERIFY(value06->from(value16) == false);
}

void TestJson::QMJsonValue_variant(void)
{
    auto variant0 = QVariant();
    auto variant1 = QVariant(true);
    auto variant2 = QVariant(4.8);
    auto variant3 = QVariant("Hello World");
    auto variant4 = QVariant(QVariantList());
    auto variant5 = QVariant(QVariantHash());

    auto value0 = QMJsonValue::fromVariant(variant0);
    auto value1 = QMJsonValue::fromVariant(variant1);
    auto value2 = QMJsonValue::fromVariant(variant2);
    auto value3 = QMJsonValue::fromVariant(variant3);
    auto value4 = QMJsonValue::fromVariant(variant4);
    auto value5 = QMJsonValue::fromVariant(variant5);

    QVERIFY(value0->toVariant() == variant0);
    QVERIFY(value1->toVariant() == variant1);
    QVERIFY(value2->toVariant() == variant2);
    QVERIFY(value3->toVariant() == variant3);
    QVERIFY(value4->toVariant() == variant4);
    QVERIFY(value5->toVariant() == variant5);
}

void TestJson::QMJsonValue_signals(void)
{
    auto value01 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value02 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto value03 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value04 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonArray));
    auto value05 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonObject));
    auto value06 = QMPointer<QMJsonValue>(new QMJsonValue(QSize()));

    connect(value01.data(), &QMJsonValue::valueChanged, this, &TestJson::signaled);
    connect(value02.data(), &QMJsonValue::valueChanged, this, &TestJson::signaled);
    connect(value03.data(), &QMJsonValue::valueChanged, this, &TestJson::signaled);
    connect(value04.data(), &QMJsonValue::valueChanged, this, &TestJson::signaled);
    connect(value05.data(), &QMJsonValue::valueChanged, this, &TestJson::signaled);
    connect(value06.data(), &QMJsonValue::valueChanged, this, &TestJson::signaled);

    mCount = 0;
    value01->fromBool(true);
    value01->from<bool>(true);
    QVERIFY(mCount == 2);

    mCount = 0;
    value02->fromDouble(4.8);
    value02->from<double>(4.8);
    QVERIFY(mCount == 2);

    mCount = 0;
    value03->fromString("Test");
    value03->from<QString>("Test");
    QVERIFY(mCount == 2);

    mCount = 0;
    value04->fromArray(QMPointer<QMJsonArray>());
    value04->from<QMPointer<QMJsonArray> >(QMPointer<QMJsonArray>());
    QVERIFY(mCount == 1);

    mCount = 0;
    value05->fromObject(QMPointer<QMJsonObject>());
    value05->from<QMPointer<QMJsonObject> >(QMPointer<QMJsonObject>());
    QVERIFY(mCount == 1);

    mCount = 0;
    value06->from<QSize>(QSize());
    QVERIFY(mCount == 1);
}

void TestJson::QMJsonValue_tofromjson_null(void)
{
    auto value00 = QMPointer<QMJsonValue>(new QMJsonValue());

    auto ojson00 = value00->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto pjson00 = value00->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);

    QVERIFY(ojson00 == "null");
    QVERIFY(pjson00 == "null");

    QVERIFY(QMJsonValue::fromJson(ojson00)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson00);
    QVERIFY(QMJsonValue::fromJson(pjson00)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson00);
}

void TestJson::QMJsonValue_tofromjson_bool(void)
{
    auto value00 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value01 = QMPointer<QMJsonValue>(new QMJsonValue(false));

    auto ojson00 = value00->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson01 = value01->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto pjson00 = value00->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson01 = value01->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);

    QVERIFY(ojson00 == "true");
    QVERIFY(ojson01 == "false");
    QVERIFY(pjson00 == "true");
    QVERIFY(pjson01 == "false");

    QVERIFY(QMJsonValue::fromJson(ojson00)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson00);
    QVERIFY(QMJsonValue::fromJson(ojson01)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson01);
    QVERIFY(QMJsonValue::fromJson(pjson00)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson00);
    QVERIFY(QMJsonValue::fromJson(pjson01)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson01);
}

void TestJson::QMJsonValue_tofromjson_double(void)
{
    auto value00 = QMPointer<QMJsonValue>(new QMJsonValue(0));
    auto value01 = QMPointer<QMJsonValue>(new QMJsonValue(-.48));
    auto value02 = QMPointer<QMJsonValue>(new QMJsonValue(-0.48));
    auto value03 = QMPointer<QMJsonValue>(new QMJsonValue(-4));
    auto value04 = QMPointer<QMJsonValue>(new QMJsonValue(-4.8));
    auto value05 = QMPointer<QMJsonValue>(new QMJsonValue(-4.8e2));
    auto value06 = QMPointer<QMJsonValue>(new QMJsonValue(-4.8e-2));
    auto value07 = QMPointer<QMJsonValue>(new QMJsonValue(-4.8e+2));
    auto value08 = QMPointer<QMJsonValue>(new QMJsonValue(-4.8e15));
    auto value09 = QMPointer<QMJsonValue>(new QMJsonValue(-4.8e-15));
    auto value10 = QMPointer<QMJsonValue>(new QMJsonValue(-4.8e+15));
    auto value11 = QMPointer<QMJsonValue>(new QMJsonValue(.48));
    auto value12 = QMPointer<QMJsonValue>(new QMJsonValue(0.48));
    auto value13 = QMPointer<QMJsonValue>(new QMJsonValue(4));
    auto value14 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto value15 = QMPointer<QMJsonValue>(new QMJsonValue(4.8e2));
    auto value16 = QMPointer<QMJsonValue>(new QMJsonValue(4.8e-2));
    auto value17 = QMPointer<QMJsonValue>(new QMJsonValue(4.8e+2));
    auto value18 = QMPointer<QMJsonValue>(new QMJsonValue(4.8e15));
    auto value19 = QMPointer<QMJsonValue>(new QMJsonValue(4.8e-15));
    auto value20 = QMPointer<QMJsonValue>(new QMJsonValue(4.8e+15));

    auto ojson00 = value00->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson01 = value01->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson02 = value02->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson03 = value03->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson04 = value04->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson05 = value05->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson06 = value06->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson07 = value07->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson08 = value08->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson09 = value09->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson10 = value10->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson11 = value11->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson12 = value12->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson13 = value13->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson14 = value14->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson15 = value15->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson16 = value16->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson17 = value17->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson18 = value18->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson19 = value19->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson20 = value20->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);

    auto pjson00 = value00->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson01 = value01->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson02 = value02->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson03 = value03->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson04 = value04->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson05 = value05->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson06 = value06->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson07 = value07->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson08 = value08->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson09 = value09->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson10 = value10->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson11 = value11->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson12 = value12->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson13 = value13->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson14 = value14->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson15 = value15->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson16 = value16->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson17 = value17->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson18 = value18->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson19 = value19->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson20 = value20->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);

    QVERIFY(ojson00 == "0");
    QVERIFY(ojson01 == "-0.48");
    QVERIFY(ojson02 == "-0.48");
    QVERIFY(ojson03 == "-4");
    QVERIFY(ojson04 == "-4.8");
    QVERIFY(ojson05 == "-480");
    QVERIFY(ojson06 == "-0.048");
    QVERIFY(ojson07 == "-480");
    QVERIFY(ojson08 == "-4.8e+15");
    QVERIFY(ojson09 == "-4.8e-15");
    QVERIFY(ojson10 == "-4.8e+15");
    QVERIFY(ojson11 == "0.48");
    QVERIFY(ojson12 == "0.48");
    QVERIFY(ojson13 == "4");
    QVERIFY(ojson14 == "4.8");
    QVERIFY(ojson15 == "480");
    QVERIFY(ojson16 == "0.048");
    QVERIFY(ojson17 == "480");
    QVERIFY(ojson18 == "4.8e+15");
    QVERIFY(ojson19 == "4.8e-15");
    QVERIFY(ojson20 == "4.8e+15");

    QVERIFY(pjson00 == "0");
    QVERIFY(pjson01 == "-0.48");
    QVERIFY(pjson02 == "-0.48");
    QVERIFY(pjson03 == "-4");
    QVERIFY(pjson04 == "-4.8");
    QVERIFY(pjson05 == "-480");
    QVERIFY(pjson06 == "-0.048");
    QVERIFY(pjson07 == "-480");
    QVERIFY(pjson08 == "-4.8e+15");
    QVERIFY(pjson09 == "-4.8e-15");
    QVERIFY(pjson10 == "-4.8e+15");
    QVERIFY(pjson11 == "0.48");
    QVERIFY(pjson12 == "0.48");
    QVERIFY(pjson13 == "4");
    QVERIFY(pjson14 == "4.8");
    QVERIFY(pjson15 == "480");
    QVERIFY(pjson16 == "0.048");
    QVERIFY(pjson17 == "480");
    QVERIFY(pjson18 == "4.8e+15");
    QVERIFY(pjson19 == "4.8e-15");
    QVERIFY(pjson20 == "4.8e+15");

    QVERIFY(QMJsonValue::fromJson(ojson00)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson00);
    QVERIFY(QMJsonValue::fromJson(ojson01)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson01);
    QVERIFY(QMJsonValue::fromJson(ojson02)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson02);
    QVERIFY(QMJsonValue::fromJson(ojson03)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson03);
    QVERIFY(QMJsonValue::fromJson(ojson04)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson04);
    QVERIFY(QMJsonValue::fromJson(ojson05)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson05);
    QVERIFY(QMJsonValue::fromJson(ojson06)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson06);
    QVERIFY(QMJsonValue::fromJson(ojson07)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson07);
    QVERIFY(QMJsonValue::fromJson(ojson08)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson08);
    QVERIFY(QMJsonValue::fromJson(ojson09)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson09);
    QVERIFY(QMJsonValue::fromJson(ojson10)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson10);
    QVERIFY(QMJsonValue::fromJson(ojson11)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson11);
    QVERIFY(QMJsonValue::fromJson(ojson12)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson12);
    QVERIFY(QMJsonValue::fromJson(ojson13)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson13);
    QVERIFY(QMJsonValue::fromJson(ojson14)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson14);
    QVERIFY(QMJsonValue::fromJson(ojson15)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson15);
    QVERIFY(QMJsonValue::fromJson(ojson16)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson16);
    QVERIFY(QMJsonValue::fromJson(ojson17)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson17);
    QVERIFY(QMJsonValue::fromJson(ojson18)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson18);
    QVERIFY(QMJsonValue::fromJson(ojson19)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson19);
    QVERIFY(QMJsonValue::fromJson(ojson20)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson20);

    QVERIFY(QMJsonValue::fromJson(pjson00)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson00);
    QVERIFY(QMJsonValue::fromJson(pjson01)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson01);
    QVERIFY(QMJsonValue::fromJson(pjson02)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson02);
    QVERIFY(QMJsonValue::fromJson(pjson03)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson03);
    QVERIFY(QMJsonValue::fromJson(pjson04)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson04);
    QVERIFY(QMJsonValue::fromJson(pjson05)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson05);
    QVERIFY(QMJsonValue::fromJson(pjson06)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson06);
    QVERIFY(QMJsonValue::fromJson(pjson07)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson07);
    QVERIFY(QMJsonValue::fromJson(pjson08)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson08);
    QVERIFY(QMJsonValue::fromJson(pjson09)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson09);
    QVERIFY(QMJsonValue::fromJson(pjson10)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson10);
    QVERIFY(QMJsonValue::fromJson(pjson11)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson11);
    QVERIFY(QMJsonValue::fromJson(pjson12)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson12);
    QVERIFY(QMJsonValue::fromJson(pjson13)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson13);
    QVERIFY(QMJsonValue::fromJson(pjson14)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson14);
    QVERIFY(QMJsonValue::fromJson(pjson15)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson15);
    QVERIFY(QMJsonValue::fromJson(pjson16)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson16);
    QVERIFY(QMJsonValue::fromJson(pjson17)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson17);
    QVERIFY(QMJsonValue::fromJson(pjson18)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson18);
    QVERIFY(QMJsonValue::fromJson(pjson19)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson19);
    QVERIFY(QMJsonValue::fromJson(pjson20)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson20);
}

void TestJson::QMJsonValue_tofromjson_string(void)
{
    auto value00 = QMPointer<QMJsonValue>(new QMJsonValue(""));
    auto value01 = QMPointer<QMJsonValue>(new QMJsonValue("Test"));
    auto value02 = QMPointer<QMJsonValue>(new QMJsonValue("\"Test\""));
    auto value03 = QMPointer<QMJsonValue>(new QMJsonValue("\\"));
    auto value04 = QMPointer<QMJsonValue>(new QMJsonValue("/"));
    auto value05 = QMPointer<QMJsonValue>(new QMJsonValue("\b"));
    auto value06 = QMPointer<QMJsonValue>(new QMJsonValue("\f"));
    auto value07 = QMPointer<QMJsonValue>(new QMJsonValue("\n"));
    auto value08 = QMPointer<QMJsonValue>(new QMJsonValue("\r"));
    auto value09 = QMPointer<QMJsonValue>(new QMJsonValue("\t"));

    auto ojson00 = value00->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson01 = value01->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson02 = value02->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson03 = value03->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson04 = value04->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson05 = value05->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson06 = value06->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson07 = value07->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson08 = value08->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson09 = value09->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);

    auto pjson00 = value00->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson01 = value01->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson02 = value02->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson03 = value03->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson04 = value04->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson05 = value05->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson06 = value06->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson07 = value07->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson08 = value08->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson09 = value09->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);

    QVERIFY(ojson00 == "\"\"");
    QVERIFY(ojson01 == "\"Test\"");
    QVERIFY(ojson02 == "\"\\\"Test\\\"\"");
    QVERIFY(ojson03 == "\"\\\\\"");
    QVERIFY(ojson04 == "\"\\/\"");
    QVERIFY(ojson05 == "\"\\b\"");
    QVERIFY(ojson06 == "\"\\f\"");
    QVERIFY(ojson07 == "\"\\n\"");
    QVERIFY(ojson08 == "\"\\r\"");
    QVERIFY(ojson09 == "\"\\t\"");

    QVERIFY(pjson00 == "\"\"");
    QVERIFY(pjson01 == "\"Test\"");
    QVERIFY(pjson02 == "\"\\\"Test\\\"\"");
    QVERIFY(pjson03 == "\"\\\\\"");
    QVERIFY(pjson04 == "\"\\/\"");
    QVERIFY(pjson05 == "\"\\b\"");
    QVERIFY(pjson06 == "\"\\f\"");
    QVERIFY(pjson07 == "\"\\n\"");
    QVERIFY(pjson08 == "\"\\r\"");
    QVERIFY(pjson09 == "\"\\t\"");

    QVERIFY(QMJsonValue::fromJson(ojson00)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson00);
    QVERIFY(QMJsonValue::fromJson(ojson01)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson01);
    QVERIFY(QMJsonValue::fromJson(ojson02)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson02);
    QVERIFY(QMJsonValue::fromJson(ojson03)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson03);
    QVERIFY(QMJsonValue::fromJson(ojson04)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson04);
    QVERIFY(QMJsonValue::fromJson(ojson05)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson05);
    QVERIFY(QMJsonValue::fromJson(ojson06)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson06);
    QVERIFY(QMJsonValue::fromJson(ojson07)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson07);
    QVERIFY(QMJsonValue::fromJson(ojson08)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson08);
    QVERIFY(QMJsonValue::fromJson(ojson09)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson09);

    QVERIFY(QMJsonValue::fromJson(pjson00)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson00);
    QVERIFY(QMJsonValue::fromJson(pjson01)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson01);
    QVERIFY(QMJsonValue::fromJson(pjson02)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson02);
    QVERIFY(QMJsonValue::fromJson(pjson03)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson03);
    QVERIFY(QMJsonValue::fromJson(pjson04)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson04);
    QVERIFY(QMJsonValue::fromJson(pjson05)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson05);
    QVERIFY(QMJsonValue::fromJson(pjson06)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson06);
    QVERIFY(QMJsonValue::fromJson(pjson07)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson07);
    QVERIFY(QMJsonValue::fromJson(pjson08)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson08);
    QVERIFY(QMJsonValue::fromJson(pjson09)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson09);
}

void TestJson::QMJsonValue_tofromjson_array(void)
{
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto array2 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto array3 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(array1));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue(array2));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(array3));

    array2->append(new QMJsonValue);
    array2->append(true);
    array2->append(4.8);
    array2->append("test");

    array3->append(array1);
    array3->append(array2);

    auto ojson1 = value1->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson2 = value2->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson3 = value3->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto pjson1 = value1->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson2 = value2->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson3 = value3->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);

    QVERIFY(ojson1 == "[]");
    QVERIFY(ojson2 == "[null,true,4.8,\"test\"]");
    QVERIFY(ojson3 == "[[],[null,true,4.8,\"test\"]]");

    QVERIFY(pjson1 == "[]");
    QVERIFY(pjson2 == "[\n"
            "    null,\n"
            "    true,\n"
            "    4.8,\n"
            "    \"test\"\n"
            "]");
    QVERIFY(pjson3 == "[\n"
            "    [],\n"
            "    [\n"
            "        null,\n"
            "        true,\n"
            "        4.8,\n"
            "        \"test\"\n"
            "    ]\n"
            "]");

    QVERIFY(QMJsonValue::fromJson(ojson1)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson1);
    QVERIFY(QMJsonValue::fromJson(ojson2)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson2);
    QVERIFY(QMJsonValue::fromJson(ojson3)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson3);

    QVERIFY(QMJsonValue::fromJson(pjson1)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson1);
    QVERIFY(QMJsonValue::fromJson(pjson2)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson2);
    QVERIFY(QMJsonValue::fromJson(pjson3)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson3);
}

void TestJson::QMJsonValue_tofromjson_object(void)
{
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto object2 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto object3 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(object1));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue(object2));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(object3));

    object2->insert("key0", new QMJsonValue);
    object2->insert("key1", true);
    object2->insert("key2", 4.8);
    object2->insert("key3", "test");

    object3->insert("key4", object1);
    object3->insert("key5", object2);

    auto ojson1 = value1->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson2 = value2->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto ojson3 = value3->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive);
    auto pjson1 = value1->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson2 = value2->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);
    auto pjson3 = value3->toJson(QMJsonFormat_Pretty, QMJsonSort_CaseSensitive);

    QVERIFY(ojson1 == "{}");
    QVERIFY(ojson2 == "{\"key0\":null,\"key1\":true,\"key2\":4.8,\"key3\":\"test\"}");
    QVERIFY(ojson3 == "{\"key4\":{},\"key5\":{\"key0\":null,\"key1\":true,\"key2\":4.8,\"key3\":\"test\"}}");

    QVERIFY(pjson1 == "{}");
    QVERIFY(pjson2 == "{\n"
            "    \"key0\" : null,\n"
            "    \"key1\" : true,\n"
            "    \"key2\" : 4.8,\n"
            "    \"key3\" : \"test\"\n"
            "}");
    QVERIFY(pjson3 == "{\n"
            "    \"key4\" : {},\n"
            "    \"key5\" : {\n"
            "        \"key0\" : null,\n"
            "        \"key1\" : true,\n"
            "        \"key2\" : 4.8,\n"
            "        \"key3\" : \"test\"\n"
            "    }\n"
            "}");

    QVERIFY(QMJsonValue::fromJson(ojson1)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson1);
    QVERIFY(QMJsonValue::fromJson(ojson2)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson2);
    QVERIFY(QMJsonValue::fromJson(ojson3)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson3);

    QVERIFY(QMJsonValue::fromJson(pjson1)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson1);
    QVERIFY(QMJsonValue::fromJson(pjson2)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson2);
    QVERIFY(QMJsonValue::fromJson(pjson3)->toJson(QMJsonFormat_Optimized, QMJsonSort_CaseSensitive) == ojson3);
}

void TestJson::QMJsonValue_fromjson(void)
{
    QVERIFY(QMJsonValue::fromJson("").isNull() == true);
    QVERIFY(QMJsonValue::fromJson("nil").isNull() == true);
    QVERIFY(QMJsonValue::fromJson("talse").isNull() == true);
    QVERIFY(QMJsonValue::fromJson("frue").isNull() == true);
    QVERIFY(QMJsonValue::fromJson("000pppsssss").isNull() == true);
    QVERIFY(QMJsonValue::fromJson("\"\"invalid").isNull() == true);
    QVERIFY(QMJsonValue::fromJson("[]invalid").isNull() == true);
    QVERIFY(QMJsonValue::fromJson("{}invalid").isNull() == true);
}
