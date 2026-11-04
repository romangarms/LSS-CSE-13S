// shout: copies a text file in ALL CAPS, then says how many chars and lines it copied.
// Usage: ./shout infile -o outfile
//
// You write the three TODO parts in main(). The argv check is done.
//   TODO 1: Open argv[1] for reading and argv[3] for writing with fopen().
//           If either one fails, print the error message shown below to stderr and exit(1).
//   TODO 2: Read the input one char at a time until EOF. Write each char to the output
//           in uppercase (toupper() from Lecture 10). Count the chars and the '\n's.
//   TODO 3: Close both files, then print the counts.
//
// The correct result:
//   $ ./shout poem.txt -o poem.out
//   Copied 86 chars, 4 lines
//   $ diff -us expected.txt poem.out
//   Files expected.txt and poem.out are identical
//   $ ./shout nope.txt -o poem.out; echo $?
//   Can't open file for input: nope.txt
//   1
//   $ ./shout poem.txt -o nofolder/poem.out; echo $?
//   Can't open file for output: nofolder/poem.out
//   1
//
// Hints:
//   asgn5 section 3.1.1 (read_file_example.c) and 3.1.2 (write_file_example.c) show every
//   call you need, in order. The difference is that this program uses both files at once.
//   What type should the variable that holds fgetc()'s return value be? Why? (section 3.1.1)
//   fputc() is like putchar(), but you also tell it which file.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Do not modify this function.
void print_usage(void) {
    fprintf(stderr, "Usage: ./shout infile -o outfile\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    // Do not modify this check.
    if (argc != 4 || strcmp(argv[2], "-o") != 0) {
        print_usage();
    }

    // TODO 1: open the input and output files.

    // TODO 2: copy the input to the output in uppercase, counting chars and lines.

    // TODO 3: close the files and print "Copied N chars, M lines".

    return 0;
}
