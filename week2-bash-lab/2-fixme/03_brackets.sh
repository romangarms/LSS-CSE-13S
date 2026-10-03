#!/usr/bin/env bash
# With no argument, should print:   usage: ./03_brackets.sh name
# With an argument, should print:   hi NAME     (for example: hi sammy)
if ["$1" = ""]
then
    echo "usage: ./03_brackets.sh name"
    exit 1
fi
echo "hi $1"
