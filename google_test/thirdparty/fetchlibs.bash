#!/bin/bash
SCRIPTPATH=$(dirname "$(realpath "$0")")
git clone --depth 1 https://github.com/google/googletest/ "${SCRIPTPATH}/googletest"