// Do not modify this file.
//
// A LW ("line writer") writes a text file with a line number in front of every line.
// You use it the way you use a FILE (or asgn5's NIB):
//
//   FILE *f = fopen(name, "w");    -->   LW *lw = lw_open(name);
//   fputc(ch, f);                  -->   lw_putc(ch, lw);
//   fclose(f);                     -->   lw_close(lw);

#include <stdbool.h>
#include <stdio.h>

typedef struct linewriter LW;

struct linewriter {
    FILE *underlying_f;  // The result of calling fopen().
    int line_number;     // The number of the line being written. The first line is 1.
    bool at_line_start;  // true when the next char written is the first char of a line.
};

LW *lw_open(const char *filename);
void lw_putc(int ch, LW *lw);
void lw_close(LW *lw);
