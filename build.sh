#!/usr/bin/env bash

set -e
if [ ! -d build ]; then
    mkdir build
fi

pushd build
cmake ../src-server
make
popd
