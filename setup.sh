#!/bin/sh

git submodule init

if [ ! -d build ]; then
  mkdir build
fi

cd build/

cmake ..
