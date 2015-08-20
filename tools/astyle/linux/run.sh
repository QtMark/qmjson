#!/bin/bash

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
