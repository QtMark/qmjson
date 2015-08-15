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

void TestJson::QMJsonObject_remove(void)
{
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(4));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue(8));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(15));

    object1->insert("key1", value1);
    object1->insert("key2", value2);
    object1->insert("key3", value3);

    object1->remove("");
    QVERIFY(object1->count() == 3);

    object1->remove("key4");
    QVERIFY(object1->count() == 3);

    object1->remove("key3");
    QVERIFY(object1->count() == 2);

    object1->remove("key2");
    QVERIFY(object1->count() == 1);

    object1->remove("key1");
    QVERIFY(object1->count() == 0);

    object1->remove("key1");
    QVERIFY(object1->count() == 0);
}
