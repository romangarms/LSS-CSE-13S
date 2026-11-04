// Write the three functions below. numlines.c (already done) uses them.
//
// The rules:
//   lw_open(filename):
//     - Opens filename for writing with fopen(). If fopen() fails, return NULL.
//     - Otherwise allocate an LW struct with calloc(), set its fields so the first
//       char written starts line 1, and return it.
//   lw_putc(ch, lw):
//     - If ch is the first char of a line, first write the line number like this:
//       fprintf(lw->underlying_f, "%3d | ", lw->line_number);
//     - Then write ch.
//     - A '\n' ends the line, so the next char starts the next line.
//   lw_close(lw):
//     - If the last line didn't end with '\n', write one, so the file always ends with '\n'.
//     - Close the file and free the struct.
//
// The correct result:
//   $ make
//   $ ./numlines todo.txt -o todo.out
//   $ diff -us expected.txt todo.out
//   Files expected.txt and todo.out are identical
//   $ ./numlines todo.txt -o nofolder/todo.out
//   Can't open file for output: nofolder/todo.out        (and the exit code, echo $?, is 1)
//
// Hints:
//   This is the same shape as asgn5's nibbler. Reread the nib_open() and nib_close()
//   pseudocode (asgn5 sections 3.2.1, 3.2.2) for which calls go in which order.
//   The struct keeps its fields between calls. Which field tells lw_putc() what happened
//   on the call before?
//   todo.txt's last line has no '\n' on purpose. Check it with: tail -c 5 todo.txt | od -c
#include "linewriter.h"

#include <stdlib.h>

LW *lw_open(const char *filename) {
    // Write this function.
    return NULL;
}

void lw_putc(int ch, LW *lw) {
    // Write this function.
}

void lw_close(LW *lw) {
    // Write this function.
}
