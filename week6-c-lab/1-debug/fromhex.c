// fromhex: the reverse of tohex. Reads hex digits two at a time and writes the byte they make.
// It compiles, but it has 2 bugs (tohex.c has the other 2).
//
// How it works:
//   - Newlines in the hex file are skipped.
//   - Each pair of hex digits is turned back into one byte: the first digit is the high
//     nibble and the second is the low nibble (asgn5 section 3.1.5). "48" becomes 'H'.
//   - If the file ends in the middle of a pair (an odd number of digits), the last lone
//     digit is ignored, the same way asgn5's decompress ignores an unfinished 15 nibble.
//
// The correct result:
//   $ ./fromhex note.hex -o note.out
//   $ diff -us note.txt note.out
//   Files note.txt and note.out are identical
//   $ ./fromhex odd.hex -o odd.out && cat odd.out
//   Hi!
//
// What should always be true:
//   - digit_value() returns a number from 0 to 15 for every hex digit '0'-'9' and 'a'-'f'.
//   - Every byte written comes from two digits that are really in the file.
//
// Hints:
//   Add printf() lines that show c1, c2 and the byte for each pair. Which pairs come out wrong?
//   What should digit_value('a') be? What does it return?
//   Compare the loop with asgn5's decompress() pseudocode (Figure 3). How many EOF checks?
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Do not modify this function.
void print_usage(void) {
    fprintf(stderr, "Usage: ./fromhex infile -o outfile\n");
    exit(1);
}

// Do not modify this function.
// Returns the next hex digit char in the file, skipping newlines, or EOF at the end.
int next_digit(FILE *f) {
    while (1) {
        int c = fgetc(f);
        if (c != '\n') {
            return c;
        }
    }
}

// Returns the value (0 to 15) of one hex digit char: '0'-'9' or 'a'-'f'.
int digit_value(int c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return c - 'a';
}

int main(int argc, char *argv[]) {
    if (argc != 4 || strcmp(argv[2], "-o") != 0) {
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
        int c1 = next_digit(fin);
        if (c1 == EOF) {
            break;
        }
        int c2 = next_digit(fin);
        int byte = (digit_value(c1) << 4) | digit_value(c2);
        fputc(byte, fout);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
