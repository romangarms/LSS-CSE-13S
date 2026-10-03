#!/usr/bin/env bash
# Runs each fixme script and says whether it now behaves correctly.
# Usage: bash check.sh
cd "$(dirname "$0")" || exit 1
pass=0
total=0

check() {   # check NAME EXPECTED_OUTPUT COMMAND...
    local name="$1" expected="$2"
    shift 2
    total=$((total + 1))
    got=$("$@" 2>&1)
    if [ "$got" = "$expected" ]; then
        echo "PASS  $name"
        pass=$((pass + 1))
    else
        echo "FAIL  $name"
        echo "      expected: $(echo "$expected" | tr '\n' '|')"
        echo "      got:      $(echo "$got" | tr '\n' '|')"
    fi
}

check "01 no args"   "Hello, Sammy"                     bash 01_variable.sh
check "02 no args"   "Total: 3 files"                   bash 02_quotes.sh
check "03 no args"   "usage: ./03_brackets.sh name"     bash 03_brackets.sh
check "03 sammy"     "hi sammy"                         bash 03_brackets.sh sammy
check "04 no args"   "searching...
grep exit code: 1"                                      bash 04_exitcode.sh
check "05 r g b"     "red
green
blue"                                                   bash 05_args.sh red green blue
check "06 9 10"      "10 is bigger"                     bash 06_compare.sh 9 10
check "06 12 3"      "12 is bigger"                     bash 06_compare.sh 12 3
rm -f 10 3   # files that the 06 bug creates by accident

echo
echo "$pass / $total checks passing"
