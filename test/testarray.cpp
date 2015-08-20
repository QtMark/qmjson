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
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isNull() == true);

    array1->prepend(QMPointer<QMJsonValue>());
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isNull() == true);

    array1->prepend(value1);
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isNull() == true);

    array1->prepend(rawValue1);
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isNull() == true);

    array1->prepend(new QMJsonArray());
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isArray() == true);

    array1->prepend(QMPointer<QMJsonArray>());
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isArray() == true);

    array1->prepend(array2);
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isArray() == true);

    array1->prepend(rawArray1);
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isArray() == true);

    array1->prepend(new QMJsonObject());
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isObject() == true);

    array1->prepend(QMPointer<QMJsonObject>());
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isObject() == true);

    array1->prepend(object1);
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isObject() == true);

    array1->prepend(rawObject1);
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isObject() == true);

    array1->prepend(QMPointer<QMJsonValue>());
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isNull() == true);

    array1->prepend(4.8);
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isDouble() == true);

    array1->prepend("Hello World");
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isString() == true);

    array1->prepend(QString("Hello World"));
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isString() == true);

    array1->prepend(new QMJsonValue(4.8));
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isDouble() == true);

    array1->prepend(new QMJsonValue("Hello World"));
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isString() == true);

    array1->prepend(new QMJsonValue(QString("Hello World")));
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isString() == true);

    array1->prepend(QMPointer<QMJsonValue>(new QMJsonValue(4.8)));
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isDouble() == true);

    array1->prepend(QMPointer<QMJsonValue>(new QMJsonValue("Hello World")));
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isString() == true);

    array1->prepend(QMPointer<QMJsonValue>(new QMJsonValue(QString("Hello World"))));
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isString() == true);
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
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isNull() == true);

    array1->append(QMPointer<QMJsonValue>());
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isNull() == true);

    array1->append(value1);
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isNull() == true);

    array1->append(rawValue1);
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isNull() == true);

    array1->append(new QMJsonArray());
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isArray() == true);

    array1->append(QMPointer<QMJsonArray>());
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isArray() == true);

    array1->append(array2);
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isArray() == true);

    array1->append(rawArray1);
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isArray() == true);

    array1->append(new QMJsonObject());
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isObject() == true);

    array1->append(QMPointer<QMJsonObject>());
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isObject() == true);

    array1->append(object1);
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isObject() == true);

    array1->append(rawObject1);
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isObject() == true);

    array1->append(QMPointer<QMJsonValue>());
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isNull() == true);

    array1->append(4.8);
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isDouble() == true);

    array1->append("Hello World");
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isString() == true);

    array1->append(QString("Hello World"));
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isString() == true);

    array1->append(new QMJsonValue(4.8));
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isDouble() == true);

    array1->append(new QMJsonValue("Hello World"));
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isString() == true);

    array1->append(new QMJsonValue(QString("Hello World")));
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isString() == true);

    array1->append(QMPointer<QMJsonValue>(new QMJsonValue(4.8)));
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isDouble() == true);

    array1->append(QMPointer<QMJsonValue>(new QMJsonValue("Hello World")));
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isString() == true);

    array1->append(QMPointer<QMJsonValue>(new QMJsonValue(QString("Hello World"))));
    QVERIFY(array1->back().isNull() == false);
    QVERIFY(array1->back()->isString() == true);
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
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isNull() == true);

    array1->insert(0, QMPointer<QMJsonValue>());
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isNull() == true);

    array1->insert(0, value1);
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isNull() == true);

    array1->insert(0, rawValue1);
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isNull() == true);

    array1->insert(0, new QMJsonArray());
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isArray() == true);

    array1->insert(0, QMPointer<QMJsonArray>());
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isArray() == true);

    array1->insert(0, array2);
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isArray() == true);

    array1->insert(0, rawArray1);
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isArray() == true);

    array1->insert(0, new QMJsonObject());
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isObject() == true);

    array1->insert(0, QMPointer<QMJsonObject>());
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isObject() == true);

    array1->insert(0, object1);
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isObject() == true);

    array1->insert(0, rawObject1);
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isObject() == true);

    array1->insert(0, QMPointer<QMJsonValue>());
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isNull() == true);

    array1->insert(0, 4.8);
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isDouble() == true);

    array1->insert(0, "Hello World");
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isString() == true);

    array1->insert(0, QString("Hello World"));
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isString() == true);

    array1->insert(0, new QMJsonValue(4.8));
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isDouble() == true);

    array1->insert(0, new QMJsonValue("Hello World"));
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isString() == true);

    array1->insert(0, new QMJsonValue(QString("Hello World")));
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isString() == true);

    array1->insert(0, QMPointer<QMJsonValue>(new QMJsonValue(4.8)));
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isDouble() == true);

    array1->insert(0, QMPointer<QMJsonValue>(new QMJsonValue("Hello World")));
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isString() == true);

    array1->insert(0, QMPointer<QMJsonValue>(new QMJsonValue(QString("Hello World"))));
    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->front()->isString() == true);
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

void TestJson::QMJsonArray_count(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());

    QVERIFY(array1->count() == 0);
    QVERIFY(array1->length() == 0);
    QVERIFY(array1->size() == 0);

    array1->append(value0);
    QVERIFY(array1->count() == 1);
    QVERIFY(array1->length() == 1);
    QVERIFY(array1->size() == 1);

    array1->append(value1);
    QVERIFY(array1->count() == 2);
    QVERIFY(array1->length() == 2);
    QVERIFY(array1->size() == 2);

    array1->append(value2);
    QVERIFY(array1->count() == 3);
    QVERIFY(array1->length() == 3);
    QVERIFY(array1->size() == 3);

    array1->append(value3);
    QVERIFY(array1->count() == 4);
    QVERIFY(array1->length() == 4);
    QVERIFY(array1->size() == 4);

    array1->clear();
    QVERIFY(array1->count() == 0);
    QVERIFY(array1->length() == 0);
    QVERIFY(array1->size() == 0);
}

void TestJson::QMJsonArray_clear(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto array2 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto object1 = QMPointer<QMJsonObject>(new QMJsonObject());
    auto document1 = QMPointer<QMJsonValue>(new QMJsonValue(array1));
    auto document2 = QMPointer<QMJsonValue>(new QMJsonValue(array2));
    auto document3 = QMPointer<QMJsonValue>(new QMJsonValue(object1));

    array1->append(value0);
    array1->append(value1);
    object1->insert("key2", value2);
    object1->insert("key3", value3);
    array2->append(array1);
    array2->append(object1);

    array2->clear();

    QVERIFY(document1->toJson() == "[]");
    QVERIFY(document2->toJson() == "[]");
    QVERIFY(document3->toJson() == "{}");
}

void TestJson::QMJsonArray_empty(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());

    QVERIFY(array1->isEmpty() == true);
    QVERIFY(array1->empty() == true);

    array1->append(value0);
    array1->append(value1);
    array1->append(value2);
    array1->append(value3);

    QVERIFY(array1->isEmpty() == false);
    QVERIFY(array1->empty() == false);

    array1->clear();

    QVERIFY(array1->isEmpty() == true);
    QVERIFY(array1->empty() == true);
}

void TestJson::QMJsonArray_with(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());

    QVERIFY(array1->startsWith(value0) == false);
    QVERIFY(array1->endsWith(value3) == false);

    array1->append(value0);
    array1->append(value1);
    array1->append(value2);
    array1->append(value3);

    QVERIFY(array1->startsWith(value0) == true);
    QVERIFY(array1->endsWith(value3) == true);

    array1->clear();

    QVERIFY(array1->startsWith(value0) == false);
    QVERIFY(array1->endsWith(value3) == false);
}

void TestJson::QMJsonArray_remove(void)
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

    array1->removeAll(QMPointer<QMJsonValue>());
    QVERIFY(array1->count() == 0);

    array1->append(value0);
    array1->append(value1);
    array1->append(value2);
    array1->append(value3);
    array1->append(value4);
    array1->append(value5);
    array1->append(value5);
    array1->append(value5);

    array1->removeOne(value6);
    QVERIFY(array1->count() == 8);
    QVERIFY(array1->contains(value6) == false);

    array1->removeOne(value0);
    QVERIFY(array1->count() == 7);
    QVERIFY(array1->contains(value0) == false);

    array1->removeOne(value1);
    QVERIFY(array1->count() == 6);
    QVERIFY(array1->contains(value1) == false);

    array1->removeOne(value2);
    QVERIFY(array1->count() == 5);
    QVERIFY(array1->contains(value2) == false);

    array1->removeOne(value3);
    QVERIFY(array1->count() == 4);
    QVERIFY(array1->contains(value3) == false);

    array1->removeOne(value4);
    QVERIFY(array1->count() == 3);
    QVERIFY(array1->contains(value4) == false);

    array1->removeOne(value5);
    QVERIFY(array1->count() == 2);
    QVERIFY(array1->contains(value5) == true);

    array1->removeOne(value5);
    QVERIFY(array1->count() == 1);
    QVERIFY(array1->contains(value5) == true);

    array1->removeOne(value5);
    QVERIFY(array1->count() == 0);
    QVERIFY(array1->contains(value5) == false);

    array1->removeOne(QMPointer<QMJsonValue>());
    QVERIFY(array1->count() == 0);

    array1->append(value0);
    array1->append(value1);
    array1->append(value2);
    array1->append(value3);
    array1->append(value4);
    array1->append(value5);
    array1->append(value5);
    array1->append(value5);

    array1->removeAt(1);
    QVERIFY(array1->count() == 7);
    QVERIFY(array1->contains(value1) == false);

    array1->removeAt(1);
    QVERIFY(array1->count() == 6);
    QVERIFY(array1->contains(value2) == false);

    array1->removeAt(1);
    QVERIFY(array1->count() == 5);
    QVERIFY(array1->contains(value3) == false);

    array1->removeAt(1);
    QVERIFY(array1->count() == 4);
    QVERIFY(array1->contains(value4) == false);

    array1->removeAt(1);
    QVERIFY(array1->count() == 3);
    QVERIFY(array1->contains(value5) == true);

    array1->removeAt(1);
    QVERIFY(array1->count() == 2);
    QVERIFY(array1->contains(value5) == true);

    array1->removeAt(1);
    QVERIFY(array1->count() == 1);
    QVERIFY(array1->contains(value5) == false);

    array1->removeAt(0);
    QVERIFY(array1->count() == 0);
    QVERIFY(array1->contains(value0) == false);

    array1->removeAt(-1);
    array1->removeAt(0);
    array1->removeAt(100);
    QVERIFY(array1->count() == 0);

    array1->append(value0);
    array1->append(value1);
    array1->append(value2);
    array1->append(value3);
    array1->append(value4);
    array1->append(value5);
    array1->append(value5);
    array1->append(value5);

    array1->removeFirst();
    QVERIFY(array1->count() == 7);
    QVERIFY(array1->contains(value0) == false);

    array1->removeFirst();
    QVERIFY(array1->count() == 6);
    QVERIFY(array1->contains(value1) == false);

    array1->removeFirst();
    QVERIFY(array1->count() == 5);
    QVERIFY(array1->contains(value2) == false);

    array1->removeFirst();
    QVERIFY(array1->count() == 4);
    QVERIFY(array1->contains(value3) == false);

    array1->removeFirst();
    QVERIFY(array1->count() == 3);
    QVERIFY(array1->contains(value4) == false);

    array1->removeFirst();
    QVERIFY(array1->count() == 2);
    QVERIFY(array1->contains(value5) == true);

    array1->removeFirst();
    QVERIFY(array1->count() == 1);
    QVERIFY(array1->contains(value5) == true);

    array1->removeFirst();
    QVERIFY(array1->count() == 0);
    QVERIFY(array1->contains(value5) == false);

    array1->removeFirst();
    QVERIFY(array1->count() == 0);

    array1->append(value0);
    array1->append(value1);
    array1->append(value2);
    array1->append(value3);
    array1->append(value4);
    array1->append(value5);
    array1->append(value5);
    array1->append(value5);

    array1->removeLast();
    QVERIFY(array1->count() == 7);
    QVERIFY(array1->contains(value5) == true);

    array1->removeLast();
    QVERIFY(array1->count() == 6);
    QVERIFY(array1->contains(value5) == true);

    array1->removeLast();
    QVERIFY(array1->count() == 5);
    QVERIFY(array1->contains(value5) == false);

    array1->removeLast();
    QVERIFY(array1->count() == 4);
    QVERIFY(array1->contains(value4) == false);

    array1->removeLast();
    QVERIFY(array1->count() == 3);
    QVERIFY(array1->contains(value3) == false);

    array1->removeLast();
    QVERIFY(array1->count() == 2);
    QVERIFY(array1->contains(value2) == false);

    array1->removeLast();
    QVERIFY(array1->count() == 1);
    QVERIFY(array1->contains(value1) == false);

    array1->removeLast();
    QVERIFY(array1->count() == 0);
    QVERIFY(array1->contains(value0) == false);

    array1->removeLast();
    QVERIFY(array1->count() == 0);
}

void TestJson::QMJsonArray_take(void)
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

    QVERIFY(array1->takeAt(1) == value1);
    QVERIFY(array1->count() == 7);
    QVERIFY(array1->contains(value1) == false);

    QVERIFY(array1->takeAt(1) == value2);
    QVERIFY(array1->count() == 6);
    QVERIFY(array1->contains(value2) == false);

    QVERIFY(array1->takeAt(1) == value3);
    QVERIFY(array1->count() == 5);
    QVERIFY(array1->contains(value3) == false);

    QVERIFY(array1->takeAt(1) == value4);
    QVERIFY(array1->count() == 4);
    QVERIFY(array1->contains(value4) == false);

    QVERIFY(array1->takeAt(1) == value5);
    QVERIFY(array1->count() == 3);
    QVERIFY(array1->contains(value5) == true);

    QVERIFY(array1->takeAt(1) == value5);
    QVERIFY(array1->count() == 2);
    QVERIFY(array1->contains(value5) == true);

    QVERIFY(array1->takeAt(1) == value5);
    QVERIFY(array1->count() == 1);
    QVERIFY(array1->contains(value5) == false);

    QVERIFY(array1->takeAt(0) == value0);
    QVERIFY(array1->count() == 0);
    QVERIFY(array1->contains(value0) == false);

    QVERIFY(array1->takeAt(-1).isNull() == false);
    QVERIFY(array1->takeAt(0).isNull() == false);
    QVERIFY(array1->takeAt(100).isNull() == false);
    QVERIFY(array1->count() == 0);

    array1->append(value0);
    array1->append(value1);
    array1->append(value2);
    array1->append(value3);
    array1->append(value4);
    array1->append(value5);
    array1->append(value5);
    array1->append(value5);

    QVERIFY(array1->takeAt(1, value0) == value1);
    QVERIFY(array1->count() == 7);
    QVERIFY(array1->contains(value1) == false);

    QVERIFY(array1->takeAt(1, value0) == value2);
    QVERIFY(array1->count() == 6);
    QVERIFY(array1->contains(value2) == false);

    QVERIFY(array1->takeAt(1, value0) == value3);
    QVERIFY(array1->count() == 5);
    QVERIFY(array1->contains(value3) == false);

    QVERIFY(array1->takeAt(1, value0) == value4);
    QVERIFY(array1->count() == 4);
    QVERIFY(array1->contains(value4) == false);

    QVERIFY(array1->takeAt(1, value0) == value5);
    QVERIFY(array1->count() == 3);
    QVERIFY(array1->contains(value5) == true);

    QVERIFY(array1->takeAt(1, value0) == value5);
    QVERIFY(array1->count() == 2);
    QVERIFY(array1->contains(value5) == true);

    QVERIFY(array1->takeAt(1, value0) == value5);
    QVERIFY(array1->count() == 1);
    QVERIFY(array1->contains(value5) == false);

    QVERIFY(array1->takeAt(0, value1) == value0);
    QVERIFY(array1->count() == 0);
    QVERIFY(array1->contains(value0) == false);

    QVERIFY(array1->takeAt(-1, value0) == value0);
    QVERIFY(array1->takeAt(0, value0) == value0);
    QVERIFY(array1->takeAt(100, value0) == value0);
    QVERIFY(array1->count() == 0);

    array1->append(value0);
    array1->append(value1);
    array1->append(value2);
    array1->append(value3);
    array1->append(value4);
    array1->append(value5);
    array1->append(value5);
    array1->append(value5);

    QVERIFY(array1->takeAt(1, false) == value1);
    QVERIFY(array1->count() == 7);
    QVERIFY(array1->contains(value1) == false);

    QVERIFY(array1->takeAt(1, "World Hello") == value2);
    QVERIFY(array1->count() == 6);
    QVERIFY(array1->contains(value2) == false);

    QVERIFY(array1->takeAt(1, 15.16) == value3);
    QVERIFY(array1->count() == 5);
    QVERIFY(array1->contains(value3) == false);

    QVERIFY(array1->takeAt(1, QMPointer<QMJsonArray>()) == value4);
    QVERIFY(array1->count() == 4);
    QVERIFY(array1->contains(value4) == false);

    QVERIFY(array1->takeAt(1, QMPointer<QMJsonObject>()) == value5);
    QVERIFY(array1->count() == 3);
    QVERIFY(array1->contains(value5) == true);

    QVERIFY(array1->takeAt(1, QMPointer<QMJsonObject>()) == value5);
    QVERIFY(array1->count() == 2);
    QVERIFY(array1->contains(value5) == true);

    QVERIFY(array1->takeAt(1, QMPointer<QMJsonObject>()) == value5);
    QVERIFY(array1->count() == 1);
    QVERIFY(array1->contains(value5) == false);

    QVERIFY(array1->takeAt(0, QMPointer<QMJsonValue>()) == value0);
    QVERIFY(array1->count() == 0);
    QVERIFY(array1->contains(value0) == false);

    QVERIFY(array1->takeAt(-1, QMPointer<QMJsonValue>()).isNull() == true);
    QVERIFY(array1->takeAt(0, QMPointer<QMJsonValue>()).isNull() == true);
    QVERIFY(array1->takeAt(100, QMPointer<QMJsonValue>()).isNull() == true);
    QVERIFY(array1->count() == 0);

    array1->append(value0);
    array1->append(value1);
    array1->append(value2);
    array1->append(value3);
    array1->append(value4);
    array1->append(value5);
    array1->append(value5);
    array1->append(value5);

    QVERIFY(array1->takeFirst() == value0);
    QVERIFY(array1->count() == 7);
    QVERIFY(array1->contains(value0) == false);

    QVERIFY(array1->takeFirst() == value1);
    QVERIFY(array1->count() == 6);
    QVERIFY(array1->contains(value1) == false);

    QVERIFY(array1->takeFirst() == value2);
    QVERIFY(array1->count() == 5);
    QVERIFY(array1->contains(value2) == false);

    QVERIFY(array1->takeFirst() == value3);
    QVERIFY(array1->count() == 4);
    QVERIFY(array1->contains(value3) == false);

    QVERIFY(array1->takeFirst() == value4);
    QVERIFY(array1->count() == 3);
    QVERIFY(array1->contains(value4) == false);

    QVERIFY(array1->takeFirst() == value5);
    QVERIFY(array1->count() == 2);
    QVERIFY(array1->contains(value5) == true);

    QVERIFY(array1->takeFirst() == value5);
    QVERIFY(array1->count() == 1);
    QVERIFY(array1->contains(value5) == true);

    QVERIFY(array1->takeFirst() == value5);
    QVERIFY(array1->count() == 0);
    QVERIFY(array1->contains(value5) == false);

    array1->takeFirst();
    QVERIFY(array1->count() == 0);

    array1->append(value0);
    array1->append(value1);
    array1->append(value2);
    array1->append(value3);
    array1->append(value4);
    array1->append(value5);
    array1->append(value5);
    array1->append(value5);

    QVERIFY(array1->takeLast() == value5);
    QVERIFY(array1->count() == 7);
    QVERIFY(array1->contains(value5) == true);

    QVERIFY(array1->takeLast() == value5);
    QVERIFY(array1->count() == 6);
    QVERIFY(array1->contains(value5) == true);

    QVERIFY(array1->takeLast() == value5);
    QVERIFY(array1->count() == 5);
    QVERIFY(array1->contains(value5) == false);

    QVERIFY(array1->takeLast() == value4);
    QVERIFY(array1->count() == 4);
    QVERIFY(array1->contains(value4) == false);

    QVERIFY(array1->takeLast() == value3);
    QVERIFY(array1->count() == 3);
    QVERIFY(array1->contains(value3) == false);

    QVERIFY(array1->takeLast() == value2);
    QVERIFY(array1->count() == 2);
    QVERIFY(array1->contains(value2) == false);

    QVERIFY(array1->takeLast() == value1);
    QVERIFY(array1->count() == 1);
    QVERIFY(array1->contains(value1) == false);

    QVERIFY(array1->takeLast() == value0);
    QVERIFY(array1->count() == 0);
    QVERIFY(array1->contains(value0) == false);

    array1->takeLast();
    QVERIFY(array1->count() == 0);
}

void TestJson::QMJsonArray_value(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());

    QVERIFY(array1->front().isNull() == false);
    QVERIFY(array1->back().isNull() == false);

    array1->append(value0);
    array1->append(value1);
    array1->append(value2);
    array1->append(value3);

    QVERIFY(array1->front() == value0);
    QVERIFY(array1->back() == value3);

    QVERIFY(array1->value(-1).isNull() == false);
    QVERIFY(array1->value(100).isNull() == false);
    QVERIFY(array1->value(0) == value0);
    QVERIFY(array1->value(1) == value1);
    QVERIFY(array1->value(2) == value2);
    QVERIFY(array1->value(3) == value3);

    QVERIFY(array1->value(-1, value1) == value1);
    QVERIFY(array1->value(100, value1) == value1);
    QVERIFY(array1->value(0, value1) == value0);
    QVERIFY(array1->value(1, value0) == value1);
    QVERIFY(array1->value(2, value1) == value2);
    QVERIFY(array1->value(3, value1) == value3);

    QVERIFY(array1->value(-1, 15.16).isNull() == false);
    QVERIFY(array1->value(100, 15.16).isNull() == false);
    QVERIFY(array1->value(0, 15.16) == value0);
    QVERIFY(array1->value(1, 15.16) == value1);
    QVERIFY(array1->value(2, 15.16) == value2);
    QVERIFY(array1->value(3, 15.16) == value3);
}

void TestJson::QMJsonArray_values(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());

    QVERIFY(array1->values() == QList<QMPointer<QMJsonValue> >());

    array1->append(value0);
    array1->append(value1);
    array1->append(value2);
    array1->append(value3);

    QVERIFY(array1->values() == QList<QMPointer<QMJsonValue> >() << value0 << value1 << value2 << value3);
    QVERIFY(array1->mid(-1, 100) == QList<QMPointer<QMJsonValue> >() << value0 << value1 << value2 << value3);
    QVERIFY(array1->mid(-1, 4) == QList<QMPointer<QMJsonValue> >() << value0 << value1 << value2 << value3);

    QVERIFY(array1->mid(0, 4) == QList<QMPointer<QMJsonValue> >() << value0 << value1 << value2 << value3);
    QVERIFY(array1->mid(0, 3) == QList<QMPointer<QMJsonValue> >() << value0 << value1 << value2);
    QVERIFY(array1->mid(0, 2) == QList<QMPointer<QMJsonValue> >() << value0 << value1);
    QVERIFY(array1->mid(0, 1) == QList<QMPointer<QMJsonValue> >() << value0);
    QVERIFY(array1->mid(0, 0) == QList<QMPointer<QMJsonValue> >());

    QVERIFY(array1->mid(1, 4) == QList<QMPointer<QMJsonValue> >() << value1 << value2 << value3);
    QVERIFY(array1->mid(1, 3) == QList<QMPointer<QMJsonValue> >() << value1 << value2 << value3);
    QVERIFY(array1->mid(1, 2) == QList<QMPointer<QMJsonValue> >() << value1 << value2);
    QVERIFY(array1->mid(1, 1) == QList<QMPointer<QMJsonValue> >() << value1);
    QVERIFY(array1->mid(1, 0) == QList<QMPointer<QMJsonValue> >());

    QVERIFY(array1->mid(2, 4) == QList<QMPointer<QMJsonValue> >() << value2 << value3);
    QVERIFY(array1->mid(2, 3) == QList<QMPointer<QMJsonValue> >() << value2 << value3);
    QVERIFY(array1->mid(2, 2) == QList<QMPointer<QMJsonValue> >() << value2 << value3);
    QVERIFY(array1->mid(2, 1) == QList<QMPointer<QMJsonValue> >() << value2);
    QVERIFY(array1->mid(2, 0) == QList<QMPointer<QMJsonValue> >());

    QVERIFY(array1->mid(3, 4) == QList<QMPointer<QMJsonValue> >() << value3);
    QVERIFY(array1->mid(3, 3) == QList<QMPointer<QMJsonValue> >() << value3);
    QVERIFY(array1->mid(3, 2) == QList<QMPointer<QMJsonValue> >() << value3);
    QVERIFY(array1->mid(3, 1) == QList<QMPointer<QMJsonValue> >() << value3);
    QVERIFY(array1->mid(3, 0) == QList<QMPointer<QMJsonValue> >());

    QVERIFY(array1->mid(4, 4) == QList<QMPointer<QMJsonValue> >());
    QVERIFY(array1->mid(4, 3) == QList<QMPointer<QMJsonValue> >());
    QVERIFY(array1->mid(4, 2) == QList<QMPointer<QMJsonValue> >());
    QVERIFY(array1->mid(4, 1) == QList<QMPointer<QMJsonValue> >());
    QVERIFY(array1->mid(4, 0) == QList<QMPointer<QMJsonValue> >());
}

void TestJson::QMJsonArray_move(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());

    array1->move(-1, 100);
    array1->move(0, 0);
    array1->move(4, 2);

    array1->append(value0);
    array1->append(value1);
    array1->append(value2);
    array1->append(value3);

    array1->move(-1, -1);
    array1->move(-1, 0);
    array1->move(-1, 1);
    array1->move(-1, 2);
    array1->move(-1, 3);
    array1->move(-1, 4);

    array1->move(0, -1);
    array1->move(0, 0);
    array1->move(0, 1);
    array1->move(0, 2);
    array1->move(0, 3);
    array1->move(0, 4);
    QVERIFY(array1->value(0) == value2);
    QVERIFY(array1->value(1) == value1);
    QVERIFY(array1->value(2) == value3);
    QVERIFY(array1->value(3) == value0);

    array1->move(1, -1);
    array1->move(1, 0);
    array1->move(1, 1);
    array1->move(1, 2);
    array1->move(1, 3);
    array1->move(1, 4);
    QVERIFY(array1->value(0) == value1);
    QVERIFY(array1->value(1) == value2);
    QVERIFY(array1->value(2) == value0);
    QVERIFY(array1->value(3) == value3);

    array1->move(2, -1);
    array1->move(2, 0);
    array1->move(2, 1);
    array1->move(2, 2);
    array1->move(2, 3);
    array1->move(2, 4);
    QVERIFY(array1->value(0) == value0);
    QVERIFY(array1->value(1) == value2);
    QVERIFY(array1->value(2) == value3);
    QVERIFY(array1->value(3) == value1);

    array1->move(3, -1);
    array1->move(3, 0);
    array1->move(3, 1);
    array1->move(3, 2);
    array1->move(3, 3);
    array1->move(3, 4);
    QVERIFY(array1->value(0) == value1);
    QVERIFY(array1->value(1) == value3);
    QVERIFY(array1->value(2) == value2);
    QVERIFY(array1->value(3) == value0);

    array1->move(4, -1);
    array1->move(4, 0);
    array1->move(4, 1);
    array1->move(4, 2);
    array1->move(4, 3);
    array1->move(4, 4);
    QVERIFY(array1->value(0) == value1);
    QVERIFY(array1->value(1) == value3);
    QVERIFY(array1->value(2) == value2);
    QVERIFY(array1->value(3) == value0);
}

void TestJson::QMJsonArray_replace(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());

    array1->replace(-1, QMPointer<QMJsonValue>());
    array1->replace(0, QMPointer<QMJsonValue>());
    array1->replace(100, QMPointer<QMJsonValue>());

    array1->replace(-1, 10);
    array1->replace(0, true);
    array1->replace(100, "Hello");

    array1->append(value0);
    array1->append(value1);

    array1->replace(0, value2);
    array1->replace(1, value3);
    QVERIFY(array1->value(0) == value2);
    QVERIFY(array1->value(1) == value3);

    array1->replace(0, QMPointer<QMJsonValue>());
    array1->replace(1, QMPointer<QMJsonValue>());
    QVERIFY(array1->value(0).isNull() == false);
    QVERIFY(array1->value(1).isNull() == false);

    array1->replace(0, "15.16");
    array1->replace(1, true);
    QVERIFY(array1->value(0)->isString() == true);
    QVERIFY(array1->value(1)->isBool() == true);
}

void TestJson::QMJsonArray_null(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());

    array1->append(value0);

    QVERIFY(array1->isNull(0) == true);
    QVERIFY(array1->isBool(0) == false);
    QVERIFY(array1->isDouble(0) == false);
    QVERIFY(array1->isString(0) == false);
    QVERIFY(array1->isArray(0) == false);
    QVERIFY(array1->isObject(0) == false);
    QVERIFY(array1->is<QRect>(0) == false);

    QVERIFY(array1->toBool(0) == false);
    QVERIFY(array1->toDouble(0) == 0);
    QVERIFY(array1->toString(0) == "null");
    QVERIFY(array1->toArray(0).isNull() == false);
    QVERIFY(array1->toObject(0).isNull() == false);

    QVERIFY(array1->toBool(0, true) == true);
    QVERIFY(array1->toDouble(0, 4.8) == 4.8);
    QVERIFY(array1->toString(0, "15.16") == "15.16");
    QVERIFY(array1->toArray(0, QMPointer<QMJsonArray>()).isNull() == true);
    QVERIFY(array1->toObject(0, QMPointer<QMJsonObject>()).isNull() == true);
    QVERIFY(array1->to<QRect>(0, QRect()) == QRect());
    QVERIFY(array1->from(0, value0) == true);
    QVERIFY(array1->from<QSize>(0, QSize(15, 16)) == false);
}

void TestJson::QMJsonArray_bool(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());

    array1->append(value0);

    QVERIFY(array1->isNull(0) == false);
    QVERIFY(array1->isBool(0) == true);
    QVERIFY(array1->isDouble(0) == false);
    QVERIFY(array1->isString(0) == false);
    QVERIFY(array1->isArray(0) == false);
    QVERIFY(array1->isObject(0) == false);
    QVERIFY(array1->is<QRect>(0) == false);

    QVERIFY(array1->toBool(0) == true);
    QVERIFY(array1->toDouble(0) == 1);
    QVERIFY(array1->toString(0) == "true");
    QVERIFY(array1->toArray(0).isNull() == false);
    QVERIFY(array1->toObject(0).isNull() == false);

    QVERIFY(array1->toBool(0, false) == true);
    QVERIFY(array1->toDouble(0, 4.8) == 4.8);
    QVERIFY(array1->toString(0, "15.16") == "15.16");
    QVERIFY(array1->toArray(0, QMPointer<QMJsonArray>()).isNull() == true);
    QVERIFY(array1->toObject(0, QMPointer<QMJsonObject>()).isNull() == true);
    QVERIFY(array1->to<QRect>(0, QRect()) == QRect());

    QVERIFY(array1->from(0, value0) == true);
    QVERIFY(array1->fromBool(0, false) == true);
    QVERIFY(array1->fromDouble(0, 4.8) == true);
    QVERIFY(array1->fromString(0, "false") == true);
    QVERIFY(array1->fromArray(0, QMPointer<QMJsonArray>()) == false);
    QVERIFY(array1->fromObject(0, QMPointer<QMJsonObject>()) == false);
    QVERIFY(array1->from<QSize>(0, QSize(15, 16)) == false);
}

void TestJson::QMJsonArray_double(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());

    array1->append(value0);

    QVERIFY(array1->isNull(0) == false);
    QVERIFY(array1->isBool(0) == false);
    QVERIFY(array1->isDouble(0) == true);
    QVERIFY(array1->isString(0) == false);
    QVERIFY(array1->isArray(0) == false);
    QVERIFY(array1->isObject(0) == false);
    QVERIFY(array1->is<QRect>(0) == false);

    QVERIFY(array1->toBool(0) == true);
    QVERIFY(array1->toDouble(0) == 4.8);
    QVERIFY(array1->toString(0) == "4.8");
    QVERIFY(array1->toArray(0).isNull() == false);
    QVERIFY(array1->toObject(0).isNull() == false);

    QVERIFY(array1->toBool(0, false) == false);
    QVERIFY(array1->toDouble(0, 15.16) == 4.8);
    QVERIFY(array1->toString(0, "15.16") == "15.16");
    QVERIFY(array1->toArray(0, QMPointer<QMJsonArray>()).isNull() == true);
    QVERIFY(array1->toObject(0, QMPointer<QMJsonObject>()).isNull() == true);
    QVERIFY(array1->to<QRect>(0, QRect()) == QRect());

    QVERIFY(array1->from(0, value0) == true);
    QVERIFY(array1->fromBool(0, false) == true);
    QVERIFY(array1->fromDouble(0, 15.16) == true);
    QVERIFY(array1->fromString(0, "false") == false);
    QVERIFY(array1->fromArray(0, QMPointer<QMJsonArray>()) == false);
    QVERIFY(array1->fromObject(0, QMPointer<QMJsonObject>()) == false);
    QVERIFY(array1->from<QSize>(0, QSize(15, 16)) == false);
}

void TestJson::QMJsonArray_string(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue("test"));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());

    array1->append(value0);

    QVERIFY(array1->isNull(0) == false);
    QVERIFY(array1->isBool(0) == false);
    QVERIFY(array1->isDouble(0) == false);
    QVERIFY(array1->isString(0) == true);
    QVERIFY(array1->isArray(0) == false);
    QVERIFY(array1->isObject(0) == false);
    QVERIFY(array1->is<QRect>(0) == false);

    QVERIFY(array1->toBool(0) == false);
    QVERIFY(array1->toDouble(0) == 0);
    QVERIFY(array1->toString(0) == "test");
    QVERIFY(array1->toArray(0).isNull() == false);
    QVERIFY(array1->toObject(0).isNull() == false);

    QVERIFY(array1->toBool(0, true) == true);
    QVERIFY(array1->toDouble(0, 15.16) == 15.16);
    QVERIFY(array1->toString(0, "15.16") == "test");
    QVERIFY(array1->toArray(0, QMPointer<QMJsonArray>()).isNull() == true);
    QVERIFY(array1->toObject(0, QMPointer<QMJsonObject>()).isNull() == true);
    QVERIFY(array1->to<QRect>(0, QRect()) == QRect());

    QVERIFY(array1->from(0, value0) == true);
    QVERIFY(array1->fromBool(0, false) == true);
    QVERIFY(array1->fromDouble(0, 15.16) == true);
    QVERIFY(array1->fromString(0, "15.16") == true);
    QVERIFY(array1->fromArray(0, QMPointer<QMJsonArray>()) == false);
    QVERIFY(array1->fromObject(0, QMPointer<QMJsonObject>()) == false);
    QVERIFY(array1->from<QSize>(0, QSize(15, 16)) == false);
}

void TestJson::QMJsonArray_array(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonArray()));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());

    array1->append(value0);

    QVERIFY(array1->isNull(0) == false);
    QVERIFY(array1->isBool(0) == false);
    QVERIFY(array1->isDouble(0) == false);
    QVERIFY(array1->isString(0) == false);
    QVERIFY(array1->isArray(0) == true);
    QVERIFY(array1->isObject(0) == false);
    QVERIFY(array1->is<QRect>(0) == false);

    QVERIFY(array1->toBool(0) == false);
    QVERIFY(array1->toDouble(0) == 0);
    QVERIFY(array1->toString(0) == QString());
    QVERIFY(array1->toArray(0).isNull() == false);
    QVERIFY(array1->toObject(0).isNull() == false);

    QVERIFY(array1->toBool(0, true) == true);
    QVERIFY(array1->toDouble(0, 15.16) == 15.16);
    QVERIFY(array1->toString(0, "15.16") == "15.16");
    QVERIFY(array1->toArray(0, QMPointer<QMJsonArray>()).isNull() == false);
    QVERIFY(array1->toObject(0, QMPointer<QMJsonObject>()).isNull() == true);
    QVERIFY(array1->to<QRect>(0, QRect()) == QRect());

    QVERIFY(array1->from(0, value0) == true);
    QVERIFY(array1->fromBool(0, false) == false);
    QVERIFY(array1->fromDouble(0, 15.16) == false);
    QVERIFY(array1->fromString(0, "15.16") == false);
    QVERIFY(array1->fromArray(0, QMPointer<QMJsonArray>()) == true);
    QVERIFY(array1->fromObject(0, QMPointer<QMJsonObject>()) == false);
    QVERIFY(array1->from<QSize>(0, QSize(15, 16)) == false);
}

void TestJson::QMJsonArray_object(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonObject()));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());

    array1->append(value0);

    QVERIFY(array1->isNull(0) == false);
    QVERIFY(array1->isBool(0) == false);
    QVERIFY(array1->isDouble(0) == false);
    QVERIFY(array1->isString(0) == false);
    QVERIFY(array1->isArray(0) == false);
    QVERIFY(array1->isObject(0) == true);
    QVERIFY(array1->is<QRect>(0) == false);

    QVERIFY(array1->toBool(0) == false);
    QVERIFY(array1->toDouble(0) == 0);
    QVERIFY(array1->toString(0) == QString());
    QVERIFY(array1->toArray(0).isNull() == false);
    QVERIFY(array1->toObject(0).isNull() == false);

    QVERIFY(array1->toBool(0, true) == true);
    QVERIFY(array1->toDouble(0, 15.16) == 15.16);
    QVERIFY(array1->toString(0, "15.16") == "15.16");
    QVERIFY(array1->toArray(0, QMPointer<QMJsonArray>()).isNull() == true);
    QVERIFY(array1->toObject(0, QMPointer<QMJsonObject>()).isNull() == false);
    QVERIFY(array1->to<QRect>(0, QRect()) == QRect());

    QVERIFY(array1->from(0, value0) == true);
    QVERIFY(array1->fromBool(0, false) == false);
    QVERIFY(array1->fromDouble(0, 15.16) == false);
    QVERIFY(array1->fromString(0, "15.16") == false);
    QVERIFY(array1->fromArray(0, QMPointer<QMJsonArray>()) == false);
    QVERIFY(array1->fromObject(0, QMPointer<QMJsonObject>()) == true);
    QVERIFY(array1->from<QSize>(0, QSize(15, 16)) == false);
}

void TestJson::QMJsonArray_custom(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue(QSize(4, 8)));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());

    array1->append(value0);

    QVERIFY(array1->isNull(0) == false);
    QVERIFY(array1->isBool(0) == false);
    QVERIFY(array1->isDouble(0) == false);
    QVERIFY(array1->isString(0) == false);
    QVERIFY(array1->isArray(0) == false);
    QVERIFY(array1->isObject(0) == false);
    QVERIFY(array1->is<QSize>(0) == true);

    QVERIFY(array1->toBool(0) == false);
    QVERIFY(array1->toDouble(0) == 0);
    QVERIFY(array1->toString(0) == QString());
    QVERIFY(array1->toArray(0).isNull() == false);
    QVERIFY(array1->toObject(0).isNull() == false);

    QVERIFY(array1->toBool(0, true) == true);
    QVERIFY(array1->toDouble(0, 15.16) == 15.16);
    QVERIFY(array1->toString(0, "15.16") == "15.16");
    QVERIFY(array1->toArray(0, QMPointer<QMJsonArray>()).isNull() == true);
    QVERIFY(array1->toObject(0, QMPointer<QMJsonObject>()).isNull() == true);
    QVERIFY(array1->to<QSize>(0, QSize()) == QSize(4, 8));

    QVERIFY(array1->from(0, value0) == false);
    QVERIFY(array1->fromBool(0, false) == false);
    QVERIFY(array1->fromDouble(0, 15.16) == false);
    QVERIFY(array1->fromString(0, "15.16") == false);
    QVERIFY(array1->fromArray(0, QMPointer<QMJsonArray>()) == false);
    QVERIFY(array1->fromObject(0, QMPointer<QMJsonObject>()) == false);
    QVERIFY(array1->from<QSize>(0, QSize(15, 16)) == true);
}

void TestJson::QMJsonArray_signals(void)
{
    auto value0 = QMPointer<QMJsonValue>(new QMJsonValue("15.16"));
    auto array1 = QMPointer<QMJsonArray>(new QMJsonArray());
    auto array2 = QMPointer<QMJsonArray>(new QMJsonArray());

    connect(array1.data(), &QMJsonArray::itemAdded, this, &TestJson::signaled);
    connect(array1.data(), &QMJsonArray::itemRemoved, this, &TestJson::signaled);
    connect(array2.data(), &QMJsonArray::itemAdded, this, &TestJson::signaled);
    connect(array2.data(), &QMJsonArray::itemRemoved, this, &TestJson::signaled);

    mCount = 0;
    array1->removeFirst();
    array1->removeLast();
    QVERIFY(mCount == 0);

    mCount = 0;
    array1->removeAt(1);
    QVERIFY(mCount == 0);

    mCount = 0;
    array1->removeOne(value0);
    QVERIFY(mCount == 0);

    mCount = 0;
    array1->removeAll(value0);
    QVERIFY(mCount == 0);

    mCount = 0;
    array1->clear();
    QVERIFY(mCount == 0);

    mCount = 0;
    array1->prepend(value0);
    array1->append(value0);
    array1->insert(0, value0);
    QVERIFY(mCount == 3);

    mCount = 0;
    array2->prepend(4.8);
    array2->append(15.16);
    array2->insert(0, 23.42);
    QVERIFY(mCount == 3);

    mCount = 0;
    array1->unite(array2, QMJsonArrayUnitePolicy_Prepend);
    array1->unite(array2, QMJsonArrayUnitePolicy_Append);
    QVERIFY(mCount == 6);

    mCount = 0;
    array1->removeFirst();
    array1->removeLast();
    QVERIFY(mCount == 2);

    mCount = 0;
    array1->removeAt(1);
    QVERIFY(mCount == 1);

    mCount = 0;
    array1->removeOne(value0);
    QVERIFY(mCount == 1);

    mCount = 0;
    array1->removeAll(value0);
    QVERIFY(mCount == 2);

    mCount = 0;
    array1->clear();
    QVERIFY(mCount == 3);

    mCount = 0;
    array1->takeFirst();
    array1->takeLast();
    QVERIFY(mCount == 0);

    mCount = 0;
    array1->takeAt(1);
    array1->takeAt(1, value0);
    array1->takeAt(1, 15.16);
    QVERIFY(mCount == 0);

    mCount = 0;
    array1->append(value0);
    array1->append(value0);
    array1->append(value0);
    array1->append(value0);
    array1->append(value0);
    array1->append(value0);
    QVERIFY(mCount == 6);

    mCount = 0;
    array1->takeAt(1);
    array1->takeAt(1, value0);
    array1->takeAt(1, 15.16);
    QVERIFY(mCount == 3);

    mCount = 0;
    array1->takeFirst();
    array1->takeLast();
    QVERIFY(mCount == 2);

    mCount = 0;
    array1->clear();
    QVERIFY(mCount == 1);

    mCount = 0;
    array1->append(value0);
    QVERIFY(mCount == 1);

    mCount = 0;
    array1->replace(0, value0);
    QVERIFY(mCount == 2);

    mCount = 0;
    array1->replace(0, 15.16);
    QVERIFY(mCount == 2);
}
