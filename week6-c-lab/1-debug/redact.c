// redact: copies a text file, but every digit becomes '*' (to hide phone numbers and PINs).
// Usage: ./redact infile -o outfile
//
// The copying part is simple and correct: it's the one `if` inside the loop.
// The bugs (4 of them) are all in the file calls: fopen(), the NULL checks, fgetc(),
// fputc() and fclose(). Fix them so every check below passes.
//
// The correct result:
//   $ ./redact note.txt -o note.out
//   $ cat note.out
//   Call me at ***-***-**** after * pm.
//   The locker code is ****.
//   $ diff -us expected.txt note.out
//   Files expected.txt and note.out are identical
//   $ ./redact nope.txt -o note.out; echo $?
//   Can't open file for input: nope.txt
//   1
//
// Hints:
//   Compare each file call with read_file_example.c and write_file_example.c (asgn5
//   sections 3.1.1 and 3.1.2). Check the mode string, which variable is checked for NULL,
//   which file the char goes to, and when the loop checks for EOF.
//   cat -A note.out shows chars you can't normally see, like an extra one at the end.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Do not modify this function.
void print_usage(void) {
    fprintf(stderr, "Usage: ./redact infile -o outfile\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 4 || strcmp(argv[2], "-o") != 0) {
        print_usage();
    }

    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[3], "r");
    if (fout == NULL) {
        fprintf(stderr, "Can't open file for input: %s\n", argv[1]);
        exit(1);
    }
    if (fout == NULL) {
        fprintf(stderr, "Can't open file for output: %s\n", argv[3]);
        exit(1);
    }

    int ch = 0;
    while (ch != EOF) {
        ch = fgetc(fin);
        if (ch >= '0' && ch <= '9') {
            ch = '*';
        }
        putchar(ch);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
