#!/bin/bash

set -e

SCRIPTPATH=$(dirname "$(realpath "$0")")

if [[ ! -d build ]]; then
  mkdir -p "${SCRIPTPATH}/"build
  cd ./build
  cmake ../
else
  cd ./build
fi

make
./spike ./test/hello.lisp
