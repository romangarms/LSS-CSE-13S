// Which letters does a phrase use, and which does it skip?
//
// Goal:
//   ./letters "hello world"        prints   used:   dehlorw
//                                           unused: abcfgijkmnpqstuvxyz
//   ./letters "Fox & Dog!"         prints   used:   gox
//                                           unused: abcdefhijklmnpqrstuvwyz
//   ./letters                      prints   usage: ./letters "PHRASE"   to stderr, exit code 1
// Only lowercase letters count: F, D, &, ! and spaces are skipped.
//
// Part 1: fill in mark_letters(). It sets seen[] to 1 for every lowercase letter in phrase.
// Part 2: fill in print_letters(). It prints, in alphabetical order, every letter whose
//         seen[] value equals want. main() calls it twice: once for 1 (used), once for 0 (unused).
//
// Hints:
//   seen[] is a set (Lecture 12, "Using an Array as a Set"). Which slot is 'a'? Which is 'z'?
//   What number is  'c' - 'a' ?  Try printing it with %d.
//   Lowercase means between 'a' and 'z'. Write the comparison yourself, no islower().
//   For alphabetical order, which should Part 2 loop over: the phrase, or the set?
//   Going the other way, from a slot number back to a letter, is the same math in reverse.
#include <stdio.h>
#include <stdlib.h>

void mark_letters(const char *phrase, int seen[]) {
    // Part 1: your code here
}

void print_letters(const int seen[], int want) {
    // Part 2: your code here
}

// Do not modify this function.
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s \"PHRASE\"\n", argv[0]);
        return 1;
    }
    int seen[26] = { 0 };
    mark_letters(argv[1], seen);
    printf("used:   ");
    print_letters(seen, 1);
    printf("\nunused: ");
    print_letters(seen, 0);
    printf("\n");
    return 0;
}
