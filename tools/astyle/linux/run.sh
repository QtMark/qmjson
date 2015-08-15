#!/bin/sh

# Make sure that any errors don't cascade.
set -e

SVLIB_PATH=$1
ASTYLE=$SVLIB_PATH/tools/astyle/linux/build/gcc/bin/astyle
CURRENT_DIR=$PWD

# If astyle has not been found, we need to get it and compile it.
# This will make sure that no matter what system your on, you will
# be able to use astyle.
if [ ! -f $ASTYLE ]; then

	echo "Building Astyle"

	# Move into the unix source directory and clean it up.
	cd $SVLIB_PATH/tools/astyle/linux/build/gcc
	rm -Rf bin
	rm -Rf obj

	# Compile astyle
	make

	# Done.
	cd $CURRENT_DIR
fi

# Run astyle
shift
find . -name "*.h" -exec $ASTYLE --options=$SVLIB_PATH/tools/astyle/astyle.config {} \;
find . -name "*.c" -exec $ASTYLE --options=$SVLIB_PATH/tools/astyle/astyle.config {} \;
find . -name "*.cpp" -exec $ASTYLE --options=$SVLIB_PATH/tools/astyle/astyle.config {} \;
