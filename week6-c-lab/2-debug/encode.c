// encode: writes a text file in "number code", where some common letters become digits.
// It compiles, but encode.c has 2 bugs and decode.c has 2 more (4 in all).
//
// How it works (like asgn5's compress, but the output is plain text):
//   - Look each char up in letter[]. If letter[d] is the char, write the digit d instead.
//     'e' is letter[3], so "meet" becomes "m337".
//   - A real digit in the file gets a '#' in front of it, so decode can tell it apart:
//     "10" becomes "#1#0". (asgn5 does the same thing with its 15 nibble.)
//   - Every other char is copied as is.
//
// The correct result:
//   $ ./encode note.txt -o note.code
//   $ cat note.code
//   M337 m3 47 7h3 c4f3 47 #1#0 0'cl0ck.
//   Br1n6 #2 p3nc1l5 4nd 7h3 l48 n0735!
//   $ diff -us expected.code note.code
//   Files expected.code and note.code are identical
//
// What should always be true:
//   - Every digit in note.txt has a '#' in front of it in note.code.
//   - `./encode in -o out` runs. Anything else prints the usage message and exits with 1.
//
// Hints:
//   Add printf() lines that show each char and what gets written for it. Which line of
//   note.code is the first to differ from expected.code?
//   What does strcmp() return when the two strings are the same?
//   Which digits does the "is it a digit?" check let through?
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// letter[d] is the letter that the digit d stands for.
const char letter[10] = { 'o', 'i', 'z', 'e', 'a', 's', 'g', 't', 'b', 'q' };

// Do not modify this function.
void print_usage(void) {
    fprintf(stderr, "Usage: ./encode infile -o outfile\n");
    exit(1);
}

// Writes the code for one char to f.
void encode_char(int ch, FILE *f) {
    if (ch > '0' && ch <= '9') {
        fputc('#', f);
        fputc(ch, f);
        return;
    }
    for (int d = 0; d < 10; d++) {
        if (letter[d] == ch) {
            fputc('0' + d, f);
            return;
        }
    }
    fputc(ch, f);
}

int main(int argc, char *argv[]) {
    if (argc != 4 || strcmp(argv[2], "-o") == 0) {
        print_usage();
    }

    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL) {
        fprintf(stderr, "Can't open file for input: %s\n", argv[1]);
        exit(1);
    }
    FILE *fout = fopen(argv[3], "w");
    if (fout == NULL) {
        fprintf(stderr, "Can't open file for output: %s\n", argv[3]);
        exit(1);
    }

    while (1) {
        int ch = fgetc(fin);
        if (ch == EOF) {
            break;
        }
        encode_char(ch, fout);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
