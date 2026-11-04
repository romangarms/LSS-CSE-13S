#include <stdio.h>
#include <stdlib.h>

/*
* Purpose:          Print the contents of a file to the screen.
*
* Parameters:       filename -- the name of the file
*
* Returns:          nothing
*/
void read_file_example(const char *filename) {
    /*
    * Try to open the file with the name in filename.  Complain and exit if
    * we can't open the file.
    */
    FILE *f = fopen(filename, "r");

    if (f == NULL) {
        printf("Can't open file for input: %s\n", filename);
        exit(1);
    }

    /*
    * Read and print chars from the file until the special end-of-file
    * value EOF is returned.  Remember that the value from fgetc() must be
    * stored in an int because a char cannot store all 256 byte values from
    * 0 to 255 as well as the special value EOF (which usually is -1).
    */
    while (1) {
        int ch = fgetc(f);
        if (ch == EOF) break;

        /*
        * Print ch.
        */
        printf("%c", ch);
    }

    fclose(f);
}

int main(void) {
    read_file_example("jabberwocky.txt");
    return 0;
}
