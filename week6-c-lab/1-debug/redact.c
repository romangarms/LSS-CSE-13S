// redact: copies note.txt to note.out, but every digit becomes '*' (to hide phone numbers).
//
// This program is short on purpose: it opens one file to read and one to write, copies the
// chars, and closes both files. It has no error checks (you'll write those in Level 2).
// The copying part is just the `if` inside the loop and it's correct. The 3 bugs are all
// in the file calls: fopen(), fgetc(), fputc() and fclose().
//
// The correct result:
//   $ ./redact
//   $ cat note.out
//   Call me at ***-***-**** after * pm.
//   The locker code is ****.
//   $ diff -us expected.txt note.out
//   Files expected.txt and note.out are identical
//
// Hints:
//   Compare each file call with read_file_example.c and write_file_example.c (asgn5
//   sections 3.1.1 and 3.1.2). Check each mode string, which file each char goes to, and
//   when the loop checks for EOF.
//   "Segmentation fault" here means a FILE * is NULL. Which fopen() could have failed, and why?
//   cat -A note.out shows chars you can't normally see, like an extra one at the end.
#include <stdio.h>

int main(void) {
    FILE *fin = fopen("note.txt", "r");
    FILE *fout = fopen("note.out", "r");

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
