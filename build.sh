#!/bin/bash

echo "Environment: `uname -a`"
echo "Compiler: `$CXX --version`"

make clean || exit 1
make all|| exit 1
