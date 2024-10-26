#!/bin/bash

BUILD_DIR="build"
CPP_VERSION=26

source optparse.bash
optparse.define short=b long=build desc="Build the project" variable=build value=true default=false
optparse.define short=c long=compiler desc="Compiler to use for building" variable=compiler default="clang++"
optparse.define short=d long=build-dependencies desc="Build only the dependencies" variable=deps value=true default=false
source $( optparse.build )

echo "Setting up repository"

pre-commit install


if [ "$build" = true ];
then
    cmake -S . \
        -B "$BUILD_DIR" \
        -DCMAKE_CXX_COMPILER="$compiler" \
        -DCMAKE_CXX_STANDARD="$CPP_VERSION" \
        -DRAD_BUILD=ON \
        -Wno-dev \
        -Wdeprecated-declarations \
        -Wunused-result

    cd build

    make
fi

if [ "$deps" = true ];
then
    cmake -S . \
        -B "$BUILD_DIR" \
        -DCMAKE_CXX_COMPILER="$compiler" \
        -DCMAKE_CXX_STANDARD="$CPP_VERSION" \
        -Wno-dev \
        -Wdeprecated-declarations \
        -Wunused-result

    cd build

    make
fi



exit 0
