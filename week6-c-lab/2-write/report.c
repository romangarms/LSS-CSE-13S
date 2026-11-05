// report: counts the chars, lines and digits in a file and writes them to another file.
// Usage: ./report infile -o outfile      (the README has the commands to test it)
//
// Write all of main(). If anything goes wrong, print a message to stderr and exit(1):
//   wrong arguments:        Usage: ./report infile -o outfile
//   can't open infile:      Can't open file for input: INFILE
//   can't open outfile:     Can't open file for output: OUTFILE
// For shopping.txt, the output file should be exactly expected.txt:
//   chars: 72
//   lines: 3
//   digits: 8
//
// Keep the three counts in one Report variable (the struct below), then write the report
// from it.
//
// Hints: your fixed redact.c has the file calls. Compare strings with strcmp(), not ==.
// fprintf() can write to any FILE *, not just stderr.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Do not modify this type.
typedef struct {
    int chars;
    int lines;
    int digits;
} Report;

int main(int argc, char *argv[]) {
    // Write your program here.

    return 0;
}
