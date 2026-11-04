// tohex: writes every byte of a file as two hex digits, the same way `xxd -p` does.
// It compiles, but tohex.c has 2 bugs and fromhex.c has 2 more (4 in all).
//
// How it works:
//   - Each byte is split into its high nibble and its low nibble (asgn5 sections 3.1.3, 3.1.4).
//   - Each nibble (0 to 15) is looked up in hex_digit[], high nibble first.
//     'H' is 0x48, so it becomes the two chars "48".
//   - After every 30 bytes (60 hex digits) it starts a new line, and the file ends with '\n'.
//
// The correct result:
//   $ ./tohex note.txt -o note.hex
//   $ cat note.hex
//   4d656574206d652061742074686520636166c3a9206174206e6f6f6e2e0a
//   4272696e672074686520686578206e6f7465732c20616e6420612070656e
//   63696c210a
//   $ xxd -p note.txt | diff - note.hex       (no output means they match)
//
// What should always be true:
//   - Every nibble is a number from 0 to 15.
//   - `./tohex in -o out` runs. Anything else prints the usage message and exits with 1.
//
// Hints:
//   Add printf() lines that show ch, high and low for each byte. Look at the first byte whose
//   digits don't match `xxd -p`. Is high a number from 0 to 15?
//   asgn5 section 3.1.4 has a warning about shifting a plain char.
//   What does strcmp() return when the two strings are the same?
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_PER_LINE 30

const char hex_digit[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
                             '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

// Do not modify this function.
void print_usage(void) {
    fprintf(stderr, "Usage: ./tohex infile -o outfile\n");
    exit(1);
}

// Writes the two hex digits of one byte to f, high nibble first.
void write_byte(int ch, FILE *f) {
    char byte = ch;
    int high = byte >> 4;
    int low = byte & 0b00001111;
    fputc(hex_digit[high], f);
    fputc(hex_digit[low], f);
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

    int count = 0;
    while (1) {
        int ch = fgetc(fin);
        if (ch == EOF) {
            break;
        }
        write_byte(ch, fout);
        count++;
        if (count % BYTES_PER_LINE == 0) {
            fputc('\n', fout);
        }
    }
    if (count % BYTES_PER_LINE != 0) {
        fputc('\n', fout);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
