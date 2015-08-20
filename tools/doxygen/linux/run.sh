#!/bin/bash

set -e

if [ $# -gt 0 ]; then
    if [ $1 = "clean" ]; then

        rm -Rf ./tools/doxygen/linux/src
        exit
    fi
fi

if [ ! -f tools/doxygen/linux/src/build/bin/doxygen ]; then

	pushd tools/doxygen/linux
	rm -Rf src

	git clone https://github.com/doxygen/doxygen.git src

	cd src
	mkdir build
  	cd build
  	cmake -G "Unix Makefiles" ../
	make -j

	popd
fi

rm -Rf doc
mkdir doc

cd doc
../tools/doxygen/linux/src/build/bin/doxygen ../tools/doxygen/config.txt
