#!/bin/bash

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

set -e

ASTYLE=./tools/astyle/linux/src/build/gcc/bin/astyle

if [ $# -gt 0 ]; then
    if [ $1 = "clean" ]; then

        rm -Rf ./tools/astyle/linux/src
        exit
    fi
fi

if [ ! -f $ASTYLE ]; then

	pushd ./tools/astyle/linux/
    rm -Rf src

    git clone https://github.com/timonwong/astyle-mirror src
    cd src/build/gcc

	make -j

	popd
fi

find src/ -name "*.h" -exec $ASTYLE --options=./tools/astyle/astyle.config {} \;
find src/ -name "*.c" -exec $ASTYLE --options=./tools/astyle/astyle.config {} \;
find src/ -name "*.cpp" -exec $ASTYLE --options=./tools/astyle/astyle.config {} \;

find test/ -name "*.h" -exec $ASTYLE --options=./tools/astyle/astyle.config {} \;
find test/ -name "*.c" -exec $ASTYLE --options=./tools/astyle/astyle.config {} \;
find test/ -name "*.cpp" -exec $ASTYLE --options=./tools/astyle/astyle.config {} \;

find example/ -name "*.h" -exec $ASTYLE --options=./tools/astyle/astyle.config {} \;
find example/ -name "*.c" -exec $ASTYLE --options=./tools/astyle/astyle.config {} \;
find example/ -name "*.cpp" -exec $ASTYLE --options=./tools/astyle/astyle.config {} \;
