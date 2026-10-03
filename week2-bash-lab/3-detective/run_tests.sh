#!/usr/bin/env bash
# Runs every tests/test_*.sh against the reference max and every mystery max.
# Usage: bash run_tests.sh
cd "$(dirname "$0")" || exit 1
programs="reference/max $(ls mystery/* | tr '\n' ' ')"

# run_one PROGRAM TEST  -> exit 0 if the test passes on that program
run_one() {
    local dir
    dir=$(mktemp -d)
    cp "$1" "$dir/max"
    chmod +x "$dir/max"
    cp "$2" "$dir/test.sh"
    (cd "$dir" && bash test.sh > /dev/null 2>&1)
    local result=$?
    rm -rf "$dir"
    return $result
}

printf "%-22s" "test"
printf "%-8s" "REF"
for p in $(ls mystery); do printf "%-8s" "$p"; done
echo
caught=""
for t in tests/test_*.sh; do
    printf "%-22s" "$(basename "$t")"
    if ! run_one reference/max "$t"; then
        echo "INVALID: fails the correct reference max, so it can't be used"
        continue
    fi
    for p in $programs; do
        if run_one "$p" "$t"; then
            printf "%-8s" "pass"
        else
            printf "%-8s" "FAIL"
            caught="$caught $(basename "$p")"
        fi
    done
    echo
done
echo
echo "Mystery versions caught by at least one valid test:"
echo "$caught" | tr ' ' '\n' | sort -u | grep -v '^$' | sed 's/^/  /'
