/*
* File:     nibbler.c
*
* Purpose:  Normally files are read and written one byte at a time, but
*           these routines let us read and write files one nibble (4 bits)
*           at a time.
*/

#include "nibbler.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


NIB *nib_open(const char *filename, const char *mode) {
    return NULL;
}


int nib_get_nibble(NIB *nib) {
    return 0;
}


void nib_put_nibble(int nibble, NIB *nib) {
}


void nib_close(NIB *nib) {
}
