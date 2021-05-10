#!/bin/bash

set -e # exit when fail

if [[ -f "doctest.h" ]];
then
  echo "-- doctest.h already exist"
else
  curl https://raw.githubusercontent.com/onqtam/doctest/master/doctest/doctest.h > doctest.h
fi

