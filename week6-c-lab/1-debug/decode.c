// decode: the reverse of encode. Turns "number code" back into the original text.
// It compiles, but it has 2 bugs (encode.c has the other 2).
//
// How it works (like asgn5's decompress):
//   - A digit d stands for letter[d], so "m337" becomes "meet".
//   - A '#' means the next char is a real digit: copy it as is. "#1#0" becomes "10".
//   - If the file ends right after a '#', ignore the '#', the same way asgn5's decompress
//     ignores a 15 nibble at the end of the file.
//   - Every other char is copied as is.
//
// The correct result:
//   $ ./decode expected.code -o note.out
//   $ diff -us note.txt note.out
//   Files note.txt and note.out are identical
//   $ ./decode cut.code -o cut.out && cat cut.out
//   See you at 
//   (cut.code ends with a '#'. cut.out ends with "at " and nothing after it.)
//
// What should always be true:
//   - letter[] is only ever read with an index from 0 to 9.
//   - Every char written comes from a char that is really in the file.
//
// Hints:
//   Add printf() lines that show each char read and the char written for it.
//   For the digit '3', what index does the code use for letter[]? What should it be?
//   Compare the '#' part with asgn5's decompress() pseudocode (Figure 3). How many EOF checks?
//   cat -A cut.out shows chars you can't normally see.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// letter[d] is the letter that the digit d stands for.
const char letter[10] = { 'o', 'i', 'z', 'e', 'a', 's', 'g', 't', 'b', 'q' };

// Do not modify this function.
void print_usage(void) {
    fprintf(stderr, "Usage: ./decode infile -o outfile\n");
    exit(1);
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
        int ch = fgetc(fin);
        if (ch == EOF) {
            break;
        }
        if (ch == '#') {
            int next = fgetc(fin);
            fputc(next, fout);
        } else if (ch >= '0' && ch <= '9') {
            fputc(letter[ch], fout);
        } else {
            fputc(ch, fout);
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
