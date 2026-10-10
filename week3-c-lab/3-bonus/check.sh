#!/usr/bin/env bash
# Compiles and runs triangle.c and checks that it prints the triangle.
# Usage: bash check.sh
cd "$(dirname "$0")" || exit 1
CC=$(command -v clang || command -v cc)

expected="#
##
###
####
#####"

if grep -q '"##' triangle.c; then
    echo "FAIL  triangle.c prints more than one # in a single printf. Use loops instead."
    exit 1
fi
"$CC" triangle.c -o triangle || { echo "FAIL  triangle.c doesn't compile (see the error above)"; exit 1; }
got=$(timeout 2 ./triangle)
if [ "$got" = "$expected" ]; then
    echo "PASS  triangle.c prints the triangle!"
else
    echo "FAIL  triangle.c"
    echo "expected:"
    echo "$expected"
    echo "got:"
    echo "$got"
fi
