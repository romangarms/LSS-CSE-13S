#!/usr/bin/env bash
# Number-conversion practice quiz (8-bit values).
# Usage: bash quiz.sh [number_of_questions]      (default 10, type q to quit)
# Answers may include spaces and prefixes: "0101 1111", "0x5f", "0b101", "0137" are all fine.

total=${1:-10}
score=0
asked=0

bin8() {   # bin8 N  -> 8-bit binary with a space in the middle, e.g. "0101 1111"
    local n=$1 s="" i
    for ((i = 7; i >= 0; i--)); do
        s="$s$(( (n >> i) & 1 ))"
        [ "$i" -eq 4 ] && s="$s "
    done
    echo "$s"
}

clean() {  # strip spaces and underscores, lowercase
    echo "$1" | tr -d ' _' | tr 'A-F' 'a-f'
}

# parse BASE ANSWER -> prints the value, or nothing if it isn't valid in that base
parse() {
    local base=$1 a sign=""
    a=$(clean "$2")
    case $base in
        2)  a=${a#0b}; [[ $a =~ ^[01]+$ ]] && echo $((2#$a)) ;;
        8)  [[ $a =~ ^[0-7]+$ ]] && echo $((8#$a)) ;;
        16) a=${a#0x}; [[ $a =~ ^[0-9a-f]+$ ]] && echo $((16#$a)) ;;
        10) if [[ $a == -* ]]; then sign="-"; a=${a#-}; fi
            [[ $a =~ ^[0-9]+$ ]] && echo "$sign$((10#$a))" ;;
    esac
}

echo "Number conversion quiz: $total questions. Type q to quit."
echo "No calculator! Work it out on paper, just like on the quiz."
echo

while [ "$asked" -lt "$total" ]; do
    n=$((RANDOM % 256))
    kind=$((RANDOM % 8))
    signed=$(( n >= 128 ? n - 256 : n ))
    case $kind in
        0) q="Convert 0b$(bin8 $n | tr -d ' ') to hexadecimal";     base=16; want=$n; show=$(printf '0x%02X' $n) ;;
        1) q="Convert $(printf '0x%02X' $n) to 8-bit binary";       base=2;  want=$n; show=$(bin8 $n) ;;
        2) q="Convert 0b$(bin8 $n | tr -d ' ') to octal";           base=8;  want=$n; show=$(printf '0%o' $n) ;;
        3) q="Convert $(printf '0%o' $n) (C octal) to 8-bit binary"; base=2; want=$n; show=$(bin8 $n) ;;
        4) q="Convert $(printf '0x%02X' $n) to UNSIGNED decimal";   base=10; want=$n; show=$n ;;
        5) q="Convert $n (decimal) to 8-bit binary";                base=2;  want=$n; show=$(bin8 $n) ;;
        6) q="Convert $(printf '0x%02X' $n) to SIGNED 8-bit decimal (two's complement)"; base=10; want=$signed; show=$signed ;;
        7) [ "$signed" -ge 0 ] && { n=$((n | 128)); signed=$((n - 256)); }
           q="Convert $signed to 8-bit two's complement hexadecimal"; base=16; want=$n; show=$(printf '0x%02X' $n) ;;
    esac
    echo "Q$((asked + 1)). $q"
    read -r -p "> " answer || break
    [ "$answer" = "q" ] && break
    asked=$((asked + 1))
    got=$(parse $base "$answer")
    if [ -n "$got" ] && [ "$got" -eq "$want" ]; then
        echo "  Correct!"
        score=$((score + 1))
    else
        echo "  Not quite. Answer: $show    (binary: $(bin8 $n))"
    fi
    echo
done

echo "Score: $score / $asked"
