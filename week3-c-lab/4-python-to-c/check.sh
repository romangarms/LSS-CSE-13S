#!/usr/bin/env bash
# Runs each Python program and your C translation, and checks they print the same thing.
# Usage: bash check.sh
cd "$(dirname "$0")" || exit 1
CC=$(command -v clang || command -v cc)
pass=0

for name in countdown evens total smaller triangle; do
    # Spaces at the end of a line are invisible, so they don't count.
    want=$(python3 "$name.py" | sed 's/ *$//')
    if ! "$CC" "$name.c" -o "$name" 2> errors.txt; then
        echo "FAIL  $name.c  (doesn't compile)"
        grep -m1 'error' errors.txt | sed 's/^/      /'
    else
        got=$(timeout 2 ./"$name" | sed 's/ *$//')
        if [ "$got" = "$want" ]; then
            echo "PASS  $name.c"
            pass=$((pass + 1))
        else
            echo "FAIL  $name.c"
            echo "$want" | sed 's/^/      python prints | /'
            echo "$got" | sed 's/^/      your C prints | /'
        fi
    fi
    rm -f errors.txt
done

echo
echo "$pass / 5 translated"
