// Sign up for an account: pick a username and a password, then type the password again.
//
// Goal (what you type is after each prompt):
//   Username: Sammy
//   Usernames are 3-12 chars: lowercase letters, digits or _, starting with a letter.
//   Username: sammy_13s
//   Password: slug
//   Too short: use at least 8 characters.
//   Password: slugsrule!
//   Add an uppercase letter.
//   Password: SlugsRule!
//   Add a digit.
//   Password: SlugsRule!13
//   Confirm password: SlugsRule!13
//   Account created for sammy_13s!
//
// The password rules, in the order check_password() checks them (return the FIRST one broken):
//   PW_TOO_SHORT          fewer than MIN_PASSWORD chars
//   PW_TOO_LONG           more than MAX_PASSWORD chars
//   PW_BAD_CHAR           a char that isn't a letter, a digit, or one of special[] (a space, '.', ...)
//   PW_NO_UPPER           no uppercase letter
//   PW_NO_DIGIT           no digit
//   PW_NO_SPECIAL         none of the chars in special[]
//   PW_TOO_FEW_DIFFERENT  fewer than MIN_DIFFERENT different chars ("Aa1!Aa1!" has only 4)
//   PW_OK                 none of the above
//
// Part 1: fill in is_valid_username().
// Part 2: fill in check_password().
// read_line() and main() are given. To test without typing, run:
//   ./signup < tries.txt | diff expected.txt -
//
// Hints:
//   Part 1: s[i] is one char of the string. Which rule is about s[0] only?
//   Part 2: man 3 strchr  tells you how to ask "is this char in special[]?"
//           Counting different chars is a set of chars: Lecture 12's  int my_set[256]  has a
//           slot for every char value. When is a char the first of its kind?
//           Lecture 10's ctype functions can help with uppercase and digits.
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Three ways to name a constant (all three are quiz topics):
#define MAX_LINE 64                // 1. #define: a text swap before compiling
const int MIN_USERNAME = 3;        // 2. const: a variable the compiler won't let you change
const int MAX_USERNAME = 12;
const int MIN_PASSWORD = 8;
const int MAX_PASSWORD = 20;
const int MIN_DIFFERENT = 5;
const char special[] = "!@#$%^&*?"; // like asgn3's punctuation[]

typedef enum {                     // 3. enum: names for 0, 1, 2, ...
    PW_OK,
    PW_TOO_SHORT,
    PW_TOO_LONG,
    PW_BAD_CHAR,
    PW_NO_UPPER,
    PW_NO_DIGIT,
    PW_NO_SPECIAL,
    PW_TOO_FEW_DIFFERENT
} Problem;

// Do not modify this function.
// Reads one line the user types into buf, without the '\n', using getchar() like asgn3.
// Returns false if the input ended (Ctrl-D) before the line started, true otherwise.
bool read_line(char buf[], int size) {
    int len = 0;
    int ch = getchar();
    if (ch == EOF) {
        return false;
    }
    while (ch != '\n' && ch != EOF) {
        if (len < size - 1) { // keep room for the '\0'; extra chars are skipped
            buf[len] = ch;
            len++;
        }
        ch = getchar();
    }
    buf[len] = '\0';
    return true;
}

// True if name is MIN_USERNAME to MAX_USERNAME chars long, starts with a lowercase letter,
// and every char is a lowercase letter, a digit, or '_'.
bool is_valid_username(const char *name) {
    // Part 1: your code here
    return false;
}

// Returns the first rule (from the list at the top) that password breaks, or PW_OK.
Problem check_password(const char *password) {
    // Part 2: your code here
    return PW_OK;
}

// Do not modify this function.
void print_problem(Problem problem) {
    switch (problem) {
    case PW_OK: break;
    case PW_TOO_SHORT: printf("Too short: use at least %d characters.\n", MIN_PASSWORD); break;
    case PW_TOO_LONG: printf("Too long: use at most %d characters.\n", MAX_PASSWORD); break;
    case PW_BAD_CHAR: printf("Use only letters, digits, and %s\n", special); break;
    case PW_NO_UPPER: printf("Add an uppercase letter.\n"); break;
    case PW_NO_DIGIT: printf("Add a digit.\n"); break;
    case PW_NO_SPECIAL: printf("Add one of %s\n", special); break;
    case PW_TOO_FEW_DIFFERENT:
        printf("Use at least %d different characters.\n", MIN_DIFFERENT);
        break;
    }
}

// Do not modify this function.
int main(void) {
    char username[MAX_LINE];
    char password[MAX_LINE];
    char again[MAX_LINE];

    while (true) {
        printf("Username: ");
        if (!read_line(username, MAX_LINE)) {
            fprintf(stderr, "\nNo input. Goodbye.\n");
            return 1;
        }
        if (is_valid_username(username)) {
            break;
        }
        printf("Usernames are %d-%d chars: lowercase letters, digits or _, starting with a "
               "letter.\n",
            MIN_USERNAME, MAX_USERNAME);
    }

    while (true) {
        printf("Password: ");
        if (!read_line(password, MAX_LINE)) {
            fprintf(stderr, "\nNo input. Goodbye.\n");
            return 1;
        }
        Problem problem = check_password(password);
        if (problem != PW_OK) {
            print_problem(problem);
            continue;
        }
        printf("Confirm password: ");
        if (!read_line(again, MAX_LINE)) {
            fprintf(stderr, "\nNo input. Goodbye.\n");
            return 1;
        }
        if (strcmp(password, again) == 0) {
            break;
        }
        printf("The passwords don't match. Try again.\n");
    }

    printf("Account created for %s!\n", username);
    return 0;
}
