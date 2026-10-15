#!/usr/bin/env bash
# Compiles and runs each challenge and says whether it prints the goal.
# Compiles with -lm, like asgn2, because interest.c uses <math.h>.
# Usage: bash check.sh
cd "$(dirname "$0")" || exit 1
CC=$(command -v clang || command -v cc)
pass=0
total=0

check() {   # check PROGRAM.c EXPECTED_OUTPUT
    local src="$1" expected="$2" got
    total=$((total + 1))
    if ! "$CC" -lm "$src" -o "${src%.c}" 2> errors.txt; then
        echo "FAIL  $src  (doesn't compile)"
        grep -m1 'error' errors.txt | sed 's/^/      /'
    else
        got=$(timeout 2 ./"${src%.c}" 2>&1 | sed 's/ *$//')
        if [ "$got" = "$expected" ]; then
            echo "PASS  $src"
            pass=$((pass + 1))
        else
            echo "FAIL  $src"
            echo "$expected" | sed 's/^/      goal | /'
            echo "$got" | sed 's/^/      got  | /'
        fi
    fi
    rm -f errors.txt
}

check line.c "line(3.5) = 8.00
line(-2) = -3.00"
check commands.c "N = 0, I = 0.00
N = 12, I = 0.03
N = 0, I = 0.00
unknown command: jump"
check interest.c "loop: 1092.73   pow: 1092.73"

echo
echo "$pass / $total challenges done"
