#include <test.h>

void TestJson::QMJsonValue_create(void)
{
    auto value00 = QMPointer<QMJsonValue>(new QMJsonValue());
    auto value01 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    auto value02 = QMPointer<QMJsonValue>(new QMJsonValue(4.8));
    auto value03 = QMPointer<QMJsonValue>(new QMJsonValue(QString("Hello World")));
    auto value04 = QMPointer<QMJsonValue>(new QMJsonValue(QMPointer<QMJsonValue>(new QMJsonValue())));
    auto value05 = QMPointer<QMJsonValue>(new QMJsonValue(QMPointer<QMJsonArray>(new QMJsonArray())));
    auto value06 = QMPointer<QMJsonValue>(new QMJsonValue(QMPointer<QMJsonObject>(new QMJsonObject())));
    auto value07 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonValue()));
    auto value08 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonArray()));
    auto value09 = QMPointer<QMJsonValue>(new QMJsonValue(new QMJsonObject()));
    auto value10 = QMPointer<QMJsonValue>(new QMJsonValue(QRect()));
    auto value11 = QMPointer<QMJsonValue>(new QMJsonValue("Hello World"));
    auto value12 = QMPointer<QMJsonValue>(new QMJsonValue((short)4));
    auto value13 = QMPointer<QMJsonValue>(new QMJsonValue((unsigned short)8));
    auto value14 = QMPointer<QMJsonValue>(new QMJsonValue((int)15));
    auto value15 = QMPointer<QMJsonValue>(new QMJsonValue((unsigned int)16));
    auto value16 = QMPointer<QMJsonValue>(new QMJsonValue((long)23));
    auto value17 = QMPointer<QMJsonValue>(new QMJsonValue((unsigned long)42));
    auto value18 = QMPointer<QMJsonValue>(new QMJsonValue((long long)4));
    auto value19 = QMPointer<QMJsonValue>(new QMJsonValue((unsigned long long)8));
    auto value20 = QMPointer<QMJsonValue>(new QMJsonValue(QMPointer<QMJsonValue>()));
    auto value21 = QMPointer<QMJsonValue>(new QMJsonValue(QMPointer<QMJsonArray>()));
    auto value22 = QMPointer<QMJsonValue>(new QMJsonValue(QMPointer<QMJsonObject>()));

    QVERIFY(value00->type() == QMJsonValueType_Null);
    QVERIFY(value01->type() == QMJsonValueType_Bool);
    QVERIFY(value02->type() == QMJsonValueType_Double);
    QVERIFY(value03->type() == QMJsonValueType_String);
    QVERIFY(value04->type() == QMJsonValueType_Null);
    QVERIFY(value05->type() == QMJsonValueType_Array);
    QVERIFY(value06->type() == QMJsonValueType_Object);
    QVERIFY(value07->type() == QMJsonValueType_Null);
    QVERIFY(value08->type() == QMJsonValueType_Array);
    QVERIFY(value09->type() == QMJsonValueType_Object);
    QVERIFY(value10->type() == QMJsonValueType_Custom);
    QVERIFY(value11->type() == QMJsonValueType_String);
    QVERIFY(value12->type() == QMJsonValueType_Double);
    QVERIFY(value13->type() == QMJsonValueType_Double);
    QVERIFY(value14->type() == QMJsonValueType_Double);
    QVERIFY(value15->type() == QMJsonValueType_Double);
    QVERIFY(value16->type() == QMJsonValueType_Double);
    QVERIFY(value17->type() == QMJsonValueType_Double);
    QVERIFY(value18->type() == QMJsonValueType_Double);
    QVERIFY(value19->type() == QMJsonValueType_Double);
    QVERIFY(value20->type() == QMJsonValueType_Null);
    QVERIFY(value21->type() == QMJsonValueType_Array);
    QVERIFY(value22->type() == QMJsonValueType_Object);

    QVERIFY(value00->typeString() == "QMJsonValueType_Null");
    QVERIFY(value01->typeString() == "QMJsonValueType_Bool");
    QVERIFY(value02->typeString() == "QMJsonValueType_Double");
    QVERIFY(value03->typeString() == "QMJsonValueType_String");
    QVERIFY(value04->typeString() == "QMJsonValueType_Null");
    QVERIFY(value05->typeString() == "QMJsonValueType_Array");
    QVERIFY(value06->typeString() == "QMJsonValueType_Object");
    QVERIFY(value07->typeString() == "QMJsonValueType_Null");
    QVERIFY(value08->typeString() == "QMJsonValueType_Array");
    QVERIFY(value09->typeString() == "QMJsonValueType_Object");
    QVERIFY(value10->typeString() == "QMJsonValueType_Custom");
    QVERIFY(value11->typeString() == "QMJsonValueType_String");
    QVERIFY(value12->typeString() == "QMJsonValueType_Double");
    QVERIFY(value13->typeString() == "QMJsonValueType_Double");
    QVERIFY(value14->typeString() == "QMJsonValueType_Double");
    QVERIFY(value15->typeString() == "QMJsonValueType_Double");
    QVERIFY(value16->typeString() == "QMJsonValueType_Double");
    QVERIFY(value17->typeString() == "QMJsonValueType_Double");
    QVERIFY(value18->typeString() == "QMJsonValueType_Double");
    QVERIFY(value19->typeString() == "QMJsonValueType_Double");
    QVERIFY(value20->typeString() == "QMJsonValueType_Null");
    QVERIFY(value21->typeString() == "QMJsonValueType_Array");
    QVERIFY(value22->typeString() == "QMJsonValueType_Object");
}
