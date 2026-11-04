#include <stdio.h>
#include <stdlib.h>

/*
* Purpose:          Write some predefined text to a file.
*
* Parameters:       filename -- the name of the file
*
* Returns:          nothing
*/
void write_file_example(const char *filename) {
    /*
    * Try to create the file with the name in the parameters filename.
    * Complain and exit if we can't create the file.
    */
    FILE *f = fopen(filename, "w");

    if (f == NULL) {
        printf("Can’t open file for output: %s\n", filename);
        exit(1);
    }

    /*
    * Here is a string of chars that we want to write to the file.
    */
    char string[] = "Write this string to the file.\n";

    /*
    * Declare a pointer p to the first char of the string.
    * Now *p == 'W' (the first char of the string).
    */
    char *p = string;

    while (*p != '\0') {
        /*
        * The expression *p refers to the char that is pointed to by p.
        * Write that char to the file using f.
        */
        fputc(*p, f);

        /*
        * Point p to the next char of the string.
        */
        ++p;
    }

    fclose(f);
}

int main(void) {
    write_file_example("out.txt");
    return 0;
}
