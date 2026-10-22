// Two small string functions, tested with assert().
//
// Goal:
//   ./words    prints   all tests passed
//
// main() is a list of tests, like asgn2's unit tests. Each assert() stops the
// program, and tells you its line number, the first time a test fails. Fill in
// count_digits() and shout() until every test passes.
//
//   count_digits(s)  returns how many chars in s are digits 0-9
//   shout(s)         changes every lowercase letter in s to uppercase
//
// Hints:
//   When an assert fails, read the line number it prints, then look at that test.
//   Every string ends with the char '\0'. How can a loop use that to stop?
//   (strlen() from <string.h> works too.)
//   Lecture 10's ctype examples have a function for each job. What's it called?
//   s[i] is one char of s, and you can store into it like any variable.
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_digits(char s[]) {
    // your code here
    return 0;
}

void shout(char s[]) {
    // your code here
}

// Do not modify this function.
int main(void) {
    assert(count_digits("abc") == 0);
    assert(count_digits("R2-D2") == 2);
    assert(count_digits("2026") == 4);
    assert(count_digits("") == 0);

    char word[] = "hi there!";
    shout(word);
    assert(strcmp(word, "HI THERE!") == 0);
    assert(strlen(word) == 9);

    char mixed[] = "CSE 13s";
    shout(mixed);
    assert(strcmp(mixed, "CSE 13S") == 0);

    printf("all tests passed\n");
    return 0;
}
