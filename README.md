# QtMark JSON Library

## Description

The QtMark JSON Library provides an alternative implementation to Qt's native
JSON implementation. Some notable improvements include:

- All JSON values, arrays and objects are stored as managed pointers, providing
a simple means to externally maintain a reference to portions of a JSON tree
- Support for custom types, providing a means to automatically marshal /
unmarshal JSON trees into complex C++ Classes.
- Native support for some custom types (providing convenience and example)
including QRect, QSize, QPoint and QColor.
- Signal / Slot support for JSON values, arrays and objects to detect when
changes occur to specific portions of the tree.
- Several convenience functions for JSON values, arrays and objects providing
a more developer friendly API.

For more information on the API, please see the API documentation:

http://qtmark.github.io/qmjson/doc/html/

## Requirements

- C++11
- Qt 5.2 and above

## Building / Installation Instructions

To build the QtMark JSON Library, first make sure that Qt is installed in your
development environment. Once installed, execute the following:

```
qmake -r
make -j
make install
```

## Usage

To use this library, simply include the following:

```c
#include <qmjson.h>
#include <qmjsongui.h>
```

The QtMark JSON Library uses C++11, and thus you must add this to your project
file. You will also need to add the libraries themselves. Note that the GUI
library is optional (don't forget to remove the include if you don't use it).

```
CONFIG += c++11
LIBS += -lqmjson -lqmjsongui
```

For a more complete example, see the example application that is included with
this source code. To run this example code, execute the following

```
cd example
qmake
make -j
./example
```

## Unit Tests

The QtMark JSON Library comes complete with a set of unit tests that can be
used to validate that changes do not break the expected functionality of the
API. The unit tests may also provide additional examples of how to use the
library as most of the API is tested.

```
cd test
qmake
make -j
./test -platform offscreen
```

## Cleanup

To cleanup your source tree after compiling, you can run the following:

```
make clean
```

If you want to completely remove all generated files, you can run the
following:

```
make distclean
```

## License

The QtMark Libraries are licensed under the GNU Lesser General Public License
v2 (LGPL) library. Please note that this library depends on Qt which has it's
own license.

