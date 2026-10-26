// Sorts each char you type into a type: lowercase, uppercase, digit, space, or other.
//
// Goal: type a line, press Enter, and it counts that line:
//   Type a line (Ctrl-D to quit): Hello World 42!
//   lowercase: 8  uppercase: 2  digits: 2  spaces: 2  other: 1
//   Type a line (Ctrl-D to quit): CSE13s rocks
//   lowercase: 6  uppercase: 3  digits: 2  spaces: 1  other: 0
//   Type a line (Ctrl-D to quit):            <- press Ctrl-D here to quit
//
// main() already reads the input one char at a time with getchar(). Fill in
// count_char(): look at ch, decide which type it is, and add 1 to the right counter.
//
// Hints:
//   Lowercase means between 'a' and 'z'. Write the comparison yourself, no islower().
//   What are the ranges for uppercase and for digits?
//   A space is the char ' '. Anything that isn't one of the first four types is "other".
//   Each char should land in exactly one counter. Which kind of if chain does that?
#include <stdio.h>

// The counters. count_char() adds to them, and main() prints and resets them.
int lowercase = 0;
int uppercase = 0;
int digits = 0;
int spaces = 0;
int other = 0;

void count_char(int ch) {
    // your code here
}

// Do not modify this function.
int main(void) {
    printf("Type a line (Ctrl-D to quit): ");
    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            printf("lowercase: %d  uppercase: %d  digits: %d  spaces: %d  other: %d\n",
                lowercase, uppercase, digits, spaces, other);
            lowercase = uppercase = digits = spaces = other = 0;
            printf("Type a line (Ctrl-D to quit): ");
        } else {
            count_char(ch);
        }
    }
    printf("\n");
    return 0;
}
