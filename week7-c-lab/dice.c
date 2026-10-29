// Two dice functions that use an array as a set of ints.
//
// Goal:
//   ./dice    prints   all tests passed
//
// A die roll is a number from 1 to 6. main() is a list of tests. Each assert()
// stops the program, and tells you its line number, the first time a test fails.
// Fill in has_repeat() and count_missing() until every test passes.
//
//   has_repeat(rolls, n)      true if some number shows up more than once in rolls
//   count_missing(rolls, n)   how many of the faces 1-6 never show up in rolls
//
// Hints:
//   Lecture 12, "Using an Array as a Set": int my_set[10] holds the numbers 0 through 9.
//   How many slots does a set of die faces need? Which slot is the face 1, and which is 6?
//   For letters you used c - 'a' to pick a slot. What plays that role for a roll?
//   A local array starts out full of garbage unless you give it a starting value.
//   has_repeat(): what does the set already say about a roll when you see it the second time?
//   count_missing(): which should the second loop go over: the rolls, or the set?
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool has_repeat(const int rolls[], int n) {
    // your code here
    return false;
}

int count_missing(const int rolls[], int n) {
    // your code here
    return 0;
}

// Do not modify this function.
int main(void) {
    int straight[] = { 3, 1, 6, 2, 5, 4 };
    int pair[] = { 2, 5, 2 };
    int sixes[] = { 6, 6, 6, 6 };
    int one[] = { 1 };

    assert(has_repeat(straight, 6) == false);
    assert(has_repeat(pair, 3) == true);
    assert(has_repeat(sixes, 4) == true);
    assert(has_repeat(one, 1) == false);
    assert(has_repeat(pair, 2) == false);   // only looks at the first 2 rolls: 2, 5

    assert(count_missing(straight, 6) == 0);
    assert(count_missing(pair, 3) == 4);
    assert(count_missing(sixes, 4) == 5);
    assert(count_missing(one, 1) == 5);
    assert(count_missing(straight, 0) == 6);

    printf("all tests passed\n");
    return 0;
}
