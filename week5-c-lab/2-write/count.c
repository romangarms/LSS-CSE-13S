// Counts the kinds of chars that come in on stdin, until EOF.
//
// Goal:
//   ./count < poem.txt         prints   lowercase: 56
//                                       uppercase: 6
//                                       digits:    3
//                                       lines:     4
// You can also run plain  ./count , type a few lines, then press Ctrl-D at the start of a
// new line. Ctrl-D is how you type "end of input" (EOF) in the terminal.
//
// Fill in the loop in main(): read one char at a time with getchar() until EOF, and add
// to the right counter. A "line" is one '\n' char.
//
// Hints:
//   man 3 getchar   (Lecture 10). Look for RETURN VALUE: what does it give you at the end?
//   Store what getchar() gives you in an int, not a char. The RETURN VALUE section says why.
//   Lowercase means between 'a' and 'z'. What are the ranges for the other two?
//   Then try  ./count < ../../asgn3/tester.txt  That file is how asgn3's tests type
//   guesses into hangman for you: one char per line.
#include <stdio.h>

int main(void) {
    int lowercase = 0;
    int uppercase = 0;
    int digits = 0;
    int lines = 0;

    // your code here

    // Do not modify the rest of main.
    printf("lowercase: %d\n", lowercase);
    printf("uppercase: %d\n", uppercase);
    printf("digits:    %d\n", digits);
    printf("lines:     %d\n", lines);
    return 0;
}
