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

void TestJson::QMJsonObject_create(void)
{
    auto hash1 = QHash<QString, QMPointer<QMJsonValue> >();
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(4));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue(8));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(15));

    hash1["key1"] = value1;
    hash1["key2"] = value2;
    hash1["key3"] = value3;
    object1->insert("key1", value1);
    object1->insert("key2", value2);
    object1->insert("key3", value3);

    auto object2 = QMPointer<QMJsonObject>(new QMJsonObject(hash1));

    QVERIFY(object1->toDouble("key1") == object2->toDouble("key1"));
    QVERIFY(object1->toDouble("key2") == object2->toDouble("key2"));
    QVERIFY(object1->toDouble("key3") == object2->toDouble("key3"));
}

void TestJson::QMJsonObject_insert(void)
{
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto object2 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto rawValue1 = new QMJsonValue();
    auto rawArray1 = new QMJsonArray();
    auto rawObject1 = new QMJsonObject();

    object1->insert("key1", new QMJsonValue());
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isNull() == true);

    object1->insert("key1", QMPointer<QMJsonValue>());
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isNull() == true);

    object1->insert("key1", value1);
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isNull() == true);

    object1->insert("key1", rawValue1);
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isNull() == true);

    object1->insert("key1", new QMJsonArray());
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isArray() == true);

    object1->insert("key1", QMPointer<QMJsonArray>());
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isArray() == true);

    object1->insert("key1", array1);
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isArray() == true);

    object1->insert("key1", rawArray1);
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isArray() == true);

    object1->insert("key1", new QMJsonObject());
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isObject() == true);

    object1->insert("key1", QMPointer<QMJsonObject>());
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isObject() == true);

    object1->insert("key1", object1);
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isObject() == true);

    object1->insert("key1", rawObject1);
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isObject() == true);

    object1->insert("key1", QMPointer<QMJsonValue>());
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isNull() == true);

    object1->insert("key1", 4.8);
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isDouble() == true);

    object1->insert("key1", "Hello World");
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isString() == true);

    object1->insert("key1", QString("Hello World"));
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isString() == true);

    object1->insert("key1", new QMJsonValue(4.8));
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isDouble() == true);

    object1->insert("key1", new QMJsonValue("Hello World"));
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isString() == true);

    object1->insert("key1", new QMJsonValue(QString("Hello World")));
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isString() == true);

    object1->insert("key1", QMPointer<QMJsonValue>(new QMJsonValue(4.8)));
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isDouble() == true);

    object1->insert("key1", QMPointer<QMJsonValue>(new QMJsonValue("Hello World")));
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isString() == true);

    object1->insert("key1", QMPointer<QMJsonValue>(new QMJsonValue(QString("Hello World"))));
    QVERIFY(object1->value("key1").isNull() == false);
    QVERIFY(object1->value("key1")->isString() == true);
}

void TestJson::QMJsonObject_unite(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto array2 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto object2 = QMPointer<QMJsonObject>(new QMJsonObject());

    array2->append(value2);
    array2->append(value3);
    object2->insert("key0", value2);
    object2->insert("key2", value3);
    object2->insert("array", array2);

    object1->clear();
    array1->append(value0);
    array1->append(value1);
    object1->insert("key0", value0);
    object1->insert("key1", value1);
    object1->insert("array", array1);
    object1->unite(object2, QMJsonReplacementPolicy_Replace, QMJsonArrayUnitePolicy_Append);

    QVERIFY(object1->isString("key0") == true);
    QVERIFY(object1->isBool("key1") == true);
    QVERIFY(object1->isDouble("key2") == true);
    QVERIFY(object1->toArray("array")->isNull(0) == true);
    QVERIFY(object1->toArray("array")->isBool(1) == true);
    QVERIFY(object1->toArray("array")->isString(2) == true);
    QVERIFY(object1->toArray("array")->isDouble(3) == true);

    object1->clear();
    array1->append(value0);
    array1->append(value1);
    object1->insert("key0", value0);
    object1->insert("key1", value1);
    object1->insert("array", array1);
    object1->unite(object2, QMJsonReplacementPolicy_Replace, QMJsonArrayUnitePolicy_Prepend);

    QVERIFY(object1->isString("key0") == true);
    QVERIFY(object1->isBool("key1") == true);
    QVERIFY(object1->isDouble("key2") == true);
    QVERIFY(object1->toArray("array")->isDouble(0) == true);
    QVERIFY(object1->toArray("array")->isString(1) == true);
    QVERIFY(object1->toArray("array")->isNull(2) == true);
    QVERIFY(object1->toArray("array")->isBool(3) == true);

    object1->clear();
    array1->append(value0);
    array1->append(value1);
    object1->insert("key0", value0);
    object1->insert("key1", value1);
    object1->insert("array", array1);
    object1->unite(object2, QMJsonReplacementPolicy_Ignore, QMJsonArrayUnitePolicy_Append);

    QVERIFY(object1->isNull("key0") == true);
    QVERIFY(object1->isBool("key1") == true);
    QVERIFY(object1->isDouble("key2") == true);
    QVERIFY(object1->toArray("array")->isNull(0) == true);
    QVERIFY(object1->toArray("array")->isBool(1) == true);
    QVERIFY(object1->toArray("array")->isString(2) == true);
    QVERIFY(object1->toArray("array")->isDouble(3) == true);

    object1->clear();
    array1->append(value0);
    array1->append(value1);
    object1->insert("key0", value0);
    object1->insert("key1", value1);
    object1->insert("array", array1);
    object1->unite(object2, QMJsonReplacementPolicy_Ignore, QMJsonArrayUnitePolicy_Prepend);

    QVERIFY(object1->isNull("key0") == true);
    QVERIFY(object1->isBool("key1") == true);
    QVERIFY(object1->isDouble("key2") == true);
    QVERIFY(object1->toArray("array")->isDouble(0) == true);
    QVERIFY(object1->toArray("array")->isString(1) == true);
    QVERIFY(object1->toArray("array")->isNull(2) == true);
    QVERIFY(object1->toArray("array")->isBool(3) == true);
}

void TestJson::QMJsonObject_iter(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());

    object1->insert("key0", value0);
    object1->insert("key1", value1);
    object1->insert("key2", value2);
    object1->insert("key3", value3);

    auto iter0 = object1->find("key0");
    QVERIFY(iter0.value() == value0);

    auto iter1 = object1->find("key1");
    QVERIFY(iter1.value() == value1);

    auto iter2 = object1->find("key2");
    QVERIFY(iter2.value() == value2);

    auto iter3 = object1->find("key3");
    QVERIFY(iter3.value() == value3);

    auto iter4 = object1->find("blah");
    QVERIFY(iter4 == object1->end());

    auto iter5 = object1->begin();
    QVERIFY(iter5 != object1->end());

    const auto const_iter0 = object1->cfind("key0");
    QVERIFY(const_iter0.value() == value0);

    const auto const_iter1 = object1->cfind("key1");
    QVERIFY(const_iter1.value() == value1);

    const auto const_iter2 = object1->cfind("key2");
    QVERIFY(const_iter2.value() == value2);

    const auto const_iter3 = object1->cfind("key3");
    QVERIFY(const_iter3.value() == value3);

    const auto const_iter4 = object1->cfind("blah");
    QVERIFY(const_iter4 == object1->cend());

    const auto const_iter5 = object1->cbegin();
    QVERIFY(const_iter5 != object1->cend());

    auto iter = object1->begin();
    while(iter != object1->end())
        iter = object1->erase(iter);

    QVERIFY(object1->count() == 0);
}

void TestJson::QMJsonObject_count(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());

    QVERIFY(object1->count() == 0);
    QVERIFY(object1->size() == 0);

    object1->insert("key0", value0);
    QVERIFY(object1->count() == 1);
    QVERIFY(object1->size() == 1);

    object1->insert("key1", value1);
    QVERIFY(object1->count() == 2);
    QVERIFY(object1->size() == 2);

    object1->insert("key2", value2);
    QVERIFY(object1->count() == 3);
    QVERIFY(object1->size() == 3);

    object1->insert("key3", value3);
    QVERIFY(object1->count() == 4);
    QVERIFY(object1->size() == 4);

    object1->clear();
    QVERIFY(object1->count() == 0);
    QVERIFY(object1->size() == 0);
}

void TestJson::QMJsonObject_clear(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto object2 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto document1 = QMPointer<QMJsonValue>(new QMJsonValue(array1));
    auto document2 = QMPointer<QMJsonValue>(new QMJsonValue(object1));
    auto document3 = QMPointer<QMJsonValue>(new QMJsonValue(object2));

    array1->append(value0);
    array1->append(value1);
    object1->insert("key2", value2);
    object1->insert("key3", value3);
    object2->insert("array", array1);
    object2->insert("object", object1);

    object2->clear();

    QVERIFY(document1->toJson() == "[]");
    QVERIFY(document2->toJson() == "{}");
    QVERIFY(document3->toJson() == "{}");
}

void TestJson::QMJsonObject_empty(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());

    QVERIFY(object1->isEmpty() == true);
    QVERIFY(object1->empty() == true);

    object1->insert("key0", value0);
    object1->insert("key1", value1);
    object1->insert("key2", value2);
    object1->insert("key3", value3);

    QVERIFY(object1->isEmpty() == false);
    QVERIFY(object1->empty() == false);

    object1->clear();

    QVERIFY(object1->isEmpty() == true);
    QVERIFY(object1->empty() == true);
}

void TestJson::QMJsonObject_contains(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());

    QVERIFY(object1->contains("") == false);
    QVERIFY(object1->contains(QString()) == false);
    QVERIFY(object1->contains("key0") == false);
    QVERIFY(object1->contains("key1") == false);
    QVERIFY(object1->contains("key2") == false);
    QVERIFY(object1->contains("key3") == false);
    QVERIFY(object1->contains("key4") == false);

    object1->insert("key0", value0);
    object1->insert("key1", value1);
    object1->insert("key2", value2);
    object1->insert("key3", value3);

    QVERIFY(object1->contains("key0") == true);
    QVERIFY(object1->contains("key1") == true);
    QVERIFY(object1->contains("key2") == true);
    QVERIFY(object1->contains("key3") == true);
    QVERIFY(object1->contains("key4") == false);

    object1->clear();

    QVERIFY(object1->contains("key0") == false);
    QVERIFY(object1->contains("key1") == false);
    QVERIFY(object1->contains("key2") == false);
    QVERIFY(object1->contains("key3") == false);
    QVERIFY(object1->contains("key4") == false);
}

void TestJson::QMJsonObject_remove(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());

    object1->remove("");
    object1->remove(QString());
    object1->remove("key0");
    QVERIFY(object1->count() == 0);
    QVERIFY(object1->take("key0").isNull() == false);
    QVERIFY(object1->take("key0", value0).isNull() == false);
    QVERIFY(object1->take("key0", 4.8).isNull() == false);
    QVERIFY(object1->count() == 0);

    auto array = object1->take("array", QMPointer<QMJsonArray>());
    QVERIFY(array.isNull() == false);
    QVERIFY(array->toArray().isNull() == false);

    auto object = object1->take("object", QMPointer<QMJsonObject>());
    QVERIFY(object.isNull() == false);
    QVERIFY(object->toArray().isNull() == false);

    object1->insert("key0", value0);
    object1->insert("key1", value1);
    object1->insert("key2", value2);
    object1->insert("key3", value3);

    object1->remove("key0");
    QVERIFY(object1->count() == 3);
    QVERIFY(object1->take("key1") == value1);
    QVERIFY(object1->take("key2", value0) == value2);
    QVERIFY(object1->take("key3", 4.8) == value3);
    QVERIFY(object1->count() == 0);
}

void TestJson::QMJsonObject_key(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());

    QVERIFY(object1->key(QMPointer<QMJsonValue>()) == QString());
    QVERIFY(object1->key(value0) == QString());
    QVERIFY(object1->key(value0, "test") == "test");

    object1->insert("key0", value0);
    object1->insert("key1", value1);
    object1->insert("key2", value2);
    object1->insert("key3", value3);

    QVERIFY(object1->key(value0) == "key0");
    QVERIFY(object1->key(value0, "test") == "key0");

    QVERIFY(object1->key(value1) == "key1");
    QVERIFY(object1->key(value1, "test") == "key1");

    QVERIFY(object1->key(value2) == "key2");
    QVERIFY(object1->key(value2, "test") == "key2");

    QVERIFY(object1->key(value3) == "key3");
    QVERIFY(object1->key(value3, "test") == "key3");
}

void TestJson::QMJsonObject_value(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());

    QVERIFY(object1->value("").isNull() == false);
    QVERIFY(object1->value(QString()).isNull() == false);
    QVERIFY(object1->value("key0").isNull() == false);
    QVERIFY(object1->value("key0", QMPointer<QMJsonValue>()).isNull() == true);
    QVERIFY(object1->value("key0", value2) == value2);
    QVERIFY(object1->value("key0", 4.8).isNull() == false);

    auto array = object1->value("array", QMPointer<QMJsonArray>());
    QVERIFY(array.isNull() == false);
    QVERIFY(array->toArray().isNull() == false);

    auto object = object1->value("object", QMPointer<QMJsonObject>());
    QVERIFY(object.isNull() == false);
    QVERIFY(object->toArray().isNull() == false);

    object1->insert("key0", value0);
    object1->insert("key1", value1);
    object1->insert("key2", value2);
    object1->insert("key3", value3);

    QVERIFY(object1->value("key0") == value0);
    QVERIFY(object1->value("key0", QMPointer<QMJsonValue>()) == value0);
    QVERIFY(object1->value("key0", value2) == value0);
    QVERIFY(object1->value("key0", 4.8) == value0);

    QVERIFY(object1->value("key1") == value1);
    QVERIFY(object1->value("key1", QMPointer<QMJsonValue>()) == value1);
    QVERIFY(object1->value("key1", value2) == value1);
    QVERIFY(object1->value("key1", 4.8) == value1);

    QVERIFY(object1->value("key2") == value2);
    QVERIFY(object1->value("key2", QMPointer<QMJsonValue>()) == value2);
    QVERIFY(object1->value("key2", value0) == value2);
    QVERIFY(object1->value("key2", 4.8) == value2);

    QVERIFY(object1->value("key3") == value3);
    QVERIFY(object1->value("key3", QMPointer<QMJsonValue>()) == value3);
    QVERIFY(object1->value("key3", value2) == value3);
    QVERIFY(object1->value("key3", 4.8) == value3);
}

void TestJson::QMJsonObject_keys(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());

    QVERIFY(object1->keys() == QList<QString>());
    QVERIFY(object1->keys().count() == 0);

    object1->insert("key0", value0);
    object1->insert("key1", value1);
    object1->insert("key2", value2);
    object1->insert("key3", value3);

    QStringList keys = object1->keys();
    keys.sort();

    QVERIFY(keys == QStringList() << "key0" << "key1" << "key2" << "key3");
    QVERIFY(keys.count() == 4);
}

void TestJson::QMJsonObject_values(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());

    QVERIFY(object1->values() == QList<QMPointer<QMJsonValue> >());
    QVERIFY(object1->values().count() == 0);

    object1->insert("key0", value0);
    object1->insert("key1", value1);
    object1->insert("key2", value2);
    object1->insert("key3", value3);

    auto values = object1->values();
    QVERIFY(values.contains(value0) == true);
    QVERIFY(values.contains(value1) == true);
    QVERIFY(values.contains(value2) == true);
    QVERIFY(values.contains(value3) == true);
    QVERIFY(values.count() == 4);
}

void TestJson::QMJsonObject_null(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());

    object1->insert("key0", value0);

    QVERIFY(object1->isNull("key0") == true);
    QVERIFY(object1->isBool("key0") == false);
    QVERIFY(object1->isDouble("key0") == false);
    QVERIFY(object1->isString("key0") == false);
    QVERIFY(object1->isArray("key0") == false);
    QVERIFY(object1->isObject("key0") == false);
    QVERIFY(object1->is<QRect>("key0") == false);

    QVERIFY(object1->toBool("key0") == false);
    QVERIFY(object1->toDouble("key0") == 0);
    QVERIFY(object1->toString("key0") == "null");
    QVERIFY(object1->toArray("key0").isNull() == false);
    QVERIFY(object1->toObject("key0").isNull() == false);

    QVERIFY(object1->toBool("key0", true) == true);
    QVERIFY(object1->toDouble("key0", 4.8) == 4.8);
    QVERIFY(object1->toString("key0", "15.16") == "15.16");
    QVERIFY(object1->toArray("key0", QMPointer<QMJsonArray>()).isNull() == true);
    QVERIFY(object1->toObject("key0", QMPointer<QMJsonObject>()).isNull() == true);
    QVERIFY(object1->to<QRect>("key0", QRect()) == QRect());
    QVERIFY(object1->from("key0", value0) == true);
    QVERIFY(object1->from<QSize>("key0", QSize(15, 16)) == false);
}

void TestJson::QMJsonObject_bool(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());

    object1->insert("key0", value0);

    QVERIFY(object1->isNull("key0") == false);
    QVERIFY(object1->isBool("key0") == true);
    QVERIFY(object1->isDouble("key0") == false);
    QVERIFY(object1->isString("key0") == false);
    QVERIFY(object1->isArray("key0") == false);
    QVERIFY(object1->isObject("key0") == false);
    QVERIFY(object1->is<QRect>("key0") == false);

    QVERIFY(object1->toBool("key0") == true);
    QVERIFY(object1->toDouble("key0") == 1);
    QVERIFY(object1->toString("key0") == "true");
    QVERIFY(object1->toArray("key0").isNull() == false);
    QVERIFY(object1->toObject("key0").isNull() == false);

    QVERIFY(object1->toBool("key0", false) == true);
    QVERIFY(object1->toDouble("key0", 4.8) == 4.8);
    QVERIFY(object1->toString("key0", "15.16") == "15.16");
    QVERIFY(object1->toArray("key0", QMPointer<QMJsonArray>()).isNull() == true);
    QVERIFY(object1->toObject("key0", QMPointer<QMJsonObject>()).isNull() == true);
    QVERIFY(object1->to<QRect>("key0", QRect()) == QRect());

    QVERIFY(object1->from("key0", value0) == true);
    QVERIFY(object1->fromBool("key0", false) == true);
    QVERIFY(object1->fromDouble("key0", 4.8) == true);
    QVERIFY(object1->fromString("key0", "false") == true);
    QVERIFY(object1->fromArray("key0", QMPointer<QMJsonArray>()) == false);
    QVERIFY(object1->fromObject("key0", QMPointer<QMJsonObject>()) == false);
    QVERIFY(object1->from<QSize>("key0", QSize(15, 16)) == false);
}

void TestJson::QMJsonObject_double(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());

    object1->insert("key0", value0);

    QVERIFY(object1->isNull("key0") == false);
    QVERIFY(object1->isBool("key0") == false);
    QVERIFY(object1->isDouble("key0") == true);
    QVERIFY(object1->isString("key0") == false);
    QVERIFY(object1->isArray("key0") == false);
    QVERIFY(object1->isObject("key0") == false);
    QVERIFY(object1->is<QRect>("key0") == false);

    QVERIFY(object1->toBool("key0") == true);
    QVERIFY(object1->toDouble("key0") == 4.8);
    QVERIFY(object1->toString("key0") == "4.8");
    QVERIFY(object1->toArray("key0").isNull() == false);
    QVERIFY(object1->toObject("key0").isNull() == false);

    QVERIFY(object1->toBool("key0", false) == false);
    QVERIFY(object1->toDouble("key0", 15.16) == 4.8);
    QVERIFY(object1->toString("key0", "15.16") == "15.16");
    QVERIFY(object1->toArray("key0", QMPointer<QMJsonArray>()).isNull() == true);
    QVERIFY(object1->toObject("key0", QMPointer<QMJsonObject>()).isNull() == true);
    QVERIFY(object1->to<QRect>("key0", QRect()) == QRect());

    QVERIFY(object1->from("key0", value0) == true);
    QVERIFY(object1->fromBool("key0", false) == true);
    QVERIFY(object1->fromDouble("key0", 15.16) == true);
    QVERIFY(object1->fromString("key0", "false") == false);
    QVERIFY(object1->fromArray("key0", QMPointer<QMJsonArray>()) == false);
    QVERIFY(object1->fromObject("key0", QMPointer<QMJsonObject>()) == false);
    QVERIFY(object1->from<QSize>("key0", QSize(15, 16)) == false);
}

void TestJson::QMJsonObject_string(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue("test"));
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());

    object1->insert("key0", value0);

    QVERIFY(object1->isNull("key0") == false);
    QVERIFY(object1->isBool("key0") == false);
    QVERIFY(object1->isDouble("key0") == false);
    QVERIFY(object1->isString("key0") == true);
    QVERIFY(object1->isArray("key0") == false);
    QVERIFY(object1->isObject("key0") == false);
    QVERIFY(object1->is<QRect>("key0") == false);

    QVERIFY(object1->toBool("key0") == false);
    QVERIFY(object1->toDouble("key0") == 0);
    QVERIFY(object1->toString("key0") == "test");
    QVERIFY(object1->toArray("key0").isNull() == false);
    QVERIFY(object1->toObject("key0").isNull() == false);

    QVERIFY(object1->toBool("key0", true) == true);
    QVERIFY(object1->toDouble("key0", 15.16) == 15.16);
    QVERIFY(object1->toString("key0", "15.16") == "test");
    QVERIFY(object1->toArray("key0", QMPointer<QMJsonArray>()).isNull() == true);
    QVERIFY(object1->toObject("key0", QMPointer<QMJsonObject>()).isNull() == true);
    QVERIFY(object1->to<QRect>("key0", QRect()) == QRect());

    QVERIFY(object1->from("key0", value0) == true);
    QVERIFY(object1->fromBool("key0", false) == true);
    QVERIFY(object1->fromDouble("key0", 15.16) == true);
    QVERIFY(object1->fromString("key0", "15.16") == true);
    QVERIFY(object1->fromArray("key0", QMPointer<QMJsonArray>()) == false);
    QVERIFY(object1->fromObject("key0", QMPointer<QMJsonObject>()) == false);
    QVERIFY(object1->from<QSize>("key0", QSize(15, 16)) == false);
}

void TestJson::QMJsonObject_array(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonArray()));
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());

    object1->insert("key0", value0);

    QVERIFY(object1->isNull("key0") == false);
    QVERIFY(object1->isBool("key0") == false);
    QVERIFY(object1->isDouble("key0") == false);
    QVERIFY(object1->isString("key0") == false);
    QVERIFY(object1->isArray("key0") == true);
    QVERIFY(object1->isObject("key0") == false);
    QVERIFY(object1->is<QRect>("key0") == false);

    QVERIFY(object1->toBool("key0") == false);
    QVERIFY(object1->toDouble("key0") == 0);
    QVERIFY(object1->toString("key0") == QString());
    QVERIFY(object1->toArray("key0").isNull() == false);
    QVERIFY(object1->toObject("key0").isNull() == false);

    QVERIFY(object1->toBool("key0", true) == true);
    QVERIFY(object1->toDouble("key0", 15.16) == 15.16);
    QVERIFY(object1->toString("key0", "15.16") == "15.16");
    QVERIFY(object1->toArray("key0", QMPointer<QMJsonArray>()).isNull() == false);
    QVERIFY(object1->toObject("key0", QMPointer<QMJsonObject>()).isNull() == true);
    QVERIFY(object1->to<QRect>("key0", QRect()) == QRect());

    QVERIFY(object1->from("key0", value0) == true);
    QVERIFY(object1->fromBool("key0", false) == false);
    QVERIFY(object1->fromDouble("key0", 15.16) == false);
    QVERIFY(object1->fromString("key0", "15.16") == false);
    QVERIFY(object1->fromArray("key0", QMPointer<QMJsonArray>()) == true);
    QVERIFY(object1->fromObject("key0", QMPointer<QMJsonObject>()) == false);
    QVERIFY(object1->from<QSize>("key0", QSize(15, 16)) == false);
}

void TestJson::QMJsonObject_object(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonObject()));
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());

    object1->insert("key0", value0);

    QVERIFY(object1->isNull("key0") == false);
    QVERIFY(object1->isBool("key0") == false);
    QVERIFY(object1->isDouble("key0") == false);
    QVERIFY(object1->isString("key0") == false);
    QVERIFY(object1->isArray("key0") == false);
    QVERIFY(object1->isObject("key0") == true);
    QVERIFY(object1->is<QRect>("key0") == false);

    QVERIFY(object1->toBool("key0") == false);
    QVERIFY(object1->toDouble("key0") == 0);
    QVERIFY(object1->toString("key0") == QString());
    QVERIFY(object1->toArray("key0").isNull() == false);
    QVERIFY(object1->toObject("key0").isNull() == false);

    QVERIFY(object1->toBool("key0", true) == true);
    QVERIFY(object1->toDouble("key0", 15.16) == 15.16);
    QVERIFY(object1->toString("key0", "15.16") == "15.16");
    QVERIFY(object1->toArray("key0", QMPointer<QMJsonArray>()).isNull() == true);
    QVERIFY(object1->toObject("key0", QMPointer<QMJsonObject>()).isNull() == false);
    QVERIFY(object1->to<QRect>("key0", QRect()) == QRect());

    QVERIFY(object1->from("key0", value0) == true);
    QVERIFY(object1->fromBool("key0", false) == false);
    QVERIFY(object1->fromDouble("key0", 15.16) == false);
    QVERIFY(object1->fromString("key0", "15.16") == false);
    QVERIFY(object1->fromArray("key0", QMPointer<QMJsonArray>()) == false);
    QVERIFY(object1->fromObject("key0", QMPointer<QMJsonObject>()) == true);
    QVERIFY(object1->from<QSize>("key0", QSize(15, 16)) == false);
}

void TestJson::QMJsonObject_custom(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue(QSize(4, 8)));
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());

    object1->insert("key0", value0);

    QVERIFY(object1->isNull("key0") == false);
    QVERIFY(object1->isBool("key0") == false);
    QVERIFY(object1->isDouble("key0") == false);
    QVERIFY(object1->isString("key0") == false);
    QVERIFY(object1->isArray("key0") == false);
    QVERIFY(object1->isObject("key0") == false);
    QVERIFY(object1->is<QSize>("key0") == true);

    QVERIFY(object1->toBool("key0") == false);
    QVERIFY(object1->toDouble("key0") == 0);
    QVERIFY(object1->toString("key0") == QString());
    QVERIFY(object1->toArray("key0").isNull() == false);
    QVERIFY(object1->toObject("key0").isNull() == false);

    QVERIFY(object1->toBool("key0", true) == true);
    QVERIFY(object1->toDouble("key0", 15.16) == 15.16);
    QVERIFY(object1->toString("key0", "15.16") == "15.16");
    QVERIFY(object1->toArray("key0", QMPointer<QMJsonArray>()).isNull() == true);
    QVERIFY(object1->toObject("key0", QMPointer<QMJsonObject>()).isNull() == true);
    QVERIFY(object1->to<QSize>("key0", QSize()) == QSize(4, 8));

    QVERIFY(object1->from("key0", value0) == false);
    QVERIFY(object1->fromBool("key0", false) == false);
    QVERIFY(object1->fromDouble("key0", 15.16) == false);
    QVERIFY(object1->fromString("key0", "15.16") == false);
    QVERIFY(object1->fromArray("key0", QMPointer<QMJsonArray>()) == false);
    QVERIFY(object1->fromObject("key0", QMPointer<QMJsonObject>()) == false);
    QVERIFY(object1->from<QSize>("key0", QSize(15, 16)) == true);
}

void TestJson::QMJsonObject_signals(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue("15.16"));
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto object2 = QMPointer<QMJsonObject>(new QMJsonObject());

    connect(object1.data(), &QMJsonObject::itemAdded, this, &TestJson::signaled);
    connect(object1.data(), &QMJsonObject::itemRemoved, this, &TestJson::signaled);
    connect(object2.data(), &QMJsonObject::itemAdded, this, &TestJson::signaled);
    connect(object2.data(), &QMJsonObject::itemRemoved, this, &TestJson::signaled);

    mCount = 0;
    object1->clear();
    QVERIFY(mCount == 0);

    mCount = 0;
    object1->remove("key0");
    QVERIFY(mCount == 0);

    mCount = 0;
    object1->take("key1");
    object1->take("key2", value0);
    object1->take("key3", 15.16);
    QVERIFY(mCount == 0);

    mCount = 0;
    object1->erase(object1->find("key4"));
    QVERIFY(mCount == 0);

    mCount = 0;
    object1->insert("key0", value0);
    object1->insert("key1", value0);
    object1->insert("key2", value0);
    QVERIFY(mCount == 3);

    mCount = 0;
    object2->insert("key2", value0);
    object2->insert("key3", value0);
    object2->insert("key4", value0);
    object2->insert("key5", value0);
    QVERIFY(mCount == 4);

    mCount = 0;
    object1->unite(object2);
    QVERIFY(mCount == 5);

    mCount = 0;
    object1->remove("key0");
    QVERIFY(mCount == 1);

    mCount = 0;
    object1->take("key1");
    object1->take("key2", value0);
    object1->take("key3", 15.16);
    QVERIFY(mCount == 3);

    mCount = 0;
    object1->erase(object1->find("key4"));
    QVERIFY(mCount == 1);

    mCount = 0;
    object1->clear();
    QVERIFY(mCount == 1);
}

