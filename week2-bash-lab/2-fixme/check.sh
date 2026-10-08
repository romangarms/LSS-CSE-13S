#!/usr/bin/env bash
# Runs each fixme script and says whether it now behaves correctly.
# Usage: bash check.sh
cd "$(dirname "$0")" || exit 1
pass=0
total=0
failures=""

check() {   # check SCRIPT EXPECTED_OUTPUT ARGS...
    local script="$1" expected="$2" got
    shift 2
    got=$(bash "$script" "$@" 2>&1)
    if [ "$got" != "$expected" ]; then
        failures+="      bash $script $*
      expected: $(echo "$expected" | tr '\n' '|')
      got:      $(echo "$got" | tr '\n' '|')
"
    fi
}

# A script passes only when every one of its cases passes: some bugs only
# show up for certain arguments, so a broken script can get single cases right.
report() {   # report SCRIPT
    total=$((total + 1))
    if [ -z "$failures" ]; then
        echo "PASS  $1"
        pass=$((pass + 1))
    else
        echo "FAIL  $1"
        printf '%s' "$failures"
    fi
    failures=""
}

check 01_variable.sh "Hello, Sammy"
report 01_variable.sh

check 02_quotes.sh "Total: 3 files"
report 02_quotes.sh

check 03_brackets.sh "usage: ./03_brackets.sh name"
check 03_brackets.sh "hi sammy" sammy
report 03_brackets.sh

check 04_exitcode.sh "searching...
grep exit code: 1"
report 04_exitcode.sh

check 05_args.sh "red
green
blue" red green blue
report 05_args.sh

check 06_compare.sh "10 is bigger" 9 10
check 06_compare.sh "12 is bigger" 12 3
report 06_compare.sh
rm -f 10 3   # files that the 06 bug creates by accident

echo
echo "$pass / $total scripts fixed"
