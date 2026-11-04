// Do not modify this file.
//
// numlines: copies a text file, putting a line number in front of every line.
// Usage: ./numlines infile -o outfile
#include "linewriter.h"

#include <stdlib.h>
#include <string.h>

void print_usage(void) {
    fprintf(stderr, "Usage: ./numlines infile -o outfile\n");
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
    LW *lw = lw_open(argv[3]);
    if (lw == NULL) {
        fprintf(stderr, "Can't open file for output: %s\n", argv[3]);
        exit(1);
    }

    while (1) {
        int ch = fgetc(fin);
        if (ch == EOF) {
            break;
        }
        lw_putc(ch, lw);
    }

    fclose(fin);
    lw_close(lw);
    return 0;
}
