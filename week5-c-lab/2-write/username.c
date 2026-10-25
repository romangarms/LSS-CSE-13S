// Checks a username typed on the command line.
//
// Rules: at most 12 chars, and only lowercase letters, digits, and '_'.
//
// Goal:
//   ./username sammy_13s       prints   welcome, sammy_13s                       exit code 0
//   ./username Sammy           prints   invalid character: 'S'                   exit code 1
//   ./username sammy.slug      prints   invalid character: '.'                   exit code 1
//   ./username sammy_the_slug  prints   the username is over 12 characters.      exit code 1
//   ./username                 prints   usage: ./username NAME                   exit code 1
//   ./username sammy slug      prints   usage: ./username NAME                   exit code 1
// Check an exit code with   echo $?   right after running it.
//
// Part 1: fill in is_valid_username(). If the name breaks a rule, print the matching
//         message and return false. Otherwise return true.
// Part 2: in main(), fill in the argc check before anything uses argv[1].
//
// Hints:
//   The messages are #defined below, like asgn3's hangman_strings.h. A message whose
//   name ends in _d or _c is a printf format: it has a %d or %c that needs a value.
//   Check the length first. Which function from <string.h> gives a string's length?
//   Can the loop say "valid" after checking only one char? When does it know for sure?
//   (02_has_digit.c in 1-fixme has a bug about exactly this.)
//   Lowercase means between 'a' and 'z'. What's the range for a digit?
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 12
#define MSG_USAGE "usage: ./username NAME\n"
#define MSG_TOO_LONG_d "the username is over %d characters.\n"
#define MSG_BAD_CHAR_c "invalid character: '%c'\n"

bool is_valid_username(const char *name) {
    // Part 1: your code here
    return true;
}

int main(int argc, char **argv) {
    // Part 2: your code here

    // Do not modify the rest of main.
    if (!is_valid_username(argv[1])) {
        return 1;
    }
    char name[MAX_LENGTH + 1]; // + 1 for the '\0' at the end
    strcpy(name, argv[1]);
    printf("welcome, %s\n", name);
    return 0;
}
