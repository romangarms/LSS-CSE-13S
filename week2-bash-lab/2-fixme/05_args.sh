#!/usr/bin/env bash
# Should print every argument on its own line.
# ./05_args.sh red green blue   ->   red
#                                    green
#                                    blue
for word in $1
do
    echo "$word"
done
