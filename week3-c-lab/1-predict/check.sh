#!/usr/bin/env bash
# Compiles and runs each program, then compares its output to your prediction.
# Usage: bash check.sh
cd "$(dirname "$0")" || exit 1
CC=$(command -v clang || command -v cc)
right=0

# Squeeze runs of spaces and trim the ends, so "4 4" and "4  4 " count as the same.
tidy() { tr -s ' ' | sed 's/^ *//; s/ *$//'; }

for n in 1 2 3 4 5 6; do
    guess=$(grep "^p$n:" predictions.txt | cut -d: -f2- | tidy)
    if [ -z "$guess" ]; then
        echo "p$n  no prediction yet (write one in predictions.txt first)"
        continue
    fi
    "$CC" "p$n.c" -o "p$n" || exit 1
    got=$(./"p$n" | tidy)
    if [ "$guess" = "$got" ]; then
        echo "p$n  RIGHT  $got"
        right=$((right + 1))
    else
        echo "p$n  WRONG  you said: $guess"
        echo "           it printed: $got"
    fi
done

echo
echo "$right / 6 predicted correctly"
echo "Got one wrong? Edit the program and re-run it until you can explain why."
