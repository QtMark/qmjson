#!/bin/bash

set -e

ASTYLE=./tools/astyle/linux/build/gcc/bin/astyle

if [ $1 = "clean" ]; then

    pushd ./tools/astyle/linux/build/gcc
    rm -Rf bin
    rm -Rf obj
    popd

    exit

fi

if [ ! -f $ASTYLE ]; then

	pushd ./tools/astyle/linux/build/gcc
	rm -Rf bin
	rm -Rf obj

	make

	popd
fi

find . -name "*.h" -exec $ASTYLE --options=./tools/astyle/astyle.config {} \;
find . -name "*.c" -exec $ASTYLE --options=./tools/astyle/astyle.config {} \;
find . -name "*.cpp" -exec $ASTYLE --options=./tools/astyle/astyle.config {} \;
