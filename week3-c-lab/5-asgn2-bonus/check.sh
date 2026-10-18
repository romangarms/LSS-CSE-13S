#!/usr/bin/env bash
# Compiles and runs each challenge and checks its normal output (stdout),
# its error output (stderr), and its exit code.
# Usage: bash check.sh
cd "$(dirname "$0")" || exit 1
CC=$(command -v clang || command -v cc)
pass=0
total=0

check() {   # check PROGRAM.c EXPECTED_STDOUT EXPECTED_STDERR EXPECTED_EXIT_CODE
    local src="$1" out="$2" err="$3" code="$4" prog="${1%.c}" got_out got_err got_code
    total=$((total + 1))
    if ! "$CC" -lm "$src" -o "$prog" 2> errors.txt; then
        echo "FAIL  $src  (doesn't compile)"
        grep -m1 'error' errors.txt | sed 's/^/      /'
        rm -f errors.txt
        return
    fi
    got_out=$(timeout 2 ./"$prog" 2> errors.txt)
    got_code=$?
    got_err=$(cat errors.txt)
    rm -f errors.txt
    if [ "$got_out" = "$out" ] && [ "$got_err" = "$err" ] && [ "$got_code" = "$code" ]; then
        echo "PASS  $src"
        pass=$((pass + 1))
        return
    fi
    echo "FAIL  $src"
    if [ "$got_out" != "$out" ]; then
        echo "$out" | sed 's/^/      stdout goal | /'
        echo "$got_out" | sed 's/^/      stdout got  | /'
    fi
    if [ "$got_err" != "$err" ]; then
        echo "      stderr goal | $err"
        echo "$got_err" | sed 's/^/      stderr got  | /'
    fi
    if [ "$got_code" != "$code" ]; then
        echo "      exit code goal $code, got $got_code"
    fi
}

check robot.c "robot says: hello
at (0.0, 0.0)
at (3.0, -1.5)
at (5.0, -1.5)
at (5.0, -1.5)
at (0.0, 0.0)" "line 6: invalid command" 1
check pizza.c "3 pizzas, 4 people: 6.00 slices each
2 pizzas, 3 people: 5.33 slices each" "people must be a positive integer" 1
check newton.c "sqrt(2) = 1.414214
sqrt(81) = 9.000000" "did not converge" 1

echo
echo "$pass / $total challenges done"
