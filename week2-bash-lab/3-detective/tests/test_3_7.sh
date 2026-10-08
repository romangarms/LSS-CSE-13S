#!/usr/bin/env bash
# Example test: "max 3 7" should print 7 and exit with code 0.
# Copy this file to make a new test:  cp test_3_7.sh test_YOURNAME.sh
# Then change the three marked lines.

./max 3 7 > got.txt          # (1) the command to run
status=$?

echo 7 > expected.txt        # (2) the output a CORRECT max would print

if [ "$status" -ne 0 ]; then # (3) the exit code a correct max would give: -ne 0 means "fail if it's not 0"
    echo "FAIL: wrong exit code ($status)"
    exit 1
fi

if ! diff -q got.txt expected.txt > /dev/null; then
    echo "FAIL: wrong output"
    exit 1
fi

echo "PASS"
exit 0
