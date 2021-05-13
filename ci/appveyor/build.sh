#!/bin/bash

set -e

BUILDTOOL=${BUILDTOOL:-cmake}
COMPILER=${COMPILER:-gcc}

echo "BUILDTOOL: ${BUILDTOOL}"
echo "COMPILER:  ${COMPILER}"

export LANG=en_US.utf8

if [ "${COMPILER}" = "clang" ] ; then
    export CC=/usr/bin/clang
    export CXX=/usr/bin/clang++
elif [ "${COMPILER}" = "gcc" ] ; then
    export CC=gcc-10
    export CXX=g++-10
fi

if [ "${BUILDTOOL}" = "cmake" ] ; then
    CMAKE_ARGS=${CMAKE_ARGS:-"-DCMAKE_BUILD_TYPE=Debug"}
    echo "CMAKE_ARGS: ${CMAKE_ARGS}"

    mkdir build
    (cd build && cmake -DCMAKE_UNITY_BUILD=ON -G Ninja "${CMAKE_ARGS}" ..)
    (cd build && ninja)
fi
