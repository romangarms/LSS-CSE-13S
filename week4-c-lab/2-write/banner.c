// Prints a name in a box of stars. The name has to fit in a char array of size 10.
//
// Goal:
//   ./banner Sammy         prints   *********
//                                   * Sammy *
//                                   *********
//   ./banner Al            prints   ******
//                                   * Al *
//                                   ******
//   ./banner Christopher   prints   name too long: Christopher       to stderr, exit code 1
//
// Part 1: fill in fits(). It returns 1 if word can be stored in a char array that
//         holds size chars, and 0 if it can't.
// Part 2: fill in print_banner() so the box is exactly as wide as the name needs.
//
// Hints:
//   main() calls fits() with sizeof(name). What does sizeof tell you about name,
//   and what does strlen tell you about word?
//   A string needs one more char than the letters you can see. Which one?
//   Try a 9-letter name like Alexander and a 10-letter name like Maximilian.
//   Count the stars in the goal for Sammy. How does that number relate to the 5 letters?
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fits(char word[], int size) {
    // Part 1: your code here
    return 1;
}

void print_banner(char word[]) {
    // Part 2: your code here
}

// Do not modify this function.
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s NAME\n", argv[0]);
        exit(1);
    }
    char name[10];
    if (!fits(argv[1], sizeof(name))) {
        fprintf(stderr, "name too long: %s\n", argv[1]);
        exit(1);
    }
    strcpy(name, argv[1]);
    print_banner(name);
    return 0;
}
