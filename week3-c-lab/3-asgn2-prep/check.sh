#!/usr/bin/env bash
# Compiles and runs each program and says whether it now does the right thing.
# Compiles with -lm, like asgn2, because some programs use <math.h>.
# Usage: bash check.sh
cd "$(dirname "$0")" || exit 1
CC=$(command -v clang || command -v cc)
pass=0
total=0

build() {   # build PROGRAM.c, or say why it didn't compile
    if ! "$CC" -lm "$1" -o "${1%.c}" 2> errors.txt; then
        echo "FAIL  $1  (doesn't compile)"
        grep -m1 'error' errors.txt | sed 's/^/      /'
        rm -f errors.txt
        return 1
    fi
    rm -f errors.txt
}

check() {   # check PROGRAM.c EXPECTED_OUTPUT
    local src="$1" expected="$2" got
    total=$((total + 1))
    build "$src" || return
    got=$(timeout 2 ./"${src%.c}" 2>&1)
    [ $? -ge 128 ] && got="$got (the program crashed)"
    if [ "$got" = "$expected" ]; then
        echo "PASS  $src"
        pass=$((pass + 1))
    else
        echo "FAIL  $src"
        echo "      expected: $expected"
        echo "      got:      $got"
    fi
}

check_error() {   # check PROGRAM.c EXPECTED_STDERR: nothing on stdout, exit code 1
    local src="$1" expected="$2" out err code
    total=$((total + 1))
    build "$src" || return
    out=$(timeout 2 ./"${src%.c}" 2> stderr.txt)
    code=$?
    err=$(cat stderr.txt)
    rm -f stderr.txt
    if [ "$err" = "$expected" ] && [ -z "$out" ] && [ "$code" -eq 1 ]; then
        echo "PASS  $src"
        pass=$((pass + 1))
    else
        echo "FAIL  $src"
        echo "      expected: stderr \"$expected\", no other output, exit code 1"
        echo "      got:      stderr \"$err\", output \"$out\", exit code $code"
    fi
}

check 01_percent_f.c "FV = 10300.00"
check 02_equation.c "PV = 373563.90"
check 03_sscanf.c "2 matched: PV is -10000.00"
check 04_strcmp.c "PV = 0.00, PMT = 5.00"
check 05_global.c "N = 12"
check_error 06_exit_code.c "line 3: I must be positive"

echo
echo "$pass / $total programs fixed"
