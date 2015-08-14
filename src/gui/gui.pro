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
TARGET = qmjsongui

DEFINES += QM_JSON_LIBRARY

#-------------------------------------------------------------------------------
# Source / Headers
#-------------------------------------------------------------------------------

SOURCES += qmjsontype_qcolor.cpp
SOURCES += qmjsontype_qpoint.cpp
SOURCES += qmjsontype_qsize.cpp
SOURCES += qmjsontype_qrect.cpp

HEADERS += ../../include/qmjsongui.h
HEADERS += ../../include/qmjsontype_qcolor.h
HEADERS += ../../include/qmjsontype_qpoint.h
HEADERS += ../../include/qmjsontype_qsize.h
HEADERS += ../../include/qmjsontype_qrect.h

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

QT += gui
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
