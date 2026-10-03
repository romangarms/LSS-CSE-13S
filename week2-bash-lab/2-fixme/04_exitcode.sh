#!/usr/bin/env bash
# grep exits with 1 when it finds no match.
# Should print:
#   searching...
#   grep exit code: 1
printf 'apple\nbanana\ncherry\n' > haystack.txt
grep -q needle haystack.txt
echo "searching..."
echo "grep exit code: $?"
rm -f haystack.txt
