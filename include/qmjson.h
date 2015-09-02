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

#ifndef QMJSON_H
#define QMJSON_H

#include <qmjsonvalue.h>
#include <qmjsonarray.h>
#include <qmjsonobject.h>

#include <qmjsontype_bool.h>
#include <qmjsontype_double.h>
#include <qmjsontype_qstring.h>
#include <qmjsontype_qmjsonarray.h>
#include <qmjsontype_qmjsonobject.h>

#endif

/**
 * @mainpage QtMark JSON Library
 *
 * This JSON library provides several benefits over the standard JSON library
 * the comes with Qt.
 *
 * ### Managed Pointers
 *
 * @note Currently QMPointer is a redefinition of QSharedPointer as we have
 * not yet upstreamed QMPointer. Once the upstream is complete, the only
 * change that will be needed is to include the QtMark Pointer Library.
 *
 * When using this library, you will notice that everything is stored using
 * managed QMPointers. This is done intentially, and you should not attempt
 * to use the Qt Mark JSON classes without storing them in a QMPointer as
 * each class prohibits by-value copying. Although storing these classes in
 * managed QMPointers adds an extra level of complexity, it also provides
 * a lot of benefits. The most notible being the following:
 *
 * @code
 *
 * auto object1 = QMPointer<QMJsonObject>(new QMJsonObject);
 * auto object2 = QMPointer<QMJsonObject>(new QMJsonObject);
 * auto object3 = QMPointer<QMJsonObject>(new QMJsonObject);
 *
 * object1->insert("object2", object2);
 * object2->insert("object3", object3);
 * object3->insert("boolean", true);
 * object3->insert("double", 4.8);
 * object3->insert("string", "Hello World");
 *
 * @endcode
 *
 * In this example, you could pass 'object3' easily to any function, and
 * manipulate it from more than one place as needed. It is also possible to
 * use a JSON value in more than one place in a JSON tree at the same time:
 *
 * @code
 *
 * object1->insert("object2", object2);
 * object1->insert("object3", object3);
 * object2->insert("object3", object3);
 *
 * @endcode
 *
 * You can also save off specific portions of a tree:
 *
 * @code
 *
 * auto object1 = QMPointer<QMJsonObject>(new QMJsonObject);
 * auto object2 = QMPointer<QMJsonObject>(new QMJsonObject);
 * auto object3 = QMPointer<QMJsonObject>(new QMJsonObject);
 * auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(object1));
 * auto value2 = QMPointer<QMJsonValue>(new QMJsonValue(object2));
 * auto value3 = QMPointer<QMJsonValue>(new QMJsonValue(object3));
 *
 * object1->insert("object2", object2);
 * object2->insert("object3", object3);
 * object3->insert("boolean", true);
 * object3->insert("double", 4.8);
 * object3->insert("string", "Hello World");
 *
 * qDebug() << value1->toJson();
 * qDebug() << value2->toJson();
 * qDebug() << value3->toJson();
 *
 * @endcode
 *
 * ### Complex Types
 *
 * Unlike Qt's native JSON support, the QtMark JSON Library has support for
 * custom types. Actually, you can store anything in a QMJsonValue that you
 * want. This provides the ability to use QMJsonArray and QMJsonObject as
 * a set of data structures that support varying data types in C++. That is
 * with most C++ data structures, you can only store one type of data in the
 * structure, but with this library, you can store anything you want, in
 * whatever combination you can think of:
 *
 * @code
 *
 * [1, 2, 3, 4, 5]
 *
 * // vs
 *
 * [QSize, 4.8, true, "Hello", MyClass]
 *
 * @endcode
 *
 * The compiler is likely to complain about a non-JSON type if it doesn't
 * contain the following:
 *
 * - Default constructor
 * - Equals operator
 * - QDebug Overload
 *
 * If you attempt to use toJson or fromJson with a non-JSON type, you will also
 * need to provide overloads to QMJsonType::toComplexJson and
 * QMJsonType::fromComplexJson. These functions are used to tell the JSON
 * library how to marshal / unmarshal the non-JSON type into standard JSON.
 * Non-standard types are stored as JSON objects, with a special field in the
 * object called 'qmjsontype' that tells the library which
 * QMJsonType::fromComplexJson function to use when an object with this
 * key is encountered. QMJsonType::fromComplexJson functions are registered
 * with the library using QMJsonValue::registerFromComplexJson.
 *
 * For a complete exmaple, see main.cpp, qmjsontype_qsize.cpp and
 * qmjsontype_qrect.cpp
 *
 * ### Signals / Slots
 *
 * Since all of the JSON classes in the QtMark JSON Library use managed
 * QMPointers, they can safely inherit QObject providing access to signals
 * and slots. QMJsonValue, QMJsonArray and QMJsonObject provide the following
 * signals:
 *
 * - valueChanged
 * - itemAdded
 * - itemRemoved
 *
 * With signals and slots, it's possible trigger code when changes to a JSON
 * tree occur, providing a simple means for implementing MVC architectures
 * with this JSON library.
 *
 * ### Convenience Functions
 *
 * This library comes with a lot of convenience functions designed to make
 * dealing with the API easier on developers. For example, JSON normally only
 * stores doubles for numbers. This is because most integer types can be stored
 * as a double. The problem is this leaves a lot of type casting to the
 * programmer. If you wanted to add an int to a QMJsonValue, you would need
 * to first case the int to a double:
 *
 * @code
 *
 * auto value1 = QMPointer<QMJsonValue>(new QMJsonValue((double)4));
 *
 * // vs
 *
 * auto value2 = QMPointer<QMJsonValue>(new QMJsonValue(4));
 *
 * @endcode
 *
 * These automatic type conversions are provided for all number types, as well
 * as standard C style strings. These type conversions also work with
 * QMJsonArray and QMJsonObject's insertion functions. QMJsonArray and
 * QMJsonObject also provide convenience functions for accessing QMJsonValues.
 * For example, the following are equivlant:
 *
 * @code
 *
 * auto object = QMPointer<QMJsonObject>(new QMJsonObject);
 * object->insert("key1", 4.8);
 *
 * qDebug() << object->value("key1")->toDouble(); // 4.8
 * qDebug() << object->toDouble("key1"); // 4.8
 *
 * @endcode
 *
 * The same works for QMJsonArray, and we even provided something similar for
 * QMJsonValue
 *
 * @code
 *
 * auto object = QMPointer<QMJsonObject>(new QMJsonObject);
 * auto value = QMPointer<QMJsonValue>(new QMJsonValue(object));
 * object->insert("key1", 4.8);
 *
 * qDebug() << value->toObject()->value("key1"); // QMJsonValue(4.8)
 * qDebug() << value->value("key1"); // QMJsonValue(4.8)
 *
 * @endcode
 *
 * ### To / From JSON
 *
 * It's likely that at some point, your going to want to convert your JSON
 * to a JSON string. This can be done by either using an existing
 * QMJsonValue, or wrapping what you want to convert to JSON (e.g. a
 * QMJsonObject or maybe a non-standard JSON type like QSize) with a
 * QMJsonValue, and then running QMJsonValue::toJson.
 *
 * @code
 *
 * auto object = QMPointer<QMJsonObject>(new QMJsonObject);
 * auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(object));
 * auto value2 = QMPointer<QMJsonValue>(new QMJsonValue(QSize(4, 8)));
 *
 * object->insert("key1", 4.8);
 *
 * qDebug() << value1->toJson(QMJsonFormat_Optimized); // {"key1":4.8}
 * qDebug() << value2->toJson(QMJsonFormat_Optimized); // {"width":4,"height":8,"qmjsontype":"QSize"}
 *
 * @endcode
 *
 * If you want to convert a JSON string to it's QtMark JSON representation,
 * you can use the fromJson function:
 *
 * @code
 *
 * QMJsonValue::registerFromComplexJson("QSize", &QMJsonType<QSize>::fromComplexJson);
 *
 * auto object = QMPointer<QMJsonObject>(new QMJsonObject);
 * auto value1 = QMPointer<QMJsonValue>(new QMJsonValue(object));
 * auto value2 = QMPointer<QMJsonValue>(new QMJsonValue(QSize(4, 8)));
 *
 * object->insert("key1", 4.8);
 *
 * qDebug() << QMJsonValue::fromJson("{\"key1\":4.8}"); // QMJsonValue(QMJsonObject("key1",4.8))
 * qDebug() << QMJsonValue::fromJson("{\"width\":4,\"height\":8,\"qmjsontype\":\"QSize\"}"); // QMJsonValue(QSize(4,8))
 *
 * @endcode
 *
 * ### Further Information
 *
 * Each of the QtMark JSON classes are documented. To see more information,
 * please review the following:
 *
 * \ref qmjsonvalue \n
 * \ref qmjsonarray \n
 * \ref qmjsonobject \n
 */

// - Several convenience functions for JSON values, arrays and objects providing
// a more developer friendly API.
