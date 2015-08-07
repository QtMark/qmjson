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

#include <qmjson.h>

int main(int argc, char const *argv[])
{
    (void) argc;
    (void) argv;

    //--------------------------------------------------------------------------
    // Setup
    //--------------------------------------------------------------------------

    QMPointer<QMJsonValue> value1 = QMPointer<QMJsonValue>(new QMJsonValue(5.5));
    QMPointer<QMJsonValue> value2 = QMPointer<QMJsonValue>(new QMJsonValue("Hello"));
    QMPointer<QMJsonValue> value3 = QMPointer<QMJsonValue>(new QMJsonValue(true));
    QMPointer<QMJsonArray> array = QMPointer<QMJsonArray>(new QMJsonArray());
    QMPointer<QMJsonObject> object = QMPointer<QMJsonObject>(new QMJsonObject());

    array->append(value1);
    array->append(value2);
    array->append(value3);

    object->insert("key1", value1);
    object->insert("key2", value2);
    object->insert("key3", value3);

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
    // Tree Example
    //--------------------------------------------------------------------------

    object->insert("key4", array);

    qDebug() << "Tree:";
    qDebug() << "  " << object;
    qDebug() << "";

    return 0;
}
