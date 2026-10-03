#!/usr/bin/env bash
# Should print which number is bigger.
# ./06_compare.sh 9 10   ->   10 is bigger
# ./06_compare.sh 12 3   ->   12 is bigger
# Careful: run `ls` after you try this one. Notice anything new?
if [ "$1" > "$2" ]
then
    echo "$1 is bigger"
else
    echo "$2 is bigger"
fi
