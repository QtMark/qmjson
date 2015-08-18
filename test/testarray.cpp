#include <test.h>

void TestJson::QMJsonArray_create(void)
{
    auto list1 = QList<QMPointer<QMJsonValue> >();
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(4));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue(8));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(15));

    list1 << value1 << value2 << value3;
    array1->append(value1);
    array1->append(value2);
    array1->append(value3);

    auto array2 = QMPointer<QMJsonArray>(new QMJsonArray(list1));

    QVERIFY(array1->toDouble(0) == array2->toDouble(0));
    QVERIFY(array1->toDouble(1) == array2->toDouble(1));
    QVERIFY(array1->toDouble(2) == array2->toDouble(2));
}

void TestJson::QMJsonArray_prepend(void)
{
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto array2 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto rawValue1 = new QMJsonValue();
    auto rawArray1 = new QMJsonArray();
    auto rawObject1 = new QMJsonObject();

    array1->prepend(new QMJsonValue());
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isNull() == true);

    array1->prepend(QMPointer<QMJsonValue>());
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isNull() == true);

    array1->prepend(value1);
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isNull() == true);

    array1->prepend(rawValue1);
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isNull() == true);

    array1->prepend(new QMJsonArray());
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isArray() == true);

    array1->prepend(QMPointer<QMJsonArray>());
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isArray() == true);

    array1->prepend(array2);
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isArray() == true);

    array1->prepend(rawArray1);
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isArray() == true);

    array1->prepend(new QMJsonObject());
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isObject() == true);

    array1->prepend(QMPointer<QMJsonObject>());
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isObject() == true);

    array1->prepend(object1);
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isObject() == true);

    array1->prepend(rawObject1);
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isObject() == true);

    array1->prepend(QMPointer<QMJsonValue>());
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isNull() == true);

    array1->prepend(4.8);
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isDouble() == true);

    array1->prepend("Hello World");
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isString() == true);

    array1->prepend(QString("Hello World"));
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isString() == true);

    array1->prepend(new QMJsonValue(4.8));
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isDouble() == true);

    array1->prepend(new QMJsonValue("Hello World"));
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isString() == true);

    array1->prepend(new QMJsonValue(QString("Hello World")));
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isString() == true);

    array1->prepend(QMPointer<QMJsonValue>(new QMJsonValue(4.8)));
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isDouble() == true);

    array1->prepend(QMPointer<QMJsonValue>(new QMJsonValue("Hello World")));
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isString() == true);

    array1->prepend(QMPointer<QMJsonValue>(new QMJsonValue(QString("Hello World"))));
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isString() == true);
}

void TestJson::QMJsonArray_append(void)
{
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto array2 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto rawValue1 = new QMJsonValue();
    auto rawArray1 = new QMJsonArray();
    auto rawObject1 = new QMJsonObject();

    array1->append(new QMJsonValue());
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isNull() == true);

    array1->append(QMPointer<QMJsonValue>());
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isNull() == true);

    array1->append(value1);
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isNull() == true);

    array1->append(rawValue1);
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isNull() == true);

    array1->append(new QMJsonArray());
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isArray() == true);

    array1->append(QMPointer<QMJsonArray>());
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isArray() == true);

    array1->append(array2);
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isArray() == true);

    array1->append(rawArray1);
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isArray() == true);

    array1->append(new QMJsonObject());
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isObject() == true);

    array1->append(QMPointer<QMJsonObject>());
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isObject() == true);

    array1->append(object1);
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isObject() == true);

    array1->append(rawObject1);
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isObject() == true);

    array1->append(QMPointer<QMJsonValue>());
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isNull() == true);

    array1->append(4.8);
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isDouble() == true);

    array1->append("Hello World");
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isString() == true);

    array1->append(QString("Hello World"));
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isString() == true);

    array1->append(new QMJsonValue(4.8));
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isDouble() == true);

    array1->append(new QMJsonValue("Hello World"));
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isString() == true);

    array1->append(new QMJsonValue(QString("Hello World")));
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isString() == true);

    array1->append(QMPointer<QMJsonValue>(new QMJsonValue(4.8)));
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isDouble() == true);

    array1->append(QMPointer<QMJsonValue>(new QMJsonValue("Hello World")));
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isString() == true);

    array1->append(QMPointer<QMJsonValue>(new QMJsonValue(QString("Hello World"))));
    QVERIFY(array1->last().isNull() == false);
    QVERIFY(array1->last()->isString() == true);
}

void TestJson::QMJsonArray_insert(void)
{
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto array2 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto rawValue1 = new QMJsonValue();
    auto rawArray1 = new QMJsonArray();
    auto rawObject1 = new QMJsonObject();

    array1->insert(0, new QMJsonValue());
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isNull() == true);

    array1->insert(0, QMPointer<QMJsonValue>());
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isNull() == true);

    array1->insert(0, value1);
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isNull() == true);

    array1->insert(0, rawValue1);
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isNull() == true);

    array1->insert(0, new QMJsonArray());
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isArray() == true);

    array1->insert(0, QMPointer<QMJsonArray>());
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isArray() == true);

    array1->insert(0, array2);
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isArray() == true);

    array1->insert(0, rawArray1);
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isArray() == true);

    array1->insert(0, new QMJsonObject());
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isObject() == true);

    array1->insert(0, QMPointer<QMJsonObject>());
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isObject() == true);

    array1->insert(0, object1);
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isObject() == true);

    array1->insert(0, rawObject1);
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isObject() == true);

    array1->insert(0, QMPointer<QMJsonValue>());
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isNull() == true);

    array1->insert(0, 4.8);
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isDouble() == true);

    array1->insert(0, "Hello World");
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isString() == true);

    array1->insert(0, QString("Hello World"));
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isString() == true);

    array1->insert(0, new QMJsonValue(4.8));
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isDouble() == true);

    array1->insert(0, new QMJsonValue("Hello World"));
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isString() == true);

    array1->insert(0, new QMJsonValue(QString("Hello World")));
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isString() == true);

    array1->insert(0, QMPointer<QMJsonValue>(new QMJsonValue(4.8)));
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isDouble() == true);

    array1->insert(0, QMPointer<QMJsonValue>(new QMJsonValue("Hello World")));
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isString() == true);

    array1->insert(0, QMPointer<QMJsonValue>(new QMJsonValue(QString("Hello World"))));
    QVERIFY(array1->first().isNull() == false);
    QVERIFY(array1->first()->isString() == true);
}

void TestJson::QMJsonArray_indexOf(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto value4 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonArray()));
    auto value5 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonObject()));
    auto value6 = QMPointer<QMJsonValue>(new QMJsonValue(15.16));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());

    array1->append(value0);
    array1->append(value1);
    array1->append(value2);
    array1->append(value3);
    array1->append(value4);
    array1->append(value5);
    array1->append(value5);
    array1->append(value5);

    QVERIFY(array1->indexOf(value0) == 0);
    QVERIFY(array1->indexOf(value1) == 1);
    QVERIFY(array1->indexOf(value2) == 2);
    QVERIFY(array1->indexOf(value3) == 3);
    QVERIFY(array1->indexOf(value4) == 4);
    QVERIFY(array1->indexOf(value5) == 5);
    QVERIFY(array1->indexOf(value6) == -1);
}

void TestJson::QMJsonArray_lastIndexOf(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto value4 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonArray()));
    auto value5 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonObject()));
    auto value6 = QMPointer<QMJsonValue>(new QMJsonValue(15.16));
    auto value7 = QMPointer<QMJsonValue>(new QMJsonValue(QRect()));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());

    array1->append(value0);
    array1->append(value1);
    array1->append(value2);
    array1->append(value3);
    array1->append(value4);
    array1->append(value5);
    array1->append(value5);
    array1->append(value5);

    QVERIFY(array1->lastIndexOf(value0) == 0);
    QVERIFY(array1->lastIndexOf(value1) == 1);
    QVERIFY(array1->lastIndexOf(value2) == 2);
    QVERIFY(array1->lastIndexOf(value3) == 3);
    QVERIFY(array1->lastIndexOf(value4) == 4);
    QVERIFY(array1->lastIndexOf(value5) == 7);
    QVERIFY(array1->lastIndexOf(value6) == -1);
    QVERIFY(array1->lastIndexOf(value0, -1) == 0);
    QVERIFY(array1->lastIndexOf(value1, -1) == 1);
    QVERIFY(array1->lastIndexOf(value2, -1) == 2);
    QVERIFY(array1->lastIndexOf(value3, -1) == 3);
    QVERIFY(array1->lastIndexOf(value4, -1) == 4);
    QVERIFY(array1->lastIndexOf(value5, -1) == 7);
    QVERIFY(array1->lastIndexOf(value6, -1) == -1);
    QVERIFY(array1->lastIndexOf(value5, 7) == 7);
    QVERIFY(array1->lastIndexOf(value5, 6) == 6);
    QVERIFY(array1->lastIndexOf(value5, 5) == 5);
    QVERIFY(array1->lastIndexOf(value5, 4) == -1);

    QVERIFY(array1->lastIndexOf(value1, -2) == 1);
    QVERIFY(array1->lastIndexOf(value1, 100) == 1);
}

void TestJson::QMJsonArray_contains(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto value4 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonArray()));
    auto value5 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonObject()));
    auto value6 = QMPointer<QMJsonValue>(new QMJsonValue(15.16));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());

    array1->append(value0);
    array1->append(value1);
    array1->append(value2);
    array1->append(value3);
    array1->append(value4);
    array1->append(value5);
    array1->append(value5);
    array1->append(value5);

    QVERIFY(array1->contains(value0) == true);
    QVERIFY(array1->contains(value1) == true);
    QVERIFY(array1->contains(value2) == true);
    QVERIFY(array1->contains(value3) == true);
    QVERIFY(array1->contains(value4) == true);
    QVERIFY(array1->contains(value5) == true);
    QVERIFY(array1->contains(value6) == false);
}

void TestJson::QMJsonArray_removeAll(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto value4 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonArray()));
    auto value5 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonObject()));
    auto value6 = QMPointer<QMJsonValue>(new QMJsonValue(15.16));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());

    array1->append(value0);
    array1->append(value1);
    array1->append(value2);
    array1->append(value3);
    array1->append(value4);
    array1->append(value5);
    array1->append(value5);
    array1->append(value5);

    QVERIFY(array1->count() == 8);

    array1->removeAll(value6);
    QVERIFY(array1->count() == 8);
    QVERIFY(array1->contains(value6) == false);

    array1->removeAll(value0);
    QVERIFY(array1->count() == 7);
    QVERIFY(array1->contains(value0) == false);

    array1->removeAll(value1);
    QVERIFY(array1->count() == 6);
    QVERIFY(array1->contains(value1) == false);

    array1->removeAll(value2);
    QVERIFY(array1->count() == 5);
    QVERIFY(array1->contains(value2) == false);

    array1->removeAll(value3);
    QVERIFY(array1->count() == 4);
    QVERIFY(array1->contains(value3) == false);

    array1->removeAll(value4);
    QVERIFY(array1->count() == 3);
    QVERIFY(array1->contains(value4) == false);

    array1->removeAll(value5);
    QVERIFY(array1->count() == 0);
    QVERIFY(array1->contains(value5) == false);
}

void TestJson::QMJsonArray_unite(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto array2 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto array3 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto array4 = QMPointer<QMJsonArray>(new QMJsonArray());

    array1->append(value0);
    array1->append(value1);
    array2->append(value2);
    array2->append(value3);

    array3->unite(array1, QMJsonArrayUnitePolicy_Prepend);
    array3->unite(array2, QMJsonArrayUnitePolicy_Prepend);

    array4->unite(array1, QMJsonArrayUnitePolicy_Append);
    array4->unite(array2, QMJsonArrayUnitePolicy_Append);

    QVERIFY(array3->value(0)->isDouble() == true);
    QVERIFY(array3->value(1)->isString() == true);
    QVERIFY(array3->value(2)->isBool() == true);
    QVERIFY(array3->value(3)->isNull() == true);

    QVERIFY(array4->value(0)->isNull() == true);
    QVERIFY(array4->value(1)->isBool() == true);
    QVERIFY(array4->value(2)->isString() == true);
    QVERIFY(array4->value(3)->isDouble() == true);
}
