#
# QtMark JSON Library
#
# Copyright (C) 2015 Assured Information Security, Inc.
# Author: Rian Quinn       <quinnr@ainfosec.com>
# Author: Rodney Forbes    <forbesr@ainfosec.com>
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

cache()

#-------------------------------------------------------------------------------
# Setup
#-------------------------------------------------------------------------------

TEMPLATE = lib
VERSION = 0.1.0
TARGET = qmjson

FEATURES = ../../include/qmjsonfeatures.h
write_file($$FEATURES);

!contains(QT_MODULES, gui) {

    QT -= gui
    DEFINES += DISABLE_QMJSON_GUI
}

contains(QT_MODULES, dbus) {

    QT += dbus

    DEFINE_QM_DBUS_ENABLED += "$${LITERAL_HASH}ifndef QM_DBUS_ENABLED"
    DEFINE_QM_DBUS_ENABLED += "$${LITERAL_HASH}define QM_DBUS_ENABLED"
    DEFINE_QM_DBUS_ENABLED += "$${LITERAL_HASH}endif"
    write_file($$FEATURES, DEFINE_QM_DBUS_ENABLED, append);
}

DEFINES += QM_JSON_LIBRARY

#-------------------------------------------------------------------------------
# Source / Headers
#-------------------------------------------------------------------------------

SOURCES += qmjsonvalue.cpp
SOURCES += qmjsonobject.cpp
SOURCES += qmjsonarray.cpp
SOURCES += qmjsontype_bool.cpp
SOURCES += qmjsontype_double.cpp
SOURCES += qmjsontype_qstring.cpp
SOURCES += qmjsontype_qmjsonarray.cpp
SOURCES += qmjsontype_qmjsonobject.cpp

HEADERS += ../../include/qmjsonfeatures.h
HEADERS += ../../include/qmjson.h
HEADERS += ../../include/qmjsontype.h
HEADERS += ../../include/qmjsonvalue.h
HEADERS += ../../include/qmjsonobject.h
HEADERS += ../../include/qmjsonarray.h
HEADERS += ../../include/qmjsontype_bool.h
HEADERS += ../../include/qmjsontype_double.h
HEADERS += ../../include/qmjsontype_qstring.h
HEADERS += ../../include/qmjsontype_qmjsonarray.h
HEADERS += ../../include/qmjsontype_qmjsonobject.h

# The following is temporary until we have the QMPointer upstreamed.
HEADERS += ../../include/qmpointer.h

#-------------------------------------------------------------------------------
# Paths
#-------------------------------------------------------------------------------

DESTDIR = .build
OBJECTS_DIR = .build
MOC_DIR = .build
RCC_DIR = .build
INCLUDEPATH += ../../include

#-------------------------------------------------------------------------------
# Config
#-------------------------------------------------------------------------------

CONFIG += qt c++11

unix: {
    QMAKE_CXXFLAGS += -Werror -Wno-missing-field-initializers -march=native
}

#-------------------------------------------------------------------------------
# Inatall
#-------------------------------------------------------------------------------

unix: {
    QMAKE_COPY_FILE = $${QMAKE_COPY_FILE} -P
    LIB_DIR = /usr/lib
    INCLUDE_DIR = /usr/include/
}

target.path = $${LIB_DIR}
include.path = $${INCLUDE_DIR}
include.files = $${HEADERS}

INSTALLS += target
INSTALLS += include

#-------------------------------------------------------------------------------
# Clean
#-------------------------------------------------------------------------------

QMAKE_DISTCLEAN += .qmake.cache
QMAKE_DISTCLEAN += ../../include/qmjsonfeatures.h
