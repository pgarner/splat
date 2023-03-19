#!/bin/sh
#
# Copyright 2018 by Philip N. Garner
#
# See the file COPYING for the licence associated with this software.
#
# Author(s):
#   Phil Garner, October 2018
#

rm -rf CMakeCache.txt CMakeFiles cmake_install.cmake

export CC=clang
export CXX=clang++

cmake \
    -D CMAKE_BUILD_TYPE=relwthdebinfo \
    -D CMAKE_CXX_FLAGS="-Wall -Werror" \
    .
