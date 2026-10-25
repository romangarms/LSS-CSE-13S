// Reads three letters, one per line, then prints them.
// Should look like this when you type  c Enter  a Enter  t Enter :
//   Type a letter: c
//   Type a letter: a
//   Type a letter: t
//   You typed: cat
//
// Pressing Ctrl-D instead of a letter ends the program with exit code 1.
#include <stdio.h>
#include <stdlib.h>

// Prompts, then returns the next char the user types.
int read_letter(void) {
    printf("Type a letter: ");
    int ch = getchar();
    if (ch == EOF) {
        exit(1);
    }
    return ch;
}

// Do not modify this function.
int main(void) {
    char word[4];
    for (int i = 0; i < 3; i++) {
        word[i] = read_letter();
    }
    word[3] = '\0';
    printf("You typed: %s\n", word);
    return 0;
}
