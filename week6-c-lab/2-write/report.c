// report: reads a text file and writes a short report about it to another file.
// Usage: ./report infile -o outfile
//
// You write all of main(). Use your fixed redact.c (Level 1) and asgn5's
// read_file_example.c to remember the file calls. What's new here is the error handling.
//
// The rules:
//   1. If the command line isn't exactly `./report infile -o outfile`, print the usage
//      message below to stderr and exit with 1.
//   2. Open infile to read. If that fails, print "Can't open file for input: INFILE"
//      to stderr and exit with 1.
//   3. Open outfile to write. If that fails, print "Can't open file for output: OUTFILE"
//      to stderr and exit with 1.
//   4. Read infile one char at a time and count its chars, lines ('\n') and digits.
//   5. Write the report to outfile in exactly this format, then close both files:
//        chars: 72
//        lines: 3
//        digits: 8
//
// The correct result:
//   $ ./report shopping.txt -o report.out
//   $ diff -us expected.txt report.out
//   Files expected.txt and report.out are identical
//   $ ./report shopping.txt report.out; echo $?
//   Usage: ./report infile -o outfile
//   1
//   $ ./report nope.txt -o report.out; echo $?
//   Can't open file for input: nope.txt
//   1
//   $ ./report shopping.txt -o nofolder/report.out; echo $?
//   Can't open file for output: nofolder/report.out
//   1
//
// Hints:
//   argc counts the program name too. How many words is `./report shopping.txt -o report.out`?
//   You can't compare strings with ==. Which function from asgn2 compares two strings?
//   fopen() returns NULL when it fails. Check it before you use the FILE *.
//   fprintf(stderr, ...) prints an error. fprintf() can write to any FILE *, so the same
//   function can write the report to your output file.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Write your program here.

    return 0;
}
