#!/usr/bin/env bash
# Compiles and runs each fixme program and says whether it now prints the right thing.
# Usage: bash check.sh
cd "$(dirname "$0")" || exit 1
CC=$(command -v clang || command -v cc)
pass=0
total=0

check() {   # check PROGRAM.c EXPECTED_OUTPUT
    local src="$1" expected="$2" prog="${1%.c}" got
    total=$((total + 1))
    if ! "$CC" "$src" -o "$prog" 2> errors.txt; then
        echo "FAIL  $src  (doesn't compile)"
        grep -m1 'error' errors.txt | sed 's/^/      /'
    else
        got=$(timeout 2 ./"$prog" 2>&1)
        if [ "$got" = "$expected" ]; then
            echo "PASS  $src"
            pass=$((pass + 1))
        else
            echo "FAIL  $src"
            echo "      expected: $(echo "$expected" | tr '\n' '|')"
            echo "      got:      $(echo "$got" | tr '\n' '|')"
        fi
    fi
    rm -f errors.txt
}

check 01_semicolon.c "hello, C"
check 02_printf.c "3 + 4 = 7"
check 03_equals.c "n is 5"
check 04_divide.c "212F is 100C"
check 05_countdown.c "3 2 1 liftoff!"
check 06_age.c "age 19: too young to rent a car"

echo
echo "$pass / $total programs fixed"
