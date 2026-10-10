#!/usr/bin/env bash
# Compiles and runs each triangle program and checks its output.
# Usage: bash check.sh
cd "$(dirname "$0")" || exit 1
CC=$(command -v clang || command -v cc)
pass=0

check() {   # check NAME EXPECTED_OUTPUT
    local src="$1.c" expected="$2" got
    if grep -qE '"(##|  )' "$src"; then
        echo "FAIL  $src prints more than one # or space in a single printf. Use loops instead."
        return
    fi
    if ! "$CC" "$src" -o "$1" 2> errors.txt; then
        echo "FAIL  $src  (doesn't compile)"
        grep -m1 'error' errors.txt | sed 's/^/      /'
        rm -f errors.txt
        return
    fi
    rm -f errors.txt
    # Spaces at the end of a line are invisible, so they don't count.
    got=$(timeout 2 ./"$1" | sed 's/ *$//')
    if [ "$got" = "$expected" ]; then
        echo "PASS  $src"
        pass=$((pass + 1))
    else
        echo "FAIL  $src"
        echo "$expected" | sed 's/^/      expected | /'
        echo "$got" | sed 's/^/      got      | /'
    fi
}

check left "#
##
###
####
#####"

check right "    #
   ##
  ###
 ####
#####"

check middle "    #
   ###
  #####
 #######
#########"

echo
echo "$pass / 3 triangles done"
